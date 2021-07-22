#include <stdio.h>
#include <stdlib.h> 
#include "lse.h"
#include <time.h> //para usar a função clock 
#define MAX 5000
#define BUSCA 5000


int main()
{
    int num;
    int i, conta = 0, conta2 = 0, conta3 = 0, conta4 = 0; //variáveis para contar o número de comparações das funções
	ptLSE *ptLista;
    clock_t tempo;
    

    printf("\nNumero de dados: %d\n", MAX);

    /*Cria a lista e conta o tempo do processo de inserção dos elementos*/
    ptLista = criaLista();
    tempo = clock(); //inicializa a variável para contar o tempo do processo
    for(i = 1; i <= MAX; i++)
    {
    	if(i == 0)
    		ptLista = insereIni(ptLista, i);
		else
			ptLista = insereFim(ptLista, i, &conta);
	}
    tempo = clock() - tempo; //tempo final do processo
    printf("\nTempo insercao: %f\n", (float)tempo / CLOCKS_PER_SEC);
    printf("\nNumero de comparacoes(insercao) = %d\n", conta);

    /*Faz a busca do primeiro elemento da lista e conta o tempo do processo*/
   	num = 1;
    tempo = clock();
    for(i = 0; i < 1000; i++)
    	buscaNum(ptLista, num, &conta2);
    tempo = clock() - tempo;
    printf("\nTempo busca primeiro: %f\n", (float)tempo / CLOCKS_PER_SEC);
    printf("Numero de comparacoes(busca) = %d\n", conta2/1000);
    	
   	/*Faz a busca do último elemento da lista e conta o tempo do processo*/
    num = BUSCA;
    tempo = clock();
    for(i = 0; i < 1000; i++)
    		buscaNum(ptLista, num, &conta3);
    tempo = clock() - tempo;
    printf("\nTempo busca ultimo: %f\n", (float)tempo / CLOCKS_PER_SEC);
    printf("Numero de comparacoes(busca) = %d\n", conta3/1000);

    /*Faz a busca do elemento do meio da lista e conta o tempo do processo*/
    num = BUSCA/2;
    tempo = clock();
    for(i = 0; i < 1000; i++)
    	buscaNum(ptLista, num, &conta4);
    tempo = clock() - tempo;
    printf("\nTempo busca meio: %f\n", (float)tempo / CLOCKS_PER_SEC);
    printf("Numero de comparacoes(busca) = %d\n", conta4/1000);

    ptLista = destroi(ptLista);

    return 0;
}
