#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "../lib/peter.h"

/* Gera um float aleatorio no intervalo [min, max] */
float randomFloat(float min, float max) 
{
	return ( min + (float)rand()/(float)(RAND_MAX) ) * max;
}

/* Gera um int aleatorio no intervalo [min, max] */
int randomInt(int min, int max) 
{
	return ( min + (int)rand()%(int)(RAND_MAX) ) * max;
}

/* Gera um numero aleatorio com média mu e desvio padrao sigma */
float generateGaussianNoise(float mu, float sigma) 
{
	float epsilon = 0.01;
	float two_pi = 2.0 * M_PI;
	float u1, u2;
	float mag, z0, z1;

	do 
	{
		u1 = randomFloat(0, 1);
		u2 = randomFloat(0, 1);
	} while (u1 <= epsilon);

	mag = sigma * sqrt(-2.0 * log(u1));
	z0 = mag * cos(two_pi * u2) + mu;
	z1 = mag * sin(two_pi * u2) + mu;

	return z0;
}

/* Gera numero aleatorio de acordo com uma distribuicao normal.
	Inteiro entre 18 e 60, com mu = 25 e sigma = 5. */
int geraIdade(int min, int max) 
{
	int idade, mu = 25, sigma = 5;
	while (1) 
	{
		idade = (int) generateGaussianNoise(mu, sigma);
		if ((idade >= min) && (idade <= max)) return idade;
	}
}

/* Gera numero aleatorio de acordo com uma distribuicao normal
	Real entre 1 e 10, com mu = 7.0 e sigma = 2.0. */
float geraCompetencia(float min, float max) 
{
	float cmp, mu = 7.0, sigma = 2.0;
	while (1) 
	{
		cmp = (float) generateGaussianNoise(mu, sigma);
		if ((cmp >= min) && (cmp <= max)) return cmp;
	}
}

/* Gera um numero aleatorio entre 0.9 e 1.1 */
float delta(struct lista *ptr) 
{
	float tmp, competencia = ptr->comp;
	
	do
	{
		tmp = competencia * randomFloat(0.9, 1.1);
	} while (tmp > 10.0);
	
	return tmp;
}
