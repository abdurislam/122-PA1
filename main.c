/****************************************************

	Abdur Islam
	CPTS 122
	Programming Assignment 1: Analyzing Fitbit Data

****************************************************/

//You have to remove the header using fgets and then you have to get the target on top of the file
//once you have header you have to get target and make sure the row you are reading has a patient that is equal to the target
//You also have to creat flags, if you look at the csv in numbers you can see when there is sleep missing the row ends in a comma
//and if hr is missing it ha 2 commas in the middle
// and base on these cases you need seperate functions to strtok through them
// Also I used a hash function for duplicates but you can just check the previous time to see if there is a duplicate entry



#include "Header.h"


int main(void)
{
	FILE* infile = fopen("FitbitData.csv", "r");
	FILE* outfile = fopen("Results.csv", "w");
	struct fitbit f_arr[1440];
	struct fitbit f_test_arr[1444];
	


	double totalCalories, totalDistance, totalFLoors, avgHR, totalSteps;
	int maxStep = 0, consPoorSleep = 0, minute = 0;
	char* buffer[100], * token, * buff1, * target[100];
	int flag = 0;
	char min1[10] = { '\0' }; char min2[10] = { '\0' };

	fgets(buffer, 100, infile);
	buff1 = strtok(buffer, ",");
	buff1 = strtok(NULL, ",");
	//puts(buff1);

	strcpy(f_test_arr[0].patient, buff1);
	strcpy(target, buff1);
	fgets(buffer, 100, infile);

	
	set_array(infile, f_test_arr, 1444);

	readfile(infile, f_test_arr, 1444, flag);


	totalCalories = totCalories(f_test_arr, 1444);
	totalDistance = totDistance(f_test_arr, 1444);
	totalFLoors = totFloors(f_test_arr, 1444);
	avgHR = avgHeartRate(f_test_arr, 1444);
	totalSteps = totSteps(f_test_arr, 1444);
	maxStep = maxSteps(f_test_arr, 1444, minute);
	poorSleep(f_test_arr, 1444, min1, min2);

	//readfile(infile, f_arr, 1440);

	/*totalCalories = totCalories(f_arr, 1440);
	totalDistance = totDistance(f_arr, 1440);
	totalFLoors = totFloors(f_arr, 1440);
	avgHR = avgHeartRate(f_arr, 1440);
	totalSteps = totSteps(f_arr, 1440);
	maxStep = maxSteps(f_arr, 1440, minute);*/


	

	/*
	Line 1: Header line : Total Calories, Total Distance, Total Floors, Total Steps, Avg Heartrate, Max Steps, Sleep

	Line 2: valueCalories, valueDistance, valueFloors, valueSteps, valueHeartrate, valueMax, valueSleepStart : valueSleepEnd

	Lines 3 – N : the filtered, deduped, and cleansed data in the original FitbitData.csv format
	*/

	fprintf(outfile, "Total Calories, Total Distance, Total Floors, Total Steps, Avg Heartrate, Max Steps, Sleep\n");
	fprintf(outfile, "%.2lf, %.2lf, %.2lf, %.2lf, %.2lf, %d, %s:%s\n", totalCalories, totalDistance, totalFLoors, totalSteps, avgHR, maxStep, min1, min2 );
	print_array(f_test_arr, outfile, 1444);


	fclose(infile);
	fclose(outfile);



	return 0;
}