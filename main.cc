/**
 * @file main.cc
 * @author Lolo (mjmorales.mcv@gmail.com)
 * @brief Main de la practica 2
 * @version 0.1+1
 * @date 2022-03-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

// Estos ifs se llaman include guardian, evitan que el codigo se rompa.
#ifndef __MAIN__
#define __MAIN__ main_already_defined
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
#include "comun.h"

/**
 * @brief Programa que gestiona todas las operaciones soportadas por el programa principal
 * 
 * @param argc total de argumentos
 * @param argv vector de argumentos
 * @param myBS tienda de libros sobre la que operar e interactuar
 */
void gestionaArgumentos(int argc, char** argv, BS myBS)
{

}

/**
 * @brief Programa que realiza toda la logica e interaccion con el usuario en la terminal
 * 
 * @param myBS tienda de libros sobre la que operar e interactuar
 */
void gestionaInteracciones(BS &myBS)
{
    string opts;
    char opt;
    do{
        opts.clear();
        showMainMenu();
        getline(cin,opts,'\n');
        if(opts.empty() || !isOption_MainMenu(trim(opts))){
            error(ERR_OPTION);
            continue;
        }
        opt = tolower(opts[0]);
        switch (opt)
        {
        case SHOW_CATALOG:
            showCatalog(myBS);
            break;
        case SHOW_EXTENDED_CATALOG:
            showCatalog(myBS);
            break;
        case ADD_BOOK:
            addBook(myBS);
            break;
        case EXIT:
        //case QUIT: // no hay que ponerlo xq EXIT y QUIT valen lo mismo
            cout << "Saliendo..."<<endl;
            break;
        default:
            error(ERR_OPTION);
            continue;
        }
    }while(opt!=EXIT);
}

/** @brief Programa principal */
int main(int argc, char** argv)
{
    BS myBS = createBookStore("My Book Store");
    gestionaArgumentos(argc, argv, myBS);
    gestionaInteracciones(myBS);
}

#endif