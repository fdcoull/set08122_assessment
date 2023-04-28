#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

//Print grid function
void printGrid(char line[], int lineLength, int size, int playerGrid[9][9])
{
		//Declare loop and coordinate variables
		int i;
		int j;
		int x = 1;
		int y = 1;
        int coordinate[2] = {0,0};

		for (i = 0; i < lineLength; i++)
		{
			for (j = 0; j < lineLength; j++)
			{
				//Check if first or last position on x axis
				if (i == 0 || i == lineLength - 1)
				{
						//Check if first position on x axis and position is not part of frame, print coordinate if so
						if (i == 0 && j % 4 != 0)
						{
							printf(" %d", coordinate[0]);
						}
						//If not, print frame character
						else
						{
							line[j] = '.';
							printf(" %c", line[j]);
						}
				}
				//Check if first or last position on y axis
				else if (j == 0 || j == lineLength - 1)
				{
					//Check if first position on y axis and position is not part of frame, print coordinate if so
					if (j == 0 && i % 4 != 0)
					{
						printf(" %d", coordinate[1]);
					}
					//If not, print frame character
					else
					{
						line[j] = '.';
						printf(" %c", line[j]);
					}
				}
				//Check if position is inside frame, print frame character if so
				else if (i % 4 == 0 || j % 4 == 0)
				{
					line[j] = '.';
					printf(" %c", line[j]);
				}
				//If not, print cell
				else
				{
                    line[j] = playerGrid[(coordinate[0] - 1)][(coordinate[1] - 1)];
                    
					if (line[j] == 0)
					{
						printf("  ");
					}
					else
					{
						printf(" %d", line[j]);
					}
				}

                //Calculate game X coordinate
                if (j == 0 || j % 4 != 0)
                {
                    coordinate[0]++;
                }
			}

            //Calculate game Y coordinate
            if (i == 0 || i % 4 != 0)
            {
                coordinate[1]++;
            }

            //Set X coordinate back to 0
            coordinate[0] = 0;

			//Print new line
			printf("\n");
		}
}

bool isPlayerGridComplete(int playerGrid[9][9])
{
	int i;
	int j;

	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			if(playerGrid[i][j] == 0)
			{
				return false;
			}
		}
	}

	return true;
}

