// Write a C program, first_line.c, which is given one command-line argument -
// the name of a file - and which prints the first line of that file to stdout.
// If given an incorrect number of arguments, or if there was an error opening
// the file, it should print a suitable error message.
//
// A line may be of any size.

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    // TODO: complete this function
    // Open file for reading
    FILE *fp = fopen(argv[1], "r");

    // Handle Errors
    if (fp == NULL) {
        perror(argv[1]);
        exit(1);
    }

    /*
    // Read & print the first line, character by character
    int c;
    while (((c = fgetc(fp)) != EOF) && (c != '\n')) {
        putchar(c);
    }*/

    char line[256];
    fgets(line, 256, fp);
    printf("%s", line);*/




    fclose(fp);

    return 0;
}
