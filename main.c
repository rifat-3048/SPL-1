#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include <float.h>

// Define the Employee struct
#define Employee struct emp

// Function prototypes
void add(FILE * fp);
FILE * del(FILE * fp);
void modify(FILE * fp);
void displayList(FILE * fp);
void searchRecord(FILE *fp);
void printChar(char ch, int n);
void printHead();
void welcome();
void displaybasic(FILE * fp);
void basiccontact(FILE * fp);
void maleemp(FILE * fp);
void femaleemp(FILE * fp);
void frmdhaka(FILE * fp);
void frmors(FILE * fp);
void mainbr(FILE * fp);
void otherbr(FILE * fp);
void DataAnalysisandStatistics(FILE *fp);

// Define the Employee struct
struct emp {
    int id;
    char name[100];
    char desgn[10];
    float sal;
    char jdate[8];
    char gender[10];
    char branch[50];
    char psaddr[200];
    char prtaddr[200];
    char phone[15];
    char mail[20];
};


// Function to display a welcome message
void welcome() {
    printf("\n\n\n\n\n\t\t[ [ [ WELCOME TO OUR EMPLOYEE MANAGEMENT SYSTEM ] ] ]\n\n\n\n\n\n\n\t");
    system("pause");
}

// Function to print a character ch n times
void printChar(char ch, int n) {
    while (n--) {
        putchar(ch);
    }
}

// Function to print the header
void printHead() {
    system("cls");
    printf("\t");
    printChar('=', 65);
    printf("\n\t");
    printChar('=', 16);
    printf("[EMPLOYEE] [MANAGEMENT] [SYSTEM]");
    printChar('=', 16);
    printf("\n\t");
    printChar('=', 65);
}

// Function to add a new employee record

void add(FILE * fp) {
    printHead();
    printf("\n\t\t\t\tAdd Employee");
    char another = 'y';
    Employee e;
    int siz = sizeof(e);

    fseek(fp, 0, SEEK_END);

    while (another == 'y' || another == 'Y') {
        printf("\n\n\t\tEnter ID number: ");
        scanf("%d", &e.id);
        fflush(stdin);

        printf("\n\n\t\tEnter Full Name of Employee: ");
        fgets(e.name, sizeof(e.name), stdin);
        e.name[strlen(e.name) - 1] = '\0';

        printf("\n\n\t\tEnter Designation: ");
        fgets(e.desgn, sizeof(e.desgn), stdin);
        e.desgn[strlen(e.desgn) - 1] = '\0';

        printf("\n\n\t\tEnter Gender: ");
        fgets(e.gender, sizeof(e.gender), stdin);
        e.gender[strlen(e.gender) - 1] = '\0';

        printf("\n\n\t\tEnter Branch: ");
        fgets(e.branch, sizeof(e.branch), stdin);
        e.branch[strlen(e.branch) - 1] = '\0';

        printf("\n\n\t\tEnter Salary: ");
        scanf("%f", &e.sal);
        fflush(stdin);

        printf("\n\n\t\tEnter Present Address: ");
        fgets(e.psaddr, sizeof(e.psaddr), stdin);
        e.psaddr[strlen(e.psaddr) - 1] = '\0';

        printf("\n\n\t\tEnter Permanent Address: ");
        fgets(e.prtaddr, sizeof(e.prtaddr), stdin);
        e.prtaddr[strlen(e.prtaddr) - 1] = '\0';

        printf("\n\n\t\tEnter Phone: ");
        fgets(e.phone, sizeof(e.phone), stdin);
        e.phone[strlen(e.phone) - 1] = '\0';

        printf("\n\n\t\tEnter E-mail: ");
        fgets(e.mail, sizeof(e.mail), stdin);
        e.mail[strlen(e.mail) - 1] = '\0';

        fwrite(&e, siz, 1, fp);

        printf("\n\n\t\tWant to enter another employee info (Y/N)\t");
        fflush(stdin);
        another = getchar();
    }
}


