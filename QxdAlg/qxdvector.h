/************************************************************************
 **
 **  @file   qxdvector.h
 **  @date   2018-11-7
 **  @author Arthur Rodrigues Araruna <ararunaufc(at)gmail.com>
 **
 **  @brief
 **
 **  @copyright
 **  This source code is part of an educational project, associated with
 **  an undergraduate course or extension project, that is hosted at
 **  Universidade Federal do Ceará, Campus Quixadá.
 **  Copyright (C) 2018 UFC Quixadá, All Rights Reserved.
 **
 **  This project is free software: you can redistribute it and/or modify
 **  it under the terms of the GNU General Public License as published by
 **  the Free Software Foundation, either version 3 of the License, or
 **  (at your option) any later version.
 **
 **  This project is distributed in the hope that it will be useful,
 **  but WITHOUT ANY WARRANTY; without even the implied warranty of
 **  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 **  GNU General Public License for more details.
 **
 **  You should have received a copy of the GNU General Public License
 **  along with the source code of this project. If not, see
 **  <http://www.gnu.org/licenses/>.
 **
 *************************************************************************/

#ifndef ED_QXALG_QXDVECTOR_H
#define ED_QXALG_QXDVECTOR_H

#include "qxddefs.h"
#include <stdio.h>

//.!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!//
//. OBSERVAÇÕES
//.
//. - Não altere este arquivo.
//. - Nos arquivos de implementação você pode definir outras funções para que
//.   sejam usadas como auxiliares das neste arquivo.
//.!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!//

struct __qxd_vector;

/**
 * Representa uma <em>Lista Sequencial</em>, ou apenas \em Vetor.
 */
typedef struct __qxd_vector *QxVector;


/**
 * @name Gestão de vida
 */
///@{
/**
 * Cria um novo vetor.
 *
 * @param  initCapacity Capacidade inicial do vetor.
 * @pre    \p initCapacity > 0
 * @return Novo vetor.
 */
QxVector qx_vector_new(size_t initCapacity);

/**
 * Descarta um vetor. O uso do vetor informado após ser descartado não é válido.
 *
 * @param vector Vetor que será descartado.
 */
void qx_vector_delete(QxVector vector);
///@}

/**
 * @name Consulta de estado
 */
///@{
/**
 * Determina o tamanho de um vetor.
 *
 * @param vector Vetor a consultar.
 * @return Número de elementos no vetor.
 */
size_t qx_vector_size(QxVector vector);

/**
 * Determina a capacidade máxima atual do vetor.
 *
 * A diferença entre a capacidade e o tamanho determina o número de elementos
 * que ainda podemos inserir sem causar uma realocação de memória no vetor.
 *
 * @param vector Vetor a consultar.
 * @return Número de espaços existentes para elementos no vetor.
 */
size_t qx_vector_capacity(QxVector vector);

/**
 * Determina se um vetor está ou não vazio.
 *
 * @param vector Vetor a consultar.
 * @return \c true se \p vector informado não possui elementos; \c false
 *         caso contrário.
 */
bool qx_vector_empty(QxVector vector);

/**
 * Determina se o vetor está com sua capacidade completamente ocupada por
 * elementos.
 *
 * Ou seja, caso a resposta seja \c true, não há espaço livre para novos
 * elementos, de forma que uma nova inserção causaria uma realocação de
 * memória no vetor.
 *
 * @param vector Vetor a consultar.
 * @return \c true caso \p vector informado não possua espaço livre; \c false
 *         caso contrário.
 */
bool qx_vector_full(QxVector vector);
///@}

/**
 * @name Consulta de elementos
 */
///@{
/**
 * Determina se um vetor possui um elemento com valor igual a um valor informado.
 *
 * @param vector Vetor a consultar.
 * @param element Valor a procurar.
 * @return \c true se algum dos elementos de \p vector possui valor
 *         \p element; \c false caso contrário.
 */
bool qx_vector_contains(QxVector vector, int element);

/**
 * Determina o índice em um vetor da primeira ocorrência de um elemento com
 * um valor informado.
 *
 * @param vector Vetor a consultar.
 * @param element Valor a procurar.
 * @param fromIndex Índice a partir do qual considerar a busca, ou seja, a
 *        busca inicia neste índice.
 * @return Índice do primeiro elemento em \p vector com valor \p element,
 *         considerado a partir de \p fromIndex; #QX_LAMBDA_INDEX caso
 *         nenhum elemento encontrado.
 */
qxIndex qx_vector_find(QxVector vector, int element, qxIndex fromIndex);

/**
 * Determina o índice em um vetor da última ocorrência de um elemento com um
 * valor informado.
 *
 * @param vector Vetor a consultar.
 * @param element Valor a procurar.
 * @param upToIndex Índice até o qual considerar a busca, ou seja, a busca vai
 *        no máximo até este índice.
 * @return Índice do último elemento em \p vector com valor \p element,
 *         considerado no máximo até \p upToIndex; #QX_LAMBDA_INDEX caso nenhum
 *         elemento encontrado.
 */
