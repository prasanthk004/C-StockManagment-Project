#include<stdio.h>
#include"stktxn.h"
#include"storeitem.h"
char tfile[]="./stktxn.bin";

void IssueEntry()
{

	stk s ;
	char itmname[30],opt;
	int itmfnd;
	FILE *p ;
	float clbal ;
	
	
	p=fopen(tfile,"ab");
	printf ("\n 		ISSUE ENTRY  ");
	printf("\n     -----------------------");  
		
	printf("\n Enter the code : ");
	scanf("%d",&s.code);
	fflush(stdin);
	
	clbal=Closebal(s.code);
	
	itmfnd=getItemname(s.code,itmname);
	
	if(itmfnd==1)
	{
		printf("\n Itemname %s ",itmname);
	}
	else
	{
		printf("\n Given Item code is wrong");
		return ;
	}	 	 
	printf("\n Is this item name correct (Y/N) ? ");
	opt=getchar() ;
	
	if(opt=='n'||opt=='N') return ;	   
		
	printf("\n Enter Issue Qty : ");
	scanf("%f",&s.qty);
	
	if(s.qty>clbal)
	{
	 printf("\n %.f no's available in item %s, We can't issue %.f qty \n ",clbal,itmname,s.qty);
	 system("pause");
	 return ;
	}
	
	
	s.txn='I' ;
	
	fwrite(&s,sizeof(stk),1,p) ;
	fclose(p);
	
}	 

 void  ReciptEntry()
{

	stk s ;
	char itmname[30],opt;
	int itmfnd;
	FILE *p ;
	p=fopen(tfile,"ab");
	
 	printf("\n RECIPT ENTRY ");
		
	printf("\n Enter the code : ");
	scanf("%d",&s.code);
	fflush(stdin);
	
	itmfnd=getItemname(s.code,itmname);
	
	if(itmfnd==1)
	{
		printf("\n Itemname %s ",itmname);
	}
	else
	{
		printf("\n Given Item code is wrong");
		return ;
	}	 	 
	printf("\n Is this item name correct (Y/N) ? ");
	opt=getchar() ;
	 
	if(opt=='n'||opt=='N') return ;	   
		
	printf("\n Enter Recipt Qty : ");
	scanf("%f",&s.qty);
	
	s.txn='R' ;
	
	fwrite(&s,sizeof(stk),1,p) ;
	fclose(p);
	
}	 


void StktxnRprt()
{

	
	stk s ;int itmcode;
	char itmname[30],opt;
	int itmfnd;
	float iqty=0,rqty=0,cbal=0 ;
	
	FILE *p ;
	p=fopen(tfile,"rb");
	
 	
		
	printf("\n Enter the code : ");
	scanf("%d",&itmcode);
	fflush(stdin);
	
	itmfnd=getItemname(itmcode,itmname);
	
	if(itmfnd==1)
	{
		printf("\n Itemname %s ",itmname);
	}
	else
	{
		printf("\n Given Item code is not found !");
		return ;
	}	 	 
	printf("\n Is this item name correct (Y/N) ? ");
	opt=getchar() ;
	if(opt=='n'||opt=='N') return ;	   
	printf("\n    Stock Transaction Report ");
	printf("\n	-----------------------------------");
	printf("\n 	TXN.Type   I.Qty      R.Qty ");
	printf("\n	-----------------------------------");
	while(fread(&s,sizeof(stk),1,p))
	{
		if(itmcode==s.code)
		{
			if(s.txn=='I')
			{
			if(s.qty>0)
			{
			printf("\n 	ISSUE      %-6.2f",s.qty);
			}
			iqty+=s.qty ;
			}
			else
			{
			if(s.qty>0)
			{
			printf("\n 	RECIPT                %-6.2f",s.qty);
			}
			rqty+=s.qty ;
			}
		}	 	 
		}	 
			
			cbal=rqty-iqty;
			
			printf("\n	-----------------------------------");
			if(rqty>0||iqty>0)
			{
			printf("\n	Total      %-6.2f     %-6.2f",iqty,rqty);
			printf("\n 	Cl.Bal                %-6.2f",cbal);
			printf("\n	-----------------------------------");
			}
			else 
			{
				printf("\n No Transaction found for item %s",itmname);
			}	 
				
}	 	 	   	   
	 


float Closebal(int code)

{

	
 	 stk s ;
	float iqty=0,rqty=0,cbal=0;
	FILE *p  ;
	p=fopen(tfile,"rb");
	
		while(fread(&s,sizeof(stk),1,p))
	   {
		if(code==s.code)
		{
			if(s.txn=='I')
			{
		 
			iqty+=s.qty ;
			}
			else
			{	 	  
			rqty+=s.qty ;
			}
		}	 	 
		}	 
			
		
		cbal=rqty-iqty;
		return cbal;
}	 
			
		 	 
void StockList()
{
	int itc ;
	SITEM *itm;
	int i ;
	itc=itemcount();
	itm=GetStoreItems();
	
	printf("\n       STOCK LIST    \n");
	printf("\n--------------------------------------------");	
	printf("\n Item.code   Item.name           Avl.Stock ");
	printf("\n--------------------------------------------");
	for(i=0;i<itc;i++)
	{
		printf("\n %-9d   %-18s  %-9.2f     ",itm->code,itm->name,Closebal(itm->code));
		itm++;
	 
	}	   
	printf("\n--------------------------------------------");    
	itm=GetStoreItems();
}

