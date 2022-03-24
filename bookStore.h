/**
 * @file bookStore.h
 * @author Lolo (mjmorales.mcv@gmail.com)
 * @brief Cabecera que contiene toda logica relacionada con bookStore
 * @version 0.1+1
 * @date 2022-03-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

// Estos ifs se llaman include guardian, evitan que el codigo se rompa.
#ifndef __BOOKSTORE__
#define __BOOKSTORE__ bookstore_already_defined
// Esto tambien es un include guardian, pero solo funciona en windows
//#pragma once
// <order 3>
#include "comun.h"

/** @brief Estructura que representa una tienda de libros (BookStore) */
struct BookStore
{
    /** @brief Nombre de la tienda */
    string name;
    /** @brief Lista de libros */
    vector<B> books;
    /** @brief Siguiente identificador en la secuencia */
    unsigned int nextId;
};

/** @brief Alias de BookStore - para escribir menos - no se tiene que hacer */
typedef BookStore BS;

/**
 * @brief Funcion que crea una tienda de libros.
 * 
 * @param name nombre de la tienda
 * @param books lista de libros
 * @param nextId identificador desde donde empezar la secuencia
 * @return BS tienda de libros nueva con los valores por defecto/pasados por parametro
 */
BS createBookStore(
    string name = "",
    vector<B> books = vector<B>(),
    unsigned int nextId = 1
    )
{
    BS bs;
    bs.name = name;
    bs.books = books;
    bs.nextId = nextId;
    return bs;
}

/**
 * @brief Funcion que devuelve el siguiente identificador de la secuencia de identificadores de una tienda de libros
 * 
 * @param bs tienda de libros de donde obtener el identificador
 * @return unsigned int identificador actual de la secuencia
 */
unsigned int getNextID(BS& bs)
{
    return bs.nextId++;
}

/**
 * @brief Funcion que convierte un BookStore en un string con los libros que tiene
 * 
 * @param b tienda de libros a convertir
 * @return string 
 */
string toShortString(BS bs)
{
    stringstream ss;
    //ss << bs.name << "(" << bs.books.size() << ")"<< ":" << endl;
    for(unsigned i = 0;i<bs.books.size();i++)
    {
        B b = bs.books[i];
        ss << toShortString(b) << endl;
    }
    return ss.str();
}

/**
 * @brief Funcion que convierte un BookStore en un string con los libros que tiene
 * 
 * @param b tienda de libros a convertir
 * @return string 
 */
string toLongString(BS bs)
{
    stringstream ss;
    //ss << bs.name << "(" << bs.books.size() << ")"<< ":" << endl;
    for(unsigned i = 0;i<bs.books.size();i++)
    {
        B b = bs.books[i];
        ss << toLongString(b) << endl;
    }
    return ss.str();
}

#endif