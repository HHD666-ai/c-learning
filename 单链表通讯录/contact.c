#include"contact.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void InitContact(contact** con){
    *con=NULL;
}
void AddContact(contact** con){
    contact*newnode=(contact*)malloc(sizeof(contact));
    if(newnode==NULL){
        perror("malloc fail");
        return;
    }
printf("请输入姓名：");
    scanf("%99s", newnode->data.name);

    printf("请输入性别：");
    scanf("%3s", newnode->data.sex);

    printf("请输入年龄：");
    scanf("%d", &newnode->data.age);

    printf("请输入电话：");
    scanf("%11s", newnode->data.tel);

    printf("请输入地址：");
    scanf("%99s", newnode->data.addr);

newnode->next=NULL;

if(*con==NULL){
    *con=newnode;
}else{
    contact* tail = *con;
    while(tail->next!=NULL){
        tail=tail->next;
    }tail->next=newnode;
}
}
void ShowContact(contact* con){
    contact* cur=con;
    while(cur!=NULL){
       printf("姓名：%s\n", cur->data.name);
        printf("性别：%s\n", cur->data.sex);
        printf("年龄：%d\n", cur->data.age);
        printf("电话：%s\n", cur->data.tel);
        printf("地址：%s\n", cur->data.addr);
        printf("--------------------\n");

        cur = cur->next;

    }
}
void FindContact(contact* con){
    char name[NAME_MAX];
    printf("输入找的名字");
    scanf("%99s",name);
    contact*cur=con;
    while(cur!=NULL){
if(strcmp(cur->data.name,name)==0){
    printf("姓名：%s\n", cur->data.name);
            printf("性别：%s\n", cur->data.sex);
            printf("年龄：%d\n", cur->data.age);
            printf("电话：%s\n", cur->data.tel);
            printf("地址：%s\n", cur->data.addr);
            return;
}cur=cur->next;

    }printf("找不到");
}void DelContact(contact** con){
    char name[NAME_MAX];
     printf("请输入要删除的姓名：");
    scanf("%99s", name);
    contact*cur=*con;
    contact*prev=NULL;
    while(cur!=NULL){
        if(strcmp(cur->data.name,name)==0){
            if(cur==*con){
                *con=cur->next;
            }
            else{
                prev->next=cur->next;
            }
            free(cur);
            printf("删了");
            return ;
        }
        prev=cur;
        cur=cur->next;
    }
    printf("没有");
}void ModifyContact(contact** con){
     char name[NAME_MAX];

    printf("请输入要修改的姓名：");
    scanf("%99s", name);

    contact* cur = *con;
   while (cur != NULL)
    {
        if (strcmp(cur->data.name, name) == 0)
        {
            printf("请输入新的姓名：");
            scanf("%99s", cur->data.name);

            printf("请输入新的性别：");
            scanf("%3s", cur->data.sex);

            printf("请输入新的年龄：");
            scanf("%d", &cur->data.age);

            printf("请输入新的电话：");
            scanf("%11s", cur->data.tel);

            printf("请输入新的地址：");
            scanf("%99s", cur->data.addr);

            printf("修改成功\n");
            return;
        }

        cur = cur->next;
    }

    printf("未找到该联系人\n");
}
void DestroyContact(contact** con){
    contact*cur=*con;
    while(cur!=NULL){
        contact*next=cur->next;
        free(cur);
        cur=next;
    }
    *con=NULL;
}
