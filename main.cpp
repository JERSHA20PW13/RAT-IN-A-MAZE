/* C program to solve Rat in a Maze problem using backtracking */

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <SDL2/SDL.h>
#define N 6

static const int width=600,height=600;

int sol[N][N] = { { 0, 0, 0, 0, 0, 0},
                  { 0, 0, 0, 0, 0, 0},
                  { 0, 0, 0, 0, 0, 0},
                  { 0, 0, 0, 0, 0, 0},
                  { 0, 0, 0, 0, 0, 0},
                  { 0, 0, 0, 0, 0, 0}};

int solveMazerec(int maze[N][N], int x, int y, int sol[N][N]);

//Function to print the solution maze

void printSolution(int sol[N][N])
{
    printf("Solution maze\n\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", sol[i][j]);
        }
        printf("\n");
    }
}

int retsol(int i,int j)
{
    return sol[i][j];
}
//Function to check validity of x and y

int isSafe(int maze[N][N], int x, int y)
{
    // if (x, y outside maze) return false
    if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1)
        return 1;

    return 0;
}

int solveMaze(int maze[N][N])
{
    if (solveMazerec(maze, 0, 0, sol)== 0)
    {
        printf("Solution doesn't exist");
        return 0;
    }

    return 1;
}

//A recursive function (backtracking) to solve our maze

int solveMazerec(int maze[N][N], int x, int y, int sol[N][N])
{
    // if (x, y is goal) return true
    if (x == N - 1 && y == N - 1 && maze[x][y] == 1)
    {
        sol[x][y] = 1;
        return 1;
    }

    // Check if maze[x][y] is valid
    if (isSafe(maze, x, y) == 1)
    {
        // mark x, y as part of solution path
        sol[x][y] = 1;

        // Move forward in x direction
        if (solveMazerec(maze, x + 1, y, sol)== 1)
            return 1;

/* If moving in x direction doesn't give solution then Move down in y direction  */
        if (solveMazerec(maze, x, y + 1, sol)== 1)
            return 1;

/* If none of the above movements work then BACKTRACK: unmark x, y as part of solution path */
        sol[x][y] = 0;
        return 0;
    }

    return 0;
}

void login()
{
    x:
    char p,w,d;
    char log[50];
    printf("ENTER YOUR LOGIN ID : ");
    gets(log);
    printf("\nENTER YOUR PASSWORD : ");
    p=getch();
    printf("*");
    w=getch();
    printf("*");
    d=getch();
    printf("*");

    if(p=='P'&& w=='S'&& d=='G' && strcmp(log,"ADMIN")==0)
       printf("\nYou have successfully logged in......!!\n");
    else
    {
        printf("\nInvalid entry..\n");
        goto x;
    }
    getch();
}

