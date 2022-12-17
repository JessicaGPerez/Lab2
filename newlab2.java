// Java program to implement
// the above approach
import java.awt.*;
import java.io.*;
import java.util.*;
import java.io.File;
import java.util.Scanner;

public class newlab2{
    private static final int row = 9;
    private static final int col = 9;

    private static void readFile() throws FileNotFoundException {
        int[][] numArr = new int[row][col];
        Scanner sc = new Scanner(textFile());
        while (sc.hasNextLine()) {
            for (int i = 0; i < numArr.length; i++) {
                String[] line = sc.nextLine().trim().split("," + " ");
                for (int j = 0; j < line.length; j++) {
                    numArr[i][j] = Integer.parseInt(line[j]);
                }
            }
        }
        System.out.println(Arrays.deepToString(numArr));
    }
    private static File textFile(){
        FileDialog dialog = new FileDialog((Frame) null, "Chose text file");
        dialog.setMode(FileDialog.LOAD);
        dialog.setVisible(true);
        File[] file = dialog.getFiles();
        return file [0];


    }


    static int N = 9;


    static boolean isSize(int[][] board)
    {

        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                if (board[i][j] <= 0 ||
                        board[i][j] > 9)
                {
                    return false;
                }
            }
        }
        return true;
    }

    static boolean isBoardValid(int board[][])
    {

        if (isSize(board) == false)
        {
            return false;
        }

        boolean[] k = new boolean[N + 1];

        for(int i = 0; i < N; i++)
        {
            Arrays.fill(k, false);


            for(int j = 0; j < N; j++)
            {

                int Z = board[i][j];


                if (k[Z])
                {
                    return false;
                }
                k[Z] = true;
            }
        }
        for(int i = 0; i < N; i++)
        {

            Arrays.fill(k, false);

            for(int j = 0; j < N; j++)
            {

                int Z = board[j][i];

                if (k[Z])
                {
                    return false;
                }
                k[Z] = true;
            }
        }

        for(int i = 0; i < N - 2; i += 3)
        {

            for(int j = 0; j < N - 2; j += 3)
            {

                Arrays.fill(k, false);

                for(int m = 0; m < 3; m++)
                {
                    for(int l = 0; l < 3; l++)
                    {

                        int X = i + m;

                        int Y = j + l;

                        int Z = board[X][Y];

                        if (k[Z])
                        {
                            return false;
                        }
                        k[Z] = true;
                    }
                }
            }
        }
        return true;
    }


    public static void main(String[] args) throws FileNotFoundException
    {
        readFile();

        int [][] board3 = readFile();

        int[][] board1 = { { 0, 9, 2, 9, 5, 4, 3, 8, 6 },
                { 9, 4, 3, 8, 2, 7, 1, 5, 9 },
                { 8, 5, 1, 3, 9, 6, 7, 2, 4 },
                { 2, 6, 5, 9, 7, 3, 8, 4, 1 },
                { 9, 8, 9, 5, 6, 1, 2, 7, 3 },
                { 3, 1, 7, 4, 8, 2, 9, 6, 5 },
                { 1, 3, 6, 7, 4, 8, 5, 9, 2 },
                { 9, 7, 4, 2, 1, 5, 6, 3, 8 },
                { 5, 2, 8, 6, 3, 9, 4, 1, 7 } };
        int[][] board2 = { { 7, 9, 2, 1, 5, 4, 3, 8, 6 },
                { 6, 4, 3, 8, 2, 7, 1, 5, 9 },
                { 8, 5, 1, 3, 9, 6, 7, 2, 4 },
                { 2, 6, 5, 9, 7, 3, 8, 4, 1 },
                { 4, 8, 9, 5, 6, 1, 2, 7, 3 },
                { 3, 1, 7, 4, 8, 2, 9, 6, 5 },
                { 1, 3, 6, 7, 4, 8, 5, 9, 2 },
                { 9, 7, 4, 2, 1, 5, 6, 3, 8 },
                { 5, 2, 8, 6, 3, 9, 4, 1, 7 } };


        if (isBoardValid(board1))
        {
            System.out.println("Valid");
        }
        else
        {
            System.out.println("Not Valid");
        }

        if (isBoardValid(board2))
        {
            System.out.println("Valid");
        }
        else
        {
            System.out.println("Not Valid");
        }

        if (isBoardValid(board3))
        {
            System.out.println("Valid");
        }
        else
        {
            System.out.println("Not Valid");
        }
    }
}





