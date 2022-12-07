#pragma once
#include <string>
class Book
{
private:
	int cost;
	std::string name;

public:
	Book();
	Book(int cost, std::string name);
	~Book();

	Book& operator= (Book* other);

	void updateCost(int newCost);
	void rename(std::string newName);
	int getCost();
	std::string getName();
};

