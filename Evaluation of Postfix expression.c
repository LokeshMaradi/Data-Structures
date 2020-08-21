#include<stdio.h>
#include<stdlib.h>
int stack[20],top=-1;
void push(int x)
{
	stack[++top]=x;
}
int pop()
{
	return stack[top--];
}
int main()
{
	char postexp[20],*e;
	int n1,n2,n3,num;
	printf("Enter the postfix expression:");
	scanf("%s",postexp);
	e=postexp;
	while(*e!='\0')
	{
		if(isdigit(*e))
		{
			num=*e-48;
			push(num);
		}
		else
		{
			n1=pop();
			n2=pop();
			switch(*e)
			{
				case '+':n3=n1+n2;
				 		 break;
				case '-':n3=n2-n1;
				        break;
				case '*':n3=n1*n2;
						 break;
				case '/':n3=n2/n1;
						 break;
			}
			push(n3);
		}
		e++;
	}
	printf("Evaluation of postfix exp %s is %d",postexp,stack[top]);
}
