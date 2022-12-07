#pragma once
#include "Slot.h"

class VendingMachine
{
private:
	int maxSlotsCount;
	int currentSlotsCount;
	Slot* slots;

public:
	VendingMachine(int slotsCount);
	~VendingMachine();

	int getMaxSlotsCount();
	int getCurrentSlotsCount();
	Slot* getSlots();

	bool vend(int slotNum, int count);
	bool addSlot(Slot* slot);
	bool removeSlot();
	int getEmptySlotsCount();
};

