#include <iostream>
#include <vector>

class Loader
{
    public:
        std::vector<std::string> WordList;
        Loader();
        std::string* GetWords(int);
        //std::string GetSentence(int);
    private:
        void ReadFile();
};