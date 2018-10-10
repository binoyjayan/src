
#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>

#define MYPORT 2323

/*
UDP math server to perform :
Addtion, subtraction, multiplication, division
*/

typedef struct tagmat
{
	float a, b;
	int op;
}mat;

int main()
{
	int sockfd;
	struct sockaddr_in my_addr, cli;
	int numbytes = 0, len;
	mat m;

	if((sockfd=socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP))==-1)
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
	
	printf("\nWaiting for Client...\n\n");
	
	while(1)
	{
		if((numbytes=recvfrom(sockfd,&m,sizeof(m), 0,(struct sockaddr*)&cli, &len))==-1)
		{
			perror("RECVFROM ERROR\n");
			return 1;
		}
		printf("%.2f ", m.a);
		switch(m.op)
		{
		case 0:
			printf("\nClient Requests to Disconnect... \n");
			close(sockfd);
			return 0;
		case 1:
			m.a += m.b;
			putchar('+');
			break;
		case 2:
			m.a-=m.b;
			putchar('-');
                        break;
		case 3:
			m.a*=m.b;
			putchar('*');
                        break;
		case 4:
			m.a/=m.b;
			putchar('/');
                        break;
		}
		printf(" %.2f = %.2f\n", m.b, m.a);
		if((numbytes=sendto(sockfd,&m,sizeof(m),0,(struct sockaddr*)&cli, sizeof(struct sockaddr)))==-1)
		{
			perror("SENDTO ERROR");
			return 2;
		}
	}
	return 0;
}

