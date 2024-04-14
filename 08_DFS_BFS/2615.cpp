#include <iostream>
#define MAX 19
using namespace std;

char g[MAX][MAX];
int moving[4][2] = { {0,1},{1,0},{1,1},{-1,1} };
bool visited_dfs[MAX][MAX][4][2];

char dfs(int r, int c, int dir, char color, int cnt) {
	visited_dfs[r][c][dir][color - '1'] = true;
	int nR = r + moving[dir][0];
	int nC = c + moving[dir][1];
	if (nR < 0 || nR >= MAX || nC < 0 || nC >= MAX || g[nR][nC] != color) {
		if (cnt == 5) {
			return color;
		}
		else {
			return '0';
		}
	}
	return dfs(nR, nC, dir, color, cnt + 1);
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < MAX; i++) {
		for(int j=0; j<MAX;j++){
			cin>>g[i][j];
		}
	}
	
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			if (g[j][i] != '0') {
				for (int dir = 0; dir < 4; dir++) {
					if (visited_dfs[j][i][dir][g[j][i] - '1'])continue;
					if (dfs(j, i, dir, g[j][i], 1) != '0') {
						cout << g[j][i] << '\n' << j + 1 << ' ' << i + 1;
						return 0;
					}
				}
			}
		}
	}
		
	cout << 0;
	return 0;
}