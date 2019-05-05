#include <stdio.h>
#include <time.h>

// Routine for printing a logo to the terminal
void printLogo()
{
    printf("\n\33[1;32m");
    printf("┏━━━┳━┳━━━━┳━┳━┳━━━┳━━━┳━┓             ┏━━┓\n");
    printf("┃   ┃ ┃ ┏━━┫ ┃ ┃   ┃   ┃ ┃             ┃  ┣━━━┳┓  \n");
    printf("┃ ┃ ┃ ┃ ┗━┓┃ ┃ ┃ ┃ ┃ ┃ ┃ ┃             ┗━━┛   ┃┃┏━━┓\n");
    printf("┃ ┃ ┃ ┃ ┏━┛┃ ┃ ┃   ┫   ┃ ┃                 ┏━┏┃┗┫  ┣━┓\n");
    printf("┃ ┃   ┃ ┗━━┫   ┃ ┃ ┃ ┃ ┃ ┗━━┓          ┏━━┓┃ ┃┃ ┗━━┛ ┃┏━━┓\n");
    printf("┣━┻━┳━╋━━━━╋━━━┻━╋━╋━┻━╋━┳━━┻┳━━━┳━┳━┓ ┃  ┣━━┫┃     ┏┗┫  ┃\n");
    printf("┃   ┃ ┃ ┏━━┻━┓ ┏━┫ ┃   ┃ ┃   ┃   ┃ ┃ ┃ ┗━━┛┃ ┃┃ ┏━━┓┃ ┗━━┛\n");
    printf("┃ ┃ ┃ ┃ ┗━┓  ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┃     ┃┏┗┗━┫  ┣┛\n");
    printf("┃ ┃ ┃ ┃ ┏━┛  ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┃ ┃   ┫   ┫ ┏━━┓┃┃   ┗━━┛\n");
    printf("┃ ┃   ┃ ┗━━┓ ┃ ┃ ┃   ┃   ┃   ┃ ┃ ┃ ┃ ┃ ┃  ┣┻┛    \n");
    printf("┗━┻━━━┻━━━━┛ ┗━┛ ┗━━━┻━━━┻━━━┻━┻━┻━┻━┛ ┗━━┛\n");

    printf("\nBY ØYVIND SÆBØ\33[m\n");
}

// Routine for prining a loading bar to the terminal
void printLoading(char message[100]) {
    printf("\n\33[1;32m%s:\n", message);
    fflush(stdout);

    for (int i = 0; i < 60; i++) {
        usleep(10000);
        printf("█");
        fflush(stdout);
    }

    usleep(10000);
    printf("█\33[m\n");
    fflush(stdout);
}
