#include "teamvec.h"
#include <stdlib.h>

// TODO: defina aqui os campos de "struct teamvec" -- pense no que o TAD
// precisa guardar para saber quantos times tem e quanto espaço ainda sobra
struct teamvec {
    int n; // numero de elementos
    int n_max; // numero de capacidade
    Team ** times; // vetor com os times
};

TeamVec *tv_create(void) {
    TeamVec *tv = (TeamVec *)malloc(sizeof(TeamVec));
    if (tv == NULL)
      return NULL;
    tv->n = 0;
    tv->n_max = 3; 
    tv->times = (Team **)malloc(tv->n_max*sizeof(Team*));
    if (tv->times == NULL){
        free(tv);
        return NULL;
    }return tv;
}

void tv_insert(TeamVec *tv, Team *t) {
    if(tv_size(tv) == tv->n_max){
        tv->n_max *=2;
        Team **aux = (Team **)realloc(tv->times,tv->n_max*sizeof(Team*));
        if (aux == NULL) {
            return;
        }
    }
    tv->times[tv->n++] = t;

}

int tv_size(TeamVec *tv) {
    if (tv == NULL) {
        return -1;
    }
    return tv->n;
}

Team *tv_get(TeamVec *tv, int i) {
    if (tv == NULL|| i < 0 || i >= tv->n) { //evita acessar uma posição inexistente
        return NULL;
    }
    return tv->times[i];
}

void tv_free(TeamVec *tv) {
    if (tv == NULL) {
        return;
    }
    for (int i = 0; i < tv->n; i++) {
        team_free(tv->times[i]);
    }
    free(tv->times);
    free(tv);
}