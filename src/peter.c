#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "../lib/peter.h"
#include "../lib/random.h"
#include "../lib/observaveis.h"

/* Cria lista com n nos */
struct lista *criaLista(int n) 
{
	struct lista *ini, *ult, *head;
	int i;

	ini = ult = NULL;

	for (i = 0; i < n; i++) 
	{
		head = (struct lista *)malloc(sizeof(struct lista));
		head->idade = geraIdade(18, 60);
		head->comp = geraCompetencia(1.0, 10.0);
		head->prox = NULL;
		
		if (ult) ult->prox = head;
		else ini = head;
		
		ult = head;
	}

	return (ini);
}

/* Conta numero de nos da lista */
int contaNos(struct lista *head) 
{
	int cont = 0;
	struct lista *atual = head;
	while (atual != NULL) 
	{
		cont++;
		atual = atual->prox;
	}

	return cont;
}

/* Remove funcionarios com competencia < 4.0 ou Idade > 60 */
void demiteFuncionarios(struct lista **head) 
{
	/* Lista vazia */
	if (head == NULL) return;

	struct lista *prev, *atual;
	atual = *head;

	while (atual != NULL) 
	{
		if ((atual->idade > idade_max)
		 || (atual->comp < comp_min)
		 || (atual->comp != atual->comp))
		{
			/* atual eh o head */
			if (atual == *head) 
			{
				/* a lista possui mais de um no */
				if(atual->prox)
				{
					prev = *head;
					atual = atual->prox;
					free(prev);
					*head = atual;
				}
				else /* a lista possui apenas o head */
				{
					*head = NULL;
					free(atual);
					*head = (struct lista *)malloc(sizeof(struct lista));
					*head = NULL;
					return;
				}
			}
			else
			{
				/* ptr eh o ultimo */
				if (atual->prox == NULL)
				{
					prev->prox = NULL;
					free(atual);
					atual = NULL;
					return;
				}
				else
				{
					/* ptr esta no meio da lista */
					prev->prox = atual->prox;
					free(atual);
					atual = prev->prox;
				}
			}
		}
		/* atual nao deve ser excluido, parte para o proximo no */
		else
		{
			prev = atual;
			atual = atual->prox;
		}
	}
}

/* Remove no (NAO EXCLUI FUNCIONARIO PROMOVIDO DO NIVEL ANTERIOR) */
void removeNo(struct lista **head, struct lista *ptr) 
{
	struct lista *prev, *atual;

	atual = *head;
	while(atual != NULL)
	{
		/* Funciona sem hipotese */
		if((atual->comp == ptr->comp) && (atual->idade == ptr->idade))
		// if((&atual == &ptr) && (atual->prox == ptr->prox))
		// if(atual == ptr)
		// if(atual->prox == ptr->prox)
		// if((atual->comp == ptr->comp) && (atual->prox == ptr->prox))
		{
			// printf("atual:\t%p\nptr:\t%p\n", atual, ptr);
			// printf("atual:\t%.2f\nptr:\t%.2f\n", atual->comp, ptr->comp);
			// printf("atual:\t%d\nptr:\t%d\n", atual->idade, ptr->idade);
			if(atual == *head)
			{
				/* a lista possuia mais de um no */
				if(atual->prox)
				{
					prev = *head;
					atual = atual->prox;
					free(prev);
					*head = atual;
					return;
				}
				/* a lista possui apenas o head */
				else 
				{
					*head = NULL;
					free(atual);
					*head = (struct lista *)malloc(sizeof(struct lista));
					*head = NULL;
					return;
				}
			}
			else
			{
				/* atual e o ultimo */
				if(atual->prox == NULL)
				{
					prev->prox = NULL;
					free(atual);
					atual = NULL;
					return;
				}
				/* atual esta no meio da lista */
				else
				{
					prev->prox = atual->prox;
					free(atual);
					atual = prev->prox;
					return;
				}
			}
		}

		prev = atual;
		atual = atual->prox;
	}
}

/* Insere novo funcionario no final da lista */
void contrataFuncionario(struct lista *head) 
{
	struct lista *ptr, *atual;

	ptr = (struct lista *)malloc(sizeof(struct lista));

	ptr->idade = geraIdade(18, 60);
	ptr->comp = geraCompetencia(1.0, 10.0);
	ptr->prox = NULL;

	/* Lista vazia */
	if(head == NULL) 
	{
		head = ptr;
		return;
	}

	atual = head;
	while(atual->prox != NULL) atual = atual->prox;
	
	atual->prox = ptr;
}

/* Insere funcionario existente no final da lista */
void insereExistente(struct lista *ptr, struct lista *head) 
{
	/* Lista vazia */
	if(head == NULL) 
	{
		printf("\nlista vazia\n");
		head = ptr;
		return;
	}

	struct lista *atual;
	atual = head;
	while(atual->prox) atual = atual->prox;
	atual->prox = ptr;
}

