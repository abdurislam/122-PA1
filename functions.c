/****************************************************

	Abdur Islam
	CPTS 122
	Programming Assignment 1: Analyzing Fitbit Data

****************************************************/

#include "Header.h"

//void set_array(struct fitbit a[], int size)
//{
//	char* buff = '\0';
//	for (int i = 0; i < size; i++)
//	{
//		strcpy(a[i].patient, '\0');
//		//strcpy(a[i].minute, );
//		a[i].calories = 0;
//		a[i].distance = 0;
//		a[i].floors = 0;
//		a[i].heartRate = 0;		
//		a[i].steps = 0;
//		a[i].sleepLevel = 0;
//
//
//	}

/*************************************************************************************
Functions Name: Print_Array
Description: Prints an array with proper formatting 
Parameters: Array of the Fitbit struct an outfile to print out to and the size of the 
array
Output: the contents of the array in a certain format it also doesnt print out the 
lines that has invalid data
*************************************************************************************/


void print_array(struct fitbit a[],FILE* outfile, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(a[i].patient, "invald") != 0 || strcmp(a[i].minute, "invald") != 0)
		{
			fprintf(outfile, "%s,", a[i].patient);
			fprintf(outfile, "%s,", a[i].minute);
			fprintf(outfile, "%lf,", a[i].calories);
			fprintf(outfile, "%lf,", a[i].distance);
			fprintf(outfile, "%d,", a[i].floors);
			fprintf(outfile, "%d,", a[i].heartRate);
			fprintf(outfile, "%d,", a[i].steps);
			fprintf(outfile, "%d", a[i].sleepLevel);
			fprintf(outfile, "\n");
		}
	}

}
/*************************************************************************************
Functions Name: Set Array
Description: Sets the first index of the array to the first line of valid data
Parameters: Array of the Fitbit struct and infile to get strings from and the size of the
array
Output: void 
*************************************************************************************/
void set_array(FILE* infile, FitbitData* f_test_arr, int size)
{
	char* str[60];
	//set_array(f_test_arr, 100);
	fgets(str, 60, infile);
	int count = 1;
	double dtok;
	int itok;
	char* token;
	for (; count < 9; count++)
	{
		switch (count)
		{
		case 1:
			token = strtok(str, ",");
			strcpy(f_test_arr[0].patient, token);
			break;
		case 2:
			token = strtok(NULL, ",");
			strcpy(f_test_arr[0].minute, token);
			break;
		case 3:
			token = strtok(NULL, ",");
			dtok = atof(token);
			f_test_arr[0].calories = dtok;
			break;
		case 4:
			token = strtok(NULL, ",");
			dtok = atof(token);
			f_test_arr[0].distance = dtok;
			break;

		case 5:
			token = strtok(NULL, ",");
			itok = atoi(token);
			f_test_arr[0].floors = itok;
			break;
		case 6:
			token = strtok(NULL, ",");
			if (token == NULL)
			{
				f_test_arr[0].heartRate = 0;
				break;
			}
			itok = atoi(token);

			f_test_arr[0].heartRate = itok;
			break;
		case 7:
			token = strtok(NULL, ",");
			itok = atoi(token);
			f_test_arr[0].steps = itok;
			break;
		case 8:
			token = strtok(NULL, ",");
			if (token == NULL)
			{
				f_test_arr[0].sleepLevel = 0;
				break;
			}
			itok = atoi(token);
			f_test_arr[0].sleepLevel = itok;
			break;
		}
	}
}
/*************************************************************************************
Functions Name: Cleanse
Description: When inputing the data inside the array from the infile it makes it so
when the data is from another patient or a dupe it flags it as invalid.
Parameters: Array of the Fitbit struct int flag that doesnt do anything and int size 
which is size of array
Output: VOID
*************************************************************************************/
void cleanse(FitbitData* a, int flag, int size)
{
	char tempp[] = "invald";
	char tempm[] = "invald";
	/*double tempc;
	double tempd;
	int tempf;
	int temph;
	int temps;
	int tempsl;



	for (int i = flag; i < size-1; i++)
	{
		strcpy(tempp, a[i+1].patient);
		strcpy(tempm, a[i+1].minute);
		tempc = a[i+1].calories;
		tempd = a[i + 1].distance;
		tempf = a[i + 1].floors;
		temph = a[i + 1].heartRate;
		temps = a[i + 1].steps;
		tempsl = a[i + 1].sleepLevel;

		strcpy(a[i].patient,tempp);
		strcpy(a[i].minute, tempm);
		a[i].calories = tempc;
		a[i].distance = tempd;
		a[i].floors = tempf;
		a[i].heartRate = temph;
		a[i].steps = temps;
		a[i].sleepLevel = tempsl;


	}*/

	strcpy(a[flag].patient, tempp);
	strcpy(a[flag].minute, tempm);
	a[flag].calories = 0;
	a[flag].distance = 0;
	a[flag].floors = 0;
	a[flag].heartRate = 0;
	a[flag].steps = 0;
	a[flag].sleepLevel = 0;

}


