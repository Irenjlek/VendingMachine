#include "VendingMachine.h"
#include <stdio.h>

VendingMachine::VendingMachine(int slotsCount): maxSlotsCount(slotsCount), currentSlotsCount(0)
{
    slots = new Slot[slotsCount];
}

VendingMachine::~VendingMachine()
{
    delete[] slots;
}

int VendingMachine::getMaxSlotsCount()
{
    return maxSlotsCount;
}

int VendingMachine::getCurrentSlotsCount()
{
    return currentSlotsCount;
}

Slot* VendingMachine::getSlots()
{
    return slots;
}

bool VendingMachine::vend(int slotNum, int count)
{
    Slot& slot = slots[slotNum];
    bool excess = true;
    for (int i = 0; i < count; i++) {
        if (!slot.removeBook()) {
            excess = false;
        }
    }
    return excess;
}

bool VendingMachine::addSlot(Slot* slot)
{
    if (currentSlotsCount == maxSlotsCount) {
        std::cout << "Все места заняты!" << std::endl;
        return false;
    }
    slots[currentSlotsCount++] = slot;
    return true;
}

bool VendingMachine::removeSlot()
{
    if (currentSlotsCount == 0) {
        std::cout << "Автомат пуст!" << std::endl;
        return false;
    }
    slots[currentSlotsCount-1] = nullptr;
    currentSlotsCount--;
    return true;
}

int VendingMachine::getEmptySlotsCount()
{
    int count = 0;
    for (int i = 0; i < maxSlotsCount; i++)
    {
        if (slots[i].getCurrentBooksCount() == 0) {
            count++;
        }
    }
    return count;
}
