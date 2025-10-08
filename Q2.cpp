//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//#include <cstdlib>
//#include <ctime>
//#include <windows.h>   // For colors
//
//using namespace std;
//
//// Function to set text color
//void setColor(int color) {
//    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
//}
//
//// Load words from a text file
//vector<string> loadWords(const string& fileName) {
//    vector<string> words;
//    ifstream file(fileName);
//
//    if (!file.is_open()) {
//        setColor(12);
//        cout << "Error: Could not open file " << fileName << endl;
//        setColor(7);
//        exit(1);
//    }
//
//    string word;
//    while (getline(file, word)) {
//        if (!word.empty())
//            words.push_back(word);
//    }
//
//    file.close();
//    return words;
//}
//
//// Select a random word
//string getRandomWord(vector<string>& words) {
//    srand(time(0));
//    int index = rand() % words.size();
//    return words[index];
//}
//
//// Check if player has guessed the whole word
//bool isWordGuessed(const string& word, const string& guessWord) {
//    return word == guessWord;
//}
//
//// Main game logic
//void playHangman(const string& word) {
//    string guessed(word.length(), '_');
//    int mistakes = 0;
//    const int maxMistakes = 7;
//    vector<char> usedLetters;
//
//    setColor(14);
//    cout << "=============================" << endl;
//    cout << "         HANGMAN GAME        " << endl;
//    cout << "=============================" << endl;
//    setColor(7);
//
//    while (mistakes < maxMistakes && !isWordGuessed(word, guessed)) {
//        cout << "\nWord: ";
//        for (int i = 0; i < guessed.length(); i++) {
//            cout << guessed[i] << " ";
//        }
//        cout << endl;
//
//        cout << "Used letters: ";
//        for (int i = 0; i < usedLetters.size(); i++) {
//            cout << usedLetters[i] << " ";
//        }
//        cout << endl;
//
//        cout << "Remaining mistakes: " << (maxMistakes - mistakes) << endl;
//
//        setColor(11);
//        cout << "Enter a letter: ";
//        setColor(7);
//
//        char letter;
//        cin >> letter;
//        letter = tolower(letter);
//
//        bool alreadyUsed = false;
//        for (int i = 0; i < usedLetters.size(); i++) {
//            if (usedLetters[i] == letter) {
//                alreadyUsed = true;
//                break;
//            }
//        }
//
//        if (alreadyUsed) {
//            setColor(6);
//            cout << "You already used that letter. Try again." << endl;
//            setColor(7);
//            continue;
//        }
//
//        usedLetters.push_back(letter);
//        bool found = false;
//
//        for (int i = 0; i < word.length(); i++) {
//            if (tolower(word[i]) == letter) {
//                guessed[i] = word[i];
//                found = true;
//            }
//        }
//
//        if (found) {
//            setColor(10);
//            cout << "Correct guess!" << endl;
//        }
//        else {
//            mistakes++;
//            setColor(12);
//            cout << "Wrong guess! Remaining: " << (maxMistakes - mistakes) << endl;
//        }
//        setColor(7);
//    }
//
//    cout << "\n-----------------------------" << endl;
//
//    if (isWordGuessed(word, guessed)) {
//        setColor(10);
//        cout << "You won! The word was: " << word << endl;
//    }
//    else {
//        setColor(12);
//        cout << "You lost! The correct word was: " << word << endl;
//    }
//
//    setColor(7);
//    cout << "-----------------------------" << endl;
//}
//
//int main() {
//    vector<string> words = loadWords("words.txt");
//
//    if (words.empty()) {
//        cout << "No words found in the file!" << endl;
//        return 0;
//    }
//
//    string word = getRandomWord(words);
//    playHangman(word);
//
//    return 0;
//}
