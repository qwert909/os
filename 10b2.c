#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/mman.h>

void main(int argc, char* argv[]){
	
	int m = atoi(argv[1]);
	int n = atoi(argv[2]);
	int fd, i, j,flag;
	int* shared_memory;
	
	fd = shm_open("OS", O_RDWR , 0666);
	shared_memory = (int*)mmap(NULL,1024, PROT_WRITE, MAP_SHARED, fd, 0);
	
	printf("\nChild Printing:\n");
	int k=0;
	for(i=m;i<=n;i++){
		flag=0;
		for(j=2;j<=i/2;j++){
			if (i%j==0){
				flag=1;
				break;
			}
		}
		if (flag==0){
			shared_memory[k++] = i;
			printf("%d ",i);
		}
	}
	shared_memory[k]=0;
	
}
