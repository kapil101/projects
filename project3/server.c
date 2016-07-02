#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<signal.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/wait.h>
void main()
{
	char s[20];
	int fd,nfd,len,a[2];


	struct sockaddr_in v,v1;

	fd=socket(AF_INET,SOCK_STREAM,0);
	perror("socket");
	v.sin_family=AF_INET;
	v.sin_port=htons(2000);
	v.sin_addr.s_addr=inet_addr("0.0.0.0");
	len=sizeof(v);

	if(bind(fd,(struct sockaddr*)&v,len)<0)
	{	
		perror("bind");
		return;
	}

	listen(fd,5);

	printf("before\n");
	nfd=accept(fd,(struct sockaddr*)&v1,&len);
	perror("accept");

	printf("after\n");
	if(fork())
	{
		while(1)
		{
			read(nfd,s,sizeof(s));
			printf("%s\n",s);
			if(strcmp(s,"bye")==0)
			{
				wait(0);
				break;
			}	
		}
	}
	else
	{
		while(1)
		{
			scanf("%s[^\n]",s);
			write(nfd,s,strlen(s)+1);
			if(strcmp(s,"bye")==0)
			{
				break;
			}
		}		
		
	}	
}
