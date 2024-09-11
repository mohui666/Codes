#include <bits/stdc++.h>
using namespace std;
int n, m, kase, id[15][15], id2[15][15];
char a[15][15];
int main() {
	while(scanf("%d", &n) && n != 0) {
		scanf("%d", &m);
		memset(id, 0, sizeof(id));
		memset(id2, 0, sizeof(id2));
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				cin >> a[i][j];
			}
		}
		int ids = 0;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				if(a[i][j] != '*' && (j == 1 || a[i][j - 1] == '*' || i == 1 || a[i - 1][j] == '*')) {
					id[i][j] = ++ids, id2[i][j] = ids;
				}
			}
		}
		kase++;
		if(kase > 1) printf("\n");
		printf("puzzle #%d:\nAcross\n", kase);
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				if(id[i][j] != 0) {
					printf("%3d.", id[i][j]);
					for(int k = j; k <= m; k++) {
						if(a[i][k] == '*') break;
						cout << a[i][k];
						id[i][k] = 0;
					}
					printf("\n");
				}
			}
		}
		printf("Down\n");
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				if(id2[i][j] != 0) {
					printf("%3d.", id2[i][j]);
					for(int k = i; k <= n; k++) {
						if(a[k][j] == '*') break;
						cout << a[k][j];
						id2[k][j] = 0;
					}
					printf("\n");
				}
			}
		}
	}
	return 0;
} 
