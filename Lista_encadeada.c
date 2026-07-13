#include <stdio.h>
#include <stdlib.h> // Para usar malloc

typedef struct no {
    int dado;               // Estrutura de um nó
    struct no *prox;
} no;

no *lista = NULL; // A Head da lista, ou seja a própria lista

int menu(){
    printf("========= Menu =========\n");
    printf("1 - Inserir no início\n");
    printf("2 - Inserir em posição\n");
    printf("3 - Inserir no final\n");
    printf("4 - Exibir lista\n");
    printf("5 - Consultar posição\n");
    printf("6 - Remover elemento\n");
    printf("7 - Liberar lista\n");
    printf("=== Funções recursivas ===\n");
    printf("8 - Inserir em posição recursivo\n");
    printf("9 - Inserir em posição ordenada recursivo\n");
    printf("10 - Somar lista recursiva\n");
    printf("11 - Exibir recursivo\n");
    printf("========================\n");
    printf("Digite o número da operação que deseja realizar: ");
    int menu = 0;
    scanf("%d", &menu);
    return menu;
}

void inserir_inicio(int valor){
    no *novo = (no *) malloc(sizeof(no)); // Nó criado dinamicante na memória
    novo->dado = valor;
    novo->prox = lista;  // Novo elemento aponta para a cabeça que agora é o segundo elemento
    lista = novo; // E a cabeça é atualizada para apontar para o novo primeiro elemento
    return;
}

void inserir_posicao(int valor, int posição){

    if(posição == 1){
        inserir_inicio(valor);  // Se a posição for 1 ele reaproveita a função inserir no início
        return;
    }
    
    // Caso a posição não seja 1:
    no *novo = (no*) malloc(sizeof(no));
    novo->dado = valor;
    no *atual = lista; // Ponteiro criado para navegar na lista e não perder a Head
    for(int contador=1; atual != NULL; contador++){
        if(contador == posição - 1){ // Percorre até achar o nó anterior a posição que vamos inserir o novo
            novo->prox = atual->prox;    
            atual->prox = novo;
            return;
        }
        atual = atual->prox;
    }
    printf("Posição inválida!\n"); // Se não entrou no if anterior isso quer dizer que a posição não existe
    free(novo);
}

void inserir_posicao_recursivo(no *atual, int valor, int posicao){
    
    if (atual == NULL){
        printf("A posição é inválida!\n");
        return;
    }
    
    else if (posicao == 1){
        no *novo = (no*) malloc(sizeof(no));
        novo->dado = valor;
        novo->prox = atual->prox;
        atual->prox = novo;
        printf("Ponto inserido com sucesso!\n");
        return;
    }

    else{
        inserir_posicao_recursivo(atual->prox, valor, posicao-1);
        return;
    }
}

void inserir_posicao_ordenada_recursivo(no *atual, no *novo){
    
    if(lista == NULL){
        inserir_inicio(novo->dado);
        return;
    }

    if(atual->prox == NULL){
        atual->prox = novo;
        novo->prox = NULL;
        return;
    }

    if(novo->dado < atual->prox->dado){
        novo->prox = atual->prox;
        atual->prox = novo;
        return;
    }
    
    else{
        inserir_posicao_ordenada_recursivo(atual->prox, novo);
        return;
    }
}

void inserir_final(int valor){
    
    no *novo = (no *) malloc(sizeof(no)); // Nó criado dinamicante na memória
    novo->dado = valor;
    novo->prox = NULL;
    
    // If para caso seja o primeiro ponto
    if(lista == NULL){
        lista = novo;
        return;
    }

    //Se não entrou no if quer dizer que tem mais pontos
    no *anterior = lista;
    while(anterior->prox != NULL){
        anterior = anterior->prox;
    }

    anterior->prox = novo; 
}

void imprime(){
    printf("Lista encadeada: ");
    for(no *p = lista; p != NULL; p = p->prox){
        printf("%d ", p->dado);
    }
    printf("\n");
}

void consultar_pos(int posição){
    if(lista == NULL){
        printf("A lista está vazia!");
        return;
    }

    no *atual = lista;
    for(int contador = 1; atual != NULL; contador++){
        if(contador == posição){
            printf("Dados dessa posição:\n");
            printf("Dado: %d\n", atual->dado);
            printf("Próximo nó: %p\n", atual->prox);
            return;
        }
        atual = atual->prox;
    }

    printf("A posição não foi encontrada.\n");
    return;
}

void remover_elemento(int valor){
    
    if (lista == NULL){
        printf("A lista está vazia!\n");
        return;
    }
    
    no *anterior = NULL;
    for(no *atual = lista; atual != NULL; atual = atual->prox){
        if(atual->dado == valor){

            if (anterior == NULL){
                lista = atual->prox;
            }

            else{
                anterior->prox = atual->prox;
            }

            free(atual);
            return;
        }
        anterior = atual;
    }
    printf("O elemento não foi encontrado!\n");
}

void liberar_lista(){
    
    if(lista == NULL){
        printf("A lista está vazia!\n");
    }

    for(no *aux = lista; lista != NULL; aux = lista){
        lista = lista->prox;
        free(aux);
    }

    return;
}

void somar_recursivo(no *atual, int soma){
    
    if(lista == NULL){
        printf("A lista está vazia!\n");
        return;
    }

    if(atual == NULL){
        printf("Soma total: %d\n", soma);
        return;
    }
    
    else{
        soma += atual->dado;
        somar_recursivo(atual->prox, soma);
        return;
    }
}

void imprime_recursivo(no *atual){
    if (atual == NULL) {
        printf("\n");
        return;
    }
    printf("%d ", atual->dado);
    imprime_recursivo(atual->prox);
    return;
}

int main(){
    inserir_inicio(3);
    inserir_final(7);
    inserir_final(53);
    inserir_final(9);
    inserir_final(15);
    while(1){
        int valor = 0;
        int posição = 0;
        int opção = menu();
        switch (opção){
            case 1:
                printf("Digite o valor que deseja inserir no início da lista: ");
                scanf("%d", &valor);
                inserir_inicio(valor);
                break;
            case 2:
                printf("Digite a posição que deseja inserir o valor: ");
                scanf("%d", &posição);
                printf("Digite o valor que deseja inserir: ");
                scanf("%d", &valor);
                inserir_posicao(valor, posição);
                break;
            case 3:
                printf("Digite o valor que deseja inserir no final da lista: ");
                scanf("%d", &valor);
                inserir_final(valor);
                break;
            case 4:
                imprime();
                break;
            case 5:
                printf("Digite a posição que deseja consultar: ");
                scanf("%d", &posição);
                consultar_pos(posição);
                break;
            case 6:
                printf("Digite o valor que deseja remover: ");
                scanf("%d", &valor);
                remover_elemento(valor);
                break;
            case 7:
                liberar_lista();
                break;
            case 8:
                printf("Digite a posição que deseja inserir o valor: ");
                scanf("%d", &posição);
                printf("Digite o valor que deseja inserir: ");
                scanf("%d", &valor);
                inserir_posicao_recursivo(lista, valor, posição-1);
                break;
            case 9:
                printf("Digite o valor que deseja inserir: ");
                scanf("%d", &valor);
                no *novo = (no*) malloc(sizeof(no));
                novo->dado = valor;
                novo->prox = NULL;
                inserir_posicao_ordenada_recursivo(lista, novo);
                break;
            case 10:
                somar_recursivo(lista, 0);
                break;
            case 11:
                imprime_recursivo(lista);
                break;
            default:
                return 0;
        }
    }
}