#include "io.h"
#include "moves.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

PlayerState player[2]; /*This has to be filled with the proper values through parse board*/
PlayerColor CurrentPlayer;
Pos ep_square;
Bool noEp;

int bKingPos = -1;
int wKingPos = -1;

/* Returns the piece on a square belonging to either color
 * If there is no piece, UNKNOWN is returned. */
Piece get_piece_at_general(Board pos) {
    if(IS_SET(player[WHITE].k, pos)) return KING;
    if(IS_SET(player[WHITE].q, pos)) return QUEEN;
    if(IS_SET(player[WHITE].b, pos)) return BISHOP;
    if(IS_SET(player[WHITE].n, pos)) return NIGHT;
    if(IS_SET(player[WHITE].r, pos)) return ROOK;
    if(IS_SET(player[WHITE].p, pos)) return PAWN;

    if(IS_SET(player[BLACK].k, pos)) return KING;
    if(IS_SET(player[BLACK].q, pos)) return QUEEN;
    if(IS_SET(player[BLACK].b, pos)) return BISHOP;
    if(IS_SET(player[BLACK].n, pos)) return NIGHT;
    if(IS_SET(player[BLACK].r, pos)) return ROOK;
    if(IS_SET(player[BLACK].p, pos)) return PAWN;

    return UNKNOWN;
}

char get_piece_char_print(Pos pos)
{
	if(IS_SET(player[WHITE].r, pos)) return 'R';
	if(IS_SET(player[WHITE].q, pos)) return 'Q';
	if(IS_SET(player[WHITE].p, pos)) return 'P';
	if(IS_SET(player[WHITE].b, pos)) return 'B';
	if(IS_SET(player[WHITE].n, pos)) return 'N';
	if(IS_SET(player[WHITE].k, pos)) return 'K';
	if(IS_SET(player[BLACK].r, pos)) return 'r';
	if(IS_SET(player[BLACK].q, pos)) return 'q';
	if(IS_SET(player[BLACK].p, pos)) return 'p';
	if(IS_SET(player[BLACK].b, pos)) return 'b';
	if(IS_SET(player[BLACK].n, pos)) return 'n';
	if(IS_SET(player[BLACK].k, pos)) return 'k';

	return ' ';
}

Bool checkPawns()
{
	int i;
	for(i = 0; i < 8; i++)
	{
		if(IS_SET(player[0].p, i) == TRUE)
		{
			return FALSE;
		}
		if(IS_SET(player[1].p, i) == TRUE)
		{
			return FALSE;
		}
	}
	for(i = 56; i < 64; i++)
	{
		if(IS_SET(player[0].p, i) == TRUE)
		{
			return FALSE;
		}
		if(IS_SET(player[1].p, i) == TRUE)
		{
			return FALSE;
		}
	}

	return TRUE;
}

Bool checkEp()
{
	if(noEp == TRUE)
	{
		return TRUE;
	}

	if(CurrentPlayer == WHITE)
	{
		if(ep_square < 16 || ep_square > 23)
		{
			return FALSE;
		}
		if(IS_SET(player[0].p, (ep_square+8)) == FALSE)
		{
			return FALSE;
		}
		if(get_piece_at_general(ep_square-8) != UNKNOWN)
		{
			return FALSE;
		}
	}
	if(CurrentPlayer == BLACK)
	{
		if(ep_square < 40 || ep_square > 47)
		{
			return FALSE;
		}
		if(IS_SET(player[1].p, (ep_square-8)) == FALSE)
		{
			return FALSE;
		}
		if(get_piece_at_general(ep_square+8) != UNKNOWN)
		{
			return FALSE;
		}
	}

	noEp = FALSE;
	return TRUE;
}

