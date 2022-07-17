#define SIZE 4

/*
GENERATES:
16 12 8  4
12 9  6  3
8  6  4  2
4  3  2  1
*/
for(int i =0; i<SIZE*SIZE;i++) {
	int p = SIZE*SIZE - i - 1;  
	matrix[i/SIZE][i%SIZE] = (p%SIZE) + (p/SIZE) + ((p%SIZE) * (p/SIZE)) + 1;
}	

/*
PRINTS A SIZE*SIZE MATRIX
*/
for(int i = 0; i<SIZE; i++) {
	printf("%.2lf\t", matrix[i/SIZE][i%SIZE]);
	if((i+1)%SIZE == 0) printf("\n");
} printf("\n");
