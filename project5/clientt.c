//client.c

#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<pthread.h>
typedef struct frame
{
	int pkt,x,y,crc;
	char name[20];	
}ST;
int my_rand();
int cal();
//ST* init();

ST v;
int fd,wr=0;

pthread_t t1,t2;
//pthread_mutex_t mtx=PTHREAD_MUTEX_INITIALIZER;
//pthread_cond_t cond=PTHREAD_COND_INITIALIZER;
void*thread_1(void*);
void*thread_2(void*);

void main()
{
	int len,i=1;
	struct sockaddr_in f;

	f.sin_family=AF_INET;
	f.sin_port=htons(2000);
	f.sin_addr.s_addr=inet_addr("127.0.0.1");
	len=sizeof(f);
	
	fd=socket(AF_INET,SOCK_STREAM,0);
	perror("socket");

	connect(fd,(struct sockaddr*)&f,len);

	pthread_create(&t1,NULL,thread_1,NULL);
	pthread_create(&t2,NULL,thread_2,NULL);

	pthread_exit(0);
//	close(fd);	
	
//	printf("name=%s,pkt=%d,x=%d,y=%d,crc=%d\n",v->name,v->pkt,v->x,v->y,v->crc);	
}
void* thread_1(void *p)
{
	int i=1,j=1;
	for(;;)
	{
//		pthread_mutex_lock(&mtx);	
		while(i<31)
		{
			//v=init();
//			while(wr==0)			
			//pthread_cond_wait(&cond,&mtx);           //this lines are for synchoronisation using condtion variable			
			if(wr!=0)
			{
				write(fd,&v,sizeof(v));
				wr=0;
				/*if(j==1)
				{
					++j;
					pthread_mutex_unlock(&mtx);
				}*/
				sleep(1);
				i++;
			}	
			/*	if(j==1)
				{
					++j;
					pthread_mutex_unlock(&mtx);
					sleep(1);
				}*/
		}
		exit(0);
	}
}






void* thread_2(void*p)
{
///	ST *h;
//	h=malloc(sizeof(ST));
	for(;;)
	{
//		pthread_mutex_lock(&mtx);
		if(wr==0)
		{
			v.pkt=my_rand();
			v.x=my_rand();
			v.y=my_rand();
			strcpy(v.name,"ABC");
			v.crc=cal();
//		pthread_mutex_unlock(&mtx);
			wr=1;
//			sleep(1);
		}
	}
}
int cal()
{
	int r,i,s=0;
	r=v.pkt+v.x+v.y;
	for(i=0;v.name[i];i++)
	s=s+v.name[i];
	return(r+s);
}
int my_rand()
{
	int r;
	time_t t;
//	sleep(1);
	srand(time(&t));
	r=rand()%20+1;
	return r;
}
