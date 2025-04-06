#include <stdio.h>
#include <stdlib.h>
/*modifier ce code au debut exemple 10->20->30 etc */
// D�finition de la structure pour un �l�ment de liste
typedef struct element {
    int valeur;
    struct element *suivant;
} element;

// Fonction pour cr�er un nouveau n�ud
element* creerNoeud(int valeur) {
    element *nouveau = malloc(sizeof(element));
    if (nouveau == NULL) {
        fprintf(stderr, "Erreur d'allocation m�moire\n");
        exit(EXIT_FAILURE);
    }

    nouveau->valeur = valeur;
    nouveau->suivant = NULL;

    return nouveau;
}

// Fonction pour ins�rer un n�ud au d�but de la liste
void insererNoeud(element **tete, int valeur) {
    element *nouveau = creerNoeud(valeur);
    nouveau->suivant = *tete; // Mise � jour du pointeur suivant
    *tete = nouveau; // Mise � jour de la t�te de la liste
}

// Fonction pour afficher la liste
void afficherliste(element *tete) {
    while (tete != NULL) {
        printf("%d -> ", tete->valeur);
        tete = tete->suivant;
    }
    printf("NULL\n"); // Ajout d'un saut de ligne apr�s "NULL"
}

int main() {
    // D�claration de la t�te de la liste
    element *liste = NULL;

    // Insertion de quelques �l�ments dans la liste
    insererNoeud(&liste, 10);
    insererNoeud(&liste, 20);
    insererNoeud(&liste, 30);

    // Affichage de la liste
    printf("Liste cha�n�e :\n");
    afficherliste(liste);

    // Lib�ration de la m�moire
    while (liste != NULL) {
        element *suivant = liste->suivant;
        free(liste);
        liste = suivant;
    }

    return 0;
}
