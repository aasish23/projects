class solution {
    public static int[][] board =  {{0,0,0,0,0,0,0,0,0},
                                    {0,0,0,0,0,0,0,0,0},
                                    {0,0,0,0,0,0,0,0,0},
                                    {0,0,0,0,0,0,0,0,0},
                                    {0,0,0,0,0,0,0,0,0},
                                    {0,0,0,0,0,8,0,0,0},
                                    {0,0,0,0,0,0,0,0,0},
                                    {0,0,0,0,0,0,0,0,0},
                                    {0,0,0,0,0,0,0,0,0}};

    public static void main(String[] args){

        solver();
    }

    public static boolean check(int row, int col, int input){
        for(int i=0; i<board.length; i++){//col check
            if(board[row][i] == input) return false;
        }

        for(int i=0; i<board[0].length; i++){ //row check
            if(board[i][col] == input) return false;
        }

        int rowPointer = (row/(board.length/3))*(3);
        int colPointer = (col/(board[0].length/3))*3;

        for(int i=0; i<3; i++){//check square
            for(int j=0; j<3; j++){
                if(board[rowPointer+i][colPointer+j] == input) return false;
            }
        }
        return true;
    }

    public static void solver(){
        for(int i=0; i<board.length; i++) {
            for (int j = 0; j <board[0].length; j++) {
                if (board[i][j] == 0) {
                    for (int k = 1; k < 10; k++) {
                        if (check(i, j, k)) {
                            board[i][j] = k;
                            solver();
                           backtrack(i, j);
                        }
                    }
                    return;
                }
            }
        }
        print(board);
    }
    public static void backtrack(int row, int col){
        board[row][col] = 0;
    }
    public static void print(int[][] board){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                System.out.print(board[i][j]+ " ");
            }
            System.out.println();
             
        }
        System.out.println();
    }

}