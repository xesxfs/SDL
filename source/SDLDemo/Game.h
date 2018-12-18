
#ifndef __Game__
#define __Game__
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "TextureManager.h"
#include "Player.h"
#include "Enemy.h"
#include "GameObject.h"
#include  "SDLGameObject.h"
#include <iostream>
#include <vector>
class Game
{
public:
    static Game* Instance()
    {
        if(s_pInstance == 0)
        {
            s_pInstance = new Game();
            return s_pInstance;
        }
        return s_pInstance;
    }


//    GameObject* m_go;
//    GameObject* m_player;
//    GameObject* m_enemy;

    std::vector<GameObject*> m_gameObjects;
    bool init(const char* title, int xpos, int ypos, int width, int
              height, int flags);
    void render();
    void update();
    void handleEvents();
    void clean();
    SDL_Renderer* getRenderer() const
    {
        return m_pRenderer;
    }
    bool running()
    {
        return m_bRunning;
    }

private:
    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;
    bool m_bRunning;
    int m_currentFrame;
    Game(){};
    static Game* s_pInstance;

    typedef Game TheGame;
    //  TextureManager m_textureManager;
    //SDL_Texture* m_pTexture;
    //SDL_Rect m_srcRect;
    //SDL_Rect m_destRect;
};

#endif // __Game__
