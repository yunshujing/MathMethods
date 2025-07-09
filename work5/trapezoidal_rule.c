// 梯形公式积分法实现（优化版）
// 支持选择不同被积函数和参数
// 作者：AI助手
#include <stdio.h>
#include <math.h>

// 题目1: f(x) = x / (4 + x^2), 积分区间[0,1], n=8
// 题目2: f(x) = sqrt(x), 积分区间[0,1], n=4

double func1(double x) {
    return x / (4 + x * x);
}
double func2(double x) {
    return sqrt(x);
}
// 梯形公式
// a: 积分下限, b: 积分上限, n: 等分数, f: 被积函数指针
double trapezoidal_rule(double a, double b, int n, double (*f)(double)) {
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    for (int i = 1; i < n; i++) {
        sum += 2 * f(a + i * h);
    }
    return sum * h / 2;
}
int main() {
    int choice;
    printf("请选择题号（1或2）：\n");
    scanf("%d", &choice);
    double result = 0;
    if (choice == 1) {
        result = trapezoidal_rule(0, 1, 8, func1);
        printf("题1 梯形公式积分近似值为：%.9lf\n", result);
    } else if (choice == 2) {
        result = trapezoidal_rule(0, 1, 4, func2);
        printf("题2 梯形公式积分近似值为：%.9lf\n", result);
    } else {
        printf("输入有误！\n");
    }
    return 0;
}
