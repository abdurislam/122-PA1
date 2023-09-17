/****************************************************

	Abdur Islam
	CPTS 122 
	Programming Assignment 1: Analyzing Fitbit Data 

****************************************************/


#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef enum sleep

{

	NONE = 0, ASLEEP = 1, AWAKE = 2, REALLYAWAKE = 3

} Sleep;
typedef struct fitbit

{

	char patient[10];
	char minute[9];
	double calories;
	double distance;
	unsigned int floors;
	unsigned int heartRate;
	unsigned int steps;

	Sleep sleepLevel;

} FitbitData;


/*************************************************************************************
Functions Name: Print_Array
Description: Prints an array with proper formatting
Parameters: Array of the Fitbit struct an outfile to print out to and the size of the
array
Output: the contents of the array in a certain format it also doesnt print out the
lines that has invalid data
*************************************************************************************/
void print_array(struct fitbit a[], FILE* outfile, int size);

/*************************************************************************************
Functions Name: Set Array
Description: Sets the first index of the array to the first line of valid data
Parameters: Array of the Fitbit struct and infile to get strings from and the size of the
array
Output: void
*************************************************************************************/

void set_array(FILE* infile, FitbitData* a, int size);

/*************************************************************************************
Functions Name: Cleanse
Description: When inputing the data inside the array from the infile it makes it so
when the data is from another patient or a dupe it flags it as invalid.
Parameters: Array of the Fitbit struct int flag that doesnt do anything and int size
which is size of array
Output: VOID
*************************************************************************************/

void cleanse(FitbitData* a, int flag, int size);

/*************************************************************************************
Functions Name: readfile
Description: Reads the data from the infile and parses the data into individual data
to fit the array of structs.
Parameters: Array of the Fitbit struct an infile, size of array, and a pointer flag
that isnt used :)
Output: VOID
*************************************************************************************/

void readfile(FILE* infile, FitbitData* a, int size, int* flag);


/*************************************************************************************
Functions Name: totCalories
Description: traverses through an array and calculates the total calories burned
for the data set
Parameters: array of structs and size of the array
Output: the total calories burned
*************************************************************************************/

double totCalories(struct fitbit a[], int size);

/*************************************************************************************
Functions Name: totDistance
Description: traverses through an array and calculates the total distance walked
for the data set
Parameters: array of structs and size of the array
Output: the total distance walked burned
*************************************************************************************/

double totDistance(struct fitbit a[], int size);

/*************************************************************************************
Functions Name: totFloors
Description: traverses through an array and calculates the total floors climbed
for the data set
Parameters: array of structs and size of the array
Output: the total floors climbed
*************************************************************************************/

double totFloors(struct fitbit a[], int size);

/*************************************************************************************
Functions Name: avgHeartRate
Description: traverses through an array and calculates the average heart rate
Parameters: array of structs and size of the array
Output: the total calories burned
*************************************************************************************/

double avgHeartRate(struct fitbit a[], int size);

/*************************************************************************************
Functions Name: totSteps
Description: traverses through an array and calculates the total Steps walked
for the data set
Parameters: array of structs and size of the array
Output: the total steps walked
*************************************************************************************/

double totSteps(struct fitbit a[], int size);

/*************************************************************************************
Functions Name: maxSteps
Description: traverses through an array and calculates the steps walked
for the data set
Parameters: array of structs and size of the array
Output: the total calories burned
*************************************************************************************/

int maxSteps(struct fitbit a[], int size, int* min);

/*************************************************************************************
Functions Name: poorSleep
Description: traverses through an array and the range of poor sleep in a row by
comparing the total "sleepness" of that range
Parameters: array of structs and size of the array, 2 char pointers to the minutes range
Output: the 2 minute ranges that has the "worst sleep range"
*************************************************************************************/

void poorSleep(FitbitData* a, int size, char* min1, char* min2);



//void set_array(struct fitbit a[], int size);

