#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MIN_YEAR 2010
#define MAX_YEAR 2021
#define LOG_DAYS 3


int main(void) {

	int YEAR, MONTH; // Variables to represent Year and Month by the user
	int const JAN = 1, DEC = 12; // Variables representing the first and last month and initlized by instructed values
	int n, i; // Varibles for loops and days
	double morningRate, eveningRate; // Double floating-point from User input representing morning and evening self-diagnosis
	double morningSum, eveningSum, totalSum, mrAverage, erAverage, totalAverage; // Double used to calculate sum, average and total ratings

	morningSum = 0;
	eveningSum = 0;

	printf("General Well-being Log\n"); // Title
	printf("======================\n");
	do
	{
		n = 1;
		printf("Set the year and month for the well-being log (YYYY MM): "); // Message displayed instructed 
		scanf("%d  %d", &YEAR, &MONTH); // User's input of Year and Month

		if (YEAR < MIN_YEAR || YEAR > MAX_YEAR) // Error Range for Years
		{
			printf("   ERROR: The year must be between 2010 and 2021 inclusive\n");
			n = 0;
		}

		if (MONTH < JAN || MONTH > DEC) // Error Range for Months
		{
			printf("   ERROR: Jan.(1) - Dec.(12)\n");
			n = 0;
		}

	} while (n == 0);

	printf("\n*** Log date set! ***\n");
	{
		for (i = 1; i <= LOG_DAYS; i++) // Nest inside the for construct
		{
			switch (MONTH) // Mapping month and day to interger value
			{
			case 1:
				printf("\n%d-JAN-%02d\n", YEAR, i);
				break;
			case 2:
				printf("\n%d-FEB-%02d\n", YEAR, i);
				break;
			case 3:
				printf("\n%d-MAR-%02d\n", YEAR, i);
				break;
			case 4:
				printf("\n%d-APR-%02d\n", YEAR, i);
				break;
			case 5:
				printf("\n%d-MAY-%02d\n", YEAR, i);
				break;
			case 6:
				printf("\n%d-JUN-%02d\n", YEAR, i);
				break;
			case 7:
				printf("\n%d-JUL-%02d\n", YEAR, i);
				break;
			case 8:
				printf("\n%d-AUG-%02d\n", YEAR, i);
				break;
			case 9:
				printf("\n%d-SEP-%02d\n", YEAR, i);
				break;
			case 10:
				printf("\n%d-OCT-%02d\n", YEAR, i);
				break;
			case 11:
				printf("\n%d-NOV-%02d\n", YEAR, i);
				break;
			case 12:
				printf("\n%d-DEC-%02d\n", YEAR, i);
				break;

			}

			do //Validating the User's input with appropriate error message that will repeat until proper value is inputed for morning rates
			{
				n = 1;
				printf("   Morning rating (0.0-5.0): ");
				scanf("%lf", &morningRate);

				if (morningRate < 0.0 || morningRate > 5.0)
				{
					printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
					n = 0;
				}

			} while (n == 0);

			do //Validating the User's input with appropriate error message that will repeat until proper value is inputed for evening rates
			{
				n = 1;
				printf("   Evening rating (0.0-5.0): ");
				scanf("%lf", &eveningRate);

				if (eveningRate < 0.0 || eveningRate > 5.0)
				{
					printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
					n = 0;
				}

			} while (n == 0);

			morningSum += morningRate; // calculation used for 5. in part 2
			eveningSum += eveningRate;
			totalSum = morningSum + eveningSum;
			mrAverage = morningSum / LOG_DAYS;
			erAverage = eveningSum / LOG_DAYS;
			totalAverage = (mrAverage + erAverage) / 2;
		}
		printf("\nSummary\n");
		printf("=======\n");
		printf("Morning total rating: %.3lf\n", morningSum);
		printf("Evening total rating: %.3lf\n", eveningSum);
		printf("----------------------------\n");
		printf("Overall total rating: %.3lf\n\n", totalSum);
		printf("Average morning rating:  %.1lf\n", mrAverage);
		printf("Average evening rating:  %.1lf\n", erAverage);
		printf("----------------------------\n");
		printf("Average overall rating:  %.1lf\n", totalAverage);


		return 0;
	}
}
