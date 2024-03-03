#include "Wordle.h"
#include <fstream>
#include <sstream>

/**
 * @brief Construct a new Wordle:: Wordle object
 * Sets root to nullptr
 */
Wordle::Wordle()
{
    root = nullptr;
    init();
    createList(root);
}

Wordle::~Wordle()
{
    //deconstructor
}

/**
 * @brief Initializes the binary search tree with the words from rawData.txt
 * 
 */
void Wordle::init()
{
    ifstream ifs;
    ifs.open("Wordle/rawData.txt");

    if(ifs.fail())
    {
        cerr << "File open error" << endl;
        return;
    }

    while(!ifs.eof())
    {
        string line;
        getline(ifs, line);
        Node *newNode = new Node{line, nullptr, nullptr};

        if(root==nullptr)
        {
            root = newNode;
        }
        else
        {
            Node *current = root;
            while(current != nullptr)
            {
                if(newNode->word < current->word)
                {
                    if(current->left == nullptr)
                    {
                        current->left = newNode;
                        break;
                    }
                    else
                    {
                        current = current->left;
                    }
                }
                else
                {
                    if(current->right == nullptr)
                    {
                        current->right = newNode;
                        break;
                    }
                    else
                    {
                        current = current->right;
                    }
                }
            }
        }
        
    }
}

Node * Wordle::getRoot()
{
    return root;
}

void Wordle::createList(Node* node) 
{
    if (node == nullptr) {
        return;
    }

    createList(node->left);
    //cout << node->word << endl;
    word_list.push_back(node->word);
    createList(node->right);
}

void Wordle::printInOrder() 
{
    for(int i = 0; i < word_list.size(); i++)
    {
        cout << word_list.at(i) << endl;
    }
}

bool Wordle::searchWord(string word)
{
    Node *current = root;
    while(current != nullptr)
    {
        if(word == current->word)
        {
            return true;
        }
        else if(word < current->word)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }
    return false;
}

string Wordle::generateRandom()
{
    int random = rand() % word_list.size();
    return word_list.at(random);
}