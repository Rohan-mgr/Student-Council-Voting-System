
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>


#define C1 "Bikash Singh"
#define C2 "Krishna Gurung"
#define C3 "Pasang Sherpa"
#define C4 "Govinda Raj Shrestha"

int votec1=0, votec2=0, votec3=0, votec4=0, i=0;
FILE *fvote,*rvote;

struct voter
{
    char name[10][10];
    int roll,grade,test;
} v;

void intro()
{
    printf("\n\n\n\n\n\t\t\t///***********************************************************///\n");
    printf("\t\t\t   Welcome to the Student Council Voting for KIST College 2021\n");
    printf("\t\t\t\t\t     Kamalpokhari,Kathmandu\n");
    printf("\t\t\t///***********************************************************///\n");
    printf("\n\n\n\t\t\t\t\t Press any key to continue..........");
    getch();
}

// Initiating castvote function to allow the user to choose their candidates
void castevote()
{
    system("cls");
    printf("Please Enter your details to cast vote: \n");
    printf("Name: ");
    scanf("%s",&v.name);
    printf("Class: ");
    scanf("%d",&v.grade);
    printf("Roll No: ");
    scanf("%d",&v.roll);
    int candidate_chosen;
    printf("\nSelect Your Candidates: \n");
    printf("1.%s\n", C1);
    printf("2.%s\n", C2);
    printf("3.%s\n", C3);
    printf("4.%s\n", C4);
    //do{
		printf("\nEnter your Candidates Number(1-4): ");
        scanf("%d", &candidate_chosen);
    v.test=candidate_chosen;
	//}while(v.test<1 || v.test>4);
	if(v.test == 1)
    	{
    		votec1++;
		}
		if(v.test == 2)
		{
			votec2++;
		}
			if(v.test == 3)
		{
			votec3++;
		}
			if(v.test == 4)
		{
			votec4++;
		}
		if(v.test>4)
		{
			printf("Enter the correct choice.");
		}
    
    fvote=fopen("Voter.dat","a");
    fwrite(&v,sizeof(struct voter),1,fvote);
    fclose(fvote);
    
   
}

//showing the user about the votes calculated
void totalvote()
{
    system("cls");
    printf("\nCandidate Names\t\t\t\t");
    printf("Votes Count\n");
    printf("1.%s\t\t\t\t\t%d\n", C1, votec1);
    printf("2.%s\t\t\t\t%d\n", C2, votec2);
    printf("3.%s\t\t\t\t\t%d\n", C3, votec3);
    printf("4.%s\t\t\t\t%d\n", C4, votec4);
    getch();
}

//display how accurate thier guess is

void guessvote()
{
    system("cls");
    int guessNo;
    int voteArray[] = {votec1, votec2, votec3, votec4};
    int temp;
    int i=0,j=0;
    for(i = 0; i<sizeof(voteArray)/sizeof(*voteArray); i++)
    {
        for(j = i + 1; j<sizeof(voteArray)/sizeof(*voteArray); j++)
        {
            if(voteArray[i]<voteArray[j])
            {
                temp = voteArray[i];
                voteArray[i]=voteArray[j];
                voteArray[j] = temp;
            }
        }
    }

    printf("\nGuess Who is going to Win: \n");
    printf("1.%s\n", C1);
    printf("2.%s\n", C2);
    printf("3.%s\n", C3);
    printf("4.%s\n", C4);
    printf("\nEnter your Candidates Number(1-4): ");
    scanf("%d", &guessNo);
    switch(guessNo)
    {
    case 1:
        if(votec1 == voteArray[0])
        {
            printf("\nCorrect! Mr.%s is at leading position.\n", C1);
        }
        else
        {
            printf("\nSorry! Mr.%s is not the leading candidate.\n", C1);
        }
        break;
    case 2:
        if(votec2 == voteArray[0])
        {
            printf("\nCorrect! Mr.%s is at leading position.\n", C2);
        }
        else
        {
            printf("\nSorry! Mr.%s is not the leading candidate.\n", C2);
        }
        break;

    case 3:
        if(votec3 == voteArray[0])
        {
            printf("\nCorrect! Mr.%s is at leading position.\n", C3);
        }
        else
        {
            printf("\nSorry! Mr.%s is not the leading candidate.\n", C3);
        }
        break;
    case 4:
        if(votec4 == voteArray[0])
        {
            printf("\nCorrect! Mr.%s is at leading position.\n", C4);
        }
        else
        {
            printf("\nSorry! Mr.%s is not the leading candidate.\n", C4);
        }
        break;
    default:
        printf("Invalid Choice");
        break;
    }
    getch();

}

