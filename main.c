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
