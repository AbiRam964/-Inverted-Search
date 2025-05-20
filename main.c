#include "invert.h"
int main(int argc, char *argv[])
{
    //declaring head pointer
    file_node *f_head = NULL;
    int count = 0;
    if(argc== 1)
    {
	printf("ERROR : Please pass the sufficient command line argument, usage:./a.out file.txt \n");
	return 0;
    }
    else
    {
	f_validation(&f_head,argv);   //funtion call foe validation
    }

    hash_t hashtable[28];
    for(int i =0; i<28; i++)		//loop for entering index in hashtable
    {
	hashtable[i].index = i;
	hashtable[i].link = NULL;
    }

    int choice;
    char str[20];
    file_node *backuplist = NULL; //Initialising main and backup list pointers
    //Displays the menu

    printf("1.Create Database\n2.Display Database\n3.Search word\n4.Save database\n5.Update database\n6.Exit\n");
    while(1)
    {
	printf("Enter the choice\n");
	scanf("%d",&choice);
	switch(choice)
	{		// Create the database using the files in the linked list
	    case 1 : if(!count)
		     {
		    if(create_database( f_head, hashtable)== SUCCESS)
		    {
			count=1;
			 printf("INFO: creating database is succesfully done\n");
		    }
		     else
			 printf("ERROR: creaing database is unsuccesfull");
		     }
		     else
			 printf("Database already created\n");
		     break;
	    case 2: if(display_file(hashtable) == FAILURE)	//Displays the database
			printf("database empty");
		    break;
	    case 3: printf("Enter the word\n");
		    scanf("%s",str);
		    if(search_db(hashtable, str) == FAILURE)   //Search for a word in the database
			printf("ERROR : Word not found\n");
		    break;
	    case 4: if(save_database(hashtable) == SUCCESS)	//Saves the database to a file
			printf("INFO:Database saved successfully\n");
		    else
			printf("Database saving failed\n");
		    break;	    
	    case 5: if(update(hashtable,&backuplist,&f_head) != FAILURE)	 //Update the database
		    {
			printf("INFO:Update success\n");
		    }
		    else
		    {
			printf("ERROR:Update unsuccessful\n");
		    }
		    break;

	    case 6: exit(1); //Exit the program
		    return SUCCESS;
		    break;
	    default:
		    printf("Invalid choice\n");


	}

    }
}
