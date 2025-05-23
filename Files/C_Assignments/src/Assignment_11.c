//
// Created by Joel Malagarriga Duarte on 25.02.25.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum {
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY,
    INVALID_DAY
} Week;

// Global array to hold Week items
Week weekArray[3];
int weekCount = 0;  // Number of valid items stored

// Helper function: converts a string to the corresponding Week enum value.
// Comparison is case-insensitive.
Week stringToWeek(const char *str) {
    if (strcasecmp(str, "Sunday") == 0)      return SUNDAY;
    else if (strcasecmp(str, "Monday") == 0)   return MONDAY;
    else if (strcasecmp(str, "Tuesday") == 0)  return TUESDAY;
    else if (strcasecmp(str, "Wednesday") == 0)return WEDNESDAY;
    else if (strcasecmp(str, "Thursday") == 0) return THURSDAY;
    else if (strcasecmp(str, "Friday") == 0)   return FRIDAY;
    else if (strcasecmp(str, "Saturday") == 0) return SATURDAY;
    else return INVALID_DAY;
}

// Helper function: converts a Week enum value to a string.
const char* weekToString(Week day) {
    switch(day) {
        case SUNDAY:    return "Sunday";
        case MONDAY:    return "Monday";
        case TUESDAY:   return "Tuesday";
        case WEDNESDAY: return "Wednesday";
        case THURSDAY:  return "Thursday";
        case FRIDAY:    return "Friday";
        case SATURDAY:  return "Saturday";
        default:        return "Invalid";
    }
}

// Function 1: Reads up to N strings from the command prompt, converts each to a Week,
// and stores it in the global weekArray. An empty line stops the input.
void readWeekInput() {
    char buffer[50]; // Temporary buffer to store input
    printf("Enter up to %d days of the week (one per line).\n", 3);
    printf("Press Enter on an empty line to finish input.\n");

    for (int i = 0; i < 3; ) {
        printf("Day %d: ", i + 1);
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            // End-of-file encountered
            break;
        }
        // Remove the trailing newline character, if any.
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }
        // If the user enters an empty line, stop reading.
        if (strlen(buffer) == 0) {
            break;
        }

        Week day = stringToWeek(buffer);
        if (day == INVALID_DAY) {
            printf("Invalid day entered. Please try again (e.g., Monday).\n");
            continue; // do not increment i; ask for input again.
        }

        // Store the valid enum value and update the count.
        weekArray[i] = day;
        i++;
        weekCount = i;
    }
}

// Function 2: Sequentially prints the items stored in the global weekArray.
void printWeekArray() {
    printf("\nStored days:\n");
    for (int i = 0; i < weekCount; i++) {
        printf("%s\n", weekToString(weekArray[i]));
    }
}

int main(void) {
    readWeekInput();
    printWeekArray();
    return 0;
}