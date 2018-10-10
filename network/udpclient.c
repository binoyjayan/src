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

	their_addr.sin_family=AF_INET;
	their_addr.sin_port=htons(MYPORT);
	their_addr.sin_addr.s_addr=INADDR_ANY;
	//memset(&(their_addr.sin_zero),'\0',8);
	printf("Server Waiting For Connection\n");
	
	while(1)
	{
		if(*send==*ter)
		{
			printf("\nU have Disconnected the Connection\n");
			close(sockfd);
			exit(0);
		}
		else if(*recv==*ter)
		{
			printf("The Server has Disconnected the Connection\n");
			close(sockfd);
			exit(0);
		}
		else
		{
			printf("\nClient : ");
			//fflush(stdin);
			//fgets(send,MAXLINE,stdin);
			scanf("%s",send);
			if((numbytes=sendto(sockfd,send,MAXLINE,0,(struct sockaddr*)&their_addr,sizeof(struct sockaddr)))==-1)
			{
				perror("SENDTO ERROR\n");
				exit(0);
			}
			if((numbytes==recvfrom(sockfd,recv,MAXLINE,0,(struct sockaddr*)&my_addr,&addr_len))==-1)
			{
				perror("RECVFROM ERROR\n");
				exit(0);
			}
			printf("\nServer : %s",recv);
		}
	}
	close(sockfd);
	return 0;
}
