/*7. Write a program that takes a score (0-100) as input from the user and uses if statements to determine the corresponding grade:
90-100: A
80-89: B
70-79: C
60-69: D
Below 60: F
Print the grade.*/
#include <stdio.h>
int main()
{
    int score;
    char grade;
    scanf("%d", &score);
    if(score>-1 && score<101){
        if (score> 89 && score<101)
            grade = 'A';
        else if (score>79 && score<90)
            grade = 'B';
        else if(score>69 && score<80)
            grade = 'C';
        else if(score>59 && score<70)
            grade = 'D';
        else
            grade = 'F';
            
        printf("grade is = %c",grade);
    }
    else
        printf("invalid score");

    return 0;
}
