#include<stdio.h>
#include<stdlib.h>

void reverseString(char* s, int sSize){
    for(int i = 0; i < sSize / 2; ++i)
    {
        char temp = s[i];
        s[i] = s[sSize - i - 1];
        s[sSize - i - 1] = temp;
    }
}

int main(void)
{
    int len, temp;
    temp = scanf("%d", &len);

    char *str = (char*)malloc((len + 1) * sizeof(char));
    temp = scanf(" %s", str);

    reverseString(str, len);
    printf("%s\n", str);

    free(str);

    return 0;
}