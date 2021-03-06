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
#define __BOOKSTORE__ 
//bookstore_already_defined
// Esto tambien es un include guardian, pero solo funciona en windows
//#pragma once
// <order 3>
#include "comun.h"
#include "book.h"

/** @brief Estructura que representa una tienda de libros (BookStore) */
struct BookStore
{
    /** @brief Nombre de la tienda */
    string name;
    /** @brief Lista de libros */
    vector<Book> books;
    /** @brief Siguiente identificador en la secuencia */
    unsigned int nextId;
};

/**
 * @brief Funcion que crea una tienda de libros.
 * 
 * @param name nombre de la tienda
 * @param books lista de libros
 * @param nextId identificador desde donde empezar la secuencia
 * @return BS tienda de libros nueva con los valores por defecto/pasados por parametro
 */
BookStore createBookStore(
    string name = "",
    vector<Book> books = vector<Book>(),
    unsigned int nextId = 1
    )
{
    BookStore bs;
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
unsigned int getNextID(BookStore& bs)
{
    return bs.nextId++;
}

/**
 * @brief Funcion que convierte un BookStore en un string con los libros que tiene
 * 
 * @param b tienda de libros a convertir
 * @return string 
 */
string toShortString(BookStore bs)
{
    stringstream ss;
    //ss << bs.name << "(" << bs.books.size() << ")"<< ":" << endl;
    for(unsigned i = 0;i<bs.books.size();i++)
    {
        Book b = bs.books[i];
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
string toLongString(BookStore bs)
{
    stringstream ss;
    //ss << bs.name << "(" << bs.books.size() << ")"<< ":" << endl;
    for(unsigned i = 0;i<bs.books.size();i++)
    {
        Book b = bs.books[i];
        ss << toLongString(b) << endl;
    }
    return ss.str();
}

BookStore addBook(BookStore& myBookStore, Book b)
{
    myBookStore.books.push_back(b);
    return myBookStore;
}

/**
 * @brief Elastic search sobre la lista de libros
 * 
 * @param myBookStore 
 * @param b 
 * @return int 
 */
int searchBook(const BookStore& myBookStore, Book b)
{
    if(b.id==-1) return -1;
    if(myBookStore.books.empty() || myBookStore.books.size() == 0) return -1;
    for (unsigned i = 0; i < myBookStore.books.size(); i++)
    {
        Book baux = myBookStore.books[i];
        if(baux.id == b.id || baux.authors == b.authors || baux.price == b.price || baux.slug == b.slug || baux.title == b.title || baux.year == b.year)
        {
            return i;
        }
    }
    return -1;
}

int searchBook(const BookStore& myBookStore, int id=-1)
{
    if(id==-1) return id;
    if(myBookStore.books.empty() || myBookStore.books.size() == 0) return -1;
    for (unsigned i = 0; i < myBookStore.books.size(); i++)
    {
        Book b = myBookStore.books[i];
        if(b.id == id)
        {
            return i;
        }
    }
    return -1;
}

BookStore deleteBook(BookStore& myBookStore, int pos){
    if(pos == -1) return myBookStore;
    myBookStore.books.erase(myBookStore.books.begin()+pos);
    return myBookStore;
}
#endif