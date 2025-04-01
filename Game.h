#pragma once
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "TextureManager.h"
#include "Ball.h"
#include "Block.h"
#include "Paddle.h"

class Game
{
private:
	TextureManager& m_textureManager;
	sf::RenderWindow m_window;

	unsigned int m_width;
	unsigned int m_height;
	size_t m_blockCount = 100;

	Paddle m_paddle;
	std::vector<Ball> m_balls;
	std::vector<Block> m_blocks;

public:
	Game(TextureManager& textureManager, sf::Vector2u windowSize);
	void Run();

private:
	void InitGame();
	void SetTextures();
	void HandleInput();
	void Update();
	void Render();
};

