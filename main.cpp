#include <iostream>

using namespace std;

char encryptLetter(char letter)
{
    int alphabetLenght = 26;
    int caesarKeyNumber = 3;
    if(letter!=32)         //spacje zostawiamy
        letter = char((letter-'A'+caesarKeyNumber)%alphabetLenght+'A');
    return letter;
}

char decryptLetter(char letter)
{
    int alphabetLenght = 26;
    int caesarKeyNumber = 3;
    if(letter!=32)         //spacje zostawiamy
        letter = char((letter-'A'+(alphabetLenght-caesarKeyNumber))%alphabetLenght+'A');
    return letter;
}

string encryptLine(string line)
{
    int lineLenght = line.length();
    for(int i=0; i<lineLenght; i++)
        line[i] = encryptLetter(line[i]);

    return line;
}

string decryptLine(string line)
{
    int lineLenght = line.length();
    for(int i=0; i<lineLenght; i++)
        line[i] = decryptLetter(line[i]);

    return line;
}

int main()
{
    string line;
    while(getline(cin,line))
    {
        if(line=="")
            break;
        cout << decryptLine(encryptLine(line)) << endl;
    }

    return 0;
}
