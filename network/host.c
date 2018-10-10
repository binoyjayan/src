
#include<netdb.h>

main(int argc, char *argv[])
{
	char name[100];
	struct hostent *h;
	if(argc != 2)
	{
		printf("invalid argument specification\n");
		return 1;
	}
	
	h = gethostbyname(argv[1]);
	if(h == NULL)
	{
		perror("gethostbyname");
		return 1;
	}
	printf("Hostname 	: %s\n", h->h_name);
	printf("Aliases 	: %s\n", *h->h_aliases);
	printf("Addr type	: %d\n", h->h_addrtype);
	printf("Addr. OLD	: %s\n", inet_ntoa(h->h_addr));
	printf("IP Addresses	: %s\n", inet_ntop(h->h_addrtype, h->h_addr, name, 100));
	printf("Length		: %d\n", h->h_length);
	
}

