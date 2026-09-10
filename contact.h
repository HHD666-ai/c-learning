#pragma once
#define NAME_MAX 100
#define SEX_MAX 4
#define TEL_MAX 11
#define ADDR_MAX 100
typedef struct PersonInfo{
    char name[NAME_MAX];
    char sex[SEX_MAX];
    int age;
    char tel[TEL_MAX+1];
    char addr[ADDR_MAX];

}PeoInfo;


typedef struct SeqList contact;
void InitContact(contact* con);
void AddContact(contact* con);
void DelContact(contact* con);
void ShowContact(contact* con);
void FindContact(contact* con);
void ModifyContact(contact* con);
void DestroyContact(contact* con);