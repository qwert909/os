#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/shm.h>

void main(int argc, char* argv[]){
	int n,i,shmid;
	int *shared_memory;
	
	n = atoi(argv[1]);
	
	shmid = shmget((key_t)110011,1024,0666);
	shared_memory = (int*)shmat(shmid,NULL,0);
	
	printf("\nChild Printing:\n");
	int j=0;
	for(i=1;i<2*n;i++){
		if (i%2!=0){
			shared_memory[j] = i;
			printf("%d ",i);
			j++;
		}
	}
	shmctl(shmid,IPC_RMID,NULL);	
}
