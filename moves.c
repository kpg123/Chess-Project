#include "moves.h"
#include "stdlib.h"
#include<stdio.h>

/* Given a color, this function returns a singly linked list of all legal Moves with the head at *m.
* The function returns TRUE if at least 1 legal move is available.
* The total number of moves found is stored in the address pointed to by pcount. */
Bool legal_moves(Move **m, PlayerColor c, unsigned int *pcount) {/*Kieran Will work on this*/
	Move *current = (Move*)malloc(sizeof(Move));
	PlayerColor opp;
	*m = current;
	if(c == WHITE) opp = BLACK;
	if(c == BLACK) opp = WHITE;
	Pos count = 0;
	Pos i;
	for(i = 0; i <= 63; i++){
		if(get_piece_at(i,c) == UNKNOWN)
		{
		}
		else if(get_piece_at(i,c) == QUEEN){
			int temp = i;
			while(temp > 8 && get_piece_at_general(temp-9) == UNKNOWN && temp % 8 != 0){
				current->from = i;
				current->to = temp-9;
				current->piece = get_piece_at(i,c);
				current->next_move  = (Move*)malloc(sizeof(Move));
				current = current->next_move;
				temp -= 9;
				count++;
			}
			if(temp >= 9 && get_piece_at(temp-9,opp) != UNKNOWN && temp % 8 != 0){
				current->from = i;
				current->to = temp - 9;
				current->piece = get_piece_at(i,c);
				current->next_move  = (Move*)malloc(sizeof(Move));
				current = current->next_move;
				count++;
			}
			temp = i;
			while(temp > 7 && get_piece_at_general(temp-8) == UNKNOWN){
				current->from = i;
				current->to = temp-8;
				current->piece = get_piece_at(i,c);
				current->next_move  = (Move*)malloc(sizeof(Move));
				current = current->next_move;
				temp -= 8;
				count++;
			}
			if(temp >= 8 && get_piece_at(temp-8,opp) != UNKNOWN){
				current->from = i;
				current->to = temp - 8;
				current->piece = get_piece_at(i,c);
				current->next_move  = (Move*)malloc(sizeof(Move));
				current = current->next_move;
				count++;
			}
			temp = i;
			while(temp > 7 && get_piece_at_general(temp-7) == UNKNOWN && (temp +1) %8 != 0){
				current->from = i;
				current->to = temp-7;
				current->piece = get_piece_at(i,c);
				current->next_move  = (Move*)malloc(sizeof(Move));
				current = current->next_move;
				temp -= 7;
				count++;
			}
			if(temp >= 7 && get_piece_at(temp-7,opp) != UNKNOWN && (temp +1) %8 != 0){
				current->from = i;
				current->to = temp - 7;
				current->piece = get_piece_at(i,c);
				current->next_move  = (Move*)malloc(sizeof(Move));
				current = current->next_move;
				count++;
			}
			temp = i;
			while(temp > 0 && get_piece_at_general(temp-1) == UNKNOWN && temp %8 != 0){
				current->from = i;
				current->to = temp-1;
				current->piece = get_piece_at(i,c);
				current->next_move  = (Move*)malloc(sizeof(Move));
				current = current->next_move;
				temp -= 1;
				count++;
			}
			if(temp >= 1 && get_piece_at(temp-1,opp) != UNKNOWN && temp %8 != 0){
				current->from = i;
				current->to = temp - 1;
				current->piece = get_piece_at(i,c);
				current->next_move  = (Move*)malloc(sizeof(Move));
				current = current->next_move;
				count++;
			}
			temp = i;
			while(temp < 63 && get_piece_at_general(temp +1) == UNKNOWN && (temp +1) %8 != 0){
				current->from = i;
				current->to = temp+1;
				current->piece = get_piece_at(i,c);
				current->next_move  = (Move*)malloc(sizeof(Move));
				current = current->next_move;
				temp += 1;
				count++;
			}
			if(temp <= 63 && get_piece_at(temp+1,opp) != UNKNOWN && (temp +1) %8 != 0){
				current->from = i;
				current->to = temp + 1;
				current->piece = get_piece_at(i,c);
				current->next_move  = (Move*)malloc(sizeof(Move));
				current = current->next_move;
				count++;
			}
			temp = i;
			while(temp < 56 && get_piece_at_general(temp+7) == UNKNOWN && temp %8 != 0){
				current->from = i;
				current->to = temp+7;
				current->piece = get_piece_at(i,c);
				current->next_move  = (Move*)malloc(sizeof(Move));
				current = current->next_move;
				temp += 7;
				count++;
			}
			if(temp <= 56 && get_piece_at(temp+7,opp) != UNKNOWN && temp %8 != 0){
				current->from = i;
				current->to = temp + 7;
				current->piece = get_piece_at(i,c);
				current->next_move  = (Move*)malloc(sizeof(Move));
				current = current->next_move;
				count++;
			}
			temp = i;
			while(temp < 56 && get_piece_at_general(temp+8) == UNKNOWN){
				current->from = i;
				current->to = temp+8;
				current->piece = get_piece_at(i,c);
				current->next_move  = (Move*)malloc(sizeof(Move));
				current = current->next_move;
				temp += 8;
				count++;
			}
			if(temp <= 55 && get_piece_at(temp+8,opp) != UNKNOWN){
				current->from = i;
				current->to = temp + 8;
				current->piece = get_piece_at(i,c);
				current->next_move  = (Move*)malloc(sizeof(Move));
				current = current->next_move;
				count++;
			}
			temp = i;
			while(temp < 55 && get_piece_at_general(temp+9) == UNKNOWN && (temp+1) % 8 !=0){
				current->from = i;
				current->to = temp+9;
				current->piece = get_piece_at(i,c);
				current->next_move  = (Move*)malloc(sizeof(Move));
				current = current->next_move;
				temp += 9;
				count++;
			}
			if(temp <= 55 && get_piece_at(temp+9,opp) != UNKNOWN && (temp+1) % 8 !=0){
				current->from = i;
				current->to = temp + 9;
				current->piece = get_piece_at(i,c);
				current->next_move  = (Move*)malloc(sizeof(Move));
				current = current->next_move;
				count++;
			}
		}
		else if(get_piece_at(i,c) == ROOK){
			int temp = i;
			while(temp < 63 && get_piece_at_general(temp+1) == UNKNOWN && (temp+1)%8 !=0){
				current->from = i;
				current->to = temp+1;
				current->piece = get_piece_at(i,c);
				current->next_move  = (Move*)malloc(sizeof(Move));
				current = current->next_move;
				temp += 1;
				count++;
			}
			if(temp <= 63 && get_piece_at(temp+1,opp) != UNKNOWN && (temp+1)%8 !=0){
				current->from = i;
				current->to = temp + 1;
				current->piece = get_piece_at(i,c);
				current->next_move  = (Move*)malloc(sizeof(Move));
				current = current->next_move;
				count++;
			}
			temp = i;
			while(temp < 56 && get_piece_at_general(temp +8) == UNKNOWN){
				current->from = i;
				current->to = temp+8;
				current->piece = get_piece_at(i,c);
				current->next_move  = (Move*)malloc(sizeof(Move));
				current = current->next_move;
				temp += 8;
				count++;
			}
			if(temp <= 55 && get_piece_at(temp+8,opp) != UNKNOWN){
				current->from = i;
				current->to = temp + 8;
				current->piece = get_piece_at(i,c);
				current->next_move  = (Move*)malloc(sizeof(Move));
				current = current->next_move;
				count++;
			}
			temp = i;
			while(temp > 7 && get_piece_at_general(temp -8) == UNKNOWN){
				current->from = i;
				current->to = temp-8;
				current->piece = get_piece_at(i,c);
				current->next_move  = (Move*)malloc(sizeof(Move));
				current = current->next_move;
				temp -= 8;
				count++;
			}
			if(temp >= 8 && get_piece_at(temp-8,opp) != UNKNOWN){
				current->from = i;
				current->to = temp -8;
				current->piece = get_piece_at(i,c);
				current->next_move  = (Move*)malloc(sizeof(Move));
				current = current->next_move;
				count++;
			}
			temp = i;
			while(temp > 0 && get_piece_at_general(temp-1) == UNKNOWN && temp%8!=0){
				current->from = i;
				current->to = temp-1;
				current->piece = get_piece_at(i,c);
				current->next_move  = (Move*)malloc(sizeof(Move));
				current = current->next_move;
				temp -= 1;
				count++;
			}
			if(temp >= 1 && get_piece_at(temp-1,opp) != UNKNOWN && (temp)%8 !=0){
				current->from = i;
				current->to = temp -1;
				current->piece = get_piece_at(i,c);
				current->next_move  = (Move*)malloc(sizeof(Move));
				current = current->next_move;
				count++;
			}
		}

		else if(get_piece_at(i,c) == BISHOP){
			int temp = i;
			while(temp < 55 && get_piece_at_general(temp+9) == UNKNOWN && (temp+1)%8!=0){
				current->from = i;
				current->to = temp+9;
				current->piece = get_piece_at(i,c);
				current->next_move  = (Move*)malloc(sizeof(Move));
				current = current->next_move;
				temp += 9;
				count++;
			}
			if(temp <= 54 && get_piece_at(temp+9,opp) != UNKNOWN && (temp+1)%8!=0){
				current->from = i;
				current->to = temp + 9;
				current->piece = get_piece_at(i,c);
				current->next_move  = (Move*)malloc(sizeof(Move));
				current = current->next_move;
				count++;
			}
			temp = i;
			while(temp < 56 && get_piece_at_general(temp+7) == UNKNOWN && (temp%8) != 0){
				current->from = i;
				current->to = temp+7;
				current->piece = get_piece_at(i,c);
				current->next_move  = (Move*)malloc(sizeof(Move));
				current = current->next_move;
				temp += 7;
				count++;
			}
			if(temp <= 55 && get_piece_at(temp+7,opp) != UNKNOWN && temp%8!=0){
				current->from = i;
				current->to = temp + 7;
				current->piece = get_piece_at(i,c);
				current->next_move  = (Move*)malloc(sizeof(Move));
				current = current->next_move;
				count++;
			}
			temp = i;
			while(temp > 8 && get_piece_at_general(temp-9) == UNKNOWN && (temp)%8!=0){
				current->from = i;
				current->to = temp-9;
				current->piece = get_piece_at(i,c);
				current->next_move  = (Move*)malloc(sizeof(Move));
				current = current->next_move;
				temp -= 9;
				count++;
			}
			if(temp >= 9 && get_piece_at(temp-9,opp) != UNKNOWN && temp%8!=0){
				current->from = i;
				current->to = temp - 9;
				current->piece = get_piece_at(i,c);
				current->next_move  = (Move*)malloc(sizeof(Move));
				current = current->next_move;
				count++;
			}
			temp = i;
			while(temp > 7 && get_piece_at_general(temp-7) == UNKNOWN && (temp+1)%8!=0){
				current->from = i;
				current->to = temp-7;
				current->piece = get_piece_at(i,c);
				current->next_move  = (Move*)malloc(sizeof(Move));
				current = current->next_move;
				temp -= 7;
				count++;
			}
			if(temp > 7 && get_piece_at(temp-7,opp) != UNKNOWN && (temp+1)%8!=0){
				current->from = i;
				current->to = temp - 7;
				current->piece = get_piece_at(i,c);
				current->next_move  = (Move*)malloc(sizeof(Move));
				current = current->next_move;
				count++;
			}
		}
		else if(get_piece_at(i,c) == NIGHT){
			if(i % 8 == 0 || (i - 1) % 8 == 0){
				if(i <=7){
					if(get_piece_at(i + 10,c) == UNKNOWN){
						current->from = i;
						current->to = i+10;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
					if(get_piece_at(i+17,c) == UNKNOWN){
						current->from = i;
						current->to = i+17;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
				}else if(i>=8 && i <=15){
					if(get_piece_at(i + 10,c) == UNKNOWN){
						current->from = i;
						current->to = i+10;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
					if(get_piece_at(i+17,c) == UNKNOWN){
						current->from = i;
						current->to = i+17;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
					if(get_piece_at(i-6,c) == UNKNOWN){
						current->from = i;
						current->to = i-6;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}				
				} else if(i >= 56){
					if(get_piece_at(i-6,c) == UNKNOWN){
						current->from = i;
						current->to = i-6;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
					if(get_piece_at(i-15,c) == UNKNOWN){
						current->from = i;
						current->to = i-15;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
				}else if(i<=55 && i>=48){
					if(get_piece_at(i - 15,c) == UNKNOWN){
						current->from = i;
						current->to = i-15;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
					if(get_piece_at(i-6,c) == UNKNOWN){
						current->from = i;
						current->to = i-6;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
					if(get_piece_at(i+10,c) == UNKNOWN){
						current->from = i;
						current->to = i+10;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
				}else if((i-1) % 8 == 0){
					if(get_piece_at(i+10,c) == UNKNOWN){
						current->from = i;
						current->to = i+10;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
					if(get_piece_at(i+17,c) == UNKNOWN){
						current->from = i;
						current->to = i+17;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
					if(get_piece_at(i-6,c) == UNKNOWN){
						current->from = i;
						current->to = i-6;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
					if(get_piece_at(i-15,c) == UNKNOWN){
						current->from = i;
						current->to = i-15;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
					if(get_piece_at(i-17,c) == UNKNOWN){
						current->from = i;
						current->to = i-17;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
					if(get_piece_at(i+15,c) == UNKNOWN){
						current->from = i;
						current->to = i+15;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
				}else{
					if(get_piece_at(i+10,c) == UNKNOWN){
						current->from = i;
						current->to = i+10;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
					if(get_piece_at(i+17,c) == UNKNOWN){
						current->from = i;
						current->to = i+17;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
					if(get_piece_at(i-6,c) == UNKNOWN){
						current->from = i;
						current->to = i-6;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
					if(get_piece_at(i-15,c) == UNKNOWN){
						current->from = i;
						current->to = i-15;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
				}
			} else if((i + 1) % 8 == 0 || (i + 2) % 8 == 0){
				if(i <= 6){
					if(get_piece_at(i+6,c) == UNKNOWN){
						current->from = i;
						current->to = i+6;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
					if(get_piece_at(i+15,c) == UNKNOWN){
						current->from = i;
						current->to = i+15;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
					if(get_piece_at(i+17,c) == UNKNOWN){
						current->from = i;
						current->to = i+17;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
				}else if( i==7){
					if(get_piece_at(i+6,c) == UNKNOWN){
						current->from = i;
						current->to = i+6;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
					if(get_piece_at(i+15,c) == UNKNOWN){
						current->from = i;
						current->to = i+15;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
				}else if(i >=8 && i <=14){
					if(get_piece_at(i + 15,c) == UNKNOWN){
						current->from = i;
						current->to = i+15;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
					if(get_piece_at(i-10,c) == UNKNOWN){
						current->from = i;
						current->to = i-10;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
					if(get_piece_at(i+6,c) == UNKNOWN){
						current->from = i;
						current->to = i+6;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
					if(get_piece_at(i+17,c) == UNKNOWN){
						current->from = i;
						current->to = i+17;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
				}else if(i==15){
					if(get_piece_at(i+6,c) == UNKNOWN){
						current->from = i;
						current->to = i+6;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
					if(get_piece_at(i+15,c) == UNKNOWN){
						current->from = i;
						current->to = i+15;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
					if(get_piece_at(i-10,c) == UNKNOWN){
						current->from = i;
						current->to = i-10;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
				} else if(i == 63){
					if(get_piece_at(i-10,c) == UNKNOWN){
						current->from = i;
						current->to = i-10;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
					if(get_piece_at(i-17,c) == UNKNOWN){
						current->from = i;
						current->to = i-17;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
				}else if(i==62){
					if(get_piece_at(i-10,c) == UNKNOWN){
						current->from = i;
						current->to = i-10;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
					if(get_piece_at(i-17,c) == UNKNOWN){
						current->from = i;
						current->to = i-17;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
					if(get_piece_at(i-15,c) == UNKNOWN){
						current->from = i;
						current->to = i-15;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
				}else if(i==55){
					if(get_piece_at(i - 10,c) == UNKNOWN){
						current->from = i;
						current->to = i-10;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
					if(get_piece_at(i-17,c) == UNKNOWN){
						current->from = i;
						current->to = i-17;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
					if(get_piece_at(i+6,c) == UNKNOWN){
						current->from = i;
						current->to = i+6;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
				}else if(i==54){
					if(get_piece_at(i-10,c) == UNKNOWN){
						current->from = i;
						current->to = i-10;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
					if(get_piece_at(i-17,c) == UNKNOWN){
						current->from = i;
						current->to = i-17;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
					if(get_piece_at(i-15,c) == UNKNOWN){
						current->from = i;
						current->to = i-15;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
					if(get_piece_at(i+6,c) == UNKNOWN){
						current->from = i;
						current->to = i+6;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
				}else if((i+2) % 8 ==0){
					if(get_piece_at(i-10,c) == UNKNOWN){
						current->from = i;
						current->to = i-10;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
					if(get_piece_at(i-17,c) == UNKNOWN){
						current->from = i;
						current->to = i-17;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
					if(get_piece_at(i+6,c) == UNKNOWN){
						current->from = i;
						current->to = i+6;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
					if(get_piece_at(i+15,c) == UNKNOWN){
						current->from = i;
						current->to = i+15;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
					if(get_piece_at(i-15,c) == UNKNOWN){
						current->from = i;
						current->to = i-15;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
					if(get_piece_at(i+17,c) == UNKNOWN){
						current->from = i;
						current->to = i+17;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
				}else{
					if(get_piece_at(i-10,c) == UNKNOWN){
						current->from = i;
						current->to = i-10;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
					if(get_piece_at(i-17,c) == UNKNOWN){
						current->from = i;
						current->to = i-17;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
					if(get_piece_at(i+6,c) == UNKNOWN){
						current->from = i;
						current->to = i+6;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
					if(get_piece_at(i+15,c) == UNKNOWN){
						current->from = i;
						current->to = i+15;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
				}
			}else if(i <= 15){ 
				if(i <=7){
					if(get_piece_at(i+6,c) == UNKNOWN){
						current->from = i;
						current->to = i+6;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
					if(get_piece_at(i+10,c) == UNKNOWN){
						current->from = i;
						current->to = i+10;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
					if(get_piece_at(i+15,c) == UNKNOWN){
						current->from = i;
						current->to = i+15;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
					if(get_piece_at(i+17,c) == UNKNOWN){
						current->from = i;
						current->to = i+17;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
				} else {
					if(get_piece_at(i+6,c) == UNKNOWN){
						current->from = i;
						current->to = i+6;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
					if(get_piece_at(i+10,c) == UNKNOWN){
						current->from = i;
						current->to = i+10;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
					if(get_piece_at(i+15,c) == UNKNOWN){
						current->from = i;
						current->to = i+15;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
					if(get_piece_at(i+17,c) == UNKNOWN){
						current->from = i;
						current->to = i+17;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
					if(get_piece_at(i-6,c) == UNKNOWN){
						current->from = i;
						current->to = i-6;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
					if(get_piece_at(i-10,c) == UNKNOWN){
						current->from = i;
						current->to = i-10;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}	
				}	
			}else if(i >=48){
				if(i >=56){
					if(get_piece_at(i-6,c) == UNKNOWN){
						current->from = i;
						current->to = i-6;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
					if(get_piece_at(i-10,c) == UNKNOWN){
						current->from = i;
						current->to = i-10;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
					if(get_piece_at(i-15,c) == UNKNOWN){
						current->from = i;
						current->to = i-15;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
					if(get_piece_at(i-17,c) == UNKNOWN){
						current->from = i;
						current->to = i-17;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
				} else {
					if(get_piece_at(i-6,c) == UNKNOWN){
						current->from = i;
						current->to = i-6;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
					if(get_piece_at(i-10,c) == UNKNOWN){
						current->from = i;
						current->to = i-10;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
					if(get_piece_at(i-15,c) == UNKNOWN){
						current->from = i;
						current->to = i-15;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
					if(get_piece_at(i+10,c) == UNKNOWN){
						current->from = i;
						current->to = i+10;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}	
				}
			}else {
				if(get_piece_at(i-10,c) == UNKNOWN){
					current->from = i;
					current->to = i-10;
					current->piece = get_piece_at(i,c);
					current->next_move  = (Move*)malloc(sizeof(Move));
					current = current->next_move;
					count++;
				}
				if(get_piece_at(i-17,c) == UNKNOWN){
					current->from = i;
					current->to = i-17;
					current->piece = get_piece_at(i,c);
					current->next_move  = (Move*)malloc(sizeof(Move));
					current = current->next_move;
					count++;
				}
				if(get_piece_at(i+6,c) == UNKNOWN){
					current->from = i;
					current->to = i+6;
					current->piece = get_piece_at(i,c);
					current->next_move  = (Move*)malloc(sizeof(Move));
					current = current->next_move;
					count++;
				}
				if(get_piece_at(i+15,c) == UNKNOWN){
					current->from = i;
					current->to = i+15;
					current->piece = get_piece_at(i,c);
					current->next_move  = (Move*)malloc(sizeof(Move));
					current = current->next_move;
					count++;
				}
				if(get_piece_at(i+10,c) == UNKNOWN){
					current->from = i;
					current->to = i+10;
					current->piece = get_piece_at(i,c);
					current->next_move  = (Move*)malloc(sizeof(Move));
					current = current->next_move;
					count++;
				}
				if(get_piece_at(i+17,c) == UNKNOWN){
					current->from = i;
					current->to = i+17;
					current->piece = get_piece_at(i,c);
					current->next_move  = (Move*)malloc(sizeof(Move));
					current = current->next_move;
					count++;
				}
				if(get_piece_at(i-6,c) == UNKNOWN){
					current->from = i;
					current->to = i-6;
					current->piece = get_piece_at(i,c);
					current->next_move  = (Move*)malloc(sizeof(Move));
					current = current->next_move;
					count++;
				}
				if(get_piece_at(i-15,c) == UNKNOWN){
					current->from = i;
					current->to = i-15;
					current->piece = get_piece_at(i,c);
					current->next_move  = (Move*)malloc(sizeof(Move));
					current = current->next_move;
					count++;
				}
			}
		}
		else if(get_piece_at(i,c) == PAWN){
			if(c == BLACK){
				if(get_piece_at_general(i+8) == UNKNOWN && i <56){
					if(i <=55 && i >=48){
						current->from = i;
						current->to = i+8;
						current->piece = get_piece_at(i,c);
						current->promotion_choice = QUEEN;
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;

						current->from = i;
						current->to = i+8;
						current->piece = get_piece_at(i,c);
						current->promotion_choice = ROOK;
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;

						current->from = i;
						current->to = i+8;
						current->piece = get_piece_at(i,c);
						current->promotion_choice = NIGHT;
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;

						current->from = i;
						current->to = i+8;
						current->piece = get_piece_at(i,c);
						current->promotion_choice = BISHOP;
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					} else {
						current->from = i;
						current->to = i+8;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
				}
				if(i<=15 && i >= 8 && get_piece_at_general(i+16) == UNKNOWN && get_piece_at_general(i+8) == UNKNOWN){
					current->from = i;
					current->to = i+16;
					current->piece = get_piece_at(i,c);
					current->next_move  = (Move*)malloc(sizeof(Move));
					current = current->next_move;
					count++;
				}
				if((get_piece_at(i+7,opp) != UNKNOWN || i+7 == ep_square) && i%8!=0 && i < 56){
					if(i <= 55 && i >= 48){
						current->from = i;
						current->to = i+7;
						current->piece = get_piece_at(i,c);
						current->promotion_choice = QUEEN;
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;

						current->from = i;
						current->to = i+7;
						current->piece = get_piece_at(i,c);
						current->promotion_choice = ROOK;
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;

						current->from = i;
						current->to = i+7;
						current->piece = get_piece_at(i,c);
						current->promotion_choice = NIGHT;
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;

						current->from = i;
						current->to = i+7;
						current->piece = get_piece_at(i,c);
						current->promotion_choice = BISHOP;
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					} else {
						current->from = i;
						current->to = i+7;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
				}
				if((get_piece_at(i+9,opp) != UNKNOWN || i+9 == ep_square) && (i+1) % 8 !=0i && i < 55){
					if(i <=55 && i >=48){
						current->from = i;
						current->to = i+9;
						current->piece = get_piece_at(i,c);
						current->promotion_choice = QUEEN;
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;

						current->from = i;
						current->to = i+9;
						current->piece = get_piece_at(i,c);
						current->promotion_choice = ROOK;
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;

						current->from = i;
						current->to = i+9;
						current->piece = get_piece_at(i,c);
						current->promotion_choice = NIGHT;
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;

						current->from = i;
						current->to = i+9;
						current->piece = get_piece_at(i,c);
						current->promotion_choice = BISHOP;
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					} else {
						current->from = i;
						current->to = i+9;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
				}
			}
			if(c == WHITE){
				if(get_piece_at_general(i-8) == UNKNOWN && i > 7){
					if(i <=15 && i >= 8){
						current->from = i;
						current->to = i-8;
						current->piece = get_piece_at(i,c);
						current->promotion_choice = QUEEN;
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;

						current->from = i;
						current->to = i-8;
						current->piece = get_piece_at(i,c);
						current->promotion_choice = ROOK;
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;

						current->from = i;
						current->to = i-8;
						current->piece = get_piece_at(i,c);
						current->promotion_choice = NIGHT;
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;

						current->from = i;
						current->to = i-8;
						current->piece = get_piece_at(i,c);
						current->promotion_choice = BISHOP;
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					} else {
						current->from = i;
						current->to = i-8;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
				}
				if(i<=55 && i >= 48 && get_piece_at_general(i-8) == UNKNOWN && get_piece_at_general(i-16) == UNKNOWN){
					current->from = i;
					current->to = i-16;
					current->piece = get_piece_at(i,c);
					current->next_move  = (Move*)malloc(sizeof(Move));
					current = current->next_move;
					count++;
				}
				if((get_piece_at(i-7,opp) != UNKNOWN || i-7 == ep_square) && (i+1) % 8 != 0 && i > 7){
					if(i <=15 && i >=8){
						current->from = i;
						current->to = i-7;
						current->piece = get_piece_at(i,c);
						current->promotion_choice = QUEEN;
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;

						current->from = i;
						current->to = i-7;
						current->piece = get_piece_at(i,c);
						current->promotion_choice = ROOK;
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;

						current->from = i;
						current->to = i-7;
						current->piece = get_piece_at(i,c);
						current->promotion_choice = NIGHT;
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;

						current->from = i;
						current->to = i-7;
						current->piece = get_piece_at(i,c);
						current->promotion_choice = BISHOP;
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					} else {
						current->from = i;
						current->to = i-7;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
				}
				if((get_piece_at(i-9,opp) != UNKNOWN || i-9 == ep_square) && (i) % 8 != 0 && i > 8){
					if(i <=15 && i >=8){
						current->from = i;
						current->to = i-9;
						current->piece = get_piece_at(i,c);
						current->promotion_choice = QUEEN;
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;

						current->from = i;
						current->to = i-9;
						current->piece = get_piece_at(i,c);
						current->promotion_choice = ROOK;
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;

						current->from = i;
						current->to = i-9;
						current->piece = get_piece_at(i,c);
						current->promotion_choice = NIGHT;
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;

						current->from = i;
						current->to = i-9;
						current->piece = get_piece_at(i,c);
						current->promotion_choice = BISHOP;
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					} else {
						current->from = i;
						current->to = i-9;
						current->piece = get_piece_at(i,c);
						current->next_move  = (Move*)malloc(sizeof(Move));
						current = current->next_move;
						count++;
					}
				}
			}
		}
		else if(get_piece_at(i,c) == KING){
			if(get_piece_at(i+8,c) == UNKNOWN && i < 56){
				current->from = i;
				current->to = i+8;
				current->piece = get_piece_at(i,c);
				current->next_move  = (Move*)malloc(sizeof(Move));
				current = current->next_move;
				count++;
			}
			if(get_piece_at(i+9,c) == UNKNOWN && (i+1)%8!= 0 && i <55){
				current->from = i;
				current->to = i+9;
				current->piece = get_piece_at(i,c);
				current->next_move  = (Move*)malloc(sizeof(Move));
				current = current->next_move;
				count++;
			}
			if(get_piece_at(i+7,c) == UNKNOWN && i% 8 != 0 && i < 56){
				current->from = i;
				current->to = i+7;
				current->piece = get_piece_at(i,c);
				current->next_move  = (Move*)malloc(sizeof(Move));
				current = current->next_move;
				count++;
			}
			if(get_piece_at(i+1,c) == UNKNOWN && (i+1) %8 != 0){
				current->from = i;
				current->to = i+1;
				current->piece = get_piece_at(i,c);
				current->next_move  = (Move*)malloc(sizeof(Move));
				current = current->next_move;
				count++;
			}
			if(get_piece_at(i-8,c) == UNKNOWN && i > 7){
				current->from = i;
				current->to = i-8;
				current->piece = get_piece_at(i,c);
				current->next_move  = (Move*)malloc(sizeof(Move));
				current = current->next_move;
				count++;
			}
			if(get_piece_at(i-9,c) == UNKNOWN && i %8 != 0 && i > 8){
				current->from = i;
				current->to = i-9;
				current->piece = get_piece_at(i,c);
				current->next_move  = (Move*)malloc(sizeof(Move));
				current = current->next_move;
				count++;
			}
			if(get_piece_at(i-1,c) == UNKNOWN && i %8 !=0){
				current->from = i;
				current->to = i-1;
				current->piece = get_piece_at(i,c);
				current->next_move  = (Move*)malloc(sizeof(Move));
				current = current->next_move;
				count++;
			}
			if(get_piece_at(i-7,c) == UNKNOWN && (i+1)%8 !=0 && i >7){
				current->from = i;
				current->to = i-7;
				current->piece = get_piece_at(i,c);
				current->next_move  = (Move*)malloc(sizeof(Move));
				current = current->next_move;
				count++;
			}
			if((c == WHITE && i > 55) || (c==BLACK && i < 8)){
				if(get_piece_at(i-4,c) == ROOK && get_piece_at_general(i-3)==UNKNOWN && get_piece_at_general(i-2) == UNKNOWN && get_piece_at_general(i-1) == UNKNOWN){
					current->from = i;
					current->to = i-2;
					current->piece = get_piece_at(i,c);
					current->next_move  = (Move*)malloc(sizeof(Move));
					current = current->next_move;
					count++;
				}
				if(get_piece_at(i+3,c) == ROOK && get_piece_at_general(i+2)==UNKNOWN && get_piece_at_general(i+1) == UNKNOWN){
					current->from = i;
					current->to = i+2;
					current->piece = get_piece_at(i,c);
					current->next_move  = (Move*)malloc(sizeof(Move));
					current = current->next_move;
					count++;
				}
			}
		}
	}
	free(current);
	current = NULL;
	*pcount = count;
	if(pcount==0) return FALSE;
	return TRUE;
}

/* Returns TRUE if the CurrentPlayer is under checkmate, FALSE otherwise. */
/* Notes:
Loop through all legal moves, if all of these posible moves are in check, return TRUE, else FALSE */
/*Nick*/
Bool is_checkmate() {
	PlayerColor enemy;
	if(CurrentPlayer == WHITE) enemy = BLACK;
	else enemy = WHITE;
	unsigned int  nums;
	Move *enter;
	/*Move *p = *enter;*/
	/*enter->from = i;*/
	/*enter->piece = get_piece_at(i, enemy);*/
	/* run each move under check, if any are FALSE, return FALSE. Else return TRUE */
	legal_moves(&enter, enemy, &nums);
	/* need to fix or confirm 3rd line down */
	Pos j;
	char* msg;
	PlayerState copy1[2];
	copy1[0] = player[0];
	copy1[1] = player[1];
	Pos epcopy = ep_square;
	Move *temp;
	int w;
	for(j = 0; j < nums; j++){
		/* setup variable t for message */
		if(validate_and_move(enter, &msg, enemy, &ep_square) == TRUE){/*enter->piece == KING*/
			for(w = j; w < nums-1; w++)
			{
				temp = enter;
				enter = enter->next_move;
				free(temp);
			}
			free(enter);
			return FALSE;
		}
		if(j < nums-1){
			temp = enter;
			enter = enter->next_move;
			free(temp);
		}
		player[0] = copy1[0];
		player[1] = copy1[1];
		ep_square = epcopy;
	}
	free(enter);
	return TRUE;
}

/* Validate a move and make it. Returns TRUE if successful, FALSE if not.
*  Error message if any, are stored in *msg.
* ep_square (if any) is stored in *ep_sq
*/
Bool validate_and_move(Move *move, char **msg, PlayerColor c, Pos *ep_sq) {/*Kieran Will work on this*/
	/*char *retMessage = (char*)malloc(20*sizeof(char));*/
	/**msg = retMessage;*/
	/*Move* legal;*/
	/*Pos count = 0*/
	PlayerColor opp;
	Piece prom = move->promotion_choice;
	if(c == BLACK)opp = WHITE;
	if(c == WHITE) opp = BLACK;
	Piece type = move->piece;
	Bool doubleM = FALSE;
	if(move->piece == PAWN && (move->to == move->from+16 || move->to == move->from-16)){
		doubleM = TRUE;
	}
	Bool allowed = TRUE;
	/*Pos kingThreat = move->to;*/
	/*Bool stay = legal_moves(&legal, c, &count);*/
	/*Move* current = legal;*/
	/*if(stay == FALSE){
		*msg = "No legal moves.";
		ep_square = -1;
		return FALSE;
	}*/
	/*int i;*/
	int k;
	Pos w;
	for(w = 0; w <= 63; w++){
		if(get_piece_at(w, c) == KING){
			k = w;
			break;
		}
	}
	PlayerState co[2];
	co[0] = player[0];
	co[1] = player[1];
	Pos epcopy = ep_square;
	player[c].castle_flags = detect_castle_move(*move,c);
	if(player[c].castle_flags == CASTLE_KING){
		perform_castle(get_piece_at(k-4,c),c);
		ep_square = -1;
		return TRUE;
	} else if(player[c].castle_flags == CASTLE_QUEEN){
	perform_castle(get_piece_at(k+3,c),c);
		ep_square = -1;	
		return TRUE;
	}
	/*Move *temp;
	int loop;
	for(loop = 0; loop < count; loop++)
	{
		if(loop < count-1)
		{
			temp = legal;
			legal = legal->next_move;
			free(temp);
		}
	}
	free(legal);*/
	if(allowed == TRUE){
		if(type == KING){
			SET_BIT(player[c].k,move->to);
			RESET_BIT(player[c].k,move->from);
		}
		if(type == QUEEN){
			SET_BIT(player[c].q,move->to);
			RESET_BIT(player[c].q,move->from);
		}
		if(type == ROOK){
			SET_BIT(player[c].r,move->to);
			RESET_BIT(player[c].r,move->from);
		}
		if(type == PAWN){
			SET_BIT(player[c].p,move->to);
			if(ep_square == move->to){
				if(c == BLACK){
					RESET_BIT(player[opp].p,move->from+8);
				} else {
					RESET_BIT(player[opp].p,move->from-8);
				}
			}
			if(prom == QUEEN){
				RESET_BIT(player[c].p,move->to);
				SET_BIT(player[c].q,move->to);
			} else if(prom == BISHOP){
				RESET_BIT(player[c].p,move->to);
				SET_BIT(player[c].b,move->to);
			} else if(prom == NIGHT){
				RESET_BIT(player[c].p,move->to);
				SET_BIT(player[c].n,move->to);
			} else if(prom == ROOK){
				RESET_BIT(player[c].p,move->to);
				SET_BIT(player[c].r,move->to);
			}
			RESET_BIT(player[c].p,move->from);	
		}
		if(type == BISHOP){
			SET_BIT(player[c].b,move->to);
			RESET_BIT(player[c].b,move->from);
		}
		if(type == NIGHT){
			SET_BIT(player[c].n,move->to);
			RESET_BIT(player[c].n,move->from);
		}
		if(doubleM == FALSE){
			RESET_BIT(player[opp].b,move->to);
			RESET_BIT(player[opp].q,move->to);
			RESET_BIT(player[opp].r,move->to);
			RESET_BIT(player[opp].n,move->to);
			RESET_BIT(player[opp].p,move->to);
		}
		ep_square = -1;
		for(w = 0; w <= 63; w++){
			if(get_piece_at(w, c) == KING){
				k = w;
				break;
			}
		}
		if(is_check(k, c) == TRUE){
			player[0] = co[0];
			player[1] = co[1];
			ep_square = epcopy;
			*msg = "is still in check";
			return FALSE;
		}
		return TRUE;
	}
	*msg = "Illegal Move";
	ep_square = -1;
	return FALSE;
}

/* Function to decide whether the current position is a draw */
/* Draw can be due to insufficient material, 3 move repetition or stalemate */
/* 3 move repetition also covers perpetual check */
/*Nick*/
Bool is_draw() {
	/* stalemate */
	Pos i;
	/*Bool exist = FALSE;
	for(i = 0; i <= 63; i++){
		if(get_piece_at(i, CurrentPlayer) != UNKNOWN){
			Move *enter = (Move*)malloc(sizeof(Move));
			Pos num = 0;
			if(legal_moves(&enter, CurrentPlayer, &num) == TRUE){
				exist = TRUE;
			}
		}
	}
	if(exist == FALSE) return TRUE;
	return FALSE;*/	
	int k;
	int w;
	PlayerColor opp = BLACK;
	if(CurrentPlayer == BLACK) opp = WHITE;
	for(w = 0; w <= 63; w++){
		if(get_piece_at(w, opp) == KING){
			k = w;
			break;
		}
	}
	if(is_check(k,opp) == TRUE) return FALSE;
	PlayerState co[2];
	co[0] = player[0];
	co[1] = player[1];
	Pos ep_copy = ep_square;
	Move* enter;
	Pos num = 0;
	legal_moves(&enter,opp,&num);
	/*Move* cpy = enter;*/
	char* msg;
	Move *temp;
	for(i = 0; i < num; i++){
		if(validate_and_move(enter,&msg,opp,&ep_copy) == TRUE){
			player[0] = co[0];
			player[1] = co[1];
			ep_square = ep_copy;
			for(w = i; w < num-1; w++)
			{
				temp = enter;
				enter = enter->next_move;
				free(temp);
			}
			free(enter);
			return FALSE;
		}
		if(i < num -1){
			temp = enter;
			enter = enter->next_move;
			free(temp);
		}
		player[0] = co[0];
		player[1] = co[0];
	}
	free(enter);
	return TRUE;
	/* end stalemate check, now repetition 3 detect*/
		/* fill */
	/* not repition 3, or stalemate. Thus return false */
}

/* Returns the piece on a square belonging to player color c.
* If there is no piece with color c, UNKNOWN is returned. */
/*Nick*/
Piece get_piece_at(Board pos, PlayerColor c) {
	if(IS_SET(player[c].k, pos)) return KING;
	if(IS_SET(player[c].q, pos)) return QUEEN;
	if(IS_SET(player[c].b, pos)) return BISHOP;
	if(IS_SET(player[c].n, pos)) return NIGHT;
	if(IS_SET(player[c].r, pos)) return ROOK;
	if(IS_SET(player[c].p, pos)) return PAWN;
	return UNKNOWN;
}

/* Check if this move is trying to castle*/
/*
1. If King is not preforming a legal move, return 0 (NO_CASTLE)
2. If either King or ROOK in question had moved, return 0 (NO_CASTLE)
3. If there are any piece between king and ROOK in question, return 0 (NO_CASTLE)
4. If King is currently is in or will be in check, return 0 (NO_CASTLE)
5. Since 1, 2, 3, and 4 did not return 0, and if king is moving right (from higher pos compared to original) return 1 (CASTLE_KING)
6. Since 1, 2, 3, 4, and 5 did not return anything, king is moving left so return 2 (QUEEN_CASTLE)
*/
/*Nick*/
Pos detect_castle_move(Move move, PlayerColor c) {
	/*Pos var = 0;*/
	/*Move *enter;*/
	/*Move *p = *enter;*/
	Pos from = move.from;
	/* Wasnt moving a King */
	if(get_piece_at(from, c) != KING){
		return NO_CASTLE;
	}
	/* The move was not legal */
	/*if(legal_moves(&enter, c, &var) == FALSE){
		Move *temp;
		int loop;
		for(loop = 0; loop < var; loop++)
		{
			if(loop < var-1)
			{
				temp = enter;
				enter = enter->next_move;
				free(temp);
			}
		}
		free(temp);
		return NO_CASTLE;
	}
	Move *temp;
	int loop;
	for(loop = 0; loop < var; loop++)
	{
		if(loop < var-1)
		{
			temp = enter;
			enter = enter->next_move;
			free(temp);
		}
	}*/
	/* If player is color white */
	if(c == WHITE){
		if(player[c].k == 60 && player[c].r == 63){
			Bool is_empty;
			if(get_piece_at_general(61) == UNKNOWN && get_piece_at_general(62) == UNKNOWN)
			is_empty = TRUE;
			else
			is_empty = FALSE;

			if(is_empty == TRUE && move.to == 62)
			return CASTLE_KING;
		}
		if(player[c].k == 60 && player[c].r == 56){
			Bool is_empty;
			if(get_piece_at_general(59) == UNKNOWN && get_piece_at_general(58) == UNKNOWN && get_piece_at_general(57) == UNKNOWN)
			is_empty = TRUE;
			else
			is_empty = FALSE;

			if(is_empty == TRUE && move.to == 57)
			return CASTLE_QUEEN;
		}
		return NO_CASTLE;
	}
	else{
		if(player[c].k == 4 && player[c].r == 7){
			Bool is_empty;
			if(get_piece_at_general(5) == UNKNOWN && get_piece_at_general(6) == UNKNOWN)
			is_empty = TRUE;
			else
			is_empty = FALSE;

			if(is_empty == TRUE && move.to == 6)
			return CASTLE_KING;
		}
		if(player[c].k == 4 && player[c].r == 0){
			Bool is_empty;
			if(get_piece_at_general(3) == UNKNOWN && get_piece_at_general(2) == UNKNOWN && get_piece_at_general(1) == UNKNOWN)
			is_empty = TRUE;
			else
			is_empty = FALSE;

			if(is_empty == TRUE && move.to == 1)
			return CASTLE_QUEEN;
		}
		return NO_CASTLE;
	}
}

/* Perform castling. Moves king and rook and resets castle flags */
void perform_castle(unsigned int castle, PlayerColor c) {/*Kieran will work on this*/
    int king = player[c].k;
    if(player[c].castle_flags == CASTLE_KING){
    	SET_BIT(player[c].k,castle+1);
    	SET_BIT(player[c].r,king-1);
    	RESET_BIT(player[c].r,castle);
    	RESET_BIT(player[c].k,king);
    }
    if(player[c].castle_flags == CASTLE_QUEEN){
   	SET_BIT(player[c].k,castle-2);
    	SET_BIT(player[c].r,king+3);
    	RESET_BIT(player[c].r,castle);
    	RESET_BIT(player[c].k,king);
    }
}

/*Notes:*/
/* 1. Check around the king, if there is a enemy king next to current king, return TRUE*/
/* 2. Check cross section (+) of king, if there is either a enemy ROOK or a QUEEN (and nothing in their way between them and the king) return TRUE*/
/* 3. Check diagonal section (X) of king, if there is a BISHOP (and nothing in their way between them and the king) return TRUE*/
/* 4. Check bottom diagonal of king, if there is a PAWN next to current king, return TRUE */
/* 5. Check 4 L positions of king, if there is a KNIGHT, return TRUE.
If none of these, return FALSE. */
/*Nick*/
Bool is_check(unsigned int i, PlayerColor c){
	/*Set PlayerColor enemy*/
	PlayerColor enemy;
	if(c == WHITE) enemy = BLACK;
	else enemy = WHITE;

	unsigned int j; /* defined these up here to fix errors */


	/*(#1) if there is a enemy king anywhere around current king, return TRUE*/
	if((get_piece_at(NORTH_OF(i), enemy) == KING && i >7) || (get_piece_at(EAST_OF(i), enemy) == KING && (i+1)%8!=0)
	|| (get_piece_at(SOUTH_OF(i), enemy) == KING && i < 56)|| (get_piece_at(WEST_OF(i), enemy) == KING && i%8!=0)
	|| (get_piece_at(NE_OF(i), enemy) == KING && (i+1) % 8 != 0 && i >7)|| (get_piece_at(SE_OF(i), enemy) == KING && (i+1) % 8 != 0 && i <56)
	|| (get_piece_at(NW_OF(i), enemy) == KING && (i) % 8 != 0 && i >7)|| (get_piece_at(SW_OF(i), enemy) == KING && (i) % 8 != 0 && i <56)) 
	return TRUE;
	/* end of (#1) */

	/* (#4) If enemy pawn and if its diagonal is legal return TRUE */
	/*enemy is black*/
	if(enemy == BLACK){
		Pos NorthWest = NW_OF(i);
		if(get_piece_at(NorthWest, enemy) == PAWN)
		return TRUE;
		Pos NorthEast = NE_OF(i);
		if(get_piece_at(NorthEast, enemy) == PAWN)
		return TRUE;
	}
	/*enemy is white*/
	else{
		Pos SouthWest = SW_OF(i);
		if(get_piece_at(SouthWest, enemy) == PAWN)
		return TRUE;
		Pos SouthEast = SE_OF(i);
		if(get_piece_at(SouthEast, enemy) == PAWN)
		return TRUE;
	}
	/* End of (#4) */

	Bool pitw = FALSE;
	/*(#2) Everything north*/
	for(j = NORTH_OF(i); j != UNKNOWN_POS; j = NORTH_OF(j)){
		 /*piece in the way*/
		if(get_piece_at(j, enemy) == QUEEN || get_piece_at(j, enemy) == ROOK){
			if(pitw == FALSE) return TRUE;
		}
		if(get_piece_at_general(j) != UNKNOWN) pitw = TRUE;
	}
	/*Everything south*/
	pitw = FALSE;
	for(j = SOUTH_OF(i); j != UNKNOWN_POS; j = SOUTH_OF(j)){
		if(get_piece_at(j, enemy) == QUEEN || get_piece_at(j, enemy) == ROOK){
			if(pitw == FALSE) return TRUE;
		}
		if(get_piece_at_general(j) != UNKNOWN) pitw = TRUE;
	}
	/*Everything West*/
	pitw = FALSE;
	for(j = WEST_OF(i); j != UNKNOWN_POS; j = WEST_OF(j)){
		if(get_piece_at(j, enemy) == QUEEN || get_piece_at(j, enemy) == ROOK){
			if(pitw == FALSE) return TRUE;
		}
		if(get_piece_at_general(j) != UNKNOWN) pitw = TRUE;
	}
	/*Everything East*/
	pitw = FALSE;
	for(j = EAST_OF(i); j != UNKNOWN_POS; j = EAST_OF(j)){
		if(get_piece_at(j, enemy) == QUEEN || get_piece_at(j, enemy) == ROOK){
			if(pitw == FALSE) return TRUE;
		}
		if(get_piece_at_general(j) != UNKNOWN) pitw = TRUE;
	}
	/*End of (#2)*/

	/*(#3) Everything north east*/
	pitw = FALSE;
	for(j = NE_OF(i); j != UNKNOWN_POS; j = NE_OF(j)){
		if(get_piece_at(j, enemy) == BISHOP || get_piece_at(j, enemy) == QUEEN){
			if(pitw == FALSE) return TRUE;
		}
		if(get_piece_at_general(j) != UNKNOWN) pitw = TRUE;
	}
	/*Everything south East*/
	pitw = FALSE;
	for(j = SE_OF(i); j != UNKNOWN_POS; j = SE_OF(j)){
		if(get_piece_at(j, enemy) == BISHOP || get_piece_at(j, enemy) == QUEEN){
			if(pitw == FALSE) return TRUE;
		}
		if(get_piece_at_general(j) != UNKNOWN) pitw = TRUE;
	}
	/*Everything North West*/
	pitw = FALSE;
	for(j = NW_OF(i); j != UNKNOWN_POS; j = NW_OF(j)){
		if(get_piece_at(j, enemy) == BISHOP || get_piece_at(j, enemy) == QUEEN){
			if(pitw == FALSE) return TRUE;
		}
		if(get_piece_at_general(j) != UNKNOWN) pitw = TRUE;
	}
	/*Everything south west*/
	pitw = FALSE;
	for(j = SW_OF(i); j != UNKNOWN_POS; j = SW_OF(j)){
		if(get_piece_at(j, enemy) == BISHOP || get_piece_at(j, enemy) == QUEEN){
			if(pitw == FALSE) return TRUE;
		}
		if(get_piece_at_general(j) != UNKNOWN) pitw = TRUE;
	}
	/*end of (#3)*/

	/*(#5, moving clockwise) Check L*/
	Pos l = SOUTH_OF(SE_OF(i));
	if(l != UNKNOWN_POS){
		if(get_piece_at(l, enemy) == NIGHT)
		return TRUE;
	}
	l = SOUTH_OF(SW_OF(i));
	if(l != UNKNOWN_POS){
		if(get_piece_at(l, enemy) == NIGHT)
		return TRUE;
	}
	l = WEST_OF(SW_OF(i));
	if(l != UNKNOWN_POS){
		if(get_piece_at(l, enemy) == NIGHT)
		return TRUE;
	}
	l = WEST_OF(NW_OF(i));
	if(l != UNKNOWN_POS){
		if(get_piece_at(l, enemy) == NIGHT)
		return TRUE;
	}
	l = NORTH_OF(NW_OF(i));
	if(l != UNKNOWN_POS){
		if(get_piece_at(l, enemy) == NIGHT)
		return TRUE;
	}
	l = NORTH_OF(NE_OF(i));
	if(l != UNKNOWN_POS){
		if(get_piece_at(l, enemy) == NIGHT)
		return TRUE;
	}
	l = EAST_OF(NE_OF(i));
	if(l != UNKNOWN_POS){
		if(get_piece_at(l, enemy) == NIGHT)
		return TRUE;
	}
	l = EAST_OF(SE_OF(i));
	if(l != UNKNOWN_POS){
		if(get_piece_at(l, enemy) == NIGHT)
		return TRUE;
	}
	/*end of (#5)*/

	return FALSE;
}
