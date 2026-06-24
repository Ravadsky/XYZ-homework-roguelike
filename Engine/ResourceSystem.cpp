#include "pch.h"
#include "ResourceSystem.h"

ResourceSystem* ResourceSystem::Instance()
{
	static ResourceSystem resourceSystem;
	return &resourceSystem;
}

void ResourceSystem::LoadTexture(const std::string& name, std::string sourcePath, bool isSmooth)
{
	if (textures.find(name) != textures.end())
		return;

	sf::Texture* newTexture = new sf::Texture();
	if (newTexture->loadFromFile(sourcePath))
	{
		newTexture->setSmooth(isSmooth);
		textures.emplace(name, newTexture);
	}
}

const sf::Texture* ResourceSystem::GetTextureShared(const std::string& name) const
{
	return textures.find(name)->second;
}

sf::Texture* ResourceSystem::GetTextureCopy(const std::string& name) const
{
	return new sf::Texture(*textures.find(name)->second);
}

void ResourceSystem::DeleteSharedTexture(const std::string& name)
{
	auto texturePair = textures.find(name);

	sf::Texture* deletingTexture = texturePair->second;
	textures.erase(texturePair);
	delete deletingTexture;
}

void ResourceSystem::LoadTextureMap(const std::string& name, std::string& sourcePath, sf::Vector2u elementPixelSize, int totalElements, bool isSmooth)
{
	if (textureMaps.find(name) != textureMaps.end())
		return;

	sf::Texture TextureMap;
	if (TextureMap.loadFromFile(sourcePath))
	{
		auto TextureMapElements = new std::vector<sf::Texture*>();

		auto TextureSize = TextureMap.getSize();
		int loadedElements = 0;

		for (int y = 0; y <= (int)TextureSize.y - (int)elementPixelSize.y; y += elementPixelSize.y)
		{
			if (loadedElements == totalElements)
				break;

			for (int x = 0; x <= (int)TextureSize.x - (int)elementPixelSize.x; x += elementPixelSize.x)
			{
				if (loadedElements == totalElements)
					break;

				sf::Texture* newTextureMapElement = new sf::Texture();
				if (newTextureMapElement->loadFromFile(sourcePath, sf::IntRect(x, y, elementPixelSize.x, elementPixelSize.y)))
				{
					newTextureMapElement->setSmooth(isSmooth);
					TextureMapElements->push_back(newTextureMapElement);
				}
				loadedElements++;
			}
		}

		textureMaps.emplace(name, *TextureMapElements);

	}
}

const sf::Texture* ResourceSystem::GetTextureMapElementShared(const std::string& name, int elementIndex) const
{
	auto textureMap = textureMaps.find(name);
	auto textures = textureMap->second;

	return textures[elementIndex];
}

sf::Texture* ResourceSystem::GetTextureMapElementCopy(const std::string& name, int elementIndex) const
{
	auto textureMap = textureMaps.find(name);
	auto textures = textureMap->second;

	return new sf::Texture(*textures[elementIndex]);
}

int ResourceSystem::GetTextureMapElementsCount(const std::string& name) const
{
	auto textureMap = textureMaps.find(name);
	auto textures = textureMap->second;
	return (int)textures.size();
}

void ResourceSystem::DeleteSharedTextureMap(const std::string& name)
{
	auto textureMap = textureMaps.find(name);
	auto deletingTextures = textureMap->second;

	for (int i = 0; i < deletingTextures.size(); i++)
	{
		delete deletingTextures[i];
	}
	textureMaps.erase(textureMap);
}

void ResourceSystem::Clear()
{
	DeleteAllTextures();
	DeleteAllTextureMaps();
}

void ResourceSystem::DeleteAllTextures()
{
	std::vector<std::string> keysToDelete;
	for (const auto& TexturePair : textures)
	{
		keysToDelete.push_back(TexturePair.first);
	}
	for (const auto& key : keysToDelete)
	{
		DeleteSharedTexture(key);
	}
}

void ResourceSystem::DeleteAllTextureMaps()
{
	std::vector<std::string> keysToDelete;
	for (const auto& TextureMapPair : textureMaps)
	{
		keysToDelete.push_back(TextureMapPair.first);
	}
	for (const auto& key : keysToDelete)
	{
		DeleteSharedTexture(key);
	}
}
