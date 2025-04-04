#include <stdio.h>
#include <math.h>

double qinjiushao(double a[], int n, double x) {
    double result = a[0];
    for (int i = 1; i < n; i++) {
        result = result * x + a[i];
    }
    return result;
}

int main() {
    int n;
    printf("请输入多项式的最高次数: ");
    scanf("%d", &n);

    double a[n + 1];
    printf("请输入多项式系数：");
    for (int i = 0; i < n+1; i++) {
        scanf("%lf", &a[i]);
    }

    double x;
    printf("请输入 x 的值: ");
    scanf("%lf", &x);

    double result = qinjiushao(a, n + 1, x);
    printf("当x=%.1f时，多项式值为：%.2f\n", x, result);
    
    return 0;
}