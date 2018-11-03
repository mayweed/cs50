// Helper functions for music
#include <cs50.h>
#include <math.h>
#include <string.h>
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
    //First parse input
    char n = note[0];
    int octave;
    int st_gap=0;

    //init st_gap
    if (note[1]=='#' || note[1]=='b'){
        octave=atoi(&note[2]);
        switch(note[1]){
            case '#':st_gap=1;break;
            case 'b':st_gap=-1;break;
        }
    }
    else
        octave=atoi(&note[1]);

    //Second configure semitones gap
    // 1-per notes
    switch (n){
        case 'A':st_gap+=0;break;
        case 'B':st_gap+=2;break;
        case 'C':st_gap+=-9;break;
        case 'D':st_gap+=-7;break;
        case 'E':st_gap+=-5;break;
        case 'F':st_gap+=-4;break;
        case 'G':st_gap+=-2;break;
    }

    //2-per octaves
    switch (octave){
        case 0:st_gap+=-48;break;
        case 1:st_gap+=-36;break;
        case 2:st_gap+=-24;break;
        case 3:st_gap+=-12;break;
        case 4:st_gap+=0;break;
        case 5:st_gap+=12;break;
        case 6:st_gap+=24;break;
        case 7:st_gap+=36;break;
    }

    //freq calculation
    double div = st_gap/12.;
    double f = pow(2,div)*440;
    double freq = round(f);

    return freq;
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
