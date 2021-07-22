typedef int tipoinfo;

struct TNodoA{
        tipoinfo info;
        struct TNodoA *esq;
        struct TNodoA *dir;
};

typedef struct TNodoA pNodoA;

/* a função insere os nodos na árvore*/
pNodoA* InsereArvore(pNodoA *a, tipoinfo ch, int *conta);


/*a função recebe a árvore e um número e busca o número dentro da árvore criada*/
int buscaNum(pNodoA *a, int num, int *conta);

/*a função libera o espaço da memória alocado para os nodos da árvore*/
void libera_arvore(pNodoA *arv);

