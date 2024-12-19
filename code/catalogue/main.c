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

int main(int argc, char const *argv[])
{
    short int mod = 0;
    short int choice;
    char name[N];
    char city[N];
    int  sold;
    float revenu;
    int counter = 0;

    static node *n;    // tampon pointerımız
    static node *top;  // stackin basının adresini tutan pointer
    static node *head; // queue nun basının adresini tutan pointer

    //kataloga stackde hazır eleman ekleme islemimizi yapıyoruz 
    
    top = push(top,"mavi","istanbul",100,55200.99);
    top = push(top,"oxxo","mersin",50,25000);
    top = push(top,"defacto","istanbul",200,80043);

    //kataloga queueda hazır eleman ekleme islemimizi yapıyoruz 
    head = enqueue(head,"DnR","istanbul",100,55200.99);
    head = enqueue(head,"boyner","mersin",50,25000);
    head = enqueue(head,"altınyıldız","erdemli",56,45654);
    //stackte yazdırıyoruz katalogumuzu
    printf("\nStack kullanarak yaptigimiz katalog\n");
    display_list(top);
    printf("\nQueue kullanarak yaptigimiz katalog\n");
    display_list(head);
while (mod == 0)
{
    printf("\nWhich way you want to save?\n\t1.Stack\n\t2.Queue\n\t3.Exit\nYour choice : ");
    scanf("%hd",&mod);


    while (mod != 0){
        if (mod == 1) // registration in Stack
        {
        printf("\nwhat do you want to do?\n");
        printf("\t1. Add a new store\n");
        printf("\t2. Delete a store\n");
        printf("\t3. Find a store\n");
        printf("\t4. Show stores\n");
        printf("\t5. Delete the entier store\n");
        printf("\t6.Return back\n");
        printf("Your choice : ");
        scanf("%hd",&choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter store name\t");
            scanf("%s",name);
            printf("\nEnter the city where the store is located\t");
            scanf("%s",city);
            printf("\nEnter the number of products sold\t");
            scanf("%d",&sold);
            printf("\nEnter the amount of income per day\t");
            scanf("%f",&revenu);
            
            top = push(top,name,city,sold,revenu);
            break;
        case 2:
            top = pop(top); // we delete a magasin
            break;
        case 3:
            printf("\nEnter the store name you want to search for\t");
            scanf("%s",name);
            while (top != NULL)
            {
                if (strcmp(name,top->name) == 0)
                {
                    printf("\nThis store exists in your catalog!\nInformation about this store:\n");
                    printf("\tmarka : %s\n\tsehir : %s\n\tsatılan mal : %d\n\tkazanc : %f\n\n\n",top->name,top->city,top->sold,top->revenu);
                    counter++;
                }
                
                top = top->next;
            }
            if (counter == 0)
            {
                printf("\nUnfortunately, there is no such store catalogue.!!!!\n");
            }
            break;
        case 4:
            display_list(top); // we display the entier list    oncekileri göstermiyor
            break;
        case 5:
            while (top != 0)
            {
                top = pop(top);
            }
            printf("\nYour catalog has been successfully deleted...\n");
            break;
        case 6:
            mod = 0;
            break;
        default:
            break;
        }

    }
    else if (mod == 2) // registration in Queue
    {
        printf("\nwhat do you want to do?\n");
        printf("\t1. Add a new store\n");
        printf("\t2. Delete a store\n");
        printf("\t3. Find a store\n");
        printf("\t4. Show stores\n");
        printf("\t5. Delete the entier store\n");
        printf("\t6.Return back\n");
        printf("Your choice : ");
        scanf("%hd",&choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter store name\t");
            scanf("%s",name);
            printf("\nEnter the city where the store is located\t");
            scanf("%s",city);
            printf("\nEnter the number of products sold\t");
            scanf("%d",&sold);
            printf("\nEnter the amount of income per day\t");
            scanf("%f",&revenu);
            head = enqueue(head,name,city,sold,revenu);
            break;
        case 2:
            head = pop(head); // we delete a magasin
            break;
        case 3:
            printf("\nEnter the store name you want to search for\t");
            scanf("%s",name);
            while (head != NULL)
            {
                if (strcmp(name,head->name) == 0)
                {
                    printf("\nThis store exists in your catalog!\nInformation about this store:\n");
                    printf("\tmarka : %s\n\tsehir : %s\n\tsatılan mal : %d\n\tkazanc : %f\n\n\n",head->name,head->city,head->sold,head->revenu);
                    counter++;
                }
                
                head = head->next;
            }
            if (counter == 0)
            {
                printf("\nUnfortunately, there is no such store catalogue.!!!!\n");
            }
            break;
        case 4:
            display_list(head); // we display the entier list    oncekileri göstermiyor
            break;
        case 5:
            while (head != 0)
            {
                head = pop(head);
            }
            printf("\nYour catalog has been successfully deleted...\n");
            break;
        case 6:
            mod = 0;
            break;
        default:
            break;
        }
    }
    else
    {
        printf("\nThank you for using this program, see you next time :))");
        exit(1);
    }
    }
}  
    return 0;
}

