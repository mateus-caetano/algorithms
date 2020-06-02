#include "qxdvector.h"
#include <stdlib.h>

struct __qxd_vector
{
  int qtd_elementos, tam ;
  int *vector ;
} ;

QxVector qx_vector_new(size_t initCapacity)
{
  QxVector new -> vector = (int*) malloc(sizeof(int) * 100) ;
  new -> qtd_elementos = 0 ;
  new -> tam = 100 ;
  return new ;
}

void qx_vector_delete(QxVector vector)
{
  free(vector) ;
  return ;
}

size_t qx_vector_size(QxVector vector)
{
  return vector -> tam ;
}

size_t qx_vector_capacity(QxVector vector)
{
  size_t n = vector -> tam - vector -> qtd_elementos ;
  return n ;
}

bool qx_vector_empty(QxVector vector)
{
  if(vector -> qtd_elementos == 0)
    return true ;

  else
    return false ;
}

bool qx_vector_full(QxVector vector)
{
  if(vector -> tam == vector -> qtd_elementos)
    return true ;
  else
    return false ;
}

bool qx_vector_contains(QxVector vector, int element)
{
  int i = 0 ;
  while (i < vector -> tam)
  {
    if (vector -> vector[i] == element)
      return true ;
  }
  return false ;
}

qxIndex qx_vector_find(QxVector vector, int element, qxIndex fromIndex)
{
  qxIndex i = 0 ;
  while(i < vector -> tam)
  {
    if(vector -> vector[i] == element)
    {
      return i ;
    }
  }

  return QX_LAMBDA_INDEX ;
}

qxIndex qx_vector_find_last(QxVector vector, int element, qxIndex upToIndex)
{
  qxIndex i = 0, j = 0 ;
  while(i < vector -> tam)
  {
    if(vector -> vector[i] == element)
    {
      j = i ;
    }
  }

  if(j == 0 && vector -> vector[j] == element)
    return j ;

  else if(j != 0)
  {
    return j ;
  }

  else
    return QX_LAMBDA_INDEX ;
}

int qx_vector_at(QxVector vector, qxIndex index)
{
  return vector -> vector[index] ;
}

int qx_vector_font(QxVector vector)
{
  return vector -> vector[0] ;
}

int qx_vector_back(QxVector vector)
{
  return vector -> vector[qtd_elementos-1] ;
}

// bool qx_vector_insert_at(QxVector vector, int element, qxIndex index)
// {
//
// }

// void qx_vector_push_front(QxVector vector, int element)
// {
//
// }

void qx_vector_push_back(QxVector vector, int element)
{
  vector -> vector[qtd_elementos] = element ;
  ++vector -> qtd_elementos ;
}

// qxIndex qx_vector_remove_element_first(QxVector vector, int element)
// {
//
// }

// qxIndex qx_vector_remove_element_last(QxVector vector, int element)
// {
//
// }

// size_t qx_vector_remove_element_all(QxVector vector, int element)
// {
//
// }

// bool qx_vector_remove_at(QxVector vector, qxIndex index)
// {
//
// }

// void qx_vector_pop_front(QxVector vector)
// {
//
// }

// void qx_vector_pop_back(QxVector vector)
// {
//
// }

// void qx_vector_clear(QxVector vector)
// {
//
// }

// void qx_vector_print_to(QxVector vector, FILE *fp)
// {
//
// }
