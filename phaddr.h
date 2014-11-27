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
#include <errno.h>   // for errno, use strerror(errno)
#include <string.h>  // for memset(), strncpy()
#include <stdlib.h>  // for malloc(), strerror()

#define INDEX_L1_STR "130"
#define INDEX_L2_STR "0000"
#define INDEX_L1_CNT 60
#define INDEX_L2_CNT 10000

typedef void * pVoid;
typedef struct ph_addr* PhAddr;
typedef struct addr_node* AddrNode;

struct ph_addr{
	char index_l1_str[6];
	char index_l2_str[10];
	void *index_l1[INDEX_L1_CNT];
};
struct addr_node{
	char phone_head[12];
	char address[52];
};


/*
 * load data:
 * return 0: none data
 *       >0: the count of data
 */
int ph_load_data(PhAddr pa, char *data_file_name);

/*
 * @para: pa ->the destination PhAddr
 *        buf->temple XXXXXXX\tXXXXX...
 *                   (telephone head\taddr) 
 */
int ph_insert_node(PhAddr pa, char *buf);

/*
 *
 */
void ph_get_addr(PhAddr pa, char *phone, char *addr);

void ph_init(PhAddr pa);

/*
 *
 */
int readline(int fd, void *vptr, size_t maxlen);

int get_addr_index(char *str_index, char *buf); 

#endif
