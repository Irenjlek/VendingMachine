#include "Slot.h"

static Book* nullBook = new Book();

Slot::Slot():maxBooksCount(10), currrentBooksCount(0)
{
	books = new Book[maxBooksCount];
}

Slot::Slot(int maxCount): maxBooksCount(maxCount), currrentBooksCount(0)
{
	books = new Book[maxBooksCount];
}

Slot& Slot::operator=(Slot* other)
{
	this->maxBooksCount = other->maxBooksCount;
	this->currrentBooksCount = other->currrentBooksCount;
	this->books = other->books;
	return *this;
}

Slot::~Slot()
{
	delete[] books;
}

int Slot::getMaxBooksCount()
{
	return maxBooksCount;
}

int Slot::getCurrentBooksCount()
{
	return currrentBooksCount;
}

bool Slot::addBook(Book* book)
{
	if (currrentBooksCount == maxBooksCount) {
		std::cout << "Лоток полностью заполнен!" << std::endl;
		return false;
	}
	books[currrentBooksCount++] = book;
	return true;
}

bool Slot::removeBook()
{
	if (currrentBooksCount == 0) {
		std::cout << "Лоток пуст!" << std::endl;
		return false;
	}
	books[currrentBooksCount-1] = nullBook;
	currrentBooksCount--;
	return true;
}

Book* Slot::getBooks()
{
	return books;
}


