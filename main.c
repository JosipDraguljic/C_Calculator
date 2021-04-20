#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIGITS 30

float DoAddition(float num1, float num2);
float DoSubstraction(float num1, float num2);
float DoMultiplication(float num1, float num2);
float DoDivision(float num1, float num2);
int IsValidNumber(char Arr[MAX_DIGITS]);

int main()
{
    char num1[MAX_DIGITS] = {}, num2[MAX_DIGITS] = {};
    float number1, number2;
    float result;
    int decision;

    for(;;)
    {
        do
        {
            system("cls");
            printf("Choose an operation you wish to use(0 to end)\n");
            printf("- 1 - Addition\n");
            printf("- 2 - Substraction\n");
            printf("- 3 - Multiplication\n");
            printf("- 4 - Division\n");
            scanf("%d", &decision);
            fflush(stdin);
        }while(((decision!=1&&decision!=2)&& (decision!=3 && decision!=4)) && decision!=0);

        if(decision == 0)
        {
            break;
        }
        system("cls");

        do
        {
            printf("Enter 1st number: ");
            fgets(num1, MAX_DIGITS, stdin);
            if(IsValidNumber(num1))
            {
                fflush(stdin);
                break;
            }
            else
            {
                fflush(stdin);
                continue;
            }
        }while(1);


        do
        {
            printf("Enter 2nd number: ");
            fgets(num2, MAX_DIGITS, stdin);
            if(IsValidNumber(num2))
            {
                fflush(stdin);
                break;
            }
            else
            {
                fflush(stdin);
                continue;
            }
        }while(1);

        number1 = atof(num1);
        number2 = atof(num2);

        switch(decision)
        {
            case 1:
                result = DoAddition(number1, number2);
                break;
            case 2:
                result = DoSubstraction(number1, number2);
                break;
            case 3:
                result = DoMultiplication(number1, number2);
                break;
            case 4:
                result = DoDivision(number1, number2);
                break;
        }

        printf("Result is: %f\n", result);
        system("pause");
        }
    return 0;
}


float DoAddition(float num1, float num2)
{
    return num1+num2;
}
float DoSubstraction(float num1, float num2)
{
    return num1-num2;
}
float DoMultiplication(float num1, float num2)
{
    return num1*num2;
}
float DoDivision(float num1, float num2)
{
    return num1/num2;
}

int IsValidNumber(char Arr[MAX_DIGITS])
{
    int numbers = 0, dots = 0;
    for(int i = 0; i< strlen(Arr); i++)
    {
        if(isdigit(Arr[i]))
        {
            numbers++;
        }
        else if(Arr[i]=='.')
        {
            dots++;
        }
    }

    if(dots == 1)
    {
        if((numbers + 1) == (strlen(Arr)-1))
        {
            return 1;
        }
    }
    else if(dots == 0)
    {
        if(numbers == (strlen(Arr)-1))
        {
            return 1;
        }
    }

    return 0;
}