// Function to delete an employee record
FILE * del(FILE * fp) {
    printHead();
    printf("\n\t\t\t\tDelete Employee");
    Employee e;
    int flag = 0, tempid, siz = sizeof(e);
    FILE * ft;

    if ((ft = fopen("temp.txt", "wb+")) == NULL) {
        printf("\n\n\t\t\t\t!!! ERROR !!!\n\t\t");
        system("pause");
        return fp;
    }

    printf("\n\n\tEnter ID number of Employee to Delete the Record");
    printf("\n\n\t\t\tID No. : ");
    scanf("%d", &tempid);

    rewind(fp);

    while (fread(&e, siz, 1, fp) == 1) {
        if (e.id == tempid) {
            flag = 1;
            printf("\n\tRecord Deleted for");
            printf("\n\n\t\t%s\n\n\t\t%s\n\n\t\t%d\n\t", e.name, e.branch, e.id);
            continue;
        }

        fwrite(&e, siz, 1, ft);
    }

    fclose(fp);
    fclose(ft);

    remove("employeeInfo.txt");
    rename("temp.txt", "employeeInfo.txt");

    if ((fp = fopen("employeeInfo.txt", "rb+")) == NULL) {
        printf("ERROR");
        return NULL;
    }

    if (flag == 0)
        printf("\n\n\t\t!!!! ERROR RECORD NOT FOUND \n\t");

    printChar('-', 65);
    printf("\n\t");
    system("pause");
    return fp;
}


// Function to modify an employee record
void modify(FILE * fp) {
    printHead();
    printf("\n\t\t\t\tModify Employee");
    Employee e;
    int i, flag = 0, tempid, siz = sizeof(e);
    float sal;

    printf("\n\n\tEnter ID Number of Employee to Modify the Record : ");
    scanf("%d", &tempid);

    rewind(fp);

    while (fread(&e, siz, 1, fp) == 1) {
        if (e.id == tempid) {
            flag = 1;
            break;
        }
    }

    if (flag == 1) {
        fseek(fp, -siz, SEEK_CUR);
        printf("\n\n\t\tRecord Found");
        printf("\n\n\t\tEnter New Data for the Record");

        printf("\n\n\t\tEnter ID number: ");
        scanf("%d", &e.id);
        fflush(stdin);

        printf("\n\n\t\tEnter Full Name of Employee: ");
        fgets(e.name, sizeof(e.name), stdin);
        e.name[strlen(e.name) - 1] = '\0';

        printf("\n\n\t\tEnter Designation: ");
        fgets(e.desgn, sizeof(e.desgn), stdin);
        e.desgn[strlen(e.desgn) - 1] = '\0';

        printf("\n\n\t\tEnter Gender: ");
        fgets(e.gender, sizeof(e.gender), stdin);
        e.gender[strlen(e.gender) - 1] = '\0';

        printf("\n\n\t\tEnter Branch: ");
        fgets(e.branch, sizeof(e.branch), stdin);
        e.branch[strlen(e.branch) - 1] = '\0';

        printf("\n\n\t\tEnter Salary: ");
        scanf("%f", &e.sal);
        fflush(stdin);

        printf("\n\n\t\tEnter Present Address: ");
        fgets(e.psaddr, sizeof(e.psaddr), stdin);
        e.psaddr[strlen(e.psaddr) - 1] = '\0';

        printf("\n\n\t\tEnter Permanent Address: ");
        fgets(e.prtaddr, sizeof(e.prtaddr), stdin);
        e.prtaddr[strlen(e.prtaddr) - 1] = '\0';

        printf("\n\n\t\tEnter Phone: ");
        fgets(e.phone, sizeof(e.phone), stdin);
        e.phone[strlen(e.phone) - 1] = '\0';

        printf("\n\n\t\tEnter E-mail: ");
        fgets(e.mail, sizeof(e.mail), stdin);
        e.mail[strlen(e.mail) - 1] = '\0';

        fwrite(&e, sizeof(e), 1, fp);
    } else {
        printf("\n\n\t!!!! ERROR !!!! RECORD NOT FOUND");
    }

    printf("\n\n\t");
    system("pause");
}


