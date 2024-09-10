#include <stdio.h>

int main()
{
	char buf[100];
	FILE *fin = fopen("input.txt","rb");
	fgets(buf,100,fin);
	printf("%s",buf);
	return 0;
}

