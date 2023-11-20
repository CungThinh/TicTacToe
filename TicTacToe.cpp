#include<stdio.h>
#include<math.h>
#include<string.h>
#include<windows.h>
#include <conio.h>

// Tic Tac Toe Code by Cung Thinh inspired by https://github.com/mishal23/Tic-Tac-Toe

//Global variable
int player = 1;
char p1[50],p2[50]; // name
char x,o; // player symbol
char symbol;
char a[9] = {'1','2','3','4','5','6','7','8','9'};

//Prototype
void decision();
void board();
int checkWin();
void rule();


int main()
{
	system("cls");
	system("color fc");
	
	printf("Type 1 to start the game");
	printf("\nType 2 to view LeaderBoard");
	printf("\nType anykey to exit");
	printf("\nYour choice: ");
	int choice;
	scanf("%d",&choice);
	if(choice==1)
	{
		start:
		system("cls");
		FILE *f = fopen("score.txt","a+");
		printf("Type player 1 name: ");
		scanf("%s",p1);
		fflush(stdin);
		printf("Type player 2 name: ");
		scanf("%s",p2);
		decision();
		int score = -1;
		printf("\n%s - %c\n",p1,x);
		printf("%s - %c\n\n",p2,o);
		board();
		
		do
		{
			player = ((player%2)?1:2);
			if(player == 1)
				printf("Player %s type any number 1-9 to fill the square: ",p1);
			else
				printf("Player %s type any number 1-9 to fill the square: ",p2);
			int input;
			fflush(stdin);
			scanf("%d",&input);
			symbol = ((player==1)?x:o);	
			if(input==1 && a[0]=='1')
            	a[0]=symbol;
        	else if(input==2 && a[1]=='2')
            	a[1]=symbol;
        	else if(input==3 && a[2]=='3')
            	a[2]=symbol;
        	else if(input==4 && a[3]=='4')
            	a[3]=symbol;
        	else if(input==5 && a[4]=='5')
            	a[4]=symbol;
        	else if(input==6 && a[5]=='6')
            	a[5]=symbol;
        	else if(input==7 && a[6]=='7')
            	a[6]=symbol;
        	else if(input==8 && a[7]=='8')
            	a[7]=symbol;
        	else if(input==9 && a[8]=='9')
            	a[8]=symbol;
        	else
            	{
					printf("Wrong selection\n");
					player--;
				}
			player++;
			board();
			score = checkWin(); 
		}while(score==-1);
		
		if(score == 0)
		{
			printf("Draw Game, Well Play!");
			fprintf(f,"%s\n","Draw");
		}
		
		if(score == 1)
		{
			if(player == 1)
			{
				printf("Player %s win the match",p2);
				fprintf(f,"%s\n",p2);
				
			}
			else
			{
				printf("Player %s win the match",p1);
				fprintf(f,"%s\n",p1);	
			}
			fclose(f);
		}
		getch();
	}
	else if(choice==2)
	{
		FILE *f = fopen("score.txt","r");
		system("cls");
		printf("LEADERBOARD\n");
		char c;
		while((c=fgetc(f))!=EOF)
		{
			printf("%c",c);
		}
		printf("\nPress 1 to start the game:\n");
		printf("Press anykey to exit");
		printf("\nYour choice:");
		int i;
		scanf("%d",&i);
		if(i==1)
		{
			system("cls");
			goto start;
		}
		else
			getch();
	}
	else
		printf("Good bye, enjoy your day!!!");
}
int checkWin()
{
	if(a[0]==a[1] && a[1]==a[2])
		return 1;
	if(a[0]==a[3] && a[3]==a[6])
		return 1;
	if(a[6]==a[7] && a[7]==a[8])
		return 1;
	if(a[2]==a[5] && a[5]==a[8])
		return 1;
	if(a[0]==a[4] && a[4]==a[8])
		return 1;
	if(a[2]==a[4] && a[4]==a[6])
		return 1;
	if(a[0] != '1' && a[1] != '2' &&a[2] != '3' && a[3] != '4' && a[4] != '5' && a[5] != '6' && a[6] != '7' && a[7] != '8' && a[8] !='9')
		return 0;
	else
		return -1;
}
void decision()
{
	char choice;
		deci:
		printf("Player %s choose X or 0:",p1);
		fflush(stdin);
		scanf("%c",&choice);
		if(choice == 'x' || choice =='X')
		{
			x = 'X';
			o = 'O';
		}
		else if(choice == 'O' || choice =='o')
		{
			x = 'O';
			o = 'X';
		}
		else
		{
			printf("Please enter X or O only");
			goto deci;
		}
}
void board()
{
 	printf("  %c |  %c | %c\n",a[0],a[1],a[2]);
    printf("    |    |    \n");
    printf("----|----|----\n");
    printf("    |    |    \n");
    printf("  %c |  %c | %c\n",a[3],a[4],a[5]);
    printf("    |    |    \n");
    printf("----|----|----\n");
    printf("  %c |  %c | %c\n",a[6],a[7],a[8]);
    printf("    |    |    \n");
}

