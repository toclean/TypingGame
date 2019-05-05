#include <iostream>
#include <string>
#include <fstream>
#include <time.h>

#include "Loader.h"

using namespace std;

Loader::Loader()
{
    ReadFile();
}

void Loader::ReadFile()
{
    ifstream wordFile("wordlist.dat");

    if (!wordFile.is_open()) return;

    string line;

    cout << "Loading words..." << endl;
    while(getline(wordFile, line))
    {
        WordList.push_back(line);
    }

    cout << "Loaded " << Loader::WordList.size() << " words!" << endl;
}

string* Loader::GetWords(int numberOfWords)
{
    string* words[numberOfWords];

    for (int i = 0; i < numberOfWords; i++)
    {
        srand(time(NULL));
        words[i] = &WordList.at(rand() % WordList.size());
    }

    return *words;
}

// string Loader::GetSentence(int numberOfWords)
// {
//     string* words = GetWords(numberOfWords);
//     string array[numberOfWords];
//     string result = "";

//     for (int i = 0; i < numberOfWords; i++)
//     {
//         result += *(words + i) + " ";
//     }

//     return result;
// }