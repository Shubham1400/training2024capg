/*9. BMI Calculator:
Write a program that calculates the Body Mass Index (BMI) based on user input for weight (in kg) and height (in meters). Use if statements to classify the BMI into categories:
Below 18.5: Underweight
18.5 to 24.9: Normal weight
25 to 29.9: Overweight
30 and above: Obesity
10. Simple Calculator:
Write a program that takes two numbers and an operator (+, -, *, /) as input and uses if statements to perform the corresponding arithmetic operation. Print the result.*/
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
