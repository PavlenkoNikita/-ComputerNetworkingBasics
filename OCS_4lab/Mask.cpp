#include "Mask.h"

Mask::Mask()
{
	this->lengthMask = 0;
}

Mask::Mask(const uint8_t length)
{
	this->lengthMask = length;
	//Перевод маски в десятичный вид
	int count = length, sum;
	for (size_t i = 0; i < 4; i++)
	{
		sum = 0;
		if (count == 0)
		{
			break;
		}
		for (short j = 7; j >= 0; j--)
		{
			sum += pow(2, j);
			count--;
			if (count == 0)
			{
				break;
			}
		}
		this->octet[i] = sum;
	}
}

Mask::~Mask()
{
}

Mask Mask::operator=(const Mask & obj)
{
	this->lengthMask = obj.lengthMask;
	for (size_t i = 0; i < 4; i++)
	{
		this->octet[i] = obj.octet[i];
	}
	return *this;
}

std::ostream& operator<<(std::ostream& ost, const Mask obj)
{
	ost << static_cast<int>(obj.lengthMask) << " (" << static_cast<int>(obj[0]) << '.' << static_cast<int>(obj[1]) << '.' << static_cast<int>(obj[2]) << '.' << static_cast<int>(obj[3]) << ')';
	return ost;
}