// Function to display the list of employees
void displayList(FILE * fp) {
    printHead();
    printf("\n\t\t\t\tList of Employees");
    Employee e;
    int i, siz = sizeof(e);

    rewind(fp);

    while (fread(&e, siz, 1, fp) == 1) {
        printf("\n\n\t\tID : %d", e.id);
        printf("\n\n\t\tNAME : %s", e.name);
        printf("\n\n\t\tDESIGNATION : %s", e.desgn);
        printf("\n\n\t\tGENDER : %s", e.gender);
        printf("\n\n\t\tBRANCH : %s", e.branch);
        printf("\n\n\t\tSALARY : %.2f", e.sal);
        printf("\n\n\t\tPRESENT ADDRESS : %s", e.psaddr);
        printf("\n\n\t\tPERMANENT ADDRESS : %s", e.prtaddr);
        printf("\n\n\t\tPHONE : %s", e.phone);
        printf("\n\n\t\tE-MAIL : %s\n\n\t", e.mail);
        printChar('=', 65);
    }
    printf("\n\n\n\t");
    printf("\n\n\t");
    system("pause");
}

// Function to search for an employee record
void searchRecord(FILE *fp) {
    printHead();
    printf("\n\t\t\t\tSearch Employee");
    int tempid, flag, siz, i;
    Employee e;
    char another = 'y';

    siz = sizeof(e);

    while (another == 'y' || another == 'Y') {
        printf("\n\n\tEnter ID Number of Employee to search the record : ");
        scanf("%d", &tempid);

        rewind(fp);

        while (fread(&e, siz, 1, fp) == 1) {
            if (e.id == tempid) {
                flag = 1;
                break;
            }
        }

        if (flag == 1) {
            printf("\n\t\tNAME : %s", e.name);
            printf("\n\n\t\tID : %d", e.id);
            printf("\n\n\t\tDESIGNATION : %s", e.desgn);
            printf("\n\n\t\tBRANCH : %s", e.branch);
            printf("\n\n\t\tSALARY: %.2f", e.sal);
            printf("\n\n\t\tPRESENT ADDRESS : %s", e.psaddr);
            printf("\n\n\t\tPERMANENT ADDRESS : %s", e.prtaddr);
            printf("\n\n\t\tPHONE : %s", e.phone);
            printf("\n\n\t\tE-MAIL : %s", e.mail);

            printChar('=', 65);
        } else {
            printf("\n\n\t!!!! ERROR RECORD NOT FOUND !!!!");
        }

        printf("\n\n\tWant to enter another search (Y/N)");
        fflush(stdin);
        another = getchar();
    }
    printf("\n\n\t");
    system("pause");
}


// Function to display basic information of employees
void displaybasic(FILE * fp) {
    printHead();
    printf("\n\t\t\t\tDisplay Basic Information");
    Employee e;
    int i, siz = sizeof(e);

    rewind(fp);

    while (fread(&e, siz, 1, fp) == 1) {
        printf("\n\n\t\tID : %d", e.id);
        printf("\n\n\t\tNAME : %s", e.name);
        printf("\n\n\t\tDESIGNATION : %s", e.desgn);
        printf("\n\n\t\tGENDER : %s", e.gender);
        printf("\n\n\t\tBRANCH : %s", e.branch);
        printf("\n\n\t\tPHONE : %s", e.phone);
        printf("\n\n\t\tE-MAIL : %s\n\n\t", e.mail);
        printChar('=', 65);
    }
    printf("\n\n\n\t");
    printf("\n\n\t");
    system("pause");
}


