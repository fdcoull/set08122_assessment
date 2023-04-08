#include <stdio.h>

void printGrid(char line[], int lineLength, int size)
{
		int i;
		int j;
		int grid[size][size];

		for (i = 0; i < lineLength; i++)
		{
			for (j = 0; j < lineLength; j++)
			{
				if (i == 0 || i == lineLength - 1 || j == 0 || j == lineLength - 1)
				{
					line[j] = '#';
				}
				else if (i % 4 == 0 || j % 4 == 0)
				{
					line[j] = '#';
				}
				else
				{
					line[j] = ' ';
				}
			}
			printf("%s\n", line);
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
