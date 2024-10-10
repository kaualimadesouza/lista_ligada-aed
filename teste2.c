#include <stdio.h>

#include "lista_ligada.h"

int main()
{
    int x;
    ListaLigada *lista = cria_lista();

    insere(lista, 3, 0);
    insere(lista, 1, 1);
    insere(lista, 5, 2);

    imprime(lista);

    int i;
    int soma = 0;
    int n = tamanho(lista);
    for (i = 0; i < n; i++)
        soma += valor_indice(lista, i);
    printf("Soma : %d\n", soma);

    destroi_lista(lista);
    return 0;
}