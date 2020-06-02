#include "qxdlist.h"
#include <stdlib.h>

struct node
{
  int n ;
  struct node * next ;
} ;

typedef struct node node ;

struct __qxd_list
{
  node * head ;
} ;

void delete(node *l)
{
  if(l != NULL)
  {
    delete(l -> next) ;
  }

  else
    free(l) ;

  return ;
}

qxIndex find_last(QxList list, int element, qxIndex upToIndex)
{
  int aux = 0 ;
  qxIndex i = 0, a = 0 ;
  node *l = (node*) malloc(sizeof(node *)) ;
  l = list -> head ;

  while (i != upToIndex)
  {
    l = l -> next ;
    ++i ;
  }

  if(l -> n == element)
    aux = 1 ;

  while (l != NULL)
  {
    if (l -> n == element)
      i = a ;
    l = l -> next ;
    ++a ;
  }

  if((qxIndex)i != upToIndex)
    return i ;

  else if((qxIndex)i == upToIndex && aux == 1)
    return i ;

  else
    return QX_LAMBDA_INDEX ;
}

QxList qx_list_new()
{
  QxList new = (QxList) malloc(sizeof(QxList)) ;
  new -> head = NULL ;
  return new ;
}

void qx_list_delete(QxList list)
{
  if(qx_list_empty(list))
  {
    free(list) ;
    return ;
  }

  delete(list -> head) ;
  free(list) ;
  return ;
}

size_t qx_list_size(QxList list)
{
  size_t count = 1 ;
  node * l = (node *) malloc(sizeof(node *)) ;

  if(qx_list_empty(list))
  {
    count = 0 ;
    return count ;
  }

  else
  {
    l = list -> head ;

    while(l -> next != NULL)
    {
      count ++ ;
      l = l -> next ;
    }

    return count ;
  }
}

bool qx_list_empty(QxList list)
{
  if(list -> head == NULL)
    return true ;

  else
    return false ;
}

bool qx_list_contains(QxList list, int element)
{
  node *l = (node *) malloc(sizeof(node *)) ;
  l = list -> head ;
  if(qx_list_empty(list))
  {
    return false ;
  }

  else
  {
    while(l != NULL)
    {
      if(l -> n == element)
      {
        return true ;
      }
      l = l -> next ;
    }

    return false ;
  }

}

qxIndex qx_list_find(QxList list, int element, qxIndex fromIndex)
{
  node *l = (node*) malloc(sizeof(node*)) ;
  qxIndex i = 0 ;
  l = list -> head ;
  if((qxIndex)qx_list_size(list)-1 < fromIndex)
    return QX_LAMBDA_INDEX ;

  else
  {
    while(i != fromIndex)
    {
      l = l -> next ;
      ++i ;
    }

    do {
      if (l -> n == element)
        return i ;

      ++ i ;
      l = l -> next ;
    } while(l != NULL) ;
    return QX_LAMBDA_INDEX ;
  }
}

qxIndex qx_list_find_last(QxList list, int element, qxIndex upToIndex)
{
  if((qxIndex)qx_list_size(list)-1 < upToIndex)
    return QX_LAMBDA_INDEX ;

  return find_last(list) ;
}

int qx_list_at(QxList list, qxIndex index)
{
  node * l = (node*) malloc(sizeof(node *)) ;
  qxIndex i = 0 ;
  l = list -> head ;

  if((qxIndex)qx_list_size(list)-1 < index)
    return QX_LAMBDA_ELEMENT ;

  else
  {
    while (i != index)
    {
      l = l -> next ;
      ++i ;
    }
    return l -> n ;
  }
}

int qx_list_font(QxList list)
{
  if(qx_list_empty(list))
    return QX_LAMBDA_ELEMENT ;

  else
    return list -> head -> n ;
}

int qx_list_back(QxList list)
{
  node * l = (node *) malloc(sizeof(node *)) ;
  l = list -> head ;
  if(qx_list_empty(list))
    return QX_LAMBDA_ELEMENT ;

  else
  {
    while (l -> next != NULL)
    {
      l = l -> next ;
    }
    return l -> n ;
  }
}

