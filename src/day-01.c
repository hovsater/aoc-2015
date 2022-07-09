#include <stdio.h>
#include <stdlib.h>

void part1(FILE *fp);
void part2(FILE *fp);

int main(void)
{
    FILE *fp;
    fp = fopen("input/day-01.txt", "r");
    if (fp == NULL) {
        printf("Failed to open input/day-01.txt\n");
        return EXIT_FAILURE;
    }

    part1(fp);
    rewind(fp);
    part2(fp);
    fclose(fp);

    return EXIT_SUCCESS;
}

void part1(FILE *fp)
{
    int c, floor_count = 0;
    while ((c = fgetc(fp)) != EOF) {
        switch (c) {
            case '(':
                floor_count += 1;
                break;
            case ')':
                floor_count -= 1;
                break;
        }
    }

    printf("floor count: %d\n", floor_count);
}


void part2(FILE *fp)
{
    int c, i = 0, floor_count = 0;
    while ((c = fgetc(fp)) != EOF) {
        i++;
        switch (c) {
            case '(':
                floor_count += 1;
                break;
            case ')':
                floor_count -= 1;
                break;
        }

        if (floor_count == -1) {
            break;
        }
    }

    printf("position: %d\n", i);
}
