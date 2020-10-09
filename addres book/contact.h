#ifndef __CONTACT_H__
#define __CONTACT_H__

#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>

#pragma warning(disable:4996)
#pragma warning(disable:6031)

#define _CRT_SECURE_NO_WARNINGS
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_PHONE 20
#define MAX_ADDR 20
#define MAX_PERSON 1000
typedef struct Information		//信息结构体
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	char phone[MAX_PHONE];
	char addr[MAX_ADDR];
	int age;
}Information;

typedef struct Contact			//通讯录结构体
{
	Information data[MAX_PERSON];		//最多存1000人
	int size;							//当前存的人数
}Contact;

enum Option
{
	EXIT,
	ADD,
	DELETE,
	SEARCH,
	MODIFY,
	SHOW,
	EMPTY,
	SORT
};

void add(Contact* pcon);
void show(const Contact* pcon);
void delete(Contact* pcon);
int find_person(const Contact* pcon, char* name);
void search(const Contact* pcon);
void modify(Contact* pcon);
void empty(Contact* pcon);
void sort(Contact* pcon);
#endif //__CONTACT_H__