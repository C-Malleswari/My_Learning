#include<stdio.h>
void main()
{
	if(printf("hello"))
	{
		printf("world");
	}
	else
		printf("world");
}
/*#include<stdio.h>
void main()
{
        if(!printf("hello"))
        {
                printf("hello");
        }
        else
	{
                printf("world");
	}
}
*/
#include<stdio.h>
void main()
{
        if(fork())
        {
                printf("hello");
        }
        else
	{
                printf("world");
	}
}

