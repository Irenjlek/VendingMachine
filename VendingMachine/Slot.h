#pragma once
#include <iostream>

#include "Book.h"

class Slot
{
private:
	int maxBooksCount;
	int currrentBooksCount;
	Book* books;

public:
	Slot();
	Slot(int maxCount);
	Slot& operator= (Slot* other);
	~Slot();

	int getMaxBooksCount();
	int getCurrentBooksCount();
	Book* getBooks();

	bool addBook(Book* book);
	bool removeBook();

};

