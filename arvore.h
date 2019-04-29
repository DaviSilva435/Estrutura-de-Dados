struct st_arvore{
    int valor;
    struct st_arvore *sad; //sub-�rvore direita
    struct st_arvore *sae; //sub-�rvore esquerda
};

typedef struct st_arvore arvore;

arvore* criaArvore(){
    return NULL;
}

int arvoreEstaVazia(arvore* t){
    return t == NULL;
}

void mostraArvore(arvore* t){
    printf("<");
    if(!arvoreEstaVazia(t)){
        printf("%d ", t->valor);
        mostraArvore(t->sae);
        mostraArvore(t->sad);
    }
    printf(">");
}

void insereDadoArvore(arvore** t, int num){
    if(*t == NULL){
        *t = (arvore*)malloc(sizeof(arvore));
        (*t)->sae = NULL;
        (*t)->sad = NULL;
        (*t)->valor = num;
    }else{
        if(num < (*t)->valor){
            insereDadoArvore(&(*t)->sae, num);
        }
        if(num > (*t)-> valor){
            insereDadoArvore(&(*t)->sad, num);
        }
    }
}

int estaNaArvore(arvore* t, int num){
    if(arvoreEstaVazia(t)){
        return 0;
    }
    return t->valor==num || estaNaArvore(t->sae, num) || estaNaArvore(t->sad, num);
}
