#include <string>
#include <vector>
#include <iostream>
using namespace std;
int main() 
	{
		//vector<string> myStuff = { "espada", "martillo", "bomba" };
		//vector<string> inventory(10);
		//vector<string> inventory(10, " - ");
		//vector<string> inventory(myStuff);

		vector<string> inventory;

		inventory.push_back("Espada");
		inventory.push_back("Escudo");
		inventory.push_back("Martillo");

		cout << "Tienes" << inventory.size() << "items en tu inventario" << endl;

		//Iteration FOR
		for (unsigned int i = 0; i < inventory.size(); i++)
		{

			cout << inventory[i] << endl;

		}
		cout << "\nCambiaste tu" << inventory[0] << "por una Bomba.";
		inventory[0] = "Bomba";

		cout << "\n";

		//Iteration DO-WHILE
		int i = 0;
		do {
			cout << inventory[i] << endl;
			i++;
		} while (i < inventory.size());
			


	}



