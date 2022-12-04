//on construit l'automate vu en td
#include <stdlib.h>
#include <stdio.h>
#include "observateur.h"



etat transition(etat etat, char c){
    switch(etat){
        case I:
            switch(c){
                case 'M':
                    return M;
                case 'A':
                    return E;
                default:
                    return I;
            }
        case M:
            switch(c){
                case 'A':
                    return I;
                case 'G':
                    return I;
                case 'D':
                    return I;
                default:
                    return M;
            }
        case E:
            return E;
        default:
        printf("Erreur l'automate est sur un état inconnu");
            exit(1);
    }
}