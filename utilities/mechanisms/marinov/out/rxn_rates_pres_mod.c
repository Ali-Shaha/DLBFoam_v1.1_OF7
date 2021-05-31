#include <math.h>
#include "header.h"
#include "rates.h"

void get_rxn_pres_mod (const double T, const double pres, const double * __restrict__ C, double * __restrict__ pres_mod) {
  // third body variable declaration
  double thd;

  // pressure dependence variable declarations
  double k0;
  double kinf;
  double Pr;

  // troe variable declarations
  double logFcent;
  double A;
  double B;

  double logT = log(T);
  double m = pres / (8.31446210e+03 * T);

  // reaction 3;
  thd = m - 1.0 * C[0] - 1.0 * C[7] - 1.0 * C[10];
  k0 = exp(2.9982396373092026e+01 - 1.257 * logT);
  kinf = 45200000000.0;
  Pr = k0 * thd / kinf;
  pres_mod[0] =  Pr / (1.0 + Pr);

  // reaction 4;
  k0 = exp(3.2944227094970337e+01 - 1.59 * logT);
  kinf = 45200000000.0;
  Pr = k0 * C[10] / kinf;
  pres_mod[1] =  Pr / (1.0 + Pr);

  // reaction 5;
  k0 = exp(3.0352316543780780e+01 - 1.133 * logT);
  kinf = 45200000000.0;
  Pr = k0 * C[0] / kinf;
  pres_mod[2] =  Pr / (1.0 + Pr);

  // reaction 6;
  k0 = exp(3.9885883925628157e+01 - 2.437 * logT);
  kinf = 45200000000.0;
  Pr = k0 * C[7] / kinf;
  pres_mod[3] =  Pr / (1.0 + Pr);

  // reaction 14;
  pres_mod[4] = m - 1.0 * C[0] - 1.0 * C[7];

  // reaction 17;
  pres_mod[5] = m + 5.4 * C[7];

  // reaction 18;
  pres_mod[6] = m + 5.4 * C[7];

  // reaction 19;
  pres_mod[7] = m;

  // reaction 22;
  thd = m;
  k0 = exp(5.6373899747275225e+01 - 4.63 * logT - (1.0310968883964242e+03 / T));
  kinf = exp(2.5543547402551447e+01 - 0.37 * logT);
  Pr = k0 * thd / kinf;
  logFcent = log10( fmax(5.30000000e-01 * exp(-T / 1.00000000e+02) + 4.70000000e-01 * exp(-T / 2.00000000e+03) + exp(-1.00000000e+15 / T), 1.0e-300));
  A = log10(fmax(Pr, 1.0e-300)) - 0.67 * logFcent - 0.4;
  B = 0.806 - 1.1762 * logFcent - 0.14 * log10(fmax(Pr, 1.0e-300));
  pres_mod[8] = pow(10.0, logFcent / (1.0 + A * A / (B * B))) * Pr / (1.0 + Pr);

} // end get_rxn_pres_mod

