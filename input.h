#include <iostream>
#include <string>
#include <utility>
#include <limits>
#pragma once

using namespace std;

enum InputToken
{
    NO_INPUT,
    MOVE_UP,
    MOVE_DOWN,
    MOVE_LEFT,
    MOVE_RIGHT,
    TELEPORT,
    DO_NOTHING,
    GET_HELP,
    EXIT_GAME
};

//All available user string inputs.
constexpr pair<const char*, InputToken> TRANSLATION_TABLE[] = {
    {"up", MOVE_UP},
    {"u", MOVE_UP},
    {"down", MOVE_DOWN},
    {"d", MOVE_DOWN},
    {"left", MOVE_LEFT},
    {"l", MOVE_LEFT},
    {"right", MOVE_RIGHT},
    {"r", MOVE_RIGHT},
    {"cheat", TELEPORT},
    {"teleport", TELEPORT},
    {"nothing", DO_NOTHING},
    {"n", DO_NOTHING},
    {"help", GET_HELP},
    {"h", GET_HELP},
    {"hint", GET_HELP},
    {"end", EXIT_GAME},
    {"exit", EXIT_GAME},
    {"stop", EXIT_GAME},
    {"stp", EXIT_GAME},
    {"quit", EXIT_GAME}
};

InputToken parseInputString (const string& input)
{
    for (const auto& x : TRANSLATION_TABLE)
    {
        if (input == x.first) return x.second;
    }

    return NO_INPUT;
}

void flushInputStream ()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}