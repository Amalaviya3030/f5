/*
* FILE: f5.cpp
* PROJECT : Focused Assignment 5
* PROGRAMMER : Aryankumar Jitendrabhai Malaviya
* FIRST VERSION : 2024 - 02 - 20
* DESCRIPTION : Write a program that gets integers from the user and determines which is the highest value.
*/

#include <stdio.h>

// Disables a specific compiler warning
#pragma warning(disable: 4996)

// Function prototypes for get input from the user 
int getNum(void);

// Function prototypes for modify the values of an array based on user input
void modifyArrayValues(int myNumbers[], int size);

// Function prototypes for find index has the highest number
int maxArrayValue(int myNumbers[], int size);


int main(void) 
{
    // Declare an array for store 10 numbers.
    int numbers[10];

    // The array values are modified based on user input using the created function 
    modifyArrayValues(numbers, 10);

    // Which index has the highest number is checked by function 
    int maxIndex = maxArrayValue(numbers, 10);

    // print the highe number and that index
    printf("The highest number is %d at index %d.\n", numbers[maxIndex], maxIndex);

    return 0;
}

//Function to modify the values of an array based on user input
void modifyArrayValues(int myNumbers[], int size) 
{
    //Ask the user to enter an integer number
    printf("Enter %d integer numbers:\n", size);

    //runnig the Loop up to the size specified by the array
    for (int i = 0; i < size; i++) 
    {

        //The new value in the array is get from the user through the getNum function
        myNumbers[i] = getNum();

    }
}
//Function to find index has the highest number
int maxArrayValue(int myNumbers[], int size)
{

    int maxValue = 0;
    // running the loop for chake each element 
    for (int i = 1; i < size; i++) 
    {

        // Compare the all element with the element at the max Value index by if condition
        if (myNumbers[i] > myNumbers[maxValue])
        {

            //Update maxValue to the current index If the current element is greater
            maxValue = i;

        }
    }

    //returns the index of maxvalue 
    return maxValue;
}

int getNum()
{
    /* the array is 121 bytes in size; we'll see in a later lecture how we can
    improve this code */
    char record[121] = { 0 }; /* record stores the string */
    int number = 0;

    fgets(record, 121, stdin);
    /* extract the number from the string; sscanf() returns a number
    * corresponding with the number of items it found in the string */
    if (sscanf(record, "%d", &number) != 1)
    {
        /* if the user did not enter a number recognizable by
        * the system, set number to -1 */
        number = -1;
    }
    return number;
}
