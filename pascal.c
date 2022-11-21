#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>


#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"


long long factorial(long long int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    else {
        return n*factorial(n-1);
    }

    /*
    long long  factorial = 1;
    for (int i = 1; i < n+1; i++) {
        factorial = factorial*i;
    }
    return factorial;
    */
}

//from n choose r
//https://math.stackexchange.com/questions/202554/how-do-i-compute-binomial-coefficients-efficiently
long long binomial_coefficient(unsigned int n, unsigned int k) {
    //return factorial(n)/ (factorial(r)*factorial(n-r));

    if ( (n == k) || (k == 0) ) {
        return 1;
    }
    else {
        //return binomial_coefficient(n-1,k-1) + binomial_coefficient(n-1,k);
        if ( k > (n/2) ) {
            return binomial_coefficient(n,n-k);
        }
        else {
            return ((n*binomial_coefficient(n-1,k-1))/k);
        }
    }

}

void print_spaces(int n) {
    if (n == 0) {
        return;
    }
    for (int i = 0; i < n; i++) {
        printf(" ");
    }
}

int main(int agrc, char *argv[]) {

    int rows;
    if (agrc > 1) {
        rows =  atoi( argv[1] );
    }
    else {
        rows = 10;
    }

    int entry;
    for (int i = 0; i < rows; i++) {

        print_spaces(rows-i);
        for (int j = 0; j < i +1; j++) {
            entry = binomial_coefficient(i,j);
            if ((entry % 2) == 0) {
//              printf(ANSI_COLOR_GREEN"%d "  ANSI_COLOR_RESET, entry );
                printf(ANSI_COLOR_GREEN"1 "  ANSI_COLOR_RESET);
            }
            else {
//                  printf(ANSI_COLOR_RED"%d "  ANSI_COLOR_RESET, entry );
                    printf(ANSI_COLOR_RED"0 "  ANSI_COLOR_RESET);

            }



            //printf("%d ",binomial_coefficient(i,j));

        }
        printf("\n");

    }

    return 0;

}
