#pragma once
#include <string>
#include <map>
#include <set>
// ������� �������� �� 1 ��������������� ������; 2 �� �� ��� ����� ������ ������ �� 40 �����; 3 ����� ��� ���������; 
struct ClientInfo {
	std::string name;
	std::string surname;
	std::string patronymic;
	long long amount;
	std::string pincode;
};

class ProcessingCenter {

	std::map<std::string, ClientInfo> database;
	std::set<std::string> existing;
public:
	// ��� ������� �����, �� ����� �������
	void addClient(const std::string card,const ClientInfo& info) {
		if (!existing.count(card)) {
			database[card] = info;
			existing.insert(card);
		}
		else
		{
			throw "Client with this card already exists in this processing center";
		}
	}
	void deleteClient(const std::string card) {
		if (existing.count(card)) {
			existing.erase(card);
		}
	}
	// ����� ��� ������� �����
	bool checkPin(const std::string card, const std::string pin) {
		return database[card].pincode == pin; // �� ������
	}
};

class ATM
{
	ProcessingCenter pcenter;
};