#include <stdio.h>

#define MAX_POINTS 10

// 计算差分表
void computeDifferenceTable(double y[][MAX_POINTS], int n) {
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
        }
    }
}

// 差分形式的牛顿插值计算
double newtonDifferenceInterpolation(double x0, double h, double y[][MAX_POINTS], int n, double value) {
    double t = (value - x0) / h;
    double result = y[0][0];
    double term = 1.0;

    for (int i = 1; i < n; i++) {
        term *= (t - (i - 1)) / i;
        result += term * y[0][i];
    }

    return result;
}

int main() {
    int n;
    double x0, h, y[MAX_POINTS][MAX_POINTS], value;

    printf("输入点的数量: ");
    scanf("%d", &n);

    printf("输入初始点 x0 和步长 h: ");
    scanf("%lf %lf", &x0, &h);

    printf("输入函数值 f(x) 的值:\n");
    for (int i = 0; i < n; i++) {
        printf("f(x[%d]): ", i);
        scanf("%lf", &y[i][0]);
    }

    // 计算差分表
    computeDifferenceTable(y, n);

    printf("\n差分表:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            printf("%lf ", y[i][j]);
        }
        printf("\n");
    }

    printf("\n输入要插值的 x 值: ");
    scanf("%lf", &value);

    // 计算插值结果
    double result = newtonDifferenceInterpolation(x0, h, y, n, value);
    printf("插值结果 P(%.2lf) = %.6lf\n", value, result);

    return 0;
}