//
// breakout.c
//
// Computer Science 50
// Problem Set 3
//

// standard libraries
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Stanford Portable Library
#include <spl/gevents.h>
#include <spl/gobjects.h>
#include <spl/gwindow.h>

// height and width of game's window in pixels
#define HEIGHT 600
#define WIDTH 400

// height and width of the paddle
#define PADDLEHEIGHT 10
#define PADDLEWIDTH 50

// height and width of bricks
#define BRICKHEIGHT 10
#define BRICKWIDTH ((WIDTH-(BRICKPADDING*COLS+1))/COLS)//depends on width window & numb o COLS :-)
#define BRICKPADDING 10

#define BALLSIZE 20

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
    
    // ball's speed
    double velocity_x = drand48() * 3;
    double velocity_y = 3.0;
    
    // Wait for click for the game to start
    waitForClick();

    // keep playing until game over
    while (lives > 0 && bricks > 0)
    {
        // TODO
        // check for mouse event
        GEvent event = getNextEvent(MOUSE_EVENT);

        // if we heard one
        if (event != NULL)
        {
            // if the event was movement
            if (getEventType(event) == MOUSE_MOVED)
            {
                // ensure paddle follows top cursor
                double x = getX(event) - getWidth(paddle) / 2;
                double y = HEIGHT - PADDLEWIDTH;
                setLocation(paddle, x, y);
            }
        }
        
         // move ball along x and y-axis
        

        // if we heard one
        move(ball, velocity_x, velocity_y);

        
        // update scoreboard
        updateScoreboard(window, label, points);

        // bounce off right edge of window
        if (getX(ball) + getWidth(ball) >= getWidth(window))
        {
            velocity_x = -velocity_x;
        }

        // bounce off left edge of window
        if (getX(ball) <= 0)
        {
            velocity_x = -velocity_x;
        }
        
        // bounce off top of window
        if (getY(ball) <= 0)
        {
            velocity_y = -velocity_y;
        }
        
        // If ball the bottom of window
        if (getY(ball) + getHeight(ball) > getHeight(window))
        {
            setLocation(ball, (WIDTH / 2 - BALLSIZE / 2), (HEIGHT / 2 - BALLSIZE / 2));
            setLocation(paddle, WIDTH / 2 - PADDLEWIDTH / 2, HEIGHT - PADDLEWIDTH);
            lives = lives - 1;
            waitForClick();
        }
        
        // bounce of paddle and bricks, not scoreboard
        // Ik snap niet helemaal waarom dit werkt....
        
        // call function detectCollision
        GObject detectCollision(GWindow window, GOval ball);
        
        GObject object = detectCollision(window, ball);
        if (object != NULL)
        {
            if (strcmp(getType(object), "GRect") == 0 && object != label)
            {
                velocity_y = -velocity_y;
                if (strcmp(getType(object), "GRect") == 0 && object != paddle)
                {
                    removeGWindow(window, object);
                    points++;
                    bricks--;
                }
            }
        }

        
        // linger before moving again
        pause(10);
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
    char* colors [] = {"003329", "006652", "00997A", "00CCA3", "00FFCC"};
    // TODO 
    for (int i=0; i < ROWS; i++)
    {
        for (int j=0; j < COLS; j++)
        {
            GRect brick = newGRect(BRICKPADDING + j * (BRICKWIDTH + BRICKPADDING), BRICKPADDING + i * (BRICKHEIGHT + BRICKPADDING), BRICKWIDTH, BRICKHEIGHT);
            setFilled(brick, true);
            setColor(brick, colors[i]);
            add(window, brick);
        }
    }
}

/**
 * Instantiates ball in center of window.  Returns ball.
 */
GOval initBall(GWindow window)
{
    // TODO
    GOval ball = newGOval((WIDTH / 2 - BALLSIZE / 2), (HEIGHT / 2 - BALLSIZE / 2),BALLSIZE,BALLSIZE);
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
    // TODO
    GRect paddle = newGRect(WIDTH / 2 - PADDLEWIDTH / 2, HEIGHT - PADDLEWIDTH, PADDLEWIDTH, PADDLEHEIGHT);
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
    // TODO
    GLabel label = newGLabel("");
    setFont(label, "SansSerif-40");
    setColor (label, "666699");
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
