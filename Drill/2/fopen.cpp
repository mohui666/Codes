#include <stdio.h>

int main()
{
	FILE *fin,*fout;
	fin = fopen("data.in","rb");
	fout = fopen("data.out","wb");
	int x[100],i=0;
	while(fscanf(fin,"%d",&x[i])==1)
	{
		i++;		
	}
	i=0;
	while(i<100)
	{
		i++;
		fprintf(fout,"%d.%d\n",i,x[i]);
	}
	
	fclose(fin);
	fclose(fout);
	return 0;
}

