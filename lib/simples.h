#ifndef simples_h__
#define simples_h__

extern void sCriaListas(struct lista *n1, struct lista *n2, struct lista *n3, struct lista *n4, struct lista *n5, struct lista *n6);
extern void sDemiteFuncionarios(struct lista *n1, struct lista *n2, struct lista *n3, struct lista *n4, struct lista *n5, struct lista *n6);
extern void sEnvelheceFuncionarios(struct lista *n1, struct lista *n2, struct lista *n3, struct lista *n4, struct lista *n5, struct lista *n6);
extern void sContrataFuncionarios(struct lista *n1, struct lista *n2, struct lista *n3, struct lista *n4, struct lista *n5, struct lista *n6);
extern void sFree(struct lista *n1, struct lista *n2, struct lista *n3, struct lista *n4, struct lista *n5, struct lista *n6);
extern void sPromoveMelhor(struct lista *n1, struct lista *n2, struct lista *n3, struct lista *n4, struct lista *n5, struct lista *n6);
extern void sPromovePior(struct lista *n1, struct lista *n2, struct lista *n3, struct lista *n4, struct lista *n5, struct lista *n6);
extern void sPromoveAleatorio(struct lista *n1, struct lista *n2, struct lista *n3, struct lista *n4, struct lista *n5, struct lista *n6);

#endif // simples_h__