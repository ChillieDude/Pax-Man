#include "Globals.h"

int timTexture::GetHeight()
{
    return tHeight;
}

int timTexture::GetWidth()
{
    return tWidth;
}

void timTexture::Render(SDL_Rect* currentLocation, SDL_Rect* clipLocation)
{
    //We pass two Rects to this function
    //target is the Rectangle on the screen that you will occupy
    //clip is the rectangle that you select a sprite from the sprite sheet
    SDL_RenderCopy(theRenderer, theTexture, clipLocation, currentLocation);
}

timTexture::timTexture()
{
    theTexture = NULL;
    tHeight = 0;
    tWidth = 0;
}

timTexture::~timTexture()
{
    Deallocate();
}

void timTexture::Deallocate()
{
    if(theTexture != NULL)
    {
        SDL_DestroyTexture(theTexture);
        theTexture = NULL;
        tHeight = 0;
        tWidth = 0;
    }

}

bool timTexture::LoadImage(std::string filename)
{
    //This function uses the surface to load an image, then create a texture out of it

    Deallocate();

    //Create a "Guinna Pig" texture
    SDL_Texture* thePig = NULL;

    //Load a BMP into theSurface. BMP Is the only file type that native SDL2 can import. W(e will have to add SDL2_image to import other formats)
    theSurface = SDL_LoadBMP(filename.c_str()); //SDL_LoadBMP expects a ( char[] )

    //Debug VV
    if(theSurface == NULL)
    {
        std::cout << "Could not Load image! : " << SDL_GetError() <<std::endl;
    }
    else
    {
        //theTexture = SDL_CreateTextureFromSurface(theRenderer, theSurface);
        thePig = SDL_CreateTextureFromSurface(theRenderer, theSurface);

        //Debug VV
        if(thePig == NULL)
        {
            std::cout << "Could not create texture! : " << SDL_GetError() <<std::endl;
        }
        //Set the height and width. -> ->(Remember that theSurface is a pointer)
        tWidth = theSurface->w;
        tHeight = theSurface->h;
        //We are going to recycle our global "Surface"
        SDL_FreeSurface(theSurface);
        theSurface = NULL;
    }


    //Here is where we copy thePig into sTexture: If anything went wrong, thePig would have been NULL
    theTexture = thePig;
    return theTexture != NULL;
}
