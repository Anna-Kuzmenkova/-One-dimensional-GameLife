#include <stdio.h>
#include <windows.h>
int next_state(int a, int b, int c);
void print_actual_state (int *a, int n);

int main()
{
    int n, i;
    int asleep=100;

    n = 79;

    int a[n];
    int b[n];

    for(i=0;i<n;i++)
        a[i]=rand() % 2;

    for(i=0;i<n;i++)
        b[i]=0;

   print_actual_state(a, n);

    Sleep(asleep);

    while(!GetAsyncKeyState(VK_ESCAPE))
    {
        for(i=0;i<n;i++)
        {
            b[i]=next_state(a[ (n+(i-1)) % n], a[i], a[ (i+1) % n]);
        }

        for(i=0;i<n;i++)
            a[i]=b[i];

        print_actual_state(a, n);

        Sleep(asleep);
    }
}

int next_state(int a, int b, int c)
{
    int result=0;
    if( (a==c) && (a==b || a<b) )
        result=0;
    else
        result=1;
    return result;
}

void print_actual_state (int *a, int n)
{
    for(int i = 0; i < n; i++)
    {
        if(a[i]==1)
            printf("*");
        else
            printf(" ");
    }
    printf("\n");

}


