/* This program takes number inputed from the command line and sorts them.
 * It will print the sorted list unless the -q flag is used. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>


int minimum_element_sort(int array[], int num_elements);
int bubble_sort(int array[], int num_elements);

/* Sorts elements of an array using minimum element sort.
 * Parameters are the array of integers which is to be sorter 
 * and the number os elements in the array.
 * The array that is inputed will be changed.
 */

int minimum_element_sort(int array[], int num_elements) {
    int start = 0;
    int smallest = start;
    int index = 0;
    int temp;
    while(start < num_elements) { /* Sorting useing minimum element sort. */
        /* First find the smallest element that hasn't been sorted yet. */
        smallest = start;
        for(index = start; index < num_elements; index ++) {
            if(array[index] <  array[smallest]) {
                smallest = index;
            }
        }
        /* Switch elements to put the next smallest element 
         * in the next spot. 
         */
        temp = array[start];
        array[start] = array[smallest];
        array[smallest] = temp;
        start ++;
    }
    return 0;
}

/* Sorts elements of an array using bubble sort.
 * Parameters are the array of integers to be sorted
 * and the number of elements in the array.
 * The array that is inputed will be changed. 
 */

int bubble_sort(int array[], int num_elements) {
    int swapped = 1;
    int index = 1;
    int temp;

    while (swapped == 1) { /* will repeat until no more swaps. */
        swapped = 0;
        for(index = 1; index < num_elements; index ++) {
            /* swap elements when the previous elements is larger */
            if(array[index] < array[index - 1]) {
                temp = array[index];
                array[index] = array[index - 1];
                array[index - 1] = temp;
                swapped = 1;
            }
        }
    }
    return 0;
}


int main(int argc, char *argv[]) {
    int index;
    int num_elements = 0;
    int input_array[32];
    int input_array_index = 0;
    int to_print = 1;
    int bubble = 0;

    for(index = 1; index < argc; index ++) { 
        /* Reading numbers and flags from command line. */
        if(strcmp(argv[index], "-q") == 0) {
            to_print = 0;
        }
        else if(strcmp(argv[index], "-b") == 0) {
            bubble = 1;
        }
        else {
            /* Check for correct number of inputs and exit if necessary. */
            if( (num_elements >= 32)) {
                fprintf(stderr, \
                    "usage: %s should have between 1 and 32 integers.\n", \
                    argv[0]);
                exit(1);
                                                        }

            input_array[input_array_index] = atoi(argv[index]);
            num_elements ++;
            input_array_index ++;
        }
    }
    
    /* Check for correct number of inputs and exit if necessary. */
    if((num_elements == 0) | (num_elements > 33)) {
        fprintf(stderr, \
                "usage: %s should have between 1 and 32 integers.\n", \
                argv[0]);
        exit(1);
    }


    /* Decide which type of sort and sort array. */
    if(bubble) {
        bubble_sort(input_array, num_elements);
    } else {
        minimum_element_sort(input_array, num_elements);
    }

    if(to_print == 1) { /* Printing elements unless -q flag is used. */
        for(index = 0; index < num_elements; index ++) {
            printf("%d\n", input_array[index]);
        }
    }

    return 0;
}
