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
    
    
    
    free(nodes);

    return 0;
}
