#include "general.h"
#include "LUT.h"
#include "fft.h"

const fixed Sinewave[N_WAVE] = {
      0,    201,    402,    603,    804,   1005,   1206,   1406,
   1607,   1808,   2009,   2209,   2410,   2610,   2811,   3011,
   3211,   3411,   3611,   3811,   4011,   4210,   4409,   4608,
   4807,   5006,   5205,   5403,   5601,   5799,   5997,   6195,
   6392,   6589,   6786,   6982,   7179,   7375,   7571,   7766,
   7961,   8156,   8351,   8545,   8739,   8932,   9126,   9319,
   9511,   9703,   9895,  10087,  10278,  10469,  10659,  10849,
  11038,  11227,  11416,  11604,  11792,  11980,  12166,  12353,
  12539,  12724,  12909,  13094,  13278,  13462,  13645,  13827,
  14009,  14191,  14372,  14552,  14732,  14911,  15090,  15268,
  15446,  15623,  15799,  15975,  16150,  16325,  16499,  16672,
  16845,  17017,  17189,  17360,  17530,  17699,  17868,  18036,
  18204,  18371,  18537,  18702,  18867,  19031,  19194,  19357,
  19519,  19680,  19840,  20000,  20159,  20317,  20474,  20631,
  20787,  20942,  21096,  21249,  21402,  21554,  21705,  21855,
  22004,  22153,  22301,  22448,  22594,  22739,  22883,  23027,
  23169,  23311,  23452,  23592,  23731,  23869,  24006,  24143,
  24278,  24413,  24546,  24679,  24811,  24942,  25072,  25201,
  25329,  25456,  25582,  25707,  25831,  25954,  26077,  26198,
  26318,  26437,  26556,  26673,  26789,  26905,  27019,  27132,
  27244,  27355,  27466,  27575,  27683,  27790,  27896,  28001,
  28105,  28208,  28309,  28410,  28510,  28608,  28706,  28802,
  28897,  28992,  29085,  29177,  29268,  29358,  29446,  29534,
  29621,  29706,  29790,  29873,  29955,  30036,  30116,  30195,
  30272,  30349,  30424,  30498,  30571,  30643,  30713,  30783,
  30851,  30918,  30984,  31049,  31113,  31175,  31236,  31297,
  31356,  31413,  31470,  31525,  31580,  31633,  31684,  31735,
  31785,  31833,  31880,  31926,  31970,  32014,  32056,  32097,
  32137,  32176,  32213,  32249,  32284,  32318,  32350,  32382,
  32412,  32441,  32468,  32495,  32520,  32544,  32567,  32588,
  32609,  32628,  32646,  32662,  32678,  32692,  32705,  32717,
  32727,  32736,  32744,  32751,  32757,  32761,  32764,  32766,
  32767,  32766,  32764,  32761,  32757,  32751,  32744,  32736,
  32727,  32717,  32705,  32692,  32678,  32662,  32646,  32628,
  32609,  32588,  32567,  32544,  32520,  32495,  32468,  32441,
  32412,  32382,  32350,  32318,  32284,  32249,  32213,  32176,
  32137,  32097,  32056,  32014,  31970,  31926,  31880,  31833,
  31785,  31735,  31684,  31633,  31580,  31525,  31470,  31413,
  31356,  31297,  31236,  31175,  31113,  31049,  30984,  30918,
  30851,  30783,  30713,  30643,  30571,  30498,  30424,  30349,
  30272,  30195,  30116,  30036,  29955,  29873,  29790,  29706,
  29621,  29534,  29446,  29358,  29268,  29177,  29085,  28992,
  28897,  28802,  28706,  28608,  28510,  28410,  28309,  28208,
  28105,  28001,  27896,  27790,  27683,  27575,  27466,  27355,
  27244,  27132,  27019,  26905,  26789,  26673,  26556,  26437,
  26318,  26198,  26077,  25954,  25831,  25707,  25582,  25456,
  25329,  25201,  25072,  24942,  24811,  24679,  24546,  24413,
  24278,  24143,  24006,  23869,  23731,  23592,  23452,  23311,
  23169,  23027,  22883,  22739,  22594,  22448,  22301,  22153,
  22004,  21855,  21705,  21554,  21402,  21249,  21096,  20942,
  20787,  20631,  20474,  20317,  20159,  20000,  19840,  19680,
  19519,  19357,  19194,  19031,  18867,  18702,  18537,  18371,
  18204,  18036,  17868,  17699,  17530,  17360,  17189,  17017,
  16845,  16672,  16499,  16325,  16150,  15975,  15799,  15623,
  15446,  15268,  15090,  14911,  14732,  14552,  14372,  14191,
  14009,  13827,  13645,  13462,  13278,  13094,  12909,  12724,
  12539,  12353,  12166,  11980,  11792,  11604,  11416,  11227,
  11038,  10849,  10659,  10469,  10278,  10087,   9895,   9703,
   9511,   9319,   9126,   8932,   8739,   8545,   8351,   8156,
   7961,   7766,   7571,   7375,   7179,   6982,   6786,   6589,
   6392,   6195,   5997,   5799,   5601,   5403,   5205,   5006,
   4807,   4608,   4409,   4210,   4011,   3811,   3611,   3411,
   3211,   3011,   2811,   2610,   2410,   2209,   2009,   1808,
   1607,   1406,   1206,   1005,    804,    603,    402,    201,
      0,   -201,   -402,   -603,   -804,  -1005,  -1206,  -1406,
  -1607,  -1808,  -2009,  -2209,  -2410,  -2610,  -2811,  -3011,
  -3211,  -3411,  -3611,  -3811,  -4011,  -4210,  -4409,  -4608,
  -4807,  -5006,  -5205,  -5403,  -5601,  -5799,  -5997,  -6195,
  -6392,  -6589,  -6786,  -6982,  -7179,  -7375,  -7571,  -7766,
  -7961,  -8156,  -8351,  -8545,  -8739,  -8932,  -9126,  -9319,
  -9511,  -9703,  -9895, -10087, -10278, -10469, -10659, -10849,
 -11038, -11227, -11416, -11604, -11792, -11980, -12166, -12353,
 -12539, -12724, -12909, -13094, -13278, -13462, -13645, -13827,
 -14009, -14191, -14372, -14552, -14732, -14911, -15090, -15268,
 -15446, -15623, -15799, -15975, -16150, -16325, -16499, -16672,
 -16845, -17017, -17189, -17360, -17530, -17699, -17868, -18036,
 -18204, -18371, -18537, -18702, -18867, -19031, -19194, -19357,
 -19519, -19680, -19840, -20000, -20159, -20317, -20474, -20631,
 -20787, -20942, -21096, -21249, -21402, -21554, -21705, -21855,
 -22004, -22153, -22301, -22448, -22594, -22739, -22883, -23027,
 -23169, -23311, -23452, -23592, -23731, -23869, -24006, -24143,
 -24278, -24413, -24546, -24679, -24811, -24942, -25072, -25201,
 -25329, -25456, -25582, -25707, -25831, -25954, -26077, -26198,
 -26318, -26437, -26556, -26673, -26789, -26905, -27019, -27132,
 -27244, -27355, -27466, -27575, -27683, -27790, -27896, -28001,
 -28105, -28208, -28309, -28410, -28510, -28608, -28706, -28802,
 -28897, -28992, -29085, -29177, -29268, -29358, -29446, -29534,
 -29621, -29706, -29790, -29873, -29955, -30036, -30116, -30195,
 -30272, -30349, -30424, -30498, -30571, -30643, -30713, -30783,
 -30851, -30918, -30984, -31049, -31113, -31175, -31236, -31297,
 -31356, -31413, -31470, -31525, -31580, -31633, -31684, -31735,
 -31785, -31833, -31880, -31926, -31970, -32014, -32056, -32097,
 -32137, -32176, -32213, -32249, -32284, -32318, -32350, -32382,
 -32412, -32441, -32468, -32495, -32520, -32544, -32567, -32588,
 -32609, -32628, -32646, -32662, -32678, -32692, -32705, -32717,
 -32727, -32736, -32744, -32751, -32757, -32761, -32764, -32766,
 -32767, -32766, -32764, -32761, -32757, -32751, -32744, -32736,
 -32727, -32717, -32705, -32692, -32678, -32662, -32646, -32628,
 -32609, -32588, -32567, -32544, -32520, -32495, -32468, -32441,
 -32412, -32382, -32350, -32318, -32284, -32249, -32213, -32176,
 -32137, -32097, -32056, -32014, -31970, -31926, -31880, -31833,
 -31785, -31735, -31684, -31633, -31580, -31525, -31470, -31413,
 -31356, -31297, -31236, -31175, -31113, -31049, -30984, -30918,
 -30851, -30783, -30713, -30643, -30571, -30498, -30424, -30349,
 -30272, -30195, -30116, -30036, -29955, -29873, -29790, -29706,
 -29621, -29534, -29446, -29358, -29268, -29177, -29085, -28992,
 -28897, -28802, -28706, -28608, -28510, -28410, -28309, -28208,
 -28105, -28001, -27896, -27790, -27683, -27575, -27466, -27355,
 -27244, -27132, -27019, -26905, -26789, -26673, -26556, -26437,
 -26318, -26198, -26077, -25954, -25831, -25707, -25582, -25456,
 -25329, -25201, -25072, -24942, -24811, -24679, -24546, -24413,
 -24278, -24143, -24006, -23869, -23731, -23592, -23452, -23311,
 -23169, -23027, -22883, -22739, -22594, -22448, -22301, -22153,
 -22004, -21855, -21705, -21554, -21402, -21249, -21096, -20942,
 -20787, -20631, -20474, -20317, -20159, -20000, -19840, -19680,
 -19519, -19357, -19194, -19031, -18867, -18702, -18537, -18371,
 -18204, -18036, -17868, -17699, -17530, -17360, -17189, -17017,
 -16845, -16672, -16499, -16325, -16150, -15975, -15799, -15623,
 -15446, -15268, -15090, -14911, -14732, -14552, -14372, -14191,
 -14009, -13827, -13645, -13462, -13278, -13094, -12909, -12724,
 -12539, -12353, -12166, -11980, -11792, -11604, -11416, -11227,
 -11038, -10849, -10659, -10469, -10278, -10087,  -9895,  -9703,
  -9511,  -9319,  -9126,  -8932,  -8739,  -8545,  -8351,  -8156,
  -7961,  -7766,  -7571,  -7375,  -7179,  -6982,  -6786,  -6589,
  -6392,  -6195,  -5997,  -5799,  -5601,  -5403,  -5205,  -5006,
  -4807,  -4608,  -4409,  -4210,  -4011,  -3811,  -3611,  -3411,
  -3211,  -3011,  -2811,  -2610,  -2410,  -2209,  -2009,  -1808,
  -1607,  -1406,  -1206,  -1005,   -804,   -603,   -402,   -201,
};

