// 어린왕자
// 한 지점만 원 내부에 있을 경우 +1

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

/* 뚜루루뚜루 */



int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int c1x, c1y;
		int c2x, c2y;
		cin >> c1x >> c1y >> c2x >> c2y;
		int n;
		cin >> n;
		int cnt = 0;
		for (int j = 0; j < n; ++j) {
			bool c1 = false, c2 = false;
			int x, y, r;
			double dist;
			cin >> x >> y >> r;
			dist = sqrt(pow(c1x - x, 2) + pow(c1y - y, 2));
			if (dist < r) c1 = true;
			dist = sqrt(pow(c2x - x, 2) + pow(c2y - y, 2));
			if (dist < r) c2 = true;
			if (c1 ^ c2) cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}
