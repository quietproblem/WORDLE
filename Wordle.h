#ifndef WORDLE_H
#define WORDLE_H

#include <iostream>

using namespace std;

struct Node
{
    string word;
    Node *left;
    Node *right;
};

class Wordle
{
    private:
        Node *root;
    
    public:
        Wordle();
        ~Wordle();
        void init();
        bool searchWord(string);
};

#endif