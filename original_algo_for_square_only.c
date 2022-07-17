#define SIZE 4

/*
GENERATES:
16 12 8  4
12 9  6  3
8  6  4  2
4  3  2  1

REMOVING THE LINE: "int p = SIZE*SIZE - i - 1;"
GENERATES:
1  2  3  4
2  4  6  8
3  6  9 12
4  8 12 16
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
