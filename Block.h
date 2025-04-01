#pragma once

#include <SFML/Graphics.hpp>

enum BlockType {
	NORMAL,
	SPAWN_BALL,
	SLOW_BALL
};

class Block {
private:
	sf::Sprite m_sprite;
	BlockType m_type;

public:
	Block(sf::Sprite& sprite);
	sf::Sprite& GetSprite();
	BlockType GetType() const;
	sf::Vector2f GetPosition();
	void SetPosition(sf::Vector2f position);
	void SetTexture(std::vector<sf::Texture>& textures);
};