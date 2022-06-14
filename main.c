#include <stdio.h>
#include "arvore.h"
#include "cliente.h"

int main(void)
{

    ARVORE* arvore;
    arvore = arvore_criar();

    int n;
    scanf("%d", &n);

    getchar();

    for(int i = 0; i<n; i++)
    {
        CLIENTE* cliente;
        cliente = cliente_ler_std_in();

        //inserir cliente na arvore

        abb_inserir(arvore, cliente);

    } 

    printf("Inorder\n");
    arvore_em_ordem(arvore);
    printf("\n");
    printf("Preordem\n");
    arvore_pre_ordem(arvore);
    printf("\n");
    printf("Posordem\n");
    arvore_pos_ordem(arvore);
    printf("\n");

    arvore_apagar(&arvore);

}

// // 118.469.561-02,Maria Cecília Gonçalves,50,3318.74
// // 498.228.938-76,Júlia Lorena Isadora Ribeiro,68,-20278.86
// // 250.627.718-89,Gabriel Maite Helena Martins,41,15079.44
// // 904.621.899-61,Lívia Isadora Joaquim Santos,47,9113.10
// // 025.801.967-06,Samuel Marques,23,-3041.86
// // 539.696.899-02,Joaquim Samuel Sophia Jesus,0,6868.53

// 186.161.140-41,Heitor Rafael Fernandes,57,-5911.43
// 834.772.252-87,Heitor Júlia Fernandes,82,-8666.55
// 977.535.257-60,Alice Bernardo Carvalho,55,1520.47
// 150.664.433-39,Pedro Mendes,38,-3435.54
// 550.980.261-80,Pedro Henrique Arthur Davi Gomes,32,-4320.64