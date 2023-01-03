#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    while(1)
    {
        system("cls");
        printf("\n");
        printf("\n\t-- Library Management System --   \n");
        printf("\n\t      (Manage All Books)    \n");
        printf("\n\n\n");
        printf("\to  Books  o   ");

        printf("\n");
        printf("\n\t1  :\1:  Add Books         |");
        printf("\n\t2  :\2:  List of Books     |");
        printf("\n\t3  :\3:  Search            |");
        printf("\n\t4  :\4:  Delete            |");
        printf("\n\t5  :\5:  Exit              |");
        printf("\n");
        printf("\t__________________________");

        printf("\n\n\n\tEnter an Option no.: ");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            Add();
            break;
         case 2:
             List();
             break;
        case 3:
             search();
             break;
         case 4:
             Delete();
             break;
        case 5:
            return 0;
            break;
        }
    }

}

struct records
{
    char name[30],ID[30],author[30],price[30],email[50];

};
struct records r;
void Add()
{
    getchar();
    system("cls");
    FILE *file;
    file = fopen("file.txt","ab+");
    printf("\n\tHere You Can Add Book Details!    \n");
    printf("\n\tBook name : ");
    gets(r.name);
    printf("\n\tBook ID : ");
    gets(r.ID);
    printf("\n\tAuthor : ");
    gets(r.author);
    printf("\n\tprice : ");
    gets(r.price);


    fwrite(&r,sizeof(r),1,file);
    printf("\tBook Added Successfully!");
    fclose(file);

}


void Delete()
{
    getchar();
    system("cls");

    char name[40];
    unsigned flag=0;

    FILE *file,*file2;
    file=fopen("file.txt","rb");
        printf("\n\t-- Delete Any Book Records --\n");


    printf("\n\tEnter Book Name for delete : ");

    gets(name);

    file2=fopen("file2.txt","ab+");
    while(fread(&r,sizeof(r),1,file)==1)
    {
        if(strcmp(name,r.name)!=0)
        {
            printf("\n\n");
            printf("\tDetails Deleted Successfully!\n");
            fwrite(&r,sizeof(r),1,file2);
        }
        else
            flag=1;
    }

        fclose(file);
        fclose(file2);
        remove("file.txt");
        rename("source2.txt","file.txt");
        printf("\n\tUpdated Details!  \n");


    printf("\n\n\tPress Any Key to Return...");
    getch();
}

void List()
{
    char ch;
    system("cls");
    FILE *file;
    file = fopen("file.txt","rb");
    printf("\n\n");
    printf("\n\n");
    printf("\n\t-- All Book List --\n");
    printf("\n\n");



    while(fread(&r,sizeof(r),1,file)==1)
        printf("\n\tBook Name : %s\n\tID        : %s\n\tAuthor    : %s\n\tPrice     : %s\n",r.name,r.ID,r.author,r.price);
        fclose(file);

    printf("\n\n\tPress Any Key to Return...");
    getch();
}


void search()
{
    system("cls");
    char id[25];
    unsigned flag=0;
    FILE *file;
    file=fopen("file.txt","ab+");

    printf("\n\n\t-- Search here --\n");
    printf("\n");
    printf("\n\tEnter Book ID :");

    scanf("%s",&id);
    while(fread(&r,sizeof(r),1,file)>0 && flag==0)
    {
        if(strcmp(id,r.ID)==0)
        {
            flag=1;
            printf("\n\tBook Name : %s\n\tID        : %s\n\tAuthor    : %s\n\tPrice     : %s\n",r.name,r.ID,r.author,r.price);
        }
    }
    fclose(file);
    printf("\n\n\tPress Any Key to Return...");
    getch();
}
