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
    
    printf("请输入字符串s：");
    scanf("%s", s);
    printf("请输入字符串t：");
    scanf("%s", t);
    
    int s_length = str_len(s);
    int t_length = str_len(t);
    printf("s的长度：%d\n", s_length);
    printf("t的长度：%d\n", t_length);
    
    int position = find(s, t);
    if (position != -1) {
        printf("t是s的子串，且起始位置为%d\n", position);
    } else {
        printf("t不是s的子串\n");
    }
    
    return 0;
}
