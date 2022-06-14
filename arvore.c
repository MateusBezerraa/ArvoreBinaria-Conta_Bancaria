#include <stdlib.h>
#include <stdio.h>
#include "arvore.h"

#define COUNT 8

struct node_st
{
    CLIENTE *cliente;
    NODE *direita;
    NODE *esquerda;
};

struct arvore_binaria
{
    NODE *raiz;
    int profundidade;
};




ARVORE* arvore_criar()
{
    ARVORE* arvore = (ARVORE*)malloc(sizeof(ARVORE));
    if(arvore)
    {
        arvore->raiz = NULL;
        arvore->profundidade = -1;
    }
    return arvore;
}

////  INSERIR NO NA ARVORE MANUALMENTE =========================================================================


static NODE* cria_node(CLIENTE *cliente)
{
    NODE *novoNode = (NODE *) malloc(sizeof(NODE));
    if (novoNode) {
        novoNode->cliente = cliente;
        novoNode->direita = NULL;
        novoNode->esquerda = NULL;
    }
    return novoNode;
}


static NODE* arvore_inserir_node(NODE *raiz, CLIENTE *cliente, int lado, long long int cpf)
// o cpf nessa caso atua como chave do pai, ou seja, o nó que será inserido será filho do cliente com o cpf passado aqui
{
    if(raiz)
    {
        raiz->esquerda = arvore_inserir_node(raiz->esquerda, cliente, lado, cpf);
        raiz->direita = arvore_inserir_node(raiz->direita, cliente, lado, cpf);
        if (cpf == cliente_get_cpf(raiz->cliente))
        {
            if (lado == FILHO_ESQ)
                raiz->esquerda = cria_node(cliente);
            else if (lado == FILHO_DIR)
                raiz->direita = cria_node(cliente);
        }
    }
    return raiz;   
}


boolean arvore_inserir(ARVORE *arvore, CLIENTE *cliente, int lado, long long int cpf){
    if (arvore->raiz == NULL)
        return((arvore->raiz = cria_node(cliente)) != NULL);
    else
        return((arvore->raiz = arvore_inserir_node(arvore->raiz, cliente, lado, cpf)) != NULL);
}

////  INSERIR NO NA ARVORE DE BINARIA DE BUSCA =========================================================================

boolean ehMenor(const NODE *raiz, CLIENTE *cliente);
boolean ehMaior(const NODE *raiz, CLIENTE *cliente);


NODE *abb_inserir_no(NODE *raiz, CLIENTE *cliente)
{
    if (raiz == NULL)
        raiz = cria_node(cliente);
    else if(ehMaior(raiz, cliente))
        raiz->direita = abb_inserir_no(raiz->direita,cliente);
    else if(ehMenor(raiz, cliente))
        raiz->esquerda = abb_inserir_no(raiz->esquerda,cliente);
    return raiz;
}

boolean ehMenor(const NODE *raiz, CLIENTE *cliente) 
{
    return cliente_get_cpf(cliente) < cliente_get_cpf(raiz->cliente);
}

boolean ehMaior(const NODE *raiz, CLIENTE *cliente) 
{
    return cliente_get_cpf(cliente) > cliente_get_cpf(raiz->cliente);
}

boolean abb_inserir (ARVORE *T, CLIENTE *cliente)
{
    return((T->raiz = abb_inserir_no(T->raiz, cliente)) != NULL);
}


int arvore_profundidade(NODE *node)
{
    if (node == NULL)
        return -1;
    int e = arvore_profundidade(node->esquerda);
    int d = arvore_profundidade(node->direita);
    return ((e > d) ? e : d) + 1;
}


// =========== APAGAR ARVORE =========================================================================

void apagar_arvore_interno(NODE **raiz) 
{
    if (*raiz != NULL) {
        apagar_arvore_interno(&(*raiz)->esquerda);
        apagar_arvore_interno(&(*raiz)->direita);
        cliente_apagar(&(*raiz)->cliente);
        free(*raiz);
        *raiz = NULL;
    }
}


void arvore_apagar(ARVORE **arvore) 
{
    apagar_arvore_interno(&(*arvore)->raiz);
    free(*arvore);
    *arvore = NULL;
}






// =========================================================================
/*          ARVORE DE EXEMPLO

                    A
                  /   \
                B      C
               /      / \
              D      E   F
               \    / \
                G  H   I

PRÉ ORDEM
realiza a operação e visita o da esqueda, se n tem da esqueda, visita o da direita, sobe pro nó pai e continua.
Na arvore de ex, a ordem de acesso aos nós seria: ABDGCEHIF

EM ORDEM
visita o da esquerda, realiza operação e depois direita
Na arvore de ex, a ordem de acesso aos nós seria: DGBAHEICF

POS ORDEM
visita da esquerda, depois da direita, e por fim realiza a operação
Na arvore de ex, a ordem de acesso aos nós seria: GDBHIEFCA

Pré -> operação dps visita;
Em  -> operações em ordem sequencial crescente para arvore ordenada
Pós -> visita tudo dps realiza operações

*/
//=========================================================================

