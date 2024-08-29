//program 1 to implement operation on array ,add,delete,modify,simple search ,binary search
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
	int info;
	struct node*link;
};
struct node *top=NULL;
void push()
{
	struct node*tmp;
	int pushed_item;
	tmp=(struct node*)malloc(sizeof(struct node));
	printf("enter the pushed data to stack");
	scanf("%d",&pushed_item);
	tmp->info=pushed_item;
	tmp->link=top;
	top=tmp;
}
void pop()
{
	struct node*tmp;
	if(top==NULL)
		printf("stack is empty");
	else
	{
		tmp=top;
		printf("popped item is \n",tmp->info);
		top=top->link;
		free (tmp);
	}
}
void display()
{
	struct node*ptr;
	ptr=top;
	if(top==NULL)
		printf("\n stack is empty \n");
	else
	{
		printf("stack element are:\n");
		while(ptr !=NULL)
		{
			printf("%d\n",ptr->info);
			ptr=ptr->link;

		}
	}

}
int main()
{
	int op;
	while(1)
	{
		printf("**MEnu on array...**\n");
		printf("\n 1.insert \n2.delete \n3.display \n0.exit");
		printf("enter value \n");
		scanf("%d",&op);
		switch(op)
		{
		case 1: push();
			    break;
        case 2: pop();
			    break;
        case 3: display();
			    break;
        case 4: return 0;
			    break;
        default:printf("wrong choice");


		}

	}
}