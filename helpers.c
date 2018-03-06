// Helper functions for music
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include "helpers.h"
#include <math.h>

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    //Does the conversion. fraction[2] is the bottom of the frac
    return 8/(fraction[2] - 0);
}
// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    //declare place
    int place;
    //calculate semi-tones from A
    place = ((((int)note[0]) - 65) + (strlen(note) - 2)) + ((int)note[0]);
    place -= 65;
    //find the octave
    int octave = atoi(&note[(1*(strlen(note) - 2)+1)]);
    //calculate the freq and return
    float hold = (((float)place)/12);
    hold = pow(2, hold);
    hold = hold * 440;
    hold = hold/8;
    float temp = pow(2,((float)(octave - 1)));
    hold = hold*temp;
    int tmp = (int) hold;
    return tmp;
}


// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (s[0] != 'A' && s[0] != 'B' && s[0] != 'C' && s[0] != 'D' && s[0] != 'E' && s[0] != 'F' && s[0] != 'G')
    {
        return true;
    }
    return false;
}
