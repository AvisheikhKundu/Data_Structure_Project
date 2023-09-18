#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct UserInfo {
    char name[100];
    int id;
    char department[100];
    int semester;
};

void displayUserInfo(struct UserInfo *users, int count) {
    printf("User Information:\n");
    if (count == 0) {
        printf("No user information available.\n");
    } else {
        printf("------------------------------------------------------------\n");
        printf("| %-20s | %-10s | %-20s | %-8s |\n", "Name", "ID", "Department", "Semester");
        printf("------------------------------------------------------------\n");

        for (int i = 0; i < count; i++) {
            printf("| %-20s | %-10d | %-20s | %-8d |\n", users[i].name, users[i].id, users[i].department, users[i].semester);
        }

        printf("------------------------------------------------------------\n");
    }
}

int main() {
    struct UserInfo *users = NULL;
    int userCount = 0;
    int capacity = 1;

    int choice;
    do {
        printf("1. Add User Information\n");
        printf("2. Display User Information\n");
        printf("3. Undo\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                if (userCount == capacity) {
                    capacity *= 2;
                    users = (struct UserInfo *)realloc(users, capacity * sizeof(struct UserInfo));
                }

                struct UserInfo newUser;
                printf("Enter Name: ");
                scanf("%s", newUser.name);
                printf("Enter ID: ");
                scanf("%d", &newUser.id);
                printf("Enter Department: ");
                scanf("%s", newUser.department);
                printf("Enter Semester: ");
                scanf("%d", &newUser.semester);

                users[userCount] = newUser;
                userCount++;
                printf("User information added successfully.\n");
                break;
            }
            case 2:
                displayUserInfo(users, userCount);
                break;
            case 3:
                if (userCount > 0) {
                    userCount--;
                    printf("Last entry undone.\n");
                } else {
                    printf("No entries to undo.\n");
                }
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    free(users);

    return 0;
}
