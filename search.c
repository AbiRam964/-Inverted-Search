#include "invert.h"
int search_db( hash_t *head,char *word)
{
    int index = tolower(word[0]) % 97;		//Finding the index to be searched
    if(head[index].link == NULL)		//Checking if the index is not empty
    {
	printf("search is not possible,list empty\n");
	return FAILURE;
    }
    main_t *temp = head[index].link;		//Creating sub node pointer
    while(temp)
    {
	if(!strcmp((temp)->word , word))	//Checking if word is present
	{
	      printf("Word %s found at %dth index and in %d files \n" , word,index , (temp)->file_count);
	      sub_t *temp2 = (temp)->slink;	//Creating sub node pointer
	      while(temp2)
	      {
		  printf("In file : %s  %d time \n" , (temp2)->filename , temp2->word_count);
		  temp2 = (temp2)->sublink;
	      }
	      return 1;
	}
	temp = temp->mlink;
    }
    printf("Search word is not present in the list\n");
}

