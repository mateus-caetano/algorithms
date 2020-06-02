/************************************************************************
 **
 **  @file   qxdsorting.h
 **  @date   2018-8-13
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


#ifndef QXDSORTING_H
#define QXDSORTING_H

#include "qxddefs.h"

//.!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!//
//. OBSERVAÇÕES
//.
//. - Não altere este arquivo.
//. - Nos arquivos de implementação você pode definir outras funções para que
//.   sejam usadas como auxiliares das neste arquivo.
//. - Todos os algoritmos de ordenação devem ordenar de forma não-decrescente.
//.!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!//

//******* BÁSICOS
/**
 * @brief Ordena o vetor informado usando <em>ordenação por inserção</em>.
 *
 * @param[in,out] array     Vetor a ser ordenado.
 * @param[in]     num_elems Quantidade de elementos no vetor a ser ordenado.
 */
void qx_insertion_sort(int array[], size_t num_elems);

/**
 * @brief Ordena o vetor informado usando <em>ordenação por seleção</em>.
 *
 * @param[in,out] array     Vetor a ser ordenado.
 * @param[in]     num_elems Quantidade de elementos no vetor a ser ordenado.
 */
void qx_selection_sort(int array[], size_t num_elems);

/**
 * @brief Ordena o vetor informado usando <em>ordenação por borbulhamento</em>.
 *
 * @param[in,out] array     Vetor a ser ordenado.
 * @param[in]     num_elems Quantidade de elementos no vetor a ser ordenado.
 */
void qx_bubble_sort(int array[], size_t num_elems);

//******* EFICIENTES
/**
 * @brief Ordena o vetor informado usando <em>ordenação por entrelaçamento</em>.
 *
 * @param[in,out] array     Vetor a ser ordenado.
 * @param[in]     num_elems Quantidade de elementos no vetor a ser ordenado.
 */
void qx_merge_sort(int array[], size_t num_elems);

/**
 * @brief Ordena o vetor informado usando <em>ordenação por particionamento</em>.
 *
 * @param[in,out] array     Vetor a ser ordenado.
 * @param[in]     num_elems Quantidade de elementos no vetor a ser ordenado.
 */
void qx_quick_sort(int array[], size_t num_elems);

//******* ESPECÍFICOS
/**
 * @brief Ordena o vetor informado usando <em>ordenação por contagem</em>.
 *
 * @param[in,out] array     Vetor a ser ordenado.
 * @param[in]     num_elems Quantidade de elementos no vetor a ser ordenado.
 * @param[in]     min_val   Valor do \em menor elemento presente em \p array.
 * @param[in]     max_val   Valor do \em maior elemento presente em \p array.
 */
void qx_counting_sort(int array[], size_t num_elems, int min_val, int max_val);

/**
 * @brief Ordena o vetor informado usando <em>ordenação pelos dígitos</em>.
 *
 * @param[in,out] array     Vetor a ser ordenado.
 * @param[in]     num_elems Quantidade de elementos no vetor a ser ordenado.
 */
void qx_radix_sort_i(int   array[], size_t num_elems);
/**
 * @brief Ordena o vetor informado usando <em>ordenação pelos dígitos</em>.
 *
 * @param[in,out] array     Vetor a ser ordenado.
 * @param[in]     num_elems Quantidade de elementos no vetor a ser ordenado.
 * @param[in]     precision Número de casas decimais a considerar na ordenação.
 */
void qx_radix_sort_f(float array[], size_t num_elems, short precision);

#endif // QXDSORTING_H