const fixed sinLUT[SIN_LUT_SIZE] = {
    0, -101, -201, -302, -402, -503, -603, -704, -804, -904, -1005, -1105, -1205, -1306, 
    -1406, -1506, -1606, -1706, -1806, -1906, -2006, -2105, -2205, -2305, -2404, -2503, 
    -2603, -2702, -2801, -2900, -2999, -3098, -3196, -3295, -3393, -3492, -3590, -3688, 
    -3786, -3883, -3981, -4078, -4176, -4273, -4370, -4467, -4563, -4660, -4756, -4852, 
    -4948, -5044, -5139, -5235, -5330, -5425, -5520, -5614, -5708, -5803, -5897, -5990, 
    -6084, -6177, -6270, -6363, -6455, -6547, -6639, -6731, -6823, -6914, -7005, -7096, 
    -7186, -7276, -7366, -7456, -7545, -7635, -7723, -7812, -7900, -7988, -8076, -8163, 
    -8250, -8337, -8423, -8509, -8595, -8680, -8765, -8850, -8935, -9019, -9102, -9186, 
    -9269, -9352, -9434, -9516, -9598, -9679, -9760, -9841, -9921, -10001, -10080, -10159, 
    -10238, -10316, -10394, -10471, -10549, -10625, -10702, -10778, -10853, -10928, -11003, 
    -11077, -11151, -11224, -11297, -11370, -11442, -11514, -11585, -11656, -11727, -11797, 
    -11866, -11935, -12004, -12072, -12140, -12207, -12274, -12340, -12406, -12472, -12537, 
    -12601, -12665, -12729, -12792, -12854, -12916, -12978, -13039, -13100, -13160, -13219, 
    -13279, -13337, -13395, -13453, -13510, -13567, -13623, -13678, -13733, -13788, -13842, 
    -13896, -13949, -14001, -14053, -14104, -14155, -14206, -14256, -14305, -14354, -14402, 
    -14449, -14497, -14543, -14589, -14635, -14680, -14724, -14768, -14811, -14854, -14896, 
    -14937, -14978, -15019, -15059, -15098, -15137, -15175, -15213, -15250, -15286, -15322, 
    -15357, -15392, -15426, -15460, -15493, -15525, -15557, -15588, -15619, -15649, -15679, 
    -15707, -15736, -15763, -15791, -15817, -15843, -15868, -15893, -15917, -15941, -15964, 
    -15986, -16008, -16029, -16049, -16069, -16088, -16107, -16125, -16143, -16160, -16176, 
    -16192, -16207, -16221, -16235, -16248, -16261, -16273, -16284, -16295, -16305, -16315, 
    -16324, -16332, -16340, -16347, -16353, -16359, -16364, -16369, -16373, -16376, -16379, 
    -16381, -16383, -16384, -16384, -16384, -16383, -16381, -16379, -16376, -16373, -16369, 
    -16364, -16359, -16353, -16347, -16340, -16332, -16324, -16315, -16305, -16295, -16284, 
    -16273, -16261, -16248, -16235, -16221, -16207, -16192, -16176, -16160, -16143, -16125, 
    -16107, -16088, -16069, -16049, -16029, -16008, -15986, -15964, -15941, -15917, -15893, 
    -15868, -15843, -15817, -15791, -15763, -15736, -15707, -15679, -15649, -15619, -15588, 
    -15557, -15525, -15493, -15460, -15426, -15392, -15357, -15322, -15286, -15250, -15213, 
    -15175, -15137, -15098, -15059, -15019, -14978, -14937, -14896, -14854, -14811, -14768, 
    -14724, -14680, -14635, -14589, -14543, -14497, -14449, -14402, -14354, -14305, -14256, 
    -14206, -14155, -14104, -14053, -14001, -13949, -13896, -13842, -13788, -13733, -13678, 
    -13623, -13567, -13510, -13453, -13395, -13337, -13279, -13219, -13160, -13100, -13039, 
    -12978, -12916, -12854, -12792, -12729, -12665, -12601, -12537, -12472, -12406, -12340, 
    -12274, -12207, -12140, -12072, -12004, -11935, -11866, -11797, -11727, -11656, -11585, 
    -11514, -11442, -11370, -11297, -11224, -11151, -11077, -11003, -10928, -10853, -10778, 
    -10702, -10625, -10549, -10471, -10394, -10316, -10238, -10159, -10080, -10001, -9921, 
    -9841, -9760, -9679, -9598, -9516, -9434, -9352, -9269, -9186, -9102, -9019, -8935, 
    -8850, -8765, -8680, -8595, -8509, -8423, -8337, -8250, -8163, -8076, -7988, -7900, 
    -7812, -7723, -7635, -7545, -7456, -7366, -7276, -7186, -7096, -7005, -6914, -6823, 
    -6731, -6639, -6547, -6455, -6363, -6270, -6177, -6084, -5990, -5897, -5803, -5708, 
    -5614, -5520, -5425, -5330, -5235, -5139, -5044, -4948, -4852, -4756, -4660, -4563, 
    -4467, -4370, -4273, -4176, -4078, -3981, -3883, -3786, -3688, -3590, -3492, -3393, 
    -3295, -3196, -3098, -2999, -2900, -2801, -2702, -2603, -2503, -2404, -2305, -2205, 
    -2105, -2006, -1906, -1806, -1706, -1606, -1506, -1406, -1306, -1205, -1105, -1005, 
    -904, -804, -704, -603, -503, -402, -302, -201, -101
};

