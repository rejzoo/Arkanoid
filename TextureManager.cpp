#include "TextureManager.h"
#include <iostream>

void TextureManager::LoadTextures()
{
	for (const auto& [key, paths] : m_texturePaths)
	{
		std::vector<sf::Texture> loaded;

		loaded.reserve(paths.size());

		for (const auto& path : paths) {
			sf::Texture texture;

			if (texture.loadFromFile(path)) {
				loaded.push_back(std::move(texture));
				std::cout << "Loaded texture: " << path << std::endl;
			}
			else {
				std::cerr << "Error loading texture: " << path << std::endl;
			}
		}

		m_textures[key] = std::move(loaded);
	}
}

const sf::Texture& TextureManager::GetTexture(const std::string& key, size_t index) const
{
	return this->m_textures.at(key).at(index);
}

std::vector<sf::Texture>& TextureManager::GetTextures(const std::string& key) 
{
	return this->m_textures.at(key);
}
