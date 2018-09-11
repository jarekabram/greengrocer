#include <sstream>
#include <Fruit.h>

Fruit::Fruit(int id, std::string itemName, double price, double weight){
	this->setId(id);
	this->setPrice(price);
	this->setWeight(weight);
	this->setItemName(itemName);
	this->setCategory("vegetable");
}
Fruit::~Fruit()
{

}
std::string Fruit::toString()
{
	std::ostringstream oss;
	oss << 	"ID: " << std::to_string(this->getId())<< "\n" <<
			"NAME: " << this->getItemName() << "\n" <<
			"PRICE: " << std::to_string(this->getPrice()) << "\n" <<
			"WEIGHT: " << std::to_string(this->getWeight());;
	return oss.str();
}
