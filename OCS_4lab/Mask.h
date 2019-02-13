#pragma once
#include "Ip.h"
class Mask :
	private Ip
{
public:
	Mask();
	Mask(const uint8_t length);
	~Mask();
	Mask operator=(const Mask& obj);
	friend std::ostream& operator<<(std::ostream& ost, const Mask obj);
private:
	uint8_t lengthMask;
};

