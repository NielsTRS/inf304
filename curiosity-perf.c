#include "environnement.h"
#include "interprete.h"
#include "programme.h"
#include "generation_terrains.h"

#include <stdio.h>
#include <stdlib.h>

void gestion_erreur_terrain(erreur_terrain e)
{
    switch (e)
    {
    case OK:
        break;
    case ERREUR_FICHIER:
        printf("Erreur lecture du terrain : erreur d'ouverture du fichier\n");
        exit(1);
    case ERREUR_LECTURE_LARGEUR:
        printf("Erreur lecture du terrain : erreur de lecture de la largeur\n");
        exit(1);
    case ERREUR_LECTURE_HAUTEUR:
        printf("Erreur lecture du terrain : erreur de lecture de la hauteur\n");
        exit(1);
    case ERREUR_LARGEUR_INCORRECTE:
        printf("Erreur lecture du terrain : largeur incorrecte\n");
        exit(1);
    case ERREUR_HAUTEUR_INCORRECTE:
        printf("Erreur lecture du terrain : hauteur incorrecte\n");
        exit(1);
    case ERREUR_CARACTERE_INCORRECT:
        printf("Erreur lecture du terrain : caractère incorrect\n");
        exit(1);
    case ERREUR_LIGNE_TROP_LONGUE:
        printf("Erreur lecture du terrain : ligne trop longue\n");
        exit(1);
    case ERREUR_LIGNE_TROP_COURTE:
        printf("Erreur lecture du terrain : ligne trop courte\n");
        exit(1);
    case ERREUR_LIGNES_MANQUANTES:
        printf("Erreur lecture du terrain : lignes manquantes\n");
        exit(1);
    case ERREUR_POSITION_ROBOT_MANQUANTE:
        printf(
            "Erreur lecture du terrain : position initiale du robot manquante\n");
        exit(1);
    }
}

void affichage_position_programme(erreur_programme e)
{
    int i;
    printf("Ligne %d, colonne %d :\n", e.num_ligne, e.num_colonne);
    printf("%s\n", e.ligne);
    /* Impression de e.num_colonne-1 espaces */
    for (i = 1; i < e.num_colonne; i++)
    {
        printf(" ");
    }
    /* Impression d'un curseur de position */
    printf("^\n");
}

void gestion_erreur_programme(erreur_programme e)
{
    switch (e.type_err)
    {
    case OK_PROGRAMME:
        break;
    case ERREUR_FICHIER_PROGRAMME:
        printf("Erreur lecture du programme : erreur d'ouverture du fichier\n");
        exit(2);
    case ERREUR_BLOC_NON_FERME:
        printf("Erreur lecture du programme : bloc non fermé\n");
        exit(2);
    case ERREUR_FERMETURE_BLOC_EXCEDENTAIRE:
        printf("Erreur lecture du programme : fermeture de bloc excédentaire\n");
        affichage_position_programme(e);
        exit(2);
    case ERREUR_COMMANDE_INCORRECTE:
        printf("Erreur lecture du programme : commande incorrecte\n");
        affichage_position_programme(e);
        exit(2);
    }
}

int main(int argc, char **argv)
{
    Environnement envt;
    Programme prog;
    erreur_terrain errt;
    erreur_programme errp;
    etat_inter etat;
    resultat_inter res;

    if (argc < 9)
    {
        printf("Usage: %s <fichier_programme> <N> <L> <H> <d> <graine> <nb_step_max> <fichier_res> \n", argv[0]);
        return 1;
    }

    /* Initialisation de l'environnement : lecture du terrain,
       initialisation de la position du robot */
    errp = lire_programme(&prog, argv[1]);
    gestion_erreur_programme(errp);
    int N = strtol(argv[2], NULL, 10);
    int L = strtol(argv[3], NULL, 10);
    int H = strtol(argv[4], NULL, 10);
    float dObst = strtof(argv[5], NULL);
    int graine = strtol(argv[6], NULL, 10);
    int nb_step_max = strtol(argv[7], NULL, 10);
    char *fichier_res = argv[8];
    FILE *fRES = fopen(fichier_res, "w");
    fprintf(fRES, "%d\n", N);
    Robot robot;
    envt.r = robot;
    srand(graine);
    int nbRobotSorti = 0;
    int nbRobotBloque = 0;
    int nbRobotObstacle = 0;
    int nbPas = 0;
    /* Initialisation de l'état */
    for (int i = 0; i < N; i++)
    {
        Terrain *t = malloc(sizeof(Terrain));

        generation_aleatoire_modifiee(t, L, H, dObst);
         envt.t = *t;
        envt.r.x = L / 2;
        envt.r.y = H / 2;
        envt.r.o = Est;
        init_etat(&etat);
        int j = 0;
        do
        {
            res = exec_pas(&prog, &envt, &etat);
            /* Affichage du terrain et du robot  */
            
            j = j + 1;
        } while (res == OK_ROBOT && j < nb_step_max);

        /* Ecriture du résultat  */
        switch (res)
        {
        case OK_ROBOT:
            fprintf(fRES, "-1\n");
            nbRobotBloque++;
            break;
        case SORTIE_ROBOT:
            fprintf(fRES, "%d\n", j);
            nbRobotSorti++;
            nbPas = nbPas + j;
            break;
        case ARRET_ROBOT:
            printf("Robot sur une case libre, programme terminé :-/\n");
            break;
        case PLOUF_ROBOT:
            fprintf(fRES, "-2\n");
            nbRobotObstacle++;
            break;
        case CRASH_ROBOT:
            fprintf(fRES, "-3\n");
            nbRobotObstacle++;
            break;
        case ERREUR_PILE_VIDE:
            printf("ERREUR : pile vide\n");
            break;
        case ERREUR_ADRESSAGE:
            printf("ERREUR : erreur d'adressage\n");
            break;
        case ERREUR_DIVISION_PAR_ZERO:
            printf("ERREUR : division par 0\n");
            break;
        } 
                free(t);
    }
    printf("Nombre de fois ou le robot est sorti : %d/%d (%f %% des terrains)\n ", nbRobotSorti, N, (float)nbRobotSorti / N * 100);
     printf("Nombre de fois ou le robot est resté coincé : %d/%d (%f %% des terrains)\n ", nbRobotBloque, N, (float)nbRobotBloque / N * 100);
     printf("Nombre de fois ou le robot est tombé dans un obstacle : %d/%d (%f %% des terrains)\n ", nbRobotObstacle, N, (float)nbRobotObstacle / N * 100);
     printf("Nombre de pas moyen pour sortir : %f\n ", (float)nbPas / nbRobotSorti);
}


