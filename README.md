I don't want to write a readme here's the code

    // This program runs a number of iterations of Conway's Game of life
    // 
    // Read from the back buffer, perform some game logic and write
    // the result to the front buffer every iteration.
    
    // printf, putchar
    #include <stdio.h>
    
    // malloc, free, rand, srand
    #include <stdlib.h>
    
    // time
    #include <time.h>
    
    // This is just for ease of typing
    typedef unsigned char uint8;
    typedef char int8;
    
    // Width and height of the board defined at compile time.
    const uint8 width =  50;
    const uint8 height = 25;
    
    // Define the pointers to the front and back buffers
    uint8** data;
    uint8** back;
    
    void draw() {
    
      // Iterate through the dataset and print the values to the terminal
    
      for(uint8 i = 0; i < height; ++i) {
        for(uint8 j = 0; j < width; ++j) {
          // If the cell is alive print a # if dead print a space
          putchar(data[i][j] ? 0x23 : 0x20 );
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
    
      // Allocate the memory for the row pointers
      data = (uint8**)malloc(sizeof(uint8*) * height);
      back = (uint8**)malloc(sizeof(uint8*) * height);
    
      for(uint8 i = 0; i < height; ++i) {
    
        // Allocate the memory for the columns
        data[i] = (uint8*)malloc(sizeof(uint8) * width);
        back[i] = (uint8*)malloc(sizeof(uint8) * width);
    
        // 50 percent of cells are to be set alive
        for(uint8 j = 0; j < width; ++j) {
          if(rand() % 10 > 4) {
          	data[i][j] = 1;
          } else {
          	data[i][j] = 0;
          }
        }
      }
    
    }
    
    void deinit() {
      // Free all the rows before we free all the columns
      for(uint8 i = 0; i < height; ++i) {
        free(data[i]);
        free(back[i]);
      }
      free(data);
      free(back);
    }
    
    // These define the neighbor cell offsets
    const int8 si[8] = {-1,0,1,0,-1,1,-1,1};
    const int8 tj[8] = {0,1,0,-1,-1,-1,1,1};
    
    void update() {
    
      // Iterate through every row and every column of the back buffer
      // in order to set an appropriate value for the back buffer 
    
      for(uint8 i = 0; i < height; ++i) {
        for(uint8 j = 0; j < width; ++j) {
          uint8 p = 0;
    
          // Iterate through every neighboring positions
          for(uint8 k = 0; k < 8; ++k) {
    	int8 s = si[k];
    	int8 t = tj[k];
    	// we don't want to access outside of the array bounds
    	if(s + i < 0 || s + i >= height || t + j < 0 || t + j >= width) continue;
    	p += data[s+i][t+j];
          }
    
          // Here's the actual life logic, p is the total population of the neighbor cells of cell i,j
    
          // If the population is 2 then the cell's state remains
          if(p == 2) {
    	back[i][j] = data[i][j];
    	continue;
          }
    
          // If the population is 3 then the cell brought alive
          if(p == 3) {
    	back[i][j] = 1;
    	continue;
          }
    
          // Any other state has the cell be killed
          back[i][j] = 0;
        }
      }
    
      // Swap the pointers of the back buffer and the data buffer
      uint8** tmp = back;
      back = data;
      data = tmp;
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
        update();
      }
    
      deinit();
      
      // Return 0
      return EXIT_SUCCESS;
    }
    