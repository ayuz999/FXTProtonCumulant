#include "r42_data_points.h"
#include "color_definition.h"

void plot_r42_cbwc_muB(){

  //initialize user defined colors
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

  //data C4/C2, CBWC, 0-5%, FXT
  TGraphErrors* tg1      = new TGraphErrors(5, FXT_CBWC_R42_muB, FXT_CBWC_R42, FXT_CBWC_R42_ex, FXT_CBWC_R42_stat);
  tg1->SetMarkerStyle(21);
  tg1->SetMarkerColorAlpha(cidx3, 1.0);
  tg1->SetLineColorAlpha(1,1.0);
  tg1->SetLineWidth(2);
  TGraphErrors* tg1_sys  = new TGraphErrors(5, FXT_CBWC_R42_muB, FXT_CBWC_R42, FXT_CBWC_R42_ex, FXT_CBWC_R42_sys);
  tg1_sys->SetLineColorAlpha(cidx3, 0.90);
  tg1_sys->SetLineWidth(13);
  tg1_sys->SetMarkerSize(1.6);
  tg1_sys->SetMarkerStyle(25);
  TGraphErrors* tg1_prof = new TGraphErrors(5, FXT_CBWC_R42_muB, FXT_CBWC_R42, FXT_CBWC_R42_ex, FXT_CBWC_R42_ex);
  tg1_prof->SetMarkerColorAlpha(1, 1.0);
  tg1_prof->SetMarkerStyle(25);
  tg1_prof->SetMarkerSize(1.8);
  tg1_prof->SetLineWidth(2);

  //UrQMD C4/C2, CBWC, 0-5%, FXT, scaling RefMult3 to data
  TGraphErrors* tgu = new TGraphErrors(6, FXT_CBWC_R42_UrQMD_muB, FXT_CBWC_R42_UrQMD, FXT_CBWC_R42_UrQMD_ex, FXT_CBWC_R42_UrQMD_tot);
  tgu->SetMarkerStyle(20);
  tgu->SetMarkerColorAlpha(cidx2,1.0);
  tgu->SetFillColorAlpha  (cidx2,1.0);
  tgu->SetLineColorAlpha  (cidx2,1.0);
  tgu->SetFillStyle(3244);

  
  //data C4/C2, CBWC, 0-5%, Collider
  TGraphErrors* tgcoll = new TGraphErrors(9, Coll_CBWC_R42_muB, Coll_CBWC_R42, Coll_CBWC_R42_ex, Coll_CBWC_R42_stat);
  tgcoll->SetMarkerStyle(21);
  tgcoll->SetFillColorAlpha(1, 1.);
  tgcoll->SetLineColorAlpha(1, 1.);
  tgcoll->SetLineWidth(2);
  tgcoll->SetMarkerColorAlpha(2, 1.0);
  tgcoll->SetMarkerSize(1.0);
  TGraphErrors* tgcoll_sys = new TGraphErrors(9, Coll_CBWC_R42_muB, Coll_CBWC_R42, Coll_CBWC_R42_ex, Coll_CBWC_R42_sys);
  tgcoll_sys->SetFillColorAlpha(2, 1.0);
  tgcoll_sys->SetLineColorAlpha(2, 1.0);
  tgcoll_sys->SetLineWidth(12);
  tgcoll_sys->SetMarkerStyle(25);
  tgcoll_sys->SetMarkerSize(1.6);
  TGraphErrors* tgcoll_prof = new TGraphErrors(9, Coll_CBWC_R42_muB, Coll_CBWC_R42, Coll_CBWC_R42_ex, Coll_CBWC_R42_ex);
  tgcoll_prof->SetMarkerColorAlpha(1, 1.0);
  tgcoll_prof->SetMarkerStyle(25);
  tgcoll_prof->SetMarkerSize(1.8);
  
  //UrQMD results at collider energies
  TGraphErrors* tgucoll = new TGraphErrors(9, Coll_CBWC_R42_UrQMD_muB, Coll_CBWC_R42_UrQMD, Coll_CBWC_R42_UrQMD_ex, Coll_CBWC_R42_UrQMD_stat);
  tgucoll->SetFillColorAlpha(cidx4, 0.6);
  tgucoll->SetLineColorAlpha(cidx4, 0.6);


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

  TLatex lax;
  lax.SetNDC();
  lax.SetTextFont(62);

  TBox bg1(520, -1.3, xl2, 1.85);
  bg1.SetFillColorAlpha(5, 0.2);
  TBox bg2(520, -5.8, xl2, 5.7);
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
  TH1D* h1 = (TH1D*) gPad->DrawFrame(xl1, -1.3, xl2, 1.85);
  h1->GetXaxis()->SetNoExponent();
  h1->GetXaxis()->SetMoreLogLabels();
  h1->GetYaxis()->SetNdivisions(505);
  h1->GetXaxis()->SetNdivisions(505);
  h1->GetYaxis()->SetLabelOffset(0.014);
  //h1->GetXaxis()->ChangeLabel(4, -1, -1, -1, -1, -1, " ");
  //h1->GetXaxis()->ChangeLabel(6, -1, -1, -1, -1, -1, " ");
  //h1->GetXaxis()->ChangeLabel(7, -1, -1, -1, -1, -1, " ");
  //h1->GetXaxis()->ChangeLabel(13, -1, -1, -1, -1, -1, " ");
  l1.Draw();
  l2.Draw();
  bg1.Draw();
  tgu->Draw("3");
  tgucoll->Draw("3");
  tg1_sys->Draw("Zp");
  tg1_prof->Draw("p");
  tg1->Draw("P");
  tgcoll_sys->Draw("Zp");
  tgcoll_prof->Draw("p");
  tgcoll->Draw("p");

  p1->cd();
  //data markers
  TMarker *tm1 = new TMarker(261.4,-0.75,21);
  tm1->SetMarkerColorAlpha(2, 1.0);
  tm1->SetMarkerSize(1.0);
  tm1->Draw();
  TMarker *tm2 = new TMarker(261.4,-0.75,25);
  tm2->SetMarkerColorAlpha(1, 1.0);
  tm2->SetMarkerSize(1.6);
  tm2->Draw();
  TMarker *tm22 = new TMarker(261.4,-0.75,25);
  tm22->SetMarkerColorAlpha(1, 1.0);
  tm22->SetMarkerSize(1.8);
  tm22->Draw();
  TMarker *tm3 = new TMarker(261.4,-0.48,21);
  tm3->SetMarkerColorAlpha(cidx3, 1.00);
  tm3->SetMarkerSize(1.0);
  tm3->Draw();
  TMarker *tm4 = new TMarker(261.4,-0.48,25);
  tm4->SetMarkerColorAlpha(1, 1.00);
  tm4->SetMarkerSize(1.6);
  tm4->Draw();
  TMarker *tm44 = new TMarker(261.4,-0.48,25);
  tm44->SetMarkerColorAlpha(1, 1.00);
  tm44->SetMarkerSize(1.8);
  tm44->Draw();

  //UrQMD bands
  TBox *b1 = new TBox(325,-0.68,425,-0.83);
  b1->SetFillColorAlpha(cidx4, 0.6);
  b1->Draw();
  TBox *b2 = new TBox(325,-0.40,425,-0.55);
  b2->SetFillColorAlpha(cidx2, 1.0);
  b2->SetFillStyle(3244);
  b2->Draw();

  TLatex ll;
  ll.SetTextFont(42);
  ll.SetNDC();
  ll.SetTextSize(0.06);
  ll.SetTextSize(0.045);
  ll.DrawLatex(0.130,0.240,"Old Method, |y|<0.5, Net-proton");
  ll.DrawLatex(0.130,0.310,"Old Method, #minus0.5<y<0, Proton");
  ll.SetTextSize(0.06);
  ll.DrawLatex(0.50,0.390,"Data");
  ll.DrawLatex(0.61,0.390,"UrQMD");

  //draw text
  cas->cd();
  lax.SetTextFont(42);
  lax.DrawLatex(0.530,0.040, "#mu_{B} (MeV)");
  lax.SetTextAngle(90);
  lax.SetTextSize(0.055);
  lax.DrawLatex(0.066,0.470,"C_{4}/C_{2}");

  lax.SetTextAngle(0);
  lax.SetTextFont(62);
  lax.SetTextSize(0.065);
  lax.SetTextFont(72);
  lax.DrawLatex(0.16,0.850,"STAR");
  lax.SetTextSize(0.055);
  lax.SetTextFont(42);
  lax.DrawLatex(0.34,0.810,"5\% Au+Au Collisions");
  lax.DrawLatex(0.34,0.880,"0.4 < p_{T} < 2.0 GeV/c");
  lax.SetTextColor(1);
  lax.SetTextSize(0.040);
  lax.SetTextFont(42);

  cas->Print("Fig_R42_CBWC_muB.pdf");
}
