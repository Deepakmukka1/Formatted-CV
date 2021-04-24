/*  Formatted CV using C */
#include <stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
int chcknum(const char *phonenum)
{
    int i=0;
    for(i=0;i<strlen(phonenum);i++)
    {
        if(isalpha(phonenum[i]))
            return 1;
    }
    return 0;
}
int main()
{
    FILE *fptr;
    fptr=fopen("newCV.txt","w");
    if(fptr==NULL)
    {
        printf("Error");
        exit(1);
    }
    else
    {
        char name[15],email[50],phone[12];
        char symbol,gender[10],skills[300],jobtitle[50];
        int age,qualification;
        char address[60];
        int i=0,j=0;
        printf("Enter your name:  \n");
        do{
            fgets(name,15,stdin);
        }while(strlen(name)>15);
        for(i=0;i<strlen(name);i++)
        {
            name[i]=toupper(name[i]);
        }
        fprintf(fptr,"%*s%*s\n",15+strlen(name)/2,name,15-strlen(name)/2,"",name);
        printf("Enter your email id: \n");
        do {
            
            scanf("%s",email);
            symbol=strchr(email,'@');
            
            
        }while(symbol==NULL);
        printf("Enter your Phone Number: \n");
        scanf("%s",phone);
        while(chcknum(phone))
        {
            printf("Type again \n");
            scanf("%s",phone);
        }
        printf("Enter your address: \n");
        //  scanf("%s",address);
        //scanf("%s", address);
        scanf(" %[^\n]s", address);
        fprintf(fptr,"Address: %s\n\n",address);
        fprintf(fptr,"Email: %s\t",email);
        fprintf(fptr,"\tPhone: %s\n",phone);
         printf("Enter your age : \n");
        scanf("%d",&age);
        if(age<15 || age>24)
        {
            printf("Sorry not eligible");
            exit(1);
        }
        printf("Enter your gender: \n");
        scanf("%s",gender);
        fprintf(fptr,"\nQualification \n\n");
        if(age>=15)
        {
            char grade[5];
            int yearofpassing;
            printf("Enter your Matric grade(10th class): \n");
            scanf("%s",grade);
            printf("Enter year of passing: \n");
            scanf("%d",&yearofpassing);
            fprintf(fptr,"\t Matric : with %s grade ",grade);
            fprintf(fptr,"in %d\n\n",yearofpassing);
        }
        if(age>=17&&age<=21)
        {
            char grade[10],grade1[10];
            int yearofpassing,yearofpassing1;
            printf("Enter your Intermediate(12th) grade: \n");
            scanf("%s",grade);
            printf("Enter year of passing: \n");
            scanf("%d",&yearofpassing);
            printf("Enter your Bachelors Degree grade(last semester) : \n");
            scanf("%s",grade1);
            printf("Enter year of completion: \n");
            scanf("%d",&yearofpassing1);
            fprintf(fptr,"\t Intermediate : with %s grade ",grade);
            fprintf(fptr,"in %d\n\n",yearofpassing);
            fprintf(fptr,"\t Bachelors : with %s grade\n",grade1);
            fprintf(fptr,"\t Year of completion : %d\n\n",yearofpassing1);
            
        }
        printf("Enter your experience in your current field and mention your skills (3-4 lines) :\n");
        scanf(" %[^\n]s", skills);
        printf("Enter your last job title (use NA if not applicable ) :\n");
        scanf(" %[^\n]s", jobtitle);
        fprintf(fptr,"Experience \n\n");
        fprintf(fptr,"\t %s\n\n",skills);
        fprintf(fptr,"Last Job title \n\n");
        fprintf(fptr,"\t %s\n\n",jobtitle);
        fclose(fptr);
    }
    
    return 0;
}
