/**
 * @file menu.h
 * @author Lolo (mjmorales.mcv@gmail.com)
 * @brief Cabecera que contiene todo el menu
 * @version 0.1+1
 * @date 2022-03-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

// Estos ifs se llaman include guardian, evitan que el codigo se rompa.
#ifndef __MENU__
#define __MENU__ menu_already_defined
// Esto tambien es un include guardian, pero solo funciona en windows
//#pragma once
// <order 1>
#include "comun.h"

/** @brief Enum que contiene todas las opciones del menu principal. */
enum MAIN_MENU_OPTIONS{
    EXIT = 'q',
    QUIT = 'q',
    SHOW_CATALOG = '1',
    SHOW_EXTENDED_CATALOG = '2',
    ADD_BOOK = '3',
    DELETE_BOOK = '4',
    IMPORT_EXPORT = '5'
};

/** @brief Procedimiento que muestra el menu principal con sus opciones. */
void showMainMenu(){
    cout << "[Options]" << endl
         << "1- Show catalog" << endl
         << "2- Show extended catalog" << endl
         << "3- Add book" << endl
         << "4- Delete book" << endl
         << "5- Import/export" << endl
         << "q- Quit" << endl
         << "Option:" << endl;
}

/**
 * @brief Funcion que decide si un string contiene una opcion del menu principal
 * 
 * @param str string que contiene una opcion
 * @return true es una opcion del menu principal
 * @return false NO es una opcion del menu principal
 */
bool isOption_MainMenu(const string& str){
    bool truth = false;
    if(str.empty() || str.length() != 1) return truth;
    char opt = tolower(str[0]);
    switch (opt)
    {
    case QUIT:
    case SHOW_CATALOG:
    case SHOW_EXTENDED_CATALOG:
    case ADD_BOOK:
    case DELETE_BOOK:
    case IMPORT_EXPORT:
        truth = true;
        break;
    default:
        break;
    }
    return truth;
}

#endif