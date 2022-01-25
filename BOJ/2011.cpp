#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING

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

using namespace std;

typedef long long ll;

#define INF 1987654321

/* *** */

ll cache[10005];
char code[10005];

int getNumber(int cur) {
	int result = (code[cur - 1] - '0') * 10 + (code[cur] - '0');

	return result;
}

bool isPosible(int cur) {
	if (code[cur + 1] == '0') return false;
	if (code[cur - 1] == '0') return false;
	return getNumber(cur) < 27;
}

bool validate(int len) {
	if (code[0] == '0') return false;
	for (int i = 0; i < len; ++i) {
		if (code[i] == '0' && code[i + 1] == '0') return false;
		if (code[i] > '2' && code[i + 1] == '0') return false;
	}
	return true;
}

ll dp(int cur) {
	if (cur == 0)
		return 1;

	if (code[cur] == '0') return dp(cur - 1);

	if (cur == 1) {
		if (isPosible(cur)) return 2;
		else 1;
	}

	ll& ret = cache[cur];
	if (ret != -1) return ret;


	if (isPosible(cur)) ret = (dp(cur - 2) + dp(cur - 1)) % 1000000;
	else ret = dp(cur - 1);

	return ret;
}

int main() {
	fgets(code, 10005, stdin);
	int len = strlen(code) - 1;
	code[len] = 0;

	memset(cache, -1, sizeof(cache));

	if (validate(len)) cout << dp(len - 1) << endl;
	else cout << 0 << endl;

	return 0;
}
