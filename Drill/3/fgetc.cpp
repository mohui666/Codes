#include <stdio.h>

int main()
{
	FILE *file = fopen("input.txt","rb");
	int c;
	while((c=fgetc(file))!=EOF)
	{
		printf("%c",c);
	}
	fclose(file);
	return 0;
}

