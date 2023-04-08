#include <stdio.h>
int main(int argc, char **argv)
{
	int size;
	int i;

	printf("Input grid size:\n");
	scanf("%d", &size);

	char line[(size * 2) + 1];

	for (i = 0; i < sizeof(line); i++)
	{
		line[i] = '#';
	}

	printf("%s\n", line);

}
