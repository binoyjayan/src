
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdio.h>

void readline(char*);
int main()
{
	struct sockaddr_in peer;
	int s, rc, i = 0;
	char buf[100], c;
	peer.sin_family=AF_INET;

	/*To connect to server listening at this port*/
	peer.sin_port = htons(7000);
	
	/*Connect server listening in the same machine.*/
//	peer.sin_addr.s_addr = inet_addr("127.0.0.1");	//loopback address

	peer.sin_addr.s_addr = inet_addr("192.168.6.45");

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
		readline(buf);
		if(strcmp(buf, "exit") == 0)
			break;
		send(s,buf,100,0);	//send msg in buf
		recv(s,buf,100,0);	//recv msg from server in 'buf'
		printf("Message from server %s\n",buf);
	}
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

