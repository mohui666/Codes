#include <stdio.h>
#include <string.h>

char puzzle[10][10];

int main(){
    char c;
    int kase = 0;
    
    while((c = getchar()) && c != 'Z')
    {
        int x, y;
        memset(puzzle, 0, sizeof(puzzle));
        puzzle[0][0] = c;
        if(c == ' ') x = y = 0;
        for(int i=0; i<5; i++)
        {
            for(int j=0; j<5; j++)
            {
                if(i!=0 || j!=0)
                {
                    puzzle[i][j] = c = getchar();
                    if(c == ' ')
                    {
                        x = i;
                        y = j;
                    }
                }
            }

            getchar();
        }

        char cmds[100];
        memset(cmds, 0, sizeof(cmds));
        for(int i=0; c!='0'; )
        {
            c = getchar();
            if(c == ' ') continue;
            cmds[i++] = c;
        }
        getchar(); 

        int flag = 0, len = strlen(cmds);
        for(int i=0; i<len; i++)
        {
            c = cmds[i];
            switch(c)
            {
                case 'A':
                    puzzle[x][y] = puzzle[x-1][y];
                    puzzle[x-1][y] = ' ';
                    x--; break;
                case 'B':
                    puzzle[x][y] = puzzle[x+1][y];
                    puzzle[x+1][y] = ' ';
                    x++; break;
                case 'L':
                    puzzle[x][y] = puzzle[x][y-1];
                    puzzle[x][y-1] = ' ';
                    y--; break;
                case 'R':
                    puzzle[x][y] = puzzle[x][y+1];
                    puzzle[x][y+1] = ' ';
                    y++; break;
                case '0':
                    flag = 1; break;
                default:
                    break;
            } 
            if(flag) break;
            
            if(x<0 || x>4 || y<0 || y>4)
            {
                flag = 2;
                break;
            }
        }

        if(kase) printf("\n");
        printf("Puzzle #%d:\n", ++kase);
        if(flag == 2)
        {
            printf("This puzzle has no final configuration.\n");
            continue;
        }
        else
        {
            for(int i=0; i<5; i++)
            {
                for(int j=0; j<5; j++)
                {
                    printf("%c", puzzle[i][j]);
                    if(j < 4) printf(" ");
                }
                printf("\n");
            }
        }
    }
    return 0;
}