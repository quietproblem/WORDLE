#ifndef WORDLE_H
#define WORDLE_H

#include <iostream>
#include <vector>
#include <random>

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
        string word_answer;
        vector<string> word_list;
        
    
    public:
        Wordle();
        ~Wordle();
        void init();
        bool searchWord(string);
        void createList(Node*);
        Node * getRoot();
        void printInOrder();
        string generateRandom();
        
};

#endif