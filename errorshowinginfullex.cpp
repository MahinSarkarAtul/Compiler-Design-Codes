#include <iostream>
#include <cctype>
using namespace std;
//shows all error and print if  no error is there
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
    bool formatCorrect = true; // Flag for correct statement format

    // To store error messages
    string errorMessages = "";

    // Iterate through the input statement
    for (int i = 0; i < statement.length(); i++) {
        char currentChar = statement[i];

        // Ignore spaces between elements but not within variable names
        if (currentChar == ' ') {
            if (!variable.empty() && inVariable) {
                inVariable = false; // Space is allowed after a completed variable
            }
            continue; // Skip space
        }

        // Check for '=' as the first required operator
        if (currentChar == '=' && !foundEquals) {
            if (!variable.empty()) {
                foundEquals = true;
                variable = ""; // Reset for the next variable
                variableStarted = false; // Reset for the next variable
            } else {
                errorMessages += "Error: Missing variable before '='.\n";
                formatCorrect = false;
            }
        }
        // Check for '+' as the second required operator
        else if (currentChar == '+' && foundEquals && !foundPlus) {
            if (!variable.empty()) {
                foundPlus = true;
                variable = ""; // Reset for the next variable
                variableStarted = false; // Reset for the next variable
            } else {
                errorMessages += "Error: Missing variable before '+'.\n";
                formatCorrect = false;
            }
        }
        // Check for ';' as the last required operator
        else if (currentChar == ';' && foundEquals && foundPlus && !foundSemicolon) {
            if (!variable.empty()) {
                foundSemicolon = true;
            } else {
                errorMessages += "Error: Missing variable before ';'.\n";
                formatCorrect = false;
            }
        }
        // Build the variable name and check for alphabetic start
        else if (isalnum(currentChar)) {
            if (!inVariable && !variable.empty()) {
                // Detect space within variable names for multi-character variables
                errorMessages += "Error: Variable names cannot contain spaces within their name.\n";
                formatCorrect = false;
            }
            // Ensure the variable starts with an alphabetic character
            if (!variableStarted) {
                if (!isalpha(currentChar)) {
                    errorMessages += "Error: Variable names must start with an alphabet character.\n";
                    formatCorrect = false;
                }
                variableStarted = true;
            }
            variable += currentChar;
            inVariable = true;
        }
        // Check for invalid characters
        else {
            errorMessages += "Error: Invalid character '" + string(1, currentChar) + "' found in the statement.\n";
            formatCorrect = false;
        }
    }

    // Final check for the statement format
    if (!foundEquals || !foundPlus || !foundSemicolon) {
        errorMessages += "Error: Statement format is incorrect. Expected format: 'variable = variable + variable;'.\n";
        formatCorrect = false;
    }

    // If errors occurred, print all error messages and exit
    if (!formatCorrect) {
        cout << errorMessages;
        return 1; // Exit after printing all errors
    }

    // If there are no errors, print lexemes one by one
    cout << "Lexing successful!" << endl;
    cout << "Lexemes are as follows:" << endl;

    // Print the lexemes, assuming the lexemes are stored correctly
    for (int i = 0; i < statement.length(); i++) {
        char currentChar = statement[i];

        // Handle lexemes (variables and operators) only if no errors occurred
        if (isalpha(currentChar)) {
            variable = currentChar; // Start with the first character of the variable
            cout << variable << endl; // Print the variable name
        }
        else if (currentChar == '=' || currentChar == '+' || currentChar == ';') {
            cout << currentChar << endl; // Print the operator
        }
    }

    return 0;
}
