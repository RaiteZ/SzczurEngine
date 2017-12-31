#include "Armature.hpp"

#include <dragonBones\SFMLFactory.h>
#include <dragonBones\SFMLArmatureDisplay.h>

namespace rat
{
	Armature::Armature(const std::string& name)
	{
		create(name);
	}

	void Armature::create(const std::string& name)
	{
		auto factory = dragonBones::SFMLFactory::get();

		if (!factory)
			return;

		std::string path = name.data();

		auto dbData = factory->loadDragonBonesData(path + "/skeleton.json");

		if (dbData == nullptr)
			return;

		auto texturesData = factory->getTexturesData(dbData, path + "/textures");

		for (auto& textureData : texturesData) {
			auto tex = new sf::Texture();
			tex->loadFromFile(textureData->path);
			textureData->setTexture(tex);
		}

		auto textureAtlasData = factory->createTextureAtlasData(texturesData, dbData);

		if (textureAtlasData == nullptr) {
			for (auto& textureData : texturesData) {
				if (textureData)
					delete textureData;
			}

			return;
		}

		_armatureDisplay = std::unique_ptr<dragonBones::SFMLArmatureDisplay>(factory->buildArmatureDisplay(name.data()));
	}

	void Armature::replaceSlotsTexture(const std::string& slotName, sf::Texture* texture)
	{
		if (!texture)
			return;

		if (!_armatureDisplay)
			return;

		auto slot = _armatureDisplay->getArmature()->getSlot(slotName.data());

		if (!slot)
			return;
	
		auto display = static_cast<dragonBones::SFMLDisplay*>(slot->getRawDisplay());

		if (display) 
			display->texture = texture;
		
	}

	void Armature::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		if (_armatureDisplay) {
			states.transform.scale({ _scale, _scale }, getPosition());
			target.draw(*_armatureDisplay, states);
		}
	}
}