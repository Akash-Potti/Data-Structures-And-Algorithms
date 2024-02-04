#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define stacksize 15
int inputprecedence(char symbol)
{
    switch (symbol)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 3;
    case '^':
    case '$':
        return 6;
    case '(':
        return 9;
    case ')':
        return 0;
    default:
        return 7;
    }
}
int stackprecedence(char symbol)
{
    switch (symbol)
    {
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 4;
    case '^':
    case '$':
        return 5;
    case '(':
        return 0;
    case '#':
        return -1;
    default:
        return 8;
    }
}

void push(char item, int *top, char s[])
{
    if (*top == stacksize - 1)
    {
        printf("Stack overflow\n");
        return;
    }
    *top = *top + 1;
    s[*top] = item;
}

char pop(int *top, char s[])
{
    if (*top == -1)
    {
        printf("Stack underflow\n");
        return -1;
    }
    char item = s[*top];
    *top = *top - 1;
    return item;
}

void convert(char infix[], char postfix[])
{
    int i, j = 0, top = -1, n;
    char s[100], symbol;
    n = strlen(infix);
    push('#', &top, s);

    for (i = 0; i < n; i++)
    {
        symbol = infix[i];
        while (stackprecedence(s[top]) > inputprecedence(symbol))
        {
            postfix[j] = pop(&top, s);
            j = j + 1;
        }
        if (stackprecedence(s[top]) != inputprecedence(symbol))
        {
            push(symbol, &top, s);
        }
        else
        {
            pop(&top, s);
        }
    }
    while (s[top] != '#')
    {
        postfix[j] = pop(&top, s);
        j = j + 1;
    }
    postfix[j] = '\0';
}

void main()
{
    char infix[100], postfix[100];
    printf("Enter the infix expression\n");
    gets(infix);
    convert(infix, postfix);
    printf("The postfix expression is\n");
    puts(postfix);
}