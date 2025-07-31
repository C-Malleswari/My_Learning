/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
	char *str=(char*)malloc(20);
	strcpy(str,"malleswari");
	printf("before appending");
	printf("%s",str);
	printf("%lu\n",strlen(str));

	str=realloc(str,strlen(str)+strlen("hyderabad")+1);
	strcat(str,"hyderabad");
	printf("after appending");
	printf("%s",str);
        printf("%lu",strlen(str));

}
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
        char *str=(char*)malloc(20);
        strcpy(str,"malleswari");
        printf("before appending");
        printf("%s",str);
        printf("%lu\n",strlen(str));
	char  str1[20];
	fgets(str1,sizeof(str1),stdin);
       // str=realloc(str,strlen(str)+strlen(str1)+1);
        strcat(str,str1);
        printf("after appending");
        printf("%s",str);
        printf("%lu",strlen(str));

	free(str);
	
	}
