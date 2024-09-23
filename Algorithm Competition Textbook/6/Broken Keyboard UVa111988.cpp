#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct Node {
    char s;
    Node *next;
    Node(char c) : s(c), next(NULL) {}
};

Node *head, *pNow, *pRear;

void create() {
    head = new Node(0); // Dummy head node
    pNow = pRear = head;
}

int main() {
    char ch[100500];
    while (scanf("%s", ch) != EOF) {
        create();
        int str = strlen(ch);
        for (int i = 0; i < str; i++) 
        {
            if (ch[i] == '[') 
            {
                pNow = head;
            } else if (ch[i] == ']') 
            {
                pNow = pRear;
            } else {
                Node *tmp = new Node(ch[i]);
                tmp->next = pNow->next;
                pNow->next = tmp;
                pNow = tmp;
                if (pNow->next == NULL) 
                {
                    pRear = pNow;
                }
            }
        }
        for (Node *p = head->next; p != NULL; p = p->next) {
            printf("%c", p->s);
        }
        printf("\n");
    }
    return 0;
}