Bool checkCastle()
{
	int bk = 4;
	int wk = 60;

	int bqr = 0;
	int bkr = 7;

	int wqr = 56;
	int wkr = 63;

	if(player[0].castle_flags == 0 && player[1].castle_flags == 0)
	{
		return TRUE;
	}
	if(player[0].castle_flags != 0 && get_piece_at(bk, BLACK) != KING)
	{
		return FALSE;
	}
	if(player[1].castle_flags != 0 && get_piece_at(wk, WHITE) != KING)
	{
		return FALSE;
	}

	if(player[0].castle_flags == 1 && get_piece_at(bkr, BLACK) != ROOK)
	{
		return FALSE;
	}
	if(player[0].castle_flags == 2 && get_piece_at(bqr, BLACK) != ROOK)
	{
		return FALSE;
	}
	if(player[0].castle_flags == 3 && (get_piece_at(bkr, BLACK) != ROOK || get_piece_at(bqr, BLACK) != ROOK))
	{
		return FALSE;
	}

	if(player[1].castle_flags == 1 && get_piece_at(wkr, WHITE) != ROOK)
	{
		return FALSE;
	}
	if(player[1].castle_flags == 2 && get_piece_at(wqr, WHITE) != ROOK)
	{
		return FALSE;
	}
	if(player[1].castle_flags == 3 && (get_piece_at(wkr, WHITE) != ROOK || get_piece_at(wqr, WHITE) != ROOK))
	{
		return FALSE;
	}

	if(player[0].castle_flags == 1 || player[0].castle_flags == 3)
	{
		if(get_piece_at_general(5) != UNKNOWN || get_piece_at_general(6) != UNKNOWN)
		{
			return FALSE;
		}
	}
	if(player[0].castle_flags == 2 || player[0].castle_flags == 3)
	{
		if(get_piece_at_general(1) != UNKNOWN || get_piece_at_general(2) != UNKNOWN || get_piece_at_general(3) != UNKNOWN)
		{
			return FALSE;
		}
	}

	if(player[1].castle_flags == 1 || player[1].castle_flags == 3)
	{
		if(get_piece_at_general(62) != UNKNOWN || get_piece_at_general(61) != UNKNOWN)
		{
			return FALSE;
		}
	}
	if(player[1].castle_flags == 2 || player[1].castle_flags == 3)
	{
		if(get_piece_at_general(57) != UNKNOWN || get_piece_at_general(58) != UNKNOWN || get_piece_at_general(59) != UNKNOWN)
		{
			return FALSE;
		}
	}

	return TRUE;
}


Bool setEp(char *eps)
{
	char *lets = "abcdefgh";
	char *nums = "87654321";

	int i;
	int valid = 0;
	int ind1= -1;
	int ind2 = -1;

	noEp = TRUE;

	if(eps[0] == '-' && eps[1] == '\0')
	{
		ep_square = -1;
		return TRUE;
	}

	for(i = 0; i < strlen(lets); i++)
	{
		if(eps[0] == lets[i])
		{
			ind1 = i;
			valid = 1;
		}
	}
	if(valid != 1)
	{
		return FALSE;
	}
	valid = 0;

	for(i = 0; i < strlen(nums); i++)
	{
		if(eps[1] == nums[i])
		{
			ind2 = i;
			valid = 1;
		}
	}
	if(valid != 1)
	{
		return FALSE;
	}

	ep_square = (ind2*8)+ind1;
	noEp = FALSE;
	return TRUE;
}

Bool parse_flags(char *input)
{
	int len = strlen(input);
	if(len < 3)
	{
		return FALSE;
	}

	if(input[0] == 'b')
	{
		CurrentPlayer = BLACK;
	}
	else if(input[0] == 'w')
	{
		CurrentPlayer = WHITE;
	}
	else
	{
		return FALSE;
	}

	if(input[1] != ' ')
	{
		return FALSE;
	}

	int k1 = 0;
	int k2 = 0;
	int q1 = 0;
	int q2 = 0;

	int h = 0;

	player[0].castle_flags = 0;
	player[1].castle_flags = 0;
	int index = 2;
	int isSpace = 0;

	while(index < len && isSpace == 0)
	{
		switch(input[index])
		{
			case '-':
				h++;
				index++;
				break;
			case 'k':
				player[0].castle_flags += 1;
				index++;
				k1++;
				break;
			case 'K':
				player[1].castle_flags += 1;
				index++;
				k2++;
				break;
			case 'q':
				player[0].castle_flags += 2;
				index++;
				q1++;
				break;
			case 'Q':
				player[1].castle_flags += 2;
				index++;
				q2++;
				break;
			case ' ':
				index++;
				isSpace = 1;
				break;
			default:
				return FALSE;
				break;
		}
	}
	if(h > 1)
	{
		return FALSE;
	}
	if(h != 1 && (k1+k2+q1+q2) == 0)
	{
		return FALSE;
	}
	if(k1 > 1 || k2 > 1 || q1 > 1 || q2 > 1)
	{
		return FALSE;
	}

	char *ep = (char*)malloc(3*sizeof(char));
	if(index < len)
	{
		if(input[index] == '-' && (index+1) == len)
		{
			ep[0] = '-';
			ep[1] = '\0';
		}
		else if((index+1)<len && (index+2) == len)
		{
			/*ep square is at most 2 chars long!*/
			ep[0] = input[index];
			ep[1] = input[index+1];
			ep[2] = '\0';
		}
		else
		{
			return FALSE;
		}
	}
	else
	{
		return FALSE;
	}
	Bool validate = setEp(ep);
	if(validate == FALSE)
	{
		return FALSE;
	}
	free(ep);
	return TRUE;
}

