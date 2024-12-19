/*
 * catalogue.c
 *
 *  Created on: 17 march  2024
 *      Author: Sumeyye
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "catalogue.h"

#define N 50

node *new_Node (char name[N], char city[N], int  sold, float revenu) {

    node *new = malloc (sizeof (node));

    strcpy(new->name,name);
    strcpy(new->city,city);
    new->sold = sold;
    new->revenu = revenu;
    new->next= NULL ;

    return new ;
}

node *push (node *top , char name[N], char city[N], int  sold, float revenu){
    node * n = malloc (sizeof(node));

    strcpy(n->name,name);
    strcpy(n->city,city);
    n->sold = sold;
    n->revenu = revenu;
    n-> next = top;
    top = n;
    
    return top ;
}

node *pop (node *top){
    node * temp = top;
    if( temp != NULL )
    { 
        temp = top;
        top = top -> next ;
        free ( temp );
    }
    else
    {
        printf ("Empty stack");
    }
    return top ; 
}

void display_list (node *top) {
    while (top != NULL)
    {
        printf("\nmarka : %s\nsehir : %s\nsatılan mal : %d\nkazanc : %f\n\n\n",top->name,top->city,top->sold,top->revenu);
        top = top->next;
    }
}

node *enqueue (node *head, char name[N], char city[N], int  sold, float revenu){
    node * temp = head ;
    node * new = new_Node (name, city, sold, revenu);
    if( temp == NULL ) head = new;
    else
    {
        while (temp -> next != NULL ) 
        {
            temp = temp -> next ;
        }
        temp -> next = new;
    }
    return head ; 
}