qxIndex qx_vector_find_last(QxVector vector, int element, qxIndex upToIndex);

/**
 * Determina o valor do elemento de um vetor em um determinado índice.
 *
 * @param vector Vetor a consultar.
 * @param index Índice a considerar.
 * @return Valor do elemento no índice \p index, caso exista; #QX_LAMBDA_ELEMENT
 *         caso \p index esteja fora dos limites de \p vector.
 */
int qx_vector_at(QxVector vector, qxIndex index);

/**
 * Determina o valor do primeiro elemento de um vetor.
 *
 * @param vector Vetor a consultar.
 * @return  Valor do primeiro elemento de \p vector, caso exista;
 *          #QX_LAMBDA_ELEMENT caso \p vector esteja vazia.
 */
int qx_vector_font(QxVector vector);

/**
 * Determina o valor do último elemento de um vetor.
 *
 * @param vector Vetor a consultar.
 * @return  Valor do último elemento de \p vector, caso exista;
 *          #QX_LAMBDA_ELEMENT caso \p vector esteja vazia.
 */
int qx_vector_back(QxVector vector);
///@}

/**
 * @name Modificação
 */
///@{
/**
 * Insere um novo elemento em um dado índice em um vetor, sem perder os
 * elementos anteriores.
 *
 * @param vector Vetor a modificar.
 * @param element Valor a inserir.
 * @param index Índice que o novo elemento deve ocupar.
 * @return \c true se a inserção foi realizada; \c false caso \p index seja
 *         inválido para \p vector ou caso não haja mais memória.
 */
bool qx_vector_insert_at(QxVector vector, int element, qxIndex index);

/**
 * Insere um novo elemento no \em início de um vetor, sem perder os elementos
 * anteriores.
 *
 * @param vector Vetor a modificar.
 * @param element Valor a inserir.
 */
void qx_vector_push_front(QxVector vector, int element);

/**
 * Insere um novo elemento no \em fim de um vetor, sem perder os elementos
 * anteriores.
 *
 * @param vector Vetor a modificar.
 * @param element Valor a inserir.
 */
void qx_vector_push_back(QxVector vector, int element);

/**
 * Remove de um vetor o \em primeiro elemento com um dado valor.
 *
 * @param vector Vetor a modificar.
 * @param element Valor a procurar.
 * @return Índice que o elemento removido \em ocupava no vetor; #QX_LAMBDA_INDEX
 *         caso não exista em \p vector elemento com valor \p element.
 */
qxIndex qx_vector_remove_element_first(QxVector vector, int element);

/**
 * Remove de um vetor o \em último elemento com um dado valor.
 *
 * @param vector Vetor a modificar.
 * @param element Valor a procurar.
 * @return Índice que o elemento removido \em ocupava no vetor; #QX_LAMBDA_INDEX
 *         caso não exista em \p vector elemento com valor \p element.
 */
qxIndex qx_vector_remove_element_last(QxVector vector, int element);

/**
 * Remove de um vetor \em todos os elementos com um dado valor.
 *
 * @param vector Vetor a modificar.
 * @param element Valor a procurar.
 * @return Quantidade de elementos removidos
 */
size_t qx_vector_remove_element_all(QxVector vector, int element);

/**
 * Remove um elemento de um vetor num índice dado.
 *
 * @param vector Vetor a modificar.
 * @param index Índice do elemento a ser removido.
 * @return \c true caso a remoção tenha ocorrido; \c false caso \p index seja
 *         inválido para \p vector.
 */
bool qx_vector_remove_at(QxVector vector, qxIndex index);

/**
 * Remove o primeiro elemento de um vetor.
 *
 * @param vector Vetor a modificar.
 */
void qx_vector_pop_front(QxVector vector);

/**
 * Remove o último elemento de um vetor.
 *
 * @param vector Vetor a modificar.
 */
void qx_vector_pop_back(QxVector vector);

/**
 * Remove \em todos os elementos de um vetor, tornando-o vazio.
 *
 * @param vector Vetor a modificar.
 */
void qx_vector_clear(QxVector vector);
///@}

/**
 * @name Extras
 */
///@{
/**
 * Gera a impressão de todos os elementos de um vetor, ordenados pelo índice,
 * no arquivo indicado. O arquivo informado pode inclusive ser uma das saídas
 * padrão (\c stdout ou \c stderr).
 *
 * @param vector Vetor a consultar.
 * @param fp Arquivo onde imprimir.
 * @see <a href="https://www.tutorialspoint.com/c_standard_library/c_function_fprintf.htm" target="_blank"
 * rel="noreferrer noopener">fprintf</a>
 */
void qx_vector_print_to(QxVector vector, FILE *fp);
///@}

#endif //ED_QXALG_QXDVECTOR_H
