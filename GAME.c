#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>

// RANDOM NUMBER 1-6
int rnd_dice() 
{
    int rnd;
    srand(time(0));
    rnd = (rand() % 6) + 1;
    return rnd;
}

int player1() 
{
    char enter;
    printf("\nPLAYER_1: PRESS 'ENTER' to roll a die.\n");
    enter = getchar();
    int die = rnd_dice();
    printf("Die rolled %d.\n", die);
    return die;
}

int player2() 
{
    char enter;
    printf("\nPLAYER_2: PRESS 'ENTER' to roll a die.\n");
    enter = getchar();
    int die = rnd_dice();
    printf("Die rolled %d.\n", die);
    return die;
}

//hangman code

int hangman()
{
	FILE *srcfile = fopen("sportsfile.txt", "r");
	if (srcfile==NULL){
		perror("error in openin the provided file");
		return 1;
	}
	srand(time(0));
	int randword= rand()%43 + 1;//19
	int linenum=1;
	char word[100];
	char selectedword[100];
	while(fgets(word,sizeof(word),srcfile)!=NULL){
		if(linenum==randword){
			strcpy(selectedword,word);
			break;
		}
		linenum++;	
	}         
	int i,space;
	
	fclose(srcfile);
//	printf("%s\n",selectedword);
    int len=strlen(selectedword)-1;
    for(i=0;i<len;i++){
    	if(selectedword[i]==' '){
    		len=len-1;
    		space=i+1;
		}
	}
	char guess;
	int k,count=0;
    printf("Your WORD is a type of SPORT and it has *%d* letters and a space at %d. \nYou can have 5 wrong turns after which you will move 1 box back. Guess your word\nspace at 0 means no space\n",len,space);
    int len2=len;
    char wordprint[25];
    int mistakes=0,flag,p;
    for (int i = 0; i < len; i++) {
        if (selectedword[i] == ' ') {
            wordprint[i] = ' ';
        } else {
            wordprint[i] = '-';
        }
    }
    
    wordprint[len] = '\0';
    selectedword[len] = '\0';
    
    
    printf("\n%s\n",wordprint);
    
    while (mistakes < 5) {
        char ans;
        
        int correctGuess = 0;

        printf("Enter your letter: ");
        scanf(" %c", &ans);

        for (int m = 0; m < len; m++) {
            if (ans == selectedword[m]) {
                wordprint[m] = ans;
                correctGuess = 1;
            }
        }

        printf("%s\n", wordprint); 

        if(correctGuess){
		
        if (strcmp(wordprint, selectedword) == 0) {
            printf("Congratulations! You're the winner!\n");
            flag++;
           break;
        }
//        for(i=0;i<len-1;i++){
//        	if(wordprint[i]==selectedword[i]){
//        		flag++;
//			}
//			if(flag==len-1){
//				 printf("Congratulations! You're the winner!\n");
//				 break;
//			}
//		}
    }
    
    
        if (!correctGuess) {
            mistakes++;
            printf("Sorry, wrong try. You have %d lives left.\n", 5 - mistakes);
        }
//        if(flag==1){
//        	break;
//		}
    }
    if(flag>0){
    	return 1; //return 1 ke mtlb player has won hangman and he wins.
	}

    if (mistakes == 5) {
        printf("You're out of lives. Game over!\n");
        return 0;//yahan pe ye hoga ke agar function 0 return kre mtlb player hangman mai haargya and he will be moved a box back.
    }   
}

// random arithmetic problems.
int random_obstacles(int p_pos) 
{
    int randop;
    int value1 = rand() % 3000 + 1;
    int value2 = rand() % 3000 + 1;
    int ans;

    if (p_pos == 62 || p_pos == 13 || p_pos == 36 || p_pos == 62 || p_pos == 72 || p_pos == 88) {
        int op = rand() % 4;

        switch (op) {
            case 0:
                randop = '+';
                break;
            case 1:
                randop = '-';
                break;
            case 2:
                randop = '*';
                break;
            case 3:
                randop = '/';
                break;
            default:
                randop = '+';
        }

        switch (randop) {
            case '+':
                ans = value1 + value2;
                break;
            case '-':
                ans = value1 - value2;
                break;
            case '*':
                ans = value1 * value2;
                break;
            case '/':
                ans = (value2 != 0) ? value1 / value2 : 0;
                break;
            default:
                ans = value1 * value2;
        }

        printf("\nYOU NEED TO ANSWER THIS:\n");
        printf(" %d %c %d = ", value1, randop, value2);

        time_t start_time = time(NULL);  

        int n;
        scanf("%d", &n);

        time_t end_time = time(NULL);  

        if (difftime(end_time, start_time) <= 20) { 
            if (n == ans) {
            
                return 1;//return 1 ke mtlb player has answered correctly.
            } else {
                printf("Wrong answer. You wasted a chance. Better luck next time!\n");
                 return 0;//yahan pe ye hoga ke agar function 0 return kre mtlb player answered wrong
            }
        } 
		else {
            printf("Time's up! You didn't answer within the time limit.\n");
            return 0;//yahan pe ye hoga ke agar function 0 return kre mtlb player answered wrong
        }
    }

    return 0;
}

