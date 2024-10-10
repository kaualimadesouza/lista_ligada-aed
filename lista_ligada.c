#include <stdio.h>
#include <stdlib.h>

#include "lista_ligada.h"

ListaLigada *cria_lista()
{

	ListaLigada *lista = (ListaLigada *)malloc(sizeof(ListaLigada));
	lista->primeiro = NULL;

	return lista;
}

void destroi_lista(ListaLigada *lista)
{

	No *p = lista->primeiro;
	No *tmp;

	while (p)
	{

		tmp = p;
		p = p->proximo;
		free(tmp);
	}

	free(lista);
}

int tamanho(ListaLigada *lista)
{

	int tamanho = 0;

	No *p = lista->primeiro;

	while (p)
	{

		tamanho++;
		p = p->proximo;
	}

	return tamanho;
}

void imprime(ListaLigada *lista)
{

	No *p;

	printf("Lista:");

	for (p = lista->primeiro; p; p = p->proximo)
	{

		printf(" %d", p->valor);
	}

	printf("\n");
}

#ifdef LISTA_ORDENADA
int busca(ListaLigada *lista, Elemento e)
{

	int i = 0;
	No *p = lista->primeiro;

	while (p && p->valor < e)
	{

		p = p->proximo;
		i++;
	}
	return p ? (p->valor == e ? i : -1) : -1;
}
#else
int busca(ListaLigada *lista, Elemento e)
{

	int i = 0;
	No *p = lista->primeiro;

	while (p && p->valor != e)
	{

		p = p->proximo;
		i++;
	}

	return p ? i : -1;
}
#endif

#ifdef LISTA_ORDENADA
Boolean insere(ListaLigada *lista, Elemento e)
{

	No *p;
	No *anterior;
	No *novo = (No *)malloc(sizeof(No));

	novo->valor = e;

	anterior = NULL;
	p = lista->primeiro;

	while (p)
	{

		if (e < p->valor)
			break;

		anterior = p;
		p = p->proximo;
	}

	novo->proximo = p;

	if (anterior)
		anterior->proximo = novo;
	else
		lista->primeiro = novo;

	return TRUE;
}
#else
Boolean insere(ListaLigada *lista, Elemento e, int indice)
{

	int i, antecessor;

	No *p;
	No *novo = (No *)malloc(sizeof(No));

	novo->valor = e;

	if (indice >= 0 && indice <= tamanho(lista))
	{

		if (indice == 0)
		{

			novo->proximo = lista->primeiro;
			lista->primeiro = novo;
		}
		else
		{

			i = 0;
			antecessor = indice - 1;
			p = lista->primeiro;

			while (i < antecessor)
			{

				i++;
				p = p->proximo;
			}

			novo->proximo = p->proximo;
			p->proximo = novo;
		}

		return TRUE;
	}

	return FALSE;
}
#endif

Boolean remove_elemento(ListaLigada *lista, Elemento e)
{

	int i, antecessor;
	int indice = busca(lista, e);
	No *p;
	No *tmp;

	if (indice >= 0)
	{

		if (indice == 0)
		{

			tmp = lista->primeiro;
			lista->primeiro = tmp->proximo;
			free(tmp);
		}
		else
		{

			i = 0;
			antecessor = indice - 1;
			p = lista->primeiro;

			while (i < antecessor)
			{

				i++;
				p = p->proximo;
			}

			tmp = p->proximo;
			p->proximo = tmp->proximo;
			free(tmp);
		}

		return TRUE;
	}

	return FALSE;
}

int valor_indice(ListaLigada *lista, int indice)
{
	No *p = lista->primeiro;
	int i;

	for (i = 0; i <= indice; i++)
	{
		if (i == indice)
		{
			return p->valor;
		}
		p = p->proximo;
	}

	return 0;
}

ListaLigada *junta_listas_1(ListaLigada *lista1, ListaLigada *lista2)
{
	ListaLigada *listajunta = cria_lista();
	No *p1 = lista1->primeiro;
	No *p2 = lista2->primeiro;

	while (p1 != NULL)
	{
		insere(listajunta, p1->valor, tamanho(listajunta));
		p1 = p1->proximo;
	}

	while (p2 != NULL)
	{
		insere(listajunta, p2->valor, tamanho(listajunta));
		p2 = p2->proximo;
	}

	return listajunta;
}

ListaLigada *junta_listas_2(ListaLigada *lista1, ListaLigada *lista2, int indice, Elemento e)
{
	ListaLigada *listajunta = cria_lista();
	No *p1 = lista1->primeiro;
	No *p2 = lista2->primeiro;
	int cont = 0;

	while (p1 != NULL)
	{
		if (cont == indice)
			insere(listajunta, e, tamanho(listajunta));
		else
			insere(listajunta, p1->valor, tamanho(listajunta));

		p1 = p1->proximo;
		cont++;
	}

	while (p2 != NULL)
	{
		if (cont == indice)
			insere(listajunta, e, tamanho(listajunta));
		else
			insere(listajunta, p2->valor, tamanho(listajunta));

		p2 = p2->proximo;
		cont++;
	}

	return listajunta;
}

ListaLigada *divide_lista(ListaLigada *lista)
{
	ListaLigada *listaDois = cria_lista();
	int tamanhoLista = tamanho(lista);
	int cont = 0;
	No *p = lista->primeiro;
	
	if (tamanhoLista % 2 == 0)
	{
		while (cont < (tamanhoLista / 2 - 1))
		{
			p = p->proximo;
			cont++;
		}
		listaDois->primeiro = p->proximo;
		p->proximo = NULL;
	}
	else
	{
		while (cont < (tamanhoLista / 2))
		{
			p = p->proximo;
			cont++;
		}
		listaDois->primeiro = p->proximo;
		p->proximo = NULL;
	}
	return listaDois;
}