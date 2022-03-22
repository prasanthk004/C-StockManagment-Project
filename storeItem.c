#include<stdio.h>
#include<string.h>
#include"storeitem.h"


SITEM items[50] ;
int ic ;

char sfile[]="./storeitem.bin";

void initialize()

{
	
	SITEM itm ;
	
	FILE *f ;
	
	f=fopen(sfile,"rb");
	
	ic=0 ;
	while(fread(&itm,sizeof(SITEM),1,f))
	{
		items[ic].code=itm.code;
		strcpy(items[ic].name ,itm.name) ;
	ic++;
	}	 
	fclose(f);
}	 

void AddItem()
{
	SITEM itm ;
	char opt ;
	int i ;
	FILE *f ;
	f=fopen(sfile,"ab");
	initialize();
	
	printf("\n ADD ITEMS ");
code:do
	{
	printf("\n\nEnter Item code : ");
	scanf("%d",&itm.code);
	fflush(stdin);
	printf("\n Item Code %d is correct (Y/N) ? : ",itm.code);
	opt=getchar();
	}while(opt=='n'||opt=='N');
	fflush(stdin);
	for(i=0;i<ic;i++)
	{
		if(itm.code==items[i].code)
		{
			printf("\n Item code %d is already allocated for item %s",itm.code,items[i].name);
		 	 goto code;
		}
	}
	
		  
name:do
	{
	printf("\n\n Enter Item Name : ");
	gets(itm.name) ;
	printf("\n Item name %s is correct (Y/N) ? : ",itm.name);
	opt=getchar();
	fflush(stdin);
	}while(opt=='n'||opt=='N');
	
 	for(i=0;i<ic;i++)
	{
		if(strcmp(itm.name,items[i].name)==0)
		{
			printf("\n Item name %s is already allocated for item code %d",itm.name,items[i].code);
			 goto name ;
		}
	}	 	
	
	fwrite(&itm,sizeof(SITEM),1,f);	    
	 
	
	fclose(f);
	
	
}

void ListItem()

{

	int i ;
	
	SITEM itm ;
	
	initialize();
	printf("\n      List OF Items\n\n ");
	printf("\n\n---------------------------");
	printf("\n Item code    Item  Name");
	printf("\n----------------------------");
	for(i=0;i<ic;i++)
	{
	
		itm=items[i] ;
		
		printf("\n %-9d    %-18s  ",itm.code,itm.name);
	}
	printf("\n---------------------------");	
}	 	 


int getItemname(int code , char *name)
{
  
  int i ;
  char *tmp ;
  int itemfound=0 ; 
 
  
  initialize();
  
  
  
  for(i=0;i<ic;i++)
  {
  
  	if(code==items[i].code )
	{
		
		strcpy(name,items[i].name);
		itemfound=1;
		break ;
	}
	
  }	
  
 return  itemfound ;
 
     
}	 	 


int itemcount()
{
	return ic ;
}


SITEM *GetStoreItems()
{

	return items ;
}	 
 	    

