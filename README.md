### Descrição

Exercicio prático desenvolvido na disciplina de Algorítmos e Estruturas de Dados 1 para simular o cadastro de pessoas fisicas em um banco com uma estrutura de Árvore Binaria.

### Entrada
O algoritmo recebe como entrada um número _n_, que representa a quantidade de clientes cadastrados no banco.
Após isso ele receberá um sequência de _n_ registros, representando os **CPFs** , **Nomes**, **Idades** e **Saldos** dos clientes.

O primeiro indivíduo é considerado como a raiz da árvore, os demais cadastros são inseridos na árvore por uma regra que facilita a busca por pessoas:

Caso o valor numérico do CPF do novo registro de cliente seja **maior** que o valor do cpf da raiz, ele é inserido na sua sub-árvore **direita**, caso contrário, na sua sub-árvore **esquerda** e assim sucessivamente até encontrar a posição adequada.

Exemplo:
```
5
186.161.140-41;Heitor Rafael Fernandes;57;-5911.43
834.772.252-87;Heitor Júlia Fernandes;82;-8666.55
977.535.257-60;Alice Bernardo Carvalho;55;1520.47
150.664.433-39;Pedro Mendes;38;-3435.54
550.980.261-80;Pedro Henrique Arthur Davi Gomes;32;-4320.64
```

### Saída
Como saída, o programa apresenta os dados de cpf das pessoas, percorrendo a ávore pelas regras **Inorder**, **Preorder**, **Postorder**:
```
Inorder
15066443339
18616114041
55098026180
83477225287
97753525760

Preorder
18616114041
15066443339
83477225287
55098026180
97753525760

Postorder
15066443339
55098026180
97753525760
83477225287
18616114041
```
