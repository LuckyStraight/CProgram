//COP3223C Section 1
//Small Program 1

#include <stdio.h>

int main()
{
    //Problem 1 creating a v
    printf("VV          VV\n");
    printf(" VV        VV\n");
    printf("  VV      VV\n");
    printf("   VV    VV\n");
    printf("    VV  VV\n");
    printf("     VVVV\n");
    printf("      VV\n");


    //problem 2
    printf("Mileage Reimbursement Calculator\n");

    int bodo = 0; //beginnning odometer
    printf("Enter beginning odometer reading=> ");
    scanf("%d", &bodo);

    int eodo = 0;// ending odometer
    printf("Enter ending odometer reading=> ");
    scanf("%d", &eodo);

    double diff = eodo - bodo; //subtracting the beginning and ending odomenter
    printf("You traveled %.1f miles.\n", diff);

    double rate = 2.61;
    double total = rate * diff; //calculates total reimbursement

    printf("At $%.2f per mile, your reimbursement is $%.2f\n", rate, total); // used %.2f to control the decimal places

    //problem 3
    
    float lbs = 0;
    printf("Enter the weight in pounds: ");
    scanf("%f", &lbs);

    float height = 0;
    printf("Enter the total height in inches: ");
    scanf("%f", &height);

    double BMI = (lbs * 703) / (height * height); // Calculates BMI
    printf("BMI = %.3f\n", BMI);

    //problem 4

    double r = 0;
    printf("Enter the radius: ");
    scanf("%lf", &r);

    double h = 0;
    printf("Enter the height: ");
    scanf("%lf", &h);

    double pi = 3.14159;
    double rsquare = r * r; // r squared


    double V = (double) 1/3 * pi * rsquare * h; // formula for volume of a cone

    printf("The volume of the cone is %.4lf\n", V);

    return 0;
}