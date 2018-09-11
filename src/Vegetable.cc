#include <sstream>
#include <Vegetable.h>

Vegetable::Vegetable(int id, std::string itemName, double price, double weight){
	this->setId(id);
	this->setPrice(price);
	this->setWeight(weight);
	this->setItemName(itemName);
	this->setCategory("vegetable");
}
Vegetable::~Vegetable()
{}

std::string Vegetable::toString()
{
	std::ostringstream oss;
	oss << 	"ID: " << std::to_string(this->getId())<< "\n" <<
			"NAME: " << this->getItemName() << "\n" <<
			"PRICE: " << std::to_string(this->getPrice()) << "\n" <<
			"WEIGHT: " << std::to_string(this->getWeight());;
	return oss.str();
}
