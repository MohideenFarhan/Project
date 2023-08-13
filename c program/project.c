#include <stdio.h>
#include <string.h>

#define MAX_TASKS 10
#define MAX_LENGTH 50

void printMenu() {
    printf("\n=== To-Do List Application ===\n");
    printf("1. Add Task\n");
    printf("2. Remove Task\n");
    printf("3. View Tasks\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    char tasks[MAX_TASKS][MAX_LENGTH];
    int numTasks = 0;
    int choice;

    while (1) {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (numTasks < MAX_TASKS) {
                    printf("Enter task: ");
                    scanf(" %[^\n]", tasks[numTasks]);
                    numTasks++;
                } else {
                    printf("Task list is full!\n");
                }
                break;

            case 2:
                if (numTasks > 0) {
                    printf("Tasks:\n");
                    for (int i = 0; i < numTasks; i++) {
                        printf("%d. %s\n", i + 1, tasks[i]);
                    }
                    int taskIndex;
                    printf("Enter the task number to remove: ");
                    scanf("%d", &taskIndex);

                    if (taskIndex >= 1 && taskIndex <= numTasks) {
                        for (int i = taskIndex - 1; i < numTasks - 1; i++) {
                            strcpy(tasks[i], tasks[i + 1]);
                        }
                        numTasks--;
                        printf("Task removed.\n");
                    } else {
                        printf("Invalid task number!\n");
                    }
                } else {
                    printf("No tasks to remove!\n");
                }
                break;

            case 3:
                if (numTasks > 0) {
                    printf("Tasks:\n");
                    for (int i = 0; i < numTasks; i++) {
                        printf("%d. %s\n", i + 1, tasks[i]);
                    }
                } else {
                    printf("No tasks to display!\n");
                }
                break;

            case 4:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    }

    return 0;
}