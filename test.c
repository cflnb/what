#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxSize 50000 //定义栈中元素最大个数

typedef struct{
	char data[MaxSize];
	int top;
}SqStack;

void InitStack(SqStack *S){
	S->top = -1;
}

int IsEmpty(SqStack S){
	if(S.top == -1){
		return 1;
	}
	return 0;
}

void Push(SqStack *S,char x){
	if(S->top == MaxSize-1){
		printf("栈已满"); 
		return;
	}
	S->top += 1;
	S->data[S->top] = x;
}

void Pop(SqStack *S,char *x){
	if(S->top == -1){
		printf("栈已满");
		return;
	}
	*x = S->data[S->top];
	S->top -= 1;
}
int posi1[50000]={0};
int k=-1;
typedef struct step
{
	int posi1;
	int posi2;
}step;

step a[1000];
int s1;
int bracketCheck(char str[],int length){
	SqStack S;
	InitStack(&S); 
	for(int i=0;i<length;i++){
		if(str[i]=='('||str[i]=='{'||str[i]=='['){
			Push(&S,str[i]);
			posi1[++k]=i;
		}else{
			if(IsEmpty(S)){ 
				return 0; 
			}
			char topElem; 
			Pop(&S,&topElem); 
			if(str[i]==')'&&topElem =='('){
				a[s1].posi1=posi1[k];
				a[s1].posi2=i;
				k--;
				s1++;
			}
			else if(str[i]=='}'&&topElem =='{'){
				a[s1].posi1=posi1[k];
				a[s1].posi2=i;
				k--;
				s1++;
			}
			else if(str[i]==']'&&topElem =='['){
				a[s1].posi1=posi1[k];
				a[s1].posi2=i;
				k--;
				s1++;
			}
			else 
			{
				return 0;
			}
		}
	}
	return IsEmpty(S);
}

char s[MaxSize];
int main(){
	
	gets(s);
	int len = strlen(s);
	if(bracketCheck(s,len)){
		printf("YES\n");
		for(int i=0;i<=s1;i++)
		{
			
				printf("%d %d\n",a[i].posi1,a[i].posi2);
			
		}
	}else{
		printf("NO");
	}
	return 0;
}

