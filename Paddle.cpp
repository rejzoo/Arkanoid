#include "Paddle.h"

Paddle::Paddle(sf::Sprite& sprite) : m_sprite(sprite)
{
}

sf::Vector2f Paddle::GetPosition()
{
	return this->m_sprite.getPosition();
}

void Paddle::SetPosition(sf::Vector2f newPosition)
{
	this->m_sprite.setPosition(newPosition);
}

const sf::Texture& Paddle::GetTexture() const 
{
	return this->m_sprite.getTexture();
}

void Paddle::Move(sf::Vector2f offset)
{
	this->m_sprite.move(offset);
}

sf::FloatRect Paddle::GetGlobalBounds()
{
	return this->m_sprite.getGlobalBounds();
}

sf::Sprite Paddle::GetSprite()
{
	return this->m_sprite;
}
