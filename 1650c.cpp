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

/* *** */

bool comp(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int input(map<int, int>& index, vector<int>& weights, vector<pair<int, int>>& wc) {
	int n, m;
	scanf("");
	scanf("%d %d", &n, &m);
	for (int j = 0; j < m; ++j) {
		int x, w;
		scanf("%d %d", &x, &w); // 좌표, 가중치
		weights.push_back(w);

		wc.push_back(make_pair(w, x));
		index.insert({ x, j });
	}

	return n;
}

int printTotal(vector<int>& weights, int n) {
	sort(weights.begin(), weights.end());
	int total = accumulate(weights.begin(), weights.begin() + (2 * n), 0);
	printf("%d\n", total);
}

int main() {
	int tc;

	cin >> tc;

	for (int i = 0; i < tc; ++i) {
		map<int, int> index;
		vector<int> weights;
		vector<pair<int, int>> wc;

		int n = input(index, weights, wc);
		printTotal(weights, n);
		
		sort(wc.begin(), wc.end());
		while (wc.size() > 2 * n) {
			wc.pop_back();
		}

		sort(wc.begin(), wc.end(), comp);

		int len = n;
		int left = 0;
		int right = 2 * n - 1;
		for (int j = 0; j < len; ++j) {
			int l = wc[left++].second;
			int r = wc[right--].second;
			printf("%d %d\n", index.find(l)->second + 1, index.find(r)->second + 1);
		}

		printf("\n");
	}

	return 0;
}
