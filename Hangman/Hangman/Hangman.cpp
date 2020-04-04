// Hangman.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <vector>
#include <thread>
#include <chrono>
#include "draw.h"

using namespace std;

const char *FILENAME = "wordList.txt";
const int MAX_BAD_GUESSES = 7;

string chooseWord(const char *fileName)
{
    vector<string> wordList;
    ifstream file;
    file.open(fileName);
    if (file.is_open()) {
        string word;
        while (file >> word) {
            wordList.push_back(word);
        }
        file.close();
    }
    else cout << "Unable to open file";
    if (wordList.size() > 0) {
        srand(time(NULL));
        int randomIndex = rand() % wordList.size();
        return wordList[randomIndex];
    }
    else return "";
}

string initializeGuessedWord(const string &secretWord) {
    string guessedWord = "";
    int n = secretWord.length();
    for (int i = 0; i < n; i++) guessedWord.push_back('*');
    return guessedWord;
}

char readGuess() {
    char c;
    cout << "Enter your answer: ";
    cin >> c;
    return c;
}

bool contained(const string &secretWord, const char &guess) {
    if (secretWord.find(guess) != secretWord.npos) return true;
    else return false;
}

void update(string &guessedWord, const string &secretWord, const char &guess) {
    int n = secretWord.length();
    for (int i = 0; i < n; i++)
        if (secretWord[i] == guess) guessedWord[i] = guess;
}

void playHangman() {
    string secretWord = chooseWord(FILENAME);
    string guessedWord = initializeGuessedWord(secretWord);
    int badGuessCount = 0;
    do {
        renderGame(guessedWord, badGuessCount);
        char guess = readGuess();
        if (contained(secretWord, guess)) update(guessedWord, secretWord, tolower(guess));
        else ++badGuessCount;
    } while (badGuessCount < 7 && secretWord != guessedWord);
    displayFinalResult(badGuessCount < MAX_BAD_GUESSES, secretWord);
}

int main() {
    char c;
    do {
        playHangman();
        do {
            cout << "Wanna play more? (Y/N): ";
            cin >> c;
            if (c == 'y' || c == 'Y') break;
            if (c == 'n' || c == 'N') return 0;
            cout << "Error! Try Again!";
        } while (tolower(c) != 'y' && tolower(c) != 'n');
    } while (tolower(c) != 'n');
    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
