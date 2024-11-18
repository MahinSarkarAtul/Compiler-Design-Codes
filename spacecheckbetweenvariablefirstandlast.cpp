#include <iostream>
using namespace std;
////both space between variable , syntax
/////  space between and fist and last space and syntax
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
    bool inVariable = false;

    for (int i = 0; i < statement.length(); i++) {
        char currentChar = statement[i];

        // Ignore spaces between elements but not within variable names
        if (currentChar == ' ') {
            // Allow spaces after a completed variable but not within the name
            if (!variable.empty() && inVariable) {
                inVariable = false; // Space is allowed after a completed variable
            }
            continue; // Skip space
        }

        // Check for '=' as the first required operator
        if (currentChar == '=' && !foundEquals) {
            if (!variable.empty()) {
                cout << variable << endl; // Print the variable name
                cout << "=" << endl;
                foundEquals = true;
                variable = ""; // Reset for the next variable
            } else {
                cout << "Error: Missing variable before '='." << endl;
                return 1;
            }
        }
        // Check for '+' as the second required operator
        else if (currentChar == '+' && foundEquals && !foundPlus) {
            if (!variable.empty()) {
                cout << variable << endl; // Print the variable name
                cout << "+" << endl;
                foundPlus = true;
                variable = ""; // Reset for the next variable
            } else {
                cout << "Error: Missing variable before '+'." << endl;
                return 1;
            }
        }
        // Check for ';' as the last required operator
        else if (currentChar == ';' && foundEquals && foundPlus && !foundSemicolon) {
            if (!variable.empty()) {
                cout << variable << endl; // Print the last variable name
                cout << ";" << endl;
                foundSemicolon = true;
            } else {
                cout << "Error: Missing variable before ';'." << endl;
                return 1;
            }
        }
        // Build the variable name
        else if (isalnum(currentChar)) {
            if (!inVariable && !variable.empty()) {
                // Detect space within variable names for multi-character variables
                cout << "Error: Variable names cannot contain spaces within their name." << endl;
                return 1;
            }
            variable += currentChar;
            inVariable = true;
        }
        else {
            cout << "Error: Invalid character '" << currentChar << "' found in the statement." << endl;
            return 1;
        }
    }

    // Final check if all operators appeared in the required order
    if (!foundEquals || !foundPlus || !foundSemicolon) {
        cout << "Error: Statement format is incorrect. Expected format: 'variable = variable + variable;'" << endl;
        return 1;
    }

    cout << "Lexing successful!" << endl;
    return 0;
}
