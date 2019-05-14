/* �rvore Bin�ria - Binary Tree
 *
 * S�o estruturas de dados caracterizadas por:
 * ou, n�o tem elemento algum (�rvore vazia).
 *
 * ou tem um elemento distinto, denominado raiz,
 * com dois apontamentos para duas estruturas diferentes,
 * denominadas sub-�rove esquerda e sub-�rvore direita.
 *
 * existe uma regra para adicionar valores na �rvore,
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

//void criaArvore(arvore** t){
//    *t = NULL;
//}

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

char menu_principal()
{
    printf("  1 - Criar %crvore\n",160);
    printf("  2 - Listar %crvore\n",160);
    printf("  3 - Pesquisar na %crvore\n",160);
    printf("  4 - Inserir na %crvore\n",160);
    printf("  5 - Excluir item da %crvore\n",160);
    printf("  6 - Esvaziar %crvore\n",160);
    printf("  7 - Contar N%cs\n", 162);
    printf("  8 - Contar folhas\n");
    printf("  9 - Altura da %crvore\n", 160);
    printf("  0 - Sair do aplicativo\n\n");
    printf("  ESCOLHA UM OP%c%cO: ",128,199);
    return getche();
}

char sub_menu()
{
    printf("  1 - Listar em ordem\n",160);
    printf("  2 - Listar em pre ordem\n",160);
    printf("  3 - Listar em pos ordem\n",160);
    printf("  0 - Voltar ao menu\n\n");
    printf("  ESCOLHA UM OP%c%cO: ",128,199);
    return getche();
}

arvore* MaiorDireita(arvore** no) //Essas duas fun��es, *MaiorDireita e *MenorEsquerda s�o duas fun��es auxiliares. V�o ser usadas na hora de remover um N� que tenha filhos a direita e a esquerda
{
//essa fun��o vai ser usada pra, como o pr�prio nome j� diz, buscar o Maior n� a direita
//Recebe um arvore** no que ser� o n� a ser removido, a partir dai ele busca o maior � direita
    if((*no)->direita != NULL)//caso seja diferente de null, ou seja, existe algum n� � direita, ele chama recursivamente o pr�ximo n� � direita
        return MaiorDireita(&(*no)->direita);
    else //caso contr�rio, esse � o maior n� a direita.
    {
        arvore *aux = *no;//faz um backup do n�, pois ele ir� excluir esse n�, e ir� adicion�-lo em outro lugar
        if((*no)->esquerda != NULL) // se nao houver essa verificacao, esse n� vai perder todos os seus filhos da esquerda!
            *no = (*no)->esquerda;
        else
            *no = NULL;
        return aux;
    }
}

arvore* MenorEsquerda(arvore** no) //Essa fun��o tem a mesma caracter�stica da anterior. Dependendo da sua abordagem, voc� pode usar uma ou outra. Se a sua abordagem � de pegar o Menor � esquerda, use essa fun��o, caso contr�rio, utilize a anterior.
{
    if((*no)->esquerda != NULL)
        return MenorEsquerda(&(*no)->esquerda);
    else
    {
        arvore *aux = *no;
        if((*no)->direita != NULL) // se nao houver essa verificacao, esse n� vai perder todos os seus filhos da direita!
            *no = (*no)->direita;
        else
            *no = NULL;
        return aux;
    }
}

void remover(arvore** t, int valor){ //Mais uma vez aquela confus�o do **pRaiz, mas j� est� ciente do problema. A fun��o recebe o n� raiz, e um n�mero a ser removido. Ir� fazer uma busca de onde est� esse n�mero e depois executa a l�gica de remo��o.

    if(*t == NULL)    // esta verificacao serve para caso o numero nao exista na arvore.
    {
        printf("Numero nao existe na arvore!");
        getch();
        return;
    }

    if(valor < (*t)->valor)//verifica se o n�mero � menor que o n�mero do N� atual, na busca.
        remover(&(*t)->esquerda, valor);//chamada recursiva para caso seja menor
    else//caso contr�rio, ele ser� o n�mero ou ser� maior
        if(valor > (*t)->valor)//verifica se o n�mero � maior que o n�mero do N� atual, na busca.
            remover(&(*t)->direita, valor);//chamada recursiva para caso seja maior
        else     // se nao eh menor nem maior, logo, eh o numero que estou procurando! :)
        {
            arvore *aux = *t;     // faz um backup do N� a ser removido
            if (((*t)->esquerda == NULL) && ((*t)->direita == NULL)) // verifica se n�o tem filho nem a direita, nem a esquerda, ou seja, n�o tem filhos.
            {
                free(aux);//Nesse Caso, � bem simples, � s� desalocar, liberar esse n� da mem�ria
                (*t) = NULL;
            }
            else      // so tem o filho da direita
            {
                if ((*t)->esquerda == NULL) //Verifica se n�o tem filho a esquerda, caracterizando como tendo filhos somente a direita.
                {
                    (*t) = (*t)->direita;//o N� atual, recebe o seu filho a direta, fazendo com que ele desapare�a e o seu pr�ximo filho substitua o seu lugar
                    aux->direita = NULL;//o backup se faz necess�rio para isso, para voc� cortar essa liga��o, caso contr�rio, teria um n� em mem�ria que teriam os antigos filhos
                    free(aux);
                    aux = NULL;// e tamb�m para poder liber�-lo da mem�ria depois
                }
                else             //so tem filho da esquerda
                {
                    if ((*t)->direita == NULL) //MESMO CASO ANTERIOR, s� que nesse caso, s� existem filhos a esquerda.
                    {
                        (*t) = (*t)->esquerda;
                        aux->esquerda = NULL;
                        free(aux);
                        aux = NULL;
                    }
                    else //Quando existe filhos a direita e a esquerda. Escolhi fazer o maior filho direito da subarvore esquerda.
                    {
                        aux = MaiorDireita(&(*t)->esquerda); //Faz um backup do Maior a direita, pois ele usar� o maior a direita no local do N� a ser removido. Se vc quiser usar o Menor da esquerda, so o que mudaria seria isso: aux = MenorEsquerda(&(*t)->direita);
                        aux->esquerda = (*t)->esquerda;          //o N�(Maior a Direita) ir� receber os filhos a esquerda do N� que ser� removido
                        aux->direita = (*t)->direita;//o N�(Maior a Direita) ir� receber os filhos a direita do N� que ser� removido
                        (*t)->esquerda = (*t)->direita = NULL;//O N� que ser� removido, perde seus filhos, ou seja, recebe NULL
                        free((*t));
                        *t = aux;
                        aux = NULL;   //Enfim, libera-se da mem�ria o n� a ser removido
                    }
                }
            }
        }
}

int contarNos(arvore **t){
    if((*t) == NULL)
        return 0;
    else
        return 1 + contarNos(&(*t)->esquerda) + contarNos(&(*t)->direita);
}

/* Folha � um n� que n�o tem filho algum */
int contarFolhas(arvore **t){
    if((*t) == NULL)
        return 0;
    if((*t)->esquerda == NULL && (*t)->direita == NULL)
        return 1;
    return contarFolhas(&(*t)->esquerda) + contarFolhas(&(*t)->direita);
}

int altura(arvore* t)
{
    if (t == NULL)
        return 0;
    else
    {
        /* Recebe altura de cada sub-arvore */
        int eAltura = altura(t->esquerda);
        int dAltura = altura(t->direita);

        /* Usa a altura maior pra dizer o tamanho da �rvore */
        if (eAltura > dAltura)
            return(eAltura + 1);
        else return(dAltura + 1);
    }
}

void apagaArvore (struct st_arvore *t){
    if (t == NULL)
        return;

    /* primeiro deleta as duas sub-arvores */
    apagaArvore(t->esquerda);
    apagaArvore(t->direita);

    /* depois deleta o n� */
    printf("\n Excluindo o n%c: %d", 162, t->valor);
    free(t);
}