int main() 
{
	
	
	printf("Welcome to the game of snakes and ladders.\nThe game rules are as follows:\n\n1)You will have two players playing this game and the game lets you roll a die and advance accordingly to the hundredth box.\n\n2)At every six you get after the die roll you will have the wild card option which will let you:\n-move the opponent one box back\nor\n-get a chance to roll again\n\n4)At some boxes you will have to answer the given mathematical question, which will be random, in a given time limit. Failure to do so will move you a box back.\n\n5)At box 100 the player will have to get through to victory by playing a hangman game. Winning the hangman would mean winning the whole game\nhowever losing it will move the player one box back.\nHAVE FUN!\n\n");

	
    int board[10][10] = {
        100, 99, 98, 97, 96, 95, 94, 93, 92, 91,
        81, 82, 83, 84, 85, 86, 87, 88, 89, 90,
        80, 79, 78, 77, 76, 75, 74, 73, 72, 71,
        61, 62, 63, 64, 65, 66, 67, 68, 69, 70,
        60, 59, 58, 57, 56, 55, 54, 53, 52, 51,
        41, 42, 43, 44, 45, 46, 47, 48, 49, 50,
        40, 39, 38, 37, 36, 35, 34, 33, 32, 31,
        21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
        20, 19, 18, 17, 16, 15, 14, 13, 12, 11,
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	// printing board
		
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d\t", board[i][j]);
        }
        printf("\n");
    }
    
    printf("\nSNAKES AT : 27, 41, 74, 99\n"); 
    
    printf("\nLADDERS AT: 8, 21, 47, 69\n");
	
	printf("\n");
	
    int pos1 = 0;
    int pos2 = 0;

    while (pos1 < 100 && pos2 < 100) {
        int roll = player1();
        
        // Check if the player1 is on or beyond position 95
        if (pos1 >= 95 && roll >= 6) 
  		{
            printf("PLAYER_1: Invalid move! Skip turn.\n");
            
        }
  
  		else if (pos1 >= 96 && roll >= 5) 
  		{
            printf("PLAYER_1: Invalid move! Skip turn.\n");
            
        }
        
        else if (pos1 >= 97 && roll >= 4) 
  		{
            printf("PLAYER_1: Invalid move! Skip turn.\n");
            
        }
        
        else if (pos1 >= 98 && roll >= 3) 
  		{
            printf("PLAYER_1: Invalid move! Skip turn.\n");
            
        }
        
        else if (pos1 >= 99 && roll >= 2) 
  		{
            printf("PLAYER_1: Invalid move! Skip turn.\n");
            
        }
            
         else 
		 {
		 	
            pos1 += roll;
            
            int obs_ans= random_obstacles(pos1);
            if(obs_ans==1)
            {
            	pos1++;
			}
			else
			{
				pos1--;
			}
            
            if(pos1==8) //ladder
            {	pos1+=12;
			printf("ITS A LADDER PLAYER_1 jumps 12 spaces\n");	
			}
			
			else if(pos1==21) //ladder
			{	pos1+=10;
			printf("ITS A LADDER PLAYER_1 jumps 10 spaces\n");
			}
			
			else if(pos1==47) //ladder
			{	pos1+=12;
			printf("ITS A LADDER PLAYER_1 jumps 12 spaces\n");
			}
			
			else if(pos1==69) //ladder
			{	pos1+=14;
			printf("ITS A LADDER PLAYER_1 jumps 14 spaces\n");
			}
			
			else if(pos1==27) //snake
			{	pos1-=10;
			printf("ITS A SNAKE PLAYER_1 drops 10 spaces\n");
			}
			
			else if(pos1==41) //snake
			{	pos1-=8;
			printf("ITS A SNAKE PLAYER_1 drops 8 spaces\n");
			}
			
			else if(pos1==74) //snake
			{	pos1-=11;
			printf("ITS A SNAKE PLAYER_1 drops 11 spaces\n");
			}
			
			else if(pos1==98) //big snake
			{	pos1-=73;
			printf("ITS A SNAKE PLAYER_1 drops 73 spaces\n");
			}
			
			if(roll==6) //wild cards when die land's on 6
            
            {
            	int wildcards;
            	printf("\n ENTER YOUR CHOICE (1 or 2).\n1- Roll again.\n2- Move opponent a place back.\n");
            	scanf("%d", &wildcards);
            	
            	if(wildcards==1)
            	{
            		pos1+=player1(); //rolling again
				}
				
				else
				{
					pos2-=1; //moving opponent a box back.
					printf("\n(*PLAYER_2 is moved bck to --> %d*).\n\n", pos2);
					
				}
			}
			
			
            printf("PLAYER_1: Position = %d\n", pos1);
        }

        // Check if Player 1 won
        if (pos1 >= 100) \
		{
			int output= hangman();
			if(output==1)
			{
				
				printf("\nPLAYER_1 wins!\n");
				exit(0);
		
			}
		
			else
			{
				pos1--;
				printf("\nPLAYER_1: Position = %d\n", pos1);
			} 
            
        }

       
        roll = player2();

        // Check if the player2 is on or beyond position 95
        if (pos2 >= 95 && roll >= 6) 
 		 {
            printf("PLAYER_2: Invalid move! Skip turn.\n");
            
        }
  
  		else if (pos2 >= 96 && roll >= 5) 
 		{
            printf("PLAYER_2: Invalid move! Skip turn.\n");
            
   		}	
        
        else if (pos2 >= 97 && roll >= 4) 
  		{
            printf("PLAYER_2: Invalid move! Skip turn.\n");
            
        }
        
        else if (pos2 >= 98 && roll >= 3) 
 		 {
            printf("PLAYER_2: Invalid move! Skip turn.\n");
            
        }
        
        else if (pos2 >= 99 && roll >= 2) 
 		 {
            printf("PLAYER_2: Invalid move! Skip turn.\n");
            
        }
            
         else 
		 {
		 	
            pos2 += roll;
            
            int obs_ans= random_obstacles(pos1);
            if(obs_ans==1)
            {
            	pos2++;
			}
			else
			{
				pos2--;
			}
            
            if(pos2==8) //ladder
            {	pos2+=12;
			printf("ITS A LADDER PLAYER_2 jumps 12 spaces\n");	
			}
			
			else if(pos2==21) //ladder
			{	pos2+=10;
			printf("ITS A LADDER PLAYER_2 jumps 10 spaces\n");
			}
			
			else if(pos2==47) //ladder
			{	pos2+=12;
			printf("ITS A LADDER PLAYER_2 jumps 12 spaces\n");
			}
			
			else if(pos2==69) //ladder
			{	pos2+=14;
			printf("ITS A LADDER PLAYER_2 jumps 14 spaces\n");
			}
			
			else if(pos2==27) //snake
			{	pos2-=10;
			printf("ITS A SNAKE PLAYER_2 drops 10 spaces\n");
			}
			
			else if(pos2==41) //snake
			{	pos2-=8;
			printf("ITS A SNAKE PLAYER_2 drops 8 spaces\n");
			}
			
			else if(pos2==74) //snake
			{	pos2-=11;
			printf("ITS A SNAKE PLAYER_2 drops 11 spaces\n");
			}
			
			else if(pos2==98) //big snake
			{	pos2-=73;
			printf("ITS A SNAKE PLAYER_2 drops 73 spaces\n");
			}
			
			if(roll==6) //wild cards when die land's on 6.
            
            {
            	int wildcards;
            	printf("\n ENTER YOUR CHOICE (1 or 2).\n1- Roll again.\n2- Move opponent a place back.\n");
            	scanf("%d", &wildcards);
            	
            	if(wildcards==1)
            	{
            		pos2+=player2();
				}
				
				else
				{
					pos1-=1; //moving opponent a box back.
					printf("\n(*PLAYER_1 is moved bck to --> %d*).\n\n", pos1);
				}
			}
            
            printf("PLAYER_2: Position = %d\n", pos2);
        }

        // Check if Player 2 won
        if (pos2 >= 100) 
		{
            int output= hangman();
			if(output==1)
			{
				
				printf("\nPLAYER_2 wins!\n");
				exit(0);
		
			}
		
			else
			{
				pos2--;
				printf("\nPLAYER_2: Position = %d\n", pos2);
			} 
        }
    
	
	}// while condition ka bracket ha way up top.

    return 0;
}

