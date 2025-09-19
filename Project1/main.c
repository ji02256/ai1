#include <math.h>
#include <stdio.h>
#include <Windows.h>

#define PI 3.14159265358979323846

int gotoxy(int x, int y)
{
    printf("\033[%d;%dH", y, x);
    return 0;
}

int END(int x, int y)
{
    gotoxy(0, 0);
    printf(" ^^^^^^\n");
    printf(" !BOOM!\n");
    printf(" ^^^^^^");
    return 0;
}

int main()
{
    printf("(  B  )");

    int a = 13;
    int posx = 7, posy = 1;
    int x, y;
    double angle = 0.0;
    int length = a;

    while (length > 0)
    {
        x = cos(angle * PI / 180.0);
        y = sin(angle * PI / 180.0);

        int count = 0;
        while (count < length)
        {
            posx += x;
            posy += y;
            gotoxy(posx, posy);
            printf("#");
            count++;
        }

        angle += 90.0;

        x = cos(angle * PI / 180.0);
        y = sin(angle * PI / 180.0);

        length--;
        length--;

        count = 0;
        while (count < length)
        {
            posx += x;
            posy += y;
            gotoxy(posx, posy);
            printf("#");
            count++;
        }

        angle += 90.0;
    }

    gotoxy(posx, posy);
    printf("*");

    Sleep(200);

    angle -= 180.0;

    while (length < a)
    {
        angle -= 90.0;

        x = cos(angle * PI / 180.0);
        y = sin(angle * PI / 180.0);

        int count = 0;
        while (count < length)
        {
            Sleep(200);
            gotoxy(posx, posy);
            printf(" ");
            posx += x;
            posy += y;
            gotoxy(posx, posy);
            printf("*");
            count++;
        }

        angle -= 90.0;

        x = cos(angle * PI / 180.0);
        y = sin(angle * PI / 180.0);

        length++;
        length++;

        count = 0;
        while (count < length)
        {
            Sleep(200);
            gotoxy(posx, posy);
            printf(" ");
            posx += x;
            posy += y;
            gotoxy(posx, posy);
            if (length != a + 1) printf("*");
            count++;
        }
    }

    END(posx, posy);
    gotoxy(0, 10);

    return 0;
}
