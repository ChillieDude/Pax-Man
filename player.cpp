#include "Globals.h"

class timPlayer
{
public:
    timPlayer();
    ~timPlayer();

    bool LoadSheet(const std::string filename);
    void SetClipLocations();

    void Render();

    void SetCurrentClip();

private:
    timTexture theSpriteSheet;
    SDL_Rect clipLocations[STANCE_TOTAL];
    SDL_Rect currentLocation;
    timStanceFlag currentStance;
};

void timPlayer::SetCurrentClip()
{
    if(frame / 4 == 0)
    {
        currentStance = STANCE_UP_1;
    }
    else if(frame / 4 == 1)
    {
        currentStance = STANCE_UP_2;
    }
    else if(frame / 4 == 2)
    {
        currentStance = STANCE_UP_3;
    }
}
void timPlayer::SetClipLocations()
{
    int clipH = 100, clipW = 100;
    int x = 0, y = 0;
    for(int i = 0; i!= STANCE_TOTAL; ++i)
    {
        if(x == 3)
        {
            x = 0;
            ++y;
        }

        clipLocations[i].x = 100 * x;
        clipLocations[i].y = 100 * y;
        clipLocations[i].w = clipW;
        clipLocations[i].h = clipH;
        // x == 3
        ++x;
    }

    return;
}

void timPlayer::Render()
{
    theSpriteSheet.Render(&currentLocation, &clipLocations[currentStance]);
    return;
}

bool timPlayer::LoadSheet(const std::string filename)
{
    if( !theSpriteSheet.LoadImage(filename) )
    {
        std::cout << "Could not Load player Sheet!" <<std::endl;
        return false;
    }
    return true;
}

timPlayer::timPlayer()
{
    currentStance = STANCE_UP_1;
    currentLocation.x = 0;
    currentLocation.y = 0;
    currentLocation.h = 100;
    currentLocation.w = 100;


    theSpriteSheet.LoadImage("player.bmp");
    SetClipLocations();
}

timPlayer::~timPlayer()
{
    theSpriteSheet.Deallocate();
}
