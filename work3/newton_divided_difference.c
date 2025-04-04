#include <stdio.h>

#define MAX_POINTS 10

// 计算均差表
void computeDividedDifferences(double x[], double y[][MAX_POINTS], int n) {
    for (int i = 1; i < n; i++)
        for (int j = 0; j < n - i; j++)
            y[j][i] = (y[j + 1][i - 1] - y[j][i - 1]) / (x[j + i] - x[j]);
}

// 牛顿插值计算
double newtonInterpolation(double x[], double y[][MAX_POINTS], int n, double value) {
    double result = y[0][0], term = 1.0;
    for (int i = 1; i < n; i++) {
        term *= (value - x[i - 1]);
        result += term * y[0][i];
    }
    return result;
}

int main() {
    int n;
    double x[MAX_POINTS], y[MAX_POINTS][MAX_POINTS], value;

    // 输入数据
    printf("输入点的数量: ");
    scanf("%d", &n);

    printf("输入 x 和 f(x) 的值:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d]: ", i + 1);
        scanf("%lf", &x[i]);
        printf("f(x[%d]): ", i + 1);
        scanf("%lf", &y[i][0]);
    }

    // 计算和显示均差表
    computeDividedDifferences(x, y, n);

    // 打印均差表
    printf("\n均差表:\nx           f(x)       ");
    for (int i = 1; i < n; i++) printf("%d阶差商     ", i);
    
    printf("\n");
    for (int i = 0; i <= n; i++) printf("------------");
    
    for (int i = 0; i < n; i++) {
        printf("\n%-11.5f%-12.5f", x[i], y[i][0]);
        for (int j = 1; j <= i; j++) printf("%-12.5f", y[i-j][j]);
    }

    // 插值计算
    printf("\n\n输入要插值的 x 值: ");
    scanf("%lf", &value);
    printf("插值结果 P(%g) = %.5f\n", value, newtonInterpolation(x, y, n, value));
    return 0;
}