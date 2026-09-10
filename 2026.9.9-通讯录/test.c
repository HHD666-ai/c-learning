#include "contact.h"
#include "Seqlist.h"
#include<stdlib.h>
#ifdef _WIN32
#include <windows.h>
#endif
void menu(){
   printf("\n===== 通讯录 =====\n");
    printf("1. 添加联系人\n");
    printf("2. 删除联系人\n");
    printf("3. 展示联系人\n");
    printf("4. 查找联系人\n");
    printf("5. 修改联系人\n");
    printf("0. 退出\n");
}
int main() {
#ifdef _WIN32
    // 本程序使用 UTF-8 输入和显示中文。
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
#endif
contact con;
InitContact(&con);
int intput=0;
do{
    menu();
    printf("请选择: ");
    scanf("%d",&intput);
    switch(intput){
        case 1:
        AddContact(&con);
        
        break;
        case 2:
        DelContact(&con);
        break;
        case 3:
        ShowContact(&con);
        break;
        case 4:
        FindContact(&con);
        break;
        case 5:
        ModifyContact(&con);
        break;
        case 0:
        printf("退出!\n");
        break;
        default:
        printf("没有选项!\n");
        break;
    }
}while(intput!=0);

// AddContact(&con);
// ShowContact(&con);
// ModifyContact(&con);
// ShowContact(&con);
// DelContact(&con);
// ShowContact(&con);

free(con.a);
con.a=NULL;
con.size=0;
con.capacity=0;
return 0;

}
