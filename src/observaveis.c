#include "../lib/peter.h"
#include "../lib/random.h"

/* Soma o numero de funcionarios de todos os niveis */
int numeroFuncionarios(struct lista *n1, struct lista *n2, struct lista *n3, struct lista *n4, struct lista *n5, struct lista *n6) {
	return (contaNos(n1) + contaNos(n2) + contaNos(n3) + contaNos(n4) + contaNos(n5) + contaNos(n6));
}

/* Calcula eficiencia maxima da empresa */
float eficienciaMax(struct lista *n1, struct lista *n2, struct lista *n3, struct lista *n4, struct lista *n5, struct lista *n6) {
	int N = numeroFuncionarios(n1, n2, n3, n4, n5, n6);
	return 10.0 * (r_1 + r_2 + r_3 + r_4 + r_5 + r_6) / (N * 1.0);
}

/* Calcula a competencia de um certo nivel */
float competenciaNivel(struct lista *n) {
	struct lista *aux;
	float cmp = 0.0;
	aux = n;
	while(aux) {
		cmp += aux->comp;
		aux = aux->prox;
	}
	return cmp;
}

/* Calcula eficiencia global da empresa */
float eficienciaGlobal(struct lista *n1, struct lista *n2, struct lista *n3, struct lista *n4, struct lista *n5, struct lista *n6) {
	int N = numeroFuncionarios(n1, n2, n3, n4, n5, n6);
	float maxEff = eficienciaMax(n1, n2, n3, n4, n5, n6);
	float c1, c2, c3, c4, c5, c6;

	c1 = competenciaNivel(n1);
	c2 = competenciaNivel(n2);
	c3 = competenciaNivel(n3);
	c4 = competenciaNivel(n4);
	c5 = competenciaNivel(n5);
	c6 = competenciaNivel(n6);

	return (c1 * r_1 + c2 * r_2 + c3 * r_3 + c4 * r_4 + c5 * r_5 + c6 * r_6) / (maxEff * N * 1.0);
}

/* Gera um numero aleatorio entre 0.9 e 1.1 */
float delta() {
	return randomFloat(0.9, 1.1);
}