#include <iostream>
using namespace std;
//format and space check
int main()
{
    cout << "Please enter an arithmetic statement in the format 'variable = variable + variable;':" << endl;
    string statement;
    getline(cin, statement);
    cout << "Entered statement is: " << statement << endl;

    bool foundEquals = false;
    bool foundPlus = false;
    bool foundSemicolon = false;
    string variable = "";
    bool inVariable = false;  // Tracks if we are currently building a variable name

    for (int i = 0; i < statement.length(); i++)
    {
        char currentChar = statement[i];

        // Skip any leading spaces or spaces between operators
        if (currentChar == ' ')
        {
            if (inVariable && !variable.empty()) {
                // If we're in a variable and encounter a space after the first character
                cout << "Error: Variables cannot contain spaces within their name." << endl;
                return 1;
            }
            continue; // Ignore spaces between operators or leading spaces
        }

        // Check for '=' as the first required operator
        if (currentChar == '=' && !foundEquals)
        {
            if (variable.empty()) {
                cout << "Error: Missing variable before '='." << endl;
                return 1;
            }
            cout << variable << endl; // Print the variable name
            cout << "=" << endl;
            foundEquals = true;
            inVariable = false;
            variable = ""; // Reset for next variable
        }
        // Check for '+' as the second required operator
        else if (currentChar == '+' && foundEquals && !foundPlus)
        {
            if (variable.empty()) {
                cout << "Error: Missing variable before '+'." << endl;
                return 1;
            }
            cout << variable << endl; // Print the variable name
            cout << "+" << endl;
            foundPlus = true;
            inVariable = false;
            variable = ""; // Reset for next variable
        }
        // Check for ';' as the last required operator
        else if (currentChar == ';' && foundEquals && foundPlus && !foundSemicolon)
        {
            if (variable.empty()) {
                cout << "Error: Missing variable before ';'." << endl;
                return 1;
            }
            cout << variable << endl; // Print the last variable name
            cout << ";" << endl;
            foundSemicolon = true;
            break;
        }
        // Build the variable name without spaces in the middle
        else
        {
            // If we've already found part of a variable, set `inVariable` to true
            if (!variable.empty()) {
                inVariable = true;
            }
            variable += currentChar;
        }
    }

    // Verify that all required operators were found in the correct order
    if (!foundEquals || !foundPlus || !foundSemicolon)
    {
        cout << "Error: Statement format is incorrect. Expected format: 'variable = variable + variable;'" << endl;
        return 1;
    }

    cout << "Lexing successful!" << endl;
    return 0;
}
