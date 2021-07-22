typedef int tipoinfo;

struct TNodoA{
        tipoinfo info;
        struct TNodoA *esq;
        struct TNodoA *dir;
};

typedef struct TNodoA pNodoA;

/*a função insere os nodos na árvore*/
pNodoA* InsereArvore(pNodoA *a, tipoinfo chm, int *conta);

/*a função recebe uma árvore e um número e procura esse número dentro da árvore*/
int buscaNum(pNodoA *a, int num, int *conta);

/*a função libera os espaços da memória alocados para os nodos*/
void libera_arvore(pNodoA *arv);


