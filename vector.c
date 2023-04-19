#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

Vector *vector_construct()
{
    Vector *v;
    v = malloc(sizeof(Vector));
    v->size = 0;
    v->allocated = 10;
    v->data = malloc(sizeof(data_type) * v->allocated);

    return v;
}

void vector_destroy(Vector *v)
{
    free(v->data);
    free(v);
}

void vector_push_back(Vector *v, data_type val)
{

    if (v->size >= v->allocated)
    {
        v->allocated *= 2;
        v->data = realloc(v->data, v->allocated * sizeof(data_type));
    }
    v->data[v->size] = val;
    v->size++;
}

data_type vector_get(Vector *v, int i)
{
    return v->data[i];
}
void vector_set(Vector *v, int i, data_type val)
{
    v->data[i] = val;
}
int vector_size(Vector *v)
{
    return v->size;
}

int vector_find(Vector *v, data_type val)
{
    int i;
    for (i = 0; i < v->size; i++)
    {
        if (v->data[i] == val)
            return i;
    }
    return -1;
}

data_type vector_remove(Vector *v, int i)
{
    data_type item = v->data[i];
    v->size--;
    for (; i < v->size; i++)
    {
        v->data[i] = v->data[i + 1];
    }
    return item;
}

data_type vector_pop_front(Vector *v)
{
    return vector_remove(v, 0);
}

data_type vector_pop_back(Vector *v)
{
    return vector_remove(v, v->size - 1);
}

void vector_insert(Vector *v, int i, data_type val)
{
    int j;
    vector_push_back(v, val);
    for (j = v->size - 1; j >= i; j--)
    {
        v->data[j + 1] = v->data[j];
    }
    v->data[i] = val;
}

void vector_swap(Vector *v, int i, int j)
{
    data_type temp;
    temp = v->data[i];
    v->data[i] = v->data[j];
    v->data[j] = temp;
}

void vector_sort(Vector *v)
{
    int i, j;
    for (i = 0; i < v->size; i++)
    {
        for (j = i + 1; j < v->size; j++)
        {
            if (v->data[i] > v->data[j])
            {
                vector_swap(v, i, j);
            }
        }
    }
}

int vector_binary_search(Vector *v, data_type val)
{
    int init = 0, end = v->size - 1;
    int mid;
    while (init <= end)
    {
        mid = (end + init) / 2;
        if (v->data[mid] > val)
        {
            end = mid - 1;
        }
        else if (v->data[mid] < val)
        {
            init = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

void vector_reverse(Vector *v)
{
    int j, i;
    for (i = 0, j = v->size - 1; i < v->size / 2; i++, j--)
        vector_swap(v, i, j);
}