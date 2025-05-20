#include"invert.h"
int display_file(hash_t *head)
{ 
printf("[Index]\tWord\tFile count\tFile name\twordcount\n");
    for(int i = 0;i<28;i++)	//Loop to run till last element in hash table
    {
	if(head[i].link != NULL)	//Condition to check if the index contains any data
	{
	    for_print(head[i].link);
	}
    }
    return SUCCESS;
}
int for_print(main_t * head)
{
    while(head != NULL)			//Loop to traverse main node
    {
	printf(" [%d]\t%s\t %d\t", tolower((head)->word[0]) % 97, (head)->word , (head)->file_count);
	sub_t *temp = head->slink;
	while(temp)			//Loop to traverse sub node
	{
	    printf("\t%s\t %d\t", temp->filename , temp->word_count);
	    temp = temp->sublink;
	}
	head = head->mlink;
	printf("\n");
    }
    return SUCCESS;
}

