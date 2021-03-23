#include "moves.h"
#include "chess.h"
#include "io.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* char_move(Move *m);

int main(int argc, char const *argv[]) {
	if(argc != 4)
	{
		printf("Invalid arguments!\n");
		return 0;
	}
	int mode;
       	
	if(strcmp(argv[3], "1") == 0)
	{
		mode = 1;
	}
	else if(strcmp(argv[3], "2") == 0)
	{
		mode = 2;
	}
	else
	{
		printf("%s is an invalid mode!\n", argv[3]);
		return 0;
	}
	FILE *fp = fopen(argv[1], "r");
	/*FILE *fp = fopen("puzzles.txt", "r");*/
	if(fp == NULL)
	{
		printf("Unable to open %s for reading.\n", argv[1]);
		return 0;
	}
	char phrase[100];
	int i;
	FILE *out = fopen(argv[2], "w+");
	/*FILE *out = fopen("output.txt", "w+");*/

	if(out == NULL)
	{
		printf("Unable to open %s for writing.\n", argv[2]);
		return 0;
	}
	Move *solution = (Move*)malloc(sizeof(Move));
	Bool isValid;
	Bool hasSol;
	char *solString;
	int printCount = 1;

	while(fgets(phrase, 100, fp))
	{
		for(i = 0; i < strlen(phrase); i++)
		{
			if(phrase[i] == '\n' && i != 0)
			{
				if(phrase[i-1] == ' ')
				{
					phrase[i-1] = '\0';
				}
				else
				{
					phrase[i] = '\0';
				}
			}
			/*else if(phrase[i] == '\n' && i == 0)
			{
				printf("File cannot contain empty lines!\n");
			}*/
		}
		if(mode == 1)
		{
			isValid = parse_board(phrase);
			if(isValid == TRUE)
			{
				hasSol = run_mate1(solution);
			}
			else
			{
				hasSol = FALSE;
			}
			if(isValid == TRUE && hasSol == TRUE)
			{
				solString = char_move(solution);
				fputs(solString, out);
				free(solString);
			}
			else
			{
				fputs("No Solution\n", out);
			}
		}
		else if(mode == 2)
		{
			isValid = parse_board(phrase);
			if(isValid == TRUE)
			{
				hasSol = run_mate2(solution);
			}
			else
			{
				hasSol = FALSE;
			}

			if(isValid == TRUE && hasSol == TRUE)
			{
				solString = char_move(solution);
				fputs(solString, out);
				free(solString);
			}
			else
			{
				fputs("No Solution\n", out);
			}
			printf("%d\n", printCount);
			printCount++;
		}	
	}
	fclose(fp);
	fclose(out);
	free(solution);
	/*free(solString);*/
	return 0;

  /*char *test2 = "2bqkbn1/2pppp2/np2N3/r3P1p1/p2N2B1/5Q2/PPPPKPP1/RNB2r2 w - -";
  char *test = "2bq1bn1/2pppk2/np2N3/r3P1p1/p2N2B1/8/PPPPKPP1/RNB2r2 w - -";
  char *test3 = "6bk/4B2p/8/8/8/8/8/K7 w - -";
  char *test4 = "3B2rk/7p/8/8/8/8/8/K7 w - -";
  char *test5 = "2bq1bn1/2pppk2/np2N3/r3P1p1/p2N2B1/8/PPPPKPP1/RNB2r2 w - -";
  char *test6 = "1R6/8/3N4/p7/kp6/8/1K6/2R5 w - -";
  Move* solutio = (Move*) malloc(sizeof(Move));
  Bool isValid = parse_board(test6);
  if(isValid == TRUE)
  {
	  printf("Board is valid!\n");
	  display_board();
  }
  else
  {
	  printf("Invalid board.\n");
  }
  Bool isFound = run_mate1(solutio);
  if(isFound == FALSE)
  {
	  printf("No solution\n");
  }
  else
  {
	print_move(solutio);
  }

  return 0;*/
}

char* char_move(Move *m) {
	char *output = (char*)malloc(7*sizeof(char));
	char *letters = "abcdefgh";
	char *nums = "87654321";
	char fromLetter = 'X';
	char toLetter = 'X';
	char fromNum = 'X';
	char toNum = 'X';

	int fromFile = (m->from)%8;
	int toFile = (m->to)%8;

	int fromRank = ((m->from)/8);
	int toRank = ((m->to)/8);

	int i;
	for(i = 0; i < 8; i++)
	{
		if(fromFile == i)
		{
			fromLetter = letters[i];
		}
		if(toFile == i)
		{
			toLetter = letters[i];
		}
		if(fromRank == i)
		{
			fromNum = nums[i];
		}
		if(toRank == i)
		{
			toNum = nums[i];
		}
	}
	
	output[0] = fromLetter;
	output[1] = fromNum;
	output[2] = '-';
	output[3] = toLetter;
	output[4] = toNum;
	output[5] = '\n';	
	output[6] = '\0';
	return output;
}
