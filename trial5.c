#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

struct list *create_list (void);
//int display(struct list *record, int *index);
int display(struct list *record);


struct list
{
    int index;
    char f_name[40];
    char m_name[40];
    char l_name[40];
    int m1;
    int m2;
    int m3;
    int m4;
    int m5;
    int total_marks;
    struct list *next;

};


struct list *create_list (void)  // CREATING A LINKED LIST
{
    FILE *fp;
    struct list *start, *record;
    char file_name[80];
    int i;
    //printf("ENTER THE FILENAME: \n");
    //scanf(" %[^\n]", file_name);
    strcpy(file_name,"input.txt");

    if((fp=fopen(file_name,"r"))==NULL)  // OPENING A FILE
    {
        printf("ERROR OPENING FILE>>>>>>");
    }

    start =(struct list *)malloc(sizeof(struct list));  // CREATING FIRST NODE
    record =start;

    while(!feof(fp))  // CREATING LINKED LIST
    {
        // READING THE DATA FROM THE FILE AND PLACING THE DATA IN THEIR RESPECTIVE PLACES IN THE STRUCTURE

        fscanf(fp, "%d ", &record->index);
        fscanf(fp, "%s ", record->f_name);
        fscanf(fp, "%s ", record->m_name);
        fscanf(fp, "%s ", record->l_name);
        fscanf(fp, "%d ", &record->m1);
        fscanf(fp, "%d ", &record->m2);
        fscanf(fp, "%d ", &record->m3);
        fscanf(fp, "%d ", &record->m4);
        fscanf(fp, "%d ", &record->m5);
        // CALCULATING TOTAL MARKS AND PLACING IT IN ITS RESPECTIVE PLACE IN THE STRUCTURE
        record->total_marks = (record->m1+record->m2+record->m3+record->m4+record->m5);

        //printf("NODE CREATED %d \n", record->index); // CHECCKING WHETHER THE NODE IS CREATED OR NOT

        if(!feof(fp))  // CREATING NEXT NODE
        {
            //printf("%s\n", record->f_name);
            record->next = (struct list *)malloc(sizeof(struct list));  // ALLOCATING SPACE FOR THE NEXT NODE
            record = record->next;  // SHIFTING RECORD TO NEXT ELEMENT
        }
    }
    //printf("RECORD %s\n", record->f_name);
    record->next=NULL;  // ENDING THE LINKED LIST
    fclose(fp);
    printf("FILE CLOSED %p\n", start);

    /*record=start;
    for(i=0; i<70; ++i)
    {
        printf("%d %s %s %s \n \n", record->index, record->f_name, record->m_name, record->l_name);
        record=record->next;

    }*/
    return(start);
}


int display(struct list *record)
{

    if(record == NULL)  // CHECKING IF THE LIST IS EMPTY
    {
        printf("\nLIST IS EMPTY.... \n"); // IF THE LIST IS EMPTY THEN PRINT AND RETURN
        return(0);
    }

    do
    {

        printf("%d %s %s %s \n ", record->index, record->f_name, record->m_name, record->l_name);

        record = record->next;
    }while(record!= NULL);
    printf("\nPRESS ANY KEY TO CONTINUE \n");
    getch();
    return(0);
}


void main(void)
{
    struct list *start, *n_start;
    int l_index[101], i;


    start = (struct list *)create_list();
    //n_start = start;
    printf("%p\n\n", start);
    for(i=1; i<=100; ++i)
    {
        l_index[i] = i;
    }
    printf("%p\n\n", start);
    display(start);

}


