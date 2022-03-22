#include<stdio.h>
#include"storeitem.h" 

void Menu() ;

int main()

{
	initialize() ;
	Menu();	   

}



void Menu()
{


	int opt  ;
	while(1)
	{
	system("cls");
	printf("\n      ABC ELETRONIC SHOP \n\n");
	printf("\n      1. ADD ITEM ");
	printf("\n      2. ISSUE ENTRY ");
	printf("\n      3. RECIPT ENTRY ");	 
	printf("\n      4. STOCK LIST ");
	printf("\n      5. STOCK TRANSACTION REPORT ");
	printf("\n      6. VIEW STORE ITEMS ");
	printf("\n      7. EXIT ");
	
	printf("\n\n Please select option(1-6) : ");
	scanf("%d",&opt) ;
	fflush(stdin);
	
	switch(opt)
	{
		case 1: AddItem();    break; 
		case 2: IssueEntry(); break;
		case 3: ReciptEntry(); break;
		case 4: StockList(); break;
		case 5: StktxnRprt(); break;
		case 6: ListItem(); break ;
		case 7:  return;
		default: printf("\n Invalid option Selected ! \n please choose option between 1 to 6"); break;
	
	}
	printf("\n\n Press a key to continue . . .. . .");
	getch();
	
	
	}
	
}	 

