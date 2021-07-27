#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
#include <cstdlib>

using namespace std;

#define INF 987654321

typedef long long ll;

/* *** */

int t;
int numbers[] = {1, 5, 10, 50, 100, 500, 1000};
int M, D, C, L, X, V, I;
bool CM, CD, XC, XL, IX, IV;


void numberToRoma(int n) {
    M = n / 1000;
    n %= 1000;
    if (n >= 900) {
        n -= 900;
        CM = true;
    }

    D = n / 500;
    n %= 500;
    if (n >= 400) {
        n -= 400;
        CD = true;
    }

    C = n / 100;
    n %= 100;
    if (n >= 90) {
        n -= 90;
        XC = true;
    }

    L = n / 50;
    n %= 50;
    if (n >= 40) {
        n -= 40;
        XL = true;
    }

    X = n / 10;
    n %= 10;
    if (n >= 9) {
        n -= 9;
        IX = true;
    }

    V = n / 5;
    n %= 5;
    if (n >= 4) {
        n -= 4;
        IV = true;
    }

    I = n;

    for (int j = 0; j < M; ++j) {
        printf("M");
    }
    if (CM) printf("CM");
    for (int j = 0; j < D; ++j) {
        printf("D");
    }
    if (CD) printf("CD");
    for (int j = 0; j < C; ++j) {
        printf("C");
    }
    if (XC) printf("XC");
    for (int j = 0; j < L; ++j) {
        printf("L");
    }
    if (XL) printf("XL");
    for (int j = 0; j < X; ++j) {
        printf("X");
    }
    if (IX) printf("IX");
    for (int j = 0; j < V; ++j) {
        printf("V");
    }
    if (IV) printf("IV");
    for (int j = 0; j < I; ++j) {
        printf("I");
    }
    printf("\n");
    CM = CD = XC = XL = IX = IV = 0;
}

void romaToNumber(char n[]) {
    int total = 0;
    for (int i = 0; n[i] != '\0'; ++i) {
        if (n[i] == 'C' && n[i + 1] == 'M') {
            total += 900;
            ++i;
            continue;
        }
        if (n[i] == 'C' && n[i + 1] == 'D') {
            total += 400;
            ++i;
            continue;
        }
        if (n[i] == 'X' && n[i + 1] == 'C') {
            total += 90;
            ++i;
            continue;
        }
        if (n[i] == 'X' && n[i + 1] == 'L') {
            total += 40;
            ++i;
            continue;
        }
        if (n[i] == 'I' && n[i + 1] == 'X') {
            total += 9;
            ++i;
            continue;
        }
        if (n[i] == 'I' && n[i + 1] == 'V') {
            total += 4;
            ++i;
            continue;
        }
        if (n[i] == 'M') {
            total += 1000;
            continue;
        }
        if (n[i] == 'D') {
            total += 500;
            continue;
        }
        if (n[i] == 'C') {
            total += 100;
            continue;
        }
        if (n[i] == 'L') {
            total += 50;
            continue;
        }
        if (n[i] == 'X') {
            total += 10;
            continue;
        }
        if (n[i] == 'V') {
            total += 5;
            continue;
        }
        if (n[i] == 'I') {
            total += 1;
            continue;
        }
    }

    printf("%d\n", total);
}

int main() {
    cin >> t;

    for (int i = 0; i < t; ++i) {
        char input[1000];
        
        scanf("%s", &input);

        if ('0' <= input[0] && input[0] <= '9') {
            numberToRoma(atoi(input));
        }
        else
            romaToNumber(input);
    }

    return 0;
}
