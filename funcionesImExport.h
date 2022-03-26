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
#ifndef __FUNCS2__
#define __FUNCS2__ 
//funcionesMain_already_defined
// Esto tambien es un include guardian, pero solo funciona en windows
//#pragma once
// <order 6> 
#include "comun.h"
#include "bookStore.h"
#include "book.h"
#include "binBookStore.h"
#include "binBook.h"

void importFromCsv(BookStore& myBookStore)
{
    cout << "Enter filename: ";
    string filename = "";
    getline(cin,filename,'\n');
    if(filename.empty() || filename.length()==0) return;
    vector<Book> readed =  readBookFromCSV(filename);
    if(readed.size() == 0 || readed.empty()) return;
    for(unsigned i = 0;i<readed.size();i++)
    {
        readed[i].id = getNextID(myBookStore);
        myBookStore.books.push_back(readed[i]);
    }
}

#endif