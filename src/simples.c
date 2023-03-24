#include "../lib/peter.h"
#include <stdlib.h>

void sCriaListas(struct lista *n1, struct lista *n2, struct lista *n3, struct lista *n4, struct lista *n5, struct lista *n6) 
{
	n1 = criaLista(n_1);
	n2 = criaLista(n_2);
	n3 = criaLista(n_3);
	n4 = criaLista(n_4);
	n5 = criaLista(n_5);
	n6 = criaLista(n_6);
}

void sDemiteFuncionarios(struct lista *n1, struct lista *n2, struct lista *n3, struct lista *n4, struct lista *n5, struct lista *n6) 
{
	demiteFuncionarios(&n1);
	demiteFuncionarios(&n2);
	demiteFuncionarios(&n3);
	demiteFuncionarios(&n4);
	demiteFuncionarios(&n5);
	demiteFuncionarios(&n6);
}

void sPromoveFuncionario(struct lista *n1, struct lista *n2, struct lista *n3, struct lista *n4, struct lista *n5, struct lista *n6) 
{
	// promoveFuncionario(n1, n2, n_1);
	// promoveFuncionario(n2, n3, n_2);
	// promoveFuncionario(n3, n4, n_3);
	// promoveFuncionario(n4, n5, n_4);
	// promoveFuncionario(n5, n6, n_5);
	/* Nao ha promocao no ultimo nivel */
	/* O mesmo sera preenchido quando houverem novas contratacoes */
}

void sEnvelheceFuncionarios(struct lista *n1, struct lista *n2, struct lista *n3, struct lista *n4, struct lista *n5, struct lista *n6) 
{
	envelheceFuncionarios(n1);
	envelheceFuncionarios(n2);
	envelheceFuncionarios(n3);
	envelheceFuncionarios(n4);
	envelheceFuncionarios(n5);
	envelheceFuncionarios(n6);
}

void sContrataFuncionarios(struct lista *n1, struct lista *n2, struct lista *n3, struct lista *n4, struct lista *n5, struct lista *n6) 
{
	while (contaNos(n1) < n_1) contrataFuncionario(n1);
	while (contaNos(n2) < n_2) contrataFuncionario(n2);
	while (contaNos(n3) < n_3) contrataFuncionario(n3);
	while (contaNos(n4) < n_4) contrataFuncionario(n4);
	while (contaNos(n5) < n_5) contrataFuncionario(n5);
	while (contaNos(n6) < n_6) contrataFuncionario(n6);
}

void sFree(struct lista *n1, struct lista *n2, struct lista *n3, struct lista *n4, struct lista *n5, struct lista *n6) 
{
	free(n1);
	free(n2);
	free(n3);
	free(n4);
	free(n5);
	free(n6);
}
