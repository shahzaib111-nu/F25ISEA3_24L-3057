// ===============================
//        Palindrome Checker
// ===============================

#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>   // For colors
#include <cctype>      // For tolower()
using namespace std;

// Function to set console text color
void setColor(int colorCode) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorCode);
}

// Convert string to lowercase (using tolower from <cctype>)
string toLowerCase(const string& str) {
    string lower;
    for (char ch : str) {
        lower += tolower(static_cast<unsigned char>(ch));
    }
    return lower;
}

// Check if a string is a palindrome
bool isPalindrome(const string& str) {
    if (str.empty() || str[0] == ' ')
        return false;

    int left = 0;
    int right = str.length() - 1;

    while (left < right) {
        if (str[left] != str[right])
            return false;
        left++;
        right--;
    }
    return true;
}

// Ask user for input
string getUserInput() {
    string input;
    cout << endl;
    setColor(11); // Light cyan
    cout << "Enter a string to check: ";
    setColor(7);  // Default color
    getline(cin, input);
    return toLowerCase(input);
}

// Main palindrome checking loop
void runPalindromeChecker() {
    setColor(14); // Yellow title
    cout << "===================================" << endl;
    cout << "          PALINDROME CHECKER       " << endl;
    cout << "===================================" << endl;
    setColor(7);
    cout << "Press ESC at any time to exit.\n" << endl;

    while (true) {
        string input = getUserInput();

        // If user enters ESC directly
        if (input.length() == 1 && input[0] == 27) {
            setColor(12);
            cout << "\nExiting program..." << endl;
            setColor(7);
            break;
        }

        cout << endl;
        if (isPalindrome(input)) {
            setColor(10); // Green
            cout << "Result: Palindrome" << endl;
        }
        else {
            setColor(12); // Red
            cout << "Result: Not a Palindrome" << endl;
        }

        setColor(9); // Blue
        cout << "\nPress any key to continue or ESC to exit..." << endl;
        setColor(7);
        char key = _getch();
        if (key == 27) { // ESC key
            setColor(12);
            cout << "\nExiting program..." << endl;
            setColor(7);
            break;
        }
    }
}

// Main function
int main() {
    runPalindromeChecker();
    return 0;
}
