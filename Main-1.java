/*
Akulkumar Patel
CS 280, 450
NJIT-ID: 31504835
*/

import java.util.*;

public class Main
{
    private static final int N = 8;
    private int tour[][];
    
    public Main()
    {
        tour = new int[N][N];
    }

    private boolean movePossible(int x, int y)
    {
        if (x >= 0 && x < N && y >= 0 && y < N && tour[x][y] == 0)
            return true;
        return false;
    }

    private void printKT()
    {
        for (int x = 0; x < N; x++)
        {
            for (int y = 0; y < N; y++)
            {
                System.out.printf("%3d", tour[x][y] +1);
            }
            System.out.println();
        }
    }   

    private boolean findTour(int x, int y, int move_count, int xMove[],int yMove[])
    {
        int i, next_x, next_y;
        if (move_count == N * N)
        return true;

        for (i = 0; i < N; i++)
        {
            next_x = x + xMove[i];
            next_y = y + yMove[i];
            if (movePossible(next_x, next_y))
            {
                tour[next_x][next_y] = move_count;
                if (findTour(next_x, next_y, move_count + 1, xMove, yMove))
                    return true;
                else
                    tour[next_x][next_y] = 0;
            }
        }
        return false;
    }

    public boolean knightTours()
    {
        for (int x = 0; x < N; x++)
        {
            for (int y = 0; y < N; y++)
            {
                tour[x][y] = 0;
            }
        }
        int xMove[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
        int yMove[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
        tour[0][0] = 0;
        if (!findTour(0, 0, 1, xMove, yMove))
        {
            System.out.println("Knights tour does not exist");
            return false;
        }
        else
        {
            printKT();
            return true;
        }
        
    }

    public static void main(String[] arg)
    {
        Main kT = new Main();
        System.out.println("Knights Tour exists...");
        kT.knightTours();
    }
}