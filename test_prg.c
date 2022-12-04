#include "environnement.h"
#include "programme.h"
#include "interprete.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    if(argc < 2){
        printf("Erreur merci d'entrer un nom de fichier");
        return 1;
    }
    FILE *f = fopen(argv[1], "r");  
    char nomTerrain[100];
    fscanf(f, "%s", nomTerrain);
    char nomProgramme[100];
    fscanf(f, "%s", nomProgramme);
    int maxExec;
    fscanf(f, "%d\n", &maxExec);
    char evenementFin;
    fscanf(f, "%c\n", &evenementFin);
    int xFin;
    int yFin;
    char oFin;
    int i = 0; //compteur nombre opérations
    if(evenementFin == 'N' || evenementFin == 'F'){
        fscanf(f, "%d %d\n", &xFin, &yFin);
        fscanf(f, "%c", &oFin);
    }
    fclose(f);
    Environnement envt;
    Programme prog;
    erreur_terrain errt;
    erreur_programme errp;
    etat_inter etat;
    resultat_inter res;
    errt = initialise_environnement(&envt, nomTerrain);
    errp = lire_programme(&prog, nomProgramme);
    init_etat(&etat);
    do { 
        res = exec_pas(&prog, &envt, &etat);
        i++;
    } while (res == OK_ROBOT);
    int erreur = 0;
    if(i > maxExec){
        erreur = 1;
        printf("ERREUR : Nombre d'opérations dépassé\n");
    }
    if(i < maxExec){
        erreur = 1;
        printf("ERREUR : Nombre d'opérations insuffisant\n");
    }
    
    if(xFin != envt.r.x){
        erreur = 1;
        printf("! La position x de fin est incorrecte ! \n");
        printf("La position x attendue était : %d, la position x du robot est : %d \n", xFin, envt.r.x);
    }
    if(yFin != envt.r.y){
        erreur = 1;
        printf("! La position y de fin est incorrecte ! \n");
        printf("La position y attendue était : %d, la position y du robot est : %d \n", yFin, envt.r.y);
    }
    switch(envt.r.o){
        case Nord:
            if(oFin != 'N'){
                erreur = 1;
                printf("! L'orientation de fin est incorrecte ! \n");
                printf("L'orientation attendue était : %c, l'orientation du robot est : Nord \n", oFin);
            }
            break;
        case Est:
            if(oFin != 'E'){
                erreur = 1;
                printf("! L'orientation de fin est incorrecte ! \n");
                printf("L'orientation attendue était : %c, l'orientation du robot est : Est \n", oFin);
            }
            break;
        case Sud:
            if(oFin != 'S'){
                erreur = 1;
                printf("! L'orientation de fin est incorrecte ! \n");
                printf("L'orientation attendue était : %c, l'orientation du robot est : Sud \n", oFin);
            }
            break;
        case Ouest:
            if(oFin != 'O'){
                erreur = 1;
                printf("! L'orientation de fin est incorrecte ! \n");
                printf("L'orientation attendue était : %c, l'orientation du robot est : Ouest \n", oFin);
            }
            break;
    }
    if(erreur == 0){
        printf("OK\n");
    }
    return 0;
}