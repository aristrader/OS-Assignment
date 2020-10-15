#include<stdio.h>
#include<stdlib.h>

//semaphores 
int s=1;
int empty =3; // assuming size of buffer is 3
int full =0; 
int number =0; // variable to display item number consumed or produced

int wait(int value)
{
	return (--value);
}
 
int signal(int value)
{
	return(++value);
}

void producer()
{
    empty=wait(empty);
	s=wait(s);
	
	number++;
	printf("Producer produces the item %d \n",number);
	
	s=signal(s);
	full=signal(full);
}
 
void consumer()
{
    full=wait(full);
	s=wait(s);
	
	printf("Consumer consumes item %d \n",number);
	number--;
	
	s=signal(s);
	empty=signal(empty);
}

int main()
{
	int n;
	printf("Choices:\n1.Producer\n2.Consumer\n3.Exit\n");
	while(1)
	{
		printf("Enter your choice:\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1:	if((s==1)&&(empty!=0))
						producer();
					else
						printf("Buffer is full!!\n");
					break;
			case 2:	if((s==1)&&(full!=0))
						consumer();
					else
						printf("Buffer is empty!!\n");
					break;
			case 3:
					exit(0);
					break;
		}
	}
	
	return 0;
}