//Getting leading candidate
void leadcount()
{
    system("cls");
    printf("\n##Leading Candidate##\n");
    if(votec1>votec2 && votec1>votec3 && votec1>votec4)
    {
        printf(" Candidate %s is leading the vote\n",C1);
    }
    else if(votec2>votec1 && votec2>votec3 && votec2>votec4)
    {
        printf(" Candidate %s is leading the vote\n",C2);
    }
    else if(votec3>votec1 && votec3>votec2 && votec3>votec4)
    {
        printf(" Candidate %s is leading the vote\n",C3);
    }
    else if(votec4>votec1 && votec4>votec2 && votec4>votec3)
    {
        printf(" Candidate %s is leading the vote\n",C4);
    }
    else
    {
        printf(" Non win condition\n");
    }
    getch();

}

void showvoter()
{
    system("cls");
    int j;
    int x;
    printf("\nShow voters details of Selected candidates:\n");
    printf("\n Select  Candidates: \n");
    printf("1.%s\n", C1);
    printf("2.%s\n", C2);
    printf("3.%s\n", C3);
    printf("4.%s\n", C4);
    scanf("%d",&x);
   
    	//printf("%s\t %d\t %d",v.name,v.grade,v.roll);
	
    switch(x)
    {
    case 1: system("cls");
        printf("\nVoters details who cast vote for %s :\n",C1);
        rvote=fopen("voter.dat","r");
        printf("\n Name\t\tClass\t\t Id");
   		 while(fread(&v,sizeof(v),1,rvote))
    	{
      	   if(v.test==1)
       		 {

                printf("\n %s \t\t %d \t\t %d",v.name,v.grade,v.roll);

           	 }
      	  
		}
		fclose(rvote);

        break;
    case 2: system("cls");
        printf("\nVoters details who cast vote for %s :\n",C2);
         rvote=fopen("voter.dat","r");
    
   		 while(fread(&v,sizeof(v),1,rvote))
    	{
      	   if(v.test==2)
       		 {

                printf("\n %s \t\t %d \t\t %d",v.name,v.grade,v.roll);

           	 }
      	  
		}
		fclose(rvote);
        break;
    case 3:
         system("cls");
        printf("\nVoters details who cast vote for %s :\n",C3);
         rvote=fopen("voter.dat","r");
    
   		 while(fread(&v,sizeof(v),1,rvote))
    	{
      	   if(v.test==3)
       		 {

                printf("\n %s \t\t %d \t\t %d",v.name,v.grade,v.roll);

           	 }
      	  
		}
		fclose(rvote);
        break;
    case 4:
        system("cls");
        printf("\nVoters details who cast vote for %s :\n",C4);
         rvote=fopen("voter.dat","r");
    
   		 while(fread(&v,sizeof(v),1,rvote))
    	{
      	   if(v.test==4)
       		 {

                printf("\n %s \t\t %d \t\t %d",v.name,v.grade,v.roll);

           	 }
      	  
		}
		fclose(rvote);
        break;
    default:
        printf("Enter correct choice");
        break;

    }
	
    getch();

}

int main()
{
    int choice;
    char password[4], ch;
    int p;
    rvote = fopen("Voter.dat","r");
    while(fread(&v,sizeof(v),1,rvote))
    {
    	if(v.test == 1)
    	{
    		votec1++;
		}
		if(v.test == 2)
		{
			votec2++;
		}
			if(v.test == 3)
		{
			votec3++;
		}
			if(v.test == 4)
		{
			votec4++;
		}
	}
	fclose(rvote);
    intro();
    while(1)
    {
        system("cls");
        printf("\n\n\n\n\n\tChoose one among the following options(1-5)\n");
        printf("\t1. Cast Your Vote!!\n");
        printf("\t2. Show Total Votes Count\n");
        printf("\t3. Guess who is Going to win The Voting\n");
        printf("\t4. Show Leading Candidates\n");

        printf("\t5. Press 5 if you are the school management\n");
        printf("\t6. Exit");
        printf("\n\tPlease enter your choice among(1-6): ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            castevote();
            break;
        case 2:
            totalvote();
            break;
        case 3:
            guessvote();
            break;
        case 4:
            leadcount();
            break;

        case 5:
            printf("\nEnter the password:: ");
            for(p=0; p<4; p++)
            {
                ch= getch();
                password[p]= ch;
                ch= '*';
                printf("%c", ch);
            }
            password[p]= '\0';
            getch();
            if(strcmp(password, "park")==0)
            {
                showvoter();
            }
            else
            {
                printf("\n Incorrect password!!!");
            }
            break;
        case 6:
            exit(1);
            break;
        default:
            printf("\nPlease Enter the correct choice!!");
            break;
        }
        getch();

    }
    return 0;
}
