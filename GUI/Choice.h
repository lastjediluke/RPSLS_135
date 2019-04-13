#ifndef CHOICE_H_
#define CHOICE_H_

#include "wx/wx.h"

// Choice represented by int.
typedef int Choice;
typedef int Round_count;

// Which object a player chooses each round.
enum { ROCK, PAPER, SCISSORS, NONE };
enum {one, two, three, four, five, six, seven, eight, nine, ten, eleven, twelve, thirteen, fourteen, fifteen, sixteen, seventeen, eightteen, nineteen, twenty};

/**
 * Convert a chosen object to a wxString.
 * @param choice the object to convert.
 * @return the wxString.
 */
wxString choice_to_wxString(Choice choice);
wxString round_count_to_wxString(Round_count round_count);

#endif /* CHOICE_H_ */
