/**
 * @file binBookStore.h
 * @author Lolo (mjmorales.mcv@gmail.com)
 * @brief Cabecera que contiene toda logica relacionada con binBookStore
 * @version 0.1+1
 * @date 2022-03-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

// Estos ifs se llaman include guardian, evitan que el codigo se rompa.
#ifndef __BINBOOKSTORE__
#define __BINBOOKSTORE__
//binbookstore_already_defined
// Esto tambien es un include guardian, pero solo funciona en windows
//#pragma once
// <order 5>
#include "comun.h"
#include "binBook.h"
#include "bookStore.h"
#include "book.h"

/** @brief Estructura que representa en memoria fisica una tienda de libros */
struct BinBookStore
{    
    /** @brief Nombre de la tienda con 49 caracteres */
    char name[KMAXSTRING];
    /** @brief Siguiente identificador en la secuencia */
    unsigned int nextId;
};

/**
 * @brief Funcion que crea registro binario de una tienda de libros
 * 
 * @param name nombre de la tienda de libros con 49 caracteres
 * @param nextId identificador desde donde empezar la secuencia
 * @return BBS registro binario de una tienda de libros
 */
BinBookStore createBinBookStore(
    char name[KMAXSTRING] = NULL,
    unsigned int nextId = 1
    )
{
    BinBookStore bbs;
    bbs.nextId = nextId;
    strcpy(bbs.name,name);
    bbs.name[KMAXSTRING-1] = '\0';
    return bbs;
}

/**
 * @brief Funcion que crea registro binario de una tienda de libros
 * 
 * @param name nombre de la tienda de libros (string)
 * @param nextId identificador desde donde empezar la secuencia
 * @return BBS registro binario de una tienda de libros
 */
BinBookStore createBinBookStore(
    string name = "",
    unsigned int nextId = 1
    )
{
    return createBinBookStore(name.c_str(),nextId);
}

BookStore BBStoBS(const BinBookStore& bbs, BookStore& myBookStore)
{
    myBookStore = createBookStore( to_string(bbs.name), vector<Book>(), bbs.nextId);
    return myBookStore;
}
BookStore BBStoBS(const BinBookStore& bbs)
{
    BookStore myBookStore;
    BBStoBS(bbs, myBookStore);
    return myBookStore;
}

BinBookStore BStoBBS(const BookStore& myBookStore, BinBookStore& bbs)
{
    bbs = createBinBookStore(myBookStore.name,myBookStore.nextId);
    return bbs;
}
BinBookStore BStoBBS(const BookStore& myBookStore)
{
    BinBookStore bbs;
    BStoBBS(myBookStore,bbs);
    return bbs;
}

BinBookStore readBinBookStore(const string& filename, int& result)
{
    BinBookStore bbs;
    result = 0;
    ifstream file(filename, ios::in|ios::binary);
    if(file.is_open())
    {
        file.read((char*)&bbs, sizeof(BinBookStore));
    }
    else
        result = 1;
    file.close();
    return bbs;
}

int writeBookStoreToBin(const string& filename, const BookStore& myBookStore)
{
    int result = 0;
    BinBookStore bb = BStoBBS(myBookStore);
    ofstream file(filename, ios::out|ios::binary);
    if(file.is_open())
    {
        file.write((const char*)&bb,sizeof(BinBookStore));
    }
    else
        result = 1;
    file.close();
    return result;
}

#endif