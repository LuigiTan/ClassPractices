#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <windows.h>
using namespace std;
//References 1111
void BADScoreSwap(int Value1, int Value2);
void ScoreSwap(int& Value1, int& Value2);
void display(const vector<string>& vec);

int main()
{
	const int ROWS = 10;
	const int COLUMNS = 10;

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			if (i == 0||i==(ROWS-1))
			{
				cout << " 1 ";
			}
			else if (j == 0 || j == (COLUMNS - 1))
			{
				cout << " 1 ";
			}
			else
			{
				cout << " 0 ";
			}
			
		}
		cout << "\n";
	}
	cout << "\n" << "\n";

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			if (i == 0 || i == (ROWS - 1))
			{
				cout << " 1 ";
			}
			else if (j == 0 || j == (COLUMNS - 1))
			{
				cout << " 1 ";
			}
			else if (j == i)
			{
				cout << " 1 ";
			}
			else
			{
				cout << " 0 ";
			}

		}
		cout << "\n";
	}
	cout << "\n" << "\n";

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			if (i == 0 || i == (ROWS - 1))
			{
				cout << " 1 ";
			}
			else if (j == 0 || j == (COLUMNS - 1))
			{
				cout << " 1 ";
			}
			else if (j == i)
			{
				cout << " 1 ";
			}
			else if (j == (COLUMNS - i - 1))
			{
				cout << " 1 ";
			}
			else
			{
				cout << " 0 ";
			}

		}
		cout << "\n";
	}






}








void inventoryDisplay()
{
	vector<string> inventory;

	inventory.push_back("sword");
	inventory.push_back("armor");
	inventory.push_back("gun");

	display(inventory);



}
void display(const vector<string>& vec)
{
	vector<string>::const_iterator iter;
	for (iter = vec.begin(); iter != vec.end(); iter++)
	{
		cout << *iter << endl;
	}
}

void swap()
{
	int Score1 = 0; 
	int Score2 = 0;

	cout << "introduce el primer score" << endl;
	cin >> Score1;
	cout << "introduce el segundo score" << endl;
	cin >> Score2;
	cout << "Estos son los scores\n" << Score1 << "\n" << Score2 << endl;
	cout << "Usando un Swap malo" << endl;
	BADScoreSwap(Score1, Score2);
	Sleep(500);
	cout << "Estos son los scores\n" << Score1 << "\n" << Score2 << endl;
	Sleep(1000);
	ScoreSwap(Score1, Score2);
	cout << "Iniciando el buen Swap." << endl;
	Sleep(1000);
	cout << "Cambiando";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout<<"\nEstos son los nuevos Scores\n"<< Score1 << "\n" << Score2 << endl;


}
void ScoreSwap(int & Value1, int & Value2)//Los amperson son necesarios para que el valor cambiado dentro de la funcion se aplique al resto del codigo
{
	int TempValue = Value1; // TempValue se vuelve el valor del Value1 (Score1)
	Value1 = Value2;
	Value2 = TempValue;

}
void BADScoreSwap(int Value1, int Value2)
{
	int TempValue = Value1; // TempValue se vuelve el valor del Value1 (Score1)
	Value1 = Value2;
	Value2 = TempValue;

}




void GuessTheWord()
{
	const int MAX_ATTEMPTS = 3;
	int attempts = 0;

	vector<string>words;
	words.push_back("COMPUTADORA");
	words.push_back("JUEGO");
	words.push_back("CODIGO");
	words.push_back("REFRIGERADOR");

	srand(time(NULL));
	int randomNumber = rand();
	int wordsRandomIndex = (randomNumber % words.size());
	string wordSelected = words[wordsRandomIndex];

	//cout << wordSelected << endl;

	random_shuffle(wordSelected.begin(), wordSelected.end());
	cout << wordSelected << endl;

	string correctWord;

	do
	{
		cin >> correctWord;
		transform(correctWord.begin(), correctWord.end(), correctWord.begin(), ::toupper);
		//cout << correctWord << endl;

		if (correctWord == words[wordsRandomIndex])
		{
			cout << "\nAdivinaste la palabra!!!\n";
			break;

		}
		else
		{
			attempts++;
			
			cout << "Fallaste humano inepto. Todo pendejo, tipico de un saco de carne, te quedan: "<< MAX_ATTEMPTS - attempts << endl;
		}
	
	} while (attempts != MAX_ATTEMPTS);
	cout << "Fin del juego" << endl;

	if (attempts == MAX_ATTEMPTS)
	{
		cout << "\nPerdiste. Todo menso, mejor date de baja de la vida\nLa palabra era: \n";
		cout << words[wordsRandomIndex];

	}
	else
	{
		cout << "\nMUY BIEN!! Lo hiciste en: " << attempts + 1 << " intentos. ";
	}
}




void IterInventory()
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




