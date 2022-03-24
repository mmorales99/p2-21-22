#include <iostream>

using namespace std;

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

int main(){
    isSafeString("Ábe ce,da:ri-o71372 ñ");
    return 0;
}