/*
UDP echo server
*/


#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>

#define MYPORT 2323
#define MAXLINE 100

int main()
{
	int sockfd;
	struct sockaddr_in my_addr;
	struct sockaddr_in cli;
	int numbytes = 0, len;
	char recv[MAXLINE];
	
	if((sockfd=socket(AF_INET,SOCK_DGRAM, IPPROTO_UDP))==-1)
	{
		perror("SOCKET ERROR\n");
		exit(-1);
	}
	printf("SOCKET CREATED.........\n");
	
	my_addr.sin_family=AF_INET;
	my_addr.sin_port=htons(MYPORT);
	my_addr.sin_addr.s_addr=htonl(INADDR_ANY);
	
	if(bind(sockfd,(struct sockaddr *)&my_addr,sizeof(struct sockaddr))==-1)
	{
		perror("BIND ERROR\n");
		exit(-1);
	}
	
	printf("\nWaiting for Client...\n");
	
	while(1)
	{
		if((numbytes=recvfrom(sockfd,recv,MAXLINE,0,(struct sockaddr*)&cli,&len))==-1)
		{
			perror("RECVFROM ERROR\n");
			return 1;
		}
		recv[numbytes] = 0;
		if(strcmp(recv, "bye") == 0)
		{
			printf("The Client has Disconnected the Connection.. \n");
			break;
		}
		printf("Message from client: %s\n", recv);
		if((numbytes=sendto(sockfd,recv,numbytes,0,(struct sockaddr*)&cli,sizeof(struct sockaddr)))==-1)
		{
			perror("SENDTO ERROR");
			return 2;
		}
	}
	close(sockfd);
	return 0;
}

