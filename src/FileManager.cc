#include <FileManager.h>

FileManager::FileManager(string filename)
{
	m_filename = filename;
}
FileManager::~FileManager()
{
}

void FileManager::calculateItems()
{
	bool flag = true;
	std::vector<std::shared_ptr<Item>> basket;
	cout << "Please insert products by ID" << endl;

	double purchase = 0.0;
	while(flag)
	{
		cout << "Actual purchase:" << purchase << endl;

		int id;
		double quantity;
		cout << "ID" << endl;
		cin >> id; cin.clear();

		if(!isProductAlreadyAdded(id))
		{
			cerr << "Product with given id was not already added, please add product and then try again" << endl;
			return;
		}

		cout << "Quantity:" << endl;
		cin >> quantity; cin.clear();

		for(auto it : m_items){
			if(id == it->getId())
			{
				it->setWeight(quantity);
				basket.emplace_back(it);
				purchase += it->getPrice()*quantity;
			}
		}

		cout << "Add another Item? (y/n)" << endl;

		char itemKey;
		cin >> itemKey; cin.clear();

		if(itemKey == 'y')
		{
			cout << "Please insert next Product ID" << endl;
		}
		else if(itemKey == 'n')
		{
			printCheck(purchase, basket);
			flag = false;
		}
		else
		{
			cerr << "You typed wrong rolling back transaction";
			flag = false;
			break;
		}
	}
}

void FileManager::addNewProduct()
{
	string category;
	cout << "Which category would be a product? (fruit or vegetable)" << endl;

	cin >> category; cin.clear();

	if(category == "fruit")
	{
		cout << "Please insert parameters to add new item:" << endl;
		gatherInput(category);
	}
	else if(category == "vegetable")
	{
		gatherInput(category);
	}
	else
	{
		cerr << "Wrong category, going back to menu..." << endl;
		return;
	}
}

bool FileManager::isProductAlreadyAdded(int id)
{
	bool result = false;
	for(auto it : m_items)
	{
		if (id == it->getId()){
			result = true;
		}
	}
	return result;
}

int FileManager::getDataFromFile()
{
	int result = 1;
	m_file.open (m_filename, ifstream::in);
	if (!m_file.is_open()) {
	  cerr << "can't open output file" << endl;
	  result = -1;
	}
	cout << "Loading objects" << endl;
	string line;

	string id;
	string name;
	string price;
	string category;

	try{
		while(m_file.good())
		{
			getline(m_file, id, ',');
			getline(m_file, name, ',');
			getline(m_file, price, ',');
			getline(m_file, category, '\n');

			addItem(id, name, price, category);
		}
	}
	catch(invalid_argument){
		cerr << "Error during parsing file (products.csv) - please check if there is an enter after last line" << endl;
		result = -1;
	}

	m_file.close();
	return result;
}

void FileManager::gatherInput(string category)
{
	string id;
	string name;
	string price;

	cout << "ID: " << endl;
	cin >> id; cin.clear();
	cout << "NAME: " << endl;
	cin >> name; cin.clear();
	cout << "PRICE: " << endl;
	cin >> price; cin.clear();

	if (!isProductAlreadyAdded(stoi(id)))
	{
		m_file.open (m_filename, fstream::app);
		if (!m_file.is_open()) {
		  cerr << "can't open output file" << endl;
		}

		addItem(id, name, price, category);

		m_file << "\n";
		m_file << id << "," <<
				  name << "," <<
				  price << "," <<
				  category;
		m_file.close();
	}
	else
	{
		cerr << "Product with given id was already added, please add product with another id" << endl;
		return;
	}
}

void FileManager::printCheck(double purchase, std::vector<std::shared_ptr<Item>> basket)
{
	cout << "All items added - printing check" << endl;
	cout << "===============================" << endl;
	cout << "PRODUCT" << "\t\t\t" << "TOTAL PRICE" << endl;
	for(auto it : basket)
	{
		cout << it->getItemName() << "\t\t\t" << it->getWeight() << "*"<< it->getPrice() << "zl" << endl;

	}
	cout << "Total purchase: " << purchase << " zl" << endl;
	cout << "===============================" << endl;
}

void FileManager::addItem(string id, string name, string price, string category)
{
	if(category == "fruit")
	{
		m_items.emplace_back(make_shared<Fruit>(stoi(id), name, stod(price)));
	}
	else if(category == "vegetable")
	{
		m_items.emplace_back(make_shared<Vegetable>(stoi(id), name, stod(price)));
	}
}
