#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <windows.h>
#include <clocale>
#include <limits>
#include <cctype>
using namespace std;

int askNumber(string question, int high, int low = 1);


//Exam P2
string GetRandomItem(vector<string>& items);
void DisplayInventory(vector<string>& inventory);
bool AskYesNo(string question);
void ReplaceItem(int& replace);
void BuySpace(unsigned int& gems, vector<string>& inventoryBought, string& itemReplace);
void ShowMenu();
//Exam ProfExample
void BuySpaceEx(vector<string>& inventory, unsigned int& gems, string itemFound);
void ReplaceItemEx(vector<string>& inventory, string itemFound);


const int MAX_ITEMS = 6;
const int SPACE_COST = 6;
const int FREE_ITEMS = 3;


//References 1111
void BADScoreSwap(int Value1, int Value2);
void ScoreSwap(int& Value1, int& Value2);

void display(const vector<string>& vec);

int main()
{
	std::setlocale(LC_ALL, "es_ES.UTF-8");
	unsigned int gems = 8;

	//Items
	vector<string> items = { "espada", "martillo", "bomba", "escudo" };

	//inventory
	vector<string> inventory;
	inventory.reserve(MAX_ITEMS);
	vector<string>::const_iterator iter;
	bool isContinue;

	do {
		cout << "\n--INVENTARIO---\n";
		cout << "Gemas: " << gems << endl;

		string itemFound = GetRandomItem(items);

		cout << "Has encontrado un(a) " << itemFound << "!!\n";

		if (inventory.size() >= FREE_ITEMS)
		{
			ShowMenu();
			int option = askNumber("\nElige un numero ", 3);

			switch (option)
			{
			case 1:
				ReplaceItemEx(inventory, itemFound);
				break;
			case 3:
				BuySpaceEx(inventory, gems, itemFound);
				break;
			default:
				break;
			}
		}
		else
		{
			inventory.push_back(itemFound);
		}



		//DisplayItems
		DisplayInventory(inventory);

		isContinue = AskYesNo("¿Seguir explorando?");

	} while (isContinue);

	cout << "\nVuelve pronto!!\n";

}

void BuySpaceEx(vector<string>& inventory, unsigned int& gems, string itemFound)
{
	if (gems >= SPACE_COST)
	{
		cout << "\n Espacio comprado con éxito!!\n";
		inventory.push_back(itemFound);
		gems -= SPACE_COST;
	}
	else
	{
		cout << "\nNo tienes gemas suficientes!!\n";
	}
}

void ReplaceItemEx(vector<string>& inventory, string itemFound)
{
	vector<string>::iterator iter;
	int itemChosen = 0;
	cout << "\n¿Qué item deseas reemplazar?\n";
	DisplayInventory(inventory);
	cin >> itemChosen;
	iter = inventory.begin() + itemChosen;
	*iter = itemFound;
}

								///PRACTICA DEL EXAMEN/////
void ExamenPractica()
{
	std::setlocale(LC_ALL, "es_ES.UTF-8");
	unsigned int gems = 8;

	//Items
	vector<string> items = { "espada", "martillo", "bomba", "escudo" };

	//inventory
	vector<string> inventory;
	inventory.reserve(MAX_ITEMS);
	vector<string>::const_iterator iter;
	bool isContinue;
	int replace = 0;

	do {
		cout << "\n--INVENTARIO---\n";
		cout << "Gemas: " << gems << endl;

		string itemFound = GetRandomItem(items);

		cout << "Has encontrado un(a) " << itemFound << "!!\n";

		if (inventory.size() >= FREE_ITEMS)
		{
			ShowMenu();
			int option = askNumber("\nElige un número ", 3);

			switch (option)
			{
			case 1:
				cout << "Que Item deseas reemplazar?"<<endl;
				DisplayInventory(inventory);/////Tengo que meter la mayoria de lo de este caso a la funcion 
				ReplaceItem(replace);
				inventory[replace] = itemFound;
				break;
			case 3:
				DisplayInventory(inventory);
				BuySpace(gems, inventory, itemFound);
				break;
			default:
				break;
			}
		}
		else
		{
			inventory.push_back(itemFound);
		}



		//DisplayItems
		DisplayInventory(inventory);

		isContinue = AskYesNo("¿Seguir explorando?");

	} while (isContinue);

	cout << "\nVuelve pronto!!\n";

}

