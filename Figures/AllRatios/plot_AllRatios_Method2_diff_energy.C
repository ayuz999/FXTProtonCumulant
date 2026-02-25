#include "../../data_points/Collider_CBWC_energy_dependence_all.h"
#include "../../data_points/UrQMD_Collider_CBWC_energy_dependence_all.h"

#include "../../data_points/FXT_Method2_energy_dependence_all.h"
#include "../../data_points/UrQMD_FXT_Method2_energy_dependence_all.h"

#include "../color_definition.h"

//0-5% 
void plot_AllRatios_Method2_diff_energy(){

  //user defined colors
  Int_t cidx1 = TColor::GetFreeColorIndex();
  Int_t cidx2 = cidx1 + 1;
  Int_t cidx3 = cidx1 + 2;
  Int_t cidx4 = cidx1 + 3;
  Int_t cidx5 = cidx1 + 4;
  Int_t cidx6 = cidx1 + 5;
  TColor* cl1 = new TColor(cidx1, float_cl1[0]/255., float_cl1[1]/255., float_cl1[2]/255.);
  TColor* cl2 = new TColor(cidx2, float_cl2[0]/255., float_cl2[1]/255., float_cl2[2]/255.);
  TColor* cl3 = new TColor(cidx3, float_cl3[0]/255., float_cl3[1]/255., float_cl3[2]/255.);
  TColor* cl4 = new TColor(cidx4, float_cl4[0]/255., float_cl4[1]/255., float_cl4[2]/255.);
  TColor* cl5 = new TColor(cidx5, float_cl5[0]/255., float_cl5[1]/255., float_cl5[2]/255.);
  TColor* cl6 = new TColor(cidx6, float_cl6[0]/255., float_cl6[1]/255., float_cl6[2]/255.);


 
  //FXT data, method 2

  //difference
  //data(0-5%)   - UrQMD(0-5%)
  double FXT_diff1     [6][6];
  double FXT_diff1_stat[6][6];
  double FXT_diff1_sys [6][6];
  for(int ierg=0;ierg<6;++ierg){
    FXT_diff1     [0][ierg] =          FXT_Method2_R21_Cent05[ierg]            -     UrQMD_FXT_Method2_R21_Cent05[ierg];
    FXT_diff1_stat[0][ierg] = sqrt(pow(FXT_Method2_R21_Cent05_stat[ierg], 2.)  + pow(UrQMD_FXT_Method2_R21_Cent05_stat[ierg] ,2.) );
    FXT_diff1_sys [0][ierg] =          FXT_Method2_R21_Cent05_sys[ierg];
    FXT_diff1     [1][ierg] =          FXT_Method2_R31_Cent05[ierg]            -     UrQMD_FXT_Method2_R31_Cent05[ierg];
    FXT_diff1_stat[1][ierg] = sqrt(pow(FXT_Method2_R31_Cent05_stat[ierg], 2.)  + pow(UrQMD_FXT_Method2_R31_Cent05_stat[ierg] ,2.) );
    FXT_diff1_sys [1][ierg] =          FXT_Method2_R31_Cent05_sys[ierg];
    FXT_diff1     [2][ierg] =          FXT_Method2_R42_Cent05[ierg]            -     UrQMD_FXT_Method2_R42_Cent05[ierg];
    FXT_diff1_stat[2][ierg] = sqrt(pow(FXT_Method2_R42_Cent05_stat[ierg], 2.)  + pow(UrQMD_FXT_Method2_R42_Cent05_stat[ierg] ,2.) );
    FXT_diff1_sys [2][ierg] =          FXT_Method2_R42_Cent05_sys[ierg];
    FXT_diff1     [3][ierg] =          FXT_Method2_FC21_Cent05[ierg]           -     UrQMD_FXT_Method2_FC21_Cent05[ierg];
    FXT_diff1_stat[3][ierg] = sqrt(pow(FXT_Method2_FC21_Cent05_stat[ierg], 2.) + pow(UrQMD_FXT_Method2_FC21_Cent05_stat[ierg] ,2.) );
    FXT_diff1_sys [3][ierg] =          FXT_Method2_FC21_Cent05_sys[ierg];
    FXT_diff1     [4][ierg] =          FXT_Method2_FC31_Cent05[ierg]           -     UrQMD_FXT_Method2_FC31_Cent05[ierg];
    FXT_diff1_stat[4][ierg] = sqrt(pow(FXT_Method2_FC31_Cent05_stat[ierg], 2.) + pow(UrQMD_FXT_Method2_FC31_Cent05_stat[ierg] ,2.) );
    FXT_diff1_sys [4][ierg] =          FXT_Method2_FC31_Cent05_sys[ierg];
    FXT_diff1     [5][ierg] =          FXT_Method2_FC41_Cent05[ierg]           -     UrQMD_FXT_Method2_FC41_Cent05[ierg];
    FXT_diff1_stat[5][ierg] = sqrt(pow(FXT_Method2_FC41_Cent05_stat[ierg], 2.) + pow(UrQMD_FXT_Method2_FC41_Cent05_stat[ierg] ,2.) );
    FXT_diff1_sys [5][ierg] =          FXT_Method2_FC41_Cent05_sys[ierg];
  }
  //data(0-5%)   - data(50-60%)
  double FXT_diff2     [6][6];
  double FXT_diff2_stat[6][6];
  double FXT_diff2_sys [6][6];
  for(int ierg=0;ierg<6;++ierg){
    FXT_diff2     [0][ierg] =          FXT_Method2_R21_Cent05[ierg]            -     FXT_Method2_R21_Cent5060[ierg];
    FXT_diff2_stat[0][ierg] = sqrt(pow(FXT_Method2_R21_Cent05_stat[ierg], 2.)  + pow(FXT_Method2_R21_Cent5060_stat[ierg] ,2.) );
    FXT_diff2_sys [0][ierg] = sqrt(pow(FXT_Method2_R21_Cent05_sys[ierg],  2.)  + pow(FXT_Method2_R21_Cent5060_sys[ierg], 2.) ); 
    FXT_diff2     [1][ierg] =          FXT_Method2_R31_Cent05[ierg]            -     FXT_Method2_R31_Cent5060[ierg];
    FXT_diff2_stat[1][ierg] = sqrt(pow(FXT_Method2_R31_Cent05_stat[ierg], 2.)  + pow(FXT_Method2_R31_Cent5060_stat[ierg] ,2.) );
    FXT_diff2_sys [1][ierg] = sqrt(pow(FXT_Method2_R31_Cent05_sys[ierg],  2.)  + pow(FXT_Method2_R31_Cent5060_sys[ierg], 2.) ); 
    FXT_diff2     [2][ierg] =          FXT_Method2_R42_Cent05[ierg]            -     FXT_Method2_R42_Cent5060[ierg];
    FXT_diff2_stat[2][ierg] = sqrt(pow(FXT_Method2_R42_Cent05_stat[ierg], 2.)  + pow(FXT_Method2_R42_Cent5060_stat[ierg] ,2.) );
    FXT_diff2_sys [2][ierg] = sqrt(pow(FXT_Method2_R42_Cent05_sys[ierg],  2.)  + pow(FXT_Method2_R42_Cent5060_sys[ierg], 2.) ); 
    FXT_diff2     [3][ierg] =          FXT_Method2_FC21_Cent05[ierg]           -     FXT_Method2_FC21_Cent5060[ierg];
    FXT_diff2_stat[3][ierg] = sqrt(pow(FXT_Method2_FC21_Cent05_stat[ierg], 2.) + pow(FXT_Method2_FC21_Cent5060_stat[ierg] ,2.) );
    FXT_diff2_sys [3][ierg] = sqrt(pow(FXT_Method2_FC21_Cent05_sys[ierg],  2.) + pow(FXT_Method2_FC21_Cent5060_sys[ierg], 2.) ); 
    FXT_diff2     [4][ierg] =          FXT_Method2_FC31_Cent05[ierg]           -     FXT_Method2_FC31_Cent5060[ierg];
    FXT_diff2_stat[4][ierg] = sqrt(pow(FXT_Method2_FC31_Cent05_stat[ierg], 2.) + pow(FXT_Method2_FC31_Cent5060_stat[ierg] ,2.) );
    FXT_diff2_sys [4][ierg] = sqrt(pow(FXT_Method2_FC31_Cent05_sys[ierg],  2.) + pow(FXT_Method2_FC31_Cent5060_sys[ierg], 2.) ); 
    FXT_diff2     [5][ierg] =          FXT_Method2_FC41_Cent05[ierg]           -     FXT_Method2_FC41_Cent5060[ierg];
    FXT_diff2_stat[5][ierg] = sqrt(pow(FXT_Method2_FC41_Cent05_stat[ierg], 2.) + pow(FXT_Method2_FC41_Cent5060_stat[ierg] ,2.) );
    FXT_diff2_sys [5][ierg] = sqrt(pow(FXT_Method2_FC41_Cent05_sys[ierg],  2.) + pow(FXT_Method2_FC41_Cent5060_sys[ierg], 2.) ); 
  }

  //data(50-60%) - UrQMD(50-60%)
  double FXT_diff3     [6][6];
  double FXT_diff3_stat[6][6];
  double FXT_diff3_sys [6][6];
  for(int ierg=0;ierg<6;++ierg){
    FXT_diff3     [0][ierg] =          FXT_Method2_R21_Cent5060[ierg]            -     UrQMD_FXT_Method2_R21_Cent5060[ierg];
    FXT_diff3_stat[0][ierg] = sqrt(pow(FXT_Method2_R21_Cent5060_stat[ierg], 2.)  + pow(UrQMD_FXT_Method2_R21_Cent5060_stat[ierg] ,2.) );
    FXT_diff3_sys [0][ierg] =          FXT_Method2_R21_Cent5060_sys[ierg];
    FXT_diff3     [1][ierg] =          FXT_Method2_R31_Cent5060[ierg]            -     UrQMD_FXT_Method2_R31_Cent5060[ierg];
    FXT_diff3_stat[1][ierg] = sqrt(pow(FXT_Method2_R31_Cent5060_stat[ierg], 2.)  + pow(UrQMD_FXT_Method2_R31_Cent5060_stat[ierg] ,2.) );
    FXT_diff3_sys [1][ierg] =          FXT_Method2_R31_Cent5060_sys[ierg];
    FXT_diff3     [2][ierg] =          FXT_Method2_R42_Cent5060[ierg]            -     UrQMD_FXT_Method2_R42_Cent5060[ierg];
    FXT_diff3_stat[2][ierg] = sqrt(pow(FXT_Method2_R42_Cent5060_stat[ierg], 2.)  + pow(UrQMD_FXT_Method2_R42_Cent5060_stat[ierg] ,2.) );
    FXT_diff3_sys [2][ierg] =          FXT_Method2_R42_Cent5060_sys[ierg];
    FXT_diff3     [3][ierg] =          FXT_Method2_FC21_Cent5060[ierg]           -     UrQMD_FXT_Method2_FC21_Cent5060[ierg];
    FXT_diff3_stat[3][ierg] = sqrt(pow(FXT_Method2_FC21_Cent5060_stat[ierg], 2.) + pow(UrQMD_FXT_Method2_FC21_Cent5060_stat[ierg] ,2.) );
    FXT_diff3_sys [3][ierg] =          FXT_Method2_FC21_Cent5060_sys[ierg];
    FXT_diff3     [4][ierg] =          FXT_Method2_FC31_Cent5060[ierg]           -     UrQMD_FXT_Method2_FC31_Cent5060[ierg];
    FXT_diff3_stat[4][ierg] = sqrt(pow(FXT_Method2_FC31_Cent5060_stat[ierg], 2.) + pow(UrQMD_FXT_Method2_FC31_Cent5060_stat[ierg] ,2.) );
    FXT_diff3_sys [4][ierg] =          FXT_Method2_FC31_Cent5060_sys[ierg];
    FXT_diff3     [5][ierg] =          FXT_Method2_FC41_Cent5060[ierg]           -     UrQMD_FXT_Method2_FC41_Cent5060[ierg];
    FXT_diff3_stat[5][ierg] = sqrt(pow(FXT_Method2_FC41_Cent5060_stat[ierg], 2.) + pow(UrQMD_FXT_Method2_FC41_Cent5060_stat[ierg] ,2.) );
    FXT_diff3_sys [5][ierg] =          FXT_Method2_FC41_Cent5060_sys[ierg];
  }
  

  TGraphErrors* tg1[6];
  TGraphErrors* tg2[6];
  TGraphErrors* tg3[6];
  TGraphErrors* tg1_sys[6];
  TGraphErrors* tg2_sys[6];
  TGraphErrors* tg3_sys[6];
  double dummy_ex6[6]={0,0,0, 0,0,0};
  
  for(int icum=0;icum<6;++icum){
    tg1[icum]     = new TGraphErrors(6, FXT_Method2_Energy, FXT_diff1[icum], dummy_ex6, FXT_diff1_stat[icum]);
    tg1_sys[icum] = new TGraphErrors(6, FXT_Method2_Energy, FXT_diff1[icum], dummy_ex6, FXT_diff1_sys[icum]);
    tg2[icum]     = new TGraphErrors(6, FXT_Method2_Energy, FXT_diff2[icum], dummy_ex6, FXT_diff2_stat[icum]);
    tg2_sys[icum] = new TGraphErrors(6, FXT_Method2_Energy, FXT_diff2[icum], dummy_ex6, FXT_diff2_sys[icum]);
    tg3[icum]     = new TGraphErrors(6, FXT_Method2_Energy, FXT_diff3[icum], dummy_ex6, FXT_diff3_stat[icum]);
    tg3_sys[icum] = new TGraphErrors(6, FXT_Method2_Energy, FXT_diff3[icum], dummy_ex6, FXT_diff3_sys[icum]);

    tg1    [icum]->SetMarkerStyle(20);
    tg1_sys[icum]->SetMarkerStyle(20);
    tg1    [icum]->SetMarkerSize(0.9); 
    tg1_sys[icum]->SetMarkerSize(0.9); 
    tg1_sys[icum]->SetLineWidth(4);
    tg1_sys[icum]->SetLineColorAlpha(1,0.3);

    tg2    [icum]->SetMarkerStyle(25);
    tg2_sys[icum]->SetMarkerStyle(25);
    tg2    [icum]->SetMarkerSize(0.9); 
    tg2_sys[icum]->SetMarkerSize(0.9); 
    tg2_sys[icum]->SetLineWidth(4);
    tg2    [icum]->SetLineColorAlpha(4,0.3);
    tg2_sys[icum]->SetLineColorAlpha(4,0.3);
    tg2    [icum]->SetMarkerColorAlpha(4,0.3);
    tg2_sys[icum]->SetMarkerColorAlpha(4,0.3);

    tg3    [icum]->SetMarkerStyle(24);
    tg3_sys[icum]->SetMarkerStyle(24);
    tg3    [icum]->SetMarkerSize(0.9); 
    tg3_sys[icum]->SetMarkerSize(0.9); 
    tg3_sys[icum]->SetLineWidth(4);
    tg3    [icum]->SetMarkerColorAlpha(2,0.3);
    tg3_sys[icum]->SetMarkerColorAlpha(2,0.3);
    tg3    [icum]->SetLineColorAlpha(2,0.3);
    tg3_sys[icum]->SetLineColorAlpha(2,0.3);
  }


  //Collider, data

  //difference
  //data(0-5%)   - UrQMD(0-5%)
  double Coll_diff1     [6][7];
  double Coll_diff1_stat[6][7];
  double Coll_diff1_sys [6][7];
  for(int ierg=0;ierg<7;++ierg){
    Coll_diff1     [0][ierg] =          cObservables    [0][0][ierg]          - UrQMD_Collider_CBWC_Netp_R2T_Cent05[ierg];
    Coll_diff1_stat[0][ierg] = sqrt(pow(cObservables_sts[0][0][ierg], 2.) + pow(UrQMD_Collider_CBWC_Netp_R2T_Cent05_stat[ierg], 2.));
    Coll_diff1_sys [0][ierg] =          cObservables_sys[0][0][ierg];
    Coll_diff1     [1][ierg] =          cObservables    [1][0][ierg]          - UrQMD_Collider_CBWC_Netp_R31_Cent05[ierg];
    Coll_diff1_stat[1][ierg] = sqrt(pow(cObservables_sts[1][0][ierg], 2.) + pow(UrQMD_Collider_CBWC_Netp_R31_Cent05_stat[ierg], 2.));
    Coll_diff1_sys [1][ierg] =          cObservables_sys[1][0][ierg];
    Coll_diff1     [2][ierg] =          cObservables    [2][0][ierg]          - UrQMD_Collider_CBWC_Netp_R42_Cent05[ierg];
    Coll_diff1_stat[2][ierg] = sqrt(pow(cObservables_sts[2][0][ierg], 2.) + pow(UrQMD_Collider_CBWC_Netp_R42_Cent05_stat[ierg], 2.));
    Coll_diff1_sys [2][ierg] =          cObservables_sys[2][0][ierg];
    Coll_diff1     [3][ierg] =          cObservables    [3][0][ierg]          - UrQMD_Collider_CBWC_Pro_FC21_Cent05[ierg];
    Coll_diff1_stat[3][ierg] = sqrt(pow(cObservables_sts[3][0][ierg], 2.) + pow(UrQMD_Collider_CBWC_Pro_FC21_Cent05_stat[ierg], 2.));
    Coll_diff1_sys [3][ierg] =          cObservables_sys[3][0][ierg];
    Coll_diff1     [4][ierg] =          cObservables    [4][0][ierg]          - UrQMD_Collider_CBWC_Pro_FC31_Cent05[ierg];
    Coll_diff1_stat[4][ierg] = sqrt(pow(cObservables_sts[4][0][ierg], 2.) + pow(UrQMD_Collider_CBWC_Pro_FC31_Cent05_stat[ierg], 2.));
    Coll_diff1_sys [4][ierg] =          cObservables_sys[4][0][ierg];
    Coll_diff1     [5][ierg] =          cObservables    [5][0][ierg]          - UrQMD_Collider_CBWC_Pro_FC41_Cent05[ierg];
    Coll_diff1_stat[5][ierg] = sqrt(pow(cObservables_sts[5][0][ierg], 2.) + pow(UrQMD_Collider_CBWC_Pro_FC41_Cent05_stat[ierg], 2.));
    Coll_diff1_sys [5][ierg] =          cObservables_sys[5][0][ierg];
  }

  //data(0-5%)   - data(70-80%)
  double Coll_diff2     [6][7];
  double Coll_diff2_stat[6][7];
  double Coll_diff2_sys [6][7];
  for(int ierg=0;ierg<7;++ierg){
    Coll_diff2     [0][ierg] =          cObservables    [0][0][ierg]          - cObservables    [0][1][ierg];
    Coll_diff2_stat[0][ierg] = sqrt(pow(cObservables_sts[0][0][ierg], 2.) + pow(cObservables_sts[0][1][ierg], 2.));
    Coll_diff2_sys [0][ierg] = sqrt(pow(cObservables_sys[0][0][ierg], 2.) + pow(cObservables_sys[0][1][ierg], 2.));
    Coll_diff2     [1][ierg] =          cObservables    [1][0][ierg]          - cObservables    [1][1][ierg];
    Coll_diff2_stat[1][ierg] = sqrt(pow(cObservables_sts[1][0][ierg], 2.) + pow(cObservables_sts[1][1][ierg], 2.));
    Coll_diff2_sys [1][ierg] = sqrt(pow(cObservables_sys[1][0][ierg], 2.) + pow(cObservables_sys[1][1][ierg], 2.));
    Coll_diff2     [2][ierg] =          cObservables    [2][0][ierg]          - cObservables    [2][1][ierg];
    Coll_diff2_stat[2][ierg] = sqrt(pow(cObservables_sts[2][0][ierg], 2.) + pow(cObservables_sts[2][1][ierg], 2.));
    Coll_diff2_sys [2][ierg] = sqrt(pow(cObservables_sys[2][0][ierg], 2.) + pow(cObservables_sys[2][1][ierg], 2.));
    Coll_diff2     [3][ierg] =          cObservables    [3][0][ierg]          - cObservables    [3][1][ierg];
    Coll_diff2_stat[3][ierg] = sqrt(pow(cObservables_sts[3][0][ierg], 2.) + pow(cObservables_sts[3][1][ierg], 2.));
    Coll_diff2_sys [3][ierg] = sqrt(pow(cObservables_sys[3][0][ierg], 2.) + pow(cObservables_sys[3][1][ierg], 2.));
    Coll_diff2     [4][ierg] =          cObservables    [4][0][ierg]          - cObservables    [4][1][ierg];
    Coll_diff2_stat[4][ierg] = sqrt(pow(cObservables_sts[4][0][ierg], 2.) + pow(cObservables_sts[4][1][ierg], 2.));
    Coll_diff2_sys [4][ierg] = sqrt(pow(cObservables_sys[4][0][ierg], 2.) + pow(cObservables_sys[4][1][ierg], 2.));
    Coll_diff2     [5][ierg] =          cObservables    [5][0][ierg]          - cObservables    [5][1][ierg];
    Coll_diff2_stat[5][ierg] = sqrt(pow(cObservables_sts[5][0][ierg], 2.) + pow(cObservables_sts[5][1][ierg], 2.));
    Coll_diff2_sys [5][ierg] = sqrt(pow(cObservables_sys[5][0][ierg], 2.) + pow(cObservables_sys[5][1][ierg], 2.));
  }

  //data(70-80%) - UrQMD(70-80%)
  double Coll_diff3     [6][7];
  double Coll_diff3_stat[6][7];
  double Coll_diff3_sys [6][7];
  for(int ierg=0;ierg<7;++ierg){
    Coll_diff3     [0][ierg] =          cObservables    [0][1][ierg]      -     UrQMD_Collider_CBWC_Netp_R2T_Cent7080[ierg];
    Coll_diff3_stat[0][ierg] = sqrt(pow(cObservables_sts[0][1][ierg], 2.) + pow(UrQMD_Collider_CBWC_Netp_R2T_Cent7080_stat[ierg], 2.));
    Coll_diff3_sys [0][ierg] =          cObservables_sys[0][1][ierg];
    Coll_diff3     [1][ierg] =          cObservables    [1][1][ierg]      -     UrQMD_Collider_CBWC_Netp_R31_Cent7080[ierg];
    Coll_diff3_stat[1][ierg] = sqrt(pow(cObservables_sts[1][1][ierg], 2.) + pow(UrQMD_Collider_CBWC_Netp_R31_Cent7080_stat[ierg], 2.));
    Coll_diff3_sys [1][ierg] =          cObservables_sys[1][1][ierg];
    Coll_diff3     [2][ierg] =          cObservables    [2][1][ierg]      -     UrQMD_Collider_CBWC_Netp_R42_Cent7080[ierg];
    Coll_diff3_stat[2][ierg] = sqrt(pow(cObservables_sts[2][1][ierg], 2.) + pow(UrQMD_Collider_CBWC_Netp_R42_Cent7080_stat[ierg], 2.));
    Coll_diff3_sys [2][ierg] =          cObservables_sys[2][1][ierg];

    Coll_diff3     [3][ierg] =          cObservables    [3][1][ierg]      -     UrQMD_Collider_CBWC_Pro_FC21_Cent7080[ierg];
    Coll_diff3_stat[3][ierg] = sqrt(pow(cObservables_sts[3][1][ierg], 2.) + pow(UrQMD_Collider_CBWC_Pro_FC21_Cent7080_stat[ierg], 2));
    Coll_diff3_sys [3][ierg] =          cObservables_sys[3][1][ierg];

    Coll_diff3     [4][ierg] =          cObservables    [4][1][ierg]      -     UrQMD_Collider_CBWC_Pro_FC31_Cent7080[ierg];
    Coll_diff3_stat[4][ierg] = sqrt(pow(cObservables_sts[4][1][ierg], 2.) + pow(UrQMD_Collider_CBWC_Pro_FC31_Cent7080_stat[ierg], 2.));
    Coll_diff3_sys [4][ierg] =          cObservables_sys[4][1][ierg];
    Coll_diff3     [5][ierg] =          cObservables    [5][1][ierg]      -     UrQMD_Collider_CBWC_Pro_FC41_Cent7080[ierg];
    Coll_diff3_stat[5][ierg] = sqrt(pow(cObservables_sts[5][1][ierg], 2.) + pow(UrQMD_Collider_CBWC_Pro_FC41_Cent7080_stat[ierg], 2.));
    Coll_diff3_sys [5][ierg] =          cObservables_sys[5][1][ierg];
  }

  TGraphErrors* tg4[6];
  TGraphErrors* tg5[6];
  TGraphErrors* tg6[6];
  TGraphErrors* tg4_sys[6];
  TGraphErrors* tg5_sys[6];
  TGraphErrors* tg6_sys[6];
  double dummy_ex7[7]={0,0,0, 0,0,0, 0};
  double Coll_Energies[7]={7.7,9.2,11.5,14.6,17.3,19.6,27};

  for(int icum=0;icum<6;++icum){
    tg4[icum]     = new TGraphErrors(7, Coll_Energies, Coll_diff1[icum], dummy_ex7, Coll_diff1_stat[icum]);
    tg4_sys[icum] = new TGraphErrors(7, Coll_Energies, Coll_diff1[icum], dummy_ex7, Coll_diff1_sys[icum]);
    tg5[icum]     = new TGraphErrors(7, Coll_Energies, Coll_diff2[icum], dummy_ex7, Coll_diff2_stat[icum]);
    tg5_sys[icum] = new TGraphErrors(7, Coll_Energies, Coll_diff2[icum], dummy_ex7, Coll_diff2_sys[icum]);
    tg6[icum]     = new TGraphErrors(7, Coll_Energies, Coll_diff3[icum], dummy_ex7, Coll_diff3_stat[icum]);
    tg6_sys[icum] = new TGraphErrors(7, Coll_Energies, Coll_diff3[icum], dummy_ex7, Coll_diff3_sys[icum]);

    tg4    [icum]->SetMarkerStyle(20);
    tg4_sys[icum]->SetMarkerStyle(20);
    tg4    [icum]->SetMarkerSize(0.9); 
    tg4_sys[icum]->SetMarkerSize(0.9); 
    tg4_sys[icum]->SetLineWidth(4);
    tg4_sys[icum]->SetLineColorAlpha(1,0.3);

    tg5    [icum]->SetMarkerStyle(25);
    tg5_sys[icum]->SetMarkerStyle(25);
    tg5    [icum]->SetMarkerSize(0.9); 
    tg5_sys[icum]->SetMarkerSize(0.9); 
    tg5_sys[icum]->SetLineWidth(4);
    tg5    [icum]->SetLineColorAlpha(4,0.3);
    tg5_sys[icum]->SetLineColorAlpha(4,0.3);
    tg5    [icum]->SetMarkerColorAlpha(4,0.3);
    tg5_sys[icum]->SetMarkerColorAlpha(4,0.3);

    tg6    [icum]->SetMarkerStyle(24);
    tg6_sys[icum]->SetMarkerStyle(24);
    tg6    [icum]->SetMarkerSize(0.9); 
    tg6_sys[icum]->SetMarkerSize(0.9); 
    tg6_sys[icum]->SetLineWidth(4);
    tg6    [icum]->SetMarkerColorAlpha(2,0.3);
    tg6_sys[icum]->SetMarkerColorAlpha(2,0.3);
    tg6    [icum]->SetLineColorAlpha(2,0.3);
    tg6_sys[icum]->SetLineColorAlpha(2,0.3);
  }


  //====================================================================
  //start to plot
  TCanvas *cas = new TCanvas("cas","",1000,550);
  cas->cd();

  gStyle->SetLabelFont(43,"XY");
  gStyle->SetLabelSize(20,"XY");



  TPad *pad[6];
  float leftmargin= 0.05;
  float width = (1-leftmargin)/3.;
  float btmmargin = 0.11;
  float height = (1-btmmargin)/2.;
  pad[0] = new TPad("pad1","",leftmargin,          height+btmmargin,leftmargin+width,  1.);
  pad[1] = new TPad("pad2","",leftmargin+width,    height+btmmargin,leftmargin+2*width,1.);
  pad[2] = new TPad("pad3","",leftmargin+2*width,  height+btmmargin,leftmargin+3*width,1.);
  pad[3] = new TPad("pad4","",leftmargin,          btmmargin,       leftmargin+width,    btmmargin+height);
  pad[4] = new TPad("pad5","",leftmargin+width,    btmmargin,       leftmargin+2*width,  btmmargin+height);
  pad[5] = new TPad("pad6","",leftmargin+2*width,  btmmargin,       leftmargin+3*width,  btmmargin+height);
  for(int i=0;i<6;++i){
    pad[i]->Draw();
  }

  float x1 = 2.4;
  float x2 = 36;

  TLine l1(x1, 1, x2, 1);
  l1.SetLineStyle(2);
  l1.SetLineColorAlpha(1,0.6);
  TLine l2(x1, 0, x2, 0);
  l2.SetLineStyle(4);
  l2.SetLineColorAlpha(1,0.6);

  pad[0]->cd();
  gPad->SetBottomMargin(0);
  gPad->SetLeftMargin(0.12);
  gPad->SetRightMargin(0.03);
  TH1D* h1 = (TH1D*)gPad->DrawFrame(x1, -0.12, x2, 0.17);
  h1->GetXaxis()->SetNoExponent();
  h1->GetXaxis()->SetMoreLogLabels();
  h1->GetYaxis()->SetNdivisions(505);
  h1->GetYaxis()->SetLabelOffset(0.01);
  gPad->SetTicks(1,1);
  gPad->SetLogx();
  TBox yellbox1(x1,-0.12, 5, 0.17);
  yellbox1.SetFillColorAlpha(5, 0.2);
  yellbox1.SetLineColorAlpha(5, 0.2);
  yellbox1.Draw();
  l2.Draw();
  tg1[0]->Draw("p");
  tg1_sys[0]->Draw("zp");
  //tg2[0]->Draw("p");
  //tg2_sys[0]->Draw("zp");
  tg3[0]->Draw("p");
  tg3_sys[0]->Draw("zp");
  tg4[0]->Draw("p");
  tg4_sys[0]->Draw("zp");
  //tg5[0]->Draw("p");
  //tg5_sys[0]->Draw("zp");
  tg6[0]->Draw("p");
  tg6_sys[0]->Draw("zp");



  pad[1]->cd();
  gPad->SetBottomMargin(0);
  gPad->SetLeftMargin(0.12);
  gPad->SetRightMargin(0.03);
  gPad->SetTicks(1,1);
  TH1D* h2 = (TH1D*)gPad->DrawFrame(x1, -0.26, x2, 0.28);
  h2->GetXaxis()->SetMoreLogLabels();
  h2->GetXaxis()->SetNoExponent();
  h2->GetYaxis()->SetNdivisions(505);
  h2->GetYaxis()->SetLabelOffset(0.01);
  gPad->SetLogx();
  TBox yellbox2(x1,-0.26, 5, 0.28);
  yellbox2.SetFillColorAlpha(5, 0.2);
  yellbox2.SetLineColorAlpha(5, 0.2);
  yellbox2.Draw();
  l2.Draw();
  tg1    [1]->Draw("p");
  tg1_sys[1]->Draw("zp");
  //tg2    [1]->Draw("p");
  //tg2_sys[1]->Draw("zp");
  tg3    [1]->Draw("p");
  tg3_sys[1]->Draw("zp");
  tg4    [1]->Draw("p");
  tg4_sys[1]->Draw("zp");
  //tg5    [1]->Draw("p");
  //tg5_sys[1]->Draw("zp");
  tg6    [1]->Draw("p");
  tg6_sys[1]->Draw("zp");




  pad[2]->cd();
  gPad->SetBottomMargin(0);
  gPad->SetLeftMargin(0.12);
  gPad->SetRightMargin(0.03);
  TH1D* h3 = (TH1D*)gPad->DrawFrame(x1, -0.6, x2, 0.9);
  h3->GetXaxis()->SetMoreLogLabels();
  h3->GetXaxis()->SetNoExponent();
  h3->GetYaxis()->SetLabelOffset(0.01);
  h3->GetYaxis()->SetNdivisions(505);
  gPad->SetTicks(1,1);
  gPad->SetLogx();
  TBox yellbox3(x1,-0.6, 5, 0.9);
  yellbox3.SetFillColorAlpha(5, 0.2);
  yellbox3.SetLineColorAlpha(5, 0.2);
  yellbox3.Draw();
  l2.Draw();
  tg1    [2]->Draw("p");
  tg1_sys[2]->Draw("zp");
  //tg2    [2]->Draw("p");
  //tg2_sys[2]->Draw("zp");
  tg3    [2]->Draw("p");
  tg3_sys[2]->Draw("zp");
  tg4    [2]->Draw("p");
  tg4_sys[2]->Draw("zp");
  //tg5    [2]->Draw("p");
  //tg5_sys[2]->Draw("zp");
  tg6    [2]->Draw("p");
  tg6_sys[2]->Draw("zp");




  pad[3]->cd();
  gPad->SetTopMargin(0);
  gPad->SetBottomMargin(0.15);
  gPad->SetLeftMargin(0.12);
  gPad->SetRightMargin(0.03);
  gPad->SetTicks(1,1);
  TH1D* h4 = (TH1D*)gPad->DrawFrame(x1, -0.12, x2, 0.17);
  h4->GetYaxis()->SetLabelOffset(0.01);
  h4->GetXaxis()->SetMoreLogLabels();
  h4->GetYaxis()->SetNdivisions(505);
  h4->GetXaxis()->SetNoExponent();
  h4->GetXaxis()->ChangeLabel(2, -1, -1, -1, -1, -1, " ");
  h4->GetXaxis()->ChangeLabel(4, -1, -1, -1, -1, -1, " ");
  h4->GetXaxis()->ChangeLabel(6, -1, -1, -1, -1, -1, " ");
  gPad->SetLogx();
  TBox yellbox4(x1,-0.12, 5, 0.17);
  yellbox4.SetFillColorAlpha(5, 0.2);
  yellbox4.SetLineColorAlpha(5, 0.2);
  yellbox4.Draw();
  l2.Draw();
  tg1    [3]->Draw("p");
  tg1_sys[3]->Draw("zp");
  //tg2    [3]->Draw("p");
  //tg2_sys[3]->Draw("zp");
  tg3    [3]->Draw("p");
  tg3_sys[3]->Draw("zp");
  tg4    [3]->Draw("p");
  tg4_sys[3]->Draw("zp");
  //tg5    [3]->Draw("p");
  //tg5_sys[3]->Draw("zp");
  tg6    [3]->Draw("p");
  tg6_sys[3]->Draw("zp");




  pad[4]->cd();
  gPad->SetTopMargin(0);
  gPad->SetBottomMargin(0.15);
  gPad->SetLeftMargin(0.12);
  gPad->SetRightMargin(0.03);
  TH1D* h5 = (TH1D*)gPad->DrawFrame(x1, -0.22, x2, 0.12);
  h5->GetXaxis()->SetMoreLogLabels();
  h5->GetXaxis()->SetNoExponent();
  h5->GetYaxis()->SetLabelOffset(0.01);
  h5->GetYaxis()->SetNdivisions(505);
  h5->GetXaxis()->ChangeLabel(2, -1, -1, -1, -1, -1, " ");
  h5->GetXaxis()->ChangeLabel(4, -1, -1, -1, -1, -1, " ");
  h5->GetXaxis()->ChangeLabel(6, -1, -1, -1, -1, -1, " ");
  TBox yellbox5(x1,-0.22, 5, 0.12);
  yellbox5.SetFillColorAlpha(5, 0.2);
  yellbox5.SetLineColorAlpha(5, 0.2);
  yellbox5.Draw();
  l2.Draw();
  gPad->SetLogx();
  gPad->SetTicks(1,1);
  tg1    [4]->Draw("p");
  tg1_sys[4]->Draw("zp");
  //tg2    [4]->Draw("p");
  //tg2_sys[4]->Draw("zp");
  tg3    [4]->Draw("p");
  tg3_sys[4]->Draw("zp");
  tg4    [4]->Draw("p");
  tg4_sys[4]->Draw("zp");
  //tg5    [4]->Draw("p");
  //tg5_sys[4]->Draw("zp");
  tg6    [4]->Draw("p");
  tg6_sys[4]->Draw("zp");





  pad[5]->cd();
  gPad->SetTopMargin(0);
  gPad->SetBottomMargin(0.15);
  gPad->SetLeftMargin(0.12);
  gPad->SetRightMargin(0.03);
  gPad->SetTicks(1,1);
  TH1D* h6 = (TH1D*)gPad->DrawFrame(x1, -0.4, x2, 0.74);
  h6->GetXaxis()->SetMoreLogLabels();
  h6->GetYaxis()->SetLabelOffset(0.01);
  h6->GetYaxis()->SetNdivisions(505);
  h6->GetXaxis()->SetNoExponent();
  h6->GetXaxis()->ChangeLabel(2, -1, -1, -1, -1, -1, " ");
  h6->GetXaxis()->ChangeLabel(4, -1, -1, -1, -1, -1, " ");
  h6->GetXaxis()->ChangeLabel(6, -1, -1, -1, -1, -1, " ");
  //h6->Draw();
  gPad->SetLogx();
  TBox yellbox6(x1,-0.4, 5, 0.74);
  yellbox6.SetFillColorAlpha(5, 0.2);
  yellbox6.SetLineColorAlpha(5, 0.2);
  yellbox6.Draw();
  l2.Draw();
  tg1    [5]->Draw("p");
  tg1_sys[5]->Draw("zp");
  //tg2    [5]->Draw("p");
  //tg2_sys[5]->Draw("zp");
  tg3    [5]->Draw("p");
  tg3_sys[5]->Draw("zp");
  tg4    [5]->Draw("p");
  tg4_sys[5]->Draw("zp");
  //tg5    [5]->Draw("p");
  //tg5_sys[5]->Draw("zp");
  tg6    [5]->Draw("p");
  tg6_sys[5]->Draw("zp");





  //draw text
  cas->cd();
  TLatex lax;
  lax.SetTextFont(42);
  lax.SetTextSize(0.060);
  lax.DrawLatex(0.355,0.074, "Collision Energy #sqrt{s_{NN}}  (GeV)");
  lax.SetTextAngle(90);
  //lax.DrawLatex(0.05,0.475,"Ratios");
  lax.SetTextSize(0.050);
  lax.DrawLatex(0.05, 0.295, "Proton");
  lax.DrawLatex(0.05, 0.645, "Net-proton");

  lax.SetTextSize(0.035);
  lax.SetTextAngle(0);
  lax.DrawLatex(0.270,0.89,"(a)  #frac{C_{2}}{#LTp+#bar{p}#GT}");
  lax.DrawLatex(0.610,0.89,"(b)  #frac{C_{3}}{C_{1}}");
  lax.DrawLatex(0.925,0.89,"(c)  #frac{C_{4}}{C_{2}}");
  lax.DrawLatex(0.270,0.48,"(d)  #frac{FC_{2}}{FC_{1}}");
  lax.DrawLatex(0.600,0.48,"(e)  #frac{FC_{3}}{FC_{1}}");
  lax.DrawLatex(0.920,0.48,"(f)  #frac{FC_{4}}{FC_{1}}");

  lax.SetTextAngle(0);
  lax.SetTextFont(62);
  lax.SetTextColor(kP10Red);
  lax.SetTextSize(0.035);
  lax.SetTextFont(72);
  lax.SetTextColor(1);
  lax.SetTextColor(4);
  lax.DrawLatex(0.170,0.890,"Method 2");
  lax.DrawLatex(0.170,0.860,"Difference");
  lax.SetTextColor(1);
  lax.SetTextColor(1);
  lax.SetTextSize(0.035);
  lax.SetTextFont(42);
  //lax.DrawLatex(0.165,0.800,"5\% Au+Au Collisions");
  lax.SetTextSize(0.035);
  //lax.DrawLatex(0.165,0.750,"0.4 < p_{T} < 2.0 GeV/c");

  cas->cd();
  TLegend *leg = new TLegend();
  leg->SetLineWidth(0);
  leg->SetFillStyle(0);
  leg->AddEntry(tg1[0], "data_{0-5%} #minus UrQMD_{0-5%}", "p");
  //leg->AddEntry(tg2[0], "data_{0-5%} #minus data_{50-60%}", "p");
  leg->AddEntry(tg3[0], "data_{50-60%} #minus UrQMD_{50-60%}", "p");
  leg->SetTextSize(0.031);
  leg->SetX1(0.47);
  leg->SetX2(0.58);
  leg->SetY1(0.20);
  leg->SetY2(0.37);
  leg->Draw();


  cas->Print("Fig_AllRatios_Method2_diff_energy.pdf");
}

