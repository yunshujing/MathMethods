#include <stdio.h>
#include <math.h>
// 定义第一个被积函数 f(x) = x / (4 + x * x)
double f1(double x) {
    return x / (4 + x * x);
}
// 定义第二个被积函数 f(x) = sqrt(x)
double f2(double x) {
    return sqrt(x);
}
// 梯形公式
double trapezoidalRule(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += 2 * f(x);
    }
    return (h / 2) * sum;
}
// 辛普森公式，要求n为偶数
double simpsonRule(double (*f)(double), double a, double b, int n) {
    if (n % 2 != 0) {
        printf("辛普森公式要求n为偶数\n");
        return -1;
    }
    double h = (b - a) / n;
    double sum1 = 0, sum2 = 0;
    for (int k = 0; k < n / 2; k++) {
        double x1 = a + (2 * k + 1) * h;
        sum1 += f(x1);
    }
    for (int k = 1; k < n / 2; k++) {
        double x2 = a + 2 * k * h;
        sum2 += f(x2);
    }
    return (h / 3) * (f(a) + 4 * sum1 + 2 * sum2 + f(b));
}
//0 1
//8
//1 9
//4
int main() {
    // 计算第一个积分
    double a1,b1;
    int n1;
    scanf("%lf %lf %d",&a1,&b1,&n1); 
    double resultTrapezoidal1 = trapezoidalRule(f1, a1, b1, n1);
    double resultSimpson1 = simpsonRule(f1, a1, b1, n1);
    printf("梯形公式计算结果: %.9lf\n", resultTrapezoidal1);
    printf("辛普森公式计算结果: %.9lf\n", resultSimpson1);
    // 计算第二个积分
    double a2,b2;
    int n2;
    scanf("%lf %lf %d",&a2,&b2,&n2); 
    double resultTrapezoidal2 = trapezoidalRule(f2, a2, b2, n2);
    double resultSimpson2 = simpsonRule(f2, a2, b2, n2);
    printf("梯形公式计算结果: %.9lf\n", resultTrapezoidal2);
    printf("辛普森公式计算结果: %.9lf\n", resultSimpson2); 
    return 0;
}