#include <stdio.h>

int main() {
    int n;
    printf("���������ָ�����");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("������Ч\n");
        return 1;
    }
    
    double num, sum = 0;
    double max_val, min_val;
    
    printf("������%d����������\n", n);
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
    
    printf("�ܺͣ�%.2f\n", sum);
    printf("���ֵ��%.2f\n", max_val);
    printf("��Сֵ��%.2f\n", min_val);
    
    return 0;
}
