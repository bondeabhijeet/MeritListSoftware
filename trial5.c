#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

struct list *create_list (void);
//int display(struct list *record, int *index);
int display(struct list *record, int *index);
int *sort_on_marks(struct list *start, int choice);


struct list
{
    int index;
    char f_name[20];
    char m_name[20];
    char l_name[20];
    int m1;
    int m2;
    int m3;
    int m4;
    int m5;
    int total_marks;
    float percentage;
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
        record->percentage = (((float)record->total_marks)/5.0);

        //printf("NODE CREATED %d \n", record->index); // CHECCKING WHETHER THE NODE IS CREATED OR NOT

        if(!feof(fp))  // CREATING NEXT NODE
        {

            record->next = (struct list *)malloc(sizeof(struct list));  // ALLOCATING SPACE FOR THE NEXT NODE
            record = record->next;  // SHIFTING RECORD TO NEXT ELEMENT
        }
    }

    record->next=NULL;  // ENDING THE LINKED LIST
    fclose(fp);
    printf("FILE CLOSED \n");
    return(start);
}



int display(struct list *record, int *index)
{
    int no_of_elements, i;
    struct list *start;
    start = record;

    if(record == NULL)  // CHECKING IF THE LIST IS EMPTY
    {
        printf("\n LIST IS EMPTY.... \n"); // IF THE LIST IS EMPTY THEN PRINT AND RETURN
        return(0);
    }
    no_of_elements=0;  // COUNTING NUMBER OF ELEMENTS
    do
    {
        no_of_elements++;

        record=record->next;  // INCREMENTING THE POINTER TO COUNT THE NUMBER OF ELEMENTS

    }while(record!=NULL);
    printf("records=%d\n", no_of_elements);  // VERIFYING THE NUMBER OF RECORDS


    for(i=0; i<no_of_elements; ++i)  // PRINTING THE RECORDS INDEX WISE
    {
        record=start;
        do
        {
            if(record->index == *(index+i))  // PRINTING THE RECORD AT I'TH INDEX
            {
                printf("%3d   ", record->index);
                printf("%-20s ", record->f_name);
                printf("%-20s ", record->m_name);
                printf("%-20s ", record->l_name);
                printf("%-4d ", record->m1);
                printf("%-4d ", record->m2);
                printf("%-4d ", record->m3);
                printf("%-4d ", record->m4);
                printf("%-4d ", record->m5);
                printf("%-5d ", record->total_marks);
                printf("%-5.3f ", record->percentage);
                printf("\n");
                break;
            }
            record = record->next;
        }while(record!= NULL);
    }

    printf("\nPRESS ANY KEY TO CONTINUE \n");  // SO THAT THE OUTPUT STAYS ON THE SCREEN
    getch();
    return(0);
}


int *sort_on_marks(struct list *start, int choice)
{
    struct list *record;
    int no_of_elements, i, j, temp, *index;

    record=start;

    no_of_elements=0;  // COUNTING NUMBER OF ELEMENTS
    do
    {
        no_of_elements++;

        record=record->next;  // INCREMENTING THE POINTER TO COUNT THE NUMBER OF ELEMENTS

    }while(record!=NULL);

    int marks[no_of_elements];
    index = (int *)malloc(sizeof(int)*(no_of_elements));

    for(i=0; i<no_of_elements; ++i)
    {
        index[i] = (i+1);
    }

    record = start;

    for(i=0; i<no_of_elements; ++i)
    {
        if(choice == 1)
        {
            marks[i]= record->m1;
        }
        if(choice == 2)
        {
            marks[i]= record->m2;
        }
        if(choice == 3)
        {
            marks[i]= record->m3;
        }
        if(choice == 4)
        {
            marks[i]= record->m4;
        }
        if(choice == 5)
        {
            marks[i]= record->m5;
        }
        if(choice == 6)
        {
            marks[i]= record->total_marks;
        }
        if(choice == 7)
        {
            marks[i]= record->index;
        }
        record = record->next;
    }
    // SORTING STARTS FROM HERE



    for(i=0; i<(no_of_elements-1); i++)
    {
        for(j=0; j<(no_of_elements-i-1); j++)
        {
            if(marks[j]<marks[j+1])
            {
                temp=marks[j];
                marks[j]=marks[j+1];
                marks[j+1]=temp;

                temp=index[j];
                index[j]=index[j+1];
                index[j+1]=temp;
            }
        }
    }


    return(index);
}




void main(void)
{
    struct list *start;
    int l_index[101], i, choice, *n_index;


    start = (struct list *)create_list();

    //printf("ENTER 1 TO SORT ")
    //scanf("%d", &choice);
    choice=1;
    n_index  = sort_on_marks(start, choice);
    display(start, n_index);
}


