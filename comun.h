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
#define __COMUN__ 
//comun_already_defined
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
        string rtrim(const string &str,const char trimable=' ')
        {
            if(str.empty() || str.length() == 0) return "";
            size_t first = str.find_first_not_of(trimable);
            if (first == std::string::npos) return "";
            string rtrimed = str.substr(first);
            return rtrimed;
        }

        /** @brief Esta funcion devuelve una copia de un string sin espacios por la izquierda.
         * @param str Cadena a sanitizar
         * @return Cadena sin espacios a la izquierda
        */
        string ltrim(const string &str, const char trimable=' ')
        {
            if(str.empty() || str.length() == 0) return "";
            size_t last = str.find_last_not_of(trimable);
            if (last == str.length()-1) return str;
            string ltrimed = str.substr(0,last);
            return ltrimed;
        }

        /** @brief Esta funcion devuelve una copia de un string sin espacios por los lados.
         * @param str Cadena a sanitizar
         * @return Cadena sin espacios a izquierda y derecha
        */
        string trim(const string& str,const char trimable=' ')
        {
            string trimmed = ltrim(str,trimable);
            trimmed = rtrim(trimmed,trimable);
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
                }
                if(!isSafe || i == str.length()-1) return isSafe;
                isSafe = false;
            }
            return isSafe;
        }

        /**
         * @brief Convierte una cadena a minusculas
         * 
         * @param str cadena con mayusculas
         * @return string cadena solo en minosculas
         */
        string tolower(const string& str)
        {
            string out = "";
            for(unsigned i = 0;i<str.length();i++)
            {
                out += tolower(str[i]);
            }
            return out;
        }

        string reduce(const string& str, const char reducible = ' ')
        {
            string out = "";
            for(unsigned i = 0;i<str.length();i++)
            {
                if(str[i] == str[i+1] && str[i] == reducible) continue;
                out += str[i];
            }
            return out;
        }

        bool isnum(const string& str)
        {
            bool truth = true;
            unsigned short int sepCounter = 0;
            for(unsigned i=0;i<str.length();i++)
            {
                if( sepCounter++ == 0 && (str[i] == '.' || str[i] == ',') ) continue;
                truth = truth && isdigit(str[i]);
            }
            return truth;
        }

        string input(const string& str, bool (*callback)(const string&) )
        {
            string in;
            bool isSafe = false;
            do{
                cout << str;
                getline(cin,in,'\n');
                in = trim(in);
                isSafe = callback(in);
            }while(!isSafe);
            return in;
        }

        vector<string> tokenize(const string& str, const string& seps = " \n\r\0", const string& ignos = "\"\'")
        {
            vector<string> vs;
            if(str.empty() || str.length()==0) return vs;
            string s = trim(str);
            s = reduce(s);
            unsigned i = 0;
            bool isIgno = false;
            bool isSep = false;
            char currigno = (char)0;
            string aux = "";
            do{
                char curr = s[i];
                for(unsigned j = 0;j<ignos.length();j++)
                {
                    if(curr == ignos[j] && currigno == (char)0){ isIgno = true; currigno = curr; }
                    if(curr == ignos[j] && currigno == curr){ isIgno = false; currigno = (char)0; }
                }
                if(!isIgno)
                {
                    for(unsigned j = 0;j<seps.length();j++)
                    {
                        if(curr == seps[j]){ isSep = true; }
                    }
                }
                if(isSep || i == s.length()-1 )
                {
                    vs.push_back(aux);
                    aux.clear();
                    isSep = false;
                }
                else
                    aux += curr;
                i++;
            }while(i<s.length());
            return vs;
        }

        string to_string(const char* arr, const long unsigned int max_leng = INTMAX_MAX)
        {
            string out = "";
            unsigned i = 0;
            while ( arr[i]!='\0' && i < max_leng )
            {
                out += arr[i];
                i++;
            }
            out += "\0";
            return out;
        }
        
    #pragma endregion
#pragma endregion

#endif