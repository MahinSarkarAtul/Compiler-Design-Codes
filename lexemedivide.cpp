#include <iostream>
using namespace std;
//by sir
int main()
{
    int i = 0;
    int j = 0;
    int k = 0;
    bool foundEquals = false;
    bool foundPlus=false;

    cout << "Please enter the statement format must be(a=b+c; and no space) :" << endl;
    string statement;
    getline(cin, statement);
    cout << "Entered statement is :" << statement << endl;

    for (int i = 0; i < statement.length(); i++)
    {
        // Check if the character is '='
        if (statement[i] == '=')
        {
            cout << endl << "=" << endl; // Print '=' on a new line
            break; // Exit the loop when '=' is found
        }
        else if (statement[i]!=' '){

        cout << statement[i]; // Print each character before '='
        }

    }

    for (int i = 0; i < statement.length(); i++)
    {
        // Check if the character is '='
        if (statement[i] == '=')
        {
            foundEquals = true;
           // cout << "=" << endl; // Print '=' and move to a new line
            continue;
        }

        // If '=' has been found, start printing characters after it
        if (foundEquals)
        {
            if (statement[i] == '+')
            {
                cout << endl << "+" << endl; // Print '+' on a new line
                break; // Exit the loop after finding '+'
            }
                    else if (statement[i]!=' '){

        cout << statement[i]; // Print each character before '='
        }
        }
    }
     for (int i = 0; i < statement.length(); i++)
    {
        // Check if the character is '='
        if (statement[i] == '+')
        {
            foundPlus = true;
           // cout << "=" << endl; // Print '=' and move to a new line
            continue;
        }

        // If '=' has been found, start printing characters after it
        if (foundPlus)
        {
            if (statement[i] == ';')
            {
                cout << endl << ";" << endl; // Print '+' on a new line
                break; // Exit the loop after finding '+'
            }
        else if (statement[i]!=' '){

        cout << statement[i]; // Print each character before '='
        }
        }
    }

}



