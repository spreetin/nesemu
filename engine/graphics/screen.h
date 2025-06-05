#ifndef SCREEN_H
#define SCREEN_H

class SDL_Window;
class SDL_Renderer;
class TTF_Font;


#include "../../units.h"
#include <array>
#include <string>

union Scaling {
    int i;
    float f;
};

union color {
    uint32_t full;
    struct {
        uint8_t a : 8;
        uint8_t r : 8;
        uint8_t g : 8;
        uint8_t b : 8;
    };
};

class Screen
{
public:
    Screen(int xSize = 1152, int ySize = 1080); // 3x 256x240
    ~Screen();

    void show();
    void clear();

    void setResolution(int xSize, int ySize);
    void draw();
    void setPixel(int x, int y, uint8_t col, bool alpha = false);

    // Helpers
    void drawBox(int x, int y, int w, int h, int thickness, color c);
    void drawText(int x, int y, int size, std::string text);

    // Debug framework
    void drawExtras();
    void drawInfoText(char *pc, char *code, char *mnemonic, char *p, char *a, char* x, char *y, char *sp);

private:
    int xRes = -1;
    int yRes = -1;
    SDL_Window * window = nullptr;
    SDL_Renderer * renderer = nullptr;
    SDL_Texture * texture = nullptr;
    SDL_Texture * back_texture = nullptr;

    SDL_Rect main_rect = {0, 0, 768, 720};

    TTF_Font * sans_font;

    struct text_block {
        SDL_Texture *texture;
        SDL_Rect *rect;
    };

    std::array<color, 256*240> nextScreen;
    std::array<color, 384*360> backBox;

    std::array<text_block, 8> text_blocks;

    std::array<color, 0x40> palette = {{
//      0 / 8     1 / 9     2 / A     3 / B     4 / C     5 / D     6 / E     7 / F
        {0x5c5c5c}, {0x002267}, {0x131280}, {0x2e067e}, {0x460060}, {0x530231}, {0x510a02}, {0x411900}, // 00 - 07
        {0x282900}, {0x0d3700}, {0x003e00}, {0x003c0a}, {0x00313b}, {0x000000}, {0x000000}, {0x000000}, // 08 - 0F
        {0xa7a7a7}, {0x1e55b7}, {0x3f3dda}, {0x662bd6}, {0x8822ac}, {0x9a246b}, {0x983225}, {0x814700}, // 10 - 17
        {0x5d5f00}, {0x367300}, {0x187d00}, {0x097a32}, {0x0b6b79}, {0x000000}, {0x000000}, {0x000000}, // 18 - 1F
        {0xfeffff}, {0x6aa7ff}, {0x8f8dff}, {0xb979ff}, {0xdd6fff}, {0xf172be}, {0xee8173}, {0xd69837}, // 20 - 27
        {0xb0b218}, {0x86c71c}, {0x64d141}, {0x52ce81}, {0x54becd}, {0x454545}, {0x000000}, {0x000000}, // 28 - 2F
        {0xfeffff}, {0xc0daff}, {0xd0cfff}, {0xe2c6ff}, {0xf1c2ff}, {0xf9c3e4}, {0xf8cac4}, {0xeed4a9}, // 30 - 37
        {0xdedf9b}, {0xcce79d}, {0xbdecae}, {0xb5eaca}, {0xb6e4ea}, {0xb0b0b0}, {0x000000}, {0x000000}  // 38 - 3F
    }};
};

#endif // SCREEN_H
