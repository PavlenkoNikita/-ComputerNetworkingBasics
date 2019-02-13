#pragma once
#include <iostream>
#include <fstream>

class Ip
{
public:
	Ip();
	Ip(const uint8_t oct[]);
	~Ip();

	uint8_t operator[](const uint8_t index) const;
	Ip operator+(int number);
	Ip operator-(const int number);
	Ip& operator=(const Ip& obj);
	friend std::istream& operator>>(std::istream& ist, Ip& obj);
	friend std::ostream& operator<<(std::ostream& ost, const Ip& obj);

protected:
	uint8_t octet[4];
};