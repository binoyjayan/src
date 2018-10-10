#include "myheader.h"
#include"auth.h"

char ip1[20]; 
char p[10][20]={"192.168.0.127","192.168.0.128","192.168.0.6"};
int i=0;
char *dst,*src;
char dst1[20],src1[20];
char newip[20];
void show(char *ip)
{
printf("%s",ip);
}


int main()
{

 pcap_t *handle;
 pthread_t *th;
printf("%s",p[0]);

printf("OK");
 char *dev;
 char errbuf[PCAP_ERRBUF_SIZE];
 struct bpf_program filter;
 struct busy *b;
 char filter_app[]="";
 bpf_u_int32 mask;
 bpf_u_int32 net;
 int sport;
 int dport;
 u_char *sether,dether;

 struct pcap_pkthdr header;
 struct ether_header *ethernet;
 struct ip *ip;
 struct tcphdr *tcp;
 struct icmphdr *icmp;
 const u_char *packet;
 dev =pcap_lookupdev(errbuf);
 if(dev==NULL)
    printf("cannot find device");
     
 else
 {
    
     pcap_lookupnet(dev,&net,&mask,errbuf);
     handle=pcap_open_live(dev,BUFSIZ,1,0,errbuf);
     pcap_compile(handle,&filter,filter_app,0,net);
     pcap_setfilter(handle,&filter);
     int k = 0;
     while(1)
     {
	packet=pcap_next(handle,&header);
	ethernet=(struct ether_header*)packet;  //ethernet header details
	ip=(struct ip*)(packet+14);             // ip header details
	tcp=(struct tcphdr*)(packet+14+20);     // tcp header details
	sport=ntohs(tcp->source);
	dport=ntohs(tcp->dest);
	sether=ethernet->ether_shost;
        dether=ethernet->ether_dhost;
	printf("Ethernet addr source:%s",ether_ntoa((const struct ether_addr *)&ethernet->ether_shost));
	printf("\tDestination%s\n",ether_ntoa((const struct ether_addr *)&ethernet->ether_dhost));

//printf("%s",(char*)inet_ntoa(ip->ip_src));
strcpy(dst1,(char*)inet_ntoa(ip->ip_dst));
//printf("\nhoi  %s  hoi\n",dst1);
for(i=0;i<=2;i++)
{	
//if(strcmp(p[i],dst1)==0)
	{
	check_ip_auth((char*)inet_ntoa(ip->ip_dst));
	/*system("iptables -t nat -A PREROUTING -p tcp -d 192.168.0.98 -m multiport --dport 22,80 -j DNAT --to-destination 10.10.10.2");
	//system("ssh 192.168.0.15"); */
	printf("\nIp:dest%s\tSource",(char*)inet_ntoa(ip->ip_dst));
	show((char*)inet_ntoa(ip->ip_src));
	printf("\nsource port%d\t%dDestination Port\n",sport,dport);
//	 printf("\n%x\t%x\n",sether,dether);

	}
     }
}
  }

return 0;
}
