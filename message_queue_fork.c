// write a program in c using pipe ipc mechanism
/*
pipe() for IPC
 parent - send a message 
 child - read and print
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<unistd.h>

#define KEY 9010
#define SRVTYPE 10
struct queue
{
        long type;
        char data[100];
};
int main()
{
        int msgid = msgget(KEY,IPC_CREAT | 0666);
        if(msgid == 0)
        {
                perror("msgget");
                exit(1);
        }
        struct queue msg;

        int pid = fork();

        if(pid == 0)
        {
                sleep(2);

                if(msgrcv(msgid,&msg,sizeof(msg.data),SRVTYPE,0) == -1)
                {
                        perror("msgrcv");
                        exit(1);
                }

                printf("CHILD : %s\n",msg.data);

                exit(0);
        }
        else
        {
                msg.type =SRVTYPE;
                char temp[100] = "Hi! CHILD";
                strcpy(msg.data,temp);

                if(msgsnd(msgid,&msg,strlen(msg.data)+1,0) == -1)
                {
                        perror("msgsnd");
                        exit(1);
                }
                printf("Parent : Sent to child\n");

                wait(NULL);
        }
        msgctl(msgid,IPC_RMID,NULL);
        return 0;
}
