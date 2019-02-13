#include "Net.h"

Net::Net()
{
	this->nSubnet = 0;
	this->subnet = new Subnet[this->nSubnet];
	uint8_t adress[4] = { 0, 0, 0, 0 };
	this->ip = Ip(adress);
}

Net::Net(const Ip& netIp, const uint8_t lengthMask, std::vector<uint32_t>& amountHosts)
{
	this->nSubnet = amountHosts.size();
	this->ip = netIp;
	this->mask = Mask(lengthMask);
	//Создаем массив подсетей
	this->subnet = new Subnet[this->nSubnet];	
	//Временная переменная для адресов подсетей
	Ip tempIp = netIp;
	for (int i = this->nSubnet - 1; i >= 0; i--)
	{
		this->subnet[i] = Subnet(lengthMask, amountHosts[i], tempIp);
		tempIp = subnet[i].findIp();
	}
}

Net::~Net()
{
	delete[] subnet;
}

std::ostream & operator<<(std::ostream & ost, const Net & obj)
{
	for (size_t i = 0; i < obj.nSubnet; i++)
	{
		ost << "\t" << i + 1 << "- subnet\n";
		ost << obj.subnet[obj.nSubnet - i - 1] << std::endl;
	}
	return ost;
}