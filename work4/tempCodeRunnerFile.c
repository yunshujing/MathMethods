#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void leastSquaresFit(double x[], double y[], double w[], int n, double *a0, double *a1);

int main() {
    int n;
    double *x, *y, *w;
    double a0, a1;
    
    printf("请输入数据点数量: ");
    scanf("%d", &n);
    
    x = (double*)malloc(n * sizeof(double));
    y = (double*)malloc(n * sizeof(double));
    w = (double*)malloc(n * sizeof(double));
    
    if (x == NULL || y == NULL || w == NULL) {
        printf("内存分配失败!\n");
        return 1;
    }
    
    printf("请输入 %d 个数据点(x y w):\n", n);
    for (int i = 0; i < n; i++) {
        printf("点 %d (x y 权重): ", i+1);
        scanf("%lf %lf %lf", &x[i], &y[i], &w[i]);
    }

    leastSquaresFit(x, y, w, n, &a0, &a1);
    printf("\n拟合直线方程为: S*(x) = %.4lf + %.4lfx\n", a0, a1);
    
    free(x);
    free(y);
    free(w);
    return 0;
}

void leastSquaresFit(double x[], double y[], double w[], int n, double *a0, double *a1) {
    double G00 = 0.0;
    double G01 = 0.0;
    double G11 = 0.0;
    double d0 = 0.0;
    double d1 = 0.0;
    
    printf("\n计算过程:\n");
    printf("数据点:\n");
    printf("x\t| y\t| 权重(w)\n");
    printf("--------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%.1lf\t| %.1lf\t| %.1lf\n", x[i], y[i], w[i]);
    }
    printf("\n");
    
    for (int i = 0; i < n; i++) {
        G00 += w[i];
        G01 += w[i] * x[i];
        G11 += w[i] * x[i] * x[i];
        d0 += w[i] * y[i];
        d1 += w[i] * x[i] * y[i];
    }
    
    printf("(φ₀,φ₀) = Σ wᵢ = %.1lf\n", G00);
    printf("(φ₀,φ₁) = (φ₁,φ₀) = Σ wᵢxᵢ = %.1lf\n", G01);
    printf("(φ₁,φ₁) = Σ wᵢxᵢ² = %.1lf\n", G11);
    printf("(φ₀,f) = Σ wᵢyᵢ = %.1lf\n", d0);
    printf("(φ₁,f) = Σ wᵢxᵢyᵢ = %.1lf\n", d1);
    
    printf("\n线性方程组:\n");
    printf("%.1lfa₀ + %.1lfa₁ = %.1lf\n", G00, G01, d0);
    printf("%.1lfa₀ + %.1lfa₁ = %.1lf\n", G01, G11, d1);
    
    double det = G00 * G11 - G01 * G01;
    
    if (fabs(det) < 1e-10) {
        printf("警告: 方程组可能无解或有无穷多解\n");
        *a0 = *a1 = 0.0;
        return;
    }
    
    *a0 = (d0 * G11 - d1 * G01) / det;
    *a1 = (G00 * d1 - G01 * d0) / det;
    
    printf("\n解得: a₀ = %.4lf, a₁ = %.4lf\n", *a0, *a1);
}