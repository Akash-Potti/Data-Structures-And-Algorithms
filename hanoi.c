#include <stdio.h>

int count = 0;

void tower(int n, char source, char destination, char temp)
{
    if (n == 1)
    {
        printf("move disk from %c to %c\n", source, destination);
        count++;
    }
    else
    {
        tower(n - 1, source, temp, destination);
        printf("move disk from %c to %c\n", source, destination);
        count++;
        tower(n - 1, temp, destination, source);
    }
}

int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    tower(n, 'A', 'C', 'B');
    printf("The number of moves is %d\n", count);

    return 0;
}
