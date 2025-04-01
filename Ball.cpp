#include "Ball.h"

Ball::Ball(sf::Sprite& sprite, sf::Vector2f position) :
	m_sprite(sprite), m_position(position) {
	m_delta = { 6, -5 };
}

void Ball::SetPosition(sf::Vector2f newPosition, sf::Vector2f newDelta) {
	this->m_position = newPosition;
	this->m_sprite.setPosition(newPosition);

	this->m_delta = newDelta;
}

sf::Vector2f Ball::GetPosition() const {
	return this->m_position;
}

sf::Vector2f Ball::GetDelta() const {
	return this->m_delta;
}

void Ball::SetX(float newX) {
	this->m_position.x = newX;
}

void Ball::SetY(float newY) {
	this->m_position.y = newY;
}

sf::Sprite& Ball::GetSprite() {
	return this->m_sprite;
}