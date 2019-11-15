#include <stdio.h>

int main() {
    static int x = 5;
    static int *p = &x;
    printf("(int) p   => %d\n",(int) p);
    printf("(int) p++ => %d\n",(int) p++); // use it then move to next int position
    x = 5; p = &x;
    printf("(int) ++p => %d\n",(int) ++p); // move to next int and then use it
    x = 5; p = &x;
    printf("++*p      => %d\n",++*p); // increments the value by 1 then use it
    x = 5; p = &x;
    printf("++(*p)    => %d\n",++(*p)); // increments the value by 1 then use it
    x = 5; p = &x;
    printf("++*(p)    => %d\n",++*(p)); // increments the value by 1 then use it
    x = 5; p = &x;
    printf("*p++      => %d\n",*p++); // use the value of p then moves to next position
    x = 5; p = &x;
    printf("(*p)++    => %d\n",(*p)++); // use the value of p then increment the value
    x = 5; p = &x;
    printf("*(p)++    => %d\n",*(p)++); // use the value of p then moves to next position
    x = 5; p = &x;
    printf("*++p      => %d\n",*++p); // moves to the next int location then use that value
    x = 5; p = &x;
    printf("*(++p)    => %d\n",*(++p)); // moves to next location then use that value
    return 0;
}
