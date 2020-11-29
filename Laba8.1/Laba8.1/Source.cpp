#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

void Change(char* str)
{
    char str2[50];
    int j = 0;

    for (int i = 0; i < strlen(str); i++)
        if (str[i] == ',')
        {
            str2[j++] = '*';
            str2[j++] = '*';
        }
        else
        {
            str2[j] = str[i];
            j++;
        }
    str2[j] = '\0';

    str = str2;

    cout << str << endl;
}

int GetThirdComma(char* str)
{
    int SkipCommaCounter = 2;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == ',') {
            if (SkipCommaCounter != 0) {
                SkipCommaCounter--;
                continue;
            }
            return i;
        }
    }
    return -1;
}


int main()
{
    char str[50];
    
    cout << "Enter string: " << endl;
    cin.getline(str, 49);
    cout << endl;

    cout << "Index of third comma: " << endl;
    cout << GetThirdComma(str) << endl;
    cout << endl;
    
    cout << "Modified string: " << endl;
    Change(str);
}