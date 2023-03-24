#include "../lib/peter.h"
#include "../lib/random.h"

/* Soma o numero de funcionarios de todos os niveis */
int numeroFuncionarios(struct lista *n1, struct lista *n2, struct lista *n3, struct lista *n4, struct lista *n5, struct lista *n6) 
{
	return (contaNos(n1)+contaNos(n2)+contaNos(n3)+contaNos(n4)+contaNos(n5)+contaNos(n6));
}

/* Calcula eficiencia maxima da empresa */
float eficienciaMax(struct lista *n1, struct lista *n2, struct lista *n3, struct lista *n4, struct lista *n5, struct lista *n6) 
{
	int N;
	int nos1, nos2, nos3, nos4, nos5, nos6;
	float NiRi;
	float effMax;

	N = numeroFuncionarios(n1, n2, n3, n4, n5, n6);

	nos1 = contaNos(n1);
	nos2 = contaNos(n2);
	nos3 = contaNos(n3);
	nos4 = contaNos(n4);
	nos5 = contaNos(n5);
	nos6 = contaNos(n6);

	NiRi = nos1*r_1 + nos2*r_2 + nos3*r_3 + nos4*r_4 + nos5*r_5 + nos6*r_6;

	effMax = (float)( 10 * (NiRi) / N );

	return effMax;
}

/* Calcula a competencia de um certo nivel */
float competenciaNivel(struct lista *n) 
{
	struct lista *aux;
	float cmp = 0.0;
	aux = n;
	while(aux) 
	{
		cmp += aux->comp;
		aux = aux->prox;
	}
	return cmp;
}

/* Calcula eficiencia global da empresa */
float eficienciaGlobal(struct lista *n1, struct lista *n2, struct lista *n3, struct lista *n4, struct lista *n5, struct lista *n6) 
{
	int N;
	float cmp1, cmp2, cmp3, cmp4, cmp5, cmp6;
	float CiRi;
	float maxEff, globalEff;

	N = numeroFuncionarios(n1, n2, n3, n4, n5, n6);

	cmp1 = competenciaNivel(n1);
	cmp2 = competenciaNivel(n2);
	cmp3 = competenciaNivel(n3);
	cmp4 = competenciaNivel(n4);
	cmp5 = competenciaNivel(n5);
	cmp6 = competenciaNivel(n6);

	maxEff = eficienciaMax(n1, n2, n3, n4, n5, n6);

	CiRi = cmp1*r_1 + cmp2*r_2 + cmp3*r_3 + cmp4*r_4 + cmp5*r_5 + cmp6*r_6;

	globalEff = (float)(CiRi)/(float)(maxEff * N)*100.0;

	return globalEff;
}
