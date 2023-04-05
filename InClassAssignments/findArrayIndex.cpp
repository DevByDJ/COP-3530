//  File: find_arr_ndx.cpp
// Class: COP 3530, Spring 2023
//  Name: Danny Joseph
//  Desc: Find the index of a value in an array
// --------------------------------------------------------
//  Write function [below main()] that returns the index
//  of a value in the array or -1 if the value does not exist
//
//  Declare an index variable in main and assign it the return
//  from your search function. Check the return value and output
//  a message similar to the below:  (replace # with numbers)
//  "The value # was not found" if -1 returned, or
//  "The value # was found at index #" if found.
// --------------------------------------------------------
#include <iostream>
#include <cstdlib>  // random numbers
#include <ctime>    // seed value for srand()

int ARRAY_SIZE = 20;    // number of array elements
int MAX_VALUE = 100;    // max value in the array

int findArrayIndex (int arrayToCompare[], int valueToCompare);


int main() {

    // init random numbers
    std::srand(std::time(NULL));

    // declare the array variable
    int theArray[ARRAY_SIZE];

    // populate array with random numbers
    for (int i=0; i < ARRAY_SIZE; i++ ) {
        theArray[i] = rand() % MAX_VALUE + 1;   // between 1 & MAX_VALUE
    }

    // print the contents of the array
    std::cout << "Array = {";
    for (int i=0; i < ARRAY_SIZE; i++ ) {
        std::cout << theArray[i];
        if (i < ARRAY_SIZE - 1)
            std::cout << ",";
    }
    std::cout << "}" << std::endl;

    // keep asking user for a value to find until they are done
    char done;
    do {
        // prompt for value to find
        int indexOf;
        std::cout << "\nEnter a value to find: ";
        std::cin >> indexOf;

        int result;
        result = findArrayIndex(theArray, indexOf);
        std::cout << "\nThe Result is = " << result;

        // prompt user to go again
        std::cout << "\nTry again? (Y/N): ";
        std::cin >> done;
    } while (done == 'Y' || done == 'y');

    return 0;
}
int findArrayIndex (int arrayToCompare[], int valueToCompare)
{

  for(int i = 0; i < ARRAY_SIZE; i++)
  {
    if(arrayToCompare[i] == valueToCompare)
    {
      valueToCompare = i;
      return valueToCompare;
    }
  }
  
valueToCompare = -1;  
return valueToCompare;

}
