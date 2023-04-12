#include <stdio.h>

//Print grid function
void printGrid(char line[], int lineLength, int size)
{
		//Declare loop and coordinate variables
		int i;
		int j;
		int x = 1;
		int y = 1;

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
							printf(" %d", x);
							x++;
						}
						//If not, print frame character
						else
						{
							line[j] = '#';
							printf(" %c", line[j]);
						}
				}
				//Check if first or last position on y axis
				else if (j == 0 || j == lineLength - 1)
				{
					//Check if first position on y axis and position is not part of frame, print coordinate if so
					if (j == 0 && i % 4 != 0)
					{
						printf(" %d", y);
						y++;
					}
					//If not, print frame character
					else
					{
						line[j] = '#';
						printf(" %c", line[j]);
					}
				}
				//Check if position is inside frame, print frame character if so
				else if (i % 4 == 0 || j % 4 == 0)
				{
					line[j] = '#';
					printf(" %c", line[j]);
				}
				//If not, print empty space
				else
				{
					line[j] = ' ';
					printf(" %c", line[j]);
				}
			}
			//Print new line
			printf("\n");
		}
}

int main(int argc, char **argv)
{
	//Declare required variables
	int size;
	int lineLength;

	//Prompt user for grid size
	printf("Input grid size:\n");
	scanf("%d", &size);

	//Calculate line size based on user input
	lineLength = (size + (3 * size)) + 1;
	char line[lineLength];

	//Execute print grid function
	printGrid(line, lineLength, size);

}
