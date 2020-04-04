#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

struct list *create_list (void);
int display(struct list *record, int *index);
int *sort_on_marks(struct list *start, int choice);
int *sort_on_name(struct list *start, int choice);
struct list *free_memory(struct list *record);
int CreateOutputFile(struct list *record, int *index);
int menu(void);


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
    printf("  ENTER THE FILENAME: ");
    scanf(" %[^\n]", file_name);
    printf("\n");
    //strcpy(file_name,"input.txt");  // FOR TESTING PURPOSE ONLY

    if((fp=fopen(file_name,"r"))==NULL)  // OPENING A FILE
    {
        printf("  ERROR OPENING FILE>>>>>>\n");
        printf("  PRESS ANY KEY TO CONTINUE\n");
        getch();
        return(NULL);
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

    printf("%4s   %-20s %-20s %-20s %-8s %-8s %-8s %-8s %-8s %-5s %-10s \n", "S.NO", "FIRST NAME", "MIDDLE NAME", "LAST NAME", "MARKS 1", "MARKS 2", "MARKS 3", "MARKS 4", "MARKS 5", "TOTAL", "PERCENTAGE" );
    for(i=0; i<no_of_elements; ++i)  // PRINTING THE RECORDS INDEX WISE
    {
        record=start;
        do
        {
            if(record->index == *(index+i))  // PRINTING THE RECORD AT I'TH INDEX
            {
                printf("%4d   ", record->index);
                printf("%-20s ", record->f_name);
                printf("%-20s ", record->m_name);
                printf("%-20s ", record->l_name);
                printf("%-8d ", record->m1);
                printf("%-8d ", record->m2);
                printf("%-8d ", record->m3);
                printf("%-8d ", record->m4);
                printf("%-8d ", record->m5);
                printf("%-5d ", record->total_marks);
                printf("%-10.3f ", record->percentage);
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
    int no_of_elements, i, j, temp, *index, *n_index;

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

    // AS THIS ROUTIINE SORTS IN DESCENDING ORDER SO TO SORT ON INDEX WE NEED TO REVERSE THE SORTED INDEX

    n_index = (int *)malloc(sizeof(int)*(no_of_elements));
    if(choice==7)
    {
        for(i=0, j=no_of_elements-1; i<no_of_elements; ++i, --j)
        {
            n_index[j]=index[i];

        }
        return(n_index);
    }

    return(index);
}





int *sort_on_name(struct list *start, int choice)
{
    struct list *record;
    int no_of_elements, i, j, temp1, *index, k;

    record=start;

    no_of_elements=0;  // COUNTING NUMBER OF ELEMENTS
    do
    {
        no_of_elements++;

        record=record->next;  // INCREMENTING THE POINTER TO COUNT THE NUMBER OF ELEMENTS

    }while(record!=NULL);

    char names[no_of_elements][20], temp[20];
    index = (int *)malloc(sizeof(int)*(no_of_elements));

    for(i=0; i<no_of_elements; ++i)
    {
        index[i] = (i+1);
    }

    record = start;

    for(i=0; i<no_of_elements; ++i)
    {
        if(choice == 8)
        {
            strcpy(&names[i][0], record->f_name);
        }
        if(choice == 9)
        {
            strcpy(&names[i][0], record->l_name);
        }

        record = record->next;
    }
    // SORTING STARTS FROM HERE



    for(i=0; i<(no_of_elements-1); i++)
    {
        for(j=0; j<(no_of_elements-i-1); j++)
        {
            k = strcmp(strupr(&names[j][0]), strupr(&names[j+1][0]));
            if(k>0)
            {
                strcpy(temp, &names[j][0]);
                strcpy(&names[j][0], &names[j+1][0]);
                strcpy(&names[j+1][0], temp);

                temp1=index[j];
                index[j]=index[j+1];
                index[j+1]=temp1;
            }
        }
    }
    return(index);
}

struct list *free_memory(struct list *record)
{
    struct list *P_record;
    if(record == NULL)  // CHECKING IF THE LIST IS EMPTY
    {
        printf("\n LIST IS EMPTY.... \n"); // IF THE LIST IS EMPTY THEN PRINT AND RETURN
        return(record);
    }

    do
    {
        P_record = record;
        record = record->next;
        printf("FREED NODE NO: %d \n", P_record->index);
        free(P_record);
    }while(record!= NULL);
    return(NULL);
}

int CreateOutputFile(struct list *record, int *index)
{
    int no_of_elements, i;
    struct list *start;
    start = record;
    FILE *fp;
    char file_name[40];

    if(record == NULL || index == NULL)  // CHECKING IF THE LIST IS EMPTY
    {
        printf("\n GIVEN LIST IS EMPTY OR MERRIT LIST IS NOT PREPARED.... \n"); // IF THE LIST IS EMPTY THEN PRINT AND RETURN
        printf("\n FIRST PREPARE THE MERRIT LIST BY CHOOSING THE OPTIONS BETWEEN 1 TO 9\n");
        printf("\n PRESS ANY KEY TO CONTINUE \n");
        getch();
        return(0);
    }

    printf("ENTER THE OUTPUT FILE NAME: ");
    scanf(" %[^\n]", file_name);

    if((fp=fopen(file_name, "w"))==NULL)
    {
        printf("ERROR OPENING FILE TO WRITE THE OUTPUT\n");
        return(0);
    }

    no_of_elements=0;  // COUNTING NUMBER OF ELEMENTS

    do
    {
        no_of_elements++;

        record=record->next;  // INCREMENTING THE POINTER TO COUNT THE NUMBER OF ELEMENTS

    }while(record!=NULL);
    fprintf(fp, "records=%d\n", no_of_elements);  // VERIFYING THE NUMBER OF RECORDS
            // PRINTING THE FIELDS
    fprintf(fp, "%4s   %-20s %-20s %-20s %-8s %-8s %-8s %-8s %-8s %-5s %-10s \n", "S.NO", "FIRST NAME", "MIDDLE NAME", "LAST NAME", "MARKS 1", "MARKS 2", "MARKS 3", "MARKS 4", "MARKS 5", "TOTAL", "PERCENTAGE" );
    for(i=0; i<no_of_elements; ++i)  // PRINTING THE RECORDS INDEX WISE
    {
        record=start;
        do
        {
            if(record->index == *(index+i))  // PRINTING THE RECORD AT I'TH INDEX
            {
                fprintf(fp, "%4d   ", record->index);
                fprintf(fp, "%-20s ", record->f_name);
                fprintf(fp, "%-20s ", record->m_name);
                fprintf(fp, "%-20s ", record->l_name);
                fprintf(fp, "%-8d ", record->m1);
                fprintf(fp, "%-8d ", record->m2);
                fprintf(fp, "%-8d ", record->m3);
                fprintf(fp, "%-8d ", record->m4);
                fprintf(fp, "%-8d ", record->m5);
                fprintf(fp, "%-5d ", record->total_marks);
                fprintf(fp, "%-10.3f ", record->percentage);
                fprintf(fp, "\n");
                break;
            }
            record = record->next;
        }while(record!= NULL);
    }

    fclose(fp);
    printf("FILE CREATED\n");
    printf("\nPRESS ANY KEY TO CONTINUE \n");  // SO THAT THE OUTPUT STAYS ON THE SCREEN
    getch();
    return(0);
}

int menu(void)   // MENU
{
    int choice;

    do
    {
        system("cls");
        printf("        MENU \n");
        printf("  1 TO SORT ON MARKS 1 \n");
        printf("  2 TO SORT ON MARKS 2 \n");
        printf("  3 TO SORT ON MARKS 3 \n");
        printf("  4 TO SORT ON MARKS 4 \n");
        printf("  5 TO SORT ON MARKS 5 \n");
        printf("  6 TO SORT ON TOTAL MARKS  \n");
        printf("  7 TO SORT ON INDEX \n");
        printf("  8 TO SORT ON FIRST NAME \n");
        printf("  9 TO SORT ON LAST NAME \n");
        printf("  10 TO CREATE A OUTPUT FILE \n");
        printf("  11 TO EXIT THE PROGRAM AND FREE MEMORY\n\n");
        printf("  ENTER YOUR CHOICE-----> ");
        scanf("%d", &choice);
        if(choice<1 || choice>11)
        {
            printf("\n ENTER A VALID INPUT!!!!! \n");
            printf("\n PRESS ANY KEY TO CONTINUE \n");
            getch();
        }
    }while(choice<1 || choice>11);


    return(choice);
}



void main(void)
{
    struct list *start;
    int l_index[101], i, choice, *n_index;

    n_index=NULL;


    start = (struct list *)create_list();   // ALLOCATING THE SPACE

    do
    {
        choice=menu();
        printf("\n\n %d \n\n", choice);
        if(choice==1)
        {
            n_index = sort_on_marks(start, choice);
            display(start, n_index);
        }
        if(choice==2)
        {
            n_index = sort_on_marks(start, choice);
            display(start, n_index);
        }
        if(choice==3)
        {
            n_index = sort_on_marks(start, choice);
            display(start, n_index);
        }
        if(choice==4)
        {
            n_index = sort_on_marks(start, choice);
            display(start, n_index);
        }
        if(choice==5)
        {
            n_index = sort_on_marks(start, choice);
            display(start, n_index);
        }
        if(choice==6)
        {
            n_index = sort_on_marks(start, choice);
            display(start, n_index);
        }
        if(choice==7)
        {
            n_index = sort_on_marks(start, choice);
            display(start, n_index);
        }
        if(choice==8)
        {
            n_index = sort_on_name(start, choice);
            display(start, n_index);
        }
        if(choice==9)
        {
            n_index = sort_on_name(start, choice);
            display(start, n_index);
        }
        if(choice==10)
        {
            CreateOutputFile(start, n_index);
        }
        if(choice==11)
        {
            free_memory(start);
            printf("\nPROGRAM EXITED...... \n");
            exit(0);
        }

    }while(choice!=11);

}


