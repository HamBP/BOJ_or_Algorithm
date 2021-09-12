#include <iostream>
#include <cstdio>
#include <utility>
#include <algorithm>
#include <cmath>

using namespace std;

int target;
bool error[10];

int getCount(int n) {
    int cnt = 0;

    if (n == 0) {
        if(error[0]) return 1000000;
        return 1;
    }

    while (n) {
        ++cnt;
        int component = n % 10;
        if (error[component]) return 1000000;
        n /= 10;
    }
    
    return cnt;
}

int main() {
    int n;

    cin >> target;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int input;
        scanf("%d", &input);
        error[input] = true;
    }

    int result = abs(target - 100);
    for (int i = 0; i < 1000000; ++i) {
        int cnt = getCount(i);
        result = min(result, cnt + abs(target - i));
    }
    cout << result << endl;

    return 0;
}
