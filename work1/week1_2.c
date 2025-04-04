#include <stdio.h>

int main() {
    int n;
    printf("请输入数字个数：");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("输入无效\n");
        return 1;
    }
    
    double num, sum = 0;
    double max_val, min_val;
    
    printf("请输入%d个浮点数：\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &num);
        sum += num;
        
        if (i == 0) {
            max_val = min_val = num;
        } else {
            if (num > max_val) max_val = num;
            if (num < min_val) min_val = num;
        }
    }
    
    printf("总和：%.2f\n", sum);
    printf("最大值：%.2f\n", max_val);
    printf("最小值：%.2f\n", min_val);
    
    return 0;
}
