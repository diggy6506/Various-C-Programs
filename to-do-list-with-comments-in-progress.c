
#include <stdio.h> // Calls stdio library
#include <string.h> // Calls string library

#define MAX_TASKS 50 // Macro for amount of array elements on y axis
#define MAX_LENGTH 100 // Macro for amount of array elements on x axis

int main(void) {
    char task_list[MAX_TASKS][MAX_LENGTH] = {0}; // Array storing todo list, {0} ensures all unused elements are empty
    int menu_selection, delete_task, complete_task; // main_menu variable for storing users selecred menu option, delete and complete are menu options
    char add_task[50]; //variable that stores task user wants to add to list
    int loop; // value != EOF, allowing user to remain in menu until manual exit
    int counter = 0; //value that tracks which task is being read or edited

    printf("\nPress Enter to view and edit tasks "); // Prompts user to start program
    scanf("%*c"); // Takes enter as input to progress program


    // Reads the file while there are still items by checking if the file is empty, if there are any items left to read

    FILE *file_task_list = fopen("tasks.txt", "r"); //opens file containing to-do list array for read
    if(file_task_list != NULL) { // if the file is not empty
      while (fgets(task_list[counter], MAX_LENGTH, file_task_list) != NULL) { // fgets reads from the file while there is still contents
        task_list[counter][strcspn(task_list[counter], "\n")] = '\0'; // replaces any new lines with null terminator(signifies end of string), so fgets doesn't terminate at new line
      }
      fclose(file_task_list); //closes the file when loop has ended
    }

    printf("\nTo-Do List:\n"); // Prints title
    for (int i = 0; i < counter; ++i) { // counts which iteration of the array the loop is on, so the correct loop is printed and the loop ends
        if (task_list[i][0] != '\0') { // ensures printf only runs if the first character of the iteration(i) has contents
            printf("\n%s\n", task_list[i]); // prints the iteration
        }
    }

    while (loop != EOF) { // ensures the user is booted back to menu after each edit to make repated edits. User can exit with selection 4.
        printf("\n(1) Add Task\n(2) Delete Task\n(3) Mark Task as Complete\n(4) Exit\n\nEnter Option Here: "); //prints menu options and asks user for their selection
        scanf("%d", &menu_selection); // allows user to input their selection and stores value in menu_selection
        
        while (getchar() != '\n'); //clears input buffer of new line

        switch (menu_selection) { // switch statement which progresses the user to their chosen selection and runs the editing processes within each case 
            case 1:
                printf("Enter New Task: "); //prompts user to add their new task
                fgets(task_list[counter], sizeof(task_list[0]), stdin); // reads user input and writes to iteration based on how many times while(loop != EOF) has looped
                counter++; //adds to counter with every loop

                FILE *file_task_list = fopen("tasks.txt", "w"); //opens file for write
                if (file_task_list != NULL) { //if the file is not empty
                for (int i = 0; i < counter; ++i) { // keep running until [i] reaches current counter value
                    fprintf(file_task_list, "%s\n", task_list[i]); //print the user input to the file [i] representing which iteration to print 
                }
                fclose(file_task_list); // close the file
                }
                
                printf("\nTo-Do List:\n"); //print the to-do list
                for(int i = 0; i < counter; ++i) { // print each iteration up to counter value
                  if(task_list[i][0] != '\0') { //only print if iteration has contents
                    printf("%s\n", task_list[i]); // print the respective iteration
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
