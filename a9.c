#include <stdio.h>
int main()
{
    float weight, height;
    scanf("%f", &weight);
    scanf("%f", &height);
    
    float bmi = weight/(height*height);
    
    if (bmi>=30)
        printf("Obesity");
    else if (bmi>=25 && bmi<30)
        printf("overweight");
    else if (bmi>=18.5 && bmi<25)
        printf("normal weight");
    else
        printf("underweight");

    return 0;
}
