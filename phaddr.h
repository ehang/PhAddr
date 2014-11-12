/*************************************************************************
    > File Name: phaddr.h
    > Author: uehang
    > Mail: uehang@gmail.com 
    > Created Time: 2014/10/16 17:46:13
 ************************************************************************/
#ifndef _PHADDR_H
#define _PHADDR_H

#include <stdio.h>

#define INDEX_L1_STR "130"
#define INDEX_L2_STR "0000"
#define INDEX_L1_CNT 60
#define INDEX_L2_CNT 10000

typedef void * pVoid;

struct addr_node{
	char ph_head[8];
	char addr[40];
}

struct ph_addr{
	pVoid index_l1[INDEX_L1_CNT];


/*
 *
int ph_insert_node(PhAddr pa, AddrNode an);

void ph_get_addr(PhAddr pa, char *phone, char *addr);
#endif
