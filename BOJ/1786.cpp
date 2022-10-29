#include <iostream>
#include <string>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> getLength(string N) {
	int n = N.size();
	vector<int> pi(n, 0);

	int begin = 1, matched = 0;
	while (begin + matched < n) {
		if (N[matched + begin] == N[matched]) {
			++matched;
			pi[begin + matched - 1] = matched;
		}
		else {
			if (matched == 0) {
				++begin;
			}
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}

	return pi;
}

vector<int> getBegins(string H, string N, vector<int>& pi) {
	int n = H.size();
	int m = N.size();

	vector<int> res;
	int begin = 0, matched = 0;
	while (begin + m <= n) {
		if (matched < m && H[begin + matched] == N[matched]) {
			++matched;
			if (matched == m) res.push_back(begin + 1);
		}
		else {
			if (matched == 0) {
				++begin;
			} else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}

	return res;
}

int main() {
	string H, N;

	getline(cin, H);
	getline(cin, N);

	vector<int> pi = getLength(N);
	vector<int> result = getBegins(H, N, pi);

	cout << result.size() << endl;
	for(int res: result) printf("%d\n", res);

	return 0;
}