/* Busca melhor funcionario (maior competencia) */
struct lista *buscaMelhor(struct lista *head) 
{
	struct lista *atual, *ptr;
	float melhor;

	atual = head;
	melhor = atual->comp;

	ptr = (struct lista *)malloc(sizeof(struct lista));

	while (atual->prox) 
	{
		atual = atual->prox;
		if (atual->comp > melhor) 
		{
			melhor = atual->comp;

			ptr->comp = atual->comp;
			ptr->idade = atual->idade;
			ptr->prox = NULL;
		}
	}

	// printNode(ptr);

	return ptr;
}

/* Busca pior funcionario (menor competencia) */
struct lista *buscaPior(struct lista *head) 
{
	struct lista *atual, *ptr;
	float pior;

	atual = head;
	pior = atual->comp;

	ptr = (struct lista *)malloc(sizeof(struct lista));
	
	while (atual->prox) 
	{
		atual = atual->prox;
		if (atual->comp < pior) 
		{
			pior = atual->comp;
			
			ptr->comp = atual->comp;
			ptr->idade = atual->idade;
			ptr->prox = NULL;
		}
	}

	// printNode(ptr);

	return ptr;
}

/* Busca funcionario aleatorio */
struct lista *buscaAleatorio(struct lista *head) 
{
	struct lista *ptr, *prev;
	int nos, k, i = 0;

	nos = contaNos(head);
	k = randomInt(0, nos);

	ptr = (struct lista *)malloc(sizeof(struct lista));

	ptr = prev = head;

	if(k == 0) 
	{
		ptr->prox = NULL;
		return ptr;
	}

	while (ptr->prox && i < k)
	{
		prev = ptr;
		ptr = ptr->prox;
		i++;
	}

	ptr->prox = NULL;

	// printNode(ptr);

	return ptr;
}

/* Altera competencia do funcionario*/
void alteraCompetencia(struct lista *ptr)
{
	float tmp;

	/* altera (ou nao) a competencia do funcionario */
	#ifdef PETER
		/* Altera competencia segundo o principio de Peter */
		tmp = geraCompetencia(1.0, 10.0);
		ptr->comp = tmp;
	#else
		#ifdef COMMONSENSE
			/* Altera competencia segundo o senso comum */
			do
			{
				tmp = ptr->comp * randomFloat(0.9, 1.1);
			} while (tmp > 10.0);
			ptr->comp = tmp;
		#endif // COMMONSENSE
	#endif // PETER

	return;
}

/* Promove funcionario */
void promoveFuncionario(struct lista **origem, struct lista **destino, int nos)
{
	float tmp;
	while(contaNos(*destino) < nos) 
	{
		struct lista *ptr;
		/* busca o funcionario */
		#ifdef MELHOR
			ptr = buscaMelhor(*origem);
			#else
				#ifdef PIOR
					ptr = buscaPior(*origem);
					#else
						#ifdef ALEATORIO
							ptr = buscaAleatorio(*origem);
						#endif // ALEATORIO
				#endif // PIOR
		#endif // MELHOR

		// printNode(ptr);

		if(nos == n_1) *destino = ptr;
		else insereExistente(ptr, *destino);
		
		removeNo(origem, ptr);

		alteraCompetencia(ptr);
	}
}

/* Envelhece todos os funcionarios de um nivel */
void envelheceFuncionarios(struct lista *head) 
{
	struct lista *atual = head;
	
	while(atual != NULL) 
	{
		atual->idade++;
		atual = atual->prox;
	}
}

/* Printa node com idade e competencia */
void printNode(struct lista *ptr)
{
	printf("\n O funcionario possui idade e competencia | %d %.2f |\n", ptr->idade, ptr->comp);
}

/* Printa lista inteira com idade e competencia */
void printLista(struct lista *head) 
{
	if (head == NULL) return;
	while (head) 
	{
		printf("%d %.2f | ", head->idade, head->comp);
		head = head->prox;
	}
}

/* Imprime teste */
void printTeste(struct lista *n1, struct lista *n2, struct lista *n3, struct lista *n4, struct lista *n5, struct lista *n6)
{
	printf("\nNivel 1, # de nos: %d/%d\n", contaNos(n1), n_1);
	if(n1 != NULL) {
		// printf("Nivel 1 nao esta vazio!\n");
		// printLista(n1);
	}
	/*
	else
	{
		printf("Nivel 1 esta vazio!");
	}
	*/

	printf("\n\nNivel 2, # de nos: %d/%d\n", contaNos(n2), n_2);
	// printLista(n2);

	printf("\n\nNivel 3, # de nos: %d/%d\n", contaNos(n3), n_3);
	// printLista(n3);

	printf("\n\nNivel 4, # de nos: %d/%d\n", contaNos(n4), n_4);
	// printLista(n4);

	printf("\n\nNivel 5, # de nos: %d/%d\n", contaNos(n5), n_5);
	// printLista(n5);

	printf("\n\nNivel 6, # de nos: %d/%d\n", contaNos(n6), n_6);
	// printLista(n6);
}
