#include <stdio.h>
#include <stdlib.h> //para utilizar a função malloc
#include "lse.h"

ptLSE *criaLista(void)
{
    return NULL;
}

ptLSE* insereIni(ptLSE* ptLista, int num)
{
    ptLSE *novo; //elemento novo para a lista

    /*aloca memória para um novo nodo na lista*/
    novo = (ptLSE*) malloc(sizeof(ptLSE));

    /*define o número informado pelo usuário como o número do novo nodo na lista*/
    novo->numero = num;

    /*define o segundo nodo da lista como sendo o primeiro da lista anterior*/
    novo->prox = ptLista;

    /*iguala ptLista ao novo para o retorno da função*/
    ptLista = novo;

    return ptLista;

}


ptLSE* insereFim(ptLSE* ptLista, int num, int *conta)
{
    ptLSE *novo, *ptAux=ptLista; //ponteiro auxiliar para percorrer a lista;


    novo = (ptLSE*) malloc(sizeof(ptLSE));
    novo->numero = num;

    /*caso a lista seja vazia, coloca o novo nodo como primeiro da lista*/
    if (ptLista == NULL)
    {
        *conta += 1;
        novo->prox = ptLista;
        ptLista = novo;
    }
    else
    {
        /*percorre toda a lista*/
        while(ptAux->prox != NULL)
        {
            *conta += 1;
            ptAux = ptAux->prox;
        }

        /*coloca o novo nodo como sendo o último da lista*/
        ptAux->prox = novo;

        /*define NULL como o próximo do novo último elemento da lista*/
        novo->prox = NULL;
    }

    return ptLista;
}

int buscaNum(ptLSE* ptLista, int num, int *conta)
{
    *conta += 1;

    ptLSE* aux = ptLista; //ponteiro auxiliar para percorrer a lista
    
	if(aux != NULL) 
    {
        *conta += 1;
        if(aux->numero == num) //se o primeiro elemento da lista for igual ao número procurado
        	return 0;
        else
        	buscaNum(aux->prox, num, conta);
    }
}

ptLSE *destroi(ptLSE *ptLista)
{
    ptLSE *ptaux;

    /*percorre a lista e destrói um por um dos nodos e mostra os elementos que estão sendo desalocados*/
    while (ptLista != NULL)
    {
        ptaux = ptLista;
        ptLista = ptLista->prox;
        free(ptaux);
    }
    return NULL;
}