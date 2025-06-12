#pragma once

/**
 * @brief Oblicza numerycznie pochodn¹ pierwszego rzêdu funkcji f(x) w punkcie x.
 *
 * @param f WskaŸnik do funkcji f(x), której pochodna ma zostaæ obliczona
 * @param x Punkt, w którym obliczamy pochodn¹
 * @param h Ma³a wartoœæ kroku ró¿niczkowania (domyœlnie 1e-5)
 * @return Przybli¿ona wartoœæ pochodnej f'(x)
 */
double rozniczka_1_rzedu(double (*f)(double), double x, double h = 1e-5);

/**
 * @brief Oblicza numerycznie pochodn¹ drugiego rzêdu funkcji f(x) w punkcie x.
 *
 * @param f WskaŸnik do funkcji f(x), której druga pochodna ma zostaæ obliczona
 * @param x Punkt, w którym obliczamy drug¹ pochodn¹
 * @param h Ma³a wartoœæ kroku ró¿niczkowania (domyœlnie 1e-5)
 * @return Przybli¿ona wartoœæ drugiej pochodnej f''(x)
 */
double rozniczka_2_rzedu(double (*f)(double), double x, double h = 1e-5);
