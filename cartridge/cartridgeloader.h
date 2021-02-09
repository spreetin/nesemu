#ifndef CARTRIDGELOADER_H
#define CARTRIDGELOADER_H

#include "cartridge.h"
#include <string>

class CartridgeLoader
{
public:
    CartridgeLoader();

    Cartridge *loadFile(std::string filename);
};

#endif // CARTRIDGELOADER_H
