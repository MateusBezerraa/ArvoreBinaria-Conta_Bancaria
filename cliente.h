#ifndef CLIENTE_H
#define CLIENTE_H

#define ERRO (-32000)
#define TRUE 1
#define FALSE 0
typedef int boolean;

typedef struct cliente_st CLIENTE;

//funções:
CLIENTE* cliente_criar(char* cpf, char* nome, int idade, float saldo);
CLIENTE* cliente_ler_std_in();
boolean cliente_apagar(CLIENTE **cliente);
void cliente_imprimir(const CLIENTE *cliente);
long long int cliente_get_cpf(CLIENTE *cliente);
void cliente_printa_cpf_num(CLIENTE* cliente);
void cliente_printa_cpf(CLIENTE* cliente);




#endif //CLIENTE_H
