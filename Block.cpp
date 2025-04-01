#include "Block.h"

Block::Block(sf::Sprite& sprite) : m_sprite(sprite) {
	if ((std::rand() % 100) < 96)
	{
		this->m_type = BlockType::NORMAL;
	}
	else
	{
		this->m_type = BlockType::SPAWN_BALL;
	}
}

sf::Sprite& Block::GetSprite() {
	return this->m_sprite;
}

BlockType Block::GetType() const {
	return this->m_type;
}

sf::Vector2f Block::GetPosition() {
	return this->m_sprite.getPosition();
}

void Block::SetPosition(sf::Vector2f position) {
	this->m_sprite.setPosition(position);
}

void Block::SetTexture(std::vector<sf::Texture>& textures) {
	switch (m_type)
	{
	case BlockType::NORMAL:
		this->m_sprite.setTexture(textures.at(0));
		break;
	case BlockType::SPAWN_BALL:
		this->m_sprite.setTexture(textures.at(1));
		break;
	default:
		break;
	}
}