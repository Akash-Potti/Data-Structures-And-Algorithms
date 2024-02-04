#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define stacksize 15

void push(int item, int *top, int s[])
{
    if (*top == stacksize - 1)
    {
        printf("Stack overflow\n");
        return;
    }
    *top = *top + 1;
    s[*top] = item;
}

int pop(int s[], int *top)
{
    if (*top == -1)
    {
        printf("Stack underflow\n");
        return -1;
    }
    int item = s[*top];
    *top = *top - 1;
    return item;
}

int evaluate(char postfix[])
{
    int n, top, i, op1, op2, res, s[stacksize];
    char symbol;
    top = -1;
    n = strlen(postfix);

    for (i = 0; i < n; i++)
    {
        symbol = postfix[i];
        switch (symbol)
        {
        case '+':
            op2 = pop(s, &top);
            op1 = pop(s, &top);
            res = op1 + op2;
            push(res, &top, s);
            break;
        case '-':
            op2 = pop(s, &top);
            op1 = pop(s, &top);
            res = op1 - op2;
            push(res, &top, s);
            break;
        case '*':
            op2 = pop(s, &top);
            op1 = pop(s, &top);
            res = op1 * op2;
            push(res, &top, s);
            break;
        case '/':
            op2 = pop(s, &top);
            op1 = pop(s, &top);
            res = op1 / op2;
            push(res, &top, s);
            break;
        case '^':
            op2 = pop(s, &top);
            op1 = pop(s, &top);
            res = (int)pow((double)op1, (double)op2);
            push(res, &top, s);
            break;
        default:
            push(symbol - '0', &top, s);
        }
    }
    return pop(s, &top);
}

int main()
{
    char postfix[50];
    int result, top = -1, s[stacksize];
    printf("Enter the postfix expression: ");
    scanf("%s", postfix);
    result = evaluate(postfix);
    printf("The result is %d\n", result);
    return 0;
}