int main(int argc,char **argv)
{
    SDL_Init((SDL_INIT_VIDEO));
    SDL_Window *window = SDL_CreateWindow("Rat in maze", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL);
    SDL_Renderer *renderer=SDL_CreateRenderer(window, -1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_Event event;
    int run=1;

    login();

    j:
    int rati=0,ratj=0,wc=0,ch=0;
    int maze[N][N],l[N][N];

    printf("\nAdmin set grid :\n");
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                scanf("%d",&maze[i][j]);
                l[i][j]=maze[i][j];
            }
        }


        solveMaze(maze);

        //File importing
        FILE * fp;
        fp = fopen("C:\\Users\\JERSHA HEARTLY X\\Desktop\\MOVIES\\rules.txt","w");
        if(fp == NULL)
        {
            printf("File not found...\n");
        }
        else
        {
            fputs("\n\t\tWELCOME TO RAT IN A MAZE\n\t\tRULES TO PLAY\n1. The player will be shown a maze of order 6 x 6.",fp);
            fputs("\n2. There will be a rat at upper left most block.\n3. The rat starts from source and reach its destination.",fp);
            fputs("\n4. Rat can be moved only in 2 directions, that is horizontal and vertical.",fp);
            fputs("\n5.You can use arrow keys to move the rat.",fp);
            fputs("\n6. Black square indicates dead end while white square indicates that the block can be used to move the rat.",fp);
        }
        fclose(fp);

        fp = fopen("C:\\Users\\JERSHA HEARTLY X\\Desktop\\MOVIES\\rules.txt","r");
        if(fp == NULL)
        {
            printf("File is not available\n");
        }
        else
        {
            char c;
            for(c = getc(fp);c!=EOF;c = getc(fp))
            {
                printf("%c",c);
            }
        }

        SDL_Rect rat;
        rat.x=25;
        rat.y=25;
        rat.w=50;
        rat.h=50;

        while (run)
        {
            while (SDL_PollEvent(&event))
            {
                switch (event.type)
                {
                    case SDL_QUIT:
                        // handling of close button
                        run = 0;
                        break;

                    case SDL_KEYDOWN:
                        // keyboard API for key pressed
                        switch (event.key.keysym.scancode)
                        {
                            case SDL_SCANCODE_UP:
                                if(rat.y!=25 && l[rati-1][ratj]==1)
                                {
                                    rat.y-=100;
                                    rati-=1;
                                }
                                break;
                            case SDL_SCANCODE_LEFT:
                                if(rat.x!=25 && l[rati][ratj-1]==1)
                                {
                                    rat.x-=100;
                                    ratj--;
                                }
                                break;
                            case SDL_SCANCODE_DOWN:
                                if(rat.y!=525 && l[rati+1][ratj]==1)
                                {
                                    rat.y+=100;
                                    rati++;
                                }
                                break;
                            case SDL_SCANCODE_RIGHT:
                                if(rat.x!=525 && l[rati][ratj+1]==1)
                                {
                                    rat.x+=100;
                                    ratj++;
                                }
                                break;
                                default:
                                    break;
                        }
                    }
                }

            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            SDL_RenderClear(renderer);

            int x=0;
            if(x==0)
                SDL_SetRenderDrawColor(renderer,0,0,0,255);
            else
                SDL_SetRenderDrawColor(renderer,255,255,255,255);

            SDL_Rect Rect1;
            Rect1.x=0;
            Rect1.y=0;
            Rect1.w=100;
            Rect1.h=100;
            SDL_Rect Rect2;
            Rect2.x=100;
            Rect2.y=0;
            Rect2.w=100;
            Rect2.h=100;
            SDL_Rect Rect3;
            Rect3.x=200;
            Rect3.y=0;
            Rect3.w=100;
            Rect3.h=100;
            SDL_Rect Rect4;
            Rect4.x=300;
            Rect4.y=0;
            Rect4.w=100;
            Rect4.h=100;
            SDL_Rect Rect5;
            Rect5.x=400;
            Rect5.y=0;
            Rect5.w=100;
            Rect5.h=100;
            SDL_Rect Rect6;
            Rect6.x=500;
            Rect6.y=0;
            Rect6.w=100;
            Rect6.h=100;
            SDL_Rect Rect7;
            Rect7.x=0;
            Rect7.y=100;
            Rect7.w=100;
            Rect7.h=100;
            SDL_Rect Rect8;
            Rect8.x=100;
            Rect8.y=100;
            Rect8.w=100;
            Rect8.h=100;
            SDL_Rect Rect9;
            Rect9.x=200;
            Rect9.y=100;
            Rect9.w=100;
            Rect9.h=100;
            SDL_Rect Rect10;
            Rect10.x=300;
            Rect10.y=100;
            Rect10.w=100;
            Rect10.h=100;
            SDL_Rect Rect11;
            Rect11.x=400;
            Rect11.y=100;
            Rect11.w=100;
            Rect11.h=100;
            SDL_Rect Rect12;
            Rect12.x=500;
            Rect12.y=100;
            Rect12.w=100;
            Rect12.h=100;
            SDL_Rect Rect13;
            Rect13.x=0;
            Rect13.y=200;
            Rect13.w=100;
            Rect13.h=100;
            SDL_Rect Rect14;
            Rect14.x=100;
            Rect14.y=200;
            Rect14.w=100;
            Rect14.h=100;
            SDL_Rect Rect15;
            Rect15.x=200;
            Rect15.y=200;
            Rect15.w=100;
            Rect15.h=100;
            SDL_Rect Rect16;
            Rect16.x=300;
            Rect16.y=200;
            Rect16.w=100;
            Rect16.h=100;
            SDL_Rect Rect17;
            Rect17.x=400;
            Rect17.y=200;
            Rect17.w=100;
            Rect17.h=100;
            SDL_Rect Rect18;
            Rect18.x=500;
            Rect18.y=200;
            Rect18.w=100;
            Rect18.h=100;
            SDL_Rect Rect19;
            Rect19.x=0;
            Rect19.y=300;
            Rect19.w=100;
            Rect19.h=100;
            SDL_Rect Rect20;
            Rect20.x=100;
            Rect20.y=300;
            Rect20.w=100;
            Rect20.h=100;
            SDL_Rect Rect21;
            Rect21.x=200;
            Rect21.y=300;
            Rect21.w=100;
            Rect21.h=100;
            SDL_Rect Rect22;
            Rect22.x=300;
            Rect22.y=300;
            Rect22.w=100;
            Rect22.h=100;
            SDL_Rect Rect23;
            Rect23.x=400;
            Rect23.y=300;
            Rect23.w=100;
            Rect23.h=100;SDL_Rect Rect24;
            Rect24.x=500;
            Rect24.y=300;
            Rect24.w=100;
            Rect24.h=100;
            SDL_Rect Rect25;
            Rect25.x=0;
            Rect25.y=400;
            Rect25.w=100;
            Rect25.h=100;
            SDL_Rect Rect26;
            Rect26.x=100;
            Rect26.y=400;
            Rect26.w=100;
            Rect26.h=100;SDL_Rect Rect27;
            Rect27.x=200;
            Rect27.y=400;
            Rect27.w=100;
            Rect27.h=100;
            SDL_Rect Rect28;
            Rect28.x=300;
            Rect28.y=400;
            Rect28.w=100;
            Rect28.h=100;
            SDL_Rect Rect29;
            Rect29.x=400;
            Rect29.y=400;
            Rect29.w=100;
            Rect29.h=100;
            SDL_Rect Rect30;
            Rect30.x=500;
            Rect30.y=400;
            Rect30.w=100;
            Rect30.h=100;
            SDL_Rect Rect31;
            Rect31.x=0;
            Rect31.y=500;
            Rect31.w=100;
            Rect31.h=100;
            SDL_Rect Rect32;
            Rect32.x=100;
            Rect32.y=500;
            Rect32.w=100;
            Rect32.h=100;
            SDL_Rect Rect33;
            Rect33.x=200;
            Rect33.y=500;
            Rect33.w=100;
            Rect33.h=100;
            SDL_Rect Rect34;
            Rect34.x=300;
            Rect34.y=500;
            Rect34.w=100;
            Rect34.h=100;
            SDL_Rect Rect35;
            Rect35.x=400;
            Rect35.y=500;
            Rect35.w=100;
            Rect35.h=100;
            SDL_Rect Rect36;
            Rect36.x=500;
            Rect36.y=500;
            Rect36.w=100;
            Rect36.h=100;

            if (l[0][0])
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            else
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderDrawRect(renderer, &Rect1);
            SDL_RenderFillRect(renderer, &Rect1);
            if (l[0][1])
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            else
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderDrawRect(renderer, &Rect2);
            SDL_RenderFillRect(renderer, &Rect2);
            if (l[0][2])
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            else
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderDrawRect(renderer, &Rect3);
            SDL_RenderFillRect(renderer, &Rect3);
            if (l[0][3])
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            else
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderDrawRect(renderer, &Rect4);
            SDL_RenderFillRect(renderer, &Rect4);
            if (l[0][4])
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            else
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderDrawRect(renderer, &Rect5);
            SDL_RenderFillRect(renderer, &Rect5);
            if (l[0][5])
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            else
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderDrawRect(renderer, &Rect6);
            SDL_RenderFillRect(renderer, &Rect6);
            if (l[1][0])
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            else
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderDrawRect(renderer, &Rect7);
            SDL_RenderFillRect(renderer, &Rect7);
            if (l[1][1])
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            else
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderDrawRect(renderer, &Rect8);
            SDL_RenderFillRect(renderer, &Rect8);
            if (l[1][2])
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            else
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderDrawRect(renderer, &Rect9);
            SDL_RenderFillRect(renderer, &Rect9);
            if (l[1][3])
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            else
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderDrawRect(renderer, &Rect10);
            SDL_RenderFillRect(renderer, &Rect10);
            if (l[1][4])
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            else
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderDrawRect(renderer, &Rect11);
            SDL_RenderFillRect(renderer, &Rect11);
            if (l[1][5])
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            else
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderDrawRect(renderer, &Rect12);
            SDL_RenderFillRect(renderer, &Rect12);
            if (l[2][0])
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            else
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderDrawRect(renderer, &Rect13);
            SDL_RenderFillRect(renderer, &Rect13);
            if (l[2][1])
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            else
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderDrawRect(renderer, &Rect14);
            SDL_RenderFillRect(renderer, &Rect14);
            if (l[2][2])
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            else
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderDrawRect(renderer, &Rect15);
            SDL_RenderFillRect(renderer, &Rect15);
            if (l[2][3])
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            else
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderDrawRect(renderer, &Rect16);
            SDL_RenderFillRect(renderer, &Rect16);
            if (l[2][4])
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            else
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderDrawRect(renderer, &Rect17);
            SDL_RenderFillRect(renderer, &Rect17);
            if (l[2][5])
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            else
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderDrawRect(renderer, &Rect18);
            SDL_RenderFillRect(renderer, &Rect18);
            if (l[3][0])
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            else
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderDrawRect(renderer, &Rect19);
            SDL_RenderFillRect(renderer, &Rect19);
            if (l[3][1])
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            else
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderDrawRect(renderer, &Rect20);
            SDL_RenderFillRect(renderer, &Rect20);
            if (l[3][2])
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            else
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderDrawRect(renderer, &Rect21);
            SDL_RenderFillRect(renderer, &Rect21);
            if (l[3][3])
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            else
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderDrawRect(renderer, &Rect22);
            SDL_RenderFillRect(renderer, &Rect22);
            if (l[3][4])
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            else
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderDrawRect(renderer, &Rect23);
            SDL_RenderFillRect(renderer, &Rect23);
            if (l[3][5])
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            else
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderDrawRect(renderer, &Rect24);
            SDL_RenderFillRect(renderer, &Rect24);
            if (l[4][0])
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            else
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderDrawRect(renderer, &Rect25);
            SDL_RenderFillRect(renderer, &Rect25);
            if (l[4][1])
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            else
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderDrawRect(renderer, &Rect26);
            SDL_RenderFillRect(renderer, &Rect26);
            if (l[4][2])
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            else
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderDrawRect(renderer, &Rect27);
            SDL_RenderFillRect(renderer, &Rect27);
            if (l[4][3])
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            else
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderDrawRect(renderer, &Rect28);
            SDL_RenderFillRect(renderer, &Rect28);
            if (l[4][4])
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            else
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderDrawRect(renderer, &Rect29);
            SDL_RenderFillRect(renderer, &Rect29);
            if (l[4][5])
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            else
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderDrawRect(renderer, &Rect30);
            SDL_RenderFillRect(renderer, &Rect30);
            if (l[5][0])
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            else
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderDrawRect(renderer, &Rect31);
            SDL_RenderFillRect(renderer, &Rect31);
            if (l[5][1])
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            else
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderDrawRect(renderer, &Rect32);
            SDL_RenderFillRect(renderer, &Rect32);
            if (l[5][2])
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            else
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderDrawRect(renderer, &Rect33);
            SDL_RenderFillRect(renderer, &Rect33);
            if (l[5][3])
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            else
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderDrawRect(renderer, &Rect34);
            SDL_RenderFillRect(renderer, &Rect34);
            if (l[5][4])
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            else
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderDrawRect(renderer, &Rect35);
            SDL_RenderFillRect(renderer, &Rect35);
            if (l[5][5])
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            else
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderDrawRect(renderer, &Rect36);
            SDL_RenderFillRect(renderer, &Rect36);

            SDL_SetRenderDrawColor(renderer, 0, 128, 255, 255);
            SDL_RenderDrawLine(renderer, 0, 100, 600, 100);

            SDL_SetRenderDrawColor(renderer, 0, 128, 255, 255);
            SDL_RenderDrawLine(renderer, 0, 200, 600, 200);

            SDL_SetRenderDrawColor(renderer, 0, 128, 255, 255);
            SDL_RenderDrawLine(renderer, 0, 300, 600, 300);

            SDL_SetRenderDrawColor(renderer, 0, 128, 255, 255);
            SDL_RenderDrawLine(renderer, 0, 400, 600, 400);

            SDL_SetRenderDrawColor(renderer, 0, 128, 255, 255);
            SDL_RenderDrawLine(renderer, 0, 500, 600, 500);

            SDL_SetRenderDrawColor(renderer, 0, 128, 255, 255);
            SDL_RenderDrawLine(renderer, 100, 0, 100, 600);

            SDL_SetRenderDrawColor(renderer, 0, 128, 255, 255);
            SDL_RenderDrawLine(renderer, 200, 0, 200, 600);

            SDL_SetRenderDrawColor(renderer, 0, 128, 255, 255);
            SDL_RenderDrawLine(renderer, 300, 0, 300, 600);

            SDL_SetRenderDrawColor(renderer, 0, 128, 255, 255);
            SDL_RenderDrawLine(renderer, 400, 0, 400, 600);

            SDL_SetRenderDrawColor(renderer, 0, 128, 255, 255);
            SDL_RenderDrawLine(renderer, 500, 0, 500, 600);

            if(rati==5 && ratj==5 && !(wc))
            {
                printf("\n\nYou won !!");
                wc = 1;
            }


            if(wc)
            {
                if (sol[0][0])
                    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
                else
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderDrawRect(renderer, &Rect1);
                SDL_RenderFillRect(renderer, &Rect1);
                if (sol[0][1])
                    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
                else
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderDrawRect(renderer, &Rect2);
                SDL_RenderFillRect(renderer, &Rect2);
                if (sol[0][2])
                    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
                else
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderDrawRect(renderer, &Rect3);
                SDL_RenderFillRect(renderer, &Rect3);
                if (sol[0][3])
                    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
                else
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderDrawRect(renderer, &Rect4);
                SDL_RenderFillRect(renderer, &Rect4);
                if (sol[0][4])
                    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
                else
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderDrawRect(renderer, &Rect5);
                SDL_RenderFillRect(renderer, &Rect5);
                if (sol[0][5])
                    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
                else
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderDrawRect(renderer, &Rect6);
                SDL_RenderFillRect(renderer, &Rect6);
                if (sol[1][0])
                    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
                else
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderDrawRect(renderer, &Rect7);
                SDL_RenderFillRect(renderer, &Rect7);
                if (sol[1][1])
                    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
                else
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderDrawRect(renderer, &Rect8);
                SDL_RenderFillRect(renderer, &Rect8);
                if (sol[1][2])
                    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
                else
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderDrawRect(renderer, &Rect9);
                SDL_RenderFillRect(renderer, &Rect9);
                if (sol[1][3])
                    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
                else
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderDrawRect(renderer, &Rect10);
                SDL_RenderFillRect(renderer, &Rect10);
                if (sol[1][4])
                    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
                else
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderDrawRect(renderer, &Rect11);
                SDL_RenderFillRect(renderer, &Rect11);
                if (sol[1][5])
                    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
                else
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderDrawRect(renderer, &Rect12);
                SDL_RenderFillRect(renderer, &Rect12);
                if (sol[2][0])
                    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
                else
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderDrawRect(renderer, &Rect13);
                SDL_RenderFillRect(renderer, &Rect13);
                if (sol[2][1])
                    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
                else
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderDrawRect(renderer, &Rect14);
                SDL_RenderFillRect(renderer, &Rect14);
                if (sol[2][2])
                    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
                else
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderDrawRect(renderer, &Rect15);
                SDL_RenderFillRect(renderer, &Rect15);
                if (sol[2][3])
                    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
                else
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderDrawRect(renderer, &Rect16);
                SDL_RenderFillRect(renderer, &Rect16);
                if (sol[2][4])
                    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
                else
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderDrawRect(renderer, &Rect17);
                SDL_RenderFillRect(renderer, &Rect17);
                if (sol[2][5])
                    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
                else
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderDrawRect(renderer, &Rect18);
                SDL_RenderFillRect(renderer, &Rect18);
                if (sol[3][0])
                    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
                else
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderDrawRect(renderer, &Rect19);
                SDL_RenderFillRect(renderer, &Rect19);
                if (sol[3][1])
                    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
                else
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderDrawRect(renderer, &Rect20);
                SDL_RenderFillRect(renderer, &Rect20);
                if (sol[3][2])
                    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
                else
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderDrawRect(renderer, &Rect21);
                SDL_RenderFillRect(renderer, &Rect21);
                if (sol[3][3])
                    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
                else
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderDrawRect(renderer, &Rect22);
                SDL_RenderFillRect(renderer, &Rect22);
                if (sol[3][4])
                    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
                else
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderDrawRect(renderer, &Rect23);
                SDL_RenderFillRect(renderer, &Rect23);
                if (sol[3][5])
                    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
                else
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderDrawRect(renderer, &Rect24);
                SDL_RenderFillRect(renderer, &Rect24);
                if (sol[4][0])
                    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
                else
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderDrawRect(renderer, &Rect25);
                SDL_RenderFillRect(renderer, &Rect25);
                if (sol[4][1])
                    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
                else
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderDrawRect(renderer, &Rect26);
                SDL_RenderFillRect(renderer, &Rect26);
                if (sol[4][2])
                    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
                else
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderDrawRect(renderer, &Rect27);
                SDL_RenderFillRect(renderer, &Rect27);
                if (sol[4][3])
                    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
                else
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderDrawRect(renderer, &Rect28);
                SDL_RenderFillRect(renderer, &Rect28);
                if (sol[4][4])
                    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
                else
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderDrawRect(renderer, &Rect29);
                SDL_RenderFillRect(renderer, &Rect29);
                if (sol[4][5])
                    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
                else
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderDrawRect(renderer, &Rect30);
                SDL_RenderFillRect(renderer, &Rect30);
                if (sol[5][0])
                    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
                else
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderDrawRect(renderer, &Rect31);
                SDL_RenderFillRect(renderer, &Rect31);
                if (sol[5][1])
                    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
                else
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderDrawRect(renderer, &Rect32);
                SDL_RenderFillRect(renderer, &Rect32);
                if (sol[5][2])
                    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
                else
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderDrawRect(renderer, &Rect33);
                SDL_RenderFillRect(renderer, &Rect33);
                if (sol[5][3])
                    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
                else
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderDrawRect(renderer, &Rect34);
                SDL_RenderFillRect(renderer, &Rect34);
                if (sol[5][4])
                    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
                else
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderDrawRect(renderer, &Rect35);
                SDL_RenderFillRect(renderer, &Rect35);
                if (sol[5][5])
                    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
                else
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderDrawRect(renderer, &Rect36);
                SDL_RenderFillRect(renderer, &Rect36);

                SDL_SetRenderDrawColor(renderer, 0, 128, 255, 255);
                SDL_RenderDrawLine(renderer, 0, 100, 600, 100);

                SDL_SetRenderDrawColor(renderer, 0, 128, 255, 255);
                SDL_RenderDrawLine(renderer, 0, 200, 600, 200);

                SDL_SetRenderDrawColor(renderer, 0, 128, 255, 255);
                SDL_RenderDrawLine(renderer, 0, 300, 600, 300);

                SDL_SetRenderDrawColor(renderer, 0, 128, 255, 255);
                SDL_RenderDrawLine(renderer, 0, 400, 600, 400);

                SDL_SetRenderDrawColor(renderer, 0, 128, 255, 255);
                SDL_RenderDrawLine(renderer, 0, 500, 600, 500);

                SDL_SetRenderDrawColor(renderer, 0, 128, 255, 255);
                SDL_RenderDrawLine(renderer, 100, 0, 100, 600);

                SDL_SetRenderDrawColor(renderer, 0, 128, 255, 255);
                SDL_RenderDrawLine(renderer, 200, 0, 200, 600);

                SDL_SetRenderDrawColor(renderer, 0, 128, 255, 255);
                SDL_RenderDrawLine(renderer, 300, 0, 300, 600);

                SDL_SetRenderDrawColor(renderer, 0, 128, 255, 255);
                SDL_RenderDrawLine(renderer, 400, 0, 400, 600);

                SDL_SetRenderDrawColor(renderer, 0, 128, 255, 255);
                SDL_RenderDrawLine(renderer, 500, 0, 500, 600);
            }

            SDL_SetRenderDrawColor(renderer, 127, 67, 41, 255);
            SDL_RenderDrawRect(renderer, &rat);
            SDL_RenderFillRect(renderer, &rat);



            SDL_RenderPresent(renderer);
        }
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        printf("\n\tThank you !!!\n");
}
