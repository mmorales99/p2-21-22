/**
 * @file book.h
 * @author Lolo (mjmorales.mcv@gmail.com)
 * @brief Cabecera que contiene toda logica relacionada con book y binBook
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

#pragma region BOOK
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
    //ss += to_string(b.id) + ". " + b.title + " (" + to_string(b.year) + "), " + to_string(b.price) ;
    ss << b.id << ". " << b.title << " (" << b.year << "), " << b.price ;
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

Book deserializeBook(const string& str)
{
    //"titulo","autores",anyo,"URL",precio'
    Book b;
    if(str.empty() || str.length() == 0) return b;
    vector<string> tokens = tokenize(str,",","\"");
    if(tokens.empty() || tokens.size() ==0 ) return b;
    b = createBook( INT16_MAX ,tokens[0], tokens[1], stoi(tokens[2]), tokens[3], stof(tokens[4]));
    return b;
}

Book readBookFromString(const string& s)
{
    Book b = deserializeBook(trim(s));
    if(isSafeTitle(b.title))
        if(isSafeAuthor(b.authors))
            if(isSafeYear(to_string(b.year)))
                if(isSafePrice(to_string(b.price)))
                    return b;
    b.id = -1;
    return b;
}
#pragma endregion

#pragma region BIN_BOOK
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

Book BBtoB(const BinBook& bb, Book& b)
{
    b = createBook(bb.id,to_string(bb.title),to_string(bb.authors),bb.year,to_string(bb.slug),bb.price);
    return b;
}
Book BBtoB(const BinBook& bb)
{
    Book b;
    BBtoB(bb,b);
    return b;
}

BinBook BtoBB(const Book& b, BinBook& bb)
{
    bb = createBinBook(b.id,b.title,b.authors,b.year,b.slug,b.price);
    return bb;
}
BinBook BtoBB(const Book& b)
{
    BinBook bb;
    BtoBB(b,bb);
    return bb;
}

vector<Book> VBBtoVB(const vector<BinBook>& vbb, vector<Book>& vb)
{
    for(unsigned i = 0; i < vbb.size(); i++)
    {
        Book b = BBtoB(vbb[i]);
        vb.push_back(b);
    }
    return vb;
}
vector<Book> VBBtoVB(const vector<BinBook>& vbb)
{
    vector<Book> vb;
    VBBtoVB(vbb,vb);
    return vb;
}

vector<BinBook> VBtoVBB(const vector<Book>& vb, vector<BinBook>& vbb)
{
    for(unsigned i = 0; i < vb.size(); i++)
    {
        BinBook bb = BtoBB(vb[i]);
        vbb.push_back(bb);
    }
    return vbb;
}
vector<BinBook> VBtoVBB(const vector<Book>& vb)
{
    vector<BinBook> vbb;
    VBtoVBB(vb,vbb);
    return vbb;
}

vector<BinBook> readBooksFromBin(const string& filename, int& result)
{
    vector<BinBook> books;
    result = 0;
    ifstream file(filename, ios::in|ios::binary);
    if(file.is_open())
    {
        while(!file.eof())
        {
            BinBook bb;
            file.read((char*)&bb, sizeof(BinBook));
            books.push_back(bb);
        }
    }
    else
        result = 1;
    file.close();
    return books;
}

int writeBooksToBin(const string& filename,const vector<Book>& v)
{
    int result = 0;
    vector<BinBook> vb = VBtoVBB(v);
    ofstream file(filename, ios::out|ios::binary);
    if(file.is_open())
    {
        for(unsigned i = 0;i<vb.size();i++)
        {
            file.write((const char*)&vb[i],sizeof(BinBook));
        }
    }
    else
        result = 1;
    file.close();
    return result;
}
#pragma endregion

#endif