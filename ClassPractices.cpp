#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main()
{
	vector <string> inventory;
	inventory.push_back("Espada");
	inventory.push_back("Escudo");
	inventory.push_back("Martillo");
	inventory.push_back("Rifle");

	vector<string>::iterator myIterator;
	vector<string>::const_iterator iter;

	cout << "\n Tus Items: \n";
	for (iter = inventory.begin(); iter != inventory.end(); iter++)
	{
		cout << *iter << endl;
	}
	//Intercambiar
	cout << "\n Intercambiaste tu " << inventory[2] << " por un arco";
	myIterator = inventory.begin() + 2;
	*myIterator = "Arco";
	cout << "\nTus Items: \n";
	for (iter = inventory.begin(); iter != inventory.end(); iter++)
	{
		cout << *iter << endl;
	}

	//SIZE
	cout << "\n El nombre del item " << *myIterator << " tiene ";
	cout << (*myIterator).size() << " letras";

	cout << "\n El nombre del item " << *myIterator << " tiene ";
	cout << (myIterator)->size() << " letras";

	//INSERT
	cout << "Recuperaste la bomba robada ";
	inventory.insert(inventory.begin() + 4, "bomba");
	cout << "\nTus Items: \n";
	for (iter = inventory.begin(); iter != inventory.end(); iter++)
	{
		cout << *iter << endl;
	}
	//DELETE
	cout << "\nTu " << inventory[1] << " fue destruido en batalla.";
	inventory.erase(inventory.begin() + 1);
	cout << "\nTus Items: \n";
	for (iter = inventory.begin(); iter != inventory.end(); iter++)
	{
		cout << *iter << endl;
	}
}

int WordGame()
{
	vector<string> WordGame = { "Computadora", "Hogar", "Inglaterra" };
	string Word1 = WordGame[0];
	string Answer1;
	string Word2 = WordGame[1];
	string Answer2;
	string Word3 = WordGame[2];
	string Answer3;
	int Vidas = 3;
	bool Continue1 = false;
	bool Continue2 = false;
	bool Continue3 = false;
	srand(time(NULL));
	do
	{
		if (Vidas == 0)
		{
			cout << "Te quedaste sin vidas" << endl;
			return 0;
		}
	cout << "Adivina la palabra que la computadora ha mezclado tienes "<<Vidas<<" vidas" << endl;
	
		cout << "Primera palabra" << endl;
		random_shuffle(Word1.begin(), Word1.end());
		cout << Word1 << endl;
		cin >> Answer1;

		

		if (Answer1 == WordGame[0])
		{
			cout << "Correcto!" << endl;
			cout << "Pasaras a la siguiente palabra" << endl;
			Continue1 = true;
		}
		
		else
		{
			cout << "Incorrecto" << endl;
			Vidas--;
		}
		


	} while (Continue1 == false);

	do
	{
		if (Vidas == 0)
		{
			cout << "Te quedaste sin vidas" << endl;
			return 0;
		}

		cout << "Segunda palabra. Tienes " <<Vidas<<" vidas"<< endl;
		random_shuffle(Word2.begin(), Word2.end());
		cout << Word2 << endl;
		cin >> Answer2;

		

		if (Answer2 == WordGame[1])
		{
			cout << "Correcto!" << endl;
			cout << "Pasaras a la siguiente palabra" << endl;
			Continue2 = true;
		}

		else
		{
			cout << "Incorrecto" << endl;
			Vidas--;
		}



	} while (Continue2 == false);

	do
	{
		if (Vidas == 0)
		{
			cout << "Te quedaste sin vidas" << endl;
			return 0;
		}

		cout << "Segunda palabra. Tienes " << Vidas << " vidas" << endl;
		random_shuffle(Word3.begin(), Word3.end());
		cout << Word3 << endl;
		cin >> Answer3;



		if (Answer3 == WordGame[2])
		{
			cout << "Correcto!" << endl;
			cout << "GANASTE!!!!!!!!!" << endl;
			Continue3 = true;
		}

		else
		{
			cout << "Incorrecto" << endl;
			Vidas--;
		}



	} while (Continue3 == false);
}






void IteratorFindShuffleSort()
{
	const int NUM_SCORES = 4;
	int score;

	vector<int>::const_iterator iter;
	vector<int> scores;

	for (int i = 0; i < NUM_SCORES; i++)
	{
		cout << "Score " << i + 1 << endl;
		cin >> score;
		scores.push_back(score);
	}
	cout << "Puntajes" << endl;
	for (iter = scores.begin(); iter != scores.end(); iter++)
	{
		cout << *iter << endl;
	}
	/*Find*/
	cout << "Buscar puntajes" << endl;
	cin >> score;
	//Desde donde buscas, hasta donde y que es lo que buscas
	iter = find(scores.begin(), scores.end(), score);
	//Si llega al final y no encuentra el score, agarra el del final
	if (iter != scores.end())
	{
		cout << "\nTu puntaje se encuentra en el vector\n";
	}
	else
	{
		cout << "\n No encontramos el puntaje que buscas\n";
	}

	/*Random Shuffle*/

	srand(time(NULL));
	random_shuffle(scores.begin(), scores.end());

	cout << "\n Scores Mezclados\n";
	for (iter = scores.begin(); iter != scores.end(); iter++)
	{
		cout << *iter << endl;
	}

	//Shuffle String
	string word = "espejo";
	random_shuffle(word.begin(), word.end());
	cout << word << endl;



	/*Sort*/
	cout << "\nCambiar orden\n";
	sort(scores.begin(), scores.end());
	for (iter = scores.begin(); iter != scores.end(); iter++)
	{
		cout << *iter << endl;
	}

	cout << "\nCambiar orden greater\n";
	sort(scores.begin(), scores.end(), greater<int>());
	for (iter = scores.begin(); iter != scores.end(); iter++)
	{
		cout << *iter << endl;
	}
}




void vectorReserve()
{
	vector<int>scores(10, 0);
	cout << "Vector size is: " << scores.size() << endl;
	cout << "Vector capacity is: " << scores.capacity() << endl;
	scores.reserve(40);
	scores.push_back(0);
	cout << "Vector size is: " << scores.size() << endl;
	cout << "Vector capacity is: " << scores.capacity() << endl;

	scores.push_back(0);
	scores.push_back(3);
	scores.push_back(3);
	scores.push_back(3);
	
	scores.push_back(3);

	cout << "Vector size is: " << scores.size() << endl;
	cout << "Vector capacity is: " << scores.capacity() << endl;

	scores.reserve(40);
	cout << "Vector size is: " << scores.size() << endl;
	cout << "Vector capacity is: " << scores.capacity() << endl;

}














void vectorsPart1() 
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




