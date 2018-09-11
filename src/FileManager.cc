#include <FileManager.h>

FileManager::FileManager(std::string filename)
{
	m_filename = filename;
}
FileManager::~FileManager()
{
}

int FileManager::addNewProduct()
{
	int result;
	std::string category;
	std::cout << "Which category would be a product? (fruit or vegetable)" << std::endl;

	std::cin >> category;

	if(category == "fruit")
	{
		std::cout << "Please insert parameters to add new item:" << std::endl;
		gatherInput(category);
//		fruits.emplace_back(Fruit(id, name, price, weight));

		result = 1;
	}
	else if(category == "vegetable")
	{
		gatherInput(category);
		result = 1;
	}
	else
	{
		std::cerr << "Wrong category, going back to menu..." << std::endl;
		result = -1;
	}
	return result;
}

bool FileManager::isProduct(int id)
{
	return 0;
}

void FileManager::getDataFromFile()
{
	m_file.open (m_filename, std::ifstream::in);
	if (!m_file.is_open()) {
	  std::cerr << "can't open output file" << std::endl;
	}
	std::cout << "Loading objects" << std::endl;
	std::string line;

	std::string id;
	std::string name;
	std::string price;
	std::string weight;
	std::string category;

	while(m_file.good()){
		std::getline(m_file, id, ',');
		std::getline(m_file, name, ',');
		std::getline(m_file, price, ',');
		std::getline(m_file, weight, ',');
		std::getline(m_file, category, '\n');

		if(category == "fruit"){
			fruits.emplace_back(Fruit(std::stoi(id), name, std::stod(price), std::stod(weight)));
		}
		if(category == "vegetable"){
			vegetables.emplace_back(Vegetable(std::stoi(id), name, std::stod(price), std::stod(weight)));
		}

	}
	m_file.close();
}

void FileManager::gatherInput(std::string category){

	m_file.open (m_filename, std::fstream::app);
	if (!m_file.is_open()) {
	  std::cerr << "can't open output file" << std::endl;
	}
	int id;
	std::string name;
	double price;
	double weight;

	std::cout << "ID: " << std::endl;
	std::cin >> id;
	std::cout << "NAME: " << std::endl;
	std::cin >> name;
	std::cout << "PRICE: " << std::endl;
	std::cin >> price;
	std::cout << "WEIGHT: " << std::endl;
	std::cin >> weight;

//	m_file << "\n";
	m_file << id << "," <<
			  name << "," <<
			  price << "," <<
			  weight << "," <<
			  category << "\n";
	m_file.close();

}
