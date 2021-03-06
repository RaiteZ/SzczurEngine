#include "InputCode.hpp"

namespace rat
{

InputCode::InputCode() :
	_data(0)
{

}

InputCode::InputCode(Keyboard::Code code) :
	_data(InputDevice_t::Keyboard | code)
{

}

InputCode::InputCode(Mouse::Code code) :
	_data(InputDevice_t::Mouse | code)
{

}

InputCode::InputCode(Scroll::Code code) :
	_data(InputDevice_t::Scroll | code)
{

}

InputCode::InputCode(int data) :
	_data(data)
{

}

InputDevice_t InputCode::getType() const
{
	return static_cast<InputDevice_t>(_data & 0xFF0000);
}

int InputCode::getID() const
{
	return _data & 0xFFFF;
}

InputCode::operator int () const
{
	return getID();
}

int InputCode::getData() const
{
	return _data;
}

bool InputCode::isValid() const
{
	return getData() != 0;
}

}
