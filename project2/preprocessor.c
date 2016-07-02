//single stage preprocessor//
#include<stdio.h>
#include<string.h>
void main(int argc,char *argv[]) 
{
	int i,j;
	char file[20],s[100],b[200],header[100]="/usr/include/",*p,*q,*r;
	FILE*fp,*fp1,*fp2;
	if(argc!=2)
	{
		printf("a.out,file.c\n");
		return;
	}
	fp=fopen(argv[1],"r");
	if(fp==NULL)
	{
		printf("error in fopen\n");
		return;
	}

	for(i=0;argv[1][i];i++)
	if(argv[1][i]!='c')
	file[i]=argv[1][i];
	file[i-1]='i';
	file[i]='\0';

	fp1=fopen(file,"w");//creating .i file
	if(fp1==NULL)
	{
		printf("error in fopen\n");
		return;
	}

	while(fgets(s,100,fp))	
	{
		 if((p=strstr(s,"//"))!=NULL)   
		{
			j=0;  
			printf("char=%d\n",s[j] ) ;
			if(s[j]!=p[j]) 
			{                                        
				while(p[j]!='\n')                   
	 			{
					p[j++]=' ';
				}
				printf("string=%s\n",s);
				fputs(s,fp1);
			}
		}
        
		else if((p=strstr(s,"/*"))!=NULL)		
		{
			 if(strstr(s,"*/")==NULL)		
			{
				fgets(s,100,fp);
				while(strstr(s,"*/")==NULL)		
				{
					fgets(s,100,fp);		
				}
			}

		}
		//	else;
			//fputs(s,fp1);
		else if((p=strstr(s,"include"))!=NULL)        //header file inclusion
		{

				if(p[7]=='<')
				{
					i=strlen(header);
					for(j=8;p[j]!='>';j++)
					header[i++]=p[j];
					header[i]='\0';

					fp2=fopen(header,"r");
					while(fgets(b,200,fp2))	
					fputs(b,fp1);
				}
				else
				{
					j=0;
					for(i=8;p[i]!='"';i++)
					file[j++]=p[i];
					file[j]='\0';
			
					fp2=fopen(file,"r");
					while(fgets(b,200,fp2))	
					fputs(b,fp1);
				}	
		}

		else if((p=strstr(s,"#define"))!=NULL)	//single line simple macro replacement	
		{
			j=0;
			for(i=7;p[i]==' ';i++);	
			for(;p[i]!=' ';i++)
			file[j++]=p[i];
			file[j]='\0';
			j=0;
			for(;p[i]==' ';i++);
			printf("p[i]=%c\n",p[i]);	
			while(p[i]!='\n')
			b[j++]=p[i++];
			b[j]='\0';			
		}
		else if((p=strstr(s,file))!=NULL)
		{
			i=strlen(b);
			j=strlen(file);
			printf("i=%d,b=%s j=%d ,file=%s\n",i,b,j,file);
			if((q=strchr(p,'"'))!=NULL)			
			{
				if((r=strstr(q,file))!=NULL)
				{
					while(b[i++]=r[j++]);
					printf("bcon=%s\n",b);
					i=j=0;
					while(r[i++]=b[j++]);					
					fputs(s,fp1);
				}
				else
				fputs(s,fp1);
			}
			else
			{
					while(b[i++]=p[j++]);
					i=j=0;
					while(p[i++]=b[j++]);					
					i=j=0;
					while(b[j])
					{
						p[j]=b[j];
						j++;
					}
					p[j]='\0';
					fputs(s,fp1);
			}
			
		}

		else                 //copying otherwise
		fputs(s,fp1);
	}
}
