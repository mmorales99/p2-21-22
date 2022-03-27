/**
 * @file error.h
 * @author Lolo (mjmorales.mcv@gmail.com)
 * @brief Cabecera donde se guarda todo lo relacionado con los errores
 * @version 0.1+1
 * @date 2022-03-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

// Estos ifs se llaman include guardian, evitan que el codigo se rompa.
#ifndef __ERROR__
#define __ERROR__ //error_already_defined
// Esto tambien es un include guardian, pero solo funciona en windows
//#pragma once
// <order 0>
#include "comun.h"

/** @brief Enum que representa la lista de errores manejados. */
enum ERROR
{
    /** @brief Error por no introducir una opcion del menu correcta */
    ERR_OPTION,
    /** @brief Error por titulo de libro no valido */
    ERR_BOOK_TITLE,
    /** @brief Error por autor no valido */
    ERR_BOOK_AUTHORS,
    /** @brief Error por anyo de publicacion no valido */
    ERR_BOOK_DATE,
    /** @brief Error por precio no valido */
    ERR_BOOK_PRICE,
    /** @brief Error por identificador no valido */
    ERR_ID,
    /** @brief Error por archivo no valido */
    ERR_FILE,
    /** @brief Error por argumentos del programa erroneos */
    ERR_ARGS
};

/** @brief Funcion que 'maneja' los errores producidos y listados en ERROR.
 * @param e Error que se ha producido
 */
void error(ERROR e)
{
    switch (e)
    {
    case ERR_OPTION:
        cout << "ERROR: wrong menu option" << endl;
        break;
    case ERR_BOOK_TITLE:
        cout << "ERROR: wrong title" << endl;
        break;
    case ERR_BOOK_AUTHORS:
        cout << "ERROR: wrong author(s)" << endl;
        break;
    case ERR_BOOK_DATE:
        cout << "ERROR: wrong publication date" << endl;
        break;
    case ERR_BOOK_PRICE:
        cout << "ERROR: wrong price" << endl;
        break;
    case ERR_ID:
        cout << "ERROR: wrong id" << endl;
        break;
    case ERR_FILE:
        cout << "ERROR: wrong file" << endl;
        break;
    case ERR_ARGS:
        cout << "ERROR: wrong args" << endl;
        break;
    default:
        cout << "ERROR: there is no error in ERROR type equal to: " << e << endl;
        break;
    }
}

#endif