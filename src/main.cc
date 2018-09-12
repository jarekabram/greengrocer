#include <iostream>
#include "FileManager.h"

int main(int argc, char** argv)
{
	FileManager* fm = new FileManager("products.csv");
	if(fm->getDataFromFile() == -1)
	{
		cerr << "There was an error during opening or parsing file closing program" << endl;
		return 0;
	}

	cout << "Welcome to cash register, what do you want to do? "<< endl <<
			"Type a number:" << endl;
	bool finish = true;

	while(finish)
	{
		char key;
		cout << "1. Serve the customer" << endl;
		cout << "2. Add new Product" << endl;
		cout << "3. Finish program" << endl;
		cout << "4. Show Products" << endl;

		cin >> key; cin.clear();
		switch(key)
		{
		case '1':
			fm->calculateItems();
			break;
		case '2':
			fm->addNewProduct();
			break;
		case '3':
			finish = false;
			cout << "Ending program" << endl;
			break;
		case '4':
			for(auto item : fm->m_items)
			{
				cout << item->toString() << endl;
			}
			break;
		default:
			cerr << "You have typed wrong key please enter once more" << endl;
			break;
		}
	}

	delete fm;
	return 0;
}
