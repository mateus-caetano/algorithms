#include "qxqueue.h"
#include <stdlib.h>

struct node
{
  int n ;
  struct node * next ;
} ;

typedef struct node node ;

struct __qxd_queue
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

QxQueue qx_queue_new()
{
  QxQueue new = (QxQueue) malloc(sizeof(QxQueue)) ;
  new -> head = NULL ;
  return new ;
}

void qx_queue_delete(QxQueue queue)
{
  if(qx_queue_empty(queue))
  {
    free(queue) ;
    return ;
  }

  delete(queue -> head) ;
  free(queue) ;
  return ;
}

size_t qx_queue_size(QxQueue queue)
{
  size_t count = 1 ;
  node * l = (node *) malloc(sizeof(node *)) ;

  if(qx_queue_empty(queue))
  {
    count = 0 ;
    return count ;
  }

  else
  {
    l = queue -> head ;

    while(l -> next != NULL)
    {
      count ++ ;
      l = l -> next ;
    }

    return count ;
  }
}

bool qx_queue_empty(QxQueue queue)
{
  if(queue -> head == NULL)
    return true ;

  else
    return false ;
}

bool qx_queue_contains(QxQueue queue, int element)
{
  node *l = (node *) malloc(sizeof(node *)) ;
  l = queue -> head ;
  if(qx_queue_empty(queue))
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

size_t qx_queue_find(QxQueue queue, int element)
{
  node *l = (node*) malloc(sizeof(node*)) ;
  qxIndex i = 0 ;
  l = queue -> head ;
  if((qxIndex)qx_queue_size(queue)-1 < fromIndex)
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

int qx_queue_font(QxQueue queue)
{
  if(qx_queue_empty(queue))
    return QX_LAMBDA_ELEMENT ;

  else
    return queue -> head -> n ;
}

int qx_queue_back(QxQueue queue)
{
  node * l = (node *) malloc(sizeof(node *)) ;
  l = queue -> head ;
  if(qx_queue_empty(queue))
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

void qx_queue_enqueue(QxQueue queue, int elem)
{
  node *l = (node *) malloc(sizeof(node *)), *new = (node *) malloc(sizeof(node *)) ;
  l = queue -> head, new -> n = element ;

  while (l -> next != NULL)
  {
    l = l -> next ;
  }
  l -> next = new ;
  new -> next = NULL ;
  return ;
}

void qx_queue_dequeue(QxQueue queue)
{
  if(qx_queue_empty(queue))
    return ;

  else
  {
    if (queue -> head -> next == NULL)
    {
      free(queue -> head) ;
      queue -> head = NULL ;
      return ;
    }
    else
    {
      node *l = (node *) malloc(sizeof(node *)) ;
      l = queue -> head -> next ;
      free (queue -> head) ;
      queue -> head =  l ;
      return
    }
  }
}

void qx_queue_clear(QxQueue queue)
{
  delete(queue -> head) ;
  return ;
}

void qx_queue_print_to(QxQueue queue, FILE *fp)
{
  node *l = (node*) malloc(sizeof(node*)) ;
  l = queue -> head ;

  while(l != NULL)
  {
    printf("%d\n", l -> n) ;
    l = l -> next ;
  }
}
