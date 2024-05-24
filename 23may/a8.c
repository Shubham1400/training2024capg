#include <stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    
    if (t>30)
        printf("It\'s hot outside, stay hydrated!");
    else if (t>19 && t<31)
        printf("The weather is nice and warm.");
    else if (t>9 && t<20)
        printf("It\'s a bit chilly, wear a jacket.");
    else
        printf("It\'s cold outside, stay warm!");

    return 0;
}
