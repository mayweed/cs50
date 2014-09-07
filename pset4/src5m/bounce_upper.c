/**
 * bounce.c
 *
 * David J. Malan
 * malan@harvard.edu
 *
 * Bounces a circle back and forth in a window.
 */

// standard libraries
#include <stdio.h>

// Stanford Portable Library
#include "gevents.h"
#include "gobjects.h"
#include "gwindow.h"

int main(void)
{
    // instantiate window
    GWindow window = newGWindow(320, 240);

    // instantiate circle
    GOval circle = newGOval(0, 110, 20, 20);
    setColor(circle, "BLACK");
    setFilled(circle, true);
    add(window, circle);
    
    // initial velocity
    double velocity = 1.0;
    
    // bounce forever
    while (true)
    {
        // move circle along y-axis
        move(circle, 0, velocity);

        // bounce off bottom edge of window
        if (getY(circle) + getWidth(circle) >= getHeight(window))
        {
            velocity = -velocity;
        }

        // bounce off upper edge of window
        else if (getY(circle) <= 0)
        {
            velocity = -velocity;
        }

        // linger before moving again
        pause(10);
    }
}
