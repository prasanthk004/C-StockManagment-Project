typedef struct storeitem
{

	int code;
	char name[40];
	
} SITEM;

void AddItem();
void ReadItemName();	
void initialize();
void ListItem();
int getItemname(int , char *);
SITEM *GetStoreItems();
int GetItemsCount();


