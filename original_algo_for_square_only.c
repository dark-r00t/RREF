for(int i =0; i<16;i++) {
	int p = 16 - i - 1;  
	matrix[i/4][i%4] = (p%4) + (p/4) + ((p%4) * (p/4)) + 1;
}	
	
for(int i = 0; i<SIZE; i++) {
	printf("%.2lf\t", matrix[i/SIZE][i%SIZE]);
	if((i+1)%SIZE == 0) printf("\n");
} printf("\n");
