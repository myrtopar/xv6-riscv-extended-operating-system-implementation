#include "kernel/types.h"
#include "kernel/pstat.h"
#include "user/user.h"
#include "kernel/param.h"

void print_state(int n)
{
    switch (n)
    {
    case 1:
        printf("\tUSED");
        break;
    case 2:
        printf("\tSLEEPING\n");
        break;
    case 3:
        printf("\tRUNNABLE\n");
        break;
    case 4:
        printf("\tRUNNING\n");
        break;
    case 5:
        printf("\tZOMBIE\n");
        break;
    default:
        printf("\tSTATE ERROR\n");
        break;
    }
}

int main(int argc, char *argv[])
{
    struct pstat ps;

    // Call the getpinfo system call
    if (getpinfo(&ps) < 0)
    {
        printf("Error calling getpinfo\n");
        exit(0);
    }

    // Print the information for all processes
    printf("PID\tNAME\tPRIORITY\tPARENT\t\tSIZE\tSTATE\n");
    for (int i = 0; i < ps.num_procs; i++)
    {
        printf("%d\t%s\t%d\t\t%d\t\t%d", ps.pids[i], ps.names[i], ps.priorities[i], ps.ppids[i], ps.sizes[i]);
        print_state(ps.states[i]);
    }

    exit(0);
}