// Function to display basic contact information of employees
void basiccontact(FILE * fp) {
    printHead();
    printf("\n\t\t\t\tBasic Contact Information");
    Employee e;
    int i, siz = sizeof(e);

    rewind(fp);

    while (fread(&e, siz, 1, fp) == 1) {
        printf("\n\n\t\tID : %d", e.id);
        printf("\n\n\t\tNAME : %s", e.name);
        printf("\n\n\t\tDESIGNATION : %s", e.desgn);
        printf("\n\n\t\tPHONE : %s", e.phone);
        printf("\n\n\t\tE-MAIL : %s\n\n\t", e.mail);
        printChar('=', 65);
    }
    printf("\n\n\n\t");
    printf("\n\n\t");
    system("pause");
}

// Function to list male employees
void maleemp(FILE * fp) {
    printHead();
    printf("\n\t\t\t\tList of Male Employee");
    Employee e;
    int i, siz = sizeof(e);

    rewind(fp);

    while (fread(&e, siz, 1, fp) == 1) {
        if (strcasecmp(e.gender, "Male") == 0 || strcasecmp(e.gender, "male") == 0) {
            printf("\n\n\t\tID : %d", e.id);
            printf("\n\n\t\tNAME : %s", e.name);
            printf("\n\n\t\tDESIGNATION : %s", e.desgn);
            printf("\n\n\t\tPHONE : %s", e.phone);
            printChar('-', 65);
        }
    }
    printf("\n\n\n\t");
    printChar('*', 65);
    printf("\n\n\t");
    system("pause");
}

// Function to list female employees
void femaleemp(FILE * fp) {
    printHead();
    printf("\n\t\t\t\tList of Female Employee");
    Employee e;
    int i, siz = sizeof(e);

    rewind(fp);

    while (fread(&e, siz, 1, fp) == 1) {
        if (strcasecmp(e.gender, "Female") == 0 || strcasecmp(e.gender, "female") == 0) {
            printf("\n\n\t\tID : %d", e.id);
            printf("\n\n\t\tNAME : %s", e.name);
            printf("\n\n\t\tDESIGNATION : %s", e.desgn);
            printf("\n\n\t\tPHONE : %s", e.phone);
            printChar('-', 65);
        }
    }
    printf("\n\n\n\t");
    printChar('*', 65);
    printf("\n\n\t");
    system("pause");
}

// Function to list employees from Dhaka
void frmdhaka(FILE * fp) {
    printHead();
    printf("\n\t\t\t\tList of Employees From Dhaka");
    Employee e;
    int i, siz = sizeof(e);

    rewind(fp);

    while (fread(&e, siz, 1, fp) == 1) {
        if (strstr(e.prtaddr, "Dhaka") || strstr(e.prtaddr, "dhaka") || strstr(e.prtaddr, "DHAKA")) {
            printf("\n\n\t\tID : %d", e.id);
            printf("\n\n\t\tNAME : %s", e.name);
            printf("\n\n\t\tDESIGNATION : %s", e.desgn);
            printf("\n\n\t\tPHONE : %s", e.phone);
            printf("\n\n\t\tE-MAIL : %s", e.mail);
            printChar('=', 65);
        }
    }
    printf("\n\n\n\t");
    printf("\n\n\t");
    system("pause");
}

// Function to list employees from other districts
void frmors(FILE * fp) {
    printHead();
    printf("\n\t\t\t\tList of Employees From Other Districts");
    Employee e;
    int i, siz = sizeof(e);

    rewind(fp);

    while (fread(&e, siz, 1, fp) == 1) {
        if (!(strstr(e.prtaddr, "Dhaka") || strstr(e.prtaddr, "dhaka") || strstr(e.prtaddr, "DHAKA"))) {
            printf("\n\n\t\tID : %d", e.id);
            printf("\n\n\t\tNAME : %s", e.name);
            printf("\n\n\t\tDESIGNATION : %s", e.desgn);
            printf("\n\n\t\tPHONE : %s", e.phone);
            printf("\n\n\t\tE-MAIL : %s", e.mail);
            printChar('=', 65);
        }
    }
    printf("\n\n\n\t");
    printf("\n\n\t");
    system("pause");
}


