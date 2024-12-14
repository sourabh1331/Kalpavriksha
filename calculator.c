#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int isOperator(char c){  
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int calculator(int a, int b, char op){
    switch (op){
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/':
            if (b==0){
                printf("Error divide by zero");
                return 0;
            }
            return a/b;
        default: return 0;
    }
}

int eval_expression(const char* expression){
    int numbers[100],numtop=-1;
    char operator[100],optop=-1;
    for(int i=0;i<strlen(expression);i++){
        if(isspace(expression[i])) continue;
        if(isdigit(expression[i])){
            int num=0;
            while (i<strlen(expression) && isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            i--;     
            numbers[++numtop]=num;
        }
        else if (isOperator(expression[i])){
            while (optop >= 0 && ((operator[optop] == '*' || operator[optop] == '/') || 
                   (operator[optop] == '+' || operator[optop] == '-') && 
                   (expression[i] == '+' || expression[i] == '-'))){
                    int b=numbers[numtop--];
                    int a=numbers[numtop--];
                    char op=operator[optop--];
                    numbers[++numtop]=calculator(a,b,op);

                }
                operator[++optop]=expression[i];

        }
        else{
            printf("Error invalid expresion");
            return 0;
        }
    }
    while(optop>=0){
        int b=numbers[numtop--];
        int a=numbers[numtop--];
        char op=operator[optop--];;
        numbers[++numtop]=calculator(a,b,op);

    }
    return numbers[numtop];
}
int main() {
    char expression[100];
    printf("Enter a mathematical expression: ");
    fgets(expression, sizeof(expression), stdin);
    expression[strcspn(expression, "\n")] = 0;
    int result = eval_expression(expression);
    printf("Result: %d\n", result);
    return 0;
}
