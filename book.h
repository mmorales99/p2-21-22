/**
 * @file book.h
 * @author Lolo (mjmorales.mcv@gmail.com)
 * @brief Cabecera que contiene toda logica relacionada con book
 * @version 0.1+1
 * @date 2022-03-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

// Estos ifs se llaman include guardian, evitan que el codigo se rompa.
#ifndef __BOOK__
#define __BOOK__// book_already_defined
// Esto tambien es un include guardian, pero solo funciona en windows
//#pragma once
// <order 2>
#include "comun.h"
#include "error.h"

const unsigned int KOLDEST_BOOK = 1440;

const unsigned int KYOUNGEST_BOOK = 2022;

const float KMIN_PRICE = 0.0f;

/** @brief Estructura que representa un Libro (Book) */
struct Book
{
    /** @brief Identificador de un libro*/
    unsigned int id;
    /** @brief Titulo/Nombre de un libro */
    string title;
    /** @brief Autores/Propietarios de un libro */
    string authors;
    /** @brief Anyo de impresion del libro */
    int year;
    /** @brief URL del libro */
    string slug;
    /** @brief Precio del libro */
    float price;
};

/**
 * @brief Funcion que crea un libro.
 * 
 * @param id Identificador del libro (valor por defecto = -1)
 * @param title Nombre/Titulo del libro (valor por defecto = "")
 * @param authors Autor/Propietario del libro (valor por defecto = "")
 * @param year Anyo de publicacion del libro (valor por defecto = 1970)
 * @param slug URL del libro (valor por defecto = "")
 * @param price Precio del libro (valor por defecto = 0.0)
 * @return B Libro nuevo con los valores por defecto/pasados por parametro
 */
Book createBook(
    unsigned int id = -1,
    string title = "",
    string authors = "",
    int year = 1970,
    string slug = "",
    float price = 0.0
    )
{
    Book b;
    b.authors = authors;
    b.id = id;
    b.title = title;
    b.year = year;
    b.slug = slug;
    b.price = price;
    return b;
}

/**
 * @brief Funcion que devuelve un string que representa un libro con formato 'id titulo (anyo), precio'
 * 
 * @param b libro a convertir
 * @return string 'id titulo (anyo), precio'
 */
string toShortString(Book b)
{
    stringstream ss;
    ss << b.id << ". " << b.title << " (" << b.year <<"), " << b.price ;
    return ss.str();
}

/**
 * @brief Funcion que devuelve un string que representa un libro con formato 'titulo,autores,anyo,URL,precio'
 * 
 * @param b libro a convertir
 * @return string '"titulo","autores",anyo,"URL",precio'
 */
string toLongString(Book b)
{
    stringstream ss;
    ss << "\"" << b.title << "\",\"" << b.authors << "\"," << b.year << ",\"" << b.slug << "\"," << b.price;
    return ss.str();
}

string generateSlug(const Book& b)
{
    string title = tolower(b.title);
    for(unsigned i = 0;i<title.length();i++)
    {
        if(!isalnum(title[i])) title[i] = '-';
    }
    title = trim(title,'-');
    title = reduce(title,'-');
    return title;
}

bool isSafeTitle(const string& str)
{
    bool isSafe = isSafeString(str);
    if(!isSafe)
    {
        error(ERR_BOOK_TITLE);
    }
    return isSafe;
}

bool isSafeAuthor(const string& str)
{
    bool isSafe = isSafeString(str);
    if(!isSafe)
    {
        error(ERR_BOOK_AUTHORS);
    }
    return isSafe;
}
bool isSafeYear(const string& str)
{
    if(!isnum(str)) return false;
    int yyyy = stoi(str);
    if( !( KOLDEST_BOOK <= yyyy && yyyy <= KYOUNGEST_BOOK ))
    {
        error(ERR_BOOK_DATE);
        return false;
    }
    return true;
}
bool isSafePrice(const string& str)
{
    if(!isnum(str)) return false;
    float pp = stof(str);
    if( pp < KMIN_PRICE)
    {
        error(ERR_BOOK_PRICE);
        return false;
    }
    return true;
}


vector<Book> readBookFromCSV(const string& filename)
{
    ifstream file(filename);
    if(file.is_open())
    {
        vector<Book> books;
        while(!file.eof())
        {
            string s;
            getline(file,s,'\n');
            Book b = deserializeBook(s);
            if(isSafeTitle(b.title) && isSafeAuthor(b.authors) && isSafeYear(itos(b.year)) && isSafePrice(ftos(b.price)))
                books.push_back(b);
        }
        file.close();
        return books;
    }
    else
    {
        file.close();
        error(ERR_FILE);
        return vector<Book>();
    }
}

#endif