// Function to list employees of the main branch
void mainbr(FILE * fp) {
    printHead();
    printf("\n\t\t\t\tList of Employees From Main Branch");
    Employee e;
    int i, siz = sizeof(e);

    rewind(fp);

    while (fread(&e, siz, 1, fp) == 1) {
        if (strcasecmp(e.branch, "Main") == 0 || strcasecmp(e.prtaddr, "main") == 0 || strcasecmp(e.prtaddr, "MAIN") == 0) {
            printf("\n\n\t\tID : %d", e.id);
            printf("\n\n\t\tNAME : %s", e.name);
            printf("\n\n\t\tDESIGNATION : %s", e.desgn);
            printf("\n\n\t\tPHONE : %s", e.phone);
            printf("\n\n\t\tE-MAIL : %s", e.mail);
            printChar('=', 65);
        }
    }
    printf("\n\n\n\t");
    printf("\n\n\t");
    system("pause");
}

// Function to list employees of other branches
void otherbr(FILE * fp) {
    printHead();
    printf("\n\t\t\t\tList of Employees From Other Branches");
    Employee e;
    int i, siz = sizeof(e);

    rewind(fp);

    while (fread(&e, siz, 1, fp) == 1) {
        if (strcasecmp(e.branch, "Main") != 0 && strcasecmp(e.prtaddr, "main") != 0 && strcasecmp(e.prtaddr, "MAIN") != 0) {
            printf("\n\n\t\tID : %d", e.id);
            printf("\n\n\t\tNAME : %s", e.name);
            printf("\n\n\t\tDESIGNATION : %s", e.desgn);
            printf("\n\n\t\tPHONE : %s", e.phone);
            printf("\n\n\t\tE-MAIL : %s", e.mail);
            printChar('=', 65);
        }
    }
    printf("\n\n\n\t");
    printf("\n\n\t");
    system("pause");
}

void DataAnalysisandStatistics(FILE *fp) {
    printHead();
    printf("\n\t\t\t\tData Analysis and Statistics");
    Employee e;
    int siz = sizeof(e);
    int totalEmployees = 0;
    float totalSalary = 0;
    float maxSalary = 0;
    float minSalary = FLT_MAX;

    rewind(fp);

    while (fread(&e, siz, 1, fp) == 1) {
        totalEmployees++;
        totalSalary += e.sal;

        if (e.sal > maxSalary) {
            maxSalary = e.sal;
        }

        if (e.sal < minSalary) {
            minSalary = e.sal;
        }
    }

    float averageSalary = totalSalary / totalEmployees;

    printf("\n\n\t\tTotal Number of Employees: %d", totalEmployees);
    printf("\n\t\tTotal Salary Expense: %.2f", totalSalary);
    printf("\n\t\tAverage Salary: %.2f", averageSalary);
    printf("\n\t\tMaximum Salary: %.2f", maxSalary);
    printf("\n\t\tMinimum Salary: %.2f", minSalary);

    int option;
    printf("\n\n\t\tFilter Options:");
    printf("\n\t\t1. Filter by Salary Range");
    printf("\n\t\t2. Filter by Designation");
    printf("\n\t\t0. Back to Main Menu");
    printf("\n\n\t\tEnter Your Option :--> ");
    scanf("%d", &option);

    switch (option) {
        case 0:
            return;
        case 1:
            filterBySalaryRange(fp);
            break;
        case 2:
            filterByDesignation(fp);
            break;
        default:
            printf("\n\t\tInvalid option. Returning to main menu.");
            break;
    }
}

void filterBySalaryRange(FILE *fp) {
    float minSalary, maxSalary;
    printf("\n\t\tEnter Minimum Salary: ");
    scanf("%f", &minSalary);
    printf("\n\t\tEnter Maximum Salary: ");
    scanf("%f", &maxSalary);

    Employee e;
    int siz = sizeof(e);

    rewind(fp);

    printHead();
    printf("\n\t\tEmployees within Salary Range: %.2f - %.2f", minSalary, maxSalary);
    printf("\n\n");

    while (fread(&e, siz, 1, fp) == 1) {
        if (e.sal >= minSalary && e.sal <= maxSalary) {
            displayList(fp);
        }
    }

    printf("\n\n\t");
    system("pause");
}

