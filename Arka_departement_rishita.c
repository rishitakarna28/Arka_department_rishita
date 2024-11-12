//DAA FINALLL
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    int id;
    int school_id;
    char dept_code[10];
    char dept_name[50];
    char dept_location[50];
    char dept_email[50];
} Department;

Department departments[MAX];
int department_count = 0;

const char* FILE_NAME = "department_data.txt";

// Function declarations
void arka_department_create();
void arka_department_update();
void arka_department_retrieve();
void arka_department_delete();
void arka_department_storing();
void arka_department_insertion_sorting(int sort_option);
void arka_department_linear_searching();
void arka_department_Compare_Search_algorithm_linear();
void arka_department_Compare_Sorting_algorithm_insertion(int sort_option);
void arka_department_complexity_searching();
void arka_department_complexity_sorting();
void arka_department_linear_search_details();
void arka_department_insertion_sorting_details();

void load_from_file() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        return; // No file exists yet, no data to load
    }

    department_count = 0;
    while (fscanf(file, "%d %d %s %s %s %s\n", 
                  &departments[department_count].id,
                  &departments[department_count].school_id,
                  departments[department_count].dept_code,
                  departments[department_count].dept_name,
                  departments[department_count].dept_location,
                  departments[department_count].dept_email) != EOF) {
        department_count++;
    }
    fclose(file);
}

void arka_department_storing() {
    FILE *file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }
    for (int i = 0; i < department_count; i++) {
        fprintf(file, "%d %d %s %s %s %s\n", departments[i].id, departments[i].school_id,
                departments[i].dept_code, departments[i].dept_name,
                departments[i].dept_location, departments[i].dept_email);
    }
    fclose(file);
}

void arka_department_create() {
    if (department_count >= MAX) {
        printf("Department list is full!\n");
        return;
    }
    
    Department d;
    printf("Enter Department ID: ");
    scanf("%d", &d.id);
    printf("Enter School ID: ");
    scanf("%d", &d.school_id);
    printf("Enter Department Code: ");
    scanf("%s", d.dept_code);
    printf("Enter Department Name: ");
    scanf("%s", d.dept_name);
    printf("Enter Department Location: ");
    scanf("%s", d.dept_location);
    printf("Enter Department Email: ");
    scanf("%s", d.dept_email);

    departments[department_count++] = d;
    arka_department_storing();
    printf("Department created successfully!\n");
}

void arka_department_update() {
    int id;
    printf("Enter Department ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < department_count; i++) {
        if (departments[i].id == id) {
            printf("Enter new School ID: ");
            scanf("%d", &departments[i].school_id);
            printf("Enter new Department Code: ");
            scanf("%s", departments[i].dept_code);
            printf("Enter new Department Name: ");
            scanf("%s", departments[i].dept_name);
            printf("Enter new Department Location: ");
            scanf("%s", departments[i].dept_location);
            printf("Enter new Department Email: ");
            scanf("%s", departments[i].dept_email);

            arka_department_storing();
            printf("Department updated successfully!\n");
            return;
        }
    }
    printf("Department with ID %d not found.\n", id);
}

void arka_department_retrieve() {
    printf("\nList of Departments:\n");
    for (int i = 0; i < department_count; i++) {
        printf("ID: %d\nSchool ID: %d\nCode: %s\nName: %s\nLocation: %s\nEmail: %s\n\n",
               departments[i].id, departments[i].school_id,
               departments[i].dept_code, departments[i].dept_name,
               departments[i].dept_location, departments[i].dept_email);
    }
}

void arka_department_delete() {
    int id;
    printf("Enter Department ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < department_count; i++) {
        if (departments[i].id == id) {
            for (int j = i; j < department_count - 1; j++) {
                departments[j] = departments[j + 1];
            }
            department_count--;
            arka_department_storing();
            printf("Department deleted successfully!\n");
            return;
        }
    }
    printf("Department with ID %d not found.\n", id);
}

