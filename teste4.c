#include <stdio.h>

#include "lista_ligada.h"

int main()
{
    ListaLigada *lista = cria_lista();
    insere(lista, 6, 0);
    insere(lista, 8, 1);
    insere(lista, 1, 2);
    insere(lista, 5, 3);
    insere(lista, 9, 4);
    insere(lista, 7, 5);
    insere(lista, 1, 6);

    ListaLigada *listaDividida = divide_lista(lista);

    imprime(lista);
    imprime(listaDividida);

    return 0;
}