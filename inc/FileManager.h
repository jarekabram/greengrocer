#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

#include <Fruit.h>
#include <Vegetable.h>

#ifndef _FILE_MANAGER_
#define _FILE_MANAGER_

class FileManager{

public:
	std::vector<Fruit> fruits;
	std::vector<Vegetable> vegetables;

	FileManager(std::string file);
	~FileManager();
	int addNewProduct();
	bool isProduct(int id);
	void getDataFromFile();


private:
	std::fstream m_file;
	std::string m_filename;

	void gatherInput(std::string category);
};

#endif
