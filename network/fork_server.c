
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdio.h>
void readline(char *);
int main()
{
	struct sockaddr_in local, cl;
	int s, s1, rc, cll;			//handle
	char buf[100];	
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
	if(!fork())
	while(1)
	{
		rc = recv(s1, buf, 100, 0);
		if(strcmp(buf, "exit") == 0)
			break;
		printf("Message from client : %d : %s\n", rc, buf);
	}
	else
	while(1)
	{
		//sending a mesg to client...
		readline(buf);
		if(strcmp(buf, "exit") == 0)
			break;
		//send to the message in 'buf' to client...
		send(s1, buf, 100, 0);
	}
	close(s1);
	close(s);
}
void readline(char *s)
{
	int i=0;
	while((s[i]=getchar())!='\n')
	{
		i++;
	}
	s[i] = 0;
}

