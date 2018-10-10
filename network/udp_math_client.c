
/*
UDP math client to perform:
Addtion, subtraction, multiplication, division
*/

#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>

#define MYPORT 2323

typedef struct tagmat
{
	float a, b;
	int op;
}mat;

int main()
{
	int sockfd;
	struct sockaddr_in my_addr;
	struct sockaddr_in their_addr;
	int addr_len, numbytes;
	mat m;
	
	if((sockfd=socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP))==-1)
	{
		perror("SOCKET ERROR\n");
		exit(-1);
	}
	printf("SOCKET CREATED\n");

	their_addr.sin_family=AF_INET;
	their_addr.sin_port=htons(MYPORT);
	their_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	while(1)
	{
		printf("Enter the operation(0 to exit)\n");
		printf("(1 for addition,2 for sub, 3 for *tion, 4 for /sion):");
		scanf("%d",&m.op);
		if(m.op == 0)
			goto skip_get_numbers;
		printf("Enter a number: ");
		scanf("%f", &m.a);
		printf("Enter another one:");
		scanf("%f", &m.b);
skip_get_numbers:
		if((numbytes=sendto(sockfd,&m,sizeof(m),0,(struct sockaddr*)&their_addr,sizeof(struct sockaddr)))==-1)
		{
			perror("SENDTO ERROR");
			return 1;
		}
		if(m.op == 0)
			break;
		if((numbytes=recvfrom(sockfd,&m,sizeof(m),0,(struct sockaddr*)&my_addr,&addr_len))==-1)
		{
			perror("RECVFROM ERROR");
			return 2;
		}
		printf("Result : %.2f\n\n", m.a);
	}
	close(sockfd);
	return 0;
}

