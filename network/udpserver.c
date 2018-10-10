#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#define MYPORT 2323
#define MAXLINE 100

int main()
{
	int sockfd;
	struct sockaddr_in my_addr;
	struct sockaddr_in their_addr;
	int addr_len,numbytes;
	char send[MAXLINE],recv[MAXLINE],ter[MAXLINE];
	strcpy(ter,"bye");
	
	if((sockfd=socket(AF_INET,SOCK_DGRAM,0))==-1)
	{
		perror("SOCKET ERROR\n");
		exit(-1);
	}
	printf("SOCKET CREATED.........\n");
	
	my_addr.sin_family=AF_INET;
	my_addr.sin_port=htons(MYPORT);
	my_addr.sin_addr.s_addr=htonl(INADDR_ANY);
	//memset(&(my_addr.sin_zero),'\0',8);
	
	if(bind(sockfd,(struct sockaddr *)&my_addr,sizeof(struct sockaddr))==-1)
	{
		perror("BIND ERROR\n");
		exit(-1);
	}
	
	addr_len=sizeof(struct sockaddr);
	printf("\n Waiting For a Client to Reply\n");
	
	while(1)
	{
		if(*recv==*ter)
		{
			printf("The Client has Disconnected the Connection.. \n");
			close(sockfd);
			exit(0);
		}
		else if(*send==*ter)
		{
			printf("U have Disconnected the Connection.. \n");
			close(sockfd);
			exit(0);
		}
		else
		{
			printf("Client : ");
			
			if((numbytes==recvfrom(sockfd,recv,MAXLINE,0,(struct sockaddr*)&their_addr,&addr_len))==-1)
			{
				perror("RECVFROM ERROR\n");
				exit(0);
			}
			
			printf("%s\n",recv);
			printf("\nSERVER : ");
			//fflush(stdin);
			//fgets(send,MAXLINE,stdin);
			//printf("enter:");
			scanf("%s",send);
			if((numbytes=sendto(sockfd,send,MAXLINE,0,(struct sockaddr*)&their_addr,sizeof(struct sockaddr)))==-1)
			{
				perror("SENDTO ERROR");
				exit(0);
			}
		}
	}
	close(sockfd);
	return 0;
}
