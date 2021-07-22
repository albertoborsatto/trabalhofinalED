#include <stdio.h>
#include <stdlib.h>
#include "abp.h"


pNodoA* InsereArvore(pNodoA *a, tipoinfo ch, int *conta)
{


	if(a == NULL) //se a árvore for vazia
	{
		a = (pNodoA*) malloc(sizeof(pNodoA)); //cria o primeiro nodo
		a->info = ch; //coloca o número informado na main para ser o número do primeiro nodo
		a->esq = NULL;
		a->dir = NULL; //seta os filhos do nodo como sendo NULL
		return a;
	}
	else //caso a árvore não seja vazia
		if(ch < a->info)
		{
			a->esq = InsereArvore(a->esq, ch, conta); //se o número informado for menor que a raíz, cria o nodo na esquerda
			*conta += 1;
		}

		else if(ch > a->info)
		{
			a->dir = InsereArvore(a->dir, ch, conta); //se o número informado for maior que a raíz, cria o nodo na direita
			*conta += 1;
		}
		
	
	return a;
}

int buscaNum(pNodoA *a, int num, int *conta)
{

	*conta += 1;
	
	if(a != NULL)
	{
		*conta += 1;
		if(a->info == num)
			return 0; //se o número da raíz for o mesmo que o procurado
		
		else //caso contrário, vê se o número é maior ou menor que o número da raíz
		{
			*conta += 1;
			if(a->info > num)
				buscaNum(a->esq, num, conta); //se for menor, continua checando na esquerda da árvore
			else
				buscaNum(a->dir, num, conta); //se for maior, continua checando na direita da árvore
		}
	}
}

void libera_arvore(pNodoA *arv)
{
	if(arv != NULL) //percorre toda a árvore aplicando a função free para liberar o espaço locado para a árvore
	{
		libera_arvore(arv->esq);
		libera_arvore(arv->dir);
		free(arv);	
	}
}

