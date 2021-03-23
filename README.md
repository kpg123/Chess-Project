# Chess-Project
Contributors-Kieran Gaffney, Andrew Horihan, Nick Grosso

This project takes chess boards and analyzes mate in 1 and mate in 2 solutions

Format: ./chess [input file] [output file] [mode]
modes: 1 - Evaluates Mate in 1 Solutions
       2 - Evaluates Mate in 2 Solutions
       
Input File Format: [rank1]/[rank2]/[rank3]/[rank4]/[rank5]/[rank6]/[rank7]/[rank8] [color to move] - -

Input File Key:    rank = string of 0-8 numbers or letter representing pieces. (ex. b6r is a balck bishop, six empty spaces, and a black rook).    
                   color to move = w or b - white or black respectively    
                   numbers = amount of blanks     
                   Uppercase = White Piece     
                   Lowercase = Black Piece    
                   k/K = king    
                   b/B = bishop    
                   r/R = rook    
                   n/N = knight    
                   p/P = pawn    
