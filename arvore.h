#ifndef ARVOREBINARIA_H
#define ARVOREBINARIA_H

#include "cliente.h"

#define FILHO_ESQ 0
#define FILHO_DIR 1

typedef struct node_st NODE;
typedef struct arvore_binaria ARVORE;

ARVORE* arvore_criar();
void arvore_pre_ordem(ARVORE* arvore);
void arvore_em_ordem(ARVORE* arvore);
void arvore_pos_ordem(ARVORE* arvore);
boolean arvore_inserir(ARVORE *arvore, CLIENTE *cliente, int lado, long long int cpf);
void arvore_apagar(ARVORE **arvore);
boolean abb_inserir (ARVORE *T, CLIENTE *cliente);


#endif //ARVOREBINARIA_H
