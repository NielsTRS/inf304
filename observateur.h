typedef enum { I, M , E } etat;
typedef struct{
    etat etat;
} automate;

etat transition(etat etat, char c);