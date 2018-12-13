
#ifndef __Game__
#define __Game__
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "TextureManager.h"
class Game
{
public:
    Game() {}
    ~Game() {}
    bool init(const char* title, int xpos, int ypos, int width, int
              height, int flags);
    void render();
    void update();
    void handleEvents();
    void clean();
    bool running()
    {
        return m_bRunning;
    }

private:
    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;
    bool m_bRunning;

    SDL_Texture* m_pTexture;
    SDL_Rect m_srcRect;
    SDL_Rect m_destRect;
};

#endif // __Game__
