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
#define __FUNCS__ 
//funcionesMain_already_defined
// Esto tambien es un include guardian, pero solo funciona en windows
//#pragma once
// <order 6> 
#include "comun.h"
#include "bookStore.h"
#include "book.h"
#include "menu2.h"

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
    Book b;
    bool isSafe = false;
    do{
        cout << "Enter book title:";
        getline(cin,opts,'\n');
        opts = trim(opts);
        
        if(! (isSafe = isSafeString(opts)) )
        {
            error(ERR_BOOK_TITLE);
        }
    }while(!isSafe);
    b.title = opts;
    opts.clear();
    do{
        cout << "Enter author(s):";
        getline(cin,opts,'\n');
        opts = trim(opts);
        if(! (isSafe = isSafeString(opts)) )
        {
            error(ERR_BOOK_AUTHORS);
        }
    }while(!isSafe);
    b.authors = opts;
    opts.clear();
    do{
        cout << "Enter publication year:";
        getline(cin,opts,'\n');
        opts = trim(opts);
        int yyyy = stoi(opts);
        if( !( 1440 <= yyyy && yyyy <= 2022 ))
        {
            error(ERR_BOOK_DATE);
            isSafe = false;
        }
        else isSafe = true;
    }while(!isSafe);
    b.year =  stoi(opts);
    opts.clear();
    do{
        cout << "Enter price:";
        getline(cin,opts,'\n');
        opts = trim(opts);
        float yyyy = stof(opts);
        if( yyyy < 0)
        {
            error(ERR_BOOK_PRICE);
            isSafe = false;
        }
        else isSafe = true;
    }while(!isSafe);
    b.price =  stoi(opts);
    opts.clear();
    b.slug = generateSlug(b);
    b.id = getNextID(myBookStore);
    addBook(myBookStore,b);
}

void deleteBook(BookStore& myBookStore)
{
    string opts;
    int id = -1;
    cout << "Enter id:";
    getline(cin,opts,'\n');
    if(opts.empty() || opts.length() == 0)
    {
        error(ERR_ID);
        return;
    }
    opts = trim(opts);
    id = stoi(opts);
    opts.clear();
    id = searchBook(myBookStore,id);
    if(id == -1)
    {
        error(ERR_ID);
        return;
    }
    deleteBook(myBookStore,id);
}

void importExportMenu(const BookStore& myBookStore)
{
    gestionaInteracciones_ImportExportMenu(myBookStore);
}

#endif