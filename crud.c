#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define FILENAME "users.txt"

typedef struct {
    int id;
    char name[50];
    int age;
} User;

// Function to validate integer input
int get_valid_int(const char *prompt) {
    int value;
    char buffer[50];
    while (1) {
        printf("%s", prompt);
        if (fgets(buffer, sizeof(buffer), stdin)) {
            char *endptr;
            value = strtol(buffer, &endptr, 10);
            if (endptr != buffer && *endptr == '\n') {
                return value;
            }
        }
        printf("Invalid input. Please enter a valid number.\n");
    }
}

// Function to validate string input
void get_valid_string(const char *prompt, char *result, size_t size) {
    while (1) {
        printf("%s", prompt);
        if (fgets(result, size, stdin)) {
            size_t len = strcspn(result, "\n");
            if (len < size) {
                result[len] = '\0';
                return;
            }
        }
        printf("Input too long. Please try again.\n");
    }
}

// Function to check if a user ID already exists
int is_user_id_exists(int id) {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        return 0; // No users yet
    }

    User user;
    while (fscanf(file, "%d %s %d", &user.id, user.name, &user.age) != EOF) {
        if (user.id == id) {
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0;
}

// Function to create a new user
void create_user() {
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        perror("Unable to open file for writing");
        return;
    }

    User user;
    do {
        user.id = get_valid_int("Enter User ID: ");
        if (is_user_id_exists(user.id)) {
            printf("Error: User ID already exists. Please try again.\n");
        }
    } while (is_user_id_exists(user.id));

    get_valid_string("Enter Name: ", user.name, sizeof(user.name));
    user.age = get_valid_int("Enter Age: ");

    fprintf(file, "%d %s %d\n", user.id, user.name, user.age);
    fclose(file);
    printf("User added successfully.\n");
}

// Function to read all users
void read_users() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Unable to open file for reading");
        return;
    }

    User user;
    printf("\nList of Users:\n");
    printf("ID\tName\tAge\n");
    printf("------------------------\n");
    while (fscanf(file, "%d %s %d", &user.id, user.name, &user.age) != EOF) {
        printf("%d\t%s\t%d\n", user.id, user.name, user.age);
    }

    fclose(file);
}

// Function to update a user
void update_user() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Unable to open file for reading");
        return;
    }

    FILE *temp_file = fopen("temp.txt", "w");
    if (temp_file == NULL) {
        perror("Unable to open temporary file for writing");
        fclose(file);
        return;
    }

    int id, found = 0;
    User user;
    id = get_valid_int("Enter User ID to update: ");

    while (fscanf(file, "%d %s %d", &user.id, user.name, &user.age) != EOF) {
        if (user.id == id) {
            found = 1;
            get_valid_string("Enter new name: ", user.name, sizeof(user.name));
            user.age = get_valid_int("Enter new age: ");
        }
        fprintf(temp_file, "%d %s %d\n", user.id, user.name, user.age);
    }

    fclose(file);
    fclose(temp_file);
    remove(FILENAME);
    rename("temp.txt", FILENAME);

    if (found) {
        printf("User updated successfully.\n");
    } else {
        printf("User ID not found.\n");
    }
}

// Function to delete a user
void delete_user() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Unable to open file for reading");
        return;
    }

    FILE *temp_file = fopen("temp.txt", "w");
    if (temp_file == NULL) {
        perror("Unable to open temporary file for writing");
        fclose(file);
        return;
    }

    int id, found = 0;
    User user;
    id = get_valid_int("Enter User ID to delete: ");

    while (fscanf(file, "%d %s %d", &user.id, user.name, &user.age) != EOF) {
        if (user.id == id) {
            found = 1;
            continue;
        }
        fprintf(temp_file, "%d %s %d\n", user.id, user.name, user.age);
    }

    fclose(file);
    fclose(temp_file);
    remove(FILENAME);
    rename("temp.txt", FILENAME);

    if (found) {
        printf("User deleted successfully.\n");
    } else {
        printf("User ID not found.\n");
    }
}

int main() {
    int choice;
    do {
        printf("\nUser Management System\n");
        printf("1. Add User\n");
        printf("2. View Users\n");
        printf("3. Update User\n");
        printf("4. Delete User\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        choice = get_valid_int("");

        switch (choice) {
            case 1:
                create_user();
                break;
            case 2:
                read_users();
                break;
            case 3:
                update_user();
                break;
            case 4:
                delete_user();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
