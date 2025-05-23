//
// Created by Joel Malagarriga Duarte on 25.02.25.
//

#include "../inc/Assignment_8.h"
#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

void rectangle(int w, int h){
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      printf("*");
    }
    printf("\n");
  }
}


// Equation of a circle: (x - h)^2 + (y - k)^2 = r^2
// Where:
// - (h, k) is the center of the circle (centerX, centerY in our case)
// - r is the radius
// - (x, y) are points on the circle's border
// We check if the distance from any point (x, y) to the center (centerX, centerY)
// is approximately equal to the radius r to determine if it's on the border
void circle(int x, int y, int r) {
  int i, j;

  // Set a grid size large enough to fit the circle
  int gridSize = 2 * r + 1;

  for (i = 0; i < gridSize; i++) {
    for (j = 0; j < gridSize; j++) {
      int gridX = i - r + x; // The actual x coordinate on the grid
      int gridY = j - r + y; // The actual y coordinate on the grid

      // Calculate the distance from the center (x, y)
      double distance = sqrt(pow(gridX - x, 2) + pow(gridY - y, 2));

      // If the point is close enough to the circle's border, print '*'
      //fabs to convert float into int
      if (fabs(distance - r) < 0.5) {
        printf("*");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}

int main(){

  rectangle(5,5);
  circle(10, 10, 8);
  return 0;
}
