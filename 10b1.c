#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/mman.h>

void main(int argc, char* argv[]){
	
	if (argc<3){
		printf("Didn't pass range\n");
		exit(0);
	}
	
	int fd;
	int* shared_memory;
	
	fd = shm_open("OS", O_CREAT|O_RDWR , 0666);
	ftruncate(fd,1024);
	shared_memory = (int*)mmap(NULL,1024, PROT_WRITE, MAP_SHARED, fd, 0);
	
	if (fork()==0){
		execlp("./prime", "prime", 	argv[1], argv[2], NULL);	
	}
	else{
		wait(NULL);
		
		printf("\n[PARENT] Child completed\n");
        printf("Parent printing:\n");
        int i=0;
		while(shared_memory[i]!=0){
			printf("%d ",shared_memory[i++]);
		}
		printf("\n");
		shm_unlink("OS");
	}
}
