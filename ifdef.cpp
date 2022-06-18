#include <stdio.h>

#define NOINPUT
int main() {
    int a = 0;
#ifdef NOINPUT  //如果NOINPUT被def的話 ，就執行
    a = 2;
#else
    printf("Enter a:");
    scanf("%d", &a);
#endif
    printf("Value of a: %d\n", a);


#ifndef NOINPUT  //如果NOINPUT被def的話 ，就不執行
    a = 2;
#else
    printf("Enter a:");
    scanf("%d", &a);
#endif
    printf("Value of a: %d\n", a);
}