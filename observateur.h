typedef enum {
    I, M, E
} etat;
typedef struct {
    etat etat;
} automate;

etat transitionAutomate(etat etat, char c);