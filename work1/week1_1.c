#include <stdio.h>

int str_len(char *s) {
    int len = 0;
    while (s[len] != '\0') len++;
    return len;
}

int find(char *s, char *t) {
    int s_len = str_len(s);
    int t_len = str_len(t);
    
    for (int i = 0; i <= s_len - t_len; i++) {
        int j;
        for (j = 0; j < t_len; j++) {
            if (s[i + j] != t[j]) break;
        }
        if (j == t_len) return i+1;
    }
    return -1;
}

int main() {
    char s[100], t[100];
    
    printf("�������ַ���s��");
    scanf("%s", s);
    printf("�������ַ���t��");
    scanf("%s", t);
    
    int s_length = str_len(s);
    int t_length = str_len(t);
    printf("s�ĳ��ȣ�%d\n", s_length);
    printf("t�ĳ��ȣ�%d\n", t_length);
    
    int position = find(s, t);
    if (position != -1) {
        printf("t��s���Ӵ�������ʼλ��Ϊ%d\n", position);
    } else {
        printf("t����s���Ӵ�\n");
    }
    
    return 0;
}
