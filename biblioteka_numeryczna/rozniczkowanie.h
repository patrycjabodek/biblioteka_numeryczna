#pragma once

/**
 * @brief Oblicza numerycznie pochodn� pierwszego rz�du funkcji f(x) w punkcie x.
 *
 * @param f Wska�nik do funkcji f(x), kt�rej pochodna ma zosta� obliczona
 * @param x Punkt, w kt�rym obliczamy pochodn�
 * @param h Ma�a warto�� kroku r�niczkowania (domy�lnie 1e-5)
 * @return Przybli�ona warto�� pochodnej f'(x)
 */
double rozniczka_1_rzedu(double (*f)(double), double x, double h = 1e-5);

/**
 * @brief Oblicza numerycznie pochodn� drugiego rz�du funkcji f(x) w punkcie x.
 *
 * @param f Wska�nik do funkcji f(x), kt�rej druga pochodna ma zosta� obliczona
 * @param x Punkt, w kt�rym obliczamy drug� pochodn�
 * @param h Ma�a warto�� kroku r�niczkowania (domy�lnie 1e-5)
 * @return Przybli�ona warto�� drugiej pochodnej f''(x)
 */
double rozniczka_2_rzedu(double (*f)(double), double x, double h = 1e-5);
