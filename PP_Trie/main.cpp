#include <iostream>
#include <fstream>
#include "Trie.h"

int main()
{
    std::ifstream ifs("wordsEn.txt");
    std::string word;
    Trie trie;
    while (ifs >> word)
    {
        trie.Push(word);
    }
    ifs.close();

    std::string text;
    std::cout << "Write your text!" << std::endl;
    std::getline(std::cin, text);
    while (text != "")
    {
        size_t index = text.find_last_of(' ');
        if (index != text.npos)
        {
            word = text.substr(index + 1, text.length());
            text.erase(index);
        }
        else
        {
            word = text;
            text.erase();
        }
        if (!trie.Contains(word))
        {
            std::cout << "Not a correct text! (" << word << ")" << std::endl;
            return 0;
        }
    }
    std::cout << "Correct text!" << std::endl;
    return 0;
}