void arka_department_linear_searching() {
    int option;
    char search_term[50];

    printf("Search by:\n1. Department Code\n2. Department Name\nEnter choice: ");
    scanf("%d", &option);

    switch (option) {
        case 1:
            printf("Enter Department Code to search: ");
            scanf("%s", search_term);
            for (int i = 0; i < department_count; i++) {
                if (strcmp(departments[i].dept_code, search_term) == 0) {
                    printf("\nDepartment Found:\n");
                    printf("ID: %d\n", departments[i].id);
                    printf("School ID: %d\n", departments[i].school_id);
                    printf("Code: %s\n", departments[i].dept_code);
                    printf("Name: %s\n", departments[i].dept_name);
                    printf("Location: %s\n", departments[i].dept_location);
                    printf("Email: %s\n\n", departments[i].dept_email);
                    return;
                }
            }
            printf("Department with code '%s' not found.\n", search_term);
            break;

        case 2:
            printf("Enter Department Name to search: ");
            scanf("%s", search_term);
            for (int i = 0; i < department_count; i++) {
                if (strcmp(departments[i].dept_name, search_term) == 0) {
                    printf("\nDepartment Found:\n");
                    printf("ID: %d\n", departments[i].id);
                    printf("School ID: %d\n", departments[i].school_id);
                    printf("Code: %s\n", departments[i].dept_code);
                    printf("Name: %s\n", departments[i].dept_name);
                    printf("Location: %s\n", departments[i].dept_location);
                    printf("Email: %s\n\n", departments[i].dept_email);
                    return;
                }
            }
            printf("Department with name '%s' not found.\n", search_term);
            break;

        default:
            printf("Invalid search option!\n");
    }
}

void arka_department_insertion_sorting(int sort_option) {
    for (int i = 1; i < department_count; i++) {
        Department key = departments[i];
        int j = i - 1;

        while (j >= 0) {
            int compare = 0;
            switch (sort_option) {
                case 1:
                    compare = strcmp(departments[j].dept_code, key.dept_code);
                    break;
                case 2: 
                    compare = strcmp(departments[j].dept_name, key.dept_name);
                    break;
                case 3: 
                    compare = strcmp(departments[j].dept_email, key.dept_email);
                    break;
            }

            if (compare > 0) {
                departments[j + 1] = departments[j];
                j--;
            } else {
                break;
            }
        }
        departments[j + 1] = key;
    }
    printf("Departments sorted!\n");
    arka_department_retrieve();
}

void arka_department_Compare_Search_algorithm_linear() {
for (int i = 1; i < department_count; i++) {
        Department key = departments[i];
        int j = i - 1;

        while (j >= 0) {
            int compare = 0;
             compare = strcmp(departments[j].dept_code, key.dept_code);

                if (compare > 0) {
                departments[j + 1] = departments[j];
                j--;
            } else {
                break;
            }
        }
        departments[j + 1] = key;
     }

    char search_code[10];
    printf("Enter Department Code to search: ");
    scanf("%s", search_code);

    int left = 0, right = department_count - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int compare = strcmp(departments[mid].dept_code, search_code);

        if (compare == 0) {
            // Department found
            printf("\nDepartment Found:\n");
            printf("ID: %d\n", departments[mid].id);
            printf("School ID: %d\n", departments[mid].school_id);
            printf("Code: %s\n", departments[mid].dept_code);
            printf("Name: %s\n", departments[mid].dept_name);
            printf("Location: %s\n", departments[mid].dept_location);
            printf("Email: %s\n\n", departments[mid].dept_email);
            return;
        } else if (compare < 0) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }
    printf("Department with code '%s' not found.\n", search_code);
}

void arka_department_Compare_Sorting_algorithm_insertion(int sort_option) {
    //Comparing by selection sorting
    for (int i = 0; i < department_count - 1; i++) {
        int min_idx = i;

        for (int j = i + 1; j < department_count; j++) {
            int compare = 0;

            switch (sort_option) {
                case 1: // Sort by dept_code
                    compare = strcmp(departments[j].dept_code, departments[min_idx].dept_code);
                    break;
                case 2: // Sort by dept_name
                    compare = strcmp(departments[j].dept_name, departments[min_idx].dept_name);
                    break;
                case 3: // Sort by dept_email
                    compare = strcmp(departments[j].dept_email, departments[min_idx].dept_email);
                    break;
            }

            if (compare < 0) {
                min_idx = j;
            }
        }

        // Swap the found minimum element with the first element
        if (min_idx != i) {
            Department temp = departments[i];
            departments[i] = departments[min_idx];
            departments[min_idx] = temp;
        }
    }

    printf("Departments sorted!\n");
    arka_department_retrieve();
}

void arka_department_complexity_sorting() {
    printf("Time Complexity Analysis:\n");
    printf("Insertion Sort: O(n^2)\n");
    printf("Selection Sort: O(n^2)\n");
}

