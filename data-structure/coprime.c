#include <stdio.h>

int gcd(int a, int b)
{
    return a % b == 0 ? b : gcd(b, a%b);
}

int main(){
    int a,b;
    printf("please enter 2 numbers\n");
    while(scanf("%d%d", &a, &b)){
        if(gcd(a,b) == 1)
            printf("����\n");
        else
            printf("������\n");
    }
    return 0;
}