bool qx_list_insert_at(QxList list, int element, qxIndex index)
{
  node *l = (node *) malloc(sizeof(node *)), *new = (node *) malloc(sizeof(node *)) ;
  qxIndex i = 0 ;
  l = list -> head ;
  new -> n = element ;
  if((qxIndex)qx_list_size(list) < index || new == NULL)
    return false ;

  else if(index == 0)
  {
    qx_list_push_front(list, element) ;
  }

  else
  {
    while (i != index-1)
    {
      l = l -> next ;
      ++i ;
    }
    new -> next = l -> next ;
    l -> next = new ;
    return true ;
  }
}

void qx_list_push_front(QxList list, int element)
{
  node *new = (node*) malloc(sizeof(node*)) ;
  new -> n = element ;
  new -> next = list -> head ;
  list -> head = new ;

  return;
}

void qx_list_push_back(QxList list, int element)
{
  node *l = (node *) malloc(sizeof(node *)), *new = (node *) malloc(sizeof(node *)) ;
  l = list -> head, new -> n = element ;

  while (l -> next != NULL)
  {
    l = l -> next ;
  }
  l -> next = new ;
  new -> next = NULL ;
  return ;
}

qxIndex qx_list_remove_element_first(QxList list, int element)
{
  qxIndex i = 0 ;
  node * l = (node*) malloc(sizeof(node *), *n = (node*) malloc(sizeof(node *)) ;
  l = list -> head ;
  if(qx_list_empty(list))
    return QX_LAMBDA_INDEX ;

  else
  {
    if(l -> n == element)
    {
      qx_list_pop_front(list) ;
      return i ;
    }

    else
    {
      while (l -> next -> next -> n != element)
      {
        l = l -> next ;
        ++i ;
      }
      n -> next = l -> next -> next -> next ;
      free(l -> next -> next) ;
      l -> next = n -> next ;
      return i+2 ;
    }
  }
}

qxIndex qx_list_remove_element_last(QxList list, int element)
{
  int aux = 0 ;
  qxIndex i = 0, a = 0 ;
  node *l = (node *) malloc(sizeof(node *)) ;
  l = list -> head ;

  if(qx_list_empty(list))
    return QX_LAMBDA_INDEX ;

  else if(l -> n == element)
    aux = 1 ;

  else
  {
    while (l != NULL)
    {
      if(l -> n == element)
        i = a ;
      l = l -> next ;
      ++a ;
    }
    if(i != 0)
      return i ;
    else if (aux == 1 && i == 0)
      return i ;
    else
      return QX_LAMBDA_INDEX ;
  }
}

// unsigned int qx_list_remove_element_all(QxList list, int element)

// bool qx_list_remove_at(QxList list, qxIndex index)

void qx_list_pop_front(QxList list)
{
  if(qx_list_empty(list))
    return ;

  else
  {
    if (list -> head -> next == NULL)
    {
      free(list -> head) ;
      list -> head = NULL ;
      return ;
    }
    else
    {
      node *l = (node *) malloc(sizeof(node *)) ;
      l = list -> head -> next ;
      free (list -> head) ;
      list -> head =  l ;
      return
    }
  }
}

void qx_list_pop_back(QxList list)
{
  node * l = (node*) malloc(sizeof(node *)) ;
  l = list -> head ;
  if(qx_list_empty(list))
    return ;

  else
  {
    while(l -> next -> next != NULL)
    {
      l = l -> next ;
    }
    free(l -> next) ;
    l -> next = NULL ;
    return ;
  }
}

void qx_list_clear(QxList list)
{
  delete(list -> head) ;
  return ;
}

void qx_list_print_to(QxList list, FILE *fp)
{
  node *l = (node*) malloc(sizeof(node*)) ;
  l = list -> head ;

  while(l != NULL)
  {
    printf("%d\n", l -> n) ;
    l = l -> next ;
  }
}