void display_board() {
    unsigned int i =0, j=0;
    printf("\n −−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−\n");
    for(i=0; i < 8; i++){ /*Rank (Rows)*/
        printf("%d |", 8-i);
        for(j=0; j<8; j++){ /*File (Columns)*/
            printf(" %c |", get_piece_char_print(i*8+j));
        }
        printf("\n −−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−\n");
    }
    printf("   a   b   c   d   e   f   g   h\n");
    printf("\n");
    printf("Current move %s\n", CurrentPlayer == WHITE ? "White" : "Black"); /*CurrentPlayer*/
}

Bool adjacentNums(char *row) /*returns true if there are two numbers next to eachother*/
{
	char *nums = "12345678";
	int adNums = 0;
	int i, j;
	int isNum;
	for(i = 0; i < strlen(row); i++)
	{
		isNum = 0;
		for(j = 0; j < strlen(nums); j++)
		{
			if(row[i] == nums[j])
			{
				isNum = 1;
			}
		}
		if(isNum == 1)
		{
			adNums++;
		}
		else
		{
			adNums = 0;
		}

		if(adNums > 1)
		{
			return TRUE;
		}
	}
	return FALSE;
}

Bool sumsToEight(char *rank)
{
	int i;
	int sum = 0;

	for(i = 0; i < strlen(rank); i++)
	{
		switch(rank[i])
		{
			case '1':
				sum += 1;
				break;
			case '2':
				sum += 2;
				break;
			case '3':
				sum += 3;
				break;
			case '4':
				sum += 4;
				break;
			case '5':
				sum += 5;
				break;
			case '6':
				sum += 6;
				break;
			case '7':
				sum += 7;
				break;
			case '8':
				sum += 8;
				break;
			default:
				sum += 1;
				break;
		}
	}

	if(sum != 8)
	{
		return FALSE;
	}

	return TRUE;
}

Bool piece_in_range(char **rows)
{
	int r1 = 0;
	int r2 = 0;
	int n1 = 0;
	int n2 = 0;
	int b1 = 0;
	int b2 = 0;
	int q1 = 0;
	int q2 = 0;
	int k1 = 0;
	int k2 = 0;
	int p1 = 0;
	int p2 = 0;

	int i, j;

	for(i = 0; i < 8; i++)
	{
		for(j = 0; j < strlen(rows[i]); j++)
		{
			switch(rows[i][j])
			{
				case 'r':
					r1++;
					break;
				case 'R':
					r2++;
					break;
				case 'n':
					n1++;
					break;
				case 'N':
					n2++;
					break;
				case 'b':
					b1++;
					break;
				case 'B':
					b2++;
					break;
				case 'q':
					q1++;
					break;
				case 'Q':
					q2++;
					break;
				case 'k':
					k1++;
					break;
				case 'K':
					k2++;
					break;
				case 'p':
					p1++;
					break;
				case 'P':
					p2++;
					break;
				default:
					break;
			}
		}
	}

	if(k1 != 1 || k2 != 1)
	{
		return FALSE;
	}
	if(p1 > 8 || p2 > 8)
	{
		return FALSE;
	}
	if((p1 + r1 + n1 + b1 + q1) > 15 || (p2 + r2 + n2 + b2 + q2) > 15)
	{
		return FALSE;
	}
	if((b1 > 10) || (b2 > 10) || (n1 > 10) || (n2 > 10) || (r1 > 10) || (r2 > 10) || (q1 > 9) || (q2 > 9))
	{
		return FALSE;
	}

	return TRUE;
}

