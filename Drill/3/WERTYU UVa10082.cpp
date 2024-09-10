#include <stdio.h>

int main()
{
	char s[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
	int i =0, c=0;
	while((c=getchar())!=EOF)
	{
		for(i=1;s[i]&&s[i]!=c;i++);
		if(s[i])
		{
			putchar(s[i-1]);
		}
		else
		{
			putchar(c);
		}
	
	}

	return 0;
}

