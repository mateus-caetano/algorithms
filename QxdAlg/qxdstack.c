#include "qxdstack.h"
#include <stdlib.h>

struct node
{
  int n ;
  struct node * next ;
} ;

typedef struct node node ;

struct __qxd_stack
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

QxStack qx_stack_new(size_t initCapacity)
{
  QxQueue new = (QxQueue) malloc(sizeof(QxQueue)) ;
  new -> head = NULL ;
  return new ;
}

void qx_stack_delete(QxStack stack)
{
  if(qx_stack_empty(stack))
  {
    free(stack) ;
    return ;
  }

  delete(stack -> head) ;
  free(stack) ;
  return ;
}

size_t qx_stack_size(QxStack stack)
{
  size_t count = 1 ;
  node * l = (node *) malloc(sizeof(node *)) ;

  if(qx_stack_empty(stack))
  {
    count = 0 ;
    return count ;
  }

  else
  {
    l = stack -> head ;

    while(l -> next != NULL)
    {
      count ++ ;
      l = l -> next ;
    }

    return count ;
  }
}

size_t qx_stack_capacity(QxStack stack)
{
  return QX_INFINITY_SIZE ;
}

bool qx_stack_empty(QxStack stack)
{
  if(stack -> head == NULL)
    return true ;

  else
    return false ;
}

bool qx_stack_full(QxStack stack)
{
  return false ;
}

int qx_stack_top(QxStack stack)
{
  if(qx_stack_empty(stack))
    return QX_LAMBDA_ELEMENT ;

  else
    return stack -> head -> n ;
}

bool qx_stack_contains(QxStack stack, int element)
{
  node *l = (node *) malloc(sizeof(node *)) ;
  l = stack -> head ;

  if(qx_stack_empty)
    return false ;

  while(l != NULL)
  {
    if(l -> n == element)
      return true ;

    l = l -> next ;
  }

  return false ;
}

size_t qx_stack_find(QxStack stack, int element)
{
  size_t count = 0 ;
  node *l = (node *) malloc(sizeof(node *)) ;
  l = stack -> head ;

  if(qx_stack_empty)
    return QX_INFINITY_SIZE ;

  while(l != NULL)
  {
    if(l -> n == element)
      return count ;

    l = l -> next ;
    ++count ;
  }
  return QX_INFINITY_SIZE ;
}

void qx_stack_push(QxStack stack, int elem)
{
  node *new = (node*) malloc(sizeof(node*)) ;
  new -> n = element ;
  new -> next = list -> head ;
  list -> head = new ;

  return;
}

void qx_stack_pop(QxStack stack)
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

void qx_stack_clear(QxStack stack)
{
  delete(list -> head) ;
  return ;
}

void qx_stack_print_to(QxStack stack, FILE *fp)
{
  node *l = (node*) malloc(sizeof(node*)) ;
  l = list -> head ;

  while(l != NULL)
  {
    printf("%d\n", l -> n) ;
    l = l -> next ;
  }
}
