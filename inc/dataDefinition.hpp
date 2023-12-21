#ifndef DATADEFINITION_HPP
#define DATADEFINITION_HPP
//Building constant
#define DEFAULT_X_SIZE 1
#define DEFAULT_Y_SIZE 1

//SmallHouse constants
#define SH_X_SIZE 4
#define SH_Y_SIZE 2
#define SH_MAX_RESIDENTS 2

enum tiles
{
    g,
    w,
    d,
    b,
    c
};

enum emotion
{
    fine,
    happy, 
    love, 
    relief, 
    contentment, 
    amusement, 
    joy, 
    pride, 
    excitement, 
    peace, 
    satisfaction, 
    loneliness, 
    heartbreak, 
    gloom, 
    disappointment, 
    hopelessness, 
    grief, 
    unhappiness, 
    loss, 
    trouble, 
    resignation, 
    misery, 
    fear, 
    anger, 
    disgust, 
    surprise, 
    trust
};

enum gender
{
male,
female
};

#endif