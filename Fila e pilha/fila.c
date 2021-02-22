#include <stdio.h>
#define TAM_FILA 5

//Para o programa , espaços vazios são representados pelo número -1

//Recebe o fim da fila, e verifica se a fila esta cheia, retornando true(1) caso esteja cheia ou false(0) caso não esteja cheia.
int filaCheia(int *fim){
    if (*fim == TAM_FILA-1){  //Se o índice do fim da fila for igual ao tamanho máximo, então ela está cheia.
        return 1;
    }
    return 0;
}

//Recebe o inicio da fila, e verifica se a fila está vazia, retornando true(1) caso esteja vazia ou  false(0) caso não esteja vazia.
int filaVazia(int *inicio){
    if(*inicio == -1){  //Se o índice de início for igual a -1, então a fila está vazia. 
        return 1;
    }
    return 0;
}

//Imprime todos os elementos da fila que não sejam vazios (-1).
void exibirFila(int *fila,int *inicio, int *fim){
    if (!filaVazia(inicio)){  //A lista só será impressa se não estiver vazia.
        for(int i=0; i<TAM_FILA; i++){
            if (fila[i] != -1){  //Índices com elementos vazios(-1) não serão impressos.
                printf("[%d] = %d \n",i,fila[i]);
            }
        }
    }else{  //Mensagem de erro aparecerá caso a lista esteja vazia.
        printf("\nErro de exibicao: a fila esta vazia !\n");
    }
}

//Insere elemento no fim da fila.
void inserirElemento(int *fila, int elemento, int *inicio, int *fim){
    if (!filaCheia(inicio)){  //Só é possível inserir um elemento se a fila não estiver cheia. 
        for (int i=0; i<TAM_FILA; i++){
            if (fila[i] == -1 && i==0){  //Caso a fila esteja vazia, o elemento será inserido na primeira posição.
                fila[i] = elemento;
                *inicio += 1; //Atualizando o inicio da fila.
                *fim += 1; //Atualizando o fim da fila.
                break;
            }else if (fila[i] == -1){  //Caso a fila não esteja vazia, o elemento será inserido no próximo espaço vazio da fila.
                fila[i] = elemento;
                *fim += 1; //Atualizando o fim da fila.
                break;
            }
        }
    }else{  // Caso a fila esteja cheia, será exibido uma mensagem de erro.
        printf("\nErro de insercao: a fila esta cheia !\n");
    }
}

//Remove elemento do inicio da fila.
void removerDaFila(int *fila, int *inicio, int *fim){
    if (!filaVazia(inicio)){  //Só será possível remover um elemento da fila, se ela não estiver vazia.
        for(int i = 0; i<=*fim; i++){
            fila[i] = fila[i+1];  //Reposicionando os elementos da fila.
        }

        fila[*fim] = -1;  //Esvaziando o fim da fila.
        *fim -= 1;        //Atualizando o fim da fila.

        if(*fim == -1){  //Caso o elemento removido da fila seja o último, é necessário atualizar o inicio da fila para indicar que está vazia.
            *inicio = -1;
        }
    }else{  //Caso a fila esteja vazia, aparecerá mensagem de erro de remoção.
        printf("\nErro de remocao: a fila esta vazia !\n");
    }
}

//Recebe um elemento e retorna sua posição na fila, caso o elemento não exista, será retornado -1
int buscarElemento(int *fila, int elemento){
    for(int i=0; i<TAM_FILA; i++){
        if (fila[i] == elemento){ 
            return i;
        }
    }
    return -1;
}

int main(){
    int fila[TAM_FILA];  
    int inicio = -1;
    int fim = -1;
    int opcao, elemento;
    
    for (int i=0; i<TAM_FILA; i++){
        fila[i] = -1; //Esvaziando a fila --> preenchendo com -1
    }

    printf("\n----------Bem vindo ao programa FILA !----------\n");
    
    do
    {   
        printf("\n");
        printf("Escolha uma das opcoes abaixo: \n");
        printf("1 - Inserir elemento na fila \n");
        printf("2 - Remover elemento da fila \n");
        printf("3 - Ver se a fila esta cheia \n");
        printf("4 - Ver se a fila esta vazia \n");
        printf("5 - Buscar algum elemento na fila \n");
        printf("6 - exibir fila \n");
        printf("7 - Sair \n");
        scanf("%d", &opcao);

        switch (opcao){
            case 1:
                printf("Digite o elemento que deseja inserir: ");
                scanf("%d", &elemento);
                inserirElemento(fila,elemento,&inicio, &fim);
                break;
            case 2:
                removerDaFila(fila,&inicio,&fim);
                break;
            case 3:
                if(filaCheia(&fim)){
                    printf("\nFila cheia !\n");
                }else{
                    printf("\nA fila nao esta cheia.\n");
                }
                break;
            case 4:
                if(filaVazia(&inicio)){
                    printf("Fila Vazia !");
                }else{
                    printf("\nA fila nao esta vazia.\n");
                }
                break;
            case 5:
                printf("Digite o elemento que deseja buscar: ");
                scanf("%d", &elemento);
                int elementoEncontrado = buscarElemento(fila,elemento);
                if (elementoEncontrado != -1){ 
                    printf("\nElemento encontrado na posicao: %d\n",elementoEncontrado);
                }else{
                    printf("\nElemento nao encontrado.\n");
                }
                break;
            case 6:
                exibirFila(fila,&inicio,&fim);
                break;
        }
    } while (opcao != 7);

    return 0;
}