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
    int result = importFromCsv(myBookStore, filename);
    if(result != 0)
    {
        error(ERR_FILE);
    }
}

void exportToCsv(const BookStore& myBookStore)
{
    cout << "Enter filename: ";
    string filename = "";
    getline(cin,filename,'\n');
    if(filename.empty() || filename.length()==0) return;
    int result = exportToCsv(myBookStore, filename);
    if(result != 0)
    {
        error(ERR_FILE);
    }
}

bool isYesNo(const string& str)
{
    string answer = tolower(trim(str));
    bool isYN = true;
    if(answer.length() != 1)
    {
        isYN = false;
    }
    else if(answer[0] == 'y' || answer[0]=='n')
    {
        isYN = true;
    }
    return isYN;
}

void loadData(BookStore& myBookStore)
{
    string answer = input("All data will be erased, do you want to continue (Y/N)?: ", isYesNo);
    char yn = answer[0];
    if(yn == 'n') return;
    cout << "Enter filename: ";
    string filename = "";
    getline(cin,filename,'\n');
    if(filename.empty() || filename.length()==0) return;
    int result = loadData(myBookStore, filename);
    if(result != 0)
    {
        error(ERR_FILE);
    }
}

void saveData(const BookStore& myBookStore)
{
    cout << "Enter filename: ";
    string filename = "";
    getline(cin,filename,'\n');
    if(filename.empty() || filename.length()==0) return;
    int result = saveData(myBookStore, filename);
    if(result != 0)
    {
        error(ERR_FILE);
    }
}
#endif