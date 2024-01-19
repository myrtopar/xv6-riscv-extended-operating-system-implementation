#include "param.h"
struct pstat
{
    int num_procs;
    int pids[NPROC];
    int ppids[NPROC];
    char names[NPROC][16];
    int priorities[NPROC];
    int states[NPROC];
    int sizes[NPROC];
};
