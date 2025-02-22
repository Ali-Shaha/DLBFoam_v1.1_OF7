#include "sparse_multiplier.h"

void sparse_multiplier(const double * A, const double * Vm, double* w) {
  w[0] =  A[0] * Vm[0] +  A[11] * Vm[1] +  A[22] * Vm[2] +  A[33] * Vm[3] +  A[44] * Vm[4] +  A[55] * Vm[5] +  A[66] * Vm[6] +  A[77] * Vm[7] +  A[88] * Vm[8] +  A[99] * Vm[9] +  A[110] * Vm[10];
  w[1] =  A[1] * Vm[0] +  A[12] * Vm[1] +  A[23] * Vm[2] +  A[34] * Vm[3] +  A[45] * Vm[4] +  A[56] * Vm[5] +  A[67] * Vm[6] +  A[78] * Vm[7] +  A[89] * Vm[8] +  A[100] * Vm[9] +  A[111] * Vm[10];
  w[2] =  A[2] * Vm[0] +  A[13] * Vm[1] +  A[24] * Vm[2] +  A[35] * Vm[3] +  A[46] * Vm[4] +  A[57] * Vm[5] +  A[68] * Vm[6] +  A[79] * Vm[7] +  A[90] * Vm[8] +  A[101] * Vm[9] +  A[112] * Vm[10];
  w[3] =  A[3] * Vm[0] +  A[14] * Vm[1] +  A[25] * Vm[2] +  A[36] * Vm[3] +  A[47] * Vm[4] +  A[58] * Vm[5] +  A[69] * Vm[6] +  A[80] * Vm[7] +  A[91] * Vm[8] +  A[102] * Vm[9] +  A[113] * Vm[10];
  w[4] =  A[4] * Vm[0] +  A[15] * Vm[1] +  A[26] * Vm[2] +  A[37] * Vm[3] +  A[48] * Vm[4] +  A[59] * Vm[5] +  A[70] * Vm[6] +  A[81] * Vm[7] +  A[92] * Vm[8] +  A[103] * Vm[9] +  A[114] * Vm[10];
  w[5] =  A[5] * Vm[0] +  A[16] * Vm[1] +  A[27] * Vm[2] +  A[38] * Vm[3] +  A[49] * Vm[4] +  A[60] * Vm[5] +  A[71] * Vm[6] +  A[82] * Vm[7] +  A[93] * Vm[8] +  A[104] * Vm[9] +  A[115] * Vm[10];
  w[6] =  A[6] * Vm[0] +  A[17] * Vm[1] +  A[28] * Vm[2] +  A[39] * Vm[3] +  A[50] * Vm[4] +  A[61] * Vm[5] +  A[72] * Vm[6] +  A[83] * Vm[7] +  A[94] * Vm[8] +  A[105] * Vm[9] +  A[116] * Vm[10];
  w[7] =  A[7] * Vm[0] +  A[18] * Vm[1] +  A[29] * Vm[2] +  A[40] * Vm[3] +  A[51] * Vm[4] +  A[62] * Vm[5] +  A[73] * Vm[6] +  A[84] * Vm[7] +  A[95] * Vm[8] +  A[106] * Vm[9] +  A[117] * Vm[10];
  w[8] =  A[8] * Vm[0] +  A[19] * Vm[1] +  A[30] * Vm[2] +  A[41] * Vm[3] +  A[52] * Vm[4] +  A[63] * Vm[5] +  A[74] * Vm[6] +  A[85] * Vm[7] +  A[96] * Vm[8] +  A[107] * Vm[9] +  A[118] * Vm[10];
  w[9] =  A[9] * Vm[0] +  A[20] * Vm[1] +  A[31] * Vm[2] +  A[42] * Vm[3] +  A[53] * Vm[4] +  A[64] * Vm[5] +  A[75] * Vm[6] +  A[86] * Vm[7] +  A[97] * Vm[8] +  A[108] * Vm[9] +  A[119] * Vm[10];
  w[10] =  A[10] * Vm[0] +  A[21] * Vm[1] +  A[32] * Vm[2] +  A[43] * Vm[3] +  A[54] * Vm[4] +  A[65] * Vm[5] +  A[76] * Vm[6] +  A[87] * Vm[7] +  A[98] * Vm[8] +  A[109] * Vm[9] +  A[120] * Vm[10];
}
