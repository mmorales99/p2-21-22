#include <iostream>
// #include "comun.h"
// #include "error.h"

using namespace std;


bool isnum(const string& str)
{
    bool truth = true;
    unsigned short int sepCounter = 0;
    for(unsigned i=0;i<str.length();i++)
    {
        if( sepCounter == 0 && (str[i] == '.' || str[i] == ',') )
        {
            sepCounter++;
            continue;
        } 
        truth = truth && isdigit(str[i]);
    }
    return truth;
}

int main(){
    cout << isnum(",1234.");
    return 0;
}