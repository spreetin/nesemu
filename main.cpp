#include <SDL2/SDL.h>
#include "engine/graphics/screen.h"

using namespace std;

int main()
{
    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_GAMECONTROLLER|SDL_INIT_EVENTS);
    Screen screen;
    SDL_Quit();
    return 0;
}
