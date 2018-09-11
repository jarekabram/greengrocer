#include <FileManager.h>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	FileManager *fm = new FileManager("products.csv");
	fm->getDataFromFile();

	cout << "Welcome to cash register, what do you want to do? "<< endl << "Type a number:" << endl;
	bool finish = true;

	while(finish)
	{
		char key;
		cout << "1. Serve the customer" << endl;
		cout << "2. Add new Product" << endl;
		cout << "3. Finish program" << endl;
		cout << "4. Show Products" << endl;
		cin >> key;
		switch(key)
		{
		case '1':
			cout << key << endl;
			break;
		case '2':
			fm->addNewProduct();
			break;
		case '3':
			finish = false;
			cout << "Ending program" << endl;
			break;
		case '4':
			for(auto fruit : fm->fruits)
			{
				cout << fruit.toString() << endl;
			}
			for(auto veg : fm->vegetables)
			{
				cout << veg.toString() << endl;
			}
			break;
		default:
			cerr << "you have typed wrong key please enter once more" << endl;
			break;
		}
	}

	delete fm;
	return 0;
}
