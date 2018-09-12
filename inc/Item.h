#include <string>

#ifndef _ITEM_H_
#define _ITEM_H_

class Item{

private:
	int 		m_id;
	std::string m_itemName;
	double 		m_price;
	double 		m_weight;
	std::string m_category;

public:
	virtual ~Item(){}

	int getId() const {	return m_id;}
	void setId(int id) { this->m_id = id; }
	const std::string& getItemName() const { return m_itemName; }
	void setItemName(const std::string& itemName) { this->m_itemName = itemName; }
	double getPrice() const { return m_price; }
	void setPrice(double price) { m_price = price; }
	void setCategory(const std::string& category) {	m_category = category; }
	const std::string& getCategory() const { return m_category;	}

	virtual std::string toString() = 0;

	double getWeight() const {
		return m_weight;
	}

	void setWeight(double weight) {
		m_weight = weight;
	}
};


#endif // _ITEM_H_
