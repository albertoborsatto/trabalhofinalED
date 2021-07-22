#include <stdio.h>
#include <stdlib.h> //para usar função srand
#include "lse.h"
#include <time.h> //para usar a função time e clock
#define MAX 100000


int main()
{
    int num, i, j, busca;
    int conta = 0, conta2 = 0; //variáveis para contar o número de comparações das funções
    int valores[5]; //array para armazenar os 5 valores aleatório a serem procurados na lista
    float media = 0;
    ptLSE *ptLista;
    clock_t tempo;
    srand(time(NULL)); //função para gera números realmente aleatórios

    printf("\nNumero de dados: %d\n", MAX);

    ptLista = criaLista();
    tempo = clock(); //inicializa a contagem do tempo do processo
    for(i = 1; i <= MAX; i++)
    {
    	num = rand() % MAX; //gera os números aleatórios para inserir na lista
    	if(i == 0)
    		ptLista = insereIni(ptLista, num);
    	else
    		ptLista = insereFim(ptLista, num, &conta);
    }
    tempo = clock() - tempo; //encerra a contagem do tempo do processo
    printf("\nTempo: %f\n", (float)tempo / CLOCKS_PER_SEC);
    printf("\nNumero de comparacoes(insercao) = %d\n", conta);

    for(i = 0; i < 5; i++)
    	valores[i] = rand() % MAX; //gera os 5 números para procurar dentro da lista

    tempo = clock();
    /*loop para procurar os números na lista e contar o número de comparações realizadas*/
    for(j = 0; j < 5; j++)
    {
        for(i = 0; i < 1000; i++)
    	{
        	busca = valores[j];
        	buscaNum(ptLista, busca, &conta2);
        }
        printf("\nNumero de comparacoes(busca) valor %d: %d\n", valores[j], conta2/1000);
        conta2 = 0;
    }
    tempo = clock() - tempo;
    media = tempo / 5; //media do tempo das buscas
    printf("\nMedia tempo das 5 buscas: %f\n", ((float)media / CLOCKS_PER_SEC));

    return 0;
}
