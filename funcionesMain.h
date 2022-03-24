/**
 * @file funcionesMain.h
 * @author Lolo (mjmorales.mcv@gmail.com)
 * @brief Cabecera donde se unen las funciones dela practica
 * @version 0.1+1
 * @date 2022-03-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

// Estos ifs se llaman include guardian, evitan que el codigo se rompa.
#ifndef __FUNCS__
#define __FUNCS__ funcionesMain_already_defined
// Esto tambien es un include guardian, pero solo funciona en windows
//#pragma once
// <order 6> 
//#include "comun.h"
#include "book.h"
#include "bookStore.h"
#include "binBook.h"
#include "binBookStore.h"

/**
 * @brief Muestra una lista con los libros
 * 
 * @details
 * Muestra una lista con los libros ordenados por el id con el formato:
 * id. titulo (anyo), precio
 * 
 * @param myBookStore tienda de libros a mostrar
 */
void showCatalog(const BookStore& myBookStore)
{
    string out = toShortString(myBookStore);
    cout << out;
    return;
}

/**
 * @brief Muestra una lista con los libros
 * 
 * @details
 * Muestra una lista con los libros ordenados por el id con el formato:
 * "titulo","autores",anyo,"URL",precio
 * 
 * @param myBookStore tienda de libros a mostrar
 */
void showExtendedCatalog(const BookStore& myBookStore)
{
    string out = toLongString(myBookStore);
    cout << out;
    return;
}


void addBook(BookStore& myBookStore)
{
    string opts;
    do{
        cout << "Enter book title:";
        getline(cin,opts,'\n');
        opts = trim(opts);
        if(!isSafeString(opts))
        {

        }
    }while(true);
}

#endif