/*************************************************************************************
Functions Name: readfile 
Description: Reads the data from the infile and parses the data into individual data
to fit the array of structs.
Parameters: Array of the Fitbit struct an infile, size of array, and a pointer flag
that isnt used :)
Output: VOID
*************************************************************************************/
void readfile(FILE* infile, FitbitData* a, int size, int* flag)
{
	char* str[60];
	char* token;
	char sTok[10];
	int arr_num = 0;
	double dtok;
	int itok;
	char* id = a[0].patient;
	char* miunte;
	int flag2 = 0;

	
		for (int i = 1; i < size; i++)
		{
			
			
			


					fgets(str, 60, infile);
					int count = 1;
					for (; count < 9; count++)
					{
						switch (count)
						{
						case 1:
							token = strtok(str, ",");
							strcpy(a[i].patient, token);
							if (strcmp(a[0].patient, a[i].patient) != 0)
							{
								flag2 = i;
								count = 9;
							}
							break;
						case 2:
							token = strtok(NULL, ",");
							strcpy(a[i].minute, token);
							if (strcmp(a[i - 1].minute, a[i].minute) == 0)
							{
								flag2 = i;
								count = 9;
							}
							break;
						case 3:
							token = strtok(NULL, ",");
							dtok = atof(token);
							a[i].calories = dtok;
							break;
						case 4:
							token = strtok(NULL, ",");
							dtok = atof(token);
							a[i].distance = dtok;
							break;

						case 5:
							token = strtok(NULL, ",");
							itok = atoi(token);
							a[i].floors = itok;
							break;
						case 6:
							token = strtok(NULL, ",");
							if (token == NULL)
							{
								a[i].heartRate = 0;
								break;
							}
							itok = atoi(token);

							a[i].heartRate = itok;
							break;
						case 7:
							token = strtok(NULL, ",");
							itok = atoi(token);
							a[i].steps = itok;
							break;
						case 8:
							token = strtok(NULL, ",");
							if (token == NULL)
							{
								a[i].sleepLevel = 0;
								break;
							}
							itok = atoi(token);
							a[i].sleepLevel = itok;
							break;
						}
						if (flag2 != 0)
						{
							cleanse(a, flag2, size);
							flag2 = 0;
							flag++;
							

						}
					
				
			}

			
			

		}
		




	



}

/*************************************************************************************
Functions Name: totCalories
Description: traverses through an array and calculates the total calories burned 
for the data set
Parameters: array of structs and size of the array 
Output: the total calories burned 
*************************************************************************************/
double totCalories(struct fitbit a[], int size)
{
	double total = 0;
	for (int i = 0; i < size; i++)
	{
		total += a[i].calories;

	}
	return total;
}

/*************************************************************************************
Functions Name: totDistance
Description: traverses through an array and calculates the total distance walked
for the data set
Parameters: array of structs and size of the array
Output: the total distance walked burned
*************************************************************************************/
double totDistance(struct fitbit a[], int size)
{
	double total = 0;
	for (int i = 0; i < size; i++)
	{
		total += a[i].distance;

	}
	return total;


}
/*************************************************************************************
Functions Name: totFloors
Description: traverses through an array and calculates the total floors climbed
for the data set
Parameters: array of structs and size of the array
Output: the total floors climbed
*************************************************************************************/

double totFloors(struct fitbit a[], int size)
{
	double total = 0;
	for (int i = 0; i < size; i++)
	{
		total += a[i].floors;

	}
	return total;
}
/*************************************************************************************
Functions Name: avgHeartRate
Description: traverses through an array and calculates the average heart rate 
Parameters: array of structs and size of the array
Output: the total calories burned
*************************************************************************************/
double avgHeartRate(struct fitbit a[], int size)
{
	double avg = 0;
	int adjustedSize = size;
	for (int i = 0; i < size; i++)
	{
		if (a[i].heartRate == 0)
		{
			adjustedSize--;

		}
		else
		{
			avg += a[i].heartRate;
		}

	}
	return avg / (adjustedSize * 1.0);


}
/*************************************************************************************
Functions Name: totSteps
Description: traverses through an array and calculates the total Steps walked
for the data set
Parameters: array of structs and size of the array
Output: the total steps walked
*************************************************************************************/

double totSteps(struct fitbit a[], int size)
{
	double total = 0;
	for (int i = 0; i < size; i++)
	{
		total += a[i].steps;

	}
	return total;
}

/*************************************************************************************
Functions Name: maxSteps
Description: traverses through an array and calculates the steps walked
for the data set
Parameters: array of structs and size of the array
Output: the total calories burned
*************************************************************************************/


int maxSteps(struct fitbit a[], int size, int* minute)
{
	int maxsteps = a[0].steps;
	

	for (int i = 0; i < size; i++)
	{
		if (maxsteps <= a[i].steps)
		{
			maxsteps = a[i].steps;
			minute = i;
		}

	}

	return maxsteps;

}
/*************************************************************************************
Functions Name: poorSleep
Description: traverses through an array and the range of poor sleep in a row by 
comparing the total "sleepness" of that range
Parameters: array of structs and size of the array, 2 char pointers to the minutes range
Output: the 2 minute ranges that has the "worst sleep range"
*************************************************************************************/


void poorSleep(FitbitData* a, int size, char* min1, char* min2)
{
	int total = 0;
	int head = 0;
	int tail = 0;
	int count = 0;
	int maxTotal = 0;
	int maxHead = 0;
	int maxTail = 0;

	for (int i = 0; i < size; i++)
	{

		if (a[i].sleepLevel > 1)
		{
			if (head == 0)
			{
				head = i;
			}
			count++;
			total += a[i].sleepLevel;
		}
		else
		{
			if (count > 0)
			{
				tail = i - 1;
				if (maxTotal < total)
				{
					maxTotal = total;
					strcpy(min1, a[head].minute);
					strcpy(min2, a[tail].minute);
				}
			}
			count = 0;
			head = 0;
			tail = 0;
			total = 0;
		}
	}





}