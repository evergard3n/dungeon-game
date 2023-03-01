#include "game.h"
#include "TextureManager.h"
#include "GameObject.h"

GameObject* player;
GameObject* enemy;

SDL_Renderer* Game::renderer = nullptr;

SDL_Texture* playerTex;
SDL_Rect scrR, dstR;
Game::Game() {

}
Game::~Game(){}
void Game::init(const char* title, int xpos, int ypos, int w, int h, bool fullscreen) {
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		
		window = SDL_CreateWindow(title, xpos, ypos, w, h, flags);
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created!" << std::endl;
		}
		isRunning = true;
		
	}
	
	player = new GameObject("textures/player2.png", 0, 0);
	enemy = new GameObject("textures/player.png", 50, 50);
}
void Game::handleEvents()
{
	SDL_Event e;
	SDL_PollEvent(&e);
	switch (e.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::update()
{
	player->Update();
	enemy->Update();
}
void Game::render()
{
	SDL_RenderClear(renderer);
	player->Render();
	enemy->Render();
	SDL_RenderPresent(renderer);

}
void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();


}
