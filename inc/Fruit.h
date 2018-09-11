#include "Item.h"

#ifndef _FRUIT_H_
#define _FRUIT_H_

class Fruit : public Item
{

public:
	Fruit(int id, std::string itemName, double price, double weight);
	virtual ~Fruit();
	virtual std::string toString() override;
};

#endif // _FRUIT_H_
