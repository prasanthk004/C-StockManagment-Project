typedef struct stock

{

	int code ;
	float qty ;
	char txn ;
	
}stk;


void IssueEntry();
void ReciptEntry();
void StktxnRprt() ;
float Closebal(int code);

void StockList();
	