void ReplaceItem(int & replace)
{
	
	cin >> replace;
	cout << "INVENTARIO ACTUALIZADO:" << endl;
}

void BuySpace(unsigned int& gems, vector<string>& inventoryBought, string& itemReplace)
{

	cout << "Un nuevo espacio en el inventario cuesta " << SPACE_COST << " gemas" << endl;
	if (gems > SPACE_COST)
	{
		AskYesNo("Tienes suficientes gemas para comprar un nuevo espacio\n ¿Deseas comprar un nuevo espacio?\n");
		gems = gems - SPACE_COST;
		cout << "Transaccion completada, haz compradu un nuevo espacio\n";
		inventoryBought.push_back(itemReplace);
	}
	else
	{
		cout << "Tristemente, no tienes suficientes gemas para comprar mas espacio\n";
	}

}

string GetRandomItem(vector<string>& items)
{
	srand(time(NULL));
	int itemRandomIndex = (rand() % items.size());
	string itemSelected = items[itemRandomIndex];

	return itemSelected;
}

void DisplayInventory(vector<string>& inventory)
{
	vector<string>::const_iterator iter;
	int i = 0;
	cout << "\n--Tus items--\n";
	for (iter = inventory.begin(); iter != inventory.end(); iter++)
	{
		cout << i << ".- " << *iter << endl;
		i++;
	}

}

							//FIN DE LA PRACTICA DEL EXAMEN///

bool AskYesNo(string question)
{
	char answer;

	do {
		cout << "\n" << question << "(y/n)";
		cin >> answer;
	} while (answer != 'y' && answer != 'n');

	if (answer == 'y')
	{
		return true;
	}

	return false;
}

void ShowMenu()
{
	cout << "\nYa no tienes espacio para más objetos, que te gustaría hacer:\n";
	cout << "\n1. Reemplazar objeto.";
	cout << "\n2. Continuar sin el objeto.";
	cout << "\n3. Comprar un espacio por " << SPACE_COST << " gemas.";
}








void TictactoePart1()
{
	const int HIGHT_WIDTH = 3;
	const int ROWS = 3;
	const int COLUMNS = 3;

	char board[ROWS][COLUMNS] = { {'o', 'x', 'o'},
								  {' ', 'x', 'x'},
								  {'x', 'o', 'o'} };

	cout << "---TIC TAC TOE--- \n";
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			cout << board[i][j];
		}
		cout << endl;
	}
	board[1][1] = 'x';

	cout << "---TIC TAC TOE---\n";
	
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			cout << board[i][j];
		}
		cout << endl;
	}

	cout << "\n X wins!!\n";


}




void MatrixBox()
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




int askNumber(string question, int high, int low)
{
	string input;
	bool isValid = false;
	//int number = 0;

	do {
		cout << question << "entre " << low << " y " << high << endl;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		getline(cin, input);
		//cin>> input;

		for (char c: input)
		{
			if (isdigit(c))
			{
				isValid = true;
				cout << "Test, The input is valid\n";
				break;
			}
			cout << "Test, outside the if\n";
		}
		if (!isValid)///Lo mismo que if(isvalid == false)
		{
			cout << "\nEntrada invalida, porfavor elige solo numeros.\n";
		}
		else if (isValid)
		{
			if (stoi(input) < low || stoi(input) > high)
			{
				cout << "Numero muy bajo o muy alto, introduce otro numero" << endl;
				isValid = false;
			}
		}

	} while (!isValid || input.empty());
		//number > high || number < low);

	return stoi(input);
}