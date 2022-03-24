/**
 * @file binBook.h
 * @author Lolo (mjmorales.mcv@gmail.com)
 * @brief Cabecera que contiene toda logica relacionada con binBook
 * @version 0.1+1
 * @date 2022-03-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

// Estos ifs se llaman include guardian, evitan que el codigo se rompa.
#ifndef __BINBOOK__
#define __BINBOOK__ binbook_already_defined
// Esto tambien es un include guardian, pero solo funciona en windows
//#pragma once
// <order 4>
#include "comun.h"

/** @brief Estructura que representa en memoria fisica un libro */
struct BinBook
{
    /** @brief identificador del libro */
    unsigned int id;
    /** @brief titulo del libro con 49 caracteres */
    char title[KMAXSTRING];
    /** @brief autores del libro con 49 caracteres */
    char authors[KMAXSTRING];
    /** @brief anyo de publicacion */
    int year;
    /** @brief URL del libro con 49 caracteres*/
    char slug[KMAXSTRING];
    /** @brief precio del libro */
    float price;
};

/**
 * @brief Funcion que crea registro binario de un libro
 * 
 * @param id identificador del libro
 * @param title titulo del libro con 49 caracteres
 * @param authors autor del libro con 49 caracteres
 * @param year anyo de publicacion
 * @param slug URL del libro con 49 caracteres
 * @param price precio del libro
 * @return BB registro binario nuevo con los valores por defecto/pasados por parametro
 */
BinBook createBinBook(
    unsigned int id = -1,
    char title[KMAXSTRING] = NULL,
    char authors[KMAXSTRING] = NULL,
    int year = 1970,
    char slug[KMAXSTRING] = NULL,
    float price = 0.0
    )
{
    BinBook bb;
    bb.id = id;
    strcpy(bb.title,title);
    bb.title[KMAXSTRING-1] = '\0';
    strcpy(bb.authors,authors);
    bb.authors[KMAXSTRING-1] = '\0';
    bb.year = year;
    strcpy(bb.slug,slug);
    bb.slug[KMAXSTRING-1] = '\0';
    bb.price = price;
    return bb;
}

/**
 * @brief Funcion que crea registro binario de un libro
 * 
 * @param id identificador del libro
 * @param title titulo del libro (string)
 * @param authors autor del libro (string)
 * @param year anyo de publicacion
 * @param slug URL del libro con (string)
 * @param price precio del libro
 * @return BB registro binario nuevo con los valores por defecto/pasados por parametro
 */
BinBook createBinBook(
    unsigned int id = -1,
    string title = "",
    string authors = "",
    int year = 1970,
    string slug = "",
    float price = 0.0
    )
{
    return createBinBook(id,title.c_str(),authors.c_str(),year,slug.c_str(),price);
}

#endif