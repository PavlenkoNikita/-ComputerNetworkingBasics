#pragma once
#include <iostream>
#include <vector>

#include "Subnet.h"

class Net 
{
public:
	Net();
	Net(const Ip& netIp, const uint8_t lengthMask, std::vector<uint32_t>& amountHostsInSubnets);
	~Net();
	friend std::ostream& operator<<(std::ostream& ost, const Net& obj);
private:
	Subnet* subnet;
	Mask mask;
	Ip ip;
	uint32_t nSubnet;
};

