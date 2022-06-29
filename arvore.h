#ifndef ARVOREBINARIA_H
#define ARVOREBINARIA_H

#include <stdlib.h>
#include <stdio.h>
#include "cliente.h"

typedef struct node_st
{
    CLIENTE *cliente;
    struct node_st *direita;
    struct node_st *esquerda;
}NODE;

typedef struct arvore_binaria
{
    NODE *raiz;
}ARVORE;

ARVORE* arvore_criar();
void arvore_pre_ordem(ARVORE* arvore);
void arvore_em_ordem(ARVORE* arvore);
void arvore_pos_ordem(ARVORE* arvore);
boolean arvore_inserir(ARVORE *arvore, CLIENTE *cliente, int lado, long long int cpf);
void arvore_apagar(ARVORE **arvore);
boolean abb_inserir (ARVORE *T, CLIENTE *cliente);


#endif //ARVOREBINARIA_H
