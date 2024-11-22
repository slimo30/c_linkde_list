#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include "rlutil.h"

#define MAX_DESCRIPTION_LENGTH 100
#define MAX_STATUS_LENGTH 15
#define MIN_PRIORITY 1
#undef MAX_PRIORITY
#define MAX_PRIORITY 5
#define SCREEN_WIDTH 80

typedef struct TaskNode {
    int task_id;
    char description[MAX_DESCRIPTION_LENGTH];
    int priority;
    char status[MAX_STATUS_LENGTH];
    struct TaskNode* next;
} TaskNode;

static TaskNode* task_list_head = NULL;


void add_task(void);
void delete_task(void);
void update_task_status(void);
void display_tasks(void);
void search_tasks_by_priority(void);
void navigate_main_menu(void);
void free_task_list(void);
void clear_screen(void);
int read_integer_input(const char* prompt, int min_value, int max_value);
void read_string_input(const char* prompt, char* output, size_t max_length);
void verify_and_normalize_status(char* status);
int is_task_id_unique(int task_id);

void clear_screen(void) {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int read_integer_input(const char* prompt, int min_value, int max_value) {
    int input;
    char buffer[20];
    
    while (1) {
        printf("%s", prompt);
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("Invalid input. Please try again.\n");
            continue;
        }
        
        buffer[strcspn(buffer, "\n")] = 0;
        
        char* endptr;
        long parsed_value = strtol(buffer, &endptr, 10);
        
        if (*endptr != '\0') {
            printf("Invalid input. Please enter a numeric value.\n");
            continue;
        }
        
        input = (int)parsed_value;
        
        if (input < min_value || input > max_value) {
            printf("Input must be between %d and %d.\n", min_value, max_value);
            continue;
        }
        
        return input;
    }
}

void read_string_input(const char* prompt, char* output, size_t max_length) {
    while (1) {
        printf("%s", prompt);
        
        if (fgets(output, max_length, stdin) == NULL) {
            printf("Input error. Please try again.\n");
            continue;
        }
        
        output[strcspn(output, "\n")] = 0;
        
        if (strlen(output) == 0) {
            printf("Input cannot be empty. Please try again.\n");
            continue;
        }
        
        char* start = output;
        char* end = output + strlen(output) - 1;
        
        while (isspace(*start)) start++;
        while (end > start && isspace(*end)) end--;
        
        *(end + 1) = '\0';
        
        if (start != output) {
            memmove(output, start, end - start + 2);
        }
        
        break;
    }
}

void verify_and_normalize_status(char* status) {
    char input;
    while (1) {
        printf("Enter Status (C for Completed, P for Pending, I for In Progress): ");
        input = getchar();
        while (getchar() != '\n');

        input = toupper(input);

        if (input == 'C') {
            strcpy(status, "Completed");
            break;
        } else if (input == 'P') {
            strcpy(status, "Pending");
            break;
        } else if (input == 'I') {
            strcpy(status, "In Progress");
            break;
        } else {
            printf("Invalid input. Please enter 'C', 'P', or 'I'.\n");
        }
    }
}

int is_task_id_unique(int task_id) {
    TaskNode* current = task_list_head;
    while (current) {
        if (current->task_id == task_id) {
            return 0; 
        }
        current = current->next;
    }
    return 1; 
}

void display_tasks(void) {
    clear_screen();
    printf("%-*s\n", SCREEN_WIDTH, "Task List");

    if (!task_list_head) {
        printf("No tasks available.\n");
        getchar();
        return;
    }

    TaskNode* current = task_list_head;
    printf("%-5s %-40s %-10s %-15s\n", "ID", "Description", "Priority", "Status");
    printf("%-*s\n", SCREEN_WIDTH, "------------------------------------------------------------");

    while (current) {
        printf("%-5d %-40s %-10d %-15s\n", 
               current->task_id, current->description, 
               current->priority, current->status);
        current = current->next;
    }
    
    getchar();
}

void update_task_status(void) {
    clear_screen();
    printf("%-*s\n", SCREEN_WIDTH, "Update Task Status");

    if (!task_list_head) {
        printf("No tasks available.\n");
        getchar();
        return;
    }

    int task_id = read_integer_input(
        "Enter Task ID to update: ", 
        1, 
        INT_MAX
    );

    TaskNode* current = task_list_head;
    while (current && current->task_id != task_id) {
        current = current->next;
    }

    if (!current) {
        printf("Task not found!\n");
    } else {
        char old_status[MAX_STATUS_LENGTH];
        strcpy(old_status, current->status);
        verify_and_normalize_status(current->status);
        printf("Status updated from %s to %s\n", old_status, current->status);
    }
    getchar();
}

