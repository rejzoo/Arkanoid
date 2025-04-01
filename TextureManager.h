#pragma once

#include <unordered_map>
#include <SFML/Graphics.hpp>
#include <string>

class TextureManager
{
private:
	std::unordered_map<std::string, std::vector<sf::Texture>> m_textures;

public:
	void LoadTextures();
	const sf::Texture& GetTexture(const std::string& key, size_t index = 0) const;
	std::vector<sf::Texture>& GetTextures(const std::string& key);

private:
	const std::unordered_map<std::string, std::vector<std::string>> m_texturePaths = {
	{ "block",      { "images/block01.png", "images/block02.png" } },
	{ "background", { "images/background.jpg" } },
	{ "ball",       { "images/ball.png" } },
	{ "paddle",     { "images/paddle.png" } }
	};
};