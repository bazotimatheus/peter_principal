#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "../lib/peter.h"
#include "../lib/random.h"
#include "../lib/observaveis.h"
#include "../lib/simples.h"

int main() 
{
	struct lista *n1, *n2, *n3, *n4, *n5, *n6;
	FILE *fp;
	int t = 0;
	float eficiencia_global;

	#ifdef PETER
		#ifdef MELHOR
			// fp = fopen("peter_melhor.out","w");
		#endif
		#ifdef PIOR
			// fp = fopen("peter_pior.out","w");
		#endif
		#ifdef ALEATORIO
			// fp = fopen("peter_aleatorio.out","w");
		#endif
	#endif
	#ifdef COMMONSENSE
		#ifdef MELHOR
			// fp = fopen("common_melhor.out","w");
		#endif
		#ifdef PIOR
			// fp = fopen("common_pior.out","w");
		#endif
		#ifdef ALEATORIO
			// fp = fopen("common_aleatorio.out","w");
		#endif
	#endif
	// fp = fopen("saida.out","w");

	srand(2);

	// printf("\n ===== Cria listas ===== \n\n");
	n1 = criaLista(n_1);
	n2 = criaLista(n_2);
	n3 = criaLista(n_3);
	n4 = criaLista(n_4);
	n5 = criaLista(n_5);
	n6 = criaLista(n_6);
	// printTeste(n1, n2, n3, n4, n5, n6);

	/* ===== Inicia loop de iteracoes ===== */
	for(t = 1; t <= TMAX; t++)
	{
		printf(" ==================== T = %d ==================== \n", t);
		eficiencia_global = eficienciaGlobal(n1, n2, n3, n4, n5, n6);
		printf("\n Eficiencia Global: %.2f%% \n", eficiencia_global);
		// fprintf(fp, "%d %.2f\n", t, eficiencia_global);

		// printf("\n ===== Demite funcionarios ===== ");
		demiteFuncionarios(&n1);
		demiteFuncionarios(&n2);
		demiteFuncionarios(&n3);
		demiteFuncionarios(&n4);
		demiteFuncionarios(&n5);
		demiteFuncionarios(&n6);
		// printTeste(n1, n2, n3, n4, n5, n6);

		// printf("\n ===== Promove funcionarios ===== ");
		promoveFuncionario(&n2, &n1, n_1);
		promoveFuncionario(&n3, &n2, n_2);
		promoveFuncionario(&n4, &n3, n_3);
		promoveFuncionario(&n5, &n4, n_4);
		promoveFuncionario(&n6, &n5, n_5);
		// printTeste(n1, n2, n3, n4, n5, n6);

		// printf("\n ===== Envelhece funcionarios ===== ");
		envelheceFuncionarios(n1);
		envelheceFuncionarios(n2);
		envelheceFuncionarios(n3);
		envelheceFuncionarios(n4);
		envelheceFuncionarios(n5);
		envelheceFuncionarios(n6);
		// printTeste(n1, n2, n3, n4, n5, n6);

		// printf("\n ===== Contrata funcionarios ===== ");
		while (contaNos(n1) < n_1) contrataFuncionario(n1);
		while (contaNos(n2) < n_2) contrataFuncionario(n2);
		while (contaNos(n3) < n_3) contrataFuncionario(n3);
		while (contaNos(n4) < n_4) contrataFuncionario(n4);
		while (contaNos(n5) < n_5) contrataFuncionario(n5);
		while (contaNos(n6) < n_6) contrataFuncionario(n6);
		printTeste(n1, n2, n3, n4, n5, n6);

		printf("\n\n ==================== Fim da iteracao ==================== \n");
	}
	/* ===== Fim do loop de iteracoes ===== */

	printf("\n Fim do programa\n");

	/* Libera memoria */
	sFree(n1, n2, n3, n4, n5, n6);

	/* Fecha arquivo de saida */
	// fclose(fp);

	return 0;
}
