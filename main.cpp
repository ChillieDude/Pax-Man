#include "Globals.h"

bool InitSDL();
void Close();

SDL_Window* theWindow  = NULL;
SDL_Renderer* theRenderer = NULL;
SDL_Surface* theSurface = NULL;

const int SCREEN_W = 720;
const int SCREEN_H = 480;

int main(int argc, char* args[])
{
    if(!InitSDL())
    {
        std::cout << "SDL cant Init =[ : " << SDL_GetError() << std::endl;
        return -1;
    }
    else
    {
        Play();
    }

    Close();
    //Place the SDL_Close Function here before the return;
    return 0;
}

