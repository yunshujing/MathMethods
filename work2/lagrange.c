#include <stdio.h>

double lagrange(double x[], double y[], int n, double xi) {
    double result = 0.0;
    for (int i = 0; i < n; i++) {
        double term = y[i];
        for (int j = 0; j < n; j++) {
            if (j != i) {
                term *= (xi - x[j]) / (x[i] - x[j]);
            }
        }
        result += term;
    }
    return result;
}

int main() {
    int n;
    printf("请输入数据点的数量: ");
    scanf("%d", &n);

    double x[n], y[n];
    
    // 输入数据点
    printf("请输入数据点的 x 值:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d]: ", i);
        scanf("%lf", &x[i]);
    }

    printf("请输入数据点的 y 值:\n");
    for (int i = 0; i < n; i++) {
        printf("y[%d]: ", i);
        scanf("%lf", &y[i]);
    }

    double xi;
    printf("请输入要插值的 x 值: ");
    scanf("%lf", &xi);
    
    // 计算并输出结果
    printf("插值结果 f(%.1f) = %.3f\n", xi, lagrange(x, y, n, xi));
    
    return 0;
}