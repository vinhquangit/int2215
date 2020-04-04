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

const string &getNextHangman()
{
    const static string figure[] = {
    "   ------------+    \n"
    "   |    /           \n"
    "   |    O           \n"
    "   |   /|\\         \n"
    "   |   / \\         \n"
    "   |                \n"
    " -----      \n" ,
    "   ------------+     \n"
    "   |     |           \n"
    "   |     O           \n"
    "   |    /|\\         \n"
    "   |    / \\         \n"
    "   |        \n"
    " -----      \n",
        "   ------------+     \n"
    "   |      \\         \n"
    "   |      O          \n"
    "   |     /|\\        \n"
    "   |     / \\        \n"
    "   |      \n"
    " -----    \n",
    "   ------------+     \n"
    "   |     |           \n"
    "   |     O           \n"
    "   |    /|\\         \n"
    "   |    / \\         \n"
    "   |        \n"
    " -----      \n",
    };
    const int NUMBER_OF_FIGURES =
        sizeof(figure) / sizeof(string);
    static int currentFigure = 0;
    return figure[(currentFigure++) % NUMBER_OF_FIGURES];
}

const string &getNextDancingman()
{
    static string figure[] = {
    "     O     \n"
    "    /|\\   \n"
    "    | |    \n",
    "     O     \n"
    "    /|\\   \n"
    "    / \\   \n",
    "   __O__   \n"
    "     |     \n"
    "    / \\   \n",
    "    \\O/   \n"
    "     |     \n"
    "    / \\   \n",
    "   __O__   \n"
    "     |     \n"
    "    / \\   \n",
    "     O     \n"
    "    /|\\   \n"
    "    / \\   \n" ,
    "    O      \n"
    "    /|\\   \n"
    "    / \\   \n" ,
    "     O     \n"
    "    /|\\   \n"
    "    / \\   \n" ,
    "      O    \n"
    "    /|\\   \n"
    "    / \\   \n" ,
    "     O     \n"
    "    /|\\   \n"
    "    / \\   \n" ,
    };
    const int NUMBER_OF_FIGURES =
        sizeof(figure) / sizeof(string);
    static int currentFigure = 0;
    return figure[(currentFigure++) % NUMBER_OF_FIGURES];
}

void displayFinalResult(bool won, const string& word) {
    for (int j = 0; j < 20; j++) {
        for (int i = 0; i < 30; i++) cout << endl;
        if (won)
            cout << "Congratulations! You win!" << endl;
        else
            cout << "You lost. The correct word is " << word << endl;
        cout << (won ? getNextDancingman() : getNextHangman());
        this_thread::sleep_for(chrono::milliseconds(300));
    }
}