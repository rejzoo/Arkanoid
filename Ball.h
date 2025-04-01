#pragma once

#include <SFML/Graphics/Sprite.hpp>

class Ball {
private:
	sf::Vector2f m_position;
	sf::Vector2f m_delta;
	sf::Sprite m_sprite;

public:
	Ball(sf::Sprite& sprite, sf::Vector2f position);
	void SetPosition(sf::Vector2f newPosition, sf::Vector2f newDelta);
	sf::Vector2f GetPosition() const;
	sf::Vector2f GetDelta() const;
	void SetX(float newX);
	void SetY(float newY);
	sf::Sprite& GetSprite();
};