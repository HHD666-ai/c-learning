#include <stdio.h>
#include "contact.h"

enum Option
{
    EXIT,
    ADD,
    DEL,
    SHOW,
    FIND,
    MODIFY
};

void menu(void)
{
    printf("******************************\n");
    printf("***** 1.添加   2.删除 ********\n");
    printf("***** 3.显示   4.查找 ********\n");
    printf("***** 5.修改   0.退出 ********\n");
    printf("******************************\n");
}int main(void)
{
    contact* con = NULL;

    InitContact(&con);

    int input = 0;

    do
    {
        menu();

        printf("请选择：");
        scanf("%d", &input);

        switch (input)
        {
        case ADD:
            AddContact(&con);
            break;

        case DEL:
            DelContact(&con);
            break;

        case SHOW:
            ShowContact(con);
            break;

        case FIND:
            FindContact(con);
            break;

        case MODIFY:
            ModifyContact(&con);
            break;

        case EXIT:
            DestroyContact(&con);
            printf("退出通讯录\n");
            break;

        default:
            printf("选择错误，请重新选择\n");
            break;
        }

    } while (input != EXIT);

    return 0;
}
