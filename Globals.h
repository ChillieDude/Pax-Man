#ifndef GLOBALS_H_INCLUDED
#define GLOBALS_H_INCLUDED


#include<SDL.h>
#include<iostream>
#include<string>
//Declare enumerators
enum timStanceFlag
{
    STANCE_UP_1 = 0,
    STANCE_UP_2 = 1,
    STANCE_UP_3 = 2,
    STANCE_RIGHT_1 = 3,
    STANCE_RIGHT_2 = 4,
    STANCE_RIGHT_3 = 5,
    STANCE_DOWN_1 = 6,
    STANCE_DOWN_2 = 7,
    STANCE_DOWN_3 = 8,
    STANCE_LEFT_1 = 9,
    STANCE_LEFT_2 = 10,
    STANCE_LEFT_3 = 11,
    STANCE_TOTAL = 12
};

//Declare your classes:


class timTexture
{
public:
    timTexture();
    ~timTexture();

    void Deallocate();
    bool LoadImage(std::string filename);
    void Render( SDL_Rect* currentLocation, SDL_Rect* clipLocation);


    //Functions for calling height / width
    int GetHeight();
    int GetWidth();

private:
    SDL_Texture* theTexture;

    int tWidth;
    int tHeight;
};



//Declare your Functions here:
bool InitSDL();
void Play();
void Close();

//Declare Global Variables:
extern SDL_Window* theWindow ;
extern SDL_Renderer* theRenderer;
extern SDL_Surface* theSurface;

extern const int SCREEN_W;
extern const int SCREEN_H;

extern int frame;

#endif
