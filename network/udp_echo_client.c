
/*
UDP echo client
*/

#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>

#define MYPORT 2323
#define MAXLINE 100

readline(char *s)
{
	int i = 0;
	while((s[i] = getchar()) != '\n')
		i++;
	s[i] = 0;
	return i;
}

int main()
{
	int sockfd;
	struct sockaddr_in cli, ser;
	int addr_len, numbytes;
	char send[MAXLINE], recv[MAXLINE];
	
	
	if((sockfd=socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP))==-1)
	{
		perror("SOCKET ERROR\n");
		exit(-1);
	}
	printf("SOCKET CREATED.........\n");

	//Initialize with server address
	ser.sin_family=AF_INET;
	ser.sin_port=htons(MYPORT);
	ser.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	while(1)
	{
		printf("Enter msg: ");
		readline(send);
		if((numbytes=sendto(sockfd,send,strlen(send),0,(struct sockaddr*)&ser,sizeof(struct sockaddr)))==-1)
		{
			perror("SENDTO ERROR\n");
			return 1;
		}
		if(strcmp(send, "bye") == 0)
			break;
		if((numbytes=recvfrom(sockfd,recv,MAXLINE,0,(struct sockaddr*)&cli,&addr_len))==-1)
		{
			perror("RECVFROM ERROR\n");
			return 2;
		}
		recv[numbytes] = 0;
		printf("\nEcho from server : %s\n", recv);
	}
	close(sockfd);
	return 0;
}

