
//C4/C2 of experimental data points at FXT energies
//0-5%, cbwc method, FXT data
double FXT_CBWC_R42_x   [6]={    3.0,     3.2,    3.5,    3.9,    4.5,   5.2};//x axis
double FXT_CBWC_R42_muB [6]={    750,     699,    670,    633,    590,   540};//mu_B
double FXT_CBWC_R42_ex  [6]={      0,       0,      0,      0,      0,     0};//x axis error
double FXT_CBWC_R42     [6]={-0.8457, -0.3476, 0.0275, 0.2420, 1.1951, 99999};//central value
double FXT_CBWC_R42_stat[6]={ 0.0862,  0.0670, 0.1707, 0.1606, 0.4257,     0};//stat. error
double FXT_CBWC_R42_sys [6]={ 0.8219,  0.2901, 0.2140, 0.1434, 0.3603,     0};//sys. error

//0-5%, method 2, FXT data
double FXT_Method2_R42_x   [6]={   3.0,    3.2,      3.5,    3.9,    4.5,    5.2};
double FXT_Method2_R42_muB [6]={   750,    699,      670,    633,    590,    540};
double FXT_Method2_R42_ex  [6]={     0,      0,        0,      0,      0,      0};
double FXT_Method2_R42     [6]={0.0082, 0.1827, 0.349245, 0.4167, 0.9216, 0.9080};
double FXT_Method2_R42_stat[6]={0.0428, 0.0600, 0.088172, 0.1156, 0.1671, 0.1054};
double FXT_Method2_R42_sys [6]={0.1576, 0.1825, 0.168719, 0.1258, 0.1205, 0.1601};

//C4/C2 of experimental data points at collider energies
//0-5%, cbwc method, Collider data
double Coll_CBWC_R42_x   [9]={     7.7,      9.2,      11.5,      14.6,      17.3,      19.6,       27.,       39.,    54.4};
double Coll_CBWC_R42_muB [9]={     420,      372,       316,       262,       230,       206,       156,       112,      85};
double Coll_CBWC_R42_ex  [9]={       0,        0,         0,         0,         0,         0,         0,         0,       0};
double Coll_CBWC_R42     [9]={0.417735, 0.550703,  0.381199,  0.430751,  0.356063,  0.328484,  0.602046,  0.739693, 0.69715};
double Coll_CBWC_R42_stat[9]={0.246897, 0.183197,  0.137369,  0.104085,  0.120039,  0.0733153, 0.0950052, 0.147006, 0.053074};
double Coll_CBWC_R42_sys [9]={0.134838, 0.0739699, 0.0537708, 0.0403519, 0.0795194, 0.0404057, 0.0304235, 0.135754, 0.0482269};

//UrQMD C4/C2 at FXT energies with scaling on RefMult3
//0-5%, cbwc method, urqmd at FXT energies
double FXT_CBWC_R42_UrQMD_x   [6]={      3,     3.2,     3.5,    3.9,    4.5,    5.2};
double FXT_CBWC_R42_UrQMD_muB [6]={    750,     699,     670,    633,    590,    540};
double FXT_CBWC_R42_UrQMD_ex  [6]={      0,       0,       0,      0,      0,      0};
double FXT_CBWC_R42_UrQMD     [6]={-1.3789, -0.9652, -0.2578, 0.1415, 0.3870, 0.5157};
double FXT_CBWC_R42_UrQMD_stat[6]={ 0.0920,  0.0662,  0.0600, 0.0649, 0.0636, 0.1011};
double FXT_CBWC_R42_UrQMD_sys [6]={ 0.0437,  0.0119,  0.0204, 0.0188, 0.0411, 0.0000};
double FXT_CBWC_R42_UrQMD_tot [6]={ 0.1019,  0.0673,  0.0633, 0.0676, 0.0757, 0.1011};//sqrt(stat^2+sys^2)

//0-5%, method 2, urqmd at fxt energies
double FXT_Method2_R42_UrQMD_x   [6]={   3.0,    3.2,    3.5,    3.9,    4.5,     5.2};
double FXT_Method2_R42_UrQMD_muB [6]={   750,    699,    670,    633,    590,     540};
double FXT_Method2_R42_UrQMD_ex  [6]={     0,      0,      0,      0,      0,       0};

double FXT_Method2_R42_UrQMD     [6]={0.0864, 0.1374, 0.3113, 0.2873, 0.3579,  0.5408};
double FXT_Method2_R42_UrQMD_stat[6]={0.0853, 0.0653, 0.0602, 0.0629, 0.0874,  0.0954};
 
//0-5%, cbwc method, urqmd at collider energies
double Coll_CBWC_R42_UrQMD_x   [9]={   7.7,     9.2,    11.5,    14.6,    17.3,    19.6,      27,     39,   54.4};
double Coll_CBWC_R42_UrQMD_muB [9]={   420,     372,    316,      262,     230,     206,     156,    112,     85};
double Coll_CBWC_R42_UrQMD_ex  [9]={     0,       0,       0,       0,       0,       0,       0,      0,      0};
double Coll_CBWC_R42_UrQMD     [9]={0.4755,  0.4628,  0.5257,  0.5962,  0.6787,  0.7332,  0.8714, 0.8600, 0.8397};
double Coll_CBWC_R42_UrQMD_stat[9]={0.0644,  0.0628,  0.0677,  0.0708,  0.0529,  0.0581,  0.0517, 0.0457, 0.0557};

