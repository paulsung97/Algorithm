#include <stdio.h>
#include <stdlib.h>
#include "23-2020_12_07-2.h"
#include "25-2020_12_11.h"

static int hash(int key, int size)
{
	return key % size;
}


static int rehash(int key, int size)
{
	return(key + 1) % size;
}


static void SetBucket(Bucket* n, const Member* x, Status stat)
{
	n->data = *x;		
	n->stat = stat;		
}


int Initialize(ClosedHash* h, int size)
{
	int i;
	if ((h->table = calloc(size, sizeof(Bucket))) == NULL) {
		h->size = 0;
		return 0;
	}
	h->size = size;
	for (i = 0; i < size; i++)		
		h->table[i].stat = Empty;	
	return 1;
}

Bucket* Search(const ClosedHash* h, const Member* x)
{
	int i;
	int key = hash(x->no, h->size); 
	Bucket* p = &h->table[key];		

	for (i = 0; p->stat != Empty && i < h->size; i++) {
		if (p->stat == Occupied && p->data.no == x->no)
			return p;
		key = rehash(key, h->size); 
		p = &h->table[key];
	}
	return NULL;
}


int Add(ClosedHash* h, const Member* x)
{
	int i;
	int key = hash(x->no, h->size);	
	Bucket* p = &h->table[key];

	if (Search(h, x)) 
		return 1;

	for (i = 0; i < h->size; i++) {
		if (p->stat == Empty || p->stat == Deleted) {
			SetBucket(p, x, Occupied);
			return 0;
		}
		key = rehash(key, h->size); 
		p = &h->table[key];
	}

	return 2; 
}


int Remove(ClosedHash* h, const Member* x)
{
	Bucket* p = Search(h, x);
	if (p == NULL)
		return 1; 
	p->stat = Deleted;
	return 0;
}


void Dump(const ClosedHash* h)
{
	int i;
	for (i = 0; i < h->size; i++) {
		printf("%02d : ", i);

		switch (h->table[i].stat) {
		case Occupied: printf("%d(%s)\n",
			h->table[i].data.no, h->table[i].data.name);	break;
		case Empty: printf("-- 미등록 --\n");				break;
		case Deleted: printf("-- 삭제 마침 --\n");			break;
		}
	}
}

/*--- 모든 데이터 삭제 ---*/
void Clear(ClosedHash* h)
{
	int i;
	for (i = 0; i < h->size; i++) /* 모든 버킷을 */
		h->table[i].stat = Empty; /* 공백으로 만듭니다. */
}

/*--- 해시 테이블 종료 ---*/
void Terminate(ClosedHash* h)
{
	Clear(h);			/* 모든 데이터 삭제 */
	free(h->table);		/* 해시 테이블 배열의 메모리 해제 */
	h->size = 0;		/* 해시 테이블 크기를 클리어 */
}