//OBS// 
// essa chamada de interna é somente para esconder o codigo. Como é necessario passar a raiz para a função
// ao inves de passarmos isso na main, criamos uma função que recebe a arvore e passa a raiz pra essa func, para esconder o codigo.

////////// pre ordem
static void arvore_pre_ordem_interna(NODE* raiz)
{
    if(raiz)
    {
        //realiza a operação que queremos no node, pode ser imprimir, buscar, etc.
        cliente_printa_cpf_num(raiz->cliente);
        arvore_pre_ordem_interna(raiz->esquerda);
        arvore_pre_ordem_interna(raiz->direita);
    }
}

void arvore_pre_ordem(ARVORE* arvore)
{
    arvore_pre_ordem_interna(arvore->raiz);
}


//////////// em ordem
static void arvore_em_ordem_interna(NODE* raiz)
{
    if(raiz)
    {
        arvore_em_ordem_interna(raiz->esquerda);
        cliente_printa_cpf_num(raiz->cliente);
        arvore_em_ordem_interna(raiz->direita);
    }
}

void arvore_em_ordem(ARVORE* arvore)
{
    arvore_em_ordem_interna(arvore->raiz);
}


////////////// pos ordem
static void arvore_pos_ordem_interna(NODE* raiz)
{
    if(raiz)
    {
        arvore_pos_ordem_interna(raiz->esquerda);
        arvore_pos_ordem_interna(raiz->direita);
        cliente_printa_cpf_num(raiz->cliente);
    }
}

void arvore_pos_ordem(ARVORE* arvore)
{
    arvore_pos_ordem_interna(arvore->raiz);
}


// CLIENTE *abb_busca_no(NODE *raiz, int chave){
//     if(raiz == NULL)
//         return NULL;
//     if(chave == cliente_get_chave(raiz->cliente))
//         return (raiz->cliente);
//     if(chave < cliente_get_chave(raiz->cliente))
//         return (abb_busca_no(raiz->esquerda, chave));
//     else
//         return (abb_busca_no(raiz->direita, chave));
// }
// CLIENTE *abb_busca(ARVORE_BINARIA *T, int chave){
//     return(abb_busca_no(T->raiz, chave));
// }

// static boolean abb_remover_aux (NODE **raiz, int chave){
//     NODE *noRemovido;
//     if(*raiz == NULL)
//     {
//         return FALSE;
//     }
//     if(chave == cliente_get_chave((*raiz)->cliente))
//     {
//         if ((*raiz)->esquerda == NULL|| (*raiz)->direita == NULL)
//         {/*Caso 1 se resume ao caso 2: há um filho ou nenhum*/
//             noRemovido = *raiz;
//             if((*raiz)->esquerda == NULL) {
//                 *raiz = (*raiz)->direita;
//             }
//             else {
//                 *raiz = (*raiz)->esquerda;
//             }
//             free(noRemovido);
//             noRemovido = NULL;
//         }
//         else /*Caso 3: há ambos os filhos*/
//         {
//             troca_max_esq((*raiz)->esquerda, (*raiz), (*raiz));
//         }
//         return TRUE;
//     }
//     else
//     {
//         if(chave < cliente_get_chave((*raiz)->cliente))
//             return abb_remover_aux (&(*raiz)->esquerda, chave);
//         else
//             return abb_remover_aux (&(*raiz)->direita, chave);
//     }
// }

// boolean arvore_binaria_remover(ARVORE_BINARIA *T){
//     if (T != NULL)
//         return abb_remover_aux(&T->raiz, cliente_get_cpf(&T->(*raiz)->cliente));
//     return FALSE;
// }

// static void troca_max_esq(NODE *troca, NODE *raiz, NODE *ant)
// {
//     if(troca->direita != NULL)
//     {
//         troca_max_esq(troca->direita, raiz, troca);
//         return;
//     }
//     if(raiz == ant) {
//         ant->esquerda = troca->esquerda;
//     }
//     else {
//         ant->direita = troca->esquerda;
//     }
//     raiz->cliente = troca->cliente;
//     free(troca);
//     troca = NULL;
// }

// // Function to print binary tree in 2D
// // It does reverse inorder traversal
// // https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
// static void print2DUtil(NODE *root, int space)
// {
//     // Base case
//     if (root == NULL)
//         return;

//     // Increase distance between levels
//     space += COUNT;

//     // Process right child first
//     print2DUtil(root->direita, space);

//     // Print current node after space
//     // count
//     printf("\n");
//     for (int i = COUNT; i < space; i++)
//         printf(" ");
//     printf("%d\n", cliente_get_chave(root->cliente));

//     // Process left child
//     print2DUtil(root->esquerda, space);
// }

// // Wrapper over print2DUtil()
// void arvore_binaria_imprimir(ARVORE_BINARIA *root)
// {
//     // Pass initial space count as 0
//     print2DUtil(root->raiz, 0);
// }





