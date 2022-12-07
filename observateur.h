typedef enum {
    I, M, E
} etat;

typedef enum{
    N, G, D, DemiTour
} etatsNouvelAutomate;
typedef struct {
    etat etat;
} automate;

typedef struct {
    etatsNouvelAutomate etat;
} Nouvelautomate;

etat transitionAutomate(etat etat, char c);

etatsNouvelAutomate transitionNouvelAutomate(etatsNouvelAutomate etat, char c);