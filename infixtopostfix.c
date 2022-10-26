#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
char stack[10];
int top=-1;
void push(char c){
    stack[++top]=c;
}
char pop()
{
    if(top==-1)
    return -1;
    else 
    return stack[top--];
}
int priority(char c)
{
    if(c=='(')
     return 0;
     if(c=='^')
      return 1;
      if(c=='+' || c=='-')
       return 2;
       if(c=='*'|| c=='/')
        return 3;
    return 0;
}
int main()
{
     char exp[10];
     char *e,c;
     printf("Enter the expression:");
     scanf("%s",exp);
     e=exp;
     while(*e!='\0')
     {
        if(isalnum(*e))
          printf("%c",*e);
          else if(*e=='(')
            push(*e);
               else if(*e==')')
               {     
                 while((c=pop())!='(')
                 printf("%c",c); }
                 else {
                    while(priority(stack[top])>=priority(*e))
                      printf("%c",pop());
                      push(*e);
                 }   e++;
     }  
     while(top!=-1) {
        printf("%c",pop());
     }
    return 0;
}