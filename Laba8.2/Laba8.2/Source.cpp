#include <iostream>
#include <string>
using namespace std;

int GetOpenBrecketIndex(char* str)
{
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '(')
            return i;
    }
    return -1;
}
int GetCloseBrecketIndex(char* str)
{
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == ')')
            return i;
    }
    return -1;
}

bool IsBrecketPair(char* str) {
    int FirstBrecketIndex = GetOpenBrecketIndex(str);
    int SecondBrecketIndex = GetCloseBrecketIndex(str);

    return FirstBrecketIndex != -1 && SecondBrecketIndex != -1 && SecondBrecketIndex > FirstBrecketIndex;
}

char* GetSubString(char* str, int start, int end) {
    int resultLeng = end - start - 1;
    char* result = new char[resultLeng];
    for (int i = start, j = 0; i < end; i++) {
        result[j] = str[i];
        j++;
    }
    return result;
}

bool ValidateInnerBreckets(char* str) {
    int BracketCounter = 0;
    bool BracketFind = false;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '(')
            BracketCounter--;

        if (str[i] == ')')
            BracketCounter++;

        if (BracketCounter == -2)
            BracketFind = true;

        if (BracketCounter == 0 && BracketFind)
            return false;
    }
    return true;
}

char* RemoveBrackets(char* str)
{
    int FirstBrecketIndex = GetOpenBrecketIndex(str);
    int SecondBrecketIndex = GetCloseBrecketIndex(str);
  
    if (FirstBrecketIndex == -1 || SecondBrecketIndex == -1) {
        return str;
    }
    if (SecondBrecketIndex <= FirstBrecketIndex)
        return str;

    int resultLeng = strlen(str) - (SecondBrecketIndex - FirstBrecketIndex + 1) + 1;
    char* result = new char[resultLeng];

    for (int i = 0, j = 0; i < strlen(str); i++) {
        if (i >= FirstBrecketIndex && i <= SecondBrecketIndex)
            continue;
        result[j] = str[i];
        j++;
    }
    result[resultLeng - 1] = '\0';
    if (IsBrecketPair(result)) {
        return RemoveBrackets(result);
    }
    return result;
}


int main()
{
    char str[50];

    cout << "Enter string:" << endl;
    cin.getline(str, 49);

    if (!ValidateInnerBreckets(str)) {
        cout << "Error: found inner brackets " << endl;
        return -1;
    }

    char* result = RemoveBrackets(str);
    cout << "Result: " << result << endl;
    return 0;
}