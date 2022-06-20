#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "../lib/peter.h"
#include "../lib/random.h"
#include "../lib/observaveis.h"
#include "../lib/simples.h"

int main() {
	struct lista *n1, *n2, *n3, *n4, *n5, *n6;
	FILE *fp;
	int i;
	float eficiencia_global;

	fp = fopen("saida.out","w");

	srand(time(NULL));

	/* Cria listas */
	//sCriaListas(n1, n2, n3, n4, n5, n6);
	n1 = criaLista(n_1);
	n2 = criaLista(n_2);
	n3 = criaLista(n_3);
	n4 = criaLista(n_4);
	n5 = criaLista(n_5);
	n6 = criaLista(n_6);
	printf("\nCriou as listas\n");

	/*================= Inicia loot de iteracoes =================*/
	/* Calcula eficiencia global */
	eficiencia_global = eficienciaGlobal(n1, n2, n3, n4, n5, n6);
	printf("\nCalculou eficiencia global\n");

	/* Demite funcionarios */
	sDemiteFuncionarios(n1, n2, n3, n4, n5, n6);
	printf("\nDemitiu funcionarios\n");

	/* Promove funcionarios ate preencher os niveis superiores */
	/* Verificar estrategia de promocao para modificar competencias */
	#ifdef MELHOR
		sPromoveMelhor(n1, n2, n3, n4, n5, n6);
	#else
		#ifdef PIOR
			sPromovePior(n1, n2, n3, n4, n5, n6);
		#else
			#ifdef ALEATORIO
				sPromoveAleatorio(n1, n2, n3, n4, n5, n6);
			#endif // ALEATORIO
		#endif // PIOR
	#endif //MELHOR
	printf("\nPromoveu funcionarios\n");

	/* Envelhece funcionarios */
	sEnvelheceFuncionarios(n1, n2, n3, n4, n5, n6);
	printf("\nEnvelheceu os funcionarios\n");

	/* Contrata novos funcionarios */
	sContrataFuncionarios(n1, n2, n3, n4, n5, n6);
	printf("\nContrata funcionarios\n");

	/*================= Fim do loop de iteracoes =================*/

	/* Libera memoria */
	sFree(n1, n2, n3, n4, n5, n6);
	printf("\nLibera memoria\n");

	/* Fecha arquivo de saida */
	fclose(fp);
	printf("\nFecha arquivo");

	return 0;
}
