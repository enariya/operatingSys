
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/types.h>
#include <time.h>
#include <pthread.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include "share.h"

void func(void) {
	shm_unlink("osp1");
}

int main(){
    srand(time(NULL));//rand seed 
	atexit(func);
    int num = 15,tmp=0,fd = shm_open("osp1", O_CREAT | O_RDWR, 0666);
	if(fd < 0){
        	printf("Initialization of shared memory failed.\n");
        	return 0;
    	}
	ftruncate(fd, 1024);
	struct data *m = mmap(NULL, 1024, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
	m->table[0] = -1;
    	m->table[1] = -1;
	sem_init(&m->mutex, 1, 1);   	
	while(num > 0){//while loop
		sem_wait(&m->mutex);
		printf("Producer is producing.\n");
		if(m->table[tmp] == -1) 
        	{
			int randNum = rand() % 1000 + 1;
			m->table[tmp] = randNum;
			printf("id %d: filling with item: %d \n", tmp, randNum);
			tmp++;
		}
		else 
			printf("id %d: filled, recheck happens in next critical section\n", tmp);
		
		if(tmp > 1) 
			tmp = 0;
		
		num--;
		sem_post(&m->mutex);
		sleep(1);
	}
}