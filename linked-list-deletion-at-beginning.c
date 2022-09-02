#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node{
    int data;
    struct node * next;
};

struct node * head = NULL;

void insb(int x)
{
    struct node *nn = (struct node *) malloc(sizeof(struct node));
    nn -> data = x;
    nn -> next = head;
    head = nn;
}

void insend(int x)
{
    if (!head){ insb(x); return;}
    struct node *t = head, *nn = (struct node *) malloc(sizeof(struct node));
    nn -> data = x;
    nn -> next = NULL;
    while (t -> next)   t = t-> next;
    t -> next = nn;
        
}

void delbeg(){
    if (head){
        struct node * t = head;
        head = head -> next;
        free(t);
    }
}


void display()
{
    struct node *t = head;
    while(t){
        printf("%d", t->data);
        
        if (t -> next != NULL){
            printf("->");
        }
        t = t->next;
    }
    
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n,i,d;
    scanf("%d", &n);
    while(n--){
        scanf("%d", &i);
        insend(i);
    }
    
    scanf("%d", &d);
    while(d--)
        delbeg();
    
    display();
    return 0;
}
