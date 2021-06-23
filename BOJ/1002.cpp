#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <array>
#include <vector>

typedef long long int LLI;

#define MIN(X, Y) (X > Y) ? Y : X
#define MAX(X, Y) (X > Y) ? X : Y

using namespace std;

int main() 
{
	int T;
	int x1, y1, r1;
	int x2, y2, r2;

	cin >> T;

	for (int i = 0; i < T; ++i) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		double dis = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2)); // 거리

	   // 두 원이 일치할 때
		if (r1 == r2 && x1 == x2 && y1 == y2) {
			cout << -1 << endl;
			continue;
		}

		// 두 점에서 만날 때 -> 삼각형을 이룬다.
		if (r1 + r2 > dis && r2 + dis > r1 && dis + r1 > r2) {
			cout << 2 << endl;
			continue;
		}

		// 만나지 않을 때 -> 삼각형을 이루지 못 함
		if (r1 + r2 < dis || r2 + dis < r1 || dis + r1 < r2) {
			cout << 0 << endl;
			continue;
		}

		// 접할 때 -> 세 점이 직선상에 있음
		if (r1 + r2 == dis || r2 + dis == r1 || dis + r1 == r2) {
			cout << 1 << endl;
			continue;
		}
	}

	return 0;
}