void setBoard(char **rows)
{
	player[0].p = 0;
	player[0].r = 0;
	player[0].b = 0;
	player[0].n = 0;
	player[0].q = 0;
	player[0].k = 0;

	player[1].p = 0;
	player[1].r = 0;
	player[1].b = 0;
	player[1].n = 0;
	player[1].q = 0;
	player[1].k = 0;

	int pos = 0;
	int i, j;

	for(i = 0; i < 8; i++)
	{
		for(j = 0; j < strlen(rows[i]); j++)
		{
			switch(rows[i][j])
			{
				case '1':
					pos += 1;
					break;
				case '2':
					pos += 2;
					break;
				case '3':
					pos += 3;
					break;
				case '4':
					pos += 4;
					break;
				case '5':
					pos += 5;
					break;
				case '6':
					pos += 6;
					break;
				case '7':
					pos += 7;
					break;
				case '8':
					pos += 8;
					break;
				case 'p':
					SET_BIT(player[0].p, pos);
					pos++;
					break;
				case 'P':
					SET_BIT(player[1].p, pos);
					pos++;
					break;
				case 'n':
					SET_BIT(player[0].n, pos);
					pos++;
					break;
				case 'N':
					SET_BIT(player[1].n, pos);
					pos++;
					break;
				case 'q':
					SET_BIT(player[0].q, pos);
					pos++;
					break;
				case 'Q':
					SET_BIT(player[1].q, pos);
					pos++;
					break;
				case 'r':
					SET_BIT(player[0].r, pos);
					pos++;
					break;
				case 'R':
					SET_BIT(player[1].r, pos);
					pos++;
					break;
				case 'b':
					SET_BIT(player[0].b, pos);
					pos++;
					break;
				case 'B':
					SET_BIT(player[1].b, pos);
					pos++;
					break;
				case 'k':
					SET_BIT(player[0].k, pos);
					bKingPos = pos;
					pos++;
					break;
				case 'K':
					SET_BIT(player[1].k, pos);
					wKingPos = pos;
					pos++;
					break;
				default:
					printf("Unknown char in input\n");
					break;
			}
		}
	}

	if(pos != 64)
	{
		printf("Not enough data in input!\n");
	}
}

Bool parse_board(char *board) {
    /* Your implementation */
    int i, j;
    int slashCount = 0;
    int len = strlen(board);
    char *legalChars = "abcdefgh12345678 /w-rnbqkpRNBQKP";
    int len2 = strlen(legalChars);
    int legal;

    for(i = 0; i < len; i++)
    {
	    legal = 0;
	    if(board[i] == '/')
	    {
		    slashCount++;
	    }
	    for(j = 0; j < len2; j++)
	    {
		   if(board[i] == legalChars[j])
		   {
			   legal = 1;
		   }
	    }
	    if(legal == 0)
	    {
		    return FALSE;
	    }
    }
    if(slashCount != 7)
    {
	    return FALSE;
    }

   char **ranks = (char**)malloc(8*sizeof(char*));
   int index2;

   int curIndex = 0;
   int lastIndex = 0;
   int curRank = 0;
   int toMalloc = 0;
   int mallocedRows = 0;

   while(curRank < 8 || curIndex == len) /*puts rank data into the array*/
   {
	if(board[curIndex] == '/' || (curRank == 7 && board[curIndex] == ' '))
	{
		toMalloc = 0;
		for(i = lastIndex; i < curIndex; i++)
		{
			toMalloc++;
		}
		if(toMalloc == 0)
		{
			return FALSE;
		}
		ranks[curRank] = (char*)malloc((1+toMalloc)*sizeof(char));
		mallocedRows++;
		for(i = 0; i < toMalloc; i++)
		{
			ranks[curRank][i] = board[lastIndex+i];
		}
		ranks[curRank][i] = '\0'; /*possible fix*/
		lastIndex = curIndex+1;
		curRank++;
	}
	curIndex++;
   }

   index2 = curIndex;

   if(mallocedRows != 8)
   {
	   return FALSE;
   }

   for(i = 0; i < 8; i++)
   {
	   if(strlen(ranks[i]) < 1 || strlen(ranks[i]) > 8)
	   {
		/*ranks can't be empty or contain >8 chars*/
		/*MIGHT seg fault if length is zero*/
		return FALSE;
	   }
   }
   char *valCharsRank = "12345678rnbqkpRNBQKP";
   int valCount;
   int valNeeded;
   int k;
   /*checking if each rank contains only valid characters*/
   for(i = 0; i < 8; i++)
   {
	   valCount = 0;
	   valNeeded = strlen(ranks[i]);
	   for(j = 0; j < strlen(ranks[i]); j++)
	   {
		for(k = 0; k < strlen(valCharsRank); k++)
		{
			if(ranks[i][j] == valCharsRank[k])
			{
				valCount++;
			}
		}
	   }
	   if(valCount != valNeeded)
	   {
		   return FALSE;
	   }
   }
   /*checking to see if each rank has no adjacent numbers*/
   Bool numIsAd;
   for(i = 0; i < 8; i++)
   {
	numIsAd = adjacentNums(ranks[i]);
	if(numIsAd == TRUE)
	{
		return FALSE;
	}
   }

   /*checking to see if each rank sums to 8 positions*/
   Bool sumsEight;
   for(i = 0; i < 8; i++)
   {
	sumsEight = sumsToEight(ranks[i]);
	if(sumsEight == FALSE)
	{
		return FALSE;
	}
   }

   /*checks to see if number of each piece is within legal range*/
   Bool inRange = piece_in_range(ranks);

   if(inRange == FALSE)
   {
	   return FALSE;
   }

   /*fills each board with proper data*/
   setBoard(ranks);

   /*frees malloc*/
   for(i = 0; i < 8; i++)
   {
	   free(ranks[i]);
   }
   free(ranks);
   /*sets additional data*/
   int ind2len = strlen(board) - index2;
   char data2[ind2len+1];
   memcpy(data2, &board[index2], ind2len);
   data2[ind2len] = '\0';
   Bool pData = parse_flags(data2);
   if(pData == FALSE)
   {
	   return FALSE;
   }
   /*checks to see if castling is valid*/
   Bool isVal = checkCastle();
   if(isVal == FALSE)
   {
	   return FALSE;
   }
   /*checks to see if en passant is valid*/
   isVal = checkEp();
   if(isVal == FALSE)
   {
	   return FALSE;
   }
   /*checks if pawns are in a valid rank*/
   isVal = checkPawns();
   if(isVal == FALSE)
   {
	   return FALSE;
   }
   /*checks if either king is under check*/
   PlayerColor copy = CurrentPlayer;
   Bool isCheck;
   if(CurrentPlayer == BLACK)
   {
   	CurrentPlayer = WHITE;
   	isCheck = is_check(wKingPos, CurrentPlayer);
   	if(isCheck == TRUE)
   	{
	   	return FALSE;
   	}
   }
   else
   {
   	CurrentPlayer = BLACK;
   	isCheck = is_check(bKingPos, CurrentPlayer);
   	if(isCheck == TRUE)
   	{
	   	return FALSE;
   	}
   }
   CurrentPlayer = copy;
   return TRUE;
}

