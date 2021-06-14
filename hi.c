#include <stdio.h>

typedef struct node{
    int value;
    struct node* next;
}Node;

int main(){
    Node n1;
    n1.value = 1;
    n1.next = NULL;
    

    return 0;
}
