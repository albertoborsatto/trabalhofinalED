#include <stdio.h>
#include <stdlib.h>
#include "abp.h"

pNodoA* InsereArvore(pNodoA *a, tipoinfo ch, int *conta)
{
	if(a == NULL) //se a árvore for vazia, cria o primeiro nodo dela
	{
		*conta += 1;
		a = (pNodoA*) malloc(sizeof(pNodoA));
		a->info = ch;
		a->esq = NULL;
		a->dir = NULL;
		return a;
	}
	else //se a árvore não for vazia
	if(ch < a->info) //se o número for menor que a raíz, coloca ele na esquerda
	{
		*conta += 1;
		a->esq = InsereArvore(a->esq, ch, conta);
	}
	else if(ch > a->info) //se o número for maior que a raíz, coloca ele na direita
	{
		*conta += 1;
		a->dir = InsereArvore(a->dir, ch, conta);
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

