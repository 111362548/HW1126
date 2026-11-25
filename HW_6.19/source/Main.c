#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROLLS 36000

int main(void) {
    int frequency[13] = { 0 }; // 索引 2~12 用來記錄各點數出現次數
    // 理論組合數（用於驗證結果是否合理）
    int expectedWays[13] = { 0, 0, 1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1 };

    srand((unsigned int)time(NULL));

    for (int i = 0; i < ROLLS; i++) {
        int die1 = 1 + rand() % 6;
        int die2 = 1 + rand() % 6;
        int sum = die1 + die2;
        frequency[sum]++;
    }

    printf("%6s%12s%14s%14s\n", "點數", "出現次數", "實際比例(%)", "理論比例(%)");
    for (int sum = 2; sum <= 12; sum++) {
        double actualPct = (double)frequency[sum] / ROLLS * 100.0;
        double expectedPct = (double)expectedWays[sum] / 36.0 * 100.0;
        printf("%6d%12d%13.2f%%%13.2f%%\n", sum, frequency[sum], actualPct, expectedPct);
    }

    return 0;
}