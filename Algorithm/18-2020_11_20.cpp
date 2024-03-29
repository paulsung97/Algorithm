﻿#include <stdio.h>
#include "18-2020_11_20 비트 벡터 헤드.h"

int IsMember(BitSet s, int n)
{
	return s & SetOf(n);
}


void Add(BitSet* s, int n)
{
	*s |= SetOf(n);
}


void Remove(BitSet* s, int n)
{
	*s &= ~SetOf(n);
}

int Size(BitSet s)
{
	int n = 0;
	for (; s != BitSetNull; n++)
		s &= s - 1;
	return n;
}

void Print(BitSet s)
{
	int i;
	printf("{ ");
	for (i = 0; i < BitSetBits; i++)
		if (IsMember(s, i))
			printf("%d ", i);
	printf("}");
}


void PrintLn(BitSet s)
{
	Print(s);
	putchar('\n');
}