#include <iostream>
#include <algorithm>

using namespace std;

int rgb[3][3];
int n;

int main() {
    int in[3];

    cin >> n;

    cin >> rgb[0][0] >> rgb[1][1] >> rgb[2][2];

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (i != j) rgb[i][j] = 1000;

    for (int i = 1; i < n - 1; ++i) {
        scanf("%d %d %d", &in[0], &in[1], &in[2]);

        for (int j = 0; j < 3; ++j) {
            int x[3];
            for (int k = 0; k < 3; ++k) {
                x[k] = 1000 * 1000;
                for (int h = 0; h < 3; ++h) 
                    if(k != h) 
                        x[k] = min(x[k], in[k] + rgb[j][h]);
            }

            for (int k = 0; k < 3; ++k) rgb[j][k] = x[k];
        }
    }

    int m = 1000 * 1000;

    scanf("%d %d %d", &in[0], &in[1], &in[2]);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                if (i != k && j != k) m = min(m, in[k] + rgb[i][j]);
            }
        }
    }

    cout << m;

    return 0;
}
