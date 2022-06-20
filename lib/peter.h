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

/* Tempo maximo da Simulação */
#define TMAX 1

/* Idade e Competencia de corte */
#define idade_max 60
#define comp_min 5.0

/* Struct com idade e competencia */
struct lista {
	float comp;
	int idade;
	struct lista *prox;
};

/* Define estrategias de promocao */
#define MELHOR
//#define PIOR
//#define ALEATORIO

/* Define hipoteses */
#define PETER
//#define COMMONSENSE


extern struct lista *criaLista(int n);
extern void printLista(struct lista *p);
extern int contaNos(struct lista *p);
extern void demiteFuncionarios(struct lista *p);
extern struct lista *buscaMelhor(struct lista *p);
extern struct lista *buscaPior(struct lista *p);
extern struct lista *buscaAleatorio(struct lista *p);
extern void removeNo(struct lista *p, struct lista *ptr);
extern void contrataFuncionario(struct lista *p);
extern void insereExistente(struct lista *p, struct lista *ptr);
extern void promoveMelhor(struct lista *alto, struct lista *baixo, int nos);
extern void promovePior(struct lista *alto, struct lista *baixo, int nos);
extern void promoveAleatorio(struct lista *alto, struct lista *baixo, int nos);
extern void envelheceFuncionarios(struct lista *p);

#endif // peter_h__