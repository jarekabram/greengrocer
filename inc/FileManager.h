#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <memory>

#include <Fruit.h>
#include <Vegetable.h>

using namespace std;

#ifndef _FILE_MANAGER_
#define _FILE_MANAGER_

class FileManager {

public:
	std::vector<std::shared_ptr<Item>> m_items;

	FileManager(std::string filename);
	~FileManager();
	void calculateItems();
	void addNewProduct();
	int getDataFromFile();

private:
	std::fstream m_file;
	std::string m_filename;

	bool isProductAlreadyAdded(int id);
	void gatherInput(std::string category);
	void printCheck(double purchase, std::vector<std::shared_ptr<Item>> basket);
	void addItem(string id, string name, string price, string category);
};

#endif
