#include "../data_points/UrQMD_FXT_Method2_centrality_dependence_all.h"
#include "../data_points/UrQMD_Collider_CBWC_centrality_dependence_all.h"
#include "../data_points/R42_central_energy_dependence.h"
#include "color_definition.h"

void plot_r42_method2_diff_muB(){

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

  //calculate absolute difference 
  double Coll_diff[9];
  double Coll_diff_stat[9];
  double Coll_diff_sys[9];
  for(int i=0;i<9;++i){
    Coll_diff[i] = Coll_CBWC_R42[i] - Coll_CBWC_R42_UrQMD[i];
    Coll_diff_stat[i] = sqrt(pow(Coll_CBWC_R42_stat[i], 2.)+ pow(Coll_CBWC_R42_UrQMD_stat[i] ,2.) );
    Coll_diff_sys[i] = Coll_CBWC_R42_sys[i];
  }
  TGraphErrors* tcoll2 = new TGraphErrors(9, Coll_CBWC_R42_muB, Coll_diff, Coll_CBWC_R42_ex, Coll_diff_stat);
  TGraphErrors* tcoll3 = new TGraphErrors(9, Coll_CBWC_R42_muB, Coll_diff, Coll_CBWC_R42_ex, Coll_CBWC_R42_ex);
  TGraphErrors* tcoll4 = new TGraphErrors(9, Coll_CBWC_R42_muB, Coll_diff, Coll_CBWC_R42_ex, Coll_diff_sys);

  tcoll3->SetMarkerStyle(21);
  tcoll3->SetMarkerColorAlpha(2, 1.0);
  tcoll3->SetLineColorAlpha(2, 1.0);
  tcoll3->SetLineStyle(2);
  tcoll3->SetLineWidth(2);
  tcoll2->SetMarkerStyle(25);
  tcoll4->SetMarkerStyle(25);
  tcoll2->SetMarkerSize(1.6);
  tcoll4->SetMarkerSize(1.8);
  tcoll4->SetLineWidth(8);
  tcoll4->SetLineColorAlpha(1,0.3);

  double FXT_diff[9];
  double FXT_diff_stat[9];
  double FXT_diff_sys[9];

  for(int ipoint=0; ipoint<6;++ipoint){
    FXT_diff[ipoint] = FXT_Method2_R42[ipoint]-FXT_Method2_R42_UrQMD[ipoint];
    FXT_diff_stat[ipoint] = sqrt(pow(FXT_Method2_R42_stat[ipoint], 2.) + pow(FXT_Method2_R42_UrQMD_stat[ipoint], 2.));
    FXT_diff_sys[ipoint] = FXT_Method2_R42_sys[ipoint];
  }
  TGraphErrors* tg71 = new TGraphErrors(6, FXT_Method2_R42_muB, FXT_diff, FXT_Method2_R42_ex, FXT_diff_stat);
  TGraphErrors* tg72 = new TGraphErrors(6, FXT_Method2_R42_muB, FXT_diff, FXT_Method2_R42_ex, FXT_Method2_R42_ex);
  TGraphErrors* tg73 = new TGraphErrors(6, FXT_Method2_R42_muB, FXT_diff, FXT_Method2_R42_ex, FXT_diff_sys);
  tg71->SetMarkerStyle(20);
  tg72->SetMarkerStyle(24);
  tg73->SetMarkerStyle(24);
  tg72->SetMarkerSize(1.6); 
  tg73->SetMarkerSize(1.8); 
  tg73->SetLineWidth(8);
  tg73->SetLineColorAlpha(1,0.3);

  //UrQMD (0-5%) - UrQMD (50-60%)
  double FXT_UrQMD_base_energy[6]={3.0, 3.2, 3.5, 3.9, 4.5, 5.2};
  double FXT_UrQMD_base_ex[6]={0,0,0,0,0};
  double FXT_UrQMD_base_diff[6]; //0-5% minus 50-60%
  double FXT_UrQMD_base_diff_stat[6]; //0-5% minus 50-60%

  FXT_UrQMD_base_diff[0]      =          UrQMD_Method2_3p0_R42[0]     -     UrQMD_Method2_3p0_R42[5];
  FXT_UrQMD_base_diff_stat[0] = sqrt(pow(UrQMD_Method2_3p0_R42_stat[0],2.) + pow(UrQMD_Method2_3p0_R42_stat[5],2.));
  FXT_UrQMD_base_diff[1]      =          UrQMD_Method2_3p2_R42[0]     -     UrQMD_Method2_3p2_R42[5];
  FXT_UrQMD_base_diff_stat[1] = sqrt(pow(UrQMD_Method2_3p2_R42_stat[0],2.) + pow(UrQMD_Method2_3p2_R42_stat[5],2.));
  FXT_UrQMD_base_diff[2]      =          UrQMD_Method2_3p5_R42[0]     -     UrQMD_Method2_3p5_R42[5];
  FXT_UrQMD_base_diff_stat[2] = sqrt(pow(UrQMD_Method2_3p5_R42_stat[0],2.) + pow(UrQMD_Method2_3p5_R42_stat[5],2.));
  FXT_UrQMD_base_diff[3]      =          UrQMD_Method2_3p9_R42[0]     -     UrQMD_Method2_3p9_R42[5];
  FXT_UrQMD_base_diff_stat[3] = sqrt(pow(UrQMD_Method2_3p9_R42_stat[0],2.) + pow(UrQMD_Method2_3p9_R42_stat[5],2.));
  FXT_UrQMD_base_diff[4]      =          UrQMD_Method2_4p5_R42[0]     -     UrQMD_Method2_4p5_R42[5];
  FXT_UrQMD_base_diff_stat[4] = sqrt(pow(UrQMD_Method2_4p5_R42_stat[0],2.) + pow(UrQMD_Method2_4p5_R42_stat[5],2.));
  FXT_UrQMD_base_diff[5]      =          UrQMD_Method2_5p2_R42[0]     -     UrQMD_Method2_5p2_R42[5];
  FXT_UrQMD_base_diff_stat[5] = sqrt(pow(UrQMD_Method2_5p2_R42_stat[0],2.) + pow(UrQMD_Method2_5p2_R42_stat[5],2.));

  TGraphErrors* tg_base1 = new TGraphErrors(6, FXT_Method2_R42_UrQMD_muB, FXT_UrQMD_base_diff, FXT_UrQMD_base_ex, FXT_UrQMD_base_diff_stat);
  tg_base1->SetMarkerStyle(24);
  tg_base1->SetMarkerColor(4);
  tg_base1->SetLineColor(4);

  double Coll_UrQMD_base_energy[7]={7.7, 9.2, 11.5, 14.6, 17.3, 19.6, 27};
  double Coll_UrQMD_base_ex[7]={0,0,0,0,0,0,0};
  double Coll_UrQMD_base_diff[7];      //0-5% minus 50-60%
  double Coll_UrQMD_base_diff_stat[7]; //0-5% minus 50-60%

  Coll_UrQMD_base_diff[0]      =          UrQMD_7p7_Netp_R42[0]     -           UrQMD_7p7_Netp_R42      [5];
  Coll_UrQMD_base_diff_stat[0] = sqrt(pow(UrQMD_7p7_Netp_R42_stat[0],2.)  + pow(UrQMD_7p7_Netp_R42_stat [5],2.));
  Coll_UrQMD_base_diff[1]      =          UrQMD_9p2_Netp_R42[0]     -           UrQMD_9p2_Netp_R42      [5];
  Coll_UrQMD_base_diff_stat[1] = sqrt(pow(UrQMD_9p2_Netp_R42_stat[0],2.)  + pow(UrQMD_9p2_Netp_R42_stat [5],2.));
  Coll_UrQMD_base_diff[2]      =          UrQMD_11p5_Netp_R42[0]     -          UrQMD_11p5_Netp_R42     [5];
  Coll_UrQMD_base_diff_stat[2] = sqrt(pow(UrQMD_11p5_Netp_R42_stat[0],2.) + pow(UrQMD_11p5_Netp_R42_stat[5],2.));
  Coll_UrQMD_base_diff[3]      =          UrQMD_14p6_Netp_R42[0]     -          UrQMD_14p6_Netp_R42     [5];
  Coll_UrQMD_base_diff_stat[3] = sqrt(pow(UrQMD_14p6_Netp_R42_stat[0],2.) + pow(UrQMD_14p6_Netp_R42_stat[5],2.));
  Coll_UrQMD_base_diff[4]      =          UrQMD_17p3_Netp_R42[0]     -          UrQMD_17p3_Netp_R42     [5];
  Coll_UrQMD_base_diff_stat[4] = sqrt(pow(UrQMD_17p3_Netp_R42_stat[0],2.) + pow(UrQMD_17p3_Netp_R42_stat[5],2.));
  Coll_UrQMD_base_diff[5]      =          UrQMD_19p6_Netp_R42[0]     -          UrQMD_19p6_Netp_R42     [5];
  Coll_UrQMD_base_diff_stat[5] = sqrt(pow(UrQMD_19p6_Netp_R42_stat[0],2.) + pow(UrQMD_19p6_Netp_R42_stat[5],2.));
  Coll_UrQMD_base_diff[6]      =          UrQMD_27_Netp_R42[0]     -            UrQMD_27_Netp_R42       [5];
  Coll_UrQMD_base_diff_stat[6] = sqrt(pow(UrQMD_27_Netp_R42_stat[0],2.)   + pow(UrQMD_27_Netp_R42_stat  [5],2.));

  TGraphErrors* tg_base2 = new TGraphErrors(7, Coll_CBWC_R42_UrQMD_muB, Coll_UrQMD_base_diff, Coll_UrQMD_base_ex, Coll_UrQMD_base_diff_stat);
  tg_base2->SetMarkerStyle(25);
  tg_base2->SetMarkerColor(4);
  tg_base2->SetLineColor(4);
  //TGraphErrors* tg_base2_prof = new TGraphErrors(5, Coll_UrQMD_base_energy, Coll_UrQMD_base_diff, Coll_UrQMD_base_ex, Coll_UrQMD_base_ex);
  //tg_base2_prof->SetMarkerStyle(24);
  //tg_base2_prof->SetMarkerColor(1);
  //tg_base2_prof->SetLineColor(1);



  //---------------------------------------------
  double xl1 = 75;
  double xl2 = 933;
  TLine l1(xl1, 1, xl2, 1);
  l1.SetLineStyle(2);
  l1.SetLineColorAlpha(1,0.4);
  TLine l2(xl1, 0, xl2, 0);
  l2.SetLineStyle(7);
  l2.SetLineColorAlpha(1,0.4);
  l2.SetLineWidth(2);

  TLine l3(xl1, 2, xl2, 2);
  l3.SetLineStyle(2);
  l3.SetLineColorAlpha(1,0.4);
  TLine l31(xl1, 3, xl2, 3);
  l31.SetLineStyle(2);
  l31.SetLineColorAlpha(1,0.4);
  TLine l32(xl1, 4, xl2, 4);
  l32.SetLineStyle(2);
  l32.SetLineColorAlpha(1,0.4);
  TLine l33(xl1, 5, xl2, 5);
  l33.SetLineStyle(2);
  l33.SetLineColorAlpha(1,0.4);
  TLine l34(xl1, 1, xl2, 1);
  l34.SetLineStyle(2);
  l34.SetLineColorAlpha(1,0.4);
  TLine l4(xl1, -2, xl2, -2);
  l4.SetLineStyle(2);
  l4.SetLineColorAlpha(1,0.4);
  TLine l41(xl1, -3, xl2, -3);
  l41.SetLineStyle(2);
  l41.SetLineColorAlpha(1,0.4);
  TLine l42(xl1, -4, xl2, -4);
  l42.SetLineStyle(2);
  l42.SetLineColorAlpha(1,0.4);
  TLine l43(xl1, -5, xl2, -5);
  l43.SetLineStyle(2);
  l43.SetLineColorAlpha(1,0.4);
  TLine l44(xl1, -1, xl2, -1);
  l44.SetLineStyle(2);
  l44.SetLineColorAlpha(1,0.4);

  TLine l5(xl1, 0, xl2, 0);
  l5.SetLineStyle(7);
  l5.SetLineColorAlpha(1,0.3);
  l5.SetLineWidth(2);



  TLatex lax;
  lax.SetNDC();
  lax.SetTextFont(62);

  TBox bg1(xl1, -1.3, 5.5, 1.85);
  bg1.SetFillColorAlpha(5, 0.2);
  TBox bg2(xl1, -5.8, 5.5, 5.7);
  bg2.SetFillColorAlpha(5, 0.2);

  TCanvas *cas = new TCanvas("cas","", 980, 650);
  cas->cd();
  TPad* p1 = new TPad("p1","",0.02,0.06,0.99,0.99);
  p1->Draw();
  
  gStyle->SetEndErrorSize(3);

  p1->cd();

  gPad->SetLogx();

  gStyle->SetLabelFont(43, "XY");
  gStyle->SetLabelSize(30,"XY");
  //gPad->SetLeftMargin(0.12);
  //gPad->SetBottomMargin(0);
  //gPad->SetTopMargin(0.15);
  gPad->SetRightMargin(0.01);
  gPad->SetTopMargin(0.02);
  gPad->SetTicks(1,1);
  TH1D* h1 = (TH1D*) gPad->DrawFrame(xl1, -1.55, xl2, 1.25);
  h1->GetXaxis()->SetNoExponent();
  h1->GetXaxis()->SetMoreLogLabels();
  h1->GetYaxis()->SetNdivisions(505);
  h1->GetXaxis()->SetNdivisions(505);
  h1->GetYaxis()->SetLabelOffset(0.014);
  //h1->GetXaxis()->ChangeLabel(2, -1, -1, -1, -1, -1, " ");
  //h1->GetXaxis()->ChangeLabel(4, -1, -1, -1, -1, -1, " ");
  //h1->GetXaxis()->ChangeLabel(6, -1, -1, -1, -1, -1, " ");
  //h1->GetXaxis()->ChangeLabel(7, -1, -1, -1, -1, -1, " ");
  //h1->GetXaxis()->ChangeLabel(11, -1, -1, -1, -1, -1, " ");
  //h1->GetXaxis()->ChangeLabel(13, -1, -1, -1, -1, -1, " ");
  l1.Draw();
  l2.Draw();


  l3.Draw();
  //l31.Draw();
  l32.Draw();
  l33.Draw();
  l34.Draw();
  l4.Draw();
  l41.Draw();
  l42.Draw();
  l43.Draw();
  l44.Draw();
  l5.Draw();

  tg_base1->Draw("P");
  tg_base2->Draw("P");
  tg_base2->Print();

  tg71->Draw("P");
  tg72->Draw("P");
  tg73->Draw("ZP");
  tcoll3->Draw("P");
  tcoll2->Draw("P");
  tcoll4->Draw("ZP");


  //UrQMD bands
  TBox *b1 = new TBox(34,-0.68,47,-0.83);
  b1->SetFillColorAlpha(cidx4, 0.6);
  //b1->Draw();
  TBox *b2 = new TBox(34,-0.90,47,-1.05);
  b2->SetFillColorAlpha(cidx2, 1.0);
  b2->SetFillStyle(3244);
  //b2->Draw();

  TLatex ll;
  ll.SetTextFont(42);
  ll.SetNDC();
  ll.SetTextSize(0.045);
  ll.SetTextSize(0.06);

  TMarker *tm1  = new TMarker(90.4,0.76,20);
  TMarker *tm2  = new TMarker(90.4,0.76,24);
  TMarker *tm22 = new TMarker(90.4,0.76,24);
  tm1->SetMarkerColorAlpha(1, 1.0);
  tm1->SetMarkerSize(1.0);
  tm1->Draw();
  tm2->SetMarkerColorAlpha(1, 1.0);
  tm2->SetMarkerSize(1.6);
  tm2->Draw();
  tm22->SetMarkerColorAlpha(1, 1.0);
  tm22->SetMarkerSize(1.8);
  tm22->Draw();

  TMarker *tm3  = new TMarker(85.4,0.48,24);
  tm3->SetMarkerColor(4);
  tm3->Draw();
  TMarker *tm31 = new TMarker(94.4,0.48,25);
  tm31->SetMarkerColor(4);
  tm31->Draw();



  ////draw text
  cas->cd();
  lax.SetTextFont(42);
  lax.DrawLatex(0.300,0.040, "Baryon Chemical Potential #mu_{B} (MeV)");
  lax.SetTextAngle(90);
  lax.SetTextSize(0.045);
  lax.DrawLatex(0.036,0.350,"C_{4}/C_{2} difference (Method 2)");
  lax.SetTextAngle(0);
  lax.SetTextSize(0.04);
  lax.DrawLatex(0.22,0.820,"[C_{4}/C_{2}]^{Data}_{0-5%} - [C_{4}/C_{2}]^{UrQMD}_{0-5%}");
  //lax.DrawLatex(0.28,0.740,"[C_{4}/C_{2}]^{Data}_{0-5%} - [C_{4}/C_{2}]^{Data}_{50-60%}");
  lax.DrawLatex(0.22,0.740,"[C_{4}/C_{2}]^{UrQMD}_{0-5%} - [C_{4}/C_{2}]^{UrQMD}_{40-50%}");

  cas->Print("Fig_R42_Method2_diff_muB.pdf");
}
