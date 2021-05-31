#ifndef MECHANISM_h
#define MECHANISM_h

#include <string.h>
//last_spec 9
/* Species Indexes
0  H2
1  H
2  O2
3  O
4  OH
5  HO2
6  H2O2
7  H2O
8  AR
9  HE
10  N2
*/

//Number of species
#define NSP 11
//Number of variables. NN = NSP + 1 (temperature)
#define NN 12
//Number of forward reactions
#define FWD_RATES 27
//Number of reversible reactions
#define REV_RATES 27
//Number of reactions with pressure modified rates
#define PRES_MOD_RATES 9

//Must be implemented by user on a per mechanism basis in mechanism.c
void set_same_initial_conditions(int, double**, double**);

#if defined (RATES_TEST) || defined (PROFILER)
    void write_jacobian_and_rates_output(int NUM);
#endif
//apply masking of ICs for cache optimized mechanisms
void apply_mask(double*);
void apply_reverse_mask(double*);
#endif

