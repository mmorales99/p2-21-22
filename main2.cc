#include <iostream>
#include "comun.h"
#include "error.h"

using namespace std;


int main(){
    string opts;
    bool isSafe = false;
    cout << "Enter publication year:";
    getline(cin,opts,'\n');
    cout << opts << endl;
    opts = ltrim(opts);
    cout << opts << endl;
    opts = rtrim(opts);
    cout << opts << endl;
    int yyyy = stoi(opts);
    cout << yyyy << endl;
    if( !( 1440 <= yyyy && yyyy <= 2022 ))
    {
        error(ERR_BOOK_DATE);
        isSafe = false;
    }
    else isSafe = true;
    return 0;
}