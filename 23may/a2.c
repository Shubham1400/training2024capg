#include <stdio.h>
#define PI 3.14 //macro
int main()
{
    float r;
    scanf("%f", &r);
    float area = PI * r * r;
    float peri = PI*2*r;
    printf("area = %f\n",area);
    printf("perimeter = %f",peri);

    return 0;
}
