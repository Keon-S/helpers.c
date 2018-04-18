// Helper functions for music
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include "helpers.h"
#include <math.h>
#define APOS 5

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    //Does the conversion. fraction[2] is the bottom of the frac
    return (8 * (fraction[0] - '0')) / (fraction[2] - '0');
}
// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    //Declare array of notes
    const char keys[] = {'C', 'D', 'E', 'F', 'G', 'A', 'B'};
    //declare place
    int place;
    //calculate semi-tones from A
    for (int i = 0; i < 7; i++)
    {
        if (keys[i] == note[0])
        {
            //Get number of semitones from A
            place = 2 * (i - APOS);
            place++;
            //Correct for the lack of a black key between E and F
            if (place / 2 > -2)
            {
                place--;
            }
        }
    }
    //Add # and b
    if (strlen(note) == 3)
    {
        if (note[1] == '#')
        {
            place++;
        }
        else
        {
            place--;
        }
    }
    //find the octave
    int octave = atoi(&note[(1 * (strlen(note) - 2) + 1)]);
    //calculate the freq and return
    float hold = (((float)place) / 12);
    hold = pow(2, hold);
    hold = hold * 440;
    hold = hold / 8;
    float temp = pow(2, ((float)(octave - 1)));
    hold = hold * temp;
    int tmp = round(hold);
    return tmp;
}


// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (s[0] == '\0')
    {
        return true;
    }
    return false;
}
