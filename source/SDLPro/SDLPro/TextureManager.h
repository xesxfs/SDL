#ifndef __TextureManager__
#define __TextureManager__
#include "SDL.h"
#include "SDL_image.h"
#include<iostream>
#include<string>
#include<map>
class TextureManager
{
public:
	~TextureManager() {}
	bool load(std::string fileName, std::string id, SDL_Renderer* pRenderer);
	void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void drawTile(std::string id, int margin, int spacing, int x, int y, int width, int height, int currentRow,int currentFrame, SDL_Renderer *pRenderer);
	static TextureManager* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new TextureManager();
			return s_pInstance;
		}
		return s_pInstance;
	}

	void TextureManager::clearFromTextureMap(std::string id)
	{
		m_textureMap.erase(id);
	}

private:
	std::map<std::string, SDL_Texture*> m_textureMap;
	TextureManager() {}
	static TextureManager*  s_pInstance;	
	
};

typedef TextureManager TheTextureManager;

#endif

