#include <stdio.h>

#define SIZE 8

int recursiveMaximum(const int array[], int size);

int main(void) {
    int data[SIZE] = { 14, 72, 35, 98, 21, 64, 89, 43 };

    printf("陣列元素: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    int maxVal = recursiveMaximum(data, SIZE);
    printf("陣列中的最大值為: %d\n", maxVal);

    return 0;
}

int recursiveMaximum(const int array[], int size) {
    // 基底條件：只剩 1 個元素時直接回傳
    if (size == 1) {
        return array[0];
    }

    // 遞迴找出剩餘元素（從索引 1 開始，長度 size - 1）的最大值
    int maxOfRest = recursiveMaximum(array + 1, size - 1);

    return (array[0] > maxOfRest) ? array[0] : maxOfRest;
}