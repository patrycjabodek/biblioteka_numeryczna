#include "pch.h"
#include "rownania_nieliniowe.h"

double bisekcja(double (*f)(double), double a, double b, std::vector<double>& historia) {
    historia.clear();
    if (f(a) * f(b) >= 0 && std::fabs(f(a)) > TOL && std::fabs(f(b)) > TOL) {
        return std::numeric_limits<double>::quiet_NaN();
    }

    double c = a;

    for (int iter = 0; iter < MAX_ITER; iter++) {
        c = (a + b) / 2.0;
        historia.push_back(c);
        double fc = f(c);

        if (std::isnan(fc) || std::fabs(fc) < TOL || (b - a) / 2.0 < TOL) {
            break;
        }

        if (f(a) * fc < 0) {
            b = c;
        }
        else {
            a = c;
        }
    }
    return c;
}

double newton(double (*f)(double), double (*df)(double), double x0, std::vector<double>& historia, bool analityczna) {
    historia.clear();
    double x = x0;
    historia.push_back(x);

    for (int iter = 0; iter < MAX_ITER; iter++) {
        double fx = f(x);
        if (std::isnan(fx) || std::fabs(fx) < TOL) break;

        double dfx_val;
        if (analityczna) {
            dfx_val = df(x);
        }
        else {
            double f_plus_h = f(x + TOL);
            double f_minus_h = f(x - TOL);
            if (std::isnan(f_plus_h) || std::isnan(f_minus_h)) {
                return std::numeric_limits<double>::quiet_NaN();
            }
            dfx_val = (f_plus_h - f_minus_h) / (2.0 * TOL);
        }

        if (std::isnan(dfx_val) || std::fabs(dfx_val) < TOL) break;

        double x_prev = x;
        x = x - fx / dfx_val;
        historia.push_back(x);

        if (std::fabs(x - x_prev) < TOL) break;
    }
    return x;
}

double siecznych(double (*f)(double), double x0, double x1, std::vector<double>& historia) {
    historia.clear();
    historia.push_back(x0);
    if (std::fabs(x0 - x1) < TOL) {
        historia.push_back(x1);
        return x1;
    }
    historia.push_back(x1);

    for (int iter = 0; iter < MAX_ITER; iter++) {
        double fx0 = f(x0);
        double fx1 = f(x1);

        if (std::isnan(fx0) || std::isnan(fx1) || std::fabs(fx1) < TOL) break;
        if (std::fabs(fx1 - fx0) < TOL) break;

        double x2 = x1 - fx1 * (x1 - x0) / (fx1 - fx0);
        historia.push_back(x2);

        if (std::fabs(x2 - x1) < TOL) break;

        x0 = x1;
        x1 = x2;
    }
    return x1;
}


std::vector<std::pair<double, double>> regula_falsi(
    double (*f)(double),
    double a,
    double b,
    double epsilon,
    int max_iter,
    std::string stop_condition //= "value"
) {
    std::vector<std::pair<double, double>> results;

    if (f(a) * f(b) >= 0) {
        std::cout << "Warunek f(a)*f(b) < 0 nie jest spelniony w przedziale [" << a << ", " << b << "]" << std::endl;
        return results;
    }

    double c = a;
    for (int i = 0; i < max_iter; ++i) {
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));

        if (f(c) == 0.0) {
            results.emplace_back(c, f(c));
            break;
        }

        results.emplace_back(c, f(c));

        if (stop_condition == "value" && std::abs(f(c)) < epsilon) {
            break;
        }
        else if (stop_condition == "interval" && std::abs(b - a) < epsilon) {
            break;
        }
        else if (stop_condition == "both" && (std::abs(f(c)) < epsilon || std::abs(b - a) < epsilon)) {
            break;
        }

        if (f(c) * f(a) < 0) {
            b = c;
        }
        else {
            a = c;
        }
    }

    return results;
}

double find_closest_exact_root(double approx_root, const std::vector<double>& exact_roots) {
    if (exact_roots.empty()) return std::numeric_limits<double>::quiet_NaN();

    auto it = std::min_element(exact_roots.begin(), exact_roots.end(),
        [approx_root](double a, double b) {
            return std::abs(a - approx_root) < std::abs(b - approx_root);
        });

    return *it;
}
