#pragma once
#include<iostream>
#include<vector>
#include "Layer.h"
#include "Tileset.h"
class Level
{
public:
	Level();
	~Level();

	void update();
	void render();

	 std::vector<Tileset>*  getTilesets ()
	{
		return &m_tilesets;
	}

	std::vector<Layer*>* getLayers()
	{
		return &m_layers;
	}
private:
	friend class LevelParser;

	std::vector<Tileset> m_tilesets;
	std::vector<Layer*> m_layers;
};