/* Parses the input move.
 * This function repeatedly prompts for a move until a valid move is typed in.
 * This function only validates that:
 *	 1) from and to are valid squares on the board.
 *	 2) from and to are separated by a '-'
 * This function does not check the legality of the move.
 */
Move parse_move() {
    char *valLetters = "abcdefgh";
    char *valNums = "12345678";
    int i;
    int fromRank = -1;
    int fromFile = -1;
    int toRank = -1;
    int toFile = -1;

    int validMove = 0;/*should be 6 to be valid*/
    char *input = malloc(sizeof(char)*7);
    while(validMove < 6)
    {
	validMove = 0;
	printf("Please input a valid move");
	scanf("%6s", input);
	if(input[5] == '\0' && input[2] == '-')
	{
		validMove+=2;
	}
	for(i = 0; i < 7; i++)
	{
		if(input[0] == valLetters[i])
		{
			validMove++;
			fromFile = i;
		}
		if(input[3] == valLetters[i])
		{
			validMove++;
			toFile = i;
		}
	}
	for(i = 0; i < 7; i++)
	{
		if(input[1] == valNums[i])
		{
			validMove++;
			fromRank = i;
		}
		if(input[4] == valNums[i])
		{
			validMove++;
			toRank = i;
		}
	}

    }

    int fromPos = fromRank*8+fromFile;
    int toPos = toRank*8+toFile;

    Move parsed;
    parsed.from = fromPos;
    parsed.to = toPos;
    parsed.piece = get_piece_at_general(fromPos);
    	free(input);
	return parsed;
}

/* This function accepts a move from the user. The move is not validated */
void prompt_move(Move *m, unsigned int move_number) {
    /* Your implementation */
}

/* This function prints a move on to the console */
void print_move(Move *m) {
    /* Your implementation */

	char *letters = "abcdefgh";
	char fromLetter = 'X';
	char toLetter = 'X';

	int fromFile = (m->from)%8;
	int toFile = (m->to)%8;

	int fromRank = 8-((m->from)/8);
	int toRank = 8-((m->to)/8);

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
	}

	printf("%c%d-%c%d\n", fromLetter, fromRank, toLetter, toRank);

}
