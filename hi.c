#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    int x, y;
    struct node* next;
}Node;

int main(){
    Node* nodes;
    
    nodes = (Node*) malloc(sizeof(nodes) * 10);
    
    
    for(int i = 1; i < 10; i++){
        nodes[i].value = i;
        nodes[i].next = NULL;
        nodes[i].x = 11;
        nodes[i].y = 21;
    }
    
    for(int i = 0; i < 10; i++){
        printf("nodes value : %d\n", nodes[i].value);
    }
    
    free(nodes);
    
    return 0;
}
