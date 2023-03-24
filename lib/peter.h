#ifndef peter_h__
#define peter_h__

/* Responsabilidades de cada nivel */
#define r_1 1.0
#define r_2 0.9
#define r_3 0.8
#define r_4 0.6
#define r_5 0.4
#define r_6 0.2

/* Numero de funcionarios de cada nivel */
#define n_1 1
#define n_2 5
#define n_3 11
#define n_4 21
#define n_5 41
#define n_6 81

/* Tempo maximo da Simulacao */
#define TMAX 60

/* Idade e Competencia de corte */
#define idade_max 60
#define comp_min 4.0

/* Define estrategias de promocao */
#define MELHOR
// #define PIOR
// #define ALEATORIO

/* Define hipoteses */
#define PETER
// #define COMMONSENSE

/* Struct com idade e competencia */
struct lista {
	float comp;
	int idade;
	struct lista *prox;
};

/* Externs */

extern struct lista *criaLista(int n);
extern int contaNos(struct lista *head);
extern void demiteFuncionarios(struct lista **head);
extern void removeNo(struct lista **head, struct lista *ptr);
extern void contrataFuncionario(struct lista *head);
extern void insereExistente(struct lista *head, struct lista *ptr);
extern struct lista *buscaMelhor(struct lista *head);
extern struct lista *buscaPior(struct lista *head);
extern struct lista *buscaAleatorio(struct lista *head);
extern void alteraCompetencia(struct lista *ptr);
extern void promoveFuncionario(struct lista **origem, struct lista **destino, int nos);
extern void envelheceFuncionarios(struct lista *head);
extern void printNode(struct lista *ptr);
extern void printLista(struct lista *head);
extern void printTeste(struct lista *n1, struct lista *n2, struct lista *n3, struct lista *n4, struct lista *n5, struct lista *n6);

#endif // peter_h__