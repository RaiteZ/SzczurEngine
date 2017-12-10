#pragma once

#include <memory>

#include <dragonBones/SFMLArmatureDisplay.h>

#include <SFML\Graphics\Drawable.hpp>

namespace rat
{
	class Armature : public sf::Drawable 
	{
	private:
		std::unique_ptr<dragonBones::SFMLArmatureDisplay> _armatureDisplay;

		float _scale = 1.f;

	public:
		Armature() = default;
		Armature(std::string_view name);
		~Armature() = default;

		void create(std::string_view name);

		void setPosition(const sf::Vector2f& pos) { _armatureDisplay->setPosition(pos); }
		auto& getPosition() const { return _armatureDisplay->getPosition(); }

		void setScale(float scale) { _scale = scale; }
		float getScale() const { return _scale; }

		void setFlipX(bool value) { _armatureDisplay->getArmature()->setFlipX(value); }
		bool getFlipX() const { return _armatureDisplay->getArmature()->getFlipX(); }

		void setFlipY(bool value) { _armatureDisplay->getArmature()->setFlipY(value); }
		bool getFlipY() const { return _armatureDisplay->getArmature()->getFlipY(); }

		void playAnimation(std::string_view animation) { _armatureDisplay->getAnimation()->play(animation.data()); }
		void stopAnimation(std::string_view animation) { _armatureDisplay->getAnimation()->stop(animation.data()); }
		void fadeInAnimation(std::string_view animationName, float fadeInTime = -1.f, int playTimes = -1, int layer = 0, 
							 const std::string& group = "", dragonBones::AnimationFadeOutMode fadeOutMode = dragonBones::AnimationFadeOutMode::SameLayerAndGroup) 
		{ 
			_armatureDisplay->getAnimation()->fadeIn(animationName.data(), fadeInTime, playTimes, layer, group, fadeOutMode); 
		}

		void addEvent(const std::string& type, const std::function<void(dragonBones::EventObject*)>& listener) { _armatureDisplay->addDBEventListener(type, listener); }

		void replaceSlotsTexture(std::string_view slotName, sf::Texture* texture);

	protected:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	};
}
