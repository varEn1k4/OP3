#include <stdio.h>
#include <conio.h>

int isItValid(char parametr[], int min, int max);

int main() {
    char exitE = 0;

    printf("This program uses the date, month, and year to determine the name of the day.\n");
    printf("Max year = 2099; Min year = 1900\n");
    printf("Enter ONLY numbers\n");
    do {
        int n = 0;
        char maxDayOfEachMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        char* days[] = {"Monday","Tuesday","Wednesday", "Thursday", "Friday", "Saturday","Sunday"};

        int date = isItValid("Date: ", 1, 31);
        int month = isItValid("Month (1-12): ", 1, 12);
        int year = isItValid("Year: ", 1900, 2099);


        maxDayOfEachMonth[1] = (year % 100 != 0 && year % 4 == 0) || (year % 400 == 0) ? 29 : 28;

        if (date > maxDayOfEachMonth[month - 1]) {
            printf("ERROR: Month %d has only %d days.\n", month, maxDayOfEachMonth[month - 1]);
            printf("Please enter the date again.\n");
            continue;
        }

        int isLeapYear = (maxDayOfEachMonth[1] == 29);

        if (month > 2) {
            n = 0;
        } else if (month < 3 && isLeapYear) {
            n = 1;
        } else if (month < 3 && !isLeapYear){
            n = 2;
        }

        int day = ((int)(365.25 * year) + (int)(30.56 * month) + date + n) % 7;

        printf("\nDate: %02d.%02d.%d\n", date, month, year);
        printf("Day: %s\n", days[day]);
        printf("\nPress 1 and ENTER to end or just ENTER to continue\n");
        exitE=getch();
    } while (exitE != '1');
    return 0;
}

int isItValid(char parametr[], int min, int max) {
    int number = 0;
    char extra = 0;
    int validInput = 1;
    do {
        printf("\n%s", parametr);
        int result = scanf(" %d%c", &number, &extra);

        if (result !=2 || extra != '\n') {
            printf("ERROR: Invalid input. Please enter ONLY a number without decimal places\n");
            while (getchar() != '\n'){}
            continue;
        }
        if (number < min || number > max) {
            printf("ERROR: your value is not correct. Please enter a new number\n");
            continue;
        }
        validInput = 0;
    } while (validInput);
    return number;
}