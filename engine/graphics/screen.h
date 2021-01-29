#ifndef SCREEN_H
#define SCREEN_H

class SDL_Window;
class SDL_Renderer;

union Scaling {
    int i;
    float f;
};

class Screen
{
public:
    Screen(int xSize = 968, int ySize = 717); // 3x 256x239
    ~Screen();

    void show();

    void setResolution(int xSize, int ySize);
    void setScalingI(int scaling);
    void setScalingF(float scaling);
    void draw();
    void setPixel(int x, int y, char color);

private:
    int xRes = -1;
    int yRes = -1;
    Scaling scale = {3};
    bool intScaling = true;
    SDL_Window * window = nullptr;
    SDL_Renderer *renderer = nullptr;
};

#endif // SCREEN_H
