#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "users.txt"

typedef struct {
    int id;
    char name[50];
    int age;
} User;

void createUser() {
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        perror("Unable to open file for writing");
        return;
    }
    
    User user;
    printf("Enter User ID: ");
    scanf("%d", &user.id);
    printf("Enter Name: ");
    scanf("%s", user.name);
    printf("Enter Age: ");
    scanf("%d", &user.age);
    
    fprintf(file, "%d %s %d\n", user.id, user.name, user.age);
    fclose(file);
    printf("User added successfully.\n");
}

void readUsers() {
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

void updateUser() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Unable to open file for reading");
        return;
    }

    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        perror("Unable to open temporary file for writing");
        fclose(file);
        return;
    }
    
    int id, found = 0;
    User user;
    printf("Enter User ID to update: ");
    scanf("%d", &id);
    
    while (fscanf(file, "%d %s %d", &user.id, user.name, &user.age) != EOF) {
        if (user.id == id) {
            found = 1;
            printf("Enter new name: ");
            scanf("%s", user.name);
            printf("Enter new age: ");
            scanf("%d", &user.age);
        }
        fprintf(tempFile, "%d %s %d\n", user.id, user.name, user.age);
    }
    
    fclose(file);
    fclose(tempFile);
    remove(FILENAME);
    rename("temp.txt", FILENAME);
    
    if (found) {
        printf("User updated successfully.\n");
    } else {
        printf("User ID not found.\n");
    }
}

void deleteUser() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Unable to open file for reading");
        return;
    }

    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        perror("Unable to open temporary file for writing");
        fclose(file);
        return;
    }
    
    int id, found = 0;
    User user;
    printf("Enter User ID to delete: ");
    scanf("%d", &id);
    
    while (fscanf(file, "%d %s %d", &user.id, user.name, &user.age) != EOF) {
        if (user.id == id) {
            found = 1;
            continue;
        }
        fprintf(tempFile, "%d %s %d\n", user.id, user.name, user.age);
    }
    
    fclose(file);
    fclose(tempFile);
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
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                createUser();
                break;
            case 2:
                readUsers();
                break;
            case 3:
                updateUser();
                break;
            case 4:
                deleteUser();
                break;
            case 5:
                printf("Exit");
                break;
            default:
                printf("Invalid choice");
        }
    } while (choice != 5);
    return 0;
}
