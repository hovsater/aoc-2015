#include <stdio.h>
#include <stdlib.h>

int min(int a, int b);
void part1(FILE* fp);
void part2(FILE* fp);

int main(void)
{
    FILE* fp;

    fp = fopen("input/day02.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to open input/day02.txt\n");
        return EXIT_FAILURE;
    }

    part1(fp);
    rewind(fp);
    part2(fp);

    return EXIT_SUCCESS;
}

void part1(FILE* fp)
{
    int ic, l, w, h;
    int total = 0;
    while ((ic = fscanf(fp, "%dx%dx%d", &l, &w, &h)) != EOF) {
        if (ic != 3) {
            fprintf(stderr, "Failed to parse line");
            exit(EXIT_FAILURE);
        }

        total += 2 * l * w + 2 * w * h + 2 * h * l
            + min(l * w, min(w * h, h * l));
    }

    printf("part 1: %d\n", total);
}

void part2(FILE* fp)
{
    int ic, l, w, h;
    int total = 0;
    while ((ic = fscanf(fp, "%dx%dx%d", &l, &w, &h)) != EOF) {
        if (ic != 3) {
            fprintf(stderr, "Failed to parse line");
            exit(EXIT_FAILURE);
        }

        total += 2 * min(l + w, min(w + h, h + l)) + l * w * h;
    }

    printf("part 2: %d\n", total);
}

int min(int a, int b)
{
    return a < b ? a : b;
}
