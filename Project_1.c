#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int Check(int x[][4])
{
    int q = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
        {
            if (q == 15)
                q = 32;
            else
                q++;

            if (x[i][j] != q)
                return 0;
        }
    return 1;
}

void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void PrintRules()
{
    system("cls");
    printf("\n\t\t\t\t\tGame Rules\n\n");

    printf("1. You can move only 1 step at a time with the arrow key.\n\n");
    printf("2. You can move numbers at an empty position only.\n\n");
    printf("3. For each valid move : your total number of moves will decrease by 1.\n");

    printf("\n\tWinnig Situation \n");
    printf("---------------------------------\n");
    printf("|   1   |   2   |   3   |   4   |\n");
    printf("|   5   |   6   |   7   |   8   |\n");
    printf("|   9   |  10   |  11   |  12   |\n");
    printf("|  13   |  14   |  15   |       |\n");
    printf("---------------------------------\n");

    printf("Press any Key to Continue : ");
    getch();
}

void Display(int a[][4], int r, int c)
{
    printf("---------------------------------\n");
    for (int i = 0; i < r; i++)
    {
        printf("|");
        for (int j = 0; j < c; j++)
        {
            if (a[i][j] == ' ')
                printf("   %c\t|", a[i][j]);
            else
                printf("   %d\t|", a[i][j]);
        }
        printf("\n");
    }
    printf("---------------------------------\n");
}

void Input(char name[], int s)
{
    system("cls");
    printf("Enter Your name : ");
    fflush(stdin);
    fgets(name, s, stdin);
}

int main()
{

    char s1 = '\0';
    do
    {
        int chance = 6;
        char c;
        int a[4][4] = {{2, 3, 4, 1}, {12, 13, 14, 11}, {5, 6, 8, 7}, {15, 9, 10, ' '}};
        char name[15];

        Input(name, 15);

        PrintRules();

        for (int p = 0; p < chance; p++)
        {

            system("cls");
            printf("Hello %s\nMove remaining %d\n", name, chance - p);
            Display(a, 4, 4);

            printf("\nPerform operation by pressing Arrow Keys :  ");

            c = getch();
            if (c == 0 || c == 224)
                c = getch();

            int i = 0, j = 0, x = 0;
            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < 4; j++)
                {
                    if (a[i][j] == ' ')
                    {
                        x = -1;
                        break;
                    }
                }
                if (x == -1)
                    break;
            }

            switch (c)
            {
            case 77:
                if (j != 0)
                    Swap(&a[i][j], &a[i][j - 1]);
                break;

            case 75:
                if (j != 3)
                    Swap(&a[i][j], &a[i][j + 1]);
                break;

            case 72:
                if (i != 3)
                    Swap(&a[i][j], &a[i + 1][j]);
                break;

            case 80:
                if (i != 0)
                    Swap(&a[i][j], &a[i - 1][j]);
                break;

            default:
                printf("Invalid Choice");
            }
        }

        system("cls");
        if (Check(a))
            printf("\nYou Won!\n");
        else
            printf("\nYou Lost!\n");

        printf("\nPress y to play Again or other key to Exit : ");
        s1 = getch();

    } while (s1 == 'Y' || s1 == 'y');

    return 0;
}
