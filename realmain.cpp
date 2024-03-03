#include <iostream>
#include <vector>

#include "Wordle.h"

using namespace std;

enum Color
{
    GREEN,
    YELLOW,
    GREY
};

struct word
{
    string name;
    Color color[5] = {GREY, GREY, GREY, GREY, GREY};
};

int main()
{
    cout<<"Welcome to wordle!"<<endl;
    Wordle instance;

    instance.init();
    bool finished = false;
    string str1 = "state";
    string str2;

    vector<word> guesses;

    for (int i = 0; i < 7; i++)
    {

        if (i == 7)
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
                }

                else if (guesses.at(i).color[j] == YELLOW)
                {
                    cout << "\033[33m" << guesses.at(i).name[j] << "\033[0m"; // print in yellow
                }

                else
                {
                    cout << guesses.at(i).name[j];
                }
            }
            cout << endl;
        }

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
