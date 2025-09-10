#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <fcntl.h>

void main(){
	int fd, n;
	int *shared_memory;
	
	fd = shm_open("OS",O_CREAT|O_RDWR, 0666);
	ftruncate(fd,1024);
	shared_memory = (int*)mmap(NULL, 1024, PROT_READ, MAP_SHARED, fd, 0);
	
	printf("Enter n>> ");
	scanf("%d",&n);
	char nstr[20];
	sprintf(nstr, "%d", n);
	
	if (fork()==0){
		execlp("./fib","fib",nstr,NULL);
	}
	else{
		wait(NULL);
		printf("\n[PARENT] Child completed\n");
        printf("Parent printing:\n");
		for(int i=0;i<n;i++){
			printf("%d ",shared_memory[i]);
		}
		printf("\n");
		
		shm_unlink("OS");
	
	}
}
