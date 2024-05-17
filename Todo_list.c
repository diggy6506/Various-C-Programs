#include <stdio.h>
#include <string.h>

#define MAX_TASKS 50
#define MAX_LENGTH 100

int main(void) {
    char task_list[MAX_TASKS][MAX_LENGTH] = {0};
    int menu_selection, delete_task, complete_task;
    char add_task[50];
    int loop = 1;
    int counter = 0;

    printf("\nPress Enter to View and Edit Tasks ");
    getchar();

    FILE *file_task_list = fopen("tasks.txt", "r");
    if (file_task_list != NULL) {
        while (fgets(task_list[counter], MAX_LENGTH, file_task_list) != NULL) {
            task_list[counter][strcspn(task_list[counter], "\n")] = '\0';
            counter++;
        }
        fclose(file_task_list);
    }

    while (loop) {
        printf("\nTo-Do List:\n");
        int task_counter = 1;
        for (int i = 0; i < counter; ++i) {
            if (task_list[i][0] != '\0') {
                printf("%d. %s\n", i + 1, task_list[i]);
            }
        }

        printf("\n(1) Add Task\n(2) Delete Task\n(3) Mark Task as Complete\n(4) Exit\n\nEnter Option Here: ");
        scanf("%d", &menu_selection);

        while (getchar() != '\n');

        switch (menu_selection) {
            case 1:
                if (counter < MAX_TASKS) {
                    printf("Enter New Task: ");
                    fgets(task_list[counter], sizeof(task_list[0]), stdin);
                    task_list[counter][strcspn(task_list[counter], "\n")] = '\0';
                    counter++;
                } else {
                    printf("Task List is Full!\n");
                }
                break;

            case 2:
                printf("Enter the Task Number to Delete: ");
                scanf("%d", &delete_task);
                while (getchar() != '\n');

                if (delete_task > 0 && delete_task <= counter) {
                    for (int i = delete_task - 1; i < counter - 1; ++i) {
                        strcpy(task_list[i], task_list[i + 1]);
                    }
                    counter--;
                    printf("Task %d Deleted\n", delete_task);
                } else {
                    printf("Invalid Task Number\n");
                }
                break;

            case 3:
                printf("Enter the Task Number To Mark as Complete: ");
                scanf("%d", &complete_task);
                while (getchar() != '\n');

                if (complete_task > 0 && complete_task <= counter) {
                    strcat(task_list[complete_task - 1], " [Completed]");
                    printf("Task %d Marked as Complete\n", complete_task);
                } else {
                    printf("Invalid Task Number\n");
                }
                break;

            case 4:
                return 1;
        }

        FILE *file_task_list = fopen("tasks.txt", "w");
        if (file_task_list != NULL) {
            for (int i = 0; i < counter; ++i) {
                fprintf(file_task_list, "%s\n", task_list[i]);
            }
            fclose(file_task_list);
        }
    }
    return 0;
}
