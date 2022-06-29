#include "arvore.h"

ARVORE* arvore_criar()
{
    ARVORE* arvore = (ARVORE*)malloc(sizeof(ARVORE));
    if(arvore)
    {
        arvore->raiz = NULL;
    }
    return arvore;
}

static NODE* cria_node(CLIENTE *cliente)
{
    NODE *novoNode = (NODE*) malloc(sizeof(NODE));
    if(!novoNode) 
    {
        return NULL;
    }
    novoNode->cliente = cliente;
    novoNode->direita = NULL;
    novoNode->esquerda = NULL;
    return novoNode;
}

////  INSERIR NO NA ARVORE BINARIA DE BUSCA =========================================================================

boolean ehMenor(const NODE *raiz, CLIENTE *cliente);
boolean ehMaior(const NODE *raiz, CLIENTE *cliente);


NODE *abb_inserir_no(NODE *raiz, CLIENTE *cliente)
{
    if (raiz == NULL)
        raiz = cria_node(cliente);
    else if(ehMaior(raiz, cliente))
        raiz->direita = abb_inserir_no(raiz->direita, cliente);
    else if(ehMenor(raiz, cliente))
        raiz->esquerda = abb_inserir_no(raiz->esquerda, cliente);
    return raiz;
}

boolean abb_inserir(ARVORE *T, CLIENTE *cliente)
{
    return((T->raiz = abb_inserir_no(T->raiz, cliente)) != NULL);
}

boolean ehMenor(const NODE *raiz, CLIENTE *cliente) 
{
    return cliente_get_cpf(cliente) < cliente_get_cpf(raiz->cliente);
}

boolean ehMaior(const NODE *raiz, CLIENTE *cliente) 
{
    return cliente_get_cpf(cliente) > cliente_get_cpf(raiz->cliente);
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

//=========================================================================

//OBS// 
// essa chamada de interna é somente para esconder o codigo. Como é necessario passar a raiz para a função
// ao inves de passarmos isso na main, criamos uma função que recebe a arvore e passa a raiz pra essa func, para esconder o codigo.

static void arvore_pre_ordem_interna(NODE* raiz)
{
    if(raiz)
    {
        cliente_printa_cpf_num(raiz->cliente);
        arvore_pre_ordem_interna(raiz->esquerda);
        arvore_pre_ordem_interna(raiz->direita);
    }
}

void arvore_pre_ordem(ARVORE* arvore)
{
    arvore_pre_ordem_interna(arvore->raiz);
}

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
