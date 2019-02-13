#include "Subnet.h"

Subnet::Subnet()
{
	this->N_hosts = 0;
	this->mask = Mask(0);
}

Subnet::Subnet(uint8_t length, uint32_t N, const Ip& ip)
{
	this->N_hosts = N;
	this->mask = Mask(length);
	this->ip = ip;
}

Subnet::~Subnet()
{
}

Ip Subnet::findIp()
{
	Ip tempIp = this->ip;
	//Находим минимальный IP-адрес хост
	findMinIp(tempIp);
	tempIp = tempIp + this->N_hosts;
	//Находим широковещательный IP-адрес
	findBroadcastIp(tempIp);
	//Находим максимальный IP-адрес хост
	findMaxIp(tempIp);
	//Изменяем маску
	changeMask();
	//Отнимаем 2 т.к. широковещательный и адрес сети не считаем хостами
	this->N_hosts -= 2;
	return tempIp;
}

Subnet & Subnet::operator=(const uint32_t N)
{
	this->N_hosts = N;
	return *this;
}

void Subnet::findMinIp(Ip ip)
{
	this->minIp = ip + 1;
}

void Subnet::findMaxIp(Ip ip)
{
	this->maxIp = ip - 2;
}

void Subnet::findBroadcastIp(Ip ip)
{
	this->broadcastIp = ip - 1;
}

void Subnet::changeMask()
{
	for (uint8_t i = 0; i < 32; i++)
	{
		if (pow(2, i) == this->N_hosts)
		{
			this->mask = Mask(32 - i);
			break;
		}
	}
}

std::ostream & operator<<(std::ostream & ost, const Subnet& obj)
{
	ost << "Ip-adress subnet: " << obj.ip << std::endl;
	ost << "Length mask subnet: " << obj.mask << std::endl;
	ost << "Min ip-adress: " << obj.minIp << std::endl;
	ost << "Max ip-adress: " << obj.maxIp << std::endl;
	ost << "Broadcast ip-adress: " << obj.broadcastIp << std::endl;
	ost << "Amount hosts: " << obj.N_hosts;
	return ost;
}