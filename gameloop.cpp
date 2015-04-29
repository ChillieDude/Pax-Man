#include "Globals.h"

SDL_Rect currentSpace;
int frame = 0;
void Play()
{
    currentSpace.x = 0;
    currentSpace.y = 0;
    currentSpace.w = SCREEN_W;
    currentSpace.h = SCREEN_H;
  bool quit = false;
  SDL_Event e;
  while(quit == false)
  {

    while(SDL_PollEvent(&e) !=0 )
    {
      //This is where we repond to events
      if(e.type == SDL_QUIT)
      {
        quit = true;
      }

       //This is where we STOP reponding to events
    }
    SDL_SetRenderDrawColor(theRenderer, 0, 0, 0, 255);
    SDL_RenderClear(theRenderer);

    //Draw the Character HERE!

    SDL_RenderPresent(theRenderer);




  }
}
