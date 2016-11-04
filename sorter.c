/* This program takes number inputed from the command line and sorts them.
 * It will print the sorted list unless the -q flag is used. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char *argv[]) {
    int index;
    int num_elements = 0;
    int input_array[32];
    int input_array_index = 0;
    int start = 0;
    int smallest = start;
    int to_print = 1;
    int temp;


    for(index = 1; index < argc; index ++) { 
        /* Reading numbers and flags from command line. */
        if(strcmp(argv[index], "-q") == 0) {
            to_print = 0;
            assert(to_print == 0);
        }
        else if(strcmp(argv[index], "-b") == 0) {
            temp = temp;
        }
        else {
            /* Check for correct number of inputs and exit if necessary. */
            if( (num_elements >= 32)) {
                fprintf(stderr, \
                    "usage: %s should have between 1 and 32 integers.\n", \
                    argv[0]);
                exit(1);
                                                        }

            assert(num_elements < 32);
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


    while(start < num_elements) { /* Sorting useing minimum element sort. */
        smallest = start;
        for(index = start; index < num_elements; index ++) {
            if(input_array[index] <  input_array[smallest]) {
                assert(input_array[index] < input_array[smallest]);
                smallest = index;
            }

        }
        temp = input_array[start];
        input_array[start] = input_array[smallest];
        input_array[smallest] = temp;
        start ++;

    }

    if(to_print == 1) { /* Printing elements unless -q flag is used. */
        for(index = 0; index < num_elements; index ++) {
            printf("%d\n", input_array[index]);
        }
    }

    return 0;
}
