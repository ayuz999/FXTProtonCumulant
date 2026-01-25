#include "../data_points/R42_central_energy_dependence.h"
#include "../data_points/color_definition.h"

void plot_r42_cbwc_diff_muB(){

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
  double FXT_diff[6];
  double FXT_diff_stat[6];
  double FXT_diff_sys[6];

  for(int iPoint=0; iPoint<6; ++iPoint){
    FXT_diff[iPoint] = FXT_CBWC_R42[iPoint] - FXT_CBWC_R42_UrQMD[iPoint];
    FXT_diff_stat[iPoint] = sqrt(pow(FXT_CBWC_R42_stat[iPoint], 2.) + pow(FXT_CBWC_R42_UrQMD_stat[iPoint], 2.) );
    FXT_diff_sys[iPoint] = sqrt(pow(FXT_CBWC_R42_sys[iPoint], 2.) + pow(FXT_CBWC_R42_UrQMD_sys[iPoint], 2.) );
  }

  //use 5 to exclude 5.2 for now
  TGraphErrors* tg2 = new TGraphErrors(5, FXT_CBWC_R42_muB, FXT_diff, FXT_CBWC_R42_ex, FXT_diff_stat);
  TGraphErrors* tg3 = new TGraphErrors(5, FXT_CBWC_R42_muB, FXT_diff, FXT_CBWC_R42_ex, FXT_CBWC_R42_ex);
  TGraphErrors* tg4 = new TGraphErrors(5, FXT_CBWC_R42_muB, FXT_diff, FXT_CBWC_R42_ex, FXT_diff_sys);

  tg2->SetMarkerStyle(25);
  tg3->SetMarkerStyle(21);
  tg4->SetMarkerStyle(25);

  tg3->SetMarkerSize(1.0);
  tg2->SetMarkerSize(1.6);
  tg4->SetMarkerSize(1.8);

  tg3->SetLineStyle(2);
  tg3->SetLineColorAlpha(cidx3, 1.0);
  tg3->SetLineWidth(2);

  tg2->SetMarkerColor(1);
  tg3->SetMarkerColorAlpha(cidx3, 1.0);
  tg4->SetMarkerColor(1);
  tg4->SetLineWidth(8);
  tg4->SetLineColorAlpha(1,0.3);

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
  TH1D* h1 = (TH1D*) gPad->DrawFrame(xl1, -0.75, xl2, 1.15);
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


  tg3->Draw("P");
  tg2->Draw("P");
  tg4->Draw("ZP");
  tcoll3->Draw("P");
  tcoll2->Draw("P");
  tcoll4->Draw("ZP");


  TLatex ll;
  ll.SetTextFont(42);
  ll.SetNDC();
  ll.SetTextSize(0.06);
  ll.SetTextSize(0.045);
  ll.SetTextSize(0.06);

  ////draw text
  cas->cd();
  lax.SetTextFont(42);
  lax.DrawLatex(0.530,0.040, "#mu_{B} (MeV)");
  lax.SetTextAngle(90);
  lax.SetTextSize(0.045);
  lax.DrawLatex(0.036,0.350,"[C_{4}/C_{2}]^{Data}-[C_{4}/C_{2}]^{UrQMD}");
  lax.SetTextAngle(0);
  lax.SetTextSize(0.04);
  //TBox *wb2 = new TBox(0.188,0.4, 0.460, 0.46);
  //wb2->SetFillColor(0);

  cas->Print("Fig_R42_CBWC_diff_muB.pdf");
}
