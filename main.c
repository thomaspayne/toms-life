// This program runs a number of iterations of Conway's Game of life
// 
// It performs the following steps every iteration:
// - read from the back buffer
// - perform some game logic
// - write the result to the back buffer
// - swap back and front buffer
// - print data to screen

// printf, putchar
#include <stdio.h>

// malloc, free, rand, srand
#include <stdlib.h>

// time
#include <time.h>

// uint8, int8
#include "defs.h"

// life
#include "life.h"

// Width and height of the board defined at compile time.
const uint8 width =  50;
const uint8 height = 25;

life* l;

void draw() {
  // Iterate through the dataset and print the values to the terminal
  for(uint8 i = 0; i < height; ++i) {
    for(uint8 j = 0; j < width; ++j) {
      // If the cell is alive print a # if dead print a space
      putchar(l->data[i][j] ? 0x23 : 0x20 );
    }
    putchar(0x0A);
  }

  // Draw a line to finalise the frame
  for(uint8 j = 0; j < width; ++j) {
    putchar(0x2D);
  }

  // Print a newline
  putchar(0x0A);
}

void init() {
  // Seed the RNG
  srand(time(0));
  // Allocate the life structure
  l = life_create(width, height);
}

void deinit() {
  // Free the life structure
  life_destroy(l);
}

int main() {

  // Initialises the memory and seeds the RNG
  init();

  // Run 100 iterations
  uint8 i = 100;
  while(i-- > 0) {
    // Print contents of the data buffer to the terminal
    draw();
    // Run the life logic
    life_step(l);
  }

  deinit();
  
  // Return 0
  return EXIT_SUCCESS;
}
