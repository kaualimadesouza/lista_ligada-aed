#include <stdio.h>

#include "lista_ligada.h"

int main()
{
    ListaLigada *lista1 = cria_lista();
    insere(lista1, 6, 0);
    insere(lista1, 8, 1);
    insere(lista1, 1, 2);

    ListaLigada *lista2 = cria_lista();
    insere(lista2, 2, 0);
    insere(lista2, 4, 1);
    insere(lista2, 3, 2);
    insere(lista2, 1, 3);

    imprime(lista1);
    imprime(lista2);

    ListaLigada *conjuntoListas = junta_listas_2(lista1, lista2, 6, 99);

    imprime(conjuntoListas);

    destroi_lista(lista1);
    destroi_lista(lista2);
    destroi_lista(conjuntoListas);
}