/* �rvore Bin�ria - Binary Tree
 *
 * S�o estruturas de dados caracterizadas por:
 * ou, n�o tem elemento algum (�rvore vazia).
 *
 * ou tem um elemento distinto, denominado raiz,
 * com dois apontamentos para duas estruturas diferentes,
 * denominadas sub-�rove esquerda e sub-�rvore direita.
 *
 * existe uma regra para adifree(t);cionar valores na �rvore,
 * se o valor novo for menor do que j� existe na �rvore �
 * criado um apontamento a esquerda caso contr�rio � criado
 * a direita.
 */

struct st_arvore{
    int valor;
    struct st_arvore *direita; //sub-�rvore direita
    struct st_arvore *esquerda; //sub-�rvore esquerda
};

typedef struct st_arvore arvore;

/*Na cria��o da �rvore retorna um ponteiro nulo*/
arvore* criaArvore(){
    return NULL;
}

/*Verifica se a �rvore est� vazia retornando nulo*/
int arvoreEstaVazia(arvore* t){
    return t == NULL;
}

void insereDadoArvore(arvore** t, int num){
    if(*t == NULL){// sendo nula ela n�o existe ainda
        *t = (arvore*)malloc(sizeof(arvore));
        (*t)->esquerda = NULL;// acessa o valor e aponta esquerda pra NULL
        (*t)->direita = NULL;
        (*t)->valor = num;// �rvore recebe um valor
    }else{// se a �rvore j� tiver valores, seus galhos estar�o vazios e adicionaremos os valores nos galhos
        if(num < (*t)->valor){
            insereDadoArvore(&(*t)->esquerda, num);
        }
        if(num > (*t)-> valor){
            insereDadoArvore(&(*t)->direita, num);
        }
    }
}

int estaNaArvore(arvore* t, int num){ // busca em �rvore bin�ria
    if(arvoreEstaVazia(t)){
        return 0;
    }
    return t->valor==num || estaNaArvore(t->esquerda, num) || estaNaArvore(t->direita, num);
    //esse return verifica pros dois ramos da �rvore se existe o valor.
}

/*--- O em ordem, busca o �ltimo � esquerda, depois volta at� o n� onde ele ter�
que ir � direita. Ap�s isso ele busca o �ltimo � esquerda e volta....---*/
void exibirEmOrdem(arvore *pRaiz){//recebe o n� raiz, de novo aquela confus�o com o nome da vari�vel
	if(pRaiz != NULL){//verifica se o n� atual existe, pois ao ser chamado pRaiz->direita ou pRaiz->esquerda, sabemos que poder�o ser nulos
            exibirEmOrdem(pRaiz->esquerda);//chamada recursiva para o pr�ximo � esquerda, e ser� chamado at� o �ltimo � esquerda.
            printf("\n%i", pRaiz->valor);//Ao chegar no �ltimo � esquerda, ou seja, for pRaiz->esquerda for NULL, ele come�a a printar, e vai printando todos os n�s por onde ele passou, "voltando"
            exibirEmOrdem(pRaiz->direita);//� chamado o n� a direita, seguindo o fluxo
	}
}

void exibirPreOrdem(arvore *pRaiz){//Pr�-Ordem � mais simples, no n� que ele t�, ele j� printa. Come�a pela raiz e vai printando at� o �ltimo a esquerda, depois volta pro n� onde ele ter� que ir at� a esquerda e volta denovo a buscar o �ltimo a esquerda e segue o fluxo.
    if(pRaiz != NULL){//mesmo teste anterior
        printf("\n%i", pRaiz->valor);//assim que est� no n�, j� faz o print
        exibirPreOrdem(pRaiz->esquerda);//faz a chamada recursiva pro n� a esquerda, perceba que o pRaiz->direita s� � chamado quando passa por todos os n�s a esquerda
        exibirPreOrdem(pRaiz->direita);//chamada recursiva para n� � direita
    }
}

void exibirPosOrdem(arvore *pRaiz){//P�s-ordem � o que eu acho mais complicado, mas n�o imposs�vel de entender. A ideia basicamente � passar por toda a �rvore, e s� depois vir fazendo os prints. Ele busca o �ltimo a esquerda, depois volta pro n� que tiver que voltar e vai pra direita, sem printar nada, e busca de novo o �ltimo a esquerda, ate varrer toda a �rvore, depois ele vai printando tudo.
    if(pRaiz != NULL){
        exibirPosOrdem(pRaiz->esquerda);
        exibirPosOrdem(pRaiz->direita);
        printf("\n%i", pRaiz->valor);
    }
}
