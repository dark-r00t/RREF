#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N;
int M;

double** getMatrix(char* file);
void printMatrix(double **matrix);
void rref(double **matrix);
void initMatrix(double **matrix);
void rowSwap(double **matrix, int a, int b);
void onesPivot(double** matrix, int row, int col, double pivot);
void multAdd(double** matrix, int row1, int row2, int col, double remove) ;

int main(int argc, char** argv) {

	// Take in an input file.
	double** matrix = getMatrix(argv[1]);
	if(!matrix) return 1;

	printMatrix(matrix);
	rref(matrix);
	printMatrix(matrix);
}	

double** getMatrix(char* text) {

	FILE* in = fopen(text, "r");
	if(!in) return NULL;

	fscanf(in, "%d %d", &N, &M);

	double **matrix = (double**) malloc(sizeof(double*) * N);
	for(int i = 0; i<N; i++) {
		matrix[i] = (double*) malloc(sizeof(double) * M);
	}

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			fscanf(in, "%lf", &matrix[i][j]);
		}
	}

	return matrix;
}

void printMatrix(double **matrix){

	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			printf("%.2lf\t", matrix[i][j]);
		} printf("\n");
	} printf("\n");
}

void rref(double **matrix) {

	int row = 0, col = 0;

	initMatrix(matrix);

	for(row=0; row<N; row++){
		while( matrix[row][col] == 0 && col<M) col++;

		onesPivot(matrix, row, col, matrix[row][col]);

		for(int j = row+1; j<N; j++)
	    	if( matrix[j][col] )
				multAdd(matrix, row, j, col, matrix[j][col]);

		if(row)
	    	for(int j = row; j>0; j--)
				multAdd(matrix, row, j-1, col, matrix[j-1][col]);

		col++;
    }
}

void initMatrix(double **matrix) {

	for(int i = 0; i < N-1; i++)
		for(int j = i+1; j < N; j++)
			if( matrix[i] < matrix[j] )
				rowSwap(matrix, i, j);

	printMatrix(matrix);
}

void rowSwap(double **matrix, int a, int b) {
	
	double* t = *(matrix+a);
	*(matrix+a) = *(matrix+b);
    *(matrix+b) = t;
}

void onesPivot(double** matrix, int row, int col, double pivot) {

	if(col>=M) return;

	matrix[row][col] = matrix[row][col] / pivot;
	onesPivot(matrix, row, ++col, pivot);
}

void multAdd(double** matrix, int row1, int row2, int col, double remove) {

	if(col >= M) return;

	matrix[row2][col] = (matrix[row1][col] * remove * -1) + matrix[row2][col];
	multAdd(matrix, row1, row2, ++col, remove);
}
