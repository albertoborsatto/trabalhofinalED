#include <stdio.h>
#include <time.h> //para usar a função time e clock
#include "abp.h"
#include <stdlib.h> //para usar função srand
#define MAX 1000000

int main()
{
	int i, j, num, busca;
	int valores[5]; //array para armazenar os 5 valores aleatório a serem procurados na lista 
	int conta = 0, conta2 = 0; //variáveis para contar o número de comparações das funções
	float media = 0;
	pNodoA *arv1 = NULL;
	clock_t tempo;
	srand(time(NULL));

	printf("\nNumero de dados: %d\n", MAX);

	tempo = clock(); //inicializa a contagem do tempo do processo
	for(i = 1; i <= MAX; i++) 
	{
		num = (rand() % 1000) * 1000 + rand(); //gera os números aleatórios para inserir na lista
		arv1 = InsereArvore(arv1, num, &conta);
	}
	tempo = clock() - tempo; //encerra a contagem do tempo do processo
	printf("\nTempo de insercao: %f\n", (float)tempo / CLOCKS_PER_SEC);
	printf("\nNumero de comparacoes(insercao) = %d\n", conta);

	for(i = 0; i < 5; i++)
		valores[i] = (rand() % 1000) * 1000 + rand(); //gera os 5 números para procurar dentro da lista

	tempo = clock();
	/*loop para procurar os números na lista e contar o número de comparações realizadas*/
	for(j = 0; j < 5; j++)
	{
		for(i = 0; i < 10000; i++)
		{
			busca = valores[j];
        	buscaNum(arv1, busca, &conta2);
        }
        printf("\nNumero de comparacoes(busca) valor %d: %d\n", valores[j], conta2/10000);
        conta2 = 0;
	}	
	tempo = clock() - tempo;
	media = tempo / 5; //media do tempo das buscas
    printf("\nMedia tempo das 5 buscas: %f\n", (float)tempo / CLOCKS_PER_SEC);

	return 0;

}



