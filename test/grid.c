#include <stdio.h>

void printGrid(char line[], int lineLength, int size)
{
		int i;
		int j;
		int x = 1;
		int y = 1;

		for (i = 0; i < lineLength; i++)
		{
			for (j = 0; j < lineLength; j++)
			{
				if (i == 0 || i == lineLength - 1)
				{
						if (i == 0 && j % 4 != 0)
						{
							printf(" %d", x);
							x++;
						}
						else
						{
							line[j] = '#';
							printf(" %c", line[j]);
						}
				}
				else if (j == 0 || j == lineLength - 1)
				{
					if (j == 0 && i % 4 != 0)
					{
						printf(" %d", y);
						y++;
					}
					else
					{
						line[j] = '#';
						printf(" %c", line[j]);
					}
				}
				else if (i % 4 == 0 || j % 4 == 0)
				{
					line[j] = '#';
					printf(" %c", line[j]);
				}
				else
				{
					line[j] = ' ';
					printf(" %c", line[j]);
				}
			}
			printf("\n");
		}
}

int main(int argc, char **argv)
{
	int size;
	int lineLength;

	printf("Input grid size:\n");
	scanf("%d", &size);

	lineLength = (size + (3 * size)) + 1;
	char line[lineLength];

	printGrid(line, lineLength, size);

}
