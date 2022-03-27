/**
 * @file argumentos.h
 * @author Lolo (mjmorales.mcv@gmail.com)
 * @brief 
 * @version 0.1+1
 * @date 2022-03-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

// Estos ifs se llaman include guardian, evitan que el codigo se rompa.
#ifndef __ARGS__
#define __ARGS__// main_already_defined
// Esto tambien es un include guardian, pero solo funciona en windows
//#pragma once

/* En comun voy a poner todo.
 * En la practica para la universidad, todo tiene que estar dentro del mismo archivo.
 * En las primeras lineas de cada archivo, escribire una cosa como esta:
 * // <order X>
 * 
 * En comun estaran los includes ordenados.
 */

// <order 7>
#include "bookStore.h"

int gestionaArgumentos(int argc, char** argv, BookStore& myBS)
{
    if(argc==0) return 0;
    if( (argc) %2!=0) return 1;
    unsigned ic = 0;
    string ifile;
    unsigned lc = 0;
    string lfile;
    for(unsigned i = 1;i<argc+1;i++)
    {
        if(i==0) continue;
        if(argv[i]== "-i")
        {
            ic++;
            ifile = argv[i++];
        }
        if(argv[i]== "-l")
        {
            lc++;
            lfile = argv[i++];
        }
    }
    if(lc == 1)
    {
        loadData(myBS,lfile);
    }
    else if(lc != 0) return 1;
    if(ic == 1)
    {
        importFromCsv(myBS,lfile);
    }
    else if(lc != 0) return 1;
    return 0;
}

#endif