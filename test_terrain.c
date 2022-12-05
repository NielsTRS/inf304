#include "terrain.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    FILE *f;
    Terrain t;
    int x, y;
    erreur_terrain e;
    if (argc < 2)
    {
        printf("Usage : %s <fichier>\n", argv[0]);
        return 1;
    }
    char nomFichier[100];
    f = fopen(argv[1], "r");
    e = lire_terrain(f, &t, &x, &y);
    fclose(f);
    switch (e)
    {
    case OK:
        afficher_terrain(&t);
        printf("Position initiale du robot : (%d, %d)\n", x, y);
        break;
    case ERREUR_FICHIER:
        printf("Erreur d'ouverture du fichier\n");
        printf("Merci d'entrer un nouveau nom de fichier :");
        scanf("%s", nomFichier);
        f = fopen(nomFichier, "r");
        e = lire_terrain(f, &t, &x, &y);
        fclose(f);
        switch (e)
        {
        case OK:
            afficher_terrain(&t);
            printf("Position initiale du robot : (%d, %d)\n", x, y);
            break;
        case ERREUR_FICHIER:
            printf("Erreur d'ouverture du fichier\n");
            break;
        case ERREUR_LARGEUR:
            printf("Erreur de largeur\n");
            break;
        case ERREUR_HAUTEUR:
            printf("Erreur de hauteur\n");
            break;
        case ERREUR_LECTURE_LARGEUR:
            printf("Erreur lecture du terrain : erreur de lecture de la largeur\n");
            break;
        case ERREUR_LECTURE_HAUTEUR:
            printf("Erreur lecture du terrain : erreur de lecture de la hauteur\n");
            break;
        case ERREUR_LARGEUR_INCORRECTE:
            printf("Erreur lecture du terrain : largeur incorrecte\n");
            break;
        case ERREUR_HAUTEUR_INCORRECTE:
            printf("Erreur lecture du terrain : hauteur incorrecte\n");
            break;
        case ERREUR_CARACTERE_INCORRECT:
            printf("Erreur lecture du terrain : caractère incorrect\n");
            break;
        case ERREUR_LIGNE_TROP_LONGUE:
            printf("Erreur lecture du terrain : ligne trop longue\n");
            break;
        case ERREUR_LIGNE_TROP_COURTE:
            printf("Erreur lecture du terrain : ligne trop courte\n");
            break;
        case ERREUR_LIGNES_MANQUANTES:
            printf("Erreur lecture du terrain : lignes manquantes\n");
            break;
        case ERREUR_POSITION_ROBOT_MANQUANTE:
            printf(
                "Erreur lecture du terrain : position initiale du robot manquante\n");
            break;
        }
        break;
    case ERREUR_LARGEUR:
        printf("Erreur le terrain est moins large que la largeur définie sur la première ligne\n");
        break;
    case ERREUR_HAUTEUR:
        printf("Erreur le terrain est moins haut que la hauteur définie sur la 2eme ligne\n");
        break;
    case ERREUR_LECTURE_LARGEUR:
        printf("Erreur lecture du terrain : erreur de lecture de la largeur\n");
        break;
    case ERREUR_LECTURE_HAUTEUR:
        printf("Erreur lecture du terrain : erreur de lecture de la hauteur\n");
        break;
    case ERREUR_LARGEUR_INCORRECTE:
        printf("Erreur lecture du terrain : largeur incorrecte\n");
        break;
    case ERREUR_HAUTEUR_INCORRECTE:
        printf("Erreur lecture du terrain : hauteur incorrecte\n");
        break;
    case ERREUR_CARACTERE_INCORRECT:
        printf("Erreur lecture du terrain : caractère incorrect\n");
        break;
    case ERREUR_LIGNE_TROP_LONGUE:
        printf("Erreur lecture du terrain : ligne trop longue\n");
        break;
    case ERREUR_LIGNE_TROP_COURTE:
        printf("Erreur lecture du terrain : ligne trop courte\n");
        break;
    case ERREUR_LIGNES_MANQUANTES:
        printf("Erreur lecture du terrain : lignes manquantes\n");
        break;
    case ERREUR_POSITION_ROBOT_MANQUANTE:
        printf(
            "Erreur lecture du terrain : position initiale du robot manquante\n");
        break;
    }
}