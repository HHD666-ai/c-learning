#include"contact.h"
#include"Seqlist.h"
#include<stdio.h>
void InitContact(contact* con){
    SLInit(con);
}
void AddContact(contact* con){
    PeoInfo person={0};
    printf("请输入年龄：");
    scanf("%d",&person.age);

    printf("请输入姓名：");
    scanf("%99s",person.name);
    
    printf("请输入性别：");
    scanf("%3s", person.sex);

    printf("请输入电话：");
    scanf("%11s", person.tel);

    printf("请输入地址（不含空格）：");
    scanf("%99s", person.addr);
    SLPushBack(con, person);

}
void ShowContact(contact* con){
if(con->size==0){
    printf("通讯录为空!\n");
    return ;
}
SLPrintf(con);
}
void FindContact(contact* con){
    char name[NAME_MAX]={0};
    printf("请输入名字： ");
    scanf("%99s", name);

    int pos=SLFind(con, name);

    if(pos==-1){
        printf("没有\n");
        return ;

    } 
    printf("姓名：%s\n", con->a[pos].name);
    printf("性别：%s\n", con->a[pos].sex);
    printf("年龄：%d\n", con->a[pos].age);
    printf("电话：%s\n", con->a[pos].tel);
    printf("地址：%s\n", con->a[pos].addr);
}
  
void DelContact(contact* con){
    char name[NAME_MAX]={0};

    printf("删谁: ");
    scanf("%99s",name);

    int pos=SLFind(con,name);
    
    if(pos==-1){
        printf("没找到!\n");
        return ;
    }
    SLErase(con,pos);
    printf("删除成功!\n");

}
void ModifyContact(contact*con){
    char name[NAME_MAX]={0};
    printf("请输入名字: ");
    scanf("%99s",name);

    int pos=SLFind(con,name);

    if(pos==-1){
        printf("找不到!\n");
        return ;
    }
PeoInfo person = {0};

    printf("请输入新的姓名：");
    scanf("%99s", person.name);

    printf("请输入新的性别：");
    scanf("%3s", person.sex);

    printf("请输入新的年龄：");
    scanf("%d", &person.age);

    printf("请输入新的电话：");
    scanf("%11s", person.tel);

    printf("请输入新的地址（不含空格）：");
    scanf("%99s", person.addr);

    SLModify(con, pos, person);

    printf("修改成功！\n");
}
