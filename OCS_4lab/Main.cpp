#include <iostream>
#include <algorithm>
#include <conio.h>
#include "Net.h"

void findAmountAllocHosts(std::vector<uint32_t>& AllocHosts)
{
	int temp;
	for (size_t i = 0; i < AllocHosts.size(); i++)
	{
		for (size_t j = 0; true; j++)
		{
			temp = pow(2, j) - 2;
			if (temp >= (int)AllocHosts[i])
			{
				AllocHosts[i] = temp + 2;
				break;
			}
		}
	}
	//Сортируем хосты
	std::sort(AllocHosts.begin(), AllocHosts.end());
}

bool checkCountHosts(std::vector<uint32_t>& amountHosts, const uint8_t length)
{
	//Округляем количество хостов
	findAmountAllocHosts(amountHosts);
	int temp = 32 - length;
	int sumHosts = 0, result = pow(2, temp);
	for (size_t i = 0; i < amountHosts.size(); i++)
	{
		sumHosts += amountHosts[i];
	}
	if (sumHosts - 2 > result - 2)
	{
		return false;
	}
	else
	{
		return true;
	}
}

int main()
{
	Ip netIP;
	int length;
	uint32_t nSubnet;
	do
	{
		std::cout << "Enter IP-adress network: ";
		std::cin >> netIP;
		std::cout << "Enter lenth mask: ";
		std::cin >> length;
		std::cout << "Enter amount subnet: ";
		std::cin >> nSubnet;
		//Массив хостов
		std::vector<uint32_t> amountHostsInSubnets(nSubnet);
		std::cout << "Enter the number of hosts for each subnet: ";
		for (size_t i = 0; i < nSubnet; i++)
		{
			do 
			{
				std::cin >> amountHostsInSubnets[i];
			} while (amountHostsInSubnets[i] == 0);
		}
		//Проверяем потянет ли сеть данные подсети
		if (!checkCountHosts(amountHostsInSubnets, length))
		{
			std::cout << "Can not divide a network into subnets!!!\n";
		}
		else
		{
			//Передаем в конструктор IP-адрес сети, длину маски и массив хостов
			Net network(netIP, static_cast<uint8_t>(length), amountHostsInSubnets);
			std::cout << network;
		}
		std::cout << "Press any key to continue. ESC to exit!!!" << std::endl;
	}
	while (_getch() != 27);
	return 0;
}