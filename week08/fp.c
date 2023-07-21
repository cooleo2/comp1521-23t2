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

    int b;
    b = fgetc(fp);
    fputc(b, stdout);
    b = fgetc(fp);
    fputc(b, stdout);

    fputc('\n', stdout);

    fseek(fp, -4, SEEK_END);


    b = fgetc(fp);
    fputc(b, stdout);
    b = fgetc(fp);
    fputc(b, stdout);

    fputc('\n', stdout);
    

    fclose(fp);

    return 0;
}
