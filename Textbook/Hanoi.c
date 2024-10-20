#include <stdio.h>

void hanoi(int a, char ch1, char ch2, char ch3);
void move(char x, char y);

int s = 0;

int main()
{
    int m;
    if (scanf("%d", &m) != 1) 
    {
        printf("Invalid input\n");
        return -1;
    }
    hanoi(m, 'A', 'B', 'C');
    printf("Total moves: %d\n", s);
    return 0;
}

void hanoi(int a, char ch1, char ch2, char ch3)
{
    if (a == 1)
    {
        move(ch1, ch3);
    }
    else
    {
        hanoi(a - 1, ch1, ch3, ch2);
        move(ch1, ch3);
        hanoi(a - 1, ch2, ch1, ch3);
    }
}

void move(char x, char y)
{
    printf("Move disk from %c to %c\n", x, y);
    s++;
}
