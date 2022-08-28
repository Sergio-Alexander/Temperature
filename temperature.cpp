#include <iostream>
#include <iomanip>
using namespace std;

// Here we are declaring the function prototypes that will be used 
int* numTemp(int &size, int arr[]); //The function numTemp will be used to ask the user to input the number of days, and the temperature for each day
int arrSorting(int &size, int arr[], int &temp); // The function arrSorting will be used to sort the temperatures in ascending order
void print(int &size, int arr[], int &temp); // The function print will be used to print the tempeartures in ascending order
double avg(int &size, int arr[]); // The avg function will be used to calculate the average of the temperatures

int main()
{
	// Declaring the integers that will be used
	const int SIZER = 10;
	int arr[SIZER];
	int size = 0;
	int temp = 0;

	// Calling the functions 
	int* callFunction1 = numTemp(size, arr);
	print(size, arr, temp);

	// Calling the function to calculate the average
	double callFunction2 = avg(size, arr);
	cout << fixed << setprecision(2); // Setting the output to produce the answer with 2 decimal places
	cout << "The average of the temperatures is " << callFunction2 << endl;

	delete[] callFunction1;

	return 0;
}

// The function definition for numTemp
int* numTemp(int &size, int arr[])
{
	cout << "Please enter the number of days you would like to input (Maximum 10)" << endl;
	cin >> size; // Here the program will ask the user to input the number of days. Basically setting the size of the array.

	if (size > 10) // This "if" statement is making sure that the number of days does not exceed 10
	{
		cout << "The number you've inputted is over 10, please try again" << endl;
			cin >> size;
	}

	for (int i = 0; i < size; i++) // This "for" statement will ask the user the temperatures for each day 
	{
		cout << "Please enter the temperature for day number " << i + 1 << endl;
		cin >> arr[i];
	}
	return 0;
}

// Function definition for arrSorting
int arrSorting(int& size, int arr[], int& temp) 
{
	for (int i = 0; i < size; i++) // These loops will arrange the temperature in ascending order
	{
		for (int j = i + 1; j < size; j++)
		{
	
			if (arr[j] < arr[i])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	return temp; // Returning the value of temperature
}

// Function definition for print
void print(int& size, int arr[], int &temp)
{
	int callFunction;
	callFunction = arrSorting(size, arr, temp); // Calling the arrSorting function to sort the temperatures
	
	cout << "Temperatures sorted in ascending order:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl; // Displaying the temperature in ascending order
	}
}

//Function Definition for avg
double avg(int& size, int arr[]) 
{
	double sum = 0;
	double average;

	for (int i = 0; i < size; i++)
	{
		sum += arr[i]; // Calculating the sum of the temperatures
	}

	average = sum / size; // Calculating the average

	return average; // Returning the value of average
}