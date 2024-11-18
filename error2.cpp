#include <iostream>
#include <cctype>
using namespace std;

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
    bool variableStarted = false;
    bool errorOccurred = false; // Flag to check if any error occurred

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
                variableStarted = false; // Reset for the next variable
            } else {
                cout << "Error: Missing variable before '='." << endl;
                errorOccurred = true;
                break; // Exit after error
            }
        }
        // Check for '+' as the second required operator
        else if (currentChar == '+' && foundEquals && !foundPlus) {
            if (!variable.empty()) {
                cout << variable << endl; // Print the variable name
                cout << "+" << endl;
                foundPlus = true;
                variable = ""; // Reset for the next variable
                variableStarted = false; // Reset for the next variable
            } else {
                cout << "Error: Missing variable before '+'." << endl;
                errorOccurred = true;
                break; // Exit after error
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
                errorOccurred = true;
                break; // Exit after error
            }
        }
        // Build the variable name and check for alphabetic start
        else if (isalnum(currentChar)) {
            if (!inVariable && !variable.empty()) {
                // Detect space within variable names for multi-character variables
                cout << "Error: Variable names cannot contain spaces within their name." << endl;
                errorOccurred = true;
                break; // Exit after error
            }
            // Ensure the variable starts with an alphabetic character
            if (!variableStarted) {
                if (!isalpha(currentChar)) {
                    cout << "Error: Variable names must start with an alphabet character." << endl;
                    errorOccurred = true;
                    break; // Exit after error
                }
                variableStarted = true;
            }
            variable += currentChar;
            inVariable = true;
        } else {
            cout << "Error: Invalid character '" << currentChar << "' found in the statement." << endl;
            errorOccurred = true;
            break; // Exit after error
        }
    }

    // If any errors occurred, stop further processing
    if (errorOccurred) {
        return 1; // Exit after printing error
    }

    // Final check if all operators appeared in the required order
    if (!foundEquals || !foundPlus || !foundSemicolon) {
        cout << "Error: Statement format is incorrect. Expected format: 'variable = variable + variable;'" << endl;
        return 1; // Exit after error
    }

    cout << "Lexing successful!" << endl;
    return 0;
}

