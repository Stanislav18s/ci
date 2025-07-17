#include <stdio.h>
#include <stdlib.h>
typedef struct c
{
    struct c * next;
    struct c * prev;
    int data;
    
}c;
typedef struct n
{
    c *head;
    c *taill;
}n;


c *add_end(c**head,int data){
    c *temp = malloc(sizeof(c));
    if (!temp){
        printf("error_memory");
        return NULL;
    }
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    if (*head == NULL){
        *head = temp;
        return *head;
    }
    else{
        c *cru = *head;
        while(cru->next!=NULL){
        cru = cru->next;
        }
        cru->next= temp;
        temp->prev= cru;
    }
    return *head;
}
void free_c( c *head){
    c *cru = head;
    while(cru!=NULL){
        c *next= cru->next;
        free(cru);
        cru = next;
    }
 }
 int del(c**head,c*elem){
    if (*head == elem && elem->next!=NULL){
    c *temp = (*head)->next;
    temp ->prev = NULL;
    free(*head);
    *head = temp;
    return 0;
    }
    c *cru = *head;
    while(cru != elem && cru!= NULL ){
        cru = cru->next;
        }
    if (cru == elem){
        if (cru->next == NULL){
            cru->prev->next = NULL;
            free(cru);
            return 0;
        }
        else {
            cru->prev->next =cru->next;
            cru->next->prev = cru->prev;
            free(cru);
            return 0;
        }
    }
    return 1;
 }
int main (){
    c *head = NULL;
    add_end(&head, 1);
    add_end(&head, 4);
    add_end(&head, 6);
    add_end(&head, 7);
    del(&head,head->next->next->next);
    c *cru = head;
    while( cru!= NULL){
        printf("%d\n",cru->data);
        cru = cru->next;
    }
    free_c(head);
    return 0;
}
