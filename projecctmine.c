//Pawan Acharya 
//BCT,Kantipur Engineering college,Dhapakhel lalitpur

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
struct rec
{
	char name[50];
	char phone[50];
	char address[50];
}r;
void add();
void load();
void modify();
void delete();
void search();

int main()
{
char choice;
printf("welcome to telephone directory\n");
printf("Here you can save contacts,load them,search them,modify them or delete them.\n");
printf("\nYou have following options\n");
printf("A.Create a contact\n");
printf("B.Load contact\n");
printf("C.Search a contact\n");
printf("D.Edit a contact\n");
printf("E.Delete contact\nSelect options A,B,C,D or E\n");
fflush(stdin);
choice=getch();
switch(choice)
{
	case 'A':
	case 'a':
       	add();
    	break;
    case 'B':
	case 'b':
	    load();
		break;
	case 'C':
	case 'c':
	    search();
		break;
	case 'D':
	case 'd':
	     modify();
		 break;
	case 'e':
	case 'E':
	     delete();
		break;
	default:
		printf("\nPlease enter a valid input");
return 0;
}
}

void add()
{
	FILE *f;
	char test;
	f=fopen("record.txt","a+");
	if(f==NULL)
	{
	printf("No contact is not stored yet");
	exit(1);
    }
    while(1)
    {
       printf("\n Enter name\t");
       gets(r.name);
       printf("Enter address\t");
       scanf("%s",r.address);
       printf("Enter phone no.\t");
       scanf("%s",r.phone);
       fwrite(&r,sizeof(r),1,f);

    	fflush(stdin);
    	
    	printf("Press ESC key to exit and press any key to add again\n");
    	test=getch();
    	if(test==27)
    	break;
	}
	fclose(f);
}
void load()
{
	FILE *f;
	if((f=fopen("record.txt","r"))==NULL)
	{
		printf("\n!!!!No record found!!!!!");
		exit(1);
	}
	
	printf("\n\n Name\t\tTelephone no.\t\tAddress\n");
	printf("____________________________________________________");
	while(fread(&r,sizeof(r),1,f)==1)
	{
       printf("\n%s\t\t%s\t\t%s",r.name,r.phone,r.address);
    
}
    
	fclose(f);
	getch();
}
void modify()
{
	FILE *f;
	char name1[50];
	int datafound=0;
	long int size=sizeof(r);
	if((f=fopen("record.txt","r+"))==NULL)
	exit(1);
	printf("\nEnter the name which you want to modify\t");
	scanf("%s",&name1);
	fflush(stdin);
	while(fread(&r,sizeof(r),1,f)==1)
	{
		if(strcmp(r.name,name1)==0)
		{
			datafound=1;
			printf("\n The old record is:\n");
			printf("\n Name \t\tTelephone no. \t\tAddress\n");
	        printf("------------------------------------------------------------------");
			printf("\n%s\t\t%s\t\t%s",r.name,r.phone,r.address);
			printf("\n\nEnter new details\t");
			printf("Enter name\t");
       scanf("%s",r.name);
       printf("Enter address\t");
       scanf("%s",r.address);
       printf("Enter phone no.\t");
       scanf("%s",r.phone);
		fseek(f,-size,SEEK_CUR);
		fwrite(&r,sizeof(r),1,f);
		break;
		}
	}
fclose(f);
}
void delete()
{
	FILE *f,*ftemp;
	char delname[50];
	printf("\nEnter the name you want to delete\n");
	scanf("%s",delname);
	if((f=fopen("record.txt","r+"))==NULL)
	exit(1);
	ftemp=fopen("temp.txt","w");
	while(fread(&r,sizeof(r),1,f)==1)
	{
		if(strcmp(r.name,delname)!=0)
		{
			fwrite(&r,sizeof(r),1,ftemp);
		}
	}
	fclose(f);
	fclose(ftemp);
	remove("record.txt");
	rename("temp.txt","record.txt");
	printf("\nSuccessfully deleted.......\n");
}


void search()
{
	FILE *f;
	char name3[100];int flag=1;
	if((f=fopen("record.txt","r+"))==NULL)
	{
		printf("no file");
		exit(1);
	}
	
	printf("\nenter the name which you want to search\n");
	scanf("%s",&name3);
	while(fread(&r,sizeof(r),1,f)==1)
	{
		if(strcmp(r.name,name3)==0)
		{
			printf("\n Name=%s\n Telephone no.=%s \n Address=%s \n",r.name,r.phone,r.address);
			flag=0;
			break;
		}
	}
	if(flag==1)
	printf("Record not found.\n");
	fclose(f);
	}
	

