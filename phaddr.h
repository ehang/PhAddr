/*************************************************************************
    > File Name: phaddr.h
    > Author: uehang
    > Mail: uehang@gmail.com 
    > Created Time: 2014/10/16 17:46:13
 ************************************************************************/
#ifndef _PHADDR_H
#define _PHADDR_H

#include <stdio.h>   // for printf()
#include <fcntl.h>   // for open()
#include <sys/stat.h>// for model O_RDONLY|O_RDWR|O_WRONLY
#include <unistd.h>  // for close(), read(), write()
#include <errno.h>   // for errno, use stderror(errno)

#define INDEX_L1_STR "130"
#define INDEX_L2_STR "0000"
#define INDEX_L1_CNT 60
#define INDEX_L2_CNT 10000

typedef void * pVoid;
typedef struct ph_addr PhAddr;
typedef struct addr_node AddrNode;

struct ph_addr{
	void *index_l1[INDEX_L1_CNT];
}
struct addr_node{
	char phone_head[12];
	char address[52];
}


/*
 * load data:
 * return 0: none data
 *       >0: the count of data
 */
int ph_load_data(PhAddr pa, char *data_file_name);

/*
 *
 */
int ph_insert_node(PhAddr pa, AddrNode an);

/*
 *
 */
void ph_get_addr(PhAddr pa, char *phone, char *addr);

#endif
