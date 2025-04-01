#include <SFML/Graphics.hpp>
#include <time.h>
#include "TextureManager.h"
#include "Game.h"

int main()
{
    srand(time(0));

    TextureManager textureManager;
    textureManager.LoadTextures();

    Game game(textureManager, { 520, 450 });
    game.Run();
    
    return EXIT_SUCCESS;
}