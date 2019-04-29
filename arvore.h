/* �rvore Bin�ria - Binary Tree

- S�o estruturas de dados caracterizadas por:

- ou, n�o tem elemento algum (�rvore vazia);
- ou tem um elemento distinto, denominado raiz,
com dois apontamentos para duas estruturas diferentes,
denominadas sub-�rove esquerda e sub-�rvore direita.
- existe uma regra para adicionar valores na �rvore,
se o valor novo for menor do que j� existe na �rvore �
criado um apontamento a esquerda caso contr�rio � criado
a direita. */

struct st_arvore{
    int valor;
    struct st_arvore *sad; //sub-�rvore direita
    struct st_arvore *sae; //sub-�rvore esquerda
};

typedef struct st_arvore arvore;

arvore* criaArvore(){ //na cria��o da �rvore retorna um ponteiro nulo
    return NULL;
}

int arvoreEstaVazia(arvore* t){ //verifica se a �rvore est� vazia retornando nulo
    return t == NULL;
}

void mostraArvore(arvore* t){
    printf("<");//coloquei pra facilitar a visualiza��o da �rvore
    if(!arvoreEstaVazia(t)){
        printf("%d ", t->valor);// se n�o for vazia mostra o valor
        mostraArvore(t->sae);// mostra os galhos da �rvore
        mostraArvore(t->sad);
    }
    printf(">");
}

void insereDadoArvore(arvore** t, int num){
    if(*t == NULL){// sendo nula ela n�o existe ainda
        *t = (arvore*)malloc(sizeof(arvore));
        (*t)->sae = NULL;// acessa o valor e aponta sae pra NULL
        (*t)->sad = NULL;
        (*t)->valor = num;// �rvore recebe um valor
    }else{// se a �rvore j� tiver valores, seus galhos estar�o vazios e adicionaremos os valores nos galhos
        if(num < (*t)->valor){
            insereDadoArvore(&(*t)->sae, num);
        }
        if(num > (*t)-> valor){
            insereDadoArvore(&(*t)->sad, num);
        }
    }
}

int estaNaArvore(arvore* t, int num){ // busca em �rvore bin�ria
    if(arvoreEstaVazia(t)){
        return 0;
    }
    return t->valor==num || estaNaArvore(t->sae, num) || estaNaArvore(t->sad, num);
    //esse return verifica pros dois ramos da �rvore se existe o valor.
}
