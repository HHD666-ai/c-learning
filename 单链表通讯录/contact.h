#pragma once

#define NAME_MAX 100
#define SEX_MAX 4
#define TEL_MAX 12
#define ADDR_MAX 100

typedef struct PersonInfo
{
    char name[NAME_MAX];
    char sex[SEX_MAX];
    int age;
    char tel[TEL_MAX];
    char addr[ADDR_MAX];
} PeoInfo;
typedef struct SListNode{
    PeoInfo data;
     struct SListNode* next;
}contact;
void InitContact(contact** con);
void AddContact(contact** con);
void DelContact(contact** con);
void ShowContact(contact* con);
void FindContact(contact* con);
void ModifyContact(contact** con);
void DestroyContact(contact** con);
