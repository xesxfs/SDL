
#include "Game.h"
Game *g_game;
int main(int argc ,char *agrv[]){
    g_game =new Game();
    g_game->init("Chapter 1", 100, 100, 640, 480, 0);

    while(g_game->running()){
        g_game->handleEvents();
        g_game->update();
        g_game->render();
    }
    g_game->clean();
}
