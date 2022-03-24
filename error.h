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
#define __ERROR__ error_already_defined
// Esto tambien es un include guardian, pero solo funciona en windows
//#pragma once
// <order 0>
#include "comun.h"

/** @brief Enum que representa la lista de errores manejados. */
enum ERROR
{
    /** @brief Error por no introducir una opcion del menu correcta*/
    ERR_OPTION,

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
    
    default:
        cout << "ERROR: there is no error in ERROR type equal to: " << e << endl;
        break;
    }
}

#endif