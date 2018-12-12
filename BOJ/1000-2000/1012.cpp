// DFS 처음 사용할 때

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <array>
#include <vector>
#include <queue>
#include <list>

typedef long long int LLI;

using namespace std;


bool bachu[50][50];
int row, column, n;

bool DFS(int y, int x)
{
	if (!bachu[y][x]) return false;

	bachu[y][x] = false;

	if (y > 0) DFS(y - 1, x);
	if (y < row - 1) DFS(y + 1, x);
	if (x > 0) DFS(y, x - 1);
	if (x < column - 1) DFS(y, x + 1);

	return true;
}

int main()
{
	int T;
	int y, x;
	int cnt = 0;

	cin >> T;

	for (int i = 0; i < T; ++i) {
		cnt = 0;
		memset(bachu, 0, sizeof(bachu));
		cin >> row >> column >> n;
		for (int j = 0; j < n; ++j) {
			cin >> y >> x;
			bachu[y][x] = true;
		}
		for (int j = 0; j < row; ++j) {
			for (int k = 0; k < column; ++k) {
				if (DFS(j, k)) cnt++;
			}
		}
		cout << cnt << endl;
	}
	
	return 0;
}
