#include"chess.h"
#include "moves.h"
#include<stdlib.h>
#include<stdio.h>
Bool run_mate1(Move* soln){
	PlayerState playerCopy[2];
	playerCopy[0] = player[0];
	playerCopy[1] = player[1];
	Pos epCopy = ep_square;

	char *message;

	/*PlayerColor opp = BLACK;
	if(CurrentPlayer == BLACK) opp = WHITE;*/
	Move* legalList;
	unsigned int pcount;
	legal_moves(&legalList,CurrentPlayer,&pcount);
	int i;

	Move *temp;
	int w;

		/*Move* temp=(Move*)malloc(sizeof(Move));
		unsigned int temp2;
		legal_moves(&temp,opp,&temp2);
		int k = 0;
		printf("_________OPP MOVES________\n");
		while(k < temp2-1){
			print_move(temp);
			temp = temp->next_move;
			k++;
		}
		printf("__________________________\n");
		temp=(Move*)malloc(sizeof(Move));
		legal_moves(&temp,CurrentPlayer,&temp2);
		k = 0;
		printf("_________CUR MOVES________\n");
		while(k < temp2){
			print_move(temp);
			printf("%d-%d\n",temp->from,temp->to);
			temp = temp->next_move;
			k++;
		}
		printf("__________________________\n");
		printf("%d\n",temp2);*/

	for(i=0;i<pcount;i++){
		Bool valid = validate_and_move(legalList, &message, CurrentPlayer, &ep_square);
		if(valid == TRUE)
		{	
		    if(is_draw() != TRUE){
			
			if(is_checkmate() == TRUE)
			{
				*soln = *legalList;
				player[0] = playerCopy[0];
				player[1] = playerCopy[1];
				ep_square = epCopy;
				for(w = i; w < pcount; w++)
				{
					if(w < pcount-1)
					{
						temp = legalList;
						legalList = legalList->next_move;
						free(temp);
					}
				}
				free(legalList);
				return TRUE;
			}
		    }
		}
		if(i < pcount-1)
		{	
			temp = legalList;
			legalList = legalList->next_move;
			free(temp);
		}
		player[0] = playerCopy[0];
		player[1] = playerCopy[1];
		ep_square = epCopy;
	}
	free(legalList);
	return FALSE;
}

Bool run_mate2(Move* soln){
	PlayerState playerCopy[2];
	playerCopy[0] = player[0];
	playerCopy[1] = player[1];
	Pos epCopy = ep_square;
	Bool solution = TRUE;
	PlayerColor opp = BLACK;
	if(CurrentPlayer == BLACK) opp = WHITE;
	Move* legalMoves;
	Move* temp = (Move*)malloc(sizeof(Move));
	unsigned int plength;
	legal_moves(&legalMoves,CurrentPlayer,&plength);
	char* msg;
	int i;
	int j;
	Bool valid1;
	Bool valid2;

	Move* temp2;

	PlayerState playerCopy2[2];

	int w;

	for(i = 0; i<plength;i++){
		solution = TRUE;
		Move* legalMoves2;
		unsigned int plength2;
		valid1 = validate_and_move(legalMoves,&msg,CurrentPlayer,&ep_square);	
		if(valid1 == TRUE)
		{
			playerCopy2[0] = player[0];
			playerCopy2[1] = player[1];
			legal_moves(&legalMoves2,opp,&plength2);
			for(j = 0;j<plength2;j++){
				valid2 = validate_and_move(legalMoves2,&msg,opp,&ep_square);
				if(valid2 == TRUE)
				{
					if(run_mate1(temp) != TRUE){
						solution = FALSE;
						for(w = j; w < plength2-1; w++)
						{
							temp2 = legalMoves2;
							legalMoves2 = legalMoves2->next_move;
							free(temp2);
						}
						break;
					}
				}
				if(j < plength2-1)
				{
					temp2 = legalMoves2;
					legalMoves2= legalMoves2->next_move;
					free(temp2);
				}
				player[0] = playerCopy2[0];
				player[1] = playerCopy2[1];
				ep_square = epCopy;
			}
			free(legalMoves2);
			if(solution == TRUE)
			{
				*soln = *legalMoves;
				free(temp);
				for(w = i; w < plength; w++)
				{
					if(w < plength-1)
					{
						temp2 = legalMoves;
						legalMoves = legalMoves->next_move;
						free(temp2);
					}
				}
				free(legalMoves);
				return TRUE;
			}
		}
		if(i < plength-1)
		{
			temp2 = legalMoves;
			legalMoves = legalMoves->next_move;
			free(temp2);
		}
		player[0] = playerCopy[0];
		player[1] = playerCopy[1];
		ep_square = epCopy;
		solution = TRUE;
	}
		free(legalMoves);
		free(temp);
		return FALSE;
}
