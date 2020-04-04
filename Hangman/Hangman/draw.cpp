#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <vector>
#include <thread>
#include <chrono>

using namespace std;

const string FIGURE[] = {
        "  -------------\n"
        "  |\n"
        "  |\n"
        "  |\n"
        "  |\n"
        "  |\n"
        "-----\n",
        "  -------------\n"
        "  |           |\n"
        "  |\n"
        "  |\n"
        "  |\n"
        "  |\n"
        "-----\n",
        "  -------------\n"
        "  |           |\n"
        "  |           O\n"
        "  |\n"
        "  |\n"
        "  |\n"
        "-----\n",
        "  -------------\n"
        "  |           |\n"
        "  |           O\n"
        "  |           |\n"
        "  |\n"
        "  |\n"
        "-----\n",
        "  -------------\n"
        "  |           |\n"
        "  |           O\n"
        "  |          /|\n"
        "  |\n"
        "  |\n"
        "-----\n",
        "  -------------\n"
        "  |           |\n"
        "  |           O\n"
        "  |          /|\\\n"
        "  |\n"
        "  |\n"
        "-----\n",
        "  -------------\n"
        "  |           |\n"
        "  |           O\n"
        "  |          /|\\\n"
        "  |          /\n"
        "  |\n"
        "-----\n",
        "  -------------\n"
        "  |           |\n"
        "  |           O\n"
        "  |          /|\\\n"
        "  |          / \\\n"
        "  |\n"
        "-----\n"
};

void renderGame(string &guessedWord, const int &badGuessCount) {
    //for (int i = 0; i < 60; i++) cout << endl;
    cout << guessedWord << endl;
    cout << FIGURE[badGuessCount];
}

void displayFinalResult(bool won, const string &word) {
    if (won) cout << "CONGRATULATION! YOU WIN!";
    else cout << "YOU LOSE!";
    cout << "The answer is: " << word << '\n';
}