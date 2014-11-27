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
		printf("open file \"%s\" failed: %s\n", data_file_name, strerror(errno));
		return 0;
	}

	//printf("open file success \"%s\"\n", data_file_name);
	while(1){
		if(readline(fd, buf, 64)<=0){
			break;
		}

		if(ph_insert_node(pa, buf) != 1){
			break;
		}
		//if((res % 10000) == 0){
		//	printf("now loading %s\n", buf);
		//}
		res ++;
	}
	close(fd);
	//printf("loading is over.\n");
	return res;
}

int ph_insert_node(PhAddr pa, char *buf)
{
	int rc = 0;
	int index1 = get_addr_index(pa->index_l1_str, buf);
	if((pa->index_l1)[index1] == NULL){
		(pa->index_l1)[index1] = (void *)malloc(INDEX_L2_CNT * 64);
	}
	int index2 = get_addr_index(pa->index_l2_str, buf+3);
	strncpy((pa->index_l1)[index1]+index2*64, buf+8, 52);
	rc = 1;
	return rc;
}

void ph_get_addr(PhAddr pa, char *phone, char *addr)
{
	strcpy(addr, "NULL");
	int index1 = get_addr_index(INDEX_L1_STR, phone);
	if((pa->index_l1)[index1] == NULL)
		return;
	int index2 = get_addr_index(INDEX_L2_STR, phone+3);
	strncpy(addr, (pa->index_l1)[index1] + index2*64, 64);
}

void ph_init(PhAddr pa)
{
	memset(pa, 0, sizeof(struct ph_addr));
	strncpy(pa->index_l1_str, INDEX_L1_STR, 3);
	strncpy(pa->index_l2_str, INDEX_L2_STR, 4);
}
int readline(int fd, void *vptr, size_t maxlen)
{
	int  n, rc;
	char c, *ptr;

	ptr = vptr;
	for(n=0; n<maxlen; n++){
		if((rc=read(fd, &c, 1))==1){
			if(c == '\n'){
				break;
			}
			*ptr = c;
			ptr ++;
		}else if(rc == 0){
			*ptr = 0;
			return(n);
		}else{
			printf("read file error: %s.\n", strerror(errno));
			return (-1);
		}
	}
	*ptr = 0;
	return n;
}

int get_addr_index(char *str_index, char *buf)
{
	int rc = 0;
	char *pstr, *pbuf;
	pstr = str_index;
	pbuf = buf;
	while((*pstr) != 0){
		rc = (*pbuf) - (*pstr) + 10*rc;
		pstr ++;
		pbuf ++;
	}
	return rc;
}
