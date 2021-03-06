#include "AssetTraits.hpp"

#include <fstream>
#include <streambuf>

#include <SFML/System/MemoryInputStream.hpp>

// @todo createFallback functions

namespace rat
{

sf::Font* AssetTraits<sf::Font>::create()
{
	return new sf::Font;
}

sf::Font* AssetTraits<sf::Font>::createFallback()
{
	return new sf::Font;
}

bool AssetTraits<sf::Font>::load(sf::Font& font, const std::string& path)
{
	return font.loadFromFile(path);
}

void AssetTraits<sf::Font>::unload(sf::Font&)
{
	// Nothing to do here, destructor will take care of freeing resource
}

const char* AssetTraits<sf::Font>::getName()
{
	return "sf::Font";
}

sf::Texture* AssetTraits<sf::Texture>::create()
{
	return new sf::Texture;
}

sf::Texture* AssetTraits<sf::Texture>::createFallback()
{
	sf::Texture* tmp = new sf::Texture;

	sf::Image img; img.create(16, 16, sf::Color::Magenta);

	tmp->loadFromImage(img);
	tmp->setRepeated(true);

	return tmp;
}

bool AssetTraits<sf::Texture>::load(sf::Texture& texture, const std::string& path)
{
	return texture.loadFromFile(path);
}

void AssetTraits<sf::Texture>::unload(sf::Texture&)
{
	// Nothing to do here, destructor will take care of freeing resource
}

const char* AssetTraits<sf::Texture>::getName()
{
	return "sf::Texture";
}

sf::Shader* AssetTraits<sf::Shader>::create()
{
	return new sf::Shader;
}

sf::Shader* AssetTraits<sf::Shader>::createFallback()
{
	return new sf::Shader;
}

bool AssetTraits<sf::Shader>::load(sf::Shader& shader, const std::string& path)
{
	std::ifstream file(path);

	if (!file.good())
		return false;

	std::string buffer;

	file.seekg(0, std::ios::end);
	buffer.reserve(file.tellg());
	file.seekg(0, std::ios::beg);

	buffer.assign(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());

	sf::MemoryInputStream streams[3];

	auto it1 = std::begin(buffer);
	auto it2 = std::find(it1, std::end(buffer), '$');
	streams[0].open(&*it1, std::distance(it1, it2));

	it1 = std::next(it2);
	it2 = std::find(it1, std::end(buffer), '$');
	streams[1].open(&*it1, std::distance(it1, it2));

	it1 = std::next(it2);
	it2 = std::find(it1, std::end(buffer), '$');
	streams[2].open(&*it1, std::distance(it1, it2));

	return shader.loadFromStream(streams[0], streams[1], streams[2]);
}

void AssetTraits<sf::Shader>::unload(sf::Shader&)
{
	// Nothing to do here, destructor will take care of freeing resource
}

const char* AssetTraits<sf::Shader>::getName()
{
	return "sf::Shader";
}

sf::Music* AssetTraits<sf::Music>::create()
{
	return new sf::Music;
}

sf::Music* AssetTraits<sf::Music>::createFallback()
{
	return new sf::Music;
}

bool AssetTraits<sf::Music>::load(sf::Music& music, const std::string& path)
{
	return music.openFromFile(path);
}

void AssetTraits<sf::Music>::unload(sf::Music&)
{
	// Nothing to do here, destructor will take care of freeing resource
}

const char* AssetTraits<sf::Music>::getName()
{
	return "sf::Music";
}

sf::SoundBuffer* AssetTraits<sf::SoundBuffer>::create()
{
	return new sf::SoundBuffer;
}

sf::SoundBuffer* AssetTraits<sf::SoundBuffer>::createFallback()
{
	return new sf::SoundBuffer;
}

bool AssetTraits<sf::SoundBuffer>::load(sf::SoundBuffer& soundBuffer, const std::string& path)
{
	return soundBuffer.loadFromFile(path);
}

void AssetTraits<sf::SoundBuffer>::unload(sf::SoundBuffer&)
{
	// Nothing to do here, destructor will take care of freeing resource
}

const char* AssetTraits<sf::SoundBuffer>::getName()
{
	return "sf::SoundBuffer";
}

}
