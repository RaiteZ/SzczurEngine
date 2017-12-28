#include "MusicBase.hpp"

#include <Szczur/Json.hpp>

#include <fstream>
#include <cmath>

namespace rat
{ 

	bool MusicBase::init(const std::string& fileName, float volume) 
	{
		if (!loadMusic(fileName))
			return false;
		_timeLeft = _base.getDuration().asSeconds();
		getJsonData(fileName);
		setVolume(volume);
		_postTime = std::fmod(_timeLeft, (_bpm * 4 / 60)); 
		return true;
	};

	void MusicBase::update(float deltaTime) 
	{
		if (getStatus() != sf::SoundSource::Status::Paused) {
			_timeLeft -= deltaTime;
			if (_timeLeft <= _postTime)
				_isEnding = true;
		}
	}

	bool MusicBase::isEnding() 
	{
		return _isEnding;
	}

	bool MusicBase::finish(float deltaTime) 
	{
		_isEnding = false;
		_timeLeft -= deltaTime;
		if (_timeLeft > 0) {
			float volume = (_timeLeft / _postTime) * _baseVolume;
			_base.setVolume(volume);
			return false;
		}
		reset();
		stop();
		return true;
	}

	void MusicBase::start(float deltaTime, float preTime) 
	{
		update(deltaTime);
		float volume = (_baseVolume * (getDuration() - _timeLeft)) / preTime;
		_base.setVolume(volume);
	}

	bool MusicBase::loadMusic(const std::string& fileName) 
	{
		return _base.openFromFile(getPath(fileName));
	}

	void MusicBase::getJsonData(const std::string& fileName) 
	{
		Json json;
		std::ifstream file("res/Music/Music.json");
		if(file.is_open()){
            file >> json;
			file.close();
		}
		_bpm = json[fileName]["BPM"];
	}

	void MusicBase::play() 
	{
		_base.play();
	}

	void MusicBase::pause() 
	{
		_base.pause();
	}

	void MusicBase::stop() 
	{
		_base.stop();
	}

	sf::SoundSource::Status MusicBase::getStatus() const 
	{
		return _base.getStatus();
	}

	float MusicBase::getPostTime() const 
	{
		return _postTime;
	}

	float MusicBase::getDuration() const 
	{
		return _base.getDuration().asSeconds();
	}

	float MusicBase::getVolume() const 
	{
		return _baseVolume;
	}

	void MusicBase::setVolume(float volume) 
	{
		_baseVolume = volume;
		_base.setVolume(volume);
	}

	inline std::string MusicBase::getPath(const std::string& fileName) const 
	{
		return "res/Music/" + fileName + ".flac"; 
	}

	void MusicBase::reset() 
	{
		_timeLeft = _base.getDuration().asSeconds();
		_base.setVolume(_baseVolume);
	}

}