#include "qxdsearching.h"
#include <stdlib.h>

int menor(int array[], int j, size_t num_elems)
{
  int i = (j+1) ;
  menor = j ;
  for(i ; i < num_elems ; i++)
  {
    if(array[menor] > array[i])
  }
  return menor ;
}

void intrelaca(int p, int m, int q, int v[])
{
  static int vet[100] ;
  int i = p, j = m+1 ;
  for(int k = p ; k <= q ; k++)
  {
    if(j > q || ((i <= m) && (v[i] <= v[j])))
    {
      vet[k] = v[i] ;
      i++ ;
    }
    else//(i > m || ((j <= q) && (v[j] <= v[i])))
    {
      vet[k] = v[j] ;
      j++ ;
    }
  }
  for(int a = p ; a <= q ; a++)
  {
    v[a] = vet[a] ;
    //cout << v[a] << " " ;
  }
 // cout << endl ;
}

void merge(int v[], int p, int q)
{
  if(p >= q)
  {
    return ;
  }

  int m = ((q+p)/2) ;
  merge(v, p, m) ;
/*  for(int i = p ; i <= m ; i++)
  {
    cout << v[i] << " " ;
  }
  cout << endl ;
*/
  merge(v, m+1, q) ;
/*  for(int i = m+1 ; i <= q ; i++)
  {
    cout << v[i] << " " ;
  }
  cout << endl ;
*/
  intrelaca(p, m, q, v) ;

}

int particiona(int v[], int p, int q)
{
  int aux = 0, i = p-1 ;
  int j = p ;

  for(int k = j ; k < q ; k++)
  {
    if(v[k] <= v[q])
    {
      i++ ;
      p++ ;
      aux = v[k] ;
      v[k] = v[i] ;
      v[i] = aux ;
    }
  }

  aux = v[p] ;
  v[p] = v[q] ;
  v[q] = aux ;

  return p ;
}

void quick(int v[], int p, int q)
{
  if(p >= q)
  {
    return ;
  }
  int j = particiona(v, p, q) ;
  quick(v, p, j-1) ;
  quick(v, j+1, q) ;
  particiona(v, p, q) ;
  particiona(v, p, q) ;
}

void qx_insertion_sort(int array[], size_t num_elems)
{
  int i = 0, j = 0, aux = 0;
  for (i = 1 ; i < num_elems ; i++)
  {
    j = i - 1 ;
    aux = array[i] ;
    while(array[j] > aux && j >= 0)
    {
      v[j+1] = v[j] ;
      --j ;
    }
    v[j+1] = aux ;
  }
}

void qx_selection_sort(int array[], size_t num_elems)
{
  int i = 0, aux = 0, aux2 = 0 ;
  for(i ; i < num_elems - 1 ; i++)
  {
    aux = array[menor(array, i, num_elems)] ;
    aux2 = array [i] ;
    array [i] = array [aux] ;
    array [aux] = aux2 ;
  }
}

void qx_bubble_sort(int array[], size_t num_elems)
{
  size_t i = 0, j = 0 ;
  int aux ;
  for(i ; i < num_elems ; i++)
  {
    for(j = i+1 ; i < num_elems ; i++)
    {
      if(array[i] > array[j])
      {
        aux = array[i] ;
        array[i] = array[j] ;
        array[j] = aux ;
      }
    }
  }
}

void qx_merge_sort(int array[], size_t num_elems)
{
  merge(array, 0, num_elems-1) ;
}

void qx_quick_sort(int array[], size_t num_elems)
{
  quick(array, 0, num_elems-1) ;
}

void qx_counting_sort(int array[], size_t num_elems, int min_val, int max_val)
{
  int *aux = (int *) calloc(sizeof(int), max_val - min_val), i = 0, j = 0 ;
  while(i < num_elems)
  {
    aux [array[i] - min_val] += 1 ;
    i++ ;
  }
  i = 0 ;
  while(i <= (max_val - min_val))
  {
    while(aux[i] != 0)
    {
      array[j] = i + min_val ;
      ++j ;
    }
    ++i ;
  }
}
