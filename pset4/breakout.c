//
// breakout.c
//
// Computer Science 50
// Problem Set 4
//

// standard libraries
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <cs50.h>

// Stanford Portable Library
#include "gevents.h"
#include "gobjects.h"
#include "gwindow.h"

// height and width of game's window in pixels
#define HEIGHT 600
#define WIDTH 400

// number of rows of bricks
#define ROWS 5

// number of columns of bricks
#define COLS 10

// radius of ball in pixels
#define RADIUS 10

// lives
#define LIVES 3

// prototypes
void initBricks(GWindow window);
GOval initBall(GWindow window);
GRect initPaddle(GWindow window);
GLabel initScoreboard(GWindow window);
void updateScoreboard(GWindow window, GLabel label, int points);
GObject detectCollision(GWindow window, GOval ball);

int main(void)
{
    // seed pseudorandom number generator
    srand48(time(NULL));

    // instantiate window
    GWindow window = newGWindow(WIDTH, HEIGHT);

    // instantiate bricks
    initBricks(window);

    // instantiate ball, centered in middle of window
    GOval ball = initBall(window);

    // instantiate paddle, centered at bottom of window
    GRect paddle = initPaddle(window);

    // instantiate scoreboard, centered in middle of window, just above ball
    GLabel label = initScoreboard(window);

    // number of bricks initially
    int bricks = COLS * ROWS;

    // number of lives initially
    int lives = LIVES;

    // number of points initially
    int points = 0;

    // ball velocity keep that out of the while() else segfault
    double Xvelocity=drand48();
    double Yvelocity=1.0;

    // keep playing until game over
    while (lives > 0 && bricks > 0)
    {
        // check for mouse event
        GEvent event = getNextEvent(MOUSE_EVENT);

        // if we heard one
        if (event != NULL)
        {
            // if the event was movement
            if (getEventType(event) == MOUSE_MOVED)
            {
                // ensure paddle follows top cursor
                double x = getX(event);

                //ensure paddle stops at the right edge
                if (getX(event) + getWidth(paddle) >= getWidth(window)) x=330;

                setLocation(paddle, x, 530);
            }
        }

        move (ball,Xvelocity,Yvelocity);

        // linger before moving again
        pause(10);

        //bounce off bottom edge
        if (getY(ball) + getWidth(ball) >= getHeight(window))
        {
            Yvelocity= -Yvelocity;
            //Need to check staff's implementation first
            lives -=1;
        }

        //bounce off right edge
        if (getX(ball)+getWidth(ball) >= getWidth(window))
        {
            Xvelocity= -Xvelocity; 
        }
            
        //bounce off upper edge
        if (getY(ball) <= 0) 
        {
            Yvelocity = -Yvelocity;
        }
            

        //bounce off left edge
        if (getX(ball) <= 0)
        {
            Xvelocity= -Xvelocity;
        }      
        
        GObject object = detectCollision(window,ball);

        //sanity check
        if (object != NULL)
        {
            //in case paddle detected
            if (object==paddle)
            {
                Yvelocity= -Yvelocity;
            }
        
            //in case bricks detected
            else if ((strcmp(getType(object), "GRect")== 0) && (object != paddle))
            {
                Yvelocity= -Yvelocity;
                removeGWindow(window,object);
                bricks -= 1;
                points +=1;
            }
        }
    }

    // wait for click before exiting
    waitForClick();

    // game over
    closeGWindow(window);
    return 0;
}

/**
 * Initializes window with a grid of bricks.
 */
void initBricks(GWindow window)
{
    // Initialize coordinates, x abscisse/y ordonnee 
    int x=2;
    int y=50;

    // This is for the colors, cant get enum{} to work, array of strings
    // makes it so...
    int z=0;
    string Colors[5]= {"red", "orange", "yellow", "green", "cyan"};

    // Initialize brick
    int width=35;
    int height=10;

    // Usage: rect = newGRect(x, y, width, height);
    for (int i=0; i < ROWS; i++){
        for (int j=0; j < COLS; j++){
            GRect rect = newGRect(x, y, width, height);
            setFilled(rect, true);
            setColor(rect, Colors[z]);
            add(window, rect);
            x+= (width + 5); //5px between each
        }
        x=2; //Carriage return ^^
        y+=15; //Needed for the next line, width+5px
        z+=1; //Next line, next color
    }
}

/**
 * Instantiates ball in center of window.  Returns ball.
 */
GOval initBall(GWindow window)
{
    int x= 190;
    int y= 290;

    //cant get a comma-separated initialization of both of them...
    int width=20;
    int height=20;

    GOval ball = newGOval(x,y,width,height);
    setFilled(ball, true);
    setColor(ball, "BLACK");
    add(window, ball);

    return ball;
}

/**
 * Instantiates paddle in bottom-middle of window.
 */
GRect initPaddle(GWindow window)
{
    int x= 165;
    int width=70;
    int height=10;


    GRect paddle = newGRect(x, 530, width, height);
    setFilled(paddle, true);
    setColor(paddle, "BLACK");
    add(window, paddle);

    return paddle;
}

/**
 * Instantiates, configures, and returns label for scoreboard.
 */
GLabel initScoreboard(GWindow window)
{
    GLabel label = newGLabel("0");
    setFont(label, "SansSerif-24");
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) + getFontAscent(label)) / 2;
    setLocation(label, x, y);
    add(window, label);
    return label;
}

/**
 * Updates scoreboard's label, keeping it centered in window.
 */
void updateScoreboard(GWindow window, GLabel label, int points)
{
    // update label
    char s[12];
    sprintf(s, "%i", points);
    setLabel(label, s);

    // center label in window
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
}

/**
 * Detects whether ball has collided with some object in window
 * by checking the four corners of its bounding box (which are
 * outside the ball's GOval, and so the ball can't collide with
 * itself).  Returns object if so, else NULL.
 */
GObject detectCollision(GWindow window, GOval ball)
{
    // ball's location
    double x = getX(ball);
    double y = getY(ball);

    // for checking for collisions
    GObject object;

    // check for collision at ball's top-left corner
    object = getGObjectAt(window, x, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's top-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-left corner
    object = getGObjectAt(window, x, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // no collision
    return NULL;
}
