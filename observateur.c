// on construit l'automate vu en td
#include <stdlib.h>
#include <stdio.h>
#include "observateur.h"

etat transitionAutomate(etat etat, char c)
{
    switch (etat)
    {
    case I:
        switch (c)
        {
        case 'M':
            return M;
        case 'A':
            return E;
        default:
            return I;
        }
    case M:
        switch (c)
        {
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

etatsNouvelAutomate transitionNouvelAutomate(etatsNouvelAutomate etat, char c)
{
    switch (etat)
    {
    case N:
        switch (c)
        {
        case 'G':
            return G;
        case 'D':
            return D;
        default:
            return N;
        }
    case G:
        switch (c)
        {
        case 'G':
            return DemiTour;
        default:
            return N;
        }
    case D:
        switch (c)
        {
        case 'D':
            return DemiTour;
        default:
            return N;
        }
    case DemiTour:
        return DemiTour;
    }
}