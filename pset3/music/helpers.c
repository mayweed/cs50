// Helper functions for music

#include <cs50.h>

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int x= atoi(&fraction[0]);
    int y= atoi(&fraction[2]);
    int dur=0;
    switch(y){
        case 2:dur= x*4;break;
        case 4:dur= x*2;break;
        case 8:dur= x;break;
    }
    return dur;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    // TODO
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    // instead of an int, shouldnt it be better to use strlen()
    if (!strncmp(s,"",6))
        return true;
    else
        return false;
}
