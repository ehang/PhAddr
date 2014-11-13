/*************************************************************************
    > File Name: phaddr.c
    > Author: uehang
    > Mail: uehang@gmail.com 
    > Created Time: 2014/10/16 17:46:26
 ************************************************************************/

#include "phaddr.h"

int ph_load_data(PhAddr pa, char *data_file_name)
{
	int res = 0;
	char buf[64];
	int fd = open(data_file_name,O_RDONLY);
	if(fd < 3){
		printf("open file \"%s\" failed: %s", data_file_name, stderror(errno));
		return 0;
	}
	
	return res;
}
