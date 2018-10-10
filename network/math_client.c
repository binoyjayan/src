
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdio.h>

struct math
{
	int flag, a,b;
};
int main()
{
	struct sockaddr_in peer;
	int s, rc, i = 0;
	struct math m;
	peer.sin_family=AF_INET;

	/*To connect to server listening at this port*/
	peer.sin_port = htons(7000);
	
	/*Connect server listening in the same machine.*/

	peer.sin_addr.s_addr = inet_addr("127.0.0.1");

	/*Create a socket end-point*/
	s = socket(AF_INET, SOCK_STREAM, 0);
	rc = connect(s, (struct sockaddr *)&peer, sizeof(peer));
	if(rc < 0)
	{
		perror("error");
		return 1;
	}
	for(;;)
	{
		printf("Enter a, b:\n");
		scanf("%d%d", &m.a, &m.b);
		printf("Enter operation:");
		scanf("%d", &m.flag);
		send(s, &m, sizeof(m), 0);
		recv(s, &m, sizeof(m), 0);
		switch(m.flag)
		{
		case 0:
			goto out_of_loop;
		case 1:
			printf("Sum = %d\n", m.a);
			break;
		case 2:
			printf("Difference = %d\n", m.a);
			break;
		case 3:
			printf("Product = %d\n", m.a);
			break;
		case 4:
			printf("Quotient = %d\n", m.a);
			break;
		}
	}
out_of_loop:
	close(s);
}
