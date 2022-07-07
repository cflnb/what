#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

typedef int Item;

typedef struct Sq
{
	Item d;
	struct Sq* next;
}Sq;



void CreatList(Sq* head, Item a[], int n)
{
	head->d = n;
	Sq* tail = head;
	for (int i = 0; i < n; i++)
	{
		Sq* new1 = (Sq*)malloc(sizeof(Sq));
		new1->d = a[i];
		tail->next = new1;
		tail = new1;
	}
	tail->next = NULL;
}

void InitList(Sq** head)
{
	*head = (Sq*)malloc(sizeof(Sq));
	(*head)->next = NULL;
}

void DestoryList(Sq* head)
{
	Sq* p = head, * q= head->next;
	while (p!= NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}
}

void DispList(Sq* head)
{
	Sq* p = head->next;
	while (p != NULL)
	{
		printf("%d ", p->d);
		p = p->next;
	}
	printf("\n");
}

int GetElem(Sq* head, int i, Item* k)
{
	Sq* p = head;
	int j = 0;
	while (j < i || p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
	{
		return 0;
	}
	else
	{
		*k = p->d;
		return 0;
	}
}

int LocateElem(Sq* head, int k, Item* i)
{
	Sq* p = head;
	int count = 0;
	while (p->d != k && p != NULL)
	{
		count++;
		p = p->next;
	}
	if (p == NULL)
	{
		return 0;
	}
	else
	{
		*i = count;
		return 1;
	}
}

int ListInsert(Sq* head, int i, Item k)

{
	Sq* p = head;
	int j = 0;
	while (j < i - 1 && p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL || i < 1)
	{
		return 0;
	}
	else
	{
		Sq* new1 = (Sq*)malloc(sizeof(Sq));
		new1->d = k;
		new1->next = p->next;
		p->next = new1;
		head->d++;
		return 0;
	}
}

int ListLenth(Sq*head)
{
	int lenth=0;
	Sq*p=head->next;
	while(p!=NULL)
	{
		lenth++;
		p=p->next;
	}
	return lenth;
}

int ListDelete(Sq* head, int i, Item* k)

{
	int j = 0;
	Sq* p = head;
	if (i < 1)
		return 0;
	while (j < i - 1 && p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
	{
		return 0;
	}
	else
	{
		Sq* q = p->next;
		if (q == NULL)
		{
			return 0;
		}
		*k = q->d;
		p->next = q->next;
		free(q);
		head->d--;
		return 0;
	}
}

void rever(Sq* head)
{
	Sq* p = head->next, * q;
	head->next = NULL;
	while (p != NULL)
	{
		q = p->next;
		p->next = head->next;
		head->next = p;
		p = q;
	}
}