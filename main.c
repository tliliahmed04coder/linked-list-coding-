#include <stdio.h>
#include <stdlib.h>
/*modifier ce code au debut exemple 10->20->30 etc */
// Définition de la structure pour un élément de liste
typedef struct element {
    int valeur;
    struct element *suivant;
} element;

// Fonction pour créer un nouveau nœud
element* creerNoeud(int valeur) {
    element *nouveau = malloc(sizeof(element));
    if (nouveau == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        exit(EXIT_FAILURE);
    }

    nouveau->valeur = valeur;
    nouveau->suivant = NULL;

    return nouveau;
}

// Fonction pour insérer un nœud au début de la liste
void insererNoeud(element **tete, int valeur) {
    element *nouveau = creerNoeud(valeur);
    nouveau->suivant = *tete; // Mise à jour du pointeur suivant
    *tete = nouveau; // Mise à jour de la tête de la liste
}

// Fonction pour afficher la liste
void afficherliste(element *tete) {
    while (tete != NULL) {
        printf("%d -> ", tete->valeur);
        tete = tete->suivant;
    }
    printf("NULL\n"); // Ajout d'un saut de ligne après "NULL"
}

int main() {
    // Déclaration de la tête de la liste
    element *liste = NULL;

    // Insertion de quelques éléments dans la liste
    insererNoeud(&liste, 10);
    insererNoeud(&liste, 20);
    insererNoeud(&liste, 30);

    // Affichage de la liste
    printf("Liste chaînée :\n");
    afficherliste(liste);

    // Libération de la mémoire
    while (liste != NULL) {
        element *suivant = liste->suivant;
        free(liste);
        liste = suivant;
    }

    return 0;
}
