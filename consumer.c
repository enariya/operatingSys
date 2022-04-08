#include "share.h"
#include <stdio.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pthread.h>
sem_t lock;
void func(void) 
{
	shm_unlink("osp1");
}

int main(int argc, char *argv[]) 
{
    atexit(func);    
    int num = 15, fd = shm_open("osp1", O_RDWR, 0666),tmp=1;
	if(fd < 0) {
        	printf("Fail! couldn't open the file.\n");
		return 0;
    	}
	ftruncate(fd, 1024);
	struct data *m = mmap(NULL, 1024, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);	
	while(num > 0) {
		sem_wait(&m->mutex);
		printf("Consumer is consuming.\n");

		if(m->table[tmp] > -1) {
			printf("id %d: filled with item: %d. clearing in progress\n", tmp, m->table[tmp]);
			m->table[tmp] = -1;
			tmp++;
		}
		else
			printf("Empty table, next attempt will happem in next critical section\n");
		if(tmp > 1)
			tmp=0;
		num--;
		sem_post(&m->mutex);
		sleep(1);
	}
}