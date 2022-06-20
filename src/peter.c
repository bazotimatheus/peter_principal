#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "../lib/peter.h"
#include "../lib/random.h"
#include "../lib/observaveis.h"

/* Cria lista com n nos */
struct lista *criaLista(int n) {
	struct lista *ini, *ult, *p;
	int i;

	ini = ult = NULL;

	for (i = 0; i < n; i++) {
		p = (struct lista *)malloc(sizeof(struct lista));
		p->comp = geraCompetencia(1.0, 10.0);
		p->idade = geraIdade(18, 60);
		p->prox = NULL;
		
		if (ult)
			ult->prox = p;
		else
			ini = p;
		
		ult = p;
	}

	return (ini);
}

/* Printa idade e competencia */
void printLista(struct lista *p) {
	if (!p)
		return;
	while (p) {
		printf("%d %f\n", p->idade, p->comp);
		p = p->prox;
	}
}

/* Conta numero de nos da lista */
int contaNos(struct lista *p) {
	struct lista *ptr;
	int cont = 0;
	
	ptr = p;

	while (ptr) {
		cont++;
		ptr = ptr->prox;
	}

	return cont;
}

/* Remove funcionarios com competencia < 4.0 ou Idade > 60 */
void demiteFuncionarios(struct lista *p) {
	struct lista *ptr, *antes;
	/* Lista vazia */
	if (!p)
		return;
	else {
		ptr = p;
		antes = p;
		while (ptr) {
			if (ptr->idade > idade_max || ptr->comp < comp_min) {
				/* ptr e o primeiro da lista */
				if (ptr == p) {
					p = p->prox;
					antes = p->prox;
					free(ptr);
					ptr = antes;
				}
				else {
					antes->prox = ptr->prox;
					free(ptr);
					ptr = antes->prox;
				}
			}
			else {
				antes = ptr;
				ptr = ptr->prox;
			}
		}
		return;
	}
}

/* Busca melhor funcionario (maior competencia) */
struct lista *buscaMelhor(struct lista *p) {
	struct lista *aux, *ptr;
	float melhor = 0;

	aux = p;
	melhor = aux->comp;

	while (aux->prox) {
		aux = aux->prox;
		if (aux->comp > melhor) {
			melhor = aux->comp;

			ptr->comp = aux->comp;
			ptr->idade = aux->idade;
			ptr->prox = NULL;
		}
	}
	return ptr;
}

/* Busca pior funcionario (menor competencia) */
struct lista *buscaPior(struct lista *p) {
	struct lista *aux, *ptr;
	float pior = 10.0;

	aux = p;
	pior = aux->comp;

	while (!aux->prox) {
		aux = aux->prox;
		if (aux->comp < pior) {
			pior = aux->comp;
			
			ptr->comp = aux->comp;
			ptr->idade = aux->idade;
			ptr->prox = NULL;
		}
	}

	return ptr;
}

/* Busca funcionario aleatorio */
struct lista *buscaAleatorio(struct lista *p) {
	struct lista *ptr;
	int nos, k, i;

	nos = contaNos(p);
	k = randomInt(0, nos);

	ptr = p;
	if(k == 1) {
		ptr->prox = NULL;
		return ptr;
	}

	for(i = 0; i < k; i++) ptr = ptr->prox;

	ptr->prox = NULL;

	return ptr;
}

/* Remove no */
void removeNo(struct lista *p, struct lista *ptr) {
	struct lista *aux, *antes;

	antes = p;
	aux = p;
	
	while(aux) {
		if(aux == ptr) {
			antes->prox = ptr->prox;
			free(ptr);
			return;
		}
		antes = aux;
		aux = aux->prox;
	}
}

/* Insere novo funcionario no final da lista */
void contrataFuncionario(struct lista *p) {
	struct lista *ptr, *aux;

	ptr = (struct lista *)malloc(sizeof(struct lista));

	ptr->idade = geraIdade(18, 60);
	ptr->comp = geraCompetencia(1.0, 10.0);
	ptr->prox = NULL;

	/* Lista vazia */
	if(!p) {
		p = ptr;
		return;
	}
	else {
		aux = p;

		while(!aux->prox)
			aux = aux->prox;
		
		aux->prox = ptr;
	}
}

/* Insere funcionario existente no final da lista */
void insereExistente(struct lista *p, struct lista *ptr) {
	struct lista *aux;

	/* Lista vazia */
	if(!p) { 
		p = ptr;
		return;
	}
	else {
		aux = p;

		while(aux->prox)
			aux = aux->prox;
		
		aux->prox = ptr;
		return;
	}
}

/* Promove funcionario com maior competencia */
void promoveMelhor(struct lista *alto, struct lista *baixo, int nos) {
	struct lista *ptr;

	while(contaNos(alto) < nos) {
		ptr = buscaMelhor(baixo);
		#ifdef PETER
			/* Altera competencia segundo o principio de Peter */
			ptr->comp = geraCompetencia(1.0, 10.0);
		#else
			#ifdef COMMONSENSE
				/* Altera competencia segundo o senso comum */
				ptr->comp = ptr->comp * delta();
			#endif // COMMONSENSE
		#endif //PETER

		insereExistente(ptr, alto);
		removeNo(ptr, baixo);
	}
}

/* Promove funcionario com pior competencia */
void promovePior(struct lista *alto, struct lista *baixo, int nos) {
	struct lista *ptr;

	while(contaNos(alto) < nos) {
		ptr = buscaPior(baixo);
		#ifdef PETER
			/* Altera competencia segundo o principio de Peter */
			ptr->comp = geraCompetencia(1.0, 10.0);
		#else
			#ifdef COMMONSENSE
				/* Altera competencia segundo o senso comum */
				ptr->comp = ptr->comp * delta();
			#endif // COMMONSENSE
		#endif //PETER

		insereExistente(alto, ptr);
		removeNo(baixo, ptr);
	}
}

/* Promove funcionario aleatorio */
void promoveAleatorio(struct lista *alto, struct lista *baixo, int nos) {
	struct lista *ptr;
	
	while(contaNos(alto) < nos) {
		ptr = buscaAleatorio(baixo);
		#ifdef PETER
			/* Altera competencia segundo o principio de Peter */
			ptr->comp = geraCompetencia(1.0, 10.0);
		#else
			#ifdef COMMONSENSE
				/* Altera competencia segundo o senso comum */
				ptr->comp = ptr->comp * delta();
			#endif // COMMONSENSE
		#endif //PETER

		insereExistente(alto, ptr);
		removeNo(baixo, ptr);
	}
}

/* Envelhece todos os funcionarios de um nivel */
void envelheceFuncionarios(struct lista *p) {
	struct lista *ptr;
	
	ptr = p;
	
	while(ptr) {
		ptr->idade++;
		ptr = ptr->prox;
	}
}