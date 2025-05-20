#include"invert.h"
int save_database(hash_t *head)
{
    char *filename;
    printf("Enter the file name\n");
    scanf("%s",filename);		//Reading the filename from the user
    if(strcmp(strstr(filename,"."),".txt")== 0)
    {
	FILE *fptr = fopen(filename, "w");  //Opening the file in write mode
	if(fptr == NULL)
	{
	    printf("ERROR:FILE FAILED TO OPEN\n");
	    return  FAILURE;
	}
	for(int i = 0; i<28;i++)
	{
	    if(head[i].link != NULL)		//Condition to check if the index contains any element
	    {
		main_t *temp =head[i].link;
		while(temp)		//Loop to traverse main node
		{
		    fprintf( fptr,"#%d;%s;%d;", i, (temp)->word , (temp)->file_count);
		    sub_t *temp2 = temp->slink;
		    while(temp2)		//Loop to traverse sub node
		    {
			fprintf(fptr,"%s;%d;", temp2->filename , temp2->word_count);
			temp2 = temp2->sublink;
		    }
		    fprintf(fptr,"#\n");
		    temp = temp->mlink;
		}
	    }
	}
	return SUCCESS;
    }
    else
    {
	printf("ERROR: please pass the file name with correct extension for %s usage :file.txt\n",filename);
	return FAILURE;
    }
}

