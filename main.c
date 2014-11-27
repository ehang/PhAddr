/*************************************************************************
  > File Name: main.c
  > Author: uehang
  > Mail: uehang@gmail.com 
  > Created Time: 2014/10/16 17:46:00
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "phaddr.h"

#define DATAFILENAME "./data/PHADDR"

int main(int argc, char **argv){
	clock_t t1, t2, t3; 
	double del_time;
	char addr[64];
	//printf("start loading %s\n", DATAFILENAME);
	PhAddr pa = (PhAddr)malloc(sizeof(struct ph_addr));
	ph_init(pa);
	//load data
	t1 = clock();
	int cnt = ph_load_data(pa, DATAFILENAME);
	t2 = clock();
	//printf("loaded %d records\n.", cnt);
	//get address
	//printf("start searching %s\n", argv[1]);
	ph_get_addr(pa, argv[1], addr);
	t3 = clock();
	printf("%s\t%s\n", argv[1], addr);
	del_time = t2 - t1;
	printf("Time Take: Load  Data: %d\n", del_time);
	del_time = t3 - t2;
	printf("          Search Data: %d\n", del_time);
	return 0;
}

