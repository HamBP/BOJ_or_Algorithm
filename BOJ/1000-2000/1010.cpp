// 조합 공식 

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


int newArr[1000];

int main()
{
	int T;
	int n, m;
	double result;

	cin >> T;

	for (int i = 0; i < T; ++i) {
		result = 1;
		cin >> n >> m;
		for (int j = 0; j < n; ++j) {
			result *= (m - j);
		}
		for (int j = 1; j <= n; ++j) {
			result /= j;
		}
		printf("%.0lf \n", result);
	}
	
	return 0;
}
