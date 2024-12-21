#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Check if the character is an operator
int is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// Perform the calculation based on the operator
int perform_calculation(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) {
                printf("Error: Division by zero.\n");
                exit(EXIT_FAILURE);
            }
            return a / b;
        default:
            printf("Error: Invalid operator '%c'.\n", op);
            exit(EXIT_FAILURE);
    }
}

// Determine operator precedence
int precedence(char op) {
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

// Evaluate the mathematical expression
int evaluate_expression(const char* expression, int* error_flag) {
    int numbers[100], num_top = -1;
    char operators[100], op_top = -1;

    for (int i = 0; i < strlen(expression); i++) {
        if (isspace(expression[i]))
            continue;

        if (isdigit(expression[i])) {
            int num = 0;
            while (i < strlen(expression) && isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            i--; // Step back to account for the last increment
            numbers[++num_top] = num;
        } else if (is_operator(expression[i])) {
            while (op_top >= 0 && precedence(operators[op_top]) >= precedence(expression[i])) {
                if (num_top < 1) {
                    printf("Error: Insufficient operands.\n");
                    *error_flag = 1;
                    return 0;
                }
                int b = numbers[num_top--];
                int a = numbers[num_top--];
                char op = operators[op_top--];
                numbers[++num_top] = perform_calculation(a, b, op);
            }
            operators[++op_top] = expression[i];
        } else {
            printf("Error: Invalid character '%c' in expression.\n", expression[i]);
            *error_flag = 1;
            return 0;
        }
    }

    while (op_top >= 0) {
        if (num_top < 1) {
            printf("Error: Insufficient operands.\n");
            *error_flag = 1;
            return 0;
        }
        int b = numbers[num_top--];
        int a = numbers[num_top--];
        char op = operators[op_top--];
        numbers[++num_top] = perform_calculation(a, b, op);
    }

    return numbers[num_top];
}

int main() {
    char expression[100];
    printf("Enter a mathematical expression: ");
    if (!fgets(expression, sizeof(expression), stdin)) {
        printf("Error: Failed to read input.\n");
        return 1;
    }

    // Remove trailing newline character if present
    expression[strcspn(expression, "\n")] = 0;

    if (strlen(expression) == 0) {
        printf("Error: Empty expression entered.\n");
        return 1;
    }

    int error_flag = 0;
    int result = evaluate_expression(expression, &error_flag);
    if (!error_flag) {
        printf("Result: %d\n", result);
    }

    return 0;
}
