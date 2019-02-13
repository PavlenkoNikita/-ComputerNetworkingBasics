#include "Ip.h"

Ip::Ip()
{
	for (int i = 0; i < 4; i++)
	{
		this->octet[i] = 0;
	}
}

Ip::Ip(const uint8_t oct[])
{
	for (size_t i = 0; i < 4; i++)
	{
		this->octet[i] = oct[i];
	}
}

Ip::~Ip()
{
}

uint8_t Ip::operator[](const uint8_t index) const
{
	return this->octet[index];
}

Ip Ip::operator+(int number)
{
	for (size_t i = 3; i >= 0; i--)
	{
		if (number >= 256)
		{
			number /= 256;
		}
		else
		{
			this->octet[i] += number;
			//Если в результате суммирования получаем 0 значт следующий октет увеличиваем на 1
			if (this->octet[i] == 0)
			{
				this->octet[i - 1] += 1;
			}
			break;
		}
	}
	//this->octet[3] += number;
	return *this;
}


Ip Ip::operator-(const int number)
{
	if (this->octet[3] == 0)
	{
		this->octet[2] -= 1;
	}
	this->octet[3] -= number;
	
	return *this;
}

Ip& Ip::operator=(const Ip & obj)
{
	for (size_t i = 0; i < 4; i++)
	{
		this->octet[i] = obj.octet[i];
	}
	return *this;
}

std::istream& operator>>(std::istream& ist, Ip& obj)
{
	int number[4];
	bool isIp = false;
	while (!isIp)
	{
		for (int i = 0; i < 4; i++)
		{
			ist >> number[i];
			if (number[0] < 0 && number[0] > 255)
			{
				std::cout << "Invalid values ​​for IP address!!! Repeat input.\n";
				break;
			}
			if (i == 3)
			{
				isIp = true;
			}
			else if(ist.get() != '.')
			{
				std::cout << "Invalid IP address entry!!! Repeat input.\n";
			}
		}
	}
	for (int i = 0; i < 4; i++)
	{
		obj.octet[i] = number[i];
	}
	return ist;
}

std::ostream& operator<<(std::ostream& ost, const Ip& obj)
{
	ost << '(' << static_cast<int>(obj[0]) << '.' << static_cast<int>(obj[1]) << '.' << static_cast<int>(obj[2]) << '.' << static_cast<int>(obj[3]) << ')';
	return ost;
}