/************************************************************************
 **
 **  @file   qxdsearching.hpp
 **  @date   2018-8-13
 **  @author Arthur Rodrigues Araruna <ararunaufc(at)gmail.com>
 **
 **  @brief
 **  Definition of all functions related to searching in the library.
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


#ifndef QXDSEARCHING_H
#define QXDSEARCHING_H

#include "qxddefs.h"
#include <stdbool.h>

//.!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!//
//. OBSERVAÇÕES
//.
//. - Não altere este arquivo.
//. - Nos arquivos de implementação você pode definir outras funções para que
//.   sejam usadas como auxiliares das neste arquivo.
//.!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!//

/**
 * @enum  qxSortType
 * @brief Descreve o tipo de ordenação de um vetor.
 */
typedef enum {
    ARRAY_NOT_SORTED, /*!< Sem ordenação. */
    ARRAY_ASC,        /*!< Ordenado não-decrescente. */
    ARRAY_DESC        /*!< Ordenado não-crescente. */
} qxSortType;

/**
 * @brief Determina se o vetor contém o elemento informado em uma de
 *        suas posições.
 *
 * @param array     Vetor onde buscar o elemento \p element.
 * @param num_elems Quantidade de elementos no vetor.
 * @param element   Elemento a ser buscado em \p array.
 * @param sorting   Tipo de ordenação do vetor \p array.
 * @return          Se o elemento \p element pertence ao vetor \p array ou não.
 */
bool qx_contains(int array[], size_t num_elems, int element, qxSortType sorting);

/**
 * @brief Determina o índice onde podemos encontrar o elemento no vetor informados.
 *
 * @param array     Vetor onde buscar o elemento \p element.
 * @param num_elems Quantidade de elementos no vetor.
 * @param element   Elemento a ser buscado em \p array.
 * @param sorting   Tipo de ordenação do vetor \p array.
 * @return          Índice onde encontramos o elemento, ou \c #QX_LAMBDA_INDEX
 *                  caso o elemento não esteja no vetor.
 *
 * @see             ::qxIndex
 * @see             #QX_LAMBDA_INDEX
 */
qxIndex qx_find_index(int array[], size_t num_elems, int element, qxSortType sorting);

/**
 * @brief Determina o índice no vetor onde encontramos o elemento
 *        \em ínfimo do elemento informado.
 *
 * @param array     Vetor onde buscar o ínfimo.
 * @param num_elems Quantidade de elementos no vetor.
 * @param element   Elemento de referência ao ínfimo.
 * @param sorting   Tipo de ordenação do vetor \p array.
 * @return          Índice onde encontramos o ínfimo, ou \c #QX_LAMBDA_INDEX caso
 *                  não exista ínfimo.
 *
 * @see             ::qxIndex
 * @see             #QX_LAMBDA_INDEX
 */
qxIndex qx_lower_bound(int array[], size_t num_elems, int element, qxSortType sorting);

/**
 * @brief Determina o índice no vetor onde encontramos o elemento
 *        \em supremo do elemento informado.
 *
 * @param array     Vetor onde buscar o supremo.
 * @param num_elems Quantidade de elementos no vetor.
 * @param element   Elemento de referência ao supremo.
 * @param sorting   Tipo de ordenação do vetor \p array.
 * @return          Índice onde encontramos o supremo, ou \c #QX_LAMBDA_INDEX caso
 *                  não exista supremo.
 *
 * @see             ::qxIndex
 * @see             #QX_LAMBDA_INDEX
 */
qxIndex qx_upper_bound(int array[], size_t num_elems, int element, qxSortType sorting);


#endif // QXDSEARCHING_H
