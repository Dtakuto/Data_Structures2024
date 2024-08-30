#include <stdio.h>
#include <stdlib.h>

#define WIDTH 15
#define LENGTH 10

int** mallocInt2DArray(int width, int length);
void free2DArray(int** array, int width);

int main(int argc, char* argv[]) {
  int** array = mallocInt2DArray( WIDTH, LENGTH );
  int i, j;
  
  for( i=0; i<LENGTH; i++ ){
    for( j=0; j<WIDTH; j++ )
	  printf("%d ", array[i][j]);
    printf("\n");
  }
  
  free2DArray(array, LENGTH); //Should instead pass WIDTH since that is the number of malloced rows

  return 0; 
}

/* Returns a 2d int array with the given length and width.
 * @warning mallocs memory so be sure to free the returned pointer in your code
 */
int** mallocInt2DArray(int width, int length) {
  int **array = (int**)malloc(sizeof(int*) * width);
  int i, j;
  
  for( i=0; i<width; i++ ){
	array[i] = (int*)malloc(sizeof(int) * length);
	
    for( j=0; j<length; j++ )
	  array[i][j] = 1337;
  }
  
  return array;
}

/* Returns a 2d int array with the given length and width.
 * @warning assumes array is a malloced 2d array with width rows
 */
void free2DArray(int** array, int width) {
  int i;
  
  free(array);  //Should be freed after the loop below since we need to access the contents of array
  for( i=0; i<width; i++ )
	free(array[i]);
}