const fixed cosLUT[COS_LUT_SIZE] = {
    16383, 16383, 16382, 16380, 16378, 16375, 16372, 16368, 16363, 16358, 16352, 16346, 
    16339, 16331, 16323, 16314, 16304, 16294, 16283, 16272, 16260, 16247, 16234, 16220, 
    16206, 16191, 16175, 16159, 16142, 16124, 16106, 16088, 16068, 16048, 16028, 16007, 
    15985, 15963, 15940, 15916, 15892, 15867, 15842, 15816, 15790, 15762, 15735, 15706, 
    15678, 15648, 15618, 15587, 15556, 15524, 15492, 15459, 15425, 15391, 15356, 15321, 
    15285, 15249, 15212, 15174, 15136, 15097, 15058, 15018, 14977, 14936, 14895, 14853, 
    14810, 14767, 14723, 14679, 14634, 14588, 14542, 14496, 14449, 14401, 14353, 14304, 
    14255, 14205, 14154, 14104, 14052, 14000, 13948, 13895, 13841, 13787, 13733, 13678, 
    13622, 13566, 13509, 13452, 13394, 13336, 13278, 13219, 13159, 13099, 13038, 12977, 
    12915, 12853, 12791, 12728, 12664, 12600, 12536, 12471, 12405, 12339, 12273, 12206, 
    12139, 12071, 12003, 11934, 11865, 11796, 11726, 11655, 11585, 11513, 11441, 11369, 
    11297, 11224, 11150, 11076, 11002, 10927, 10852, 10777, 10701, 10625, 10548, 10471, 
    10393, 10315, 10237, 10158, 10079, 10000, 9920, 9840, 9759, 9678, 9597, 9515, 9433, 
    9351, 9268, 9185, 9102, 9018, 8934, 8850, 8765, 8680, 8594, 8509, 8423, 8336, 8249, 
    8162, 8075, 7988, 7900, 7811, 7723, 7634, 7545, 7456, 7366, 7276, 7186, 7095, 7005, 
    6914, 6822, 6731, 6639, 6547, 6455, 6362, 6270, 6177, 6083, 5990, 5896, 5802, 5708, 
    5614, 5519, 5425, 5330, 5234, 5139, 5044, 4948, 4852, 4756, 4659, 4563, 4466, 4370, 
    4273, 4175, 4078, 3981, 3883, 3785, 3688, 3590, 3491, 3393, 3295, 3196, 3098, 2999, 
    2900, 2801, 2702, 2603, 2503, 2404, 2304, 2205, 2105, 2005, 1906, 1806, 1706, 1606, 
    1506, 1406, 1305, 1205, 1105, 1005, 904, 804, 703, 603, 503, 402, 302, 201, 101, 
    0, -101, -201, -302, -402, -503, -603, -704, -804, -904, -1005, -1105, -1205, -1306, 
    -1406, -1506, -1606, -1706, -1806, -1906, -2006, -2105, -2205, -2305, -2404, -2503, 
    -2603, -2702, -2801, -2900, -2999, -3098, -3196, -3295, -3393, -3492, -3590, -3688, 
    -3786, -3883, -3981, -4078, -4176, -4273, -4370, -4467, -4563, -4660, -4756, -4852, 
    -4948, -5044, -5139, -5235, -5330, -5425, -5520, -5614, -5708, -5803, -5897, -5990, 
    -6084, -6177, -6270, -6363, -6455, -6547, -6639, -6731, -6823, -6914, -7005, -7096, 
    -7186, -7276, -7366, -7456, -7545, -7635, -7723, -7812, -7900, -7988, -8076, -8163, 
    -8250, -8337, -8423, -8509, -8595, -8680, -8765, -8850, -8935, -9019, -9102, -9186, 
    -9269, -9352, -9434, -9516, -9598, -9679, -9760, -9841, -9921, -10001, -10080, -10159, 
    -10238, -10316, -10394, -10471, -10549, -10625, -10702, -10778, -10853, -10928, -11003, 
    -11077, -11151, -11224, -11297, -11370, -11442, -11514, -11585, -11656, -11727, -11797, 
    -11866, -11935, -12004, -12072, -12140, -12207, -12274, -12340, -12406, -12472, -12537, 
    -12601, -12665, -12729, -12792, -12854, -12916, -12978, -13039, -13100, -13160, -13219, 
    -13279, -13337, -13395, -13453, -13510, -13567, -13623, -13678, -13733, -13788, -13842, 
    -13896, -13949, -14001, -14053, -14104, -14155, -14206, -14256, -14305, -14354, -14402, 
    -14449, -14497, -14543, -14589, -14635, -14680, -14724, -14768, -14811, -14854, -14896, 
    -14937, -14978, -15019, -15059, -15098, -15137, -15175, -15213, -15250, -15286, -15322, 
    -15357, -15392, -15426, -15460, -15493, -15525, -15557, -15588, -15619, -15649, -15679, 
    -15707, -15736, -15763, -15791, -15817, -15843, -15868, -15893, -15917, -15941, -15964, 
    -15986, -16008, -16029, -16049, -16069, -16088, -16107, -16125, -16143, -16160, -16176, 
    -16192, -16207, -16221, -16235, -16248, -16261, -16273, -16284, -16295, -16305, -16315, 
    -16324, -16332, -16340, -16347, -16353, -16359, -16364, -16369, -16373, -16376, -16379, 
    -16381, -16383, -16384
};