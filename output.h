#include <iostream>
#include <string>
#include <sstream>
#pragma once

using namespace std;

template<typename... Args>
string concatenate (Args const&... args)
{
    return (std::ostringstream() << ... << args).str();
}

template<typename... Args>
void print (Args const&... args)
{
    cout << concatenate(args...);
}

struct GameText
{
    static inline const string helpText = concatenate //@Explain why.
    (
        "Your goal is to walk far enough so that one of the numbers overflows (hint: short integer, 2 bytes).\n"
        "Type \"up\", \"down\", \"left\" or \"right\" to move around.\n",
        "Type \"nothing\" to do nothing.\n",
        "Type \"cheat\" to be teleported closer to the edge.\n",
        "Type \"exit\" to exit the game.\n",
        "Type \"help\" to get help\n\n"
    );

    static inline const string welcomeText = concatenate
    (
        "Welcome to the overflow game!\n",
        "=============================\n",
        "In this game, you can only walk, and that's fun.\n",
        helpText
    );

    static inline const string winText = "\n             YOU WIN!\n YOU HAVE REACHED THE OVERFLOW STATE.\n\n";

    static inline const string exitText = "Exitting the game.\n";
};
