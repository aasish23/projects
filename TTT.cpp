#import <iostream>

     char board [3][3] ={ {'.', '.','.'},
                                         {'.', '.','.'},
                                         {'.', '.','.'}
                                 };
   bool isPossible(int row, int col);
   bool checkWin();
    void print();
    bool emptySpot();
    
    int main(){
        int player = 1;
         print();
        while(true){
            int row, col;
           std::cout<< "enter col: ";
            std::cin>> col; 
            std::cout<< "enter row: ";
            std::cin>> row;
            row--; 
            col--;

            if(isPossible(row,col)){
                if(player%2== 1){ 
                    board[row][col] = 'x';
                    player++;
            }
                else if(player%2==0){
                 board[row][col] = 'o';
                 player++;
                }
                } else std::cout<<"not possible" << std::endl;
               if(checkWin()){
                   break;
               }
               else if(!emptySpot()){
                   std::cout<<"game over!";
                   return 0;
               }
              print();
           }
          print();
          std::cout<<"game over!";
        return 0;
    }

    bool isPossible(int row, int col){
        if(board[row][col] == 'x' || board[row][col] == 'o'){
            return false;
        }//check empty spot for input
        return true;
    }
    
    bool emptySpot(){//check if there are any empty spots left in the board
        for(int i=0; i<3; i++){ 
            for(int j=0; j<3; j++){
                if(board[i][j] != '.') return true;
            }
        }
        return false;
    }

    bool checkWin(){
        for(int i=0; i<3; i++){
             if((board[i][0] == 'x' && board[i][1] == 'x' && board[i][2] == 'x')||( board[i][0] == 'o' &&  board[i][1] == 'o' &&  board[i][2] == 'o' )) return true; //X-axis check

             if((board[0][i] == 'x' && board[1][i] == 'x' && board[2][i] == 'x')||( board[0][i] == 'o' &&  board[1][i] == 'o' &&  board[2][i] == 'o' )) return true; //Y-axis check
        }
        if((board[0][0] == 'x' && board[1][1] == 'x' && board[2][2] == 'x') ||(board[0][0] == 'o' && board[1][1]=='o' && board[2][2] == 'o' )) return true; //diagonal check
     
        return false;
    }


    void print(){
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                std::cout<< board[i][j] << " ";
            }
            std::cout<<std::endl;
        }
    }
