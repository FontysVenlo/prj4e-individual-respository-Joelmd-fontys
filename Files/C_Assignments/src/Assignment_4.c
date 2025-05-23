#include <stdlib.h>
#include <stdio.h>

void chessConverter(char row[], int *outRow, int *outCol) {
    // Validate input: Row should be '1'-'8', Col should be 'A'-'H'
    if (row[0] < '1' || row[0] > '8' || row[1] < 'A' || row[1] > 'H') {
        printf("Input Invalid, please enter a row from 1-8 and a column from A-H\n");
        return;
    }

    *outRow = row[0] - '1';  // Convert '1'-'8' → 0-7
    *outCol = row[1] - 'A';  // Convert 'A'-'H' → 0-7
}

int main() {
    char row[] = {'8', 'H'};  // Corrected: Use characters, not numbers
    int outR, outC;

    chessConverter(row, &outR, &outC);

    printf("Row: %d\n", outR);  // Expected output: 0
    printf("Col: %d\n", outC);  // Expected output: 0

    return 0;
}
