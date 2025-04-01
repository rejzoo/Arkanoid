#pragma once
#include <SFML/Graphics/Sprite.hpp>

class Paddle
{
private:
	sf::Sprite m_sprite;

public:
	Paddle(sf::Sprite& sprite);
	sf::Vector2f GetPosition();
	void SetPosition(sf::Vector2f newPosition);
	const sf::Texture& GetTexture() const;
	void Move(sf::Vector2f offset);
	sf::FloatRect GetGlobalBounds();
	sf::Sprite GetSprite();
};

