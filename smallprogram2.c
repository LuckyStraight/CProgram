//COP3223C Section 1
//Small Program 2

#include <stdio.h>
#include <math.h>

double coneSurfaceArea(double radius, double height, double pi);
void parkingCharge();
void wakandaPopulation(int year);
double factorialApprox(int n);

int main()
{
    double radius, height, pi; //defining all variables to be a double

    printf("Enter the radius: ");
    scanf("%lf", &radius);

    printf("Enter the height: ");
    scanf("%lf", &height);

    pi = 3.14;
    double result = coneSurfaceArea(radius, height, pi); // calling from the coneSurfaceArea function to be redefined.

    printf("The total surface area of the cone is %.2lf\n", result);

    parkingCharge(); //Calling parkingCharge into main to run

    int year;
    printf("Enter a year after 2016: ");
    scanf("%d", &year);
    wakandaPopulation(year); //calling wakandaPopualtion into main to run

    int n;
    printf("Enter the value for n: ");
    scanf("%d", &n);
    double total = factorialApprox(n); // calling from the factorialApprox function to be redefined.

    printf("%d! is approximately %.4lf\n", n, total);
    

    return 0;

}

double coneSurfaceArea(double radius, double height, double pi)
{
    
    double SA = pi * radius * (radius + sqrt(height * height + radius * radius)); //formula to calcualte the Surface Area of a cone.

    return SA;
}

void parkingCharge()
{
    printf("Welcome to the Parking Garage!\n");

    int hours;
    printf("How many hours will you keep your car parked here> ");
    scanf("%d", &hours);

    double rate = 4.21;

    double total = rate * hours; //calculating the rate in whlich customers will be charged for the number of hours.

    printf("Car will be parked for %d hours and will be charged $%.2lf.\n", hours, total);

}

void wakandaPopulation(int year)
{
    int years = year - 2016; //subtracting the year inputed by 2016 to get the difference.
    double population = 51.451 + (4.239 * years); //using years to calculate the predicted popualtion.
    printf("Predicted Wakanda's population for %d (in thousands): %.3lf\n", year, population);

}

double factorialApprox(int n)
{
    double pi = 3.14;

    double outsidesqrt = (pow(n,n))*(exp(-n)); //calulates the outside the of the square root.
    double insidesqrt = sqrt(((2*n) + ((double)1/3))* pi); // calulates the inside of the square root.
    double factorial = outsidesqrt * insidesqrt; //multiplies the outside and the inside of the square root.

    return factorial; // sends factorial to the main function.
}
