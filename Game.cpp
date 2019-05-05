#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <math.h> 
#include <stdlib.h>

#include "Loader.h"

using namespace std;

const int SUMMARY_SIZE = 10;
const int DELAY = 5;

void Print(string* sentence)
{
    int removed = 0;
    for (int i = 0; i < SUMMARY_SIZE; i++)
    {
        if (sentence[i] == "")
            removed++;
    }

    for (int i = removed; i < SUMMARY_SIZE; i++)
    {
        cout << sentence[i] << " ";
    }
}

void PrintWPM(int correctWords, chrono::time_point<chrono::system_clock> start)
{
    auto end = std::chrono::system_clock::now();

    chrono::duration<double> diff = end-start;

    double minutes = diff.count() / 60.00;

    cout << "WPM: " << correctWords / minutes << endl;
}

void ClearScreen()
{
    #ifdef _WIN32
        std::system("cls");
    #else
        // Assume POSIX
        std::system ("clear");
    #endif
}

int main()
{
    Loader loader = Loader();
    string* sentence =  loader.GetWords(SUMMARY_SIZE);

    int wrong = 0, currentIndex = 0, correctWords = 0;
    int wordsSuccessfullyTyped = 0;

    cout << "Starting in " << DELAY << " seconds..." << endl;
    auto begin = chrono::system_clock::now();
    
    int previous = -1;
    while(1)
    {
        bool five, four, three, two, one;
        auto now = chrono::system_clock::now();
        chrono::duration<double> diff = now-begin;

        double current = round(diff.count());

        if (previous != current)
            cout << DELAY - current << "..." << endl;
            previous = current;

        if (current == DELAY) break;
    }

    auto start = chrono::system_clock::now();

    while(1)
    {
        ClearScreen();
        PrintWPM(correctWords, start);
        Print(sentence);

        cout << endl;

        string input;
        cin >> input;

        if (input == sentence[currentIndex])
        {
            sentence[currentIndex] = "";
            currentIndex++;
            correctWords++;
        }
        else if (input == "exit")
        {
            break;
        }
        else
        {
            wrong = 0;
        }

        if (sentence[SUMMARY_SIZE - 1] == "")
        {
            sentence = loader.GetWords(SUMMARY_SIZE);
            currentIndex = 0;
        }
    }

    return 0;
}