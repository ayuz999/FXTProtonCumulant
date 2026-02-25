#include "../../data_points/Collider_CBWC_energy_dependence_all.h"
#include "../../data_points/UrQMD_Collider_CBWC_energy_dependence_central.h"

#include "../../data_points/FXT_CBWC_energy_dependence_all.h"
#include "../../data_points/UrQMD_FXT_CBWC_energy_dependence_all.h"

#include "../color_definition.h"

//0-5% 
void plot_AllRatios_CBWC_energy(){

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


 
  //FXT data, CBWC
  TGraphErrors *tg1[6];
  TGraphErrors *tg1_sys[6];
  TGraphErrors *tg1_prof[6];
  tg1[0]      = new TGraphErrors(6, FXT_CBWC_Energy, FXT_CBWC_R21_Cent05,  FXT_CBWC_XError, FXT_CBWC_R21_Cent05_stat);
  tg1_sys[0]  = new TGraphErrors(6, FXT_CBWC_Energy, FXT_CBWC_R21_Cent05,  FXT_CBWC_XError, FXT_CBWC_R21_Cent05_sys);
  tg1_prof[0] = new TGraphErrors(6, FXT_CBWC_Energy, FXT_CBWC_R21_Cent05,  FXT_CBWC_XError, FXT_CBWC_XError);
  tg1[1]      = new TGraphErrors(6, FXT_CBWC_Energy, FXT_CBWC_R31_Cent05,  FXT_CBWC_XError, FXT_CBWC_R31_Cent05_stat);
  tg1_sys[1]  = new TGraphErrors(6, FXT_CBWC_Energy, FXT_CBWC_R31_Cent05,  FXT_CBWC_XError, FXT_CBWC_R31_Cent05_sys);
  tg1_prof[1] = new TGraphErrors(6, FXT_CBWC_Energy, FXT_CBWC_R31_Cent05,  FXT_CBWC_XError, FXT_CBWC_XError);
  tg1[2]      = new TGraphErrors(6, FXT_CBWC_Energy, FXT_CBWC_R42_Cent05,  FXT_CBWC_XError, FXT_CBWC_R42_Cent05_stat);
  tg1_sys[2]  = new TGraphErrors(6, FXT_CBWC_Energy, FXT_CBWC_R42_Cent05,  FXT_CBWC_XError, FXT_CBWC_R42_Cent05_sys);
  tg1_prof[2] = new TGraphErrors(6, FXT_CBWC_Energy, FXT_CBWC_R42_Cent05,  FXT_CBWC_XError, FXT_CBWC_XError);
  tg1[3]      = new TGraphErrors(6, FXT_CBWC_Energy, FXT_CBWC_FC21_Cent05, FXT_CBWC_XError, FXT_CBWC_FC21_Cent05_stat);
  tg1_sys[3]  = new TGraphErrors(6, FXT_CBWC_Energy, FXT_CBWC_FC21_Cent05, FXT_CBWC_XError, FXT_CBWC_FC21_Cent05_sys);
  tg1_prof[3] = new TGraphErrors(6, FXT_CBWC_Energy, FXT_CBWC_FC21_Cent05, FXT_CBWC_XError, FXT_CBWC_XError);
  tg1[4]      = new TGraphErrors(6, FXT_CBWC_Energy, FXT_CBWC_FC31_Cent05, FXT_CBWC_XError, FXT_CBWC_FC31_Cent05_stat);
  tg1_sys[4]  = new TGraphErrors(6, FXT_CBWC_Energy, FXT_CBWC_FC31_Cent05, FXT_CBWC_XError, FXT_CBWC_FC31_Cent05_sys);
  tg1_prof[4] = new TGraphErrors(6, FXT_CBWC_Energy, FXT_CBWC_FC31_Cent05, FXT_CBWC_XError, FXT_CBWC_XError);
  tg1[5]      = new TGraphErrors(6, FXT_CBWC_Energy, FXT_CBWC_FC41_Cent05, FXT_CBWC_XError, FXT_CBWC_FC41_Cent05_stat);
  tg1_sys[5]  = new TGraphErrors(6, FXT_CBWC_Energy, FXT_CBWC_FC41_Cent05, FXT_CBWC_XError, FXT_CBWC_FC41_Cent05_sys);
  tg1_prof[5] = new TGraphErrors(6, FXT_CBWC_Energy, FXT_CBWC_FC41_Cent05, FXT_CBWC_XError, FXT_CBWC_XError);

  for(int i=0;i<6;++i){
    tg1[i]->SetMarkerStyle(20);
    tg1[i]->SetMarkerSize(0.6); 
    tg1_sys[i]->SetMarkerStyle(24);
    tg1_sys[i]->SetMarkerSize(1.0); 
    tg1_sys[i]->SetLineWidth(6);
    tg1_sys[i]->SetLineColorAlpha(1,0.3);
  }


  //UrQMD, FXT, CBWC
  TGraphErrors* tg2[6];
  tg2[0] = new TGraphErrors(6, UrQMD_FXT_CBWC_Energy, UrQMD_FXT_CBWC_GapON_HY5_R21_Cent05,  UrQMD_FXT_CBWC_XError, UrQMD_FXT_CBWC_GapON_HY5_R21_Cent05_stat);
  tg2[1] = new TGraphErrors(6, UrQMD_FXT_CBWC_Energy, UrQMD_FXT_CBWC_GapON_HY5_R31_Cent05,  UrQMD_FXT_CBWC_XError, UrQMD_FXT_CBWC_GapON_HY5_R31_Cent05_stat);
  tg2[2] = new TGraphErrors(6, UrQMD_FXT_CBWC_Energy, UrQMD_FXT_CBWC_GapON_HY5_R42_Cent05,  UrQMD_FXT_CBWC_XError, UrQMD_FXT_CBWC_GapON_HY5_R42_Cent05_stat);
  tg2[3] = new TGraphErrors(6, UrQMD_FXT_CBWC_Energy, UrQMD_FXT_CBWC_GapON_HY5_FC21_Cent05, UrQMD_FXT_CBWC_XError, UrQMD_FXT_CBWC_GapON_HY5_FC21_Cent05_stat);
  tg2[4] = new TGraphErrors(6, UrQMD_FXT_CBWC_Energy, UrQMD_FXT_CBWC_GapON_HY5_FC31_Cent05, UrQMD_FXT_CBWC_XError, UrQMD_FXT_CBWC_GapON_HY5_FC31_Cent05_stat);
  tg2[5] = new TGraphErrors(6, UrQMD_FXT_CBWC_Energy, UrQMD_FXT_CBWC_GapON_HY5_FC41_Cent05, UrQMD_FXT_CBWC_XError, UrQMD_FXT_CBWC_GapON_HY5_FC41_Cent05_stat);
  for(int i=0;i<6;++i){
    tg2[i]->SetFillColorAlpha(4, 0.6);
    tg2[i]->SetLineColorAlpha(4, 0.6);
  }

  //Collider, data
  TGraphErrors* tg3[6];
  TGraphErrors* tg3_sys[6];
  TGraphErrors* tg3_prof[6];
  double dummy_ex[9]={0,0,0, 0,0,0, 0,0,0};
  tg3[0]      = new TGraphErrors(9, cEnergies, cObservables[0][0], dummy_ex, cObservables_sts[0][0]);
  tg3_sys[0]  = new TGraphErrors(9, cEnergies, cObservables[0][0], dummy_ex, cObservables_sys[0][0]);
  tg3_prof[0] = new TGraphErrors(9, cEnergies, cObservables[0][0], dummy_ex, dummy_ex);
  tg3[1]      = new TGraphErrors(9, cEnergies, cObservables[1][0], dummy_ex, cObservables_sts[1][0]);
  tg3_sys[1]  = new TGraphErrors(9, cEnergies, cObservables[1][0], dummy_ex, cObservables_sys[1][0]);
  tg3_prof[1] = new TGraphErrors(9, cEnergies, cObservables[1][0], dummy_ex, dummy_ex);
  tg3[2]      = new TGraphErrors(9, cEnergies, cObservables[2][0], dummy_ex, cObservables_sts[2][0]);
  tg3_sys[2]  = new TGraphErrors(9, cEnergies, cObservables[2][0], dummy_ex, cObservables_sys[2][0]);
  tg3_prof[2] = new TGraphErrors(9, cEnergies, cObservables[2][0], dummy_ex, dummy_ex);
  tg3[3]      = new TGraphErrors(9, cEnergies, cObservables[3][0], dummy_ex, cObservables_sts[3][0]);
  tg3_sys[3]  = new TGraphErrors(9, cEnergies, cObservables[3][0], dummy_ex, cObservables_sys[3][0]);
  tg3_prof[3] = new TGraphErrors(9, cEnergies, cObservables[3][0], dummy_ex, dummy_ex);
  tg3[4]      = new TGraphErrors(9, cEnergies, cObservables[4][0], dummy_ex, cObservables_sts[4][0]);
  tg3_sys[4]  = new TGraphErrors(9, cEnergies, cObservables[4][0], dummy_ex, cObservables_sys[4][0]);
  tg3_prof[4] = new TGraphErrors(9, cEnergies, cObservables[4][0], dummy_ex, dummy_ex);
  tg3[5]      = new TGraphErrors(9, cEnergies, cObservables[5][0], dummy_ex, cObservables_sts[5][0]);
  tg3_sys[5]  = new TGraphErrors(9, cEnergies, cObservables[5][0], dummy_ex, cObservables_sys[5][0]);
  tg3_prof[5] = new TGraphErrors(9, cEnergies, cObservables[5][0], dummy_ex, dummy_ex);

  for(int i=0;i<6;++i){
    tg3[i]->SetMarkerStyle(21);
    tg3[i]->SetFillColorAlpha(1, 1.);
    tg3[i]->SetLineColorAlpha(1, 1.);
    tg3[i]->SetLineWidth(1);
    tg3[i]->SetMarkerColorAlpha(2, 1.0);
    tg3[i]->SetMarkerSize(0.6);

    tg3_sys[i]->SetFillColorAlpha(2, 1.0);
    tg3_sys[i]->SetLineColorAlpha(1, 0.3);
    tg3_sys[i]->SetLineWidth(6);
    tg3_sys[i]->SetMarkerStyle(25);
    tg3_sys[i]->SetMarkerSize(1.0);

    //tg3_prof[i]->SetMarkerColorAlpha(1, 1.0);
    //tg3_prof[i]->SetMarkerStyle(25);
    //tg3_prof[i]->SetMarkerSize(1.8);
  }

  //UrQMD results at collider energies
  TGraphErrors* tg4[6];
  tg4[0] = new TGraphErrors(9, UrQMD_Collider_CBWC_Energy, UrQMD_Collider_CBWC_Netp_R2T_Cent05, UrQMD_Collider_CBWC_XError, UrQMD_Collider_CBWC_Netp_R2T_Cent05_stat);
  tg4[1] = new TGraphErrors(9, UrQMD_Collider_CBWC_Energy, UrQMD_Collider_CBWC_Netp_R31_Cent05, UrQMD_Collider_CBWC_XError, UrQMD_Collider_CBWC_Netp_R31_Cent05_stat);
  tg4[2] = new TGraphErrors(9, UrQMD_Collider_CBWC_Energy, UrQMD_Collider_CBWC_Netp_R42_Cent05, UrQMD_Collider_CBWC_XError, UrQMD_Collider_CBWC_Netp_R42_Cent05_stat);
  tg4[3] = new TGraphErrors(9, UrQMD_Collider_CBWC_Energy, UrQMD_Collider_CBWC_Pro_FC21_Cent05, UrQMD_Collider_CBWC_XError, UrQMD_Collider_CBWC_Pro_FC21_Cent05_stat);
  tg4[4] = new TGraphErrors(9, UrQMD_Collider_CBWC_Energy, UrQMD_Collider_CBWC_Pro_FC31_Cent05, UrQMD_Collider_CBWC_XError, UrQMD_Collider_CBWC_Pro_FC31_Cent05_stat);
  tg4[5] = new TGraphErrors(9, UrQMD_Collider_CBWC_Energy, UrQMD_Collider_CBWC_Pro_FC41_Cent05, UrQMD_Collider_CBWC_XError, UrQMD_Collider_CBWC_Pro_FC41_Cent05_stat);
  for(int i=0;i<6;++i){
    tg4[i]->SetFillColorAlpha(cidx4, 0.6);
    tg4[i]->SetLineColorAlpha(cidx4, 0.6);
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
  TH1D* h1 = (TH1D*)gPad->DrawFrame(x1, 0.82, x2, 1.27);
  h1->GetXaxis()->SetNoExponent();
  h1->GetXaxis()->SetMoreLogLabels();
  h1->GetYaxis()->SetNdivisions(505);
  h1->GetYaxis()->SetLabelOffset(0.01);
  gPad->SetTicks(1,1);
  gPad->SetLogx();
  TBox yellbox1(x1,0.82, 5, 1.27);
  yellbox1.SetFillColorAlpha(5, 0.2);
  yellbox1.SetLineColorAlpha(5, 0.2);
  yellbox1.Draw();
  l1.Draw();
  tg2[0]->Draw("e3");
  tg4[0]->Draw("e3");
  tg1[0]->Draw("p");
  tg1_sys[0]->Draw("zp");
  tg3[0]->Draw("p");
  tg3_sys[0]->Draw("zp");


  pad[1]->cd();
  gPad->SetBottomMargin(0);
  gPad->SetLeftMargin(0.12);
  gPad->SetRightMargin(0.03);
  gPad->SetTicks(1,1);
  TH1D* h2 = (TH1D*)gPad->DrawFrame(x1, 0.56, x2, 1.38);
  h2->GetXaxis()->SetMoreLogLabels();
  h2->GetXaxis()->SetNoExponent();
  h2->GetYaxis()->SetNdivisions(505);
  h2->GetYaxis()->SetLabelOffset(0.01);
  gPad->SetLogx();
  TBox yellbox2(x1,0.56, 5, 1.38);
  yellbox2.SetFillColorAlpha(5, 0.2);
  yellbox2.SetLineColorAlpha(5, 0.2);
  yellbox2.Draw();
  l1.Draw();
  tg2    [1]->Draw("e3");
  tg4    [1]->Draw("e3");
  tg1    [1]->Draw("p");
  tg1_sys[1]->Draw("zp");
  tg3    [1]->Draw("p");
  tg3_sys[1]->Draw("zp");




  pad[2]->cd();
  gPad->SetBottomMargin(0);
  gPad->SetLeftMargin(0.12);
  gPad->SetRightMargin(0.03);
  TH1D* h3 = (TH1D*)gPad->DrawFrame(x1, -1.8, x2, 2.2);
  h3->GetXaxis()->SetMoreLogLabels();
  h3->GetXaxis()->SetNoExponent();
  h3->GetYaxis()->SetLabelOffset(0.01);
  h3->GetYaxis()->SetNdivisions(505);
  gPad->SetTicks(1,1);
  gPad->SetLogx();
  TBox yellbox3(x1,-1.8, 5, 2.2);
  yellbox3.SetFillColorAlpha(5, 0.2);
  yellbox3.SetLineColorAlpha(5, 0.2);
  yellbox3.Draw();
  l1.Draw();
  tg2    [2]->Draw("e3");
  tg4    [2]->Draw("e3");
  tg1    [2]->Draw("p");
  tg1_sys[2]->Draw("zp");
  tg3    [2]->Draw("p");
  tg3_sys[2]->Draw("zp");




  pad[3]->cd();
  gPad->SetTopMargin(0);
  gPad->SetBottomMargin(0.15);
  gPad->SetLeftMargin(0.12);
  gPad->SetRightMargin(0.03);
  gPad->SetTicks(1,1);
  TH1D* h4 = (TH1D*)gPad->DrawFrame(x1, -0.28, x2, 0.38);
  h4->GetYaxis()->SetLabelOffset(0.01);
  h4->GetXaxis()->SetMoreLogLabels();
  h4->GetYaxis()->SetNdivisions(505);
  h4->GetXaxis()->SetNoExponent();
  h4->GetXaxis()->ChangeLabel(2, -1, -1, -1, -1, -1, " ");
  h4->GetXaxis()->ChangeLabel(4, -1, -1, -1, -1, -1, " ");
  h4->GetXaxis()->ChangeLabel(6, -1, -1, -1, -1, -1, " ");
  gPad->SetLogx();
  TBox yellbox4(x1,-0.28, 5, 0.38);
  yellbox4.SetFillColorAlpha(5, 0.2);
  yellbox4.SetLineColorAlpha(5, 0.2);
  yellbox4.Draw();
  l2.Draw();
  tg2    [3]->Draw("e3");
  tg4    [3]->Draw("e3");
  tg1    [3]->Draw("p");
  tg1_sys[3]->Draw("zp");
  tg3    [3]->Draw("p");
  tg3_sys[3]->Draw("zp");




  pad[4]->cd();
  gPad->SetTopMargin(0);
  gPad->SetBottomMargin(0.15);
  gPad->SetLeftMargin(0.12);
  gPad->SetRightMargin(0.03);
  TH1D* h5 = (TH1D*)gPad->DrawFrame(x1, -0.62, x2, 0.32);
  h5->GetXaxis()->SetMoreLogLabels();
  h5->GetXaxis()->SetNoExponent();
  h5->GetYaxis()->SetLabelOffset(0.01);
  h5->GetYaxis()->SetNdivisions(505);
  h5->GetXaxis()->ChangeLabel(2, -1, -1, -1, -1, -1, " ");
  h5->GetXaxis()->ChangeLabel(4, -1, -1, -1, -1, -1, " ");
  h5->GetXaxis()->ChangeLabel(6, -1, -1, -1, -1, -1, " ");
  TBox yellbox5(x1,-0.62, 5, 0.32);
  yellbox5.SetFillColorAlpha(5, 0.2);
  yellbox5.SetLineColorAlpha(5, 0.2);
  yellbox5.Draw();
  l2.Draw();
  gPad->SetLogx();
  gPad->SetTicks(1,1);
  tg2    [4]->Draw("e3");
  tg4    [4]->Draw("e3");
  tg1    [4]->Draw("p");
  tg1_sys[4]->Draw("zp");
  tg3    [4]->Draw("p");
  tg3_sys[4]->Draw("zp");





  pad[5]->cd();
  gPad->SetTopMargin(0);
  gPad->SetBottomMargin(0.15);
  gPad->SetLeftMargin(0.12);
  gPad->SetRightMargin(0.03);
  gPad->SetTicks(1,1);
  TH1D* h6 = (TH1D*)gPad->DrawFrame(x1, -1.4, x2, 0.84);
  h6->GetXaxis()->SetMoreLogLabels();
  h6->GetYaxis()->SetLabelOffset(0.01);
  h6->GetYaxis()->SetNdivisions(505);
  h6->GetXaxis()->SetNoExponent();
  h6->GetXaxis()->ChangeLabel(2, -1, -1, -1, -1, -1, " ");
  h6->GetXaxis()->ChangeLabel(4, -1, -1, -1, -1, -1, " ");
  h6->GetXaxis()->ChangeLabel(6, -1, -1, -1, -1, -1, " ");
  //h6->Draw();
  gPad->SetLogx();
  TBox yellbox6(x1,-1.4, 5, 0.84);
  yellbox6.SetFillColorAlpha(5, 0.2);
  yellbox6.SetLineColorAlpha(5, 0.2);
  yellbox6.Draw();
  l2.Draw();
  tg2    [5]->Draw("e3");
  tg4    [5]->Draw("e3");
  tg1    [5]->Draw("p");
  tg1_sys[5]->Draw("zp");
  tg3    [5]->Draw("p");
  tg3_sys[5]->Draw("zp");


  //draw text
  cas->cd();
  TLatex lax;
  lax.SetTextFont(42);
  lax.SetTextSize(0.060);
  lax.DrawLatex(0.355,0.074, "Collision Energy #sqrt{s_{NN}}  (GeV)");
  lax.SetTextAngle(90);
  lax.SetTextSize(0.050);
  lax.DrawLatex(0.05, 0.295, "Proton");
  lax.DrawLatex(0.05, 0.645, "Net-proton");

  lax.SetTextSize(0.035);
  lax.SetTextAngle(0);
  lax.DrawLatex(0.270,0.89,"(a)  #frac{C_{2}}{#LTp+#bar{p}#GT}");
  lax.DrawLatex(0.600,0.89,"(b)  #frac{C_{3}}{C_{1}}");
  lax.DrawLatex(0.925,0.89,"(c)  #frac{C_{4}}{C_{2}}");
  lax.DrawLatex(0.270,0.48,"(d)  #frac{FC_{2}}{FC_{1}}");
  lax.DrawLatex(0.600,0.48,"(e)  #frac{FC_{3}}{FC_{1}}");
  lax.DrawLatex(0.925,0.48,"(f)  #frac{FC_{4}}{FC_{1}}");

  lax.SetTextAngle(0);
  lax.SetTextFont(62);
  lax.SetTextColor(kP10Red);
  lax.SetTextSize(0.045);
  lax.SetTextFont(72);
  lax.SetTextColor(1);
  lax.SetTextColor(4);
  lax.DrawLatex(0.155,0.880,"CBWC");
  lax.SetTextColor(1);
  lax.SetTextColor(1);
  lax.SetTextSize(0.035);
  lax.SetTextFont(42);
  lax.DrawLatex(0.165,0.800,"5\% Au+Au Collisions");
  lax.SetTextSize(0.035);
  lax.DrawLatex(0.165,0.750,"0.4 < p_{T} < 2.0 GeV/c");



  cas->Print("Fig_AllRatios_CBWC_energy.pdf");
}


