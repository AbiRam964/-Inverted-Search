#include"invert.h"
char *fname ;
int create_database(file_node *f_head, hash_t *hashtable)
{
    if(f_head == NULL)
    {
	printf("ERROR: Database is already created\n");
	return FAILURE;
    }

    while(f_head)		//loop for accessing files linklist
    {
	if(read_file(f_head ,hashtable,f_head->filename)== SUCCESS)
	{
	    f_head = f_head->link;	//storing next file address to f_head		
	}
	else
	{
	    return FAILURE;
	}
    }
    return SUCCESS;

}
int read_file(file_node *file, hash_t *head, char *filename)
{
    fname = filename;
    char word[20];
    int flag = 1, index;
    FILE *fptr = fopen(filename, "r");		//oprning file in the reading mode 
    while(fscanf(fptr,"%s",word) != EOF)   //loop for accessing words
    {
	if(isalpha(word[0]))
		{
			index = tolower(word[0] - 97); // finding index of alphabets
		}
	else if( isdigit(word[0]))	//if the word is digit storing that into index 27
	    index = 27;
	else
	    index = 26;			//if it is special chara it will store into 26
	if(head[index].link != NULL)
	{
	    main_t *temp = head[index].link;
	    while(temp)
	    {
		if(strcmp(temp->word,word)== 0)	//Checking if words match
		{
		    update_word_count(&temp,filename );	//function call for updating word count
		    flag=0;
		    break;
		}
		temp=temp->mlink;

	    }

	}
	if(flag ==1)
	{
	    create_main_node(&head[index],word);    //Creating a new main node if word is not present
	}   
    }
    return SUCCESS;
}

int create_main_node( hash_t *head,char *data)  // creating main node
{ 
    main_t *new = malloc(sizeof(main_t));
    if(new == NULL)
	return FAILURE;
    new->file_count = 1;
    strcpy(new->word, data);
    new->slink = NULL;
    new->mlink = NULL;
    create_subnode(&new);   //function call to creating main node
    if(head ->link == NULL)
    {
	head->link = new;
	return SUCCESS;
    }
    else
    {
	main_t *temp = head->link;
	while( temp -> mlink != NULL)	//loop for travesrsion
	{
	    temp = (temp)->mlink;
	}
	(temp)->mlink = new;
	return SUCCESS;

    }

}

int create_subnode( main_t **head)		//creating subnode
{   
    sub_t *Snew = malloc(sizeof(sub_t));
    if(Snew == NULL)
	return FAILURE;
    Snew->word_count = 1;
    strcpy(Snew->filename ,fname);
    Snew->sublink = NULL;
    (*head)->slink = Snew;
    return SUCCESS; 
}

int update_word_count(main_t **head, char * filename)
{
    sub_t *temp = (*head)->slink;
    while(temp)
    {
	if(strcmp(temp->filename,filename)== 0)	//checking file names are equal or note
	{
	    (temp->word_count)++;//Incrementing word count
	    return 1;
	}
	temp = temp->sublink;
    }
    temp = (*head)->slink;
    while(temp->sublink)
    {
	temp= temp->sublink;
    }
    sub_t *new = malloc(sizeof(sub_t));//Creating new sub node
    new->sublink = NULL;
    strcpy(new->filename,filename);
    temp->sublink = new;
    new->word_count = 1;
    ((*head)->file_count)++;//Incrementing filecount
    return 1;

}

