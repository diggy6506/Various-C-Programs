#include <stdio.h> 
#include <string.h> 

#define MAX_TASKS 50 
#define MAX_LENGTH 100 

int main(void) {
    char task_list[MAX_TASKS][MAX_LENGTH] = {0}; 
    int menu_selection, delete_task, complete_task; 
    char add_task[50]; 
    int loop; 
    int counter = 0; 

    printf("\nPress Enter to view and edit tasks "); 
    scanf("%*c"); 

    FILE *file_task_list = fopen("tasks.txt", "r"); 
    if(file_task_list != NULL) { 
      while (fgets(task_list[counter], MAX_LENGTH, file_task_list) != NULL) { 
        task_list[counter][strcspn(task_list[counter], "\n")] = '\0'; 
      }
      fclose(file_task_list); 
    }

    printf("\nTo-Do List:\n"); 
    for (int i = 0; i < counter; ++i) { 
        if (task_list[i][0] != '\0') { 
            printf("\n%s\n", task_list[i]); 
        }
    }

    while (loop != EOF) { 
        printf("\n(1) Add Task\n(2) Delete Task\n(3) Mark Task as Complete\n(4) Exit\n\nEnter Option Here: "); 
        scanf("%d", &menu_selection); 
        
        while (getchar() != '\n'); 

        switch (menu_selection) { 
            case 1:
                printf("Enter New Task: "); 
                fgets(task_list[counter], sizeof(task_list[0]), stdin); 
                counter++; 

                FILE *file_task_list = fopen("tasks.txt", "w"); 
                if (file_task_list != NULL) { 
                for (int i = 0; i < counter; ++i) { 
                    fprintf(file_task_list, "%s\n", task_list[i]); 
                }
                fclose(file_task_list); 
                }
                
                printf("\nTo-Do List:\n\n"); 
                for(int i = 0; i < counter; ++i) { 
                  if(task_list[i][0] != '\0') { 
                    printf("%s\n", task_list[i]); 
                  }
                }

                break;
            case 2:
                scanf("%d", &delete_task);
                break;
            case 3:
                scanf("%d", &complete_task);
                break;
            case 4:
                return 1;
        }
    }

    return 0;
}
