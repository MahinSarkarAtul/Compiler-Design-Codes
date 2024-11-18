#include <iostream>
using namespace std;

int main()
{
    int i = 0;
    int j = 0;
    int k = 0;
    bool foundEquals = false;
    bool foundPlus=false;

    cout << "Please enter the statement" << endl;
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


        else if(statement[i]!=' ')
        {

            if(statement[i+1]==' '){

              cout << "Error"; // Print each character before '='
              break;
            }
            else
            {
                cout<<statement[i];
            }

        }

    }
}

