// 오차 범위를 줄이기 위해 6자리 이상 출력 필요

#include <stdio.h>

int main()
{
    double A, B;
    scanf("%lf %lf", &A, &B);
    printf("%.9lf", A/B);
    
    return 0;
}
