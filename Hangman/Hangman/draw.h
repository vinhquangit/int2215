//#pragma once
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

string chooseWord(const char *fileName);
string initializeGuessedWord(const string &secretWord);
void renderGame(string &guessedWord, const int &badGuessCount);
char readGuess();
bool contained(const string &secretWord, const char &guess);
void update(string &guessedWord, const string &secretWord, const char &guess);
void displayFinalResult(bool won, const string &word);