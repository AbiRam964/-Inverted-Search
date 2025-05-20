#include "invert.h"
int f_validation(file_node **f_head, char *argv[])
{
    int i =1,empty;
    int flag = 0;
    while(argv[i] != NULL)
    {
	if(strstr(argv[i],".") != NULL && strcmp(strstr(argv[i],"."),".txt") == 0)	//Condition to check if file is a .txt file
	{	
	    empty = isFileEmpty(argv[i]);	//function call for checking file is empty or not
	    if(empty == FILE_NOT_AVAILABLE)
	    {
		printf("File: %s not found\n",argv[i]);
		i++;                             //incerementing i for accessing next command line argument
		continue;
	    }
	    else if(empty == FILE_EMPTY)
	    {
		printf("File: %s is not having any contents\n ",argv[i]);
		i++;				 //incrementing i for accessing command line arguments
		continue;
	    }
	    else
	    {
		file_node *temp = *f_head;
		file_node *prev = NULL;
		while( temp != NULL)
		{
		    if(strcmp(argv[i],temp->filename) == 0)		//Condition to check if it is a duplicate file
		    {
			flag = 1;
			printf("File: %s repeated\n",argv[i]);
			break;
		    }
		    prev = temp;
		    temp = temp->link;	 
		}
		if(flag == 0)
		{
		    file_node *new = malloc(sizeof(file_node));
		    strcpy(new->filename ,argv[i]);
		    if(*f_head == NULL) //condition for checking file linklist is NULL or not
		    {
		      *f_head = new;
		      printf("File: %s insertes Successfully into file linked list\n",argv[i]);
		    }
		    else
		    {
		      prev->link = new;
		      printf("File: %s insertes Successfully into file linked list\n",argv[i]);
		    }
		}
	    }
		printf("ERROR : Please pass the .txt extension along with %s file name\n",argv[i]);
	}
	i++;			//incrementing i for accessing command line arguments
    }
}
int isFileEmpty( char *file_name)
{
    //checking file is present or not
    FILE *fptr = fopen(file_name,"r");
    if(fptr == NULL)
    {
	return FILE_NOT_AVAILABLE;
    }
    //checking file is empty or not
    fseek(fptr,0,SEEK_END);
    if(ftell(fptr) == 0)
    {
	return FILE_EMPTY;
    }
}

