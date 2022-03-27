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
#include "binBookStore.h"
#include "binBook.h"

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

vector<Book> readBooksFromCSV(const string& filename)
{
    ifstream file(filename);
    vector<Book> books;
    if(file.is_open())
    {
        while(!file.eof())
        {
            string s;
            getline(file,s,'\n');
            Book b = readBookFromString(s);
            if(b.id != -1)
                books.push_back(b);
        }
    }
    file.close();
    return books;
}

string toCsv(const vector<Book>& v)
{
    stringstream ss;
    // ss << bs.name << "("<< bs.books.size()<<")" << endl;
    for (size_t i = 0; i < v.size(); i++)
    {
        Book b = v[i];
        ss << toLongString(b) << endl;
    }
    return ss.str();
}

int writeToCsv(const vector<Book>& v, const string& filename)
{
    int result = 0;
    ofstream file(filename,ios::out);
    if(file.is_open())
    {
    file << toCsv(v);  
    } 
    else
        result = 1;
    file.close();
    return result;
}

BookStore addBook(BookStore& myBookStore, Book b)
{
    myBookStore.books.push_back(b);
    return myBookStore;
}

BookStore deleteBook(BookStore& myBookStore, int pos){
    if(pos == -1) return myBookStore;
    myBookStore.books.erase(myBookStore.books.begin()+pos);
    return myBookStore;
}

int importFromCsv(BookStore& myBookStore, const string& filename)
{
    int result = 0;
    vector<Book> readed =  readBooksFromCSV(filename);
    if(readed.size() == 0 || readed.empty()) return 1; // error 1, no se han leido libros
    for(unsigned i = 0;i<readed.size();i++)
    {
        readed[i].id = getNextID(myBookStore);
        myBookStore.books.push_back(readed[i]);
    }
    return 0; // todo ha ido bien
}

int exportToCsv(const BookStore& myBookStore, const string& filename)
{
    int result = 0;
    vector<Book> exportable = myBookStore.books;
    if(exportable.size() == 0 || exportable.empty()) return 0; // error 1, no se han leido libros
    return writeToCsv(exportable, filename); // todo ha ido bien
}

int loadData(BookStore& myBookStore, const string& filename)
{
    int result = 0;
    BinBookStore bbs = readBinBookStore(filename,result);
    if(result == 0)
    {
        vector<BinBook> v = readBooksFromBin(filename,result);
        if((result == 0) && (!v.empty() || v.size()!=0) )
        {
            myBookStore = BBStoBS(bbs);
            myBookStore.books = VBBtoVB(v);
        }
    }
    return result;
}

int saveData(const BookStore& myBookStore, const string& filename)
{
    int result = 0;
    result = writeBookStoreToBin(filename,myBookStore);
    if(result == 0)
    {
        vector<Book> v = myBookStore.books;
        result = writeBooksToBin(filename,v);
    }
    return result;
}
#endif