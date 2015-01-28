/*
    name:       davg
    author:     Dave Smith-Hayes

    This program performs averaging for values passed through
    stdin or the argument list. All results are floats. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_BUFFER  1024

int main(int argc, char *argv[])
{
    /* Declarations */
    int     i;
    int     input_length;
    double  total = (double)(argc - 1);
    double  sum = 0.0;
    char    buffer[MAX_BUFFER + 1] = { 0 };
    char   *value;
    bool    use_argv = false;

    if(argc != 1)
        use_argv = true;

    if(use_argv) {      /* use argv */
        for(i = 1; i < argc; i++)
            sum += atof(argv[i]);

        fprintf(stdout, "%f\n", (sum / total));
        return (int)((int)sum / (int)total);
    }
    else {              /* use stdin */
        total = 0.0;

        while((input_length = fread(buffer, 1, MAX_BUFFER, stdin)) > 0) {
            value = strtok(buffer, " ");

            while(value != NULL) {
                sum += atof(value);
                total++;
                value = strtok(NULL, " ");
            }
        }

        fprintf(stdout, "%f\n", (sum / total));
        return (int)((int)sum / (int)total);
    }

    return 0;
}