void arka_department_complexity_searching() {
    printf("Time Complexity Analysis:\n");
    printf("Linear Search: O(n)\n");
    printf("Binary Search: O(log n)\n");
}

void arka_department_linear_search_details() {
    printf("Pseudocode for Linear Search:\n");
    printf("For each department in departments:\n");
    printf("1. If department.dept_code matches the search_code:\n");
    printf("- Print the department details.\n - Return Department Found.\n");
    printf("2. If the end of the departments array is reached without finding a match:\n");
    printf("- Print Department not found.\n\n");
    
    printf("Pseudocode for Binary Search:\n");
    printf("1. Initialize left to 0 and right to department_count - 1.\n");
    printf("2. While left is less than or equal to right:\n");
    printf("   a. Set middle to (left + right) / 2.\n");
    printf("   b. If departments[middle].dept_code matches search_code:\n");
    printf("      - Print the department details.\n");
    printf("      - Return \"Department Found.\"\n");
    printf("   c. If departments[middle].dept_code is less than search_code:\n");
    printf("      - Set left to middle + 1.\n");
    printf("   d. Else (if departments[middle].dept_code is greater than search_code):\n");
    printf("      - Set right to middle - 1.\n");
    printf("3. If no match is found after exiting the loop:\n");
    printf("   - Print \"Department not found.\"\n");
}

void arka_department_insertion_sorting_details() {
    printf("Pseudocode for Insertion Sort:\n");
    printf("1. For i from 1 to department_count - 1:\n");
    printf("   a. Set current to departments[i].\n");
    printf("   b. Set j to i - 1.\n");
    printf("   c. While j >= 0 and departments[j].dept_code is greater than current.dept_code:\n");
    printf("      - Shift departments[j] to departments[j + 1].\n");
    printf("      - Decrement j by 1.\n");
    printf("   d. Place current at departments[j + 1].\n");
    printf("2. The departments array is now sorted by dept_code.\n");
    printf("Pseudocode for Selection Sort:\n");
    printf("1. For i from 0 to department_count - 2:\n");
    printf("   a. Set min_index to i.\n");
    printf("   b. For j from i + 1 to department_count - 1:\n");
    printf("      - If departments[j].dept_code is less than departments[min_index].dept_code:\n");
    printf("         - Set min_index to j.\n");
    printf("   c. If min_index is not i:\n");
    printf("      - Swap departments[i] with departments[min_index].\n");
    printf("2. The departments array is now sorted by dept_code.\n");

}

int main() {
    load_from_file();
    printf("*DEPARTMENT MANAGEMENT*\n");
    printf("Choose your option\n");
    
    while(1) {
        printf("1. Create New department\n");
        printf("2. Update department\n");
        printf("3. Retrieve department details\n");
        printf("4. Delete department details\n");
        printf("5. Sort departments by dept_code, dept_name, dept_email\n");
        printf("6. Search departments by dept_code or dept_name\n");
        printf("7. Store department details\n");
        printf("8. Comparison of search algorithms (binary search)\n");
        printf("9. Comparison of sorting algorithms (selection sort)\n");
        printf("10. Time Complexity of sorting algorithms\n");
        printf("11. Time Complexity of searching algorithms\n");
        printf("12. Display linear search algorithm details\n");
        printf("13. Display sorting algorithm details\n");
        printf("14. Exit application\n");
        printf("Please select the option: ");
        
        int option;
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                arka_department_create();
                break;
            case 2:
                arka_department_update();
                break;
            case 3:
                arka_department_retrieve();
                break;
            case 4:
                arka_department_delete();
                break;
            case 5:
                printf("Enter sorting option:\n1. By Department Code\n2. By Department Name\n3. By Department Email\n");
                int sort_option;
                scanf("%d", &sort_option);
                arka_department_insertion_sorting(sort_option);
                break;
            case 6:
                arka_department_linear_searching();
                break;
            case 7:
                arka_department_storing();
                break;
            case 8:
                arka_department_Compare_Search_algorithm_linear();
                break;
            case 9:
                arka_department_Compare_Sorting_algorithm_insertion(1);
                break;
            case 10:
                arka_department_complexity_sorting();
                break;
            case 11:
                arka_department_complexity_searching();
                break;
            case 12:
                arka_department_linear_search_details();
                break;
            case 13:
                arka_department_insertion_sorting_details();
                break;
            case 14:
                exit(0); // Exit the program
            default:
                printf("Please select a valid option.\n");
        }
    }

    return 0;
}