void filterByDesignation(FILE *fp) {
    char designation[10];
    printf("\n\t\tEnter Designation: ");
    scanf("%s", designation);

    Employee e;
    int siz = sizeof(e);

    rewind(fp);

    printHead();
    printf("\n\t\tEmployees with Designation: %s", designation);
    printf("\n\n");

    while (fread(&e, siz, 1, fp) == 1) {
        if (strcasecmp(e.desgn, designation) == 0) {
            displayList(fp);
        }
    }

    printf("\n\n\t");
    system("pause");
}

int main() {
    FILE *fp;
    Employee e;
    int option;
    char username[10], password[10];

    // Opening or creating the employeeInfo.txt file
    if ((fp = fopen("employeeInfo.txt", "rb+")) == NULL) {
        if ((fp = fopen("employeeInfo.txt", "wb+")) == NULL) {
            printf("Can't open file");
            return 0;
        }
    }

    // Display welcome message and login screen
    printHead();
    welcome();
    printHead();
    printf("\n\t\t\t\t  Login Screen");
    printf("\n\t\t\t      Enter Your Credential");
    printf("\n\n\n\t\tUsername: ");
    scanf("%s", username);
    printf("\n\t\tPassword: ");
    int i = 0;

    do {
        password[i] = getch();

        if (password[i] == 13) {
            break;
        } else if (password[i] == 8 && i > 0) {
            printf("%c%c%c", 8, 32, 8);
            i--;
        } else {
            printf("*");
            i++;
        }
    } while (password[i] != 13);

    password[i] = '\0';

    // Check username and password
    if ((strcasecmp(username, "Rifat") == 0) && (strcasecmp(password, "rifat1410") == 0)) {
        while (1) {
            printHead();
            // Display menu options

            printf("\n\t\t\t\tMain Menu");
    printf("\n\n\n");


    printf("\n\n\t\t\t1. Add Employee");
    printf("\n\n\t\t\t2. Delete Employee");
    printf("\n\n\t\t\t3. Modify Employee");
    printf("\n\n\t\t\t4. Display Employee List");
    printf("\n\n\t\t\t5. Search Record");
    printf("\n\n\t\t\t6. Display Basic Info");
    printf("\n\n\t\t\t7. Display Basic Contact Info");
    printf("\n\n\t\t\t8. List of Male Employee");
    printf("\n\n\t\t\t9. List of Female Employee");
    printf("\n\n\t\t\t10. List of Employee From Dhaka");
    printf("\n\n\t\t\t11. List of Employee From Others District");
    printf("\n\n\t\t\t12. List of Employee of Main Branch");
    printf("\n\n\t\t\t13. List of Employee of Others Branch");
    printf("\n\n\t\t\t14. Data Analysis and Statistics");
    printf("\n\n\t\t\t0. EXIT");

    printf("\n\n\t\tEnter Your Option :--> ");
    scanf("%d",&option);


            switch (option) {
                case 0: return 1;
                        break;
                case 1: add(fp);
                        break;
                case 2: fp = del(fp);
                        break;
                case 3: modify(fp);
                        break;
                case 4: displayList(fp);
                        break;
                case 5: searchRecord(fp);
                        break;
                case 6: displaybasic(fp);
                        break;
                case 7: basiccontact(fp);
                        break;
                case 8: maleemp(fp);
                        break;
                case 9: femaleemp(fp);
                        break;
                case 10: frmdhaka(fp);
                         break;
                case 11: frmors(fp);
                         break;
                case 12: mainbr(fp);
                         break;
                case 13: otherbr(fp);
                         break;
                case 14: DataAnalysisandStatistics(fp);
                         break;

                default: printf("\n\t\tYou Pressed wrong key");
                         printf("\n\t\tProgram terminated");
                         getch();
                         exit(0);
            }
        }
    } else {
        printf("\n\t\tLogin Failed");
    }

    return 1;
}
