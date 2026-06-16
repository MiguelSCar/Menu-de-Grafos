#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int num_vertices;

void limparGrafo(){
    for(int i=0; i<num_vertices; i++){  
        for(int j=0; j>num_vertices; j++){
            graph[i][j]=0;
        }
    }
    printf("\n Grafo limpo com sucesso\n");
}

void imprimirMatriz(){
    printf("\nMatriz de Adjacencia\n");
    printf("");
    for(int i=0; i<num_vertices; i++){
        printf("2d,i");
    }
    
    printf("\n");

    for(int i=0; i<num_vertices; i++){
        printf("%2d | ",i);
        for(int j=0; j<num_vertices; j++){
            printf("%2d", graph[i][j]);
        }
        printf("\n");
    }
}

void modificaAresta(){
    int origem,destino,valor;
    printf("\nVertice de Origem: \n");
    scanf("%d", &origem);
    
    
    printf("\nVertice de Destino: \n");
    scanf("%d", &destino);
    
    if(origem<0 || origem>=num_vertices || destino<0 || destino>=num_vertices){
        printf("Vertices inválidos\n");
        return;
    }
    
    printf("1 - Adicionar Aresta \n");
    printf("0 - Remover Aresta \n");
    printf("Opção: ");
    scanf("%d", &valor);
    
    graph[origem][destino]=valor;
    graph[destino][origem]=valor;
    
    printf("Aresta atualizada com sucesso\n");
}

void calcularGraus(){
    int grau;
    
    printf("\nGrau dos Vértices\n\n");
    
    for(int i=0; i<num_vertices; i++){
        grau=0;
        for(int j=0; j<num_vertices; j++){
            grau+=graph[i][j];
        }
        
        printf("Vertice %d -> Grau %d\n", i,grau);
        
    }
}

void listarAdjacencias(){
    printf("\nLista de Adjacencias\n");
    
    for(int i=0; i<num_vertices; i++){
        printf("%d -> ", i);
        int vazio=1;
        for(int j=0; j<num_vertices; j++) {
            if(graph[i][j]==1){
                printf("%d ", j);
                vazio=0;
            } 
        }
        
        if(vazio==1){
            printf("\nNenhum\n");
        } else{
            printf("\n");
        }
    }
}
    void main() {
        int opcao;
        printf("Quantidade de Vértices: ");
        scanf("%d", &num_vertices);
        
        if(num_vertices<=0 || num_vertices>MAX_VERTICES){
            printf("\nQuantidade Inválida\n");
            return;
        }
        
        do{
            printf("MENU DO GRAFO\n");
            printf("1 - Limpar grafo\n");
            printf("2 - Inserir/remover aresta\n");
            printf("3 - Mostrar Matriz \n");
            printf("4 - Mostrar Graus\n");
            printf("5 - Mostrar adjacencias\n");
            printf("6 - Sair\n");
            printf("Opção: ");
            scanf("%d", &opcao);
            
            switch(opcao){
                case 1:
                limparGrafo();
                break;
                
                case 2:
                modificaAresta();
                break;
                
                case 3:
                imprimirMatriz();
                break;
                
                case 4:
                calcularGraus();
                break;
                
                case 5:
                listarAdjacencias();
                break;
                
                case 6:
                printf("Encerrando...");
                break;
                
                default:
                printf("Opção Inválida\n");
            }
        }while(opcao!=6);
    }