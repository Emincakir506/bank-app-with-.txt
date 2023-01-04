#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
 // creating txt to  bank customer
int main()
{    setlocale(LC_ALL,"Turkýsh");
	char name[50] ;
	int bankno , balance , choice1 ,choice2;
	printf("what do you want\n");
	printf("1: add information\n");
	printf("2: read information\n");
	scanf("%d" ,&choice1);
	switch(choice1)
	{
	case 1 :
	 {
	  FILE *wrtfile = fopen ("Bank.txt" ,"a");
	  printf("press EOF (ctrl + z) to log out");
	  printf("\nenter bankno , name , balance :");
	  scanf("%d%s%d" ,&bankno ,name ,&balance);
	  while( !feof(stdin))
	   {
		fprintf(wrtfile, "%d\t%s\t%d\n" ,bankno ,name , balance);
	    printf("new account\n");
	    printf("enter bankno , name , balance :");
		scanf("%d%s%d" ,&bankno ,name ,&balance);
		}	
	  fclose(wrtfile);
    break;
	 } 
	case 2 :
	 {
	FILE *rdfile ;
	if((rdfile= fopen("Bank.txt","r") )== NULL)
	    printf("file not found\n");
	else
	while(1)
	{
		printf("\n\n\n BANK INFORMATION APP\n");
		printf("1: customers who have got many in their account\n");
	    printf("2: customers who haven't got many in their account\n");
	    printf("3: customers with debt\n");
	    printf("4: exit\n");
	    scanf("%d" ,&choice2);
	    switch(choice2)
	    {    
		    fscanf(rdfile , "%d\t%s\t%d" ,&bankno,name,&balance );
		case 1: printf("customers who have got many in their account\n");
	    	while( !feof(rdfile))
	         	{
	    		if ( balance > 0)
	    		printf("%d\t%s\t%d\n" ,bankno,name,balance);
			    fscanf(rdfile , "%d\t%s\t%d" ,&bankno,name,&balance );
			   } 
			break;
			
		case 2: printf("customers who haven't got many in their account\n");
	    	while( !feof(rdfile))
	    	   {
	    		if ( balance == 0)
	    		printf("%d\t%s\t%d\n" ,bankno,name,balance);
			    fscanf(rdfile , "%d\t%s\t%d" ,&bankno ,name,&balance );
			   }
	    	break;
			
		case 3: printf("customers with debt\n");
	    	while( !feof(rdfile))
	    	   {  
	    		if ( balance < 0)
	    		printf("%d\t%s\t%d\n" ,bankno,name,balance);
			    fscanf(rdfile , "%d\t%s\t%d" ,&bankno ,name,&balance );
			   }
			break;
			
		case 4: printf("log out\n");
	    return 0;
		}
	    rewind(rdfile);
      }}} 
	return 0;	
}
