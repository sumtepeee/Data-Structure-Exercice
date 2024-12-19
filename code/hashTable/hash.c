#include<stdlib.h>
#include<string.h>
#include<stdio.h>

#include"hash.h"
#define MULTIPLIER 256 

/* La fonction de hachage dont le pseudocode est
 * donne sur l'enonce de TP */
unsigned long hash_compute(const char *str){
	unsigned long  sum = 0, mul = 1;
	int lent = strlen(str);

	for (int i = 0; i < lent; i++)
	{
		if (i%4 == 0)
		{
			mul = 1;
		}
		else
		{
			mul *= MULTIPLIER;
		}
		sum += str[i]*mul;
	}
	return (sum%MULTIPLIER); 
  
}

/* La table represente la structure de hach.
 * Si la chaine de caractere existe deja dans la liste
 * alors on retourne son adresse, sinon et si create == 1
 * alors on ajoute cette chaine à la table de hachage */
Key* hash_lookup(Key **table, const char *str, int create){
	// TODO
	
	// appel à la fonction hash_compute pour str
	
	// controlez si cette valeur de hachage existe deja
	// si elle existe alors retournez l'adresse de cette case
	
	// si elle n'existe pas et si on va l'ajouter:
	if(create){
		// allouez la place necessaire dans la memoire
		
		// si la place correspondante est allouee sans probleme
		// alors pour le nouvel element faites l'initalisation 
		// de word, count et next
		
		// retournez l'adresse de cet element
	
   }
  return NULL;
}

/* Une fonction pour effacer la table entiere.
 * Vous devez liberer (free) chaque noeud et chaque 
 * word qui se toruvent dans la liste chainee. */
void hash_free(Key **table){
  // TODO
  
}

/* Une fonction pour afficher les mots dont 
 * la frequence >= n. Pour l'affichage utiliser
 * le format "%30s-->%5ld\n" 
 * (ld pour unsigned long) */
void hash_dump(Key **table,int n){
  // TODO 
  
}
