#include <cstdio>
#include <iostream>
#include <string>

#define DEBUG 0
#define RELEASE 0
#define FUNCTION(num, op) void num(int a, int b){ \
                          if(a op b) {    \
                           a = b;         \
                           }              \
                             }             \

#if DEBUG
#define LOG(x) std::cout << x << std::endl
#elif defined(RELEASE)
#define LOG(X) std::cout << "yes"
#endif

#define cube(b) b*b*b
#define MACRO(num, str) ({\
            printf("%d", num);\
            printf("is "); \
            printf("%s number", str);\
            printf("\n");\
           })

FUNCTION(minimum, <);
FUNCTION(maximum, >);

void preprocessor() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num & 1)
        MACRO(num, "Odd");
    else
        MACRO(num, "Even");

    LOG("Debug Mode");

}
