#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE 15

int binarySearch(const int b[], int low, int high, int key);

int main(void) {
    int a[SIZE];
    int key;

    // 建立已排序陣列：0, 2, 4, ..., 28（對應課本 Fig. 6.19）
    for (size_t i = 0; i < SIZE; i++) {
        a[i] = 2 * (int)i;
    }

    printf("請輸入要搜尋的整數 (0 ~ 28): ");
    scanf("%d", &key);

    int result = binarySearch(a, 0, SIZE - 1, key);

    if (result != -1) {
        printf("\n在陣列索引 %d 找到數值 %d\n", result, key);
    }
    else {
        printf("\n找不到數值 %d\n", key);
    }

    return 0;
}

int binarySearch(const int b[], int low, int high, int key) {
    if (low > high) {
        return -1; // 搜尋區間為空，代表找不到
    }

    int middle = low + (high - low) / 2;

    if (key == b[middle]) {
        return middle;
    }
    else if (key < b[middle]) {
        return binarySearch(b, low, middle - 1, key);
    }
    else {
        return binarySearch(b, middle + 1, high, key);
    }
}