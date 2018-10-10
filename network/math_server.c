
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdio.h>
struct math
{
	int flag;
	int a, b;
};
void readline(char *);
int main()
{
	struct sockaddr_in local, cl;
	int s, s1, rc, cll;					//handle
	struct math m;
	local.sin_family = AF_INET;			/*Internet family*/
	//little endian intel
	//big-endian	motorala, network
	local.sin_port = htons(7000);			/*Listening port*/
	//printf("\nport = %d\n", local.sin_port);
	local.sin_addr.s_addr = htonl(INADDR_ANY);	/*Can listen on any address*/
	s = socket(AF_INET, SOCK_STREAM, 0);		/**/
	if(s < 0)	//if socket creation fails
	{
		perror("socket call failed");
		exit(1);
	}
	rc = bind(s, (struct sockaddr*) &local ,sizeof(local));
	if(rc<0)
	{
		perror("bind call failed");
		exit(1);
	}
	rc = listen(s, 5);
	if(rc)
	{
		perror("listen call failed");
		exit(1);
	}
	s1 = accept(s, (struct sockaddr*)&cl, &cll);

	while(1)
	{
		rc = recv(s1, &m, sizeof(m), 0);
		switch(m.flag)
		{
		case 0:
			goto out_of_loop;
		case 1:
			m.a += m.b;			
			break;
		case 2:
			m.a -= m.b;
			break;
		case 3:
			m.a *= m.b;
			break;
		case 4:
			m.a /= m.b;
			break;
		}
		send(s1, &m, sizeof(m), 0);
	}
out_of_loop:
	close(s1);
}

