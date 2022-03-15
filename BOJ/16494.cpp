#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <set>
#include <numeric>
#include <map>

using namespace std;

typedef long long ll;

#define INF 1987654321

int dr[] = { -1, 1, 0, 0, 0, 0 };
int dc[] = { 0, 0, -1, 1, 0, 0 };
int dh[] = { 0, 0, 0, 0, -1, 1 };

/* *** */

int n, m;
int arr[25];

int getSumFromRange(int left, int right) {
	int result = -2000;
	for (int i = left; i < right; ++i) {
		if (left != 0) result = max(arr[i] - arr[left - 1], result);
		else result = max(arr[i], result);
	}
	return result;
}

int getTotal(vector<int>& lefts) {
	int result = 0;
	for (int i = 0; i < m; ++i) {
		result += getSumFromRange(lefts[i], lefts[i + 1]);
	}
	return result;
}

int dfs(vector<int>& lefts) {
	if (lefts.size() == m) {
		lefts.push_back(n);
		int result = getTotal(lefts);
		lefts.pop_back();
		return result;
	}

	int start = 0;
	if(lefts.size()) start = lefts.back() + 1;
	
	int result = -2000;
	for (int left = start; left < n; ++left) {
		lefts.push_back(left);
		result = max(dfs(lefts), result);
		lefts.pop_back();
	}
	return result;
}

int main() {
	cin >> n >> m;
	
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
		if (i > 0) arr[i] += arr[i - 1];
	}

	vector<int> lefts;
	int result = dfs(lefts);
	cout << result << endl;

	return 0;
}
