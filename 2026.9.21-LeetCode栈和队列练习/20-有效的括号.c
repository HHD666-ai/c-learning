#include <stdbool.h>

bool isValid(char* s) {
    char stack[10001];
    int top=0;
    int i=0;
    while(s[i]!='\0'){
        if(s[i]=='['||s[i]=='('||s[i]=='{'){
            stack[top]=s[i];
            top++;
        }
        else{
            if(top==0){
                return false;
            }
            char ch=stack[top-1];
            if((s[i]=='}'&&ch=='{')
            ||(s[i]==')'&&ch=='(')
            ||(s[i]==']'&&ch=='[')){
                top--;
            }
            else{return false;}
        }

        i++;
    }
    return top==0;
}
