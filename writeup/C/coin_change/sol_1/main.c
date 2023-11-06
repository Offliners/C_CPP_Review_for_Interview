#include<stdio.h>
#include<stdlib.h>

int coinChange(int* coins, int coinsSize, int amount) {
    int *table = (int*)malloc((amount + 1) * sizeof(int));

    table[0] = 0;
    for(int i = 1; i < amount + 1; ++i)
        table[i] = amount + 1;

    for(int i = 1; i <=amount; ++i)
        for(int j = 0; j < coinsSize; ++j)
            if(i - coins[j] >= 0)
                table[i] = (table[i] < 1 + table[i - coins[j]]) ? table[i] : 1 + table[i - coins[j]];

    int ans = (table[amount] == amount + 1) ? -1 : table[amount];
    free(table);

    return ans;
}

int main(void)
{
    int amount, temp;
    temp = scanf("%d", &amount);

    int coinsSize;
    temp = scanf("%d", &coinsSize);

    int *coins = (int*)malloc(coinsSize * sizeof(int));
    for(int i = 0; i < coinsSize; ++i)
        temp = scanf("%d", &coins[i]);

    printf("%d\n", coinChange(coins, coinsSize, amount));

    return 0;
}