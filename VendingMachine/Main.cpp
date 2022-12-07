#include "VendingMachine.h"
#include "Book.h"
#include "Slot.h"

int main() {
	setlocale(LC_ALL, "");
	Book* prince = new Book(10, "The little prince");
	Book* pirate = new Book(12, "About pirates");
	Book* stars = new Book(7, "Stars shining");
	Book* prince1 = new Book(10, "The little prince");

	Slot* firstSlot = new Slot(3);
	Slot* secondSlot = new Slot(2);
	Slot* thirdSlot = new Slot(3);
	Slot* fourthSlot = new Slot(2);
	
	firstSlot->addBook(prince);
	secondSlot->addBook(pirate);
	secondSlot->addBook(stars);
	secondSlot->addBook(prince1); //переполнение слота

	Book* books = secondSlot->getBooks();
	for (int i = 0; i < secondSlot->getMaxBooksCount(); i++) {
		std::cout << books[i].getName() << std::endl;
	}

	VendingMachine* machine = new VendingMachine(3);
	machine->addSlot(firstSlot);
	machine->addSlot(secondSlot);
	machine->addSlot(thirdSlot);
	machine->addSlot(fourthSlot); //переполнение машины

	std::cout << machine->getEmptySlotsCount() << std::endl; //1

	machine->vend(1, 2);

	std::cout << machine->getEmptySlotsCount() << std::endl; //2

	delete machine;

	return 0;
}