#include <stdio.h>

void stringReverse(const char s[]);

int main(void) {
    char str[100];

    printf("請輸入一個字串: ");
    fgets(str, sizeof(str), stdin);

    // 移除 fgets 可能讀入的換行符號
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
    }

    printf("反向輸出結果: ");
    stringReverse(str);
    printf("\n");

    return 0;
}

void stringReverse(const char s[]) {
    if (s[0] == '\0') {
        return; // 遇到結束字元 '\0' 即停止遞迴
    }

    stringReverse(&s[1]); // 先遞迴處理下一個字元
    putchar(s[0]);        // 回溯時再印出當前字元
}