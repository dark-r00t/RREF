#include <stdio.h>
#include <stdlib.h>

#define N 4
#define M 4

void printMatrix(double **matrix);
void rref(double **matrix, int n, int m);
void initMatrix(double **matrix, int n, int m);
void rowSwap(double **matrix, int a, int b, int n, int m);
void onesPivot(double** matrix, int row, int col, int m);
void multAdd(double** matrix, int row1, int row2, int col, int m) ;

int main(void) {

	double **matrix = (double**) malloc(sizeof(double*) * N);
	for(int i = 0; i<N; i++) {

		matrix[i] = (double*) malloc(sizeof(double) * M);
	}

	for(int i =0; i<16;i++) {										// 16	12	 8	 4
																	// 12	9	 6 	 3 
		int p = 16 - i - 1;											// 8    6    4   2   
		matrix[i/4][i%4] = (p%4) + (p/4) + ((p%4) * (p/4)) + 1;		// 4    3    2   1
	}

	printMatrix(matrix);

	rref(matrix, N, M);

	printMatrix(matrix);
}	

void printMatrix(double **matrix) {
	
	for(int i = 0; i<16; i++) {

		printf("%.2lf\t", matrix[i/4][i%4]);
		if((i+1)%4 == 0) printf("\n");
	} 

	printf("\n");
}

void rref(double **matrix, int n, int m) {

	int row = 0, col = 0;

	initMatrix(matrix, n, m);

	for(row=0; row<n ;row++){

		while( *(*(matrix+row)+col ) == 0 && col<m) col++;

		onesPivot(matrix, row, col, m);

		for(int j = row+1; j<n; j++){

	    	if( *(*(matrix + j)+col) ){

				multAdd(matrix, row, j, col, m);
	    	}
		}

		if(row){

	    	for(int j = row;j>0;j--){

				multAdd(matrix, row, j-1, col, m);
	   		}
		}

		col++;
    }
}

void initMatrix(double **matrix, int n, int m) {

	for(int i = 0; i < n-1; i++) {

		for(int j = i+1; j < n; j++) {

			if( *(*matrix+i) < *(*(matrix+j)) ) {
				rowSwap(matrix, i, j, n, m);
			}
		}
	}

	printMatrix(matrix);
}

void rowSwap(double **matrix, int a, int b, int n, int m) {
	double* t = *(matrix+a);
	*(matrix+a) = *(matrix+b);
    *(matrix+b) = t;

    //*(matrix+a) += *(matrix+b) – (*(matrix+b) = *(matrix+a));
}

void onesPivot(double** matrix, int row, int col, int m) {

	double pivot = *(*(matrix+row)+col); 

    for(int i = col; i < m; i++){

		*(*(matrix+row)+i) = (*(*(matrix+row)+i) / pivot);
	}
}

void multAdd(double** matrix, int row1, int row2, int col, int m) {

	double remove = *(*(matrix+row2)+col);

    for(int i = col; i < m; i++){

		*(*(matrix+row2)+i) = (*(*(matrix+row1)+i)*remove*-1) + *(*(matrix+row2)+i);
    }
}
