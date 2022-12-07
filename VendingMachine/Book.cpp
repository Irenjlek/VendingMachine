#include "Book.h"

Book::Book(): cost(0), name("empty")
{
}

Book::Book(int cost, std::string name): cost(cost), name(name)
{
}

Book::~Book()
{
}

Book& Book::operator=(Book* other)
{
	this->cost = other->cost;
	this->name = other->name;
	return *this;
}

void Book::updateCost(int newCost)
{
	cost = newCost;
}

void Book::rename(std::string newName)
{
	name = newName;
}

int Book::getCost()
{
	return cost;
}

std::string Book::getName()
{
	return name;
}
