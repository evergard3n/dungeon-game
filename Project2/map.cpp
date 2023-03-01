#include "map.h"
#include "TextureManager.h"

Map::Map()
{
	dirt = TextureManager::LoadTexture("textures/dirt bg.jpg");
	grass = TextureManager::LoadTexture("textures/grassblock.png");

}
void Map::LoadMap()
{}
void Map::DrawMap()
{}