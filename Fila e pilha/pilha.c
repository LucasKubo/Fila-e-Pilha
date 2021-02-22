#include <stdio.h>
#define TAM_PILHA 5

//Para o programa , espaços vazios são representados pelo número -1

//Recebe o topo da pilha e retorna se ela está cheia ou não.
int pilhaCheia(int *topo){
    if (*topo == TAM_PILHA-1){  //Se o índice do topo da pilha for igual ao tamanho máximo -1, então ela está cheia.
        return 1;
    }
    return 0;
}

//Recebe o topo da pilha e retorna se ela está vazia ou não.
int pilhaVazia(int *topo){
    if (*topo == -1){
        return 1;
    }
    return 0;
}

//Insere elemento na pilha.
void inserirElemento (int *pilha, int *topo, int elemento, int *ret_code){
    if (!pilhaCheia(topo)){ //Só será possível inserir um elemento se a pilha não estiver cheia.
        *topo += 1;  //Atualiza o topo para o elemento que será inserido.
        pilha[*topo] = elemento;
        *ret_code = 1;  //Confirmação da execução correta da função.
    }
}

//Remove elemento da pilha
void removerDaPilha (int *pilha, int *topo, int *ret_code){
    if (!pilhaVazia(topo)){  //Só será possível remover um elemento se a pilha não estiver vazia.
        pilha[*topo] = -1;
        *topo -= 1;  //Atualiza o topo para o elemento anterior ao que foi removido.
        *ret_code = 1;  //Confirmação da execução correta da função.
    }
}

//Exibe qual é o topo da pilha
void exibirTopo (int *pilha, int *topo, int *ret_code){
    if(!pilhaVazia(topo)){ //Só será exibido o topo se a pilha não estiver vazia.
        printf("\nTopo da pilha: [%d] = %d\n", *topo, pilha[*topo]);
        *ret_code = 1; //Confirmação da execução correta da função.
    }
}

//Exibe os elementos da pilha e seus respectivos indices.
void exibirPilha (int *pilha, int *topo, int *ret_code){
    if (!pilhaVazia(topo)){  //Só será possível exibir se a pilha nao estiver vazia.
        for (int i=TAM_PILHA-1; i>=0; i--){
            if (pilha[i] != -1){  //Os elementos que serão exibidos não podem ser vazios.
                printf("[%d] = %d\n", i, pilha[i]);
            }
        }
        *ret_code = 1; //Confirmação da execução correta da função.
    }
}

int main (){
    int pilha[TAM_PILHA];
    int topo = -1; //Indica que a pilha está vazia.
    int elemento, opcao, ret_code;

    for (int i=0; i<TAM_PILHA; i++){
        pilha[i] = -1; //Esvaziando a pilha --> preenchendo com -1.
    }

    printf("\n----------Bem vindo ao programa PILHA !----------\n");

    do
    {   
        ret_code = 0;
        printf("\n");
        printf("Escolha uma das opcoes abaixo: \n");
        printf("1 - Inserir elemento na pilha \n");
        printf("2 - Remover elemento da pilha \n");
        printf("3 - Ver se a pilha esta cheia \n");
        printf("4 - Ver se a pilha esta vazia \n");
        printf("5 - exibir topo da pilha \n");
        printf("6 - exibir pilha \n");
        printf("7 - Sair \n");
        scanf("%d", &opcao);

        switch (opcao){
            case 1:
                printf("Digite o elemento que deseja inserir: ");
                scanf("%d", &elemento);
                inserirElemento(pilha, &topo, elemento, &ret_code);
                if(ret_code == 1){  //Verificando se a função foi bem sucedida
                    printf("\nElemento inserido com sucesso !\n");
                }else{
                    printf("\nErro de insersao: pilha cheia !\n");
                }
                break;
            case 2:
                removerDaPilha(pilha,&topo,&ret_code);
                if(ret_code == 1){//Verificando se a função foi bem sucedida
                    printf("\nElemento removido com sucesso !\n");
                }else{
                    printf("\nErro de exclusao: pilha vazia !\n");
                }
                break;
            case 3:
                if(pilhaCheia(&topo)){
                    printf("\nA pilha esta cheia !\n");
                }else{
                    printf("\nA pilha nao esta cheia\n");
                }
                break;
            case 4:
                if(pilhaVazia(&topo)){
                    printf("\nA pilha esta vazia !\n");
                }else{
                    printf("\nA pilha nao esta vazia \n");
                }
                break;
            case 5:
                exibirTopo(pilha,&topo, &ret_code);
                if (ret_code == 0){  //Verificando se a função foi bem sucedida.
                    printf("\nErro de impressao do topo: a pilha esta vazia !\n");
                }
                break;
            case 6:
                exibirPilha(pilha, &topo, &ret_code);
                if (ret_code == 0){  //Verificando se a função foi bem sucedida.
                    printf("\nErro de impressao: a pilha esta vazia !\n");
                }
                break;
        }
    } while (opcao != 7);

    return 0;
}