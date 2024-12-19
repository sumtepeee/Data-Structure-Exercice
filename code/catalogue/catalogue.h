#ifndef CATALOGUE_H_
#define CATALOGUE_H_

#define N 50

/* Magazaların adını, magazanın bulundugu sehiri,
magazanın sattıgı urun sayısı ve magazanın gunluk
kazancını tutan bir struck olusturuyoruz.*/
typedef struct node
{
    char name[N];
    char city[N];
    int  sold;
    float revenu;
    struct node *next;

} node; 

/*parametre olarak aldıgı degerleri stack yapısındaki linkliste ekler*/
node *new_Node (char name[N], char city[N], int  sold, float revenu);

/*stack a yeni eleman ekleme fonksiyonumuz*/
node *push (node *top , char name[N], char city[N], int  sold, float revenu);

///////
/////// 2 .durum

/*stacktan ve quue dan eleman silme fonksiyonumuz*/
node *pop (node * top);

////fine a store

//listemizi yazdırıyoruz
void display_list (node *top);

/*Queu ya yeni eleman ekleme fonksiyonumuz*/
node *enqueue (node *head, char name[N], char city[N], int  sold, float revenu);


#endif /* CATALOGUE_H_ */