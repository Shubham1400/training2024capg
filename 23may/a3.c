#include <stdio.h>
#define FAH(c)((c*9/5)+32)
int main()
{
    float celsius;
    scanf("%f", &celsius);
    //float fah = (celsius*9/5)+32;
    printf("fahrenheit = %f\n",FAH(celsius));

    return 0;
}
