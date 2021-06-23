// DP 처음 시작할 때

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <array>
#include <stdlib.h>
#include <string.h>

using namespace std;

int cash[2][45];

int fibo0(int n) {
	// 기저
	if (n == 0) {
		cash[0][n] = 1;
		return 1;
	}
	if (n == 1) {
		cash[0][n] = 0;
		return 0;
	}

	// 메모이제이션
	if (cash[0][n] != -1) {
		return cash[0][n];
	}
	
	cash[0][n] = cash[0][n - 2] + cash[0][n - 1];
	return cash[0][n];
}

int fibo1(int n) {
	// 기저
	if (n == 0) {
		cash[1][n] = 0;
		return 0;
	}
	if (n == 1) {
		cash[1][n] = 1;
		return 1;
	}

	// 메모이제이션
	if (cash[1][n] != -1) {
		return cash[1][n];
	}

	cash[1][n] = cash[1][n - 2] + cash[1][n - 1];
	return cash[1][n];
}
int main()
{
	int t;
	int n;

	memset(cash, -1, sizeof(cash));

	cin >> t;

	for (int i = 0; i < 41; ++i) {
		fibo0(i);
		fibo1(i);
	}

	for (int i = 0; i < t; ++i) {
		cin >> n;
		cout << cash[0][n] << " " << cash[1][n] << endl;
	}
}
