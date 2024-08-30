#include <stdio.h>
#include <stdlib.h>

// function declaration 
double **allocAndFillArray( int  length, int width );
void freeArray( double** array, int length );

int main (int argc, char **argv) {

    double** array,sum;
    int i;

    array = allocAndFillArray( 3,5 );//rows * cols

    //use your array here
    //What is wrong with the following code?  Try valgrind on it.
    /*
    for( i=0; i<3; i++ )
      sum = sum + array[i][0];

    printf("%lf\n",sum);
    */

    freeArray( array, 3 );

    return 0;
}

double **allocAndFillArray( int  length, int width ) {

    int i, j;
    /* array of doubles of doubles '*'s of size length*/
    //Not allowed; double[length][width]
    // (/*type of variable*/)malloc(/*size of(type in the array) * # you want to stroe*/ ); 
    double** array = (double**)malloc( sizeof(double*) * length); //3 

    for (i = 0; i < length; i ++){
        array[i] = (double*)malloc(sizeof(double) * width); // 8 * 5 = 40bytes
    }
    

    //malloc array and store into array[i][j] the double i.j (assume i,j<10)
    //example: i = 2, j = 3 then array[2][3] = 2.3

    //free(array);
    
    //return array;
}

void freeArray( double** array, int length ){
    //Free the malloced data in the array
}






