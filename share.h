#ifndef SHARE_H
#define SHARE_H

#include <stdlib.h>
#include <semaphore.h>

struct data 
{
	int table[2];//two item buffer.
	sem_t mutex;
};

#endif