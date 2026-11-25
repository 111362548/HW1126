#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int b[] = { 10, 20, 30, 40 };
    int* bPtr = b; // 設定指標 bPtr 指向陣列 b 的起始位址
    int i;
    int offset;

    printf("Array subscript notation\n");
    for (i = 0; i < 4; i++) {
        printf("b[%d] = %d\n", i, b[i]);
    }

    printf("\nPointer/offset notation where\nthe pointer is the array name\n");
    for (offset = 0; offset < 4; offset++) {
        printf("*(b + %d) = %d\n", offset, *(b + offset));
    }

    printf("\nPointer subscript notation\n");
    for (i = 0; i < 4; i++) {
        printf("bPtr[%d] = %d\n", i, bPtr[i]);
    }

    printf("\nPointer/offset notation\n");
    for (offset = 0; offset < 4; offset++) {
        printf("*(bPtr + %d) = %d\n", offset, *(bPtr + offset));
    }

    system("pause");
    return 0;
}