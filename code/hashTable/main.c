#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"
#define CREATE 1 
#define NCREATE 0

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("utilisation: %s <nom_du_fichier>\n", argv[0]);
        exit(1);
    }

    Key *w = NULL;
    char word[1024];

    /* La table de hachage dont chaque element est un noeud */
    Key *hash_table[MAXBUCKETS];

    /* Espace de memoire est mise a 0 */
    memset(hash_table, 0, sizeof(hash_table));

    /* Ouverture du fichier 
	 * (Vous pouvez utiliser emma.txt) */
    FILE *fp = fopen(argv[1], "r");

    if (fp == NULL) {
        printf("Pas pu trouver le fichier %s.\n", argv[1]);
        exit(1);
    }

    /* Lecture des mots dans une boucle infinie.
	 * On cherche le mot dans la table de hachage, 
	 * s'il n'existe pas alors on l'ajoute. S 'il 
	 * est deja dans la table alors on incremente 
	 * son nombre d'occurence. */
    while (1) {
        if (fscanf(fp, "%s", word) != 1)
            break;

        w = hash_lookup(hash_table, word, CREATE);
        w->count++;
    }

    /* Fermeture du fichier */
    fclose(fp);

    /* On affiche les mots dont leur frequence > 100 */
    hash_dump(hash_table, 100);

    /* On libere la table de hachage */
    hash_free(hash_table);
    return 0;
}
