#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <clocale>

using namespace std;

void CreateCards(int[][15],int);//Function that creates a two dimensional array of tombala cards
void ChooseCards(int[][15],int, int[],int, int);//Mixed card selector function
void TombalaBag(int[], int);//A sequence of numbers from 1 to 90 representing tombala stamps
int StampSelector(int[], int);//Function that selects stamps from tombala bag
void FindResult(int[][15],int, int[],int, int[],int, int[],int, int[],int, int);//The function that replaces the numbers drawn from the bag with -1 and finds players who make çinko and tombala
void ArrayValueReset(int[][15],int,int[][15],int ,int[], int, int[], int);//Function to restore strings after each set
void ScoreTable(int[], int,int);//The function that calculates the scores of the players at the end of 3 sets and prints them on the screen



int main()
{
	int a[10][15];//Array of cards
	int b[10][15] = {};//Copy Of "a" array, used to restore "a" sequence after each set
	int c[10]={0};//Array containing card numbers assigned to players
	int d[90] = { 0 };//Array of stamps created in tombala bag
	int e[90] = { };//Array with stamp numbers between 1 and 90
	int numberOfPlayer;//Variable containing the number of players set by the user
	int f[5] = {};//The array where players' scores are stored
	
	
	setlocale(LC_ALL,"Turkish");
	srand(time(NULL));
	cout << "     " << "LOADING TOMBALA CARDS...\n";
	cout << endl;
	
	CreateCards(a,15);            //The two-dimensional array a is created with the function,
	for (int x = 0;x < 10;x++)    // and with the following loop, the array b is created, which is a copy of a,
	{                             // which we will use to restore the sequence representing the cards in a after each set.
		for (int y = 0;y < 15;y++)
		{
			b[x][y] = a[x][y];
		}
	}

	cout << "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n" << endl;

	cout << "Number Of Player: ";
	cin >> numberOfPlayer;

	if ((numberOfPlayer < 2) || (numberOfPlayer > 5))//Sets the limit for the number of players
	{
		cout << "Please enter a minimum of 2 and a maximum of 5 players!!!" << endl;
		return 0;
	}

	
	for (int i = 1;i < 4;i++) //Loop allowing each game to be 3 sets
	{
		
		cout << "\n**************************************  THE " << i << " . SET  **************************************" << endl;

		ChooseCards(a, 15, c, 10,numberOfPlayer);

		TombalaBag(d, 90);


		cout << "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n" << endl;

		FindResult(a, 15, c, 10, d, 90, e, 90, f , 5 ,numberOfPlayer);

		ArrayValueReset(a,15,b,15,c, 10, d, 90);

	}
	cout << "\n=====================================  SCORE TABLE  =====================================\n" << endl;
	ScoreTable(f, 5,numberOfPlayer);

		return 0;
	
}





void CreateCards(int a[][15], int )
{
	for (int row = 0;row < 10;row++)
	{
		cout << "Card No" << row << ":"<<"  "<<setw(3);

		for (int column = 0;column < 15;column++)
		{
			a[row][column] = rand() % 89 + 1;
			
			for (int i = 0;i < column;i++)
			{
				for (int j =0 ;j < column+1;j++)
				{
					if (i == j)
						continue;

					if (a[row][i] == a[row][j])
						a[row][j] = rand() % 89 + 1;
				}
			}
			
			cout << a[row][column]<<setw(4);
		}
		cout << endl;
	}

}


void ChooseCards(int a[][15], int ,int b[],int,int gamers )
//We throw mixed unique numbers representing card numbers into the array we originally defined with 0.
{
	
	int r;//After each loop the rand function is the variable where we define random unique numbers between 0 and 9

	for (int i = 0;i <10;i++)
	{
		while (1)
		{
			r = rand() % 9;

			if (b[r] == 0)
			{
				b[r] = i;
				break;
			}
		}

	}
	
	cout << "Card Numbers Of Players\n"<<endl;
	//The part that assigns cards to the players designated by the user and prints the selected cards on the screen

			for (int i = 0;i < gamers;i++)  
			{
				cout << b[i] << setw(4);
			}
			cout << "\n" << endl;

			for (int j = 0;j < gamers;j++)
			{
				if (j == 0)
					cout << setw(4);
				cout << j << ". Player's Card Number:" << "  " << setw(2);
				for (int k = 0;k < 15;k++)
				{
					cout << a[b[j]][k] << setw(4);
				}
				cout << endl;

			}
}		


void TombalaBag(int d[], int)
{
	/*Filling the tombala bag with random unique numbers between 1 and 90 is done with the following loops
	and is printed on the screen*/

	int r;//After each loop the rand function is the variable where we define random unique numbers between 1 and 90

	cout << "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n" << endl;
	cout << "  Numbers Drawn: " << endl;
	cout << endl;

	for (int i = 1;i <= 90;i++)
	{
		while (1)
		{
			r = rand() % 90;

			if (d[r] == 0)
			{
				d[r] = i;
				break;
			}
		}

	}

	for (int l = 0;l < 90;l++)
	{
		if (l == 0)
			cout << setw(5);
		cout << d[l] << setw(5);

		if (l == 9 || l == 19 || l == 29 || l == 39 || l == 49 || l == 59 || l == 69 || l == 79 || l == 89)

		{
			cout << endl;
		}
	
	}

}