void add_task(void) {
    clear_screen();
    printf("%-*s\n", SCREEN_WIDTH, "Add a New Task");

    TaskNode* new_task = malloc(sizeof(TaskNode));
    if (!new_task) {
        printf("Memory allocation failed!\n");
        getchar();
        return;
    }

    do {
        new_task->task_id = read_integer_input(
            "Enter Task ID: ", 
            1, 
            INT_MAX
        );
        
        if (!is_task_id_unique(new_task->task_id)) {
            printf("ID already exists! Please enter a new ID.\n");
        }
    } while (!is_task_id_unique(new_task->task_id));

    read_string_input(
        "Enter Task Description: ", 
        new_task->description, 
        sizeof(new_task->description)
    );

    new_task->priority = read_integer_input(
        "Enter Priority (1-5): ", 
        MIN_PRIORITY, 
        MAX_PRIORITY
    );

    verify_and_normalize_status(new_task->status);

    new_task->next = NULL;
    if (!task_list_head || task_list_head->priority < new_task->priority) {
        new_task->next = task_list_head;
        task_list_head = new_task;
    } else {
        TaskNode* current = task_list_head;
        while (current->next && current->next->priority >= new_task->priority) {
            current = current->next;
        }
        new_task->next = current->next;
        current->next = new_task;
    }

    printf("Task added successfully!\n");
    getchar();
}

void delete_task(void) {
    clear_screen();
    printf("%-*s\n", SCREEN_WIDTH, "Delete a Task");

    if (!task_list_head) {
        printf("No tasks to delete.\n");
        getchar();
        return;
    }

    int task_id = read_integer_input(
        "Enter Task ID to delete: ", 
        1, 
        INT_MAX
    );

    TaskNode* current = task_list_head;
    TaskNode* previous = NULL;

    while (current && current->task_id != task_id) {
        previous = current;
        current = current->next;
    }

    if (!current) {
        printf("Task not found!\n");
    } else {
        if (!previous) {
            task_list_head = current->next;
        } else {
            previous->next = current->next;
        }
        free(current);
        printf("Task deleted successfully!\n");
    }
    getchar();
}

void search_tasks_by_priority(void) {
    clear_screen();
    printf("%-*s\n", SCREEN_WIDTH, "Search Tasks by Priority");

    if (!task_list_head) {
        printf("No tasks available.\n");
        getchar();
        return;
    }

    int priority = read_integer_input(
        "Enter Priority (1-5) to search for: ", 
        MIN_PRIORITY, 
        MAX_PRIORITY
    );

    TaskNode* current = task_list_head;
    int found = 0;
    while (current) {
        if (current->priority == priority) {
            printf("ID: %d | Description: %s | Priority: %d | Status: %s\n",
                   current->task_id, current->description, 
                   current->priority, current->status);
            found = 1;
        }
        current = current->next;
    }

    if (!found) {
        printf("No tasks found with the given priority.\n");
    }
    getchar();
}

void free_task_list(void) {
    TaskNode* current = task_list_head;
    while (current) {
        TaskNode* temp = current;
        current = current->next;
        free(temp);
    }
    task_list_head = NULL;
}

void navigate_main_menu(void) {
    const char* menu_options[] = {
        "Add Task", 
        "Delete Task", 
        "Update Status", 
        "Display Tasks", 
        "Search by Priority", 
        "Exit"
    };
    int num_options = sizeof(menu_options) / sizeof(menu_options[0]);
    int selected_option = 0;

    while (1) {
        clear_screen();
        printf("%-*s\n\n", SCREEN_WIDTH, "Task Management System");

        for (int i = 0; i < num_options; i++) {
            if (i == selected_option) {
                setColor(YELLOW);
                printf("-> %s\n", menu_options[i]);
                setColor(WHITE);
            } else {
                printf("   %s\n", menu_options[i]);
            }
        }

        printf("\nUse UP/DOWN to navigate, ENTER to select");

        int key = getkey();
        switch (key) {
            case KEY_UP: 
                selected_option = (selected_option > 0) ? selected_option - 1 : num_options - 1;
                break;
            case KEY_DOWN: 
                selected_option = (selected_option < num_options - 1) ? selected_option + 1 : 0;
                break;
            case KEY_ENTER:
                switch (selected_option) {
                    case 0: add_task(); break;
                    case 1: delete_task(); break;
                    case 2: update_task_status(); break;
                    case 3: display_tasks(); break;
                    case 4: search_tasks_by_priority(); break;
                    case 5: 
                        free_task_list();
                        exit(0);
                }
                break;
        }
    }
}

int main(void) {
    navigate_main_menu();
    return 0;
}