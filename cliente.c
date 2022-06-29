#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "cliente.h"

struct cliente_st
{
    char cpf[16];
    char nome[50];
    int idade;
    float saldo;
};

CLIENTE* cliente_criar(char* cpf, char* nome, int idade, float saldo)
{
    CLIENTE* cliente;
    cliente = (CLIENTE*) malloc(sizeof(CLIENTE));

    if(cliente != NULL)
    {
        strcpy(cliente->cpf, cpf);
        strcpy(cliente->nome, nome);
        cliente->idade = idade;
        cliente->saldo = saldo;
        
        return cliente;
    }
    return NULL;
}

CLIENTE* cliente_ler_std_in()
{
    CLIENTE cliente;

    char input[100];
    fgets(input, 100, stdin);
    
    char idade[3], saldo[20];

    strcpy(cliente.cpf, strtok(input, ";"));
    strcpy(cliente.nome, strtok(NULL, ";"));
    strcpy(idade, strtok(NULL, ";"));
    strcpy(saldo, strtok(NULL, ";"));

    cliente.idade = atoi(idade);
    cliente.saldo = atof(saldo);
    
    return cliente_criar(cliente.cpf, cliente.nome, cliente.idade, cliente.saldo);
}


boolean cliente_apagar(CLIENTE **cliente)
{
    if (*cliente != NULL)
    {
        free (*cliente);
        *cliente = NULL;
        return TRUE;
    }
    return FALSE;
}

void cliente_imprimir(const CLIENTE *cliente)
{
    if (cliente != NULL)
    {
        printf("\n-->cpf: %s", cliente->cpf);
        printf("\n-->nome: %s", cliente->nome);
        printf("\n-->idade: %d", cliente->idade);
        printf("\n-->saldo: %.2f\n", cliente->saldo);
    }
}

long long int cliente_get_cpf(CLIENTE *cliente)
{
    char copia_cpf[15];
    strcpy(copia_cpf, cliente->cpf);
    char cpf1[4], cpf2[4], cpf3[4], cpf4[4];
    strcpy(cpf1, strtok(copia_cpf, "."));
    strcpy(cpf2, strtok(NULL, "."));
    strcpy(cpf3, strtok(NULL, "-"));
    strcpy(cpf4, strtok(NULL, ""));

    char cpfNum[12];
    strcpy(cpfNum, cpf1);
    strcat(cpfNum, cpf2);
    strcat(cpfNum, cpf3);
    strcat(cpfNum, cpf4);

    long long int cpfNumero;
    char *ptrAux;
    cpfNumero = strtol(cpfNum, &ptrAux, 10);
    
    return cpfNumero;
}

void cliente_printa_cpf(CLIENTE* cliente)
{
    if(cliente != NULL)
    {
        printf("cpf: %s\n", cliente->cpf);
    }
}

void cliente_printa_cpf_num(CLIENTE* cliente)
{
    if(cliente != NULL)
    {
        printf("%lld\n", cliente_get_cpf(cliente));
    }
}
