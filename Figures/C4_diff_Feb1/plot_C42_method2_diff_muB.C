
#include "DataPoints/C42_central_energy_dependence_2026Feb1.h"
#include "DataPoints/Collider_CBWC_energy_dependence_all.h"
#include "DataPoints/UrQMD_Collider_CBWC_energy_dependence_ratios.h"
#include "DataPoints/UrQMD_FXT_Method2_energy_dependence_all.h"

void plot_C42_method2_diff_muB(){

  //calculate difference in Collider energies
  double Coll_diff[9];
  double Coll_diff_stat[9];
  double Coll_diff_sys[9];
  for(int i=0;i<9;++i){
    Coll_diff[i]      =          cObservables[2][0][i]           -     UrQMD_Collider_CBWC_Netp_R42_Cent05     [i];
    Coll_diff_stat[i] = sqrt(pow(cObservables_sts[2][0][i], 2.) + pow(UrQMD_Collider_CBWC_Netp_R42_Cent05_stat[i] ,2.) );
    Coll_diff_sys[i]  =          cObservables_sys[2][0][i];
  }
  double dummy_ex[9]={0,0,0,  0,0,0,  0,0,0};
  TGraphErrors* tg_coll1 = new TGraphErrors(9, Coll_CBWC_muB, Coll_diff, dummy_ex, Coll_diff_stat);
  TGraphErrors* tg_coll2 = new TGraphErrors(9, Coll_CBWC_muB, Coll_diff, dummy_ex, dummy_ex);
  TGraphErrors* tg_coll3 = new TGraphErrors(9, Coll_CBWC_muB, Coll_diff, dummy_ex, Coll_diff_sys); 

  tg_coll1->SetMarkerStyle(25);
  tg_coll1->SetMarkerSize(1.6);
  tg_coll2->SetMarkerStyle(21);
  tg_coll2->SetMarkerColorAlpha(2, 1.0);
  tg_coll2->SetLineColorAlpha(2, 1.0);
  tg_coll2->SetLineStyle(2);
  tg_coll2->SetLineWidth(2);
  tg_coll3->SetMarkerStyle(25);
  tg_coll3->SetMarkerSize(1.8);
  tg_coll3->SetLineWidth(8);
  tg_coll3->SetLineColorAlpha(1,0.3);

  //calculate difference in FXT energies
  double FXT_diff[6];
  double FXT_diff_stat[6];
  double FXT_diff_sys[6];

  for(int ipoint=0; ipoint<6;++ipoint){
    FXT_diff[ipoint] =               FXT_Method2_R42[ipoint]           -     UrQMD_FXT_Method2_R42_Cent05[ipoint];
    FXT_diff_stat[ipoint] = sqrt(pow(FXT_Method2_R42_stat[ipoint], 2.) + pow(UrQMD_FXT_Method2_R42_Cent05_stat[ipoint], 2.));
    FXT_diff_sys[ipoint] =           FXT_Method2_R42_sys[ipoint];
  }
  TGraphErrors* tg_fxt1 = new TGraphErrors(6, FXT_Method2_R42_muB, FXT_diff, FXT_Method2_R42_ex, FXT_diff_stat);
  TGraphErrors* tg_fxt2 = new TGraphErrors(6, FXT_Method2_R42_muB, FXT_diff, FXT_Method2_R42_ex, FXT_Method2_R42_ex);
  TGraphErrors* tg_fxt3 = new TGraphErrors(6, FXT_Method2_R42_muB, FXT_diff, FXT_Method2_R42_ex, FXT_diff_sys);
  tg_fxt1->SetMarkerStyle(20);
  tg_fxt2->SetMarkerStyle(24);
  tg_fxt3->SetMarkerStyle(24);
  tg_fxt2->SetMarkerSize(1.6); 
  tg_fxt3->SetMarkerSize(1.8); 
  tg_fxt3->SetLineWidth(8);
  tg_fxt3->SetLineColorAlpha(1,0.3);


  //---------------------------------------------
  //start to plot
  double xl1 = 75;
  double xl2 = 933;
  TLine l1(xl1, 1, xl2, 1);
  l1.SetLineStyle(2);
  l1.SetLineColorAlpha(1,0.4);
  TLine l2(xl1, 0, xl2, 0);
  l2.SetLineStyle(7);
  l2.SetLineColorAlpha(1,0.4);
  l2.SetLineWidth(2);

  
  TCanvas *cas = new TCanvas("cas","", 980, 650);
  cas->cd();
  TPad* p1 = new TPad("p1","",0.02,0.06,0.99,0.99);
  p1->Draw();
  p1->cd();

  gStyle->SetEndErrorSize(3);
  gStyle->SetLabelFont(43, "XY");
  gStyle->SetLabelSize(30,"XY");
  gPad->SetLogx();
  gPad->SetRightMargin(0.01);
  gPad->SetTopMargin(0.02);
  gPad->SetTicks(1,1);

  //draw axis
  TH1D* h1 = (TH1D*) gPad->DrawFrame(xl1, -0.65, xl2, 1.15);
  h1->GetXaxis()->SetNoExponent();
  h1->GetXaxis()->SetMoreLogLabels();
  h1->GetYaxis()->SetNdivisions(505);
  h1->GetXaxis()->SetNdivisions(505);
  h1->GetYaxis()->SetLabelOffset(0.014);
  h1->GetXaxis()->ChangeLabel(2, -1, -1, -1, -1, -1, " ");
  h1->GetXaxis()->ChangeLabel(4, -1, -1, -1, -1, -1, " ");
  h1->GetXaxis()->ChangeLabel(6, -1, -1, -1, -1, -1, " ");
  h1->GetXaxis()->ChangeLabel(7, -1, -1, -1, -1, -1, " ");
  h1->GetXaxis()->ChangeLabel(11, -1, -1, -1, -1, -1, " ");
  h1->GetXaxis()->ChangeLabel(13, -1, -1, -1, -1, -1, " ");

  //draw dashed line
  l1.Draw();
  l2.Draw();

  //draw data points
  tg_fxt1->Draw("P");
  tg_fxt2->Draw("P");
  tg_fxt3->Draw("ZP");

  tg_coll1->Draw("P");
  tg_coll2->Draw("P");
  tg_coll3->Draw("ZP");

  //draw Marker
  TLatex ll;
  ll.SetTextFont(42);
  ll.SetNDC();
  ll.SetTextSize(0.045);
  ll.SetTextSize(0.06);

  TMarker *tm1  = new TMarker(89.4,0.76,20);
  TMarker *tm2  = new TMarker(89.4,0.76,24);
  TMarker *tm22 = new TMarker(89.4,0.76,24);
  tm1->SetMarkerColorAlpha(1, 1.0);
  tm1->SetMarkerSize(1.0);
  tm1->Draw();
  tm2->SetMarkerColorAlpha(1, 1.0);
  tm2->SetMarkerSize(1.6);
  tm2->Draw();
  tm22->SetMarkerColorAlpha(1, 1.0);
  tm22->SetMarkerSize(1.8);
  tm22->Draw();


  //draw text
  cas->cd();
  TLatex lax;
  lax.SetNDC();
  lax.SetTextFont(62);
  lax.SetTextFont(42);
  lax.DrawLatex(0.30,0.040, "Baryon Chemical Potential #mu_{B} (MeV)");
  lax.SetTextAngle(90);
  lax.SetTextSize(0.045);
  lax.DrawLatex(0.036,0.350,"C_{4}/C_{2} difference (Method 2)");
  lax.SetTextAngle(0);
  lax.SetTextSize(0.04);
  lax.DrawLatex(0.22,0.784,"[C_{4}/C_{2}]^{Data}_{0-5%} - [C_{4}/C_{2}]^{UrQMD}_{0-5%}");

  cas->Print("Fig_C42_Method2_diff_muB.pdf");
}
