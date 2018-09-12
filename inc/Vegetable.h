#include "Item.h"

#ifndef _VEGETABLE_H_
#define _VEGETABLE_H_

class Vegetable : public Item
{

public:
	Vegetable(int id, std::string itemName, double price);
	virtual ~Vegetable();
	virtual std::string toString() override;
};

#endif // _FRUIT_H_
