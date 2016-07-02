#include<stdio.h>
#include<string.h>
#include<unistd.h>
//#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<sys/wait.h>
void main()
{
	struct sockaddr_in v;
	int fd,len,a[2];
	char s[20];
	fd=socket(AF_INET,SOCK_STREAM,0);
	perror("socket");
	v.sin_family=AF_INET;
	v.sin_port=htons(2000);
	v.sin_addr.s_addr=inet_addr("127.0.0.1");
	len=sizeof(v);
	if(connect(fd,(struct sockaddr*)&v,len)<0)
	{
		perror("connect");
		return;
	}
	printf("enter the string\n");
	if(fork())
	{
		while(1)
		{
			bzero(s,20);
			scanf("%s[^\n]",s);

			write(fd,s,strlen(s)+1);
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
			read(fd,s,sizeof(s));
			printf("%s\n",s);
			if(strcmp(s,"bye")==0)
			{
				break;
			}
		
		}
	}

}
