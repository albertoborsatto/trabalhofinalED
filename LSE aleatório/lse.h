typedef struct tipoNo ptLSE;
struct tipoNo{
    int numero;
    ptLSE *prox;
};


ptLSE *criaLista(void);

/*a função recebe um ponteiro para a estrutura da lista e o número que o usuário deseja
adicionar na lista e insere ele no início da lista (quando o número digitado é par).*/
ptLSE* insereIni(ptLSE* ptLista, int num);


/*a função recebe um ponteiro para a estrutura da lista e o número que o usuário deseja
adicionar na lista e insere ele no final da lista (quando o número digitado é ímpar).*/
ptLSE* insereFim(ptLSE* ptLista, int num, int *conta);

/*a função recebe uma lista e um número para procurar dentro da lista*/
int buscaNum(ptLSE* ptLista, int num, int *conta);

/*a função desaloca o espaço da memória utilizado para guardar os números da lista*/
ptLSE *destroi(ptLSE *ptLista);

