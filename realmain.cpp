#include <iostream>
#include <vector>
#include <iomanip>
#include "Wordle.h"

using namespace std;

enum Color
{
    GREEN,
    YELLOW,
    RED,
    DARK_GREY
};

struct characters
{
    char letter;
    Color color = DARK_GREY;
};

characters abc[26] = {{'Q', DARK_GREY}, {'W', DARK_GREY}, {'E', DARK_GREY}, {'R', DARK_GREY}, {'T', DARK_GREY}, {'Y', DARK_GREY}, {'U', DARK_GREY}, {'I', DARK_GREY}, {'O', DARK_GREY}, {'P', DARK_GREY}, {'A', DARK_GREY}, {'S', DARK_GREY}, {'D', DARK_GREY}, {'F', DARK_GREY}, {'G', DARK_GREY}, {'H', DARK_GREY}, {'J', DARK_GREY}, {'K', DARK_GREY}, {'L', DARK_GREY}, {'Z', DARK_GREY}, {'X', DARK_GREY}, {'C', DARK_GREY}, {'V', DARK_GREY}, {'B', DARK_GREY}, {'N', DARK_GREY}, {'M', DARK_GREY}};

void modifyLetter(char letter, Color color, characters abc[])
{
    //
    letter = toupper(letter);

    for (int i = 0; i < 26; i++)
    {
        if (letter == abc[i].letter && (color!=RED || abc[i].color!=YELLOW))
        {
            abc[i].color = color;
            break;
        }
    }
}

const char *greenColorCode = "\033[1;32m";
const char *yellowColorCode = "\033[1;33m";
const char *greyColorCode = "\033[1;30m";
const char *darkRedColorCode = "\033[1;31m";

// Reset color to default after printing
const char *resetColorCode = "\033[0m";

void printABC()
{
    //q-p
    //a-l
    //z-m

    for (int i = 0; i < 26; i++)
    {

        // if (i == 11 || i == 19)
        // {
        //     cout << "  ";
        // }

        if (abc[i].color == GREEN)
        {
            cout << greenColorCode << abc[i].letter << " " << resetColorCode;
        }

        else if (abc[i].color == YELLOW)
        {
            cout << yellowColorCode << abc[i].letter << " " << resetColorCode;
        }

        else if (abc[i].color == RED)
        {
            cout << darkRedColorCode << abc[i].letter << " " << resetColorCode;
        }

        else
        {
            cout << greyColorCode << abc[i].letter << " " << resetColorCode;
        }
        if (i == 9)
        {
            cout << endl
                 << " ";
        }

        if (i == 18)
        {
            cout << endl
                 << "  ";
        }
    }

    cout << endl
         << endl;
}

struct word
{
    string name;
    Color color[5] = {DARK_GREY, DARK_GREY, DARK_GREY, DARK_GREY, DARK_GREY};
};

int main()
{
    srand(time(0)); // seed the random number generator

    cout << "Welcome to wordle!" << endl;

    Wordle instance;
    instance.init();
    bool finished = false;
    string str1 = instance.generateRandom();



    string str2;

    vector<word> guesses;

    for (int i = 0; i < 7; i++)
    {



        if (i == 6)
        {
            cout << "TOO BAD! The correct word was " << str1 << endl;
            return -1;
        }

        str2 = "";
        word temporary;
        //This is where we receive user input
        while (instance.searchWord(str2) == false)
        {

            getline(cin, str2);

            if (instance.searchWord(str2) == false)
            {
                cout << "Please enter a valid word: " << endl;
            }
        }
        temporary.name = str2;
        system("clear");
        for (int i = 0; i < 5; i++)
        {
            int total = 0;
            int count = 0;
            for (int p = 0; p < 5; p++)
            {

                if (str1[i] == str1[p])
                {
                    total++;
                }
            }

            if (str2[i] == str1[i])

            {

                temporary.color[i] = GREEN;
                count++;
                continue;
            }

            else
            {
                for (int j = 0; j < 5; j++)
                {
                    if (str1[i] == str2[j] && count < total && temporary.color[j] != GREEN)
                    {

                        temporary.color[j] = YELLOW;
                        // cout << "yellow" << endl;
                        count++;
                        continue;
                    }
                }
            }
        }

        finished = true;
        for (int i = 0; i < 5; i++)
        {

            if (temporary.color[i] != GREEN)
            {
                finished = false;
                // cout << "ENTERED" << endl;
                break;
            }
        }
        // cout << temporary.name << endl;
        guesses.push_back(temporary);
        // cout << guesses.size() << endl;

        for (int i = 0; i < guesses.size(); i++)
        {
            if (i == 0)
            {
                cout << "WORDLE" << endl;
            }

            for (int j = 0; j < 5; j++)
            {
                if (guesses.at(i).color[j] == GREEN)
                {
                    
                    cout << "\033[32m" << guesses.at(i).name[j] << "\033[0m";
                    modifyLetter(guesses.at(i).name[j], GREEN, abc);
                }

                else if (guesses.at(i).color[j] == YELLOW)
                {
                    
                    cout << "\033[33m" << guesses.at(i).name[j] << "\033[0m"; // print in yellow
                    modifyLetter(guesses.at(i).name[j], YELLOW, abc);
                }

                else
                {
                    
                    cout << "\033[1;31m" << guesses.at(i).name[j] << "\033[0m";
                    modifyLetter(guesses.at(i).name[j], RED, abc);
                }
            }
            cout << endl;
        }
        cout << endl
             << endl;

        printABC();
        bool found = false;
        for (int i = 0; i < 5; i++)
        {
            if (guesses.back().color[i] != GREEN)
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            break;
        }
    }
    cout << "CONGRATS! See you tomorrow" << endl;
}
