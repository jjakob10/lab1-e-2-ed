#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

Vector *vector_construct(){
    Vector *v;
    v = malloc(sizeof(Vector));
    v->size = 0;
    v->allocated = 10;
    v->data = malloc(sizeof(data_type)*v->allocated);

    return v;
}

void vector_destroy(Vector *v){
    free(v->data);
    free(v);
}

void vector_push_back(Vector *v, data_type val){
    
    if(v->size  >= v->allocated){
        v->allocated*=2;
        v->data = realloc(v->data, v->allocated*sizeof(data_type));
    }
    v->data[v->size] = val;
    v->size++;
}

data_type vector_get(Vector *v, int i){
    return v->data[i];
}
void vector_set(Vector *v, int i, data_type val){
    v->data[i] = val;
}
int vector_size(Vector *v){
    return v->size;
}

int vector_find(Vector *v, data_type val){
    int i;
    for(i=0;i<v->size;i++){
        if(v->data[i] == val)return i;
    }
    return -1;
}