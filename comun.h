/**
 * @file comun.h
 * @author Lolo (mjmorales.mcv@gmail.com)
 * @brief Cabecera donde guardamos todos los includes y las funciones comunes
 * @version 0.1+1
 * @date 2022-03-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

// Estos ifs se llaman include guardian, evitan que el codigo se rompa.
#ifndef __COMUN__
#define __COMUN__ comun_already_defined
// Esto tambien es un include guardian, pero solo funciona en windows
//#pragma once

// Este header solo lo usamos para no tener que poner todas las cabeceras que vamos a usar cada vez.
// Asi, los includes solo los pones una vez aqui y un include comun.h en cada archivo menos en este.
// <order -1> // este archivo debe ser lo primero que haya - siempre

// pragma region nos permite crear zonas de codigo que podemos ocultar y organizar facilmente
// en casi todos los editores de texto con compatiblidad con C/C++.
#pragma region CABECERAS ESTANDAR
    #include <iostream>
    #include <vector>
    #include <string>
    #include <cstring>
    #include <fstream>
    #include <sstream>
    #pragma region NAMESPACES
        using namespace std;
    #pragma endregion
#pragma endregion

#pragma region MIS FUNCIONES UTILES Y CONSTANTES
    #pragma region CONSTANTES

        /** @brief Constante del tamanyo maximo de una cadena de caracteres */
        const unsigned int KMAXSTRING = 50;

    #pragma endregion
    #pragma region FUNCIONES

        /** @brief Esta funcion devuelve una copia de un string sin espacios por la derecha.
         * @param str Cadena a sanitizar
         * @return Cadena sin espacios a la derecha
        */
        string rtrim(const string &str)
        {
            if(str.empty() || str.length() == 0) return "";
            size_t first = str.find_first_not_of(' ');
            if (first == std::string::npos) return "";
            string rtrimed = str.substr(first);
            return rtrimed;
        }

        /** @brief Esta funcion devuelve una copia de un string sin espacios por la izquierda.
         * @param str Cadena a sanitizar
         * @return Cadena sin espacios a la izquierda
        */
        string ltrim(const string &str)
        {
            if(str.empty() || str.length() == 0) return "";
            size_t last = str.find_last_not_of(' ');
            if (last == std::string::npos) return "";
            string ltrimed = str.substr(0,last);
            return ltrimed;
        }

        /** @brief Esta funcion devuelve una copia de un string sin espacios por los lados.
         * @param str Cadena a sanitizar
         * @return Cadena sin espacios a izquierda y derecha
        */
        string trim(const string& str)
        {
            string trimmed = ltrim(str);
            trimmed = rtrim(trimmed);
            return trimmed;
        }

        /**
         * @brief Decide si una cadena de texto contiene o no caracteres no admitibles
         * 
         * @param str cadena de texto a analizar
         * @return true es admitible
         * @return false NO es admitible
         */
        bool isSafeString(const string& str)
        {
            string safe = " :,-0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
            bool isSafe = false;
            for (size_t i = 0; i < str.length(); i++)
            {
                for (size_t j = 0; j < safe.length(); j++)
                {
                    isSafe = str[i]==safe[j] || isSafe;
                    cout << str[i] << " - " << isSafe << endl;
                }
                if(!isSafe || i == str.length()-1) return isSafe;
                isSafe = false;
            }
        }
        
    #pragma endregion
#pragma endregion

#pragma region MIS CABECERAS
    #include "error.h"
    #include "menu.h"
#pragma endregion

#endif