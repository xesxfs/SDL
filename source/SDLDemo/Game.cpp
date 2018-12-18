
#include "Game.h"
Game* Game::s_pInstance = 0;

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags)
{
    if(SDL_Init(SDL_INIT_EVENTS) == 0)
    {
        m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if(m_pWindow != 0)
        {
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
            if(m_pRenderer != 0)
            {
                SDL_SetRenderDrawColor(m_pRenderer,
                                       255, 0, 0, 255);
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    TextureManager::Instance()->load("assets/animate-alpha.png",
                                     "animate", m_pRenderer);
//    m_go = new GameObject();
//    m_player = new Player();
//    m_go->load(100, 100, 128, 82, "animate");
//    m_player->load(300, 300, 128, 82, "animate");
//    m_gameObjects.push_back(m_go);
//    m_gameObjects.push_back(m_player);
//
//    m_enemy = new Enemy();
//    m_enemy->load(0, 0, 128, 82, "animate");
//    m_gameObjects.push_back(m_enemy);
//
//    m_gameObjects.push_back(new Player(new LoaderParams(100, 100, 128, 82,
//                                       "animate")));
    m_gameObjects.push_back(new SDLGameObject(new LoaderParams(300, 100, 128, 82,
                                      "animate")));

    //SDL_Surface *pTempSurface = SDL_LoadBMP("assets/animate.bmp");
    //SDL_Surface *pTempSurface = IMG_Load("assets/animate-alpha.png");
    //  m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer,
    //              pTempSurface);

    //  SDL_FreeSurface(pTempSurface);
    // SDL_QueryTexture(m_pTexture, NULL, NULL, &m_srcRect.w, &m_srcRect.h);
    //  m_srcRect.w = 128;
    // m_srcRect.h = 82;

    // m_srcRect.x = 0;
    //  m_srcRect.y = 0;
    // m_destRect.w = m_srcRect.w;
    // m_destRect.h = m_srcRect.h;
    // m_destRect.x = 0;
    //  m_destRect.y = 0;
    m_bRunning = true;
    return true;

}

void Game::render()
{
    SDL_RenderClear(m_pRenderer); // clear the renderer to the draw color

    for(std::vector<GameObject*>::size_type i = 0; i !=
            m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->draw();
        // m_enemy->draw(m_pRenderer);
    }
    //m_go.draw(m_pRenderer);
    //m_player.draw(m_pRenderer);
    //SDL_RenderCopy(m_pRenderer, m_pTexture, &m_srcRect, &m_destRect);
    //SDL_RenderCopy(m_pRenderer, m_pTexture, 0, 0);
    //SDL_RenderCopyEx(m_pRenderer, m_pTexture, &m_srcRect, &m_destRect,0,0,SDL_FLIP_NONE);
    //TextureManager::Instance()->draw("animate",0,0,128,82,m_pRenderer);
    //TextureManager::Instance()->drawFrame("animate",100,100,128,82,1,m_currentFrame,m_pRenderer);
    SDL_RenderPresent(m_pRenderer); // draw to the screen
}
void Game::update()
{
    //m_srcRect.x =128*int(((SDL_GetTicks()/100)%6));
    // m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
    //m_go.update();
    //m_player.update();
    for(std::vector<GameObject*>::size_type i = 0; i !=
            m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->update();
    }
    // m_enemy->update();
}

void Game::clean()
{
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}

void Game::handleEvents()
{
    SDL_Event event;
    if(SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            m_bRunning = false;
            break;
        default:
            break;
        }
    }
}
