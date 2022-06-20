#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/* Gera um float aleatorio no intervalo [min, max] */
float randomFloat(float min, float max) {
	return (float)((rand() / (max - min + 1.0)) + min);
}

/* Gera um int aleatorio no intervalo [min, max] */
int randomInt(int min, int max) {
	return (int)((rand() % (max - min + 1)) + min);
}

/* Gera um numero aleatorio com média mu e desvio padrao sigma */
float generateGaussianNoise(float mu, float sigma) {
	float epsilon;
	float two_pi = 2.0 * M_PI;
	float u1, u2;
	float mag, z0, z1;

	do {
		u1 = randomFloat(0, 1);
		u2 = randomFloat(0, 1);
	} while (u1 <= epsilon);

	mag = sigma * sqrt(-2.0 * log(u1));
	z0 = mag * cos(two_pi * u2) + mu;
	z1 = mag * sin(two_pi * u2) + mu;

	if (u1 > 0.5)
		return z0;
	else
		return z1;
}

/* Gera numero aleatorio de acordo com uma distribuicao normal.
	Inteiro entre 18 e 60, com mu = 25 e sigma = 5. */
int geraIdade(int min, int max) {
	int idade;
	while (1) {
		idade = (int)generateGaussianNoise(25, 5);
		if ((idade >= min) && (idade <= max))
			return idade;
	}
}

/* Gera numero aleatorio de acordo com uma distribuicao normal
	Real entre 1 e 10, com mu = 7.0 e sigma = 2.0. */
float geraCompetencia(float min, float max) {
	float cmp;
	while (1) {
		cmp = generateGaussianNoise(7.0, 2.0);
		if ((cmp >= min) && (cmp <= max))
			return cmp;
	}
}
