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
#ifndef __MENU2__
#define __MENU2__ 
//menu_already_defined
// Esto tambien es un include guardian, pero solo funciona en windows
//#pragma once
// <order 1>
#include "comun.h"
#include "error.h"
#include "bookStore.h"
#include "funcionesImExport.h"

/** @brief Enum que contiene todas las opciones del menu de importacion/exportacion. */
enum IMPORT_EXPORT_MENU_OPTIONS{
    BACK = 'b',
    IMPORT = '1',
    EXPORT = '2',
    LOAD = '3',
    SAVE = '4',
};

/** @brief Procedimiento que muestra el menu de importacion/exportacion con sus opciones. */
void showImportExportMenu(){
    cout << "[Import/export options]" << endl
         << "1- Import from CSV" << endl
         << "2- Export to CSV" << endl
         << "3- Load data" << endl
         << "4- Save data" << endl
         << "b- Back to main menu" << endl
         << "Option:" << endl;
}

/**
 * @brief Funcion que decide si un string contiene una opcion del menu de importacion/exportacion
 * 
 * @param str string que contiene una opcion
 * @return true es una opcion del menu de importacion/exportacion
 * @return false NO es una opcion del menu de importacion/exportacion
 */
bool isOption_ImportExportMenu(const string& str){
    bool truth = false;
    if(str.empty() || str.length() != 1) return truth;
    char opt = tolower(str[0]);
    switch (opt)
    {
    case BACK:
    case IMPORT:
    case EXPORT:
    case LOAD:
    case SAVE:
        truth = true;
        break;
    default:
        break;
    }
    return truth;
}

void gestionaInteracciones_ImportExportMenu(BookStore &myBS)
{
    string opts;
    char opt;
    do{
        opts.clear();
        showImportExportMenu();
        getline(cin,opts,'\n');
        if(opts.empty() || !isOption_ImportExportMenu(trim(opts))){
            error(ERR_OPTION);
            continue;
        }
        opt = tolower(opts[0]);
        switch (opt)
        {
        case IMPORT:
            importFromCsv(myBS);
            break;
        case EXPORT:
            exportToCsv(myBS);
            break;
        case LOAD:
            loadData(myBS);
            break;
        case SAVE:
            saveData(myBS);
            break;
        case BACK:
            return;
        default:
            error(ERR_OPTION);
            continue;
        }
    }while(opt!=BACK);
}
#endif