void printUi(int difficultyOption)
{
	//Declare required variables
	int size;
	int lineLength;

	int filledGrid[9][9] = {{0},{0}};
	int playerGrid[9][9] = {{0},{0}};

	//Grid seeds
	int filledGridEasy[9][9] = {
		{5,3,7,8,1,2,9,6,4},
		{6,2,1,4,9,5,7,3,8},
		{9,4,8,6,3,7,2,1,5},
		{1,9,4,5,8,3,6,7,2},
		{2,8,6,1,7,4,3,5,9},
		{7,5,3,2,6,9,8,4,1},
		{4,6,5,7,2,8,1,9,3},
		{3,7,2,9,4,1,5,8,6},
		{8,1,9,3,5,6,4,2,7}
	};

	int playerGridEasy[9][9] = {
		{0,0,0,8,0,2,0,0,0},
		{0,2,1,0,9,0,0,3,0},
		{9,4,0,0,0,7,0,0,5},
		{1,0,0,0,8,0,0,7,0},
		{0,0,6,0,7,0,0,5,0},
		{0,5,0,0,6,0,0,0,1},
		{4,0,0,7,0,8,0,9,3},
		{0,7,0,0,4,0,5,8,0},
		{0,0,0,3,0,6,0,0,0}
	};

	int filledGridMedium[9][9] = {
		{5,3,2,9,8,7,4,1,6},
		{1,6,7,4,2,3,8,9,5},
		{9,8,4,5,1,6,2,3,7},
		{7,1,8,6,5,4,9,2,3},
		{4,9,6,2,3,1,7,5,8},
		{3,2,5,8,7,9,6,4,1},
		{6,5,1,7,9,2,3,8,4},
		{8,4,9,3,6,5,1,7,2},
		{2,7,3,1,4,8,5,6,9}
	};

	int playerGridMedium[9][9] = {
		{0,0,2,9,0,0,0,1,0},
		{1,0,0,0,0,3,0,0,0},
		{0,0,0,0,0,0,2,0,7},
		{0,0,0,0,0,0,9,0,3},
		{4,0,0,0,0,1,0,0,0},
		{0,0,5,8,0,0,0,4,0},
		{0,5,1,7,9,0,0,8,0},
		{0,4,0,0,6,0,0,0,0},
		{0,7,3,1,4,0,0,0,0}
	};

	int filledGridHard[9][9] = {
		{2,9,1,3,7,6,8,4,5},
		{8,4,3,2,1,5,9,6,7},
		{6,5,7,9,4,8,1,3,2},
		{9,7,4,5,3,1,6,2,8},
		{3,1,2,6,8,9,5,7,4},
		{5,6,8,4,2,7,3,1,9},
		{1,2,9,7,5,3,4,8,6},
		{4,3,5,8,6,2,7,9,1},
		{7,8,6,1,9,4,2,5,3}
	};

	int playerGridHard[9][9] = {
		{2,0,0,3,7,0,8,0,5},
		{8,0,0,0,0,5,0,0,0},
		{6,0,7,0,4,0,0,3,0},
		{0,0,4,0,0,0,0,0,0},
		{0,1,2,0,0,0,5,7,0},
		{0,0,0,0,0,0,3,0,0},
		{0,2,0,0,5,0,4,0,6},
		{0,0,0,8,0,0,0,0,1},
		{7,0,6,0,9,4,0,0,3}
	};


	bool completed = false;

    int userX;
    int userY;
    int userValue;

	int i;
	int j;

	//Populate grids with values depending on difficulty
	if (difficultyOption == 1)
	{
		for (i = 0; i < 9; i++)
		{
			for (j = 0; j < 9; j++)
			{
				filledGrid[i][j] = filledGridEasy[i][j];
				playerGrid[i][j] = playerGridEasy[i][j];
			}
		}
	}
	else if (difficultyOption == 2)
	{
		for (i = 0; i < 9; i++)
		{
			for (j = 0; j < 9; j++)
			{
				filledGrid[i][j] = filledGridMedium[i][j];
				playerGrid[i][j] = playerGridMedium[i][j];
			}
		}
	}
	else
	{
		for (i = 0; i < 9; i++)
		{
			for (j = 0; j < 9; j++)
			{
				filledGrid[i][j] = filledGridHard[i][j];
				playerGrid[i][j] = playerGridHard[i][j];
			}
		}
	}

	//Use seed to generate unique grid
	int seededValue;
	int randomNo;

	srand(time(NULL));
	
	//Use provided grid seeds and randomly generate new values
	randomNo = 1 + (rand() % 9);
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{

			seededValue = randomNo + filledGrid[i][j];

			if (seededValue > 9)
			{
				seededValue = seededValue - 9;
			}

			filledGrid[i][j] = seededValue;

			if (playerGrid[i][j] != 0)
			{
				playerGrid[i][j] = seededValue;
			}
		}
	}

	//Prompt user for grid size
	size = 3;

	//Calculate line size based on user input
	lineLength = (size + (3 * size)) + 1;

	//Set line array (required for Visual Studio Compiler)
	char line[13];

	while (completed == false)
    {
        //Execute print grid function
	    printGrid(line, lineLength, size, playerGrid);

        printf("Input X coordinate:");
        scanf("%d", &userX);
        printf("Input Y coordinate:");
        scanf("%d", &userY);
        printf("Input value:");
        scanf("%d", &userValue);

		if (playerGrid[(userX - 1)][(userY - 1)] == 0)
		{
			if (userValue == filledGrid[(userX - 1)][(userY - 1)])
			{
				printf("CORRECT!\n");
				playerGrid[userX - 1][userY - 1] = userValue;

				completed = isPlayerGridComplete(playerGrid);
			}
			else
			{
				printf("The entry you entered was incorrect, please try again.\n");
			}

		}
		else
		{
			printf("You selected a full cell, please select an empty one.\n");
		}

    }
}

int main(int argc, char **argv)
{
	bool menu = true;
	int menuOption;
	int difficultyOption;

	printf("Sudoku\nBy Finlay Coull\n\n");

	//Display main menu
	while (menu == true)
	{
		printf("Welcome to Sudoku!\nSelect a menu option:\n");
		printf("1. Play\n2. Exit\n");
		scanf("%d", &menuOption);

		if (menuOption == 1)
		{
			while (difficultyOption != 4)
			{
				//Display difficulty options
				printf("Select a difficulty:\n");
				printf("1. Easy\n2. Medium\n3. Hard\n4. Exit\n");
				scanf("%d", &difficultyOption);
				printUi(difficultyOption);
			}
		}
		else if (menuOption == 2)
		{
			menu = false;
		}
	}
}
