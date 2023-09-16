#include<stdio.h>
#include <stdlib.h>
int GetMaxCaloryFromDataFile(FILE* calory_data_file) {
    char line[10];
    int calory_sum = 0,
    current_calory,
    max_calories = -1000;
    while (fgets(line, sizeof(line), calory_data_file) != NULL) {
        current_calory = atoi(line);
        if (current_calory == 0) {
            if (calory_sum > max_calories) {
                max_calories = calory_sum;
            }
            calory_sum = 0; // Here I made a logical error on this line. Now it is corrected.
        }
        else {
            calory_sum += current_calory;
        }
    }
    return max_calories;
}


int main(int argc, char* argv[]) {
    // Take input 
    FILE *calories_file;
    if (argc < 2) {
        fprintf(stderr, "File name must be provided as command line argument.");
        exit(EXIT_FAILURE);
    }

    calories_file = fopen(argv[1], "r");
    
    if (calories_file == NULL) {
        fprintf(stderr, "`%s` is unavailable. Check the path you've provided for the input file.\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    int max_calories = GetMaxCaloryFromDataFile(calories_file);
    printf("max calories = %d\n", max_calories);
}