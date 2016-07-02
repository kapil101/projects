//server
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
typedef struct 
{
	int pkt,x,y,crc;
	char name[20];
}ST;
typedef struct frame
{
	int x,y,crc;
	char name[20];
	struct frame *next;
}fr;
typedef struct node
{
	int pkt;
	struct node*node_next;
	struct frame*frame_next;
}nd;
void make_node();
void print(void);
nd* my_malloc();
nd*h;	
ST z;	

pthread_mutex_t mtx=PTHREAD_MUTEX_INITIALIZER;
//pthread_cond_t cond=PTHREAD_COND_INITIALIZER;
int c=1,nfd;

void* thread_3(void *);

void * thread_1(void *p)
{
	for(;;)
	{
		pthread_mutex_lock(&mtx);
		while(c=read(nfd,&z,sizeof(z)))
		{
			pthread_mutex_unlock(&mtx);
			//pthread_cond_signal(&cond);
			sleep(1);//this is must otherwise it will keep on reading
		}
		pthread_exit(0);
	}
}




void* thread_2(void *p)
{
	pthread_t t3;
	for(;;)
	{	
		pthread_mutex_lock(&mtx);
		while(c==0)
			{
				pthread_create(&t3,NULL,thread_3,NULL);
				pthread_exit(0);
			}

		while(c!=1)
			//pthread_cond_wait(&cond,&mtx);

		{

			nd*t=h,*t1;
			fr*temp,*t2;
			if(h==0)
			{      				 
				h=my_malloc();      				
			}
			else
			{
				while(t)
				{
					if(t->pkt==z.pkt)
						break;
					t1=t;
					t=t->node_next;
				}
				if(t==0)
				{
					t1->node_next=my_malloc();		
				}
				else
				{
					temp=malloc(sizeof(fr));
					temp->x=z.x;
					temp->y=z.y;
					temp->crc=z.crc;
					strcpy(temp->name,z.name);
					temp->next=0;

					if(t->frame_next==0||(h->frame_next->crc)>(temp->crc))
					{
						temp->next=t->frame_next;
						t->frame_next=temp;
					}
					else
					{
						t2=h->frame_next;
						while(t2)	
						{
							if(t2->next==0)
							{
								temp->next=t2->next;
								t2->next=temp;
								break;
							}
							if(t2->next->crc>temp->crc)
							{
								temp->next=t2->next;
								t2->next=temp;
								break;
							}

							t2=t2->next;
						}	
					}									


				}

			}
			c=1;
		}
		pthread_mutex_unlock(&mtx);
	}
}

void* thread_3(void *k)
{
	nd *p=h;
	fr*t;
	while(p)	
	{
		t=p->frame_next;
		printf("pkt type=%d\n",p->pkt);	
		while(t)
		{
			printf("x=%d y=%d crc=%d\n",t->x,t->y,t->crc);
			printf("name=%s\n",t->name);
			t=t->next;
		}
		p=p->node_next;
	}

}
nd*my_malloc()
{
	nd*temp;
	temp=malloc(sizeof(nd));  
	temp->pkt=z.pkt;
	temp->frame_next=malloc(sizeof(fr));
	temp->frame_next->x=z.x;
	temp->frame_next->y=z.y;
	temp->frame_next->crc=z.crc;
	strcpy(temp->frame_next->name,z.name);
	temp->frame_next->next=0;
	temp->node_next=0;
	return temp;
}
void main()
{

	pthread_t t1,t2;

	int fd,len,i=1;
	struct sockaddr_in f,f1;

	f.sin_family=AF_INET;
	f.sin_port=htons(2000);
	f.sin_addr.s_addr=inet_addr("0.0.0.0");

	len=sizeof(f);

	fd=socket(AF_INET,SOCK_STREAM,0);
	perror("socket");

	bind(fd,(struct sockaddr*)&f,len);
	perror("bind");

	listen(fd,5);

	printf("before\n");
	nfd=accept(fd,(struct sockaddr*)&f1,&len);
	perror("accept");
	printf("after\n");

	pthread_create(&t1,NULL,thread_1,NULL);
	pthread_create(&t2,NULL,thread_2,NULL);

	pthread_exit(0);
//	pthread_join(t1,NULL);
//	pthread_join(t2,NULL);

//	print();

}
