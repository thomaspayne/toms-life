#include "life.h"

life* life_create(uint8 width, uint8 height) {

  life* l = (life*)malloc(sizeof(life));

  l->width = width;
  l->height = height;

  // Allocate the memory for the row pointers
  l->data = (uint8**)malloc(sizeof(uint8*) * l->height);
  l->back = (uint8**)malloc(sizeof(uint8*) * l->height);

  for(uint8 i = 0; i < height; ++i) {
    // Allocate the memory for the columns
    l->data[i] = (uint8*)malloc(sizeof(uint8) * l->width);
    l->back[i] = (uint8*)malloc(sizeof(uint8) * l->width);

    // 50 percent of cells are to be set alive
    for(uint8 j = 0; j < l->width; ++j) {
      if(rand() % 10 > 4) {
	l->data[i][j] = 1;
      } else {
      	l->data[i][j] = 0;
      }
    }
  }

  return l;
}

// These define the neighbor cell offsets
const int8 si[8] = {-1,0,1,0,-1,1,-1,1};
const int8 tj[8] = {0,1,0,-1,-1,-1,1,1};

void life_step(life* l) {
  // Iterate through every row and every column of the back buffer
  // in order to set an appropriate value for the back buffer 

  for(uint8 i = 0; i < l->height; ++i) {
    for(uint8 j = 0; j < l->width; ++j) {
      uint8 p = 0;

      // Iterate through every neighboring positions
      for(uint8 k = 0; k < 8; ++k) {
	int8 s = si[k];
	int8 t = tj[k];
	// we don't want to access outside of the array bounds
	if(s + i < 0 || s + i >= l->height || t + j < 0 || t + j >= l->width) continue;
	p += l->data[s+i][t+j];
      }

      // Here's the actual life logic, p is the total population of the neighbor cells of cell i,j

      // If the population is 2 then the cell's state remains
      if(p == 2) {
	l->back[i][j] = l->data[i][j];
	continue;
      }

      // If the population is 3 then the cell brought alive
      if(p == 3) {
	l->back[i][j] = 1;
	continue;
      }

      // Any other state has the cell be killed
      l->back[i][j] = 0;
    }
  }

  // Swap the pointers of the back buffer and the data buffer
  uint8** tmp = l->back;
  l->back = l->data;
  l->data = tmp;
}

void life_destroy(life* l) {
  // Free all the rows before we free all the columns
  for(uint8 i = 0; i < l->height; ++i) {
    free(l->data[i]);
    free(l->back[i]);
  }
  free(l->data);
  free(l->back);
}

