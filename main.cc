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
#define __MAIN__// main_already_defined
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
#include "menu.h"
#include "bookStore.h"

/**
 * @brief Programa que gestiona todas las operaciones soportadas por el programa principal
 * 
 * @param argc total de argumentos
 * @param argv vector de argumentos
 * @param myBS tienda de libros sobre la que operar e interactuar
 */
void gestionaArgumentos(int argc, char** argv, BookStore myBS)
{

}

/** @brief Programa principal */
int main(int argc, char** argv)
{
    BookStore myBS = createBookStore("My Book Store");
    gestionaArgumentos(argc, argv, myBS);
    gestionaInteracciones(myBS);
}

#endif