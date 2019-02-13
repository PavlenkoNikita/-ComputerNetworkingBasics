#pragma once
#include "Mask.h"

class Subnet
{
public:
	Subnet(uint8_t length, uint32_t N, const Ip& ip);
	Subnet();
	~Subnet();

	Ip findIp();
	Subnet& operator=(const uint32_t N);
	friend std::ostream& operator<<(std::ostream& ost, const Subnet& obj);
private:
	Mask mask;
	Ip minIp, maxIp, broadcastIp, ip;
	int N_hosts;
	void findMinIp(Ip ip);
	void findMaxIp(Ip ip);
	void findBroadcastIp(Ip ip);
	void changeMask();
};