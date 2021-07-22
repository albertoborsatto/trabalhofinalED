#include <stdio.h>
#include <stdlib.h>
#include <time.h> //para usar a função time e clock
#include "abp.h"
#define MAX 10000
#define BUSCA 10000

int main()
{
	int i, num;
	int conta = 0, conta2 = 0, conta3 = 0, conta4 = 0; //variáveis para contar o número de comparações das funções
	pNodoA *arv1 = NULL;
	clock_t tempo;

	printf("\nNumero de dados: %d\n", MAX);

	tempo = clock(); //inicializa a contagem do tempo do processo
	for(i = 1; i <= MAX; i++) //loop para criar os nodos da árvore
	{
		arv1 = InsereArvore(arv1, i, &conta);
	}
	tempo = clock() - tempo; //encerra a contagem do tempo do processo
	printf("\nTempo de insercao: %f\n", (float)tempo / CLOCKS_PER_SEC);
	printf("\nNumero de comparacoes(insercao) = %d\n", conta);

	/*Faz a busca do primeiro elemento inserido na árvore e conta o tempo do processo*/
	num = 1;
	tempo = clock();
	for(i = 0; i < 1000; i++)
		buscaNum(arv1, num, &conta2);
	tempo = clock() - tempo;
	printf("\nTempo busca primeiro: %f\n", (float)tempo / CLOCKS_PER_SEC);
	printf("Numero de comparacoes(busca) = %d\n", conta2/1000);

	/*Faz a busca do último elemento inserido na árvore e conta o tempo do processo*/
    num = BUSCA;
    tempo = clock();
    for(i = 0; i < 1000; i++)
    	buscaNum(arv1, num, &conta3);
    tempo = clock() - tempo;
    printf("\nTempo busca ultimo: %f\n", (float)tempo / CLOCKS_PER_SEC);
    printf("Numero de comparacoes(busca) = %d\n", conta3/1000);

    /*Faz a busca do elemento do meio da árvore e conta o tempo do processo*/
    num = BUSCA/2;
    tempo = clock();
    	for(i = 0; i < 1000; i++)
    buscaNum(arv1, num, &conta4);
    tempo = clock() - tempo;
    printf("\nTempo busca meio: %f\n", (float)tempo / CLOCKS_PER_SEC);
    printf("Numero de comparacoes(busca) = %d\n", conta4/1000);

    libera_arvore(arv1);


	return 0;

}