int StampSelector(int e[], int)
{
	//Selects stamps to be hovered on cards and assigns 0 to selected stamps to avoid re-selection
	int pul=0;

	for (int i = 0;i < 90;i++)
	{
		if (e[i] == 0)
			continue;
		pul = e[i];
		e[i] = 0;
		break;
	}
	
return pul;

}




void FindResult(int a[][15], int, int c[], int, int d[], int, int e[], int,int f[],int, int r)
{

	int counter;//Counts -1's on the cards of players who make çinko and tombala
	int control=0;//Control variable prevents printouts from printing more than 1 when çinko and tombala are made

	for (int x = 0;x < 90;x++)
	{
		e[x] = StampSelector(d, 90);

		for (int k = 0;k < r;k++)
		{
			for (int l = 0;l < 15;l++)
			{
				if (a[c[k]][l] == e[x])
					a[c[k]][l] = -1;
			}

		}


		for (int i = 0;i < r;i++)
		{
			counter = 0;

			for (int j = 0;j < 15;j++)
			{
				if (a[c[i]][j] == -1)
					counter++;
			}



			if (control == 0)
			{
				if (counter == 5)
				{
					control = 1;
					cout << endl;
					cout << "Winner Of The First Çinko is Player " << i << "\n" << endl;
					f[i] += 5;
					for (int x = 0;x < r;x++)
					{
						if (x == 0)
							cout << setw(4);
						for (int y = 0;y < 15;y++)
						{
							cout << a[c[x]][y] << setw(4);
						}
						cout << endl;

					}


				}
			}
			else if (control == 1)
			{
				if (counter == 10)
				{
					control = 2;
					cout << endl;
					cout << "Winner Of The Second Çinko is Player " << i << "\n" << endl;
					f[i] += 10;
					for (int x = 0;x < r;x++)
					{
						if (x == 0)
							cout << setw(4);
						for (int y = 0;y < 15;y++)
						{
							cout << a[c[x]][y] << setw(4);
						}
						cout << endl;

					}


				}

			}

			else if (control == 2)
			{
				if (counter == 15)
				{
					control = 3;
					cout << endl;
					cout << "Winner Of The Tombala is Player " << i << "\n" << endl;
					f[i] += 15;
					for (int x = 0;x < r;x++)
					{
						if (x == 0)
							cout << setw(4);
						for (int y = 0;y < 15;y++)
						{
							cout << a[c[x]][y] << setw(4);
						}
						cout << endl;

					}


				}

			}
			
			
		}
		if (control == 3)//Torbadan pul çekmeyi bırakır
			break;
	}
}


void ArrayValueReset(int a[][15],int, int d[][15],int ,int b[],int, int c[],int)
{
	//With the following loops, we restore each series whose content is changed in each set during the program run
	for (int i = 0;i < 10;i++)
	{
	
			b[i] = 0;
	}

	for (int j = 0;j < 90;j++)
	{
		c[j] = 0;
	}
	
	for (int x = 0;x < 10;x++)
	{
		for (int y = 0;y < 15;y++)
		{
			a[x][y] = d[x][y];
		}
	}

}

	

void ScoreTable(int f[], int,int numberOfPlayer)
{
	//Prints the total of points and the player who won the game on the screen

	int largestScore=f[0];
	int index=0;
	int index2 = 0;
	int index3 = 0;
	int counter = 0;

	for (int i = 0;i < numberOfPlayer;i++)
	{
		if (i == 0)
			cout << setw(4);
		cout << i << ". Player Score:----------> " << f[i]<<setw(4)<<endl;
	}
	//The following for cycle determines the players who win the game by finding the largest scored index in the series that contains players' scores
	for (int j = 1;j < numberOfPlayer;j++)
	{
		
		if (f[j] > largestScore)
		{
			largestScore = f[j];
			index = j;
		}
		
		
	}

	for (int x = 0;x < numberOfPlayer;x++)
	{
		if ((largestScore == f[x]) && (index != x))
		{
			index2 = x;
		}
	}
	for (int y = 0;y < numberOfPlayer;y++)
	{
		if ((largestScore == f[y]) && (index != y)&&(index2!=y))
		{
			index3 = y;
		}
	}
	//Cannot have more than 3 players with the same highest score because up to 5 players can play
	if ((index2!=0)&&(index3!=0))//Prints all 3 players if 3 players have the highest equal score
	{
		cout << "\n   WINNING PLAYERS --------> " << index <<". --- "<< index3 <<". AND "<< index2 << ". PLAYERS " << "     " << "SCORE-----> " << largestScore << setw(4) << endl;
		
	}
	else if(index2!=0)//Prints all 2 players  if 2 players have the highest equal score
	{
		cout << "\n   WINNING PLAYERS --------> " << index << ". AND " << index2 << ". PLAYERS " << "     " << "SCORE-----> " << largestScore << setw(4) << endl;
	
	}
	else//if the winner is only 1 player
	{
		cout << "\n   WINNING PLAYER --------> " << index << ". PLAYER " << "     " << "SCORE-----> " << largestScore << setw(4) << endl;
	}

}