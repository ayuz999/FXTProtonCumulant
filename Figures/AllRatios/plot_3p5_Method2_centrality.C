#include "../../data_points/FXT_Method2_centrality_dependence_all.h"
#include "../../data_points/UrQMD_FXT_Method2_centrality_dependence_all.h"

#include "../../data_points/FXT_CBWC_centrality_dependence_all.h"
#include "../../data_points/UrQMD_FXT_CBWC_centrality_dependence_all.h"

#include "../../data_points/FXT_Data_Npart.h"
#include "../../data_points/UrQMD_FXT_Npart.h"

#include "../color_definition.h"

//0-5% 
void plot_3p5_Method2_centrality(){

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
  TGraphErrors *tg1[6];
  TGraphErrors *tg1_sys[6];
  TGraphErrors *tg1_prof[6];
  double dummy_ex[7]={0,0,0,0, 0,0,0};
  tg1[0]      = new TGraphErrors(7, FXT_Data_3p5_Npart, FXT_Method2_3p5_R21,  dummy_ex, FXT_Method2_3p5_R21_stat);
  tg1_sys[0]  = new TGraphErrors(7, FXT_Data_3p5_Npart, FXT_Method2_3p5_R21,  dummy_ex, FXT_Method2_3p5_R21_sys);
  tg1_prof[0] = new TGraphErrors(7, FXT_Data_3p5_Npart, FXT_Method2_3p5_R21,  dummy_ex, dummy_ex);
  tg1[1]      = new TGraphErrors(7, FXT_Data_3p5_Npart, FXT_Method2_3p5_R31,  dummy_ex, FXT_Method2_3p5_R31_stat);
  tg1_sys[1]  = new TGraphErrors(7, FXT_Data_3p5_Npart, FXT_Method2_3p5_R31,  dummy_ex, FXT_Method2_3p5_R31_sys);
  tg1_prof[1] = new TGraphErrors(7, FXT_Data_3p5_Npart, FXT_Method2_3p5_R31,  dummy_ex, dummy_ex);
  tg1[2]      = new TGraphErrors(7, FXT_Data_3p5_Npart, FXT_Method2_3p5_R42,  dummy_ex, FXT_Method2_3p5_R42_stat);
  tg1_sys[2]  = new TGraphErrors(7, FXT_Data_3p5_Npart, FXT_Method2_3p5_R42,  dummy_ex, FXT_Method2_3p5_R42_sys);
  tg1_prof[2] = new TGraphErrors(7, FXT_Data_3p5_Npart, FXT_Method2_3p5_R42,  dummy_ex, dummy_ex);
  tg1[3]      = new TGraphErrors(7, FXT_Data_3p5_Npart, FXT_Method2_3p5_FC21, dummy_ex, FXT_Method2_3p5_FC21_stat);
  tg1_sys[3]  = new TGraphErrors(7, FXT_Data_3p5_Npart, FXT_Method2_3p5_FC21, dummy_ex, FXT_Method2_3p5_FC21_sys);
  tg1_prof[3] = new TGraphErrors(7, FXT_Data_3p5_Npart, FXT_Method2_3p5_FC21, dummy_ex, dummy_ex);
  tg1[4]      = new TGraphErrors(7, FXT_Data_3p5_Npart, FXT_Method2_3p5_FC31, dummy_ex, FXT_Method2_3p5_FC31_stat);
  tg1_sys[4]  = new TGraphErrors(7, FXT_Data_3p5_Npart, FXT_Method2_3p5_FC31, dummy_ex, FXT_Method2_3p5_FC31_sys);
  tg1_prof[4] = new TGraphErrors(7, FXT_Data_3p5_Npart, FXT_Method2_3p5_FC31, dummy_ex, dummy_ex);
  tg1[5]      = new TGraphErrors(7, FXT_Data_3p5_Npart, FXT_Method2_3p5_FC41, dummy_ex, FXT_Method2_3p5_FC41_stat);
  tg1_sys[5]  = new TGraphErrors(7, FXT_Data_3p5_Npart, FXT_Method2_3p5_FC41, dummy_ex, FXT_Method2_3p5_FC41_sys);
  tg1_prof[5] = new TGraphErrors(7, FXT_Data_3p5_Npart, FXT_Method2_3p5_FC41, dummy_ex, dummy_ex);

  for(int i=0;i<6;++i){
    tg1[i]->SetMarkerStyle(20);
    tg1[i]->SetMarkerSize(0.6); 
    tg1_sys[i]->SetMarkerStyle(24);
    tg1_sys[i]->SetMarkerSize(1.0); 
    tg1_sys[i]->SetLineWidth(6);
    tg1_sys[i]->SetLineColorAlpha(1,0.3);
    //tg1_prof[i]->SetMarkerSize(1.4); 
    //tg1_prof[i]->SetMarkerStyle(24);
  }


  //UrQMD, FXT, method 2
  TGraphErrors* tg2[6];
  tg2[0] = new TGraphErrors(7, UrQMD_3p5_Npart, UrQMD_Method2_3p5_R21,  dummy_ex, UrQMD_Method2_3p5_R21_stat);
  tg2[1] = new TGraphErrors(7, UrQMD_3p5_Npart, UrQMD_Method2_3p5_R31,  dummy_ex, UrQMD_Method2_3p5_R31_stat);
  tg2[2] = new TGraphErrors(7, UrQMD_3p5_Npart, UrQMD_Method2_3p5_R42,  dummy_ex, UrQMD_Method2_3p5_R42_stat);
  tg2[3] = new TGraphErrors(7, UrQMD_3p5_Npart, UrQMD_Method2_3p5_FC21, dummy_ex, UrQMD_Method2_3p5_FC21_stat);
  tg2[4] = new TGraphErrors(7, UrQMD_3p5_Npart, UrQMD_Method2_3p5_FC31, dummy_ex, UrQMD_Method2_3p5_FC31_stat);
  tg2[5] = new TGraphErrors(7, UrQMD_3p5_Npart, UrQMD_Method2_3p5_FC41, dummy_ex, UrQMD_Method2_3p5_FC41_stat);
  for(int i=0;i<6;++i){
    tg2[i]->SetFillColorAlpha(4, 0.6);
    tg2[i]->SetLineColorAlpha(4, 0.6);
  }

  //FXT data, CBWc
  TGraphErrors *tg3[6];
  TGraphErrors *tg3_sys[6];
  TGraphErrors *tg3_prof[6];
  tg3[0]      = new TGraphErrors(7, FXT_Data_3p5_Npart, FXT_CBWC_3p5GeV_R21,  dummy_ex, FXT_CBWC_3p5GeV_R21_stat);
  tg3_sys[0]  = new TGraphErrors(7, FXT_Data_3p5_Npart, FXT_CBWC_3p5GeV_R21,  dummy_ex, FXT_CBWC_3p5GeV_R21_sys);
  tg3_prof[0] = new TGraphErrors(7, FXT_Data_3p5_Npart, FXT_CBWC_3p5GeV_R21,  dummy_ex, dummy_ex);
  tg3[1]      = new TGraphErrors(7, FXT_Data_3p5_Npart, FXT_CBWC_3p5GeV_R31,  dummy_ex, FXT_CBWC_3p5GeV_R31_stat);
  tg3_sys[1]  = new TGraphErrors(7, FXT_Data_3p5_Npart, FXT_CBWC_3p5GeV_R31,  dummy_ex, FXT_CBWC_3p5GeV_R31_sys);
  tg3_prof[1] = new TGraphErrors(7, FXT_Data_3p5_Npart, FXT_CBWC_3p5GeV_R31,  dummy_ex, dummy_ex);
  tg3[2]      = new TGraphErrors(7, FXT_Data_3p5_Npart, FXT_CBWC_3p5GeV_R42,  dummy_ex, FXT_CBWC_3p5GeV_R42_stat);
  tg3_sys[2]  = new TGraphErrors(7, FXT_Data_3p5_Npart, FXT_CBWC_3p5GeV_R42,  dummy_ex, FXT_CBWC_3p5GeV_R42_sys);
  tg3_prof[2] = new TGraphErrors(7, FXT_Data_3p5_Npart, FXT_CBWC_3p5GeV_R42,  dummy_ex, dummy_ex);
  tg3[3]      = new TGraphErrors(7, FXT_Data_3p5_Npart, FXT_CBWC_3p5GeV_FC21, dummy_ex, FXT_CBWC_3p5GeV_FC21_stat);
  tg3_sys[3]  = new TGraphErrors(7, FXT_Data_3p5_Npart, FXT_CBWC_3p5GeV_FC21, dummy_ex, FXT_CBWC_3p5GeV_FC21_sys);
  tg3_prof[3] = new TGraphErrors(7, FXT_Data_3p5_Npart, FXT_CBWC_3p5GeV_FC21, dummy_ex, dummy_ex);
  tg3[4]      = new TGraphErrors(7, FXT_Data_3p5_Npart, FXT_CBWC_3p5GeV_FC31, dummy_ex, FXT_CBWC_3p5GeV_FC31_stat);
  tg3_sys[4]  = new TGraphErrors(7, FXT_Data_3p5_Npart, FXT_CBWC_3p5GeV_FC31, dummy_ex, FXT_CBWC_3p5GeV_FC31_sys);
  tg3_prof[4] = new TGraphErrors(7, FXT_Data_3p5_Npart, FXT_CBWC_3p5GeV_FC31, dummy_ex, dummy_ex);
  tg3[5]      = new TGraphErrors(7, FXT_Data_3p5_Npart, FXT_CBWC_3p5GeV_FC41, dummy_ex, FXT_CBWC_3p5GeV_FC41_stat);
  tg3_sys[5]  = new TGraphErrors(7, FXT_Data_3p5_Npart, FXT_CBWC_3p5GeV_FC41, dummy_ex, FXT_CBWC_3p5GeV_FC41_sys);
  tg3_prof[5] = new TGraphErrors(7, FXT_Data_3p5_Npart, FXT_CBWC_3p5GeV_FC41, dummy_ex, dummy_ex);

  for(int i=0;i<6;++i){
    tg3[i]->SetMarkerStyle(21);
    tg3[i]->SetMarkerSize(0.6); 
    tg3_sys[i]->SetMarkerStyle(25);
    tg3_sys[i]->SetMarkerSize(1.0); 
    tg3_sys[i]->SetLineWidth(6);
    tg3_sys[i]->SetLineColorAlpha(1,0.3);
  }


  //UrQMD, FXT, CBWC
  TGraphErrors* tg4[6];
  tg4[0] = new TGraphErrors(7, UrQMD_3p5_Npart, UrQMD_CBWC_3p5_GapON_HY5_R21,  dummy_ex, UrQMD_CBWC_3p5_GapON_HY5_R21_stat);
  tg4[1] = new TGraphErrors(7, UrQMD_3p5_Npart, UrQMD_CBWC_3p5_GapON_HY5_R31,  dummy_ex, UrQMD_CBWC_3p5_GapON_HY5_R31_stat);
  tg4[2] = new TGraphErrors(7, UrQMD_3p5_Npart, UrQMD_CBWC_3p5_GapON_HY5_R42,  dummy_ex, UrQMD_CBWC_3p5_GapON_HY5_R42_stat);
  tg4[3] = new TGraphErrors(7, UrQMD_3p5_Npart, UrQMD_CBWC_3p5_GapON_HY5_FC21, dummy_ex, UrQMD_CBWC_3p5_GapON_HY5_FC21_stat);
  tg4[4] = new TGraphErrors(7, UrQMD_3p5_Npart, UrQMD_CBWC_3p5_GapON_HY5_FC31, dummy_ex, UrQMD_CBWC_3p5_GapON_HY5_FC31_stat);
  tg4[5] = new TGraphErrors(7, UrQMD_3p5_Npart, UrQMD_CBWC_3p5_GapON_HY5_FC41, dummy_ex, UrQMD_CBWC_3p5_GapON_HY5_FC41_stat);
  for(int i=0;i<6;++i){
    tg4[i]->SetFillColorAlpha(2, 0.6);
    tg4[i]->SetLineColorAlpha(2, 0.6);
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

  float x1 = 0.0;
  float x2 = 380;

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
  TH1D* h1 = (TH1D*)gPad->DrawFrame(x1, 0.82, x2, 1.62);
  h1->GetXaxis()->SetNoExponent();
  h1->GetXaxis()->SetMoreLogLabels();
  h1->GetYaxis()->SetNdivisions(505);
  h1->GetXaxis()->SetNdivisions(505);
  h1->GetYaxis()->SetLabelOffset(0.01);
  gPad->SetTicks(1,1);
  l1.Draw();
  tg2[0]->Draw("le3");
  tg1[0]->Draw("p");
  tg1_sys[0]->Draw("zp");
  tg4[0]->Draw("le3");
  tg3[0]->Draw("p");
  tg3_sys[0]->Draw("zp");


  pad[1]->cd();
  gPad->SetBottomMargin(0);
  gPad->SetLeftMargin(0.12);
  gPad->SetRightMargin(0.03);
  gPad->SetTicks(1,1);
  TH1D* h2 = (TH1D*)gPad->DrawFrame(x1, 0.45, x2, 4.45);
  h2->GetXaxis()->SetMoreLogLabels();
  h2->GetXaxis()->SetNoExponent();
  h2->GetYaxis()->SetNdivisions(505);
  h2->GetXaxis()->SetNdivisions(505);
  h2->GetYaxis()->SetLabelOffset(0.01);
  l1.Draw();
  tg2    [1]->Draw("le3");
  tg1    [1]->Draw("p");
  tg1_sys[1]->Draw("zp");
  tg4    [1]->Draw("le3");
  tg3    [1]->Draw("p");
  tg3_sys[1]->Draw("zp");




  pad[2]->cd();
  gPad->SetBottomMargin(0);
  gPad->SetLeftMargin(0.12);
  gPad->SetRightMargin(0.03);
  TH1D* h3 = (TH1D*)gPad->DrawFrame(x1, -1.2, x2, 4.4);
  h3->GetXaxis()->SetMoreLogLabels();
  h3->GetXaxis()->SetNoExponent();
  h3->GetYaxis()->SetLabelOffset(0.01);
  h3->GetYaxis()->SetNdivisions(505);
  h3->GetXaxis()->SetNdivisions(505);
  gPad->SetTicks(1,1);
  l1.Draw();
  tg2    [2]->Draw("e3");
  tg1    [2]->Draw("p");
  tg1_sys[2]->Draw("zp");
  tg4    [2]->Draw("e3");
  tg3    [2]->Draw("p");
  tg3_sys[2]->Draw("zp");




  pad[3]->cd();
  gPad->SetTopMargin(0);
  gPad->SetBottomMargin(0.15);
  gPad->SetLeftMargin(0.12);
  gPad->SetRightMargin(0.03);
  gPad->SetTicks(1,1);
  TH1D* h4 = (TH1D*)gPad->DrawFrame(x1, -0.18, x2, 0.68);
  h4->GetYaxis()->SetLabelOffset(0.01);
  h4->GetXaxis()->SetMoreLogLabels();
  h4->GetYaxis()->SetNdivisions(505);
  h4->GetXaxis()->SetNdivisions(505);
  h4->GetXaxis()->SetNoExponent();
  l2.Draw();
  tg2    [3]->Draw("le3");
  tg1    [3]->Draw("p");
  tg1_sys[3]->Draw("zp");
  tg4    [3]->Draw("le3");
  tg3    [3]->Draw("p");
  tg3_sys[3]->Draw("zp");




  pad[4]->cd();
  gPad->SetTopMargin(0);
  gPad->SetBottomMargin(0.15);
  gPad->SetLeftMargin(0.12);
  gPad->SetRightMargin(0.03);
  TH1D* h5 = (TH1D*)gPad->DrawFrame(x1, -0.38, x2, 0.37);
  h5->GetXaxis()->SetMoreLogLabels();
  h5->GetXaxis()->SetNoExponent();
  h5->GetYaxis()->SetLabelOffset(0.01);
  h5->GetYaxis()->SetNdivisions(505);
  h5->GetXaxis()->SetNdivisions(505);
  l2.Draw();
  gPad->SetTicks(1,1);
  tg2    [4]->Draw("e3");
  tg1    [4]->Draw("p");
  tg1_sys[4]->Draw("zp");
  tg4    [4]->Draw("e3");
  tg3    [4]->Draw("p");
  tg3_sys[4]->Draw("zp");





  pad[5]->cd();
  gPad->SetTopMargin(0);
  gPad->SetBottomMargin(0.15);
  gPad->SetLeftMargin(0.12);
  gPad->SetRightMargin(0.03);
  gPad->SetTicks(1,1);
  TH1D* h6 = (TH1D*)gPad->DrawFrame(x1, -0.48, x2, 0.42);
  h6->GetXaxis()->SetMoreLogLabels();
  h6->GetYaxis()->SetLabelOffset(0.01);
  h6->GetYaxis()->SetNdivisions(505);
  h6->GetXaxis()->SetNdivisions(505);
  h6->GetXaxis()->SetNoExponent();
  l2.Draw();
  tg2    [5]->Draw("e3");
  tg1    [5]->Draw("p");
  tg1_sys[5]->Draw("zp");
  tg4    [5]->Draw("e3");
  tg3    [5]->Draw("p");
  tg3_sys[5]->Draw("zp");


  //draw text
  cas->cd();
  TLatex lax;
  lax.SetTextFont(42);
  lax.SetTextSize(0.060);
  lax.DrawLatex(0.325,0.074, "Number of Participating Nucleons (N_{part})");
  lax.SetTextAngle(90);
  lax.SetTextSize(0.050);
  //lax.DrawLatex(0.05, 0.295, "Proton");
  //lax.DrawLatex(0.05, 0.645, "Net-proton");

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
  lax.SetTextSize(0.035);
  lax.SetTextColor(1);
  lax.DrawLatex(0.12,0.91,"3.5 GeV");
  lax.SetTextSize(0.031);
  lax.SetTextFont(42);
  lax.SetTextSize(0.031);
  lax.DrawLatex(0.12,0.860,"0.4 < p_{T} < 2.0 GeV/c");
  lax.DrawLatex(0.12,0.820,"-0.5 < y < 0");

  //lax.SetTextSize(0.035);
  //lax.DrawLatex(0.495, 0.270, "Data");
  //lax.DrawLatex(0.495, 0.220, "UrQMD");
  //lax.DrawLatex(0.810, 0.270, "Data");
  //lax.DrawLatex(0.810, 0.220, "UrQMD");
  //lax.SetTextSize(0.035);
  //lax.DrawLatex(0.810, 0.320, "|y| < 0.5");
  //lax.DrawLatex(0.495, 0.320, "#minus0.5 < y < 0");

  cas->cd();
  TLegend *leg = new TLegend();
  leg->AddEntry(tg1[0], "Data, CIGAR", "p");
  leg->AddEntry(tg2[0], "UrQMD, CIGAR", "F");
  leg->AddEntry(tg3[0], "Data, CBWC", "p");
  leg->AddEntry(tg4[0], "UrQMD, CBWC", "F");
  leg->SetTextSize(0.031);
  leg->SetX1(0.43);
  leg->SetX2(0.56);
  leg->SetY1(0.78);
  leg->SetY2(0.93);
  leg->SetLineWidth(0);
  leg->Draw();

  TMarker *tm1 = new TMarker(0.4462,0.9115,24);
  tm1->Draw();

  TMarker *tm2 = new TMarker(0.4462,0.8357,25);
  tm2->Draw();

  cas->Print("Fig_3p5_Method2_centrality.pdf");

}

