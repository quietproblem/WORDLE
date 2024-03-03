#include <iostream>
#include <sstream>
#include <fstream>
#include "Wordle.h"

using namespace std;

// struct Node
// {
//     string word;
//     Node *left;
//     Node *right;
// };



bool searchWord(Node *root)
{
    string word;
    cout << "Enter a word to search for: ";
    cin >> word;

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

int main()
{
//     Node *root = nullptr;
    
//     ifstream ifs;
//     ifs.open("testData.txt");

//     if(ifs.fail())
//     {
//         cerr << "File open error" << endl;
//         return 0;
//     }

//     while(!ifs.eof())
//     {
//         string line;
//         getline(ifs, line);
//         Node *newNode = new Node{line, nullptr, nullptr};

//         if(root==nullptr)
//         {
//             root = newNode;
//         }
//         else
//         {
//             Node *current = root;
//             while(current != nullptr)
//             {
//                 if(newNode->word < current->word)
//                 {
//                     if(current->left == nullptr)
//                     {
//                         current->left = newNode;
//                         break;
//                     }
//                     else
//                     {
//                         current = current->left;
//                     }
//                 }
//                 else
//                 {
//                     if(current->right == nullptr)
//                     {
//                         current->right = newNode;
//                         break;
//                     }
//                     else
//                     {
//                         current = current->right;
//                     }
//                 }
//             }
//         }
        
//     }

   
   
   
//    Node *crawler = root;
//     // printInOrder(crawler);

//     string word="12356";


//     cout<<searchWord(crawler)<<endl;


    Wordle instance;

    instance.init();

    instance.createList(instance.getRoot());
    instance.printInOrder();


}