#include <stdio.h>
#include <math.h>

//function declarations
double leftCalc(double, double, double, double, double, double, double, double);
double midCalc(double, double, double, double, double, double, double, double);
double rightCalc(double, double, double, double, double, double, double, double);

int main()
{
    //local variables
    double a;
    double b;
    double c;
    double d;
    double e;
    double initial;
    double final;
    double rect;
    double choice;
    double width;
    double area;

    //statements
    printf("Enter integer coefficients [a b c d e]: ");
    scanf("%lf %lf %lf %lf %lf", &a, &b, &c, &d, &e);

    printf("Enter the initial value of x: ");
    scanf("%lf", &initial);

    do
    {
        printf("Enter the final value of x: ");
        final = scanf("%lf", &final);
        if (final <= initial)
            printf("\nError! Final must be greater than initial!!\n \n");
    } while (final <= initial);

    do
    {
        printf("\nPlease enter the number of approximating rectangles: ");
        rect = scanf("%lf", &rect);
        if (rect <= 0)
            printf("\nError! Number of rectangles must be positive!!\n");
    } while (rect <= 0);

    printf("\nPlease choose your method of approximation: \n1. Left end-point\n2. Mid-point\n3. Right end-point\nYour choice: ");
    choice = scanf("%lf", &choice);

    while ((choice != 1) && (choice != 2) && (choice != 3))
    {
        printf("\nError! Invalid selection!!\n");
        printf("\nPlease choose your method of approximation: \n1. Left end-point\n2. Mid-point\n3. Right end-point\nYour choice: ");
        choice = scanf("%lf", &choice);
    }

    width = (final - initial) / rect;

    if (choice == 1)
        area = leftCalc (a, b, c, d, e, initial, final, width);
    else if (choice == 2)
        area = midCalc (a, b, c, d, e, initial, final, width);
    else if (choice == 3)
        area = rightCalc (a, b, c, d, e, initial, final, width);

    printf("\nEstimated area: %lf sq. units\n", area);

    return(0);
}





double leftCalc (double a, double b, double c, double d, double e, double initial, double final, double width)
{
    double area;

    while (initial < final)
    {
        area += width * (a * pow(initial, 4) + b * pow(initial, 3) + c*pow(initial, 3) + d*pow(initial, 2) + d*initial + e);
        initial += width;
    }

    return(area);
}



double midCalc (double a, double b, double c, double d, double e, double initial, double final, double width)
{
    double area;

    while (initial < final)
    {
        initial += width / 2;
        area += width * (a * pow(initial, 4) + b * pow(initial, 3) + c*pow(initial, 3) + d*pow(initial, 2) + d*initial + e);
        initial += width / 2;
    }

    return area;
}


double rightCalc (double a, double b, double c, double d, double e, double initial, double final, double width)
{
    double area;

    while (initial < final)
    {
        initial += width;
        area += width * (a * pow(initial, 4) + b * pow(initial, 3) + c*pow(initial, 3) + d*pow(initial, 2) + d*initial + e);
    }

    return area;
}