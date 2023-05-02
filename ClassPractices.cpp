#include <string>
#include <vector>
#include <iostream>
using namespace std;
int main() 
	{
	int TamMochila = 0;
	vector<string> invent;
		//vector<string> myStuff = { "espada", "martillo", "bomba" };
		//vector<string> inventory(10);
		//vector<string> inventory(10, " - ");
		//vector<string> inventory(myStuff);
		cout << "Tienes 3 mochilas en frente de ti:\n1. Rara (5 Espacios) \n2. Epica (7 Espacios) \n3.Legendaria(10 Espacios)"<<endl;
		cout << "Cual deseas agarrar?"<<endl;
		cin >> TamMochila;
		switch (TamMochila)
		{
			case 1:
				invent.resize(5);
				break;
			case 2:
				invent.resize(7);
				break;
			case 3:
				invent.resize(10);
				break;

		default:
			cout << "Opcion no valida" << endl;
			break;
		}
		
		for (unsigned int i = 0; i < invent.size();i++)
		{
			cout << "Tienes " << invent.size() << " espacios en tu inventario. Te quedan: " << invent.size() - i << endl;
			cout << "Introduce el item que quieres introducir" << endl;
			cin >> invent[i];
			system("cls");
			cout << "Tu inventario ahora contiene: " << endl;
			
			for(unsigned int j = 0; j<=i;j++)
			{
				cout << invent[j] << endl;

			}

			
		}
		/*
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
			

		cout << inventory[0] << " tiene " << inventory[0].size() << " letras en el. ";

		cout << "Tu martillo fue destruido en la ultima batalla" << endl;

		//Delete item from vector
		inventory.pop_back();
		//Iteration FOR
		for (unsigned int i = 0; i < inventory.size(); i++)
		{
			cout << inventory[i] << endl;
		}

		cout << "Un enemigo ha robado todas tus armas" << endl;
		//inventory.clear

		if (inventory.empty()) 
		{
			cout << "No tienes nada" << endl;
		}
		else
		{
			for (unsigned int i = 0; i < inventory.size(); i++)
			{
				cout << inventory[i] << endl;
			}
		}
		*/

	}




