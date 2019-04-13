#include "Choice.h"

wxString choice_to_wxString(Choice choice)
{
    switch (choice)
    {
        case ROCK:     return "Rock";
        case PAPER:    return "Paper";
        case SCISSORS: return "Scissors";
        default:       return "none";
    }
}

wxString round_count_to_wxString(Round_count round_count)
{
    return std::to_string(round_count);
}

