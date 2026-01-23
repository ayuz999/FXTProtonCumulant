double oscillatingCurve(double *x, double *par) {
    // 参数说明：
    // par[0] = A1 (初始下降幅度)
    // par[1] = k1 (初始下降陡峭度)
    // par[2] = x1 (初始下降中心)
    // par[3] = A2 (上升幅度)
    // par[4] = k2 (上升陡峭度)
    // par[5] = x2 (上升中心)
    // par[6] = A3 (最终下降幅度)
    // par[7] = k3 (最终下降陡峭度)
    // par[8] = x3 (最终下降中心)
    
    double A1 = par[0];
    double k1 = par[1];
    double x1 = par[2];
    double A2 = par[3];
    double k2 = par[4];
    double x2 = par[5];
    double A3 = par[6];
    double k3 = par[7];
    double x3 = par[8];
    
    // 初始下降（0 → -4）
    double fall1 = -A1 / (1.0 + exp(-k1 * (x[0] - x1)));
    
    // 上升（-4 → 2）
    double rise = A2 / (1.0 + exp(-k2 * (x[0] - x2)));
    
    // 最终下降（2 → 0）
    double fall2 = -A3 / (1.0 + exp(-k3 * (x[0] - x3)));
    
    return 1.0*(fall1 + rise + fall2);
}




void plotv1(){

  //customized colors
  float float_cl1[3]={25,156,119}; //green
  float float_cl2[3]={244,125,31}; //orange
  float float_cl3[3]={68, 141, 252}; //blue
  float float_cl4[3]={109,62,153}; //purple
  float float_cl5[3]={0,0,0};
  float float_cl6[3]={250, 175, 48}; //yellow
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


  //data point from FXT energies
  int n = 5;
  double x1[5]={3, 3.2, 3.5, 3.9, 4.5};
  double ex1[5]={0,0,0,0,0};
  //data 0-5%
  double y1[5]=  {-0.8457, -0.3476, 0.0275, 0.2420, 1.1951};
  double ey1[5]= {0.0862,  0.0670,  0.1707, 0.1606, 0.4257};
  double ey11[5]={0.8219,  0.2901,  0.2140, 0.1434, 0.3603};
  TGraphErrors* tg1 = new TGraphErrors(n,x1,y1,ex1,ey1);
  tg1->SetMarkerStyle(21);
  tg1->SetMarkerColorAlpha(cidx3, 1.0);
  tg1->SetLineColorAlpha(1,1.0);
  tg1->SetLineWidth(2);
  TGraphErrors* tg1_sys = new TGraphErrors(n,x1,y1,ex1,ey11);
  tg1_sys->SetLineColorAlpha(cidx3, 0.90);
  tg1_sys->SetLineWidth(13);
  tg1_sys->SetMarkerSize(1.6);
  tg1_sys->SetMarkerStyle(25);
  TGraphErrors* tg1_prof = new TGraphErrors(n,x1,y1,ex1,ex1);
  tg1_prof->SetMarkerColorAlpha(1, 1.0);
  tg1_prof->SetMarkerStyle(25);
  tg1_prof->SetMarkerSize(1.8);
  tg1_prof->SetLineWidth(2);

  //UrQMD results at FXT energies with scaling on RefMult3
  //UrQMD 0-5%
  double x3  [6]={3, 3.2, 3.5, 3.9, 4.5, 5.2};
  double ex3 [6]={0,0,0,0,0,0};
  double y3  [6]={-1.37890, -0.965221, -0.257811, 0.141463, 0.38697, 0.72925};
  double ey3 [6]={0.092023,  0.066248,  0.059953, 0.064884, 0.06358, 0.15926};
  double ey33[6]={0.043657,  0.011904,  0.020361, 0.018803, 0.04108, 0.00000};
  for(int i=0;i<5;++i){
    ey3[i] = sqrt(pow(ey3[i],2.)+pow(ey33[i],2.));
  }
  TGraphErrors* tgu = new TGraphErrors(6,x3,y3,ex3,ey3);
  tgu->SetMarkerStyle(20);
  tgu->SetMarkerColorAlpha(cidx2,1.0);
  tgu->SetFillColorAlpha  (cidx2,1.0);
  tgu->SetLineColorAlpha  (cidx2,1.0);
  tgu->SetFillStyle(3244);


  //data, method 2
  double x5  [5]={3.2, 3.5, 3.9, 4.5, 5.2};
  double xe5 [5]={0,0,0,0,0};
  double y5  [5]={0.1827, 0.349245, 0.4167, 0.9216, 0.7649};
  double ey5 [5]={0.0600, 0.088172, 0.1156, 0.1671, 0.1703};
  double ey55[5]={0.1825, 0.168719, 0.1258, 0.1205, 0.0000};
  TGraphErrors* tg5 = new TGraphErrors(5,x5,y5,xe5, ey5);
  TGraphErrors* tg5_sys = new TGraphErrors(5,x5,y5,xe5, ey55);
  TGraphErrors* tg5_prof = new TGraphErrors(5,x5,y5,xe5, xe5);
  tg5->SetMarkerStyle(20);
  tg5_sys->SetMarkerStyle(24);
  tg5_prof->SetMarkerStyle(24);
  tg5_sys->SetMarkerSize(1.6); 
  tg5_prof->SetMarkerSize(1.8); 
  tg5_sys->SetLineWidth(13);
  tg5_sys->SetLineColorAlpha(1,0.3);


  //urqmd, method 2
  double x6  [4]={3.2, 3.5, 3.9, 4.5};
  double xe6 [4]={0,0,0,0};
  double y6  [4]={0.1324, 0.3176, 0.2897, 0.3118};
  double ey6 [4]={0.0662, 0.0607, 0.0645, 0.0842};
  TGraphErrors* tg6 = new TGraphErrors(4,x6,y6,xe6,ey6);
  TGraphErrors* tg6_prof = new TGraphErrors(4,x6,y6,xe6,ey6);
  tg6->SetMarkerStyle(28);
  tg6->SetMarkerSize(1.8);
  tg6->SetMarkerColor(4);
  tg6_prof->SetMarkerStyle(28);
  tg6_prof->SetMarkerSize(1.6);
  tg6_prof->SetMarkerColor(4);

  
  //data points from collider energies
  //
  double Energies[9] = {7.7, 9.2, 11.5, 14.6, 17.3, 19.6, 27., 39., 54.4};
  double C42_5[9] = {0.417735, 0.550703, 0.381199, 0.430751, 0.356063, 0.328484, 0.602046,           0.739693, 0.69715};
  double C42_5_stat[9] = {0.246897, 0.183197, 0.137369, 0.104085, 0.120039, 0.0733153, 0.0950052,    0.147006, 0.053074};
  double C42_5_sys[9] = {0.134838, 0.0739699, 0.0537708, 0.0403519, 0.0795194, 0.0404057, 0.0304235, 0.135754, 0.0482269};
  double collex[12]={0,0,0,0,0,0,0,0,0,0,0,0};
  TGraphErrors* tgcoll = new TGraphErrors(9, Energies, C42_5, collex, C42_5_stat);
  tgcoll->SetMarkerStyle(21);
  tgcoll->SetFillColorAlpha(1, 1.);
  tgcoll->SetLineColorAlpha(1, 1.);
  tgcoll->SetLineWidth(2);
  tgcoll->SetMarkerColorAlpha(2, 1.0);
  tgcoll->SetMarkerSize(1.0);
  TGraphErrors* tgcoll_sys = new TGraphErrors(9, Energies, C42_5, collex, C42_5_sys);
  tgcoll_sys->SetFillColorAlpha(2, 1.0);
  tgcoll_sys->SetLineColorAlpha(2, 1.0);
  tgcoll_sys->SetLineWidth(12);
  tgcoll_sys->SetMarkerStyle(25);
  tgcoll_sys->SetMarkerSize(1.6);
  TGraphErrors* tgcoll_prof = new TGraphErrors(9,Energies,C42_5,collex,collex);
  tgcoll_prof->SetMarkerColorAlpha(1, 1.0);
  tgcoll_prof->SetMarkerStyle(25);
  tgcoll_prof->SetMarkerSize(1.8);
  
  //UrQMD results at collider energies
  double Erg9[9]={7.7, 9.2, 11.5, 14.6, 17.3, 19.6, 27, 39, 54.4};
  double rC42_5_UrQMD[10]      ={-0.2026,  0.4755,  0.4628,  0.5257,  0.5962,  0.6787,  0.7332,  0.9032, 0.8600, 0.8397};
  double rC42_5_UrQMD_stat[10] ={0.117985, 0.0644,  0.0628,  0.0677,  0.0708,  0.0529,  0.0581,  0.0517, 0.0457, 0.0557};
  double C42_5_UrQMD[9] =      {0.4755,  0.4628,  0.5257,  0.5962,  0.6787,  0.7332,  0.8714, 0.8600, 0.8397};
  double C42_5_UrQMD_stat[9] = {0.0644,  0.0628,  0.0677,  0.0708,  0.0529,  0.0581,  0.0517, 0.0457, 0.0557};
  double collex2[9]={0,0,0,0,0,0,0,0,0};
  TGraphErrors* tgucoll = new TGraphErrors(9, Erg9, C42_5_UrQMD, collex2, C42_5_UrQMD_stat);
  tgucoll->SetFillColorAlpha(cidx4, 0.6);
  tgucoll->SetLineColorAlpha(cidx4, 0.6);


  //make the plot
  //---------------------------------------------
  double xl1 = 2.5;
  double xl2 = 63;
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
  TH1D* h1 = (TH1D*) gPad->DrawFrame(xl1, -1.3, xl2, 1.85);
  h1->GetXaxis()->SetNoExponent();
  h1->GetXaxis()->SetMoreLogLabels();
  h1->GetYaxis()->SetNdivisions(505);
  h1->GetXaxis()->SetNdivisions(505);
  h1->GetYaxis()->SetLabelOffset(0.014);
  h1->GetXaxis()->ChangeLabel(4, -1, -1, -1, -1, -1, " ");
  h1->GetXaxis()->ChangeLabel(6, -1, -1, -1, -1, -1, " ");
  h1->GetXaxis()->ChangeLabel(7, -1, -1, -1, -1, -1, " ");
  h1->GetXaxis()->ChangeLabel(13, -1, -1, -1, -1, -1, " ");
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

  tg5->Draw("p");
  tg5_sys->Draw("zp");
  tg5_prof->Draw("p");


  tg6->Draw("p");
  tg6_prof->Draw("p");


  p1->cd();
  //data markers
  TMarker *tm1 = new TMarker(25.4,-0.75,21);
  tm1->SetMarkerColorAlpha(2, 1.0);
  tm1->SetMarkerSize(1.0);
  tm1->Draw();
  TMarker *tm2 = new TMarker(25.4,-0.75,25);
  tm2->SetMarkerColorAlpha(1, 1.0);
  tm2->SetMarkerSize(1.6);
  tm2->Draw();
  TMarker *tm22 = new TMarker(25.4,-0.75,25);
  tm22->SetMarkerColorAlpha(1, 1.0);
  tm22->SetMarkerSize(1.8);
  tm22->Draw();
  TMarker *tm3 = new TMarker(25.4,-0.985,21);
  tm3->SetMarkerColorAlpha(cidx3, 1.00);
  tm3->SetMarkerSize(1.0);
  tm3->Draw();
  TMarker *tm4 = new TMarker(25.4,-0.985,25);
  tm4->SetMarkerColorAlpha(1, 1.00);
  tm4->SetMarkerSize(1.6);
  tm4->Draw();
  TMarker *tm44 = new TMarker(25.4,-0.985,25);
  tm44->SetMarkerColorAlpha(1, 1.00);
  tm44->SetMarkerSize(1.8);
  tm44->Draw();
  TMarker *tm5 =   new TMarker(25.4,-0.48,20);
  tm5->SetMarkerColorAlpha(1, 1.00);
  tm5->SetMarkerSize(1.0);
  tm5->Draw();
  TMarker *tm55 =  new TMarker(25.4,-0.48,24);
  tm55->SetMarkerColorAlpha(1, 1.00);
  tm55->SetMarkerSize(1.8);
  tm55->Draw();
  TMarker *tm555 = new TMarker(25.4,-0.48,24);
  tm555->SetMarkerColorAlpha(1, 1.00);
  tm555->SetMarkerSize(1.6);
  tm555->Draw();
  TMarker *tm66 = new TMarker(40.5,-0.480,28);
  tm66->SetMarkerColorAlpha(4, 1.00);
  tm66->SetMarkerSize(1.8);
  tm66->Draw();
  TMarker *tm666 = new TMarker(40.5,-0.480,28);
  tm666->SetMarkerColorAlpha(4, 1.00);
  tm666->SetMarkerSize(1.6);
  tm666->Draw();

  //UrQMD bands
  TBox *b1 = new TBox(34,-0.68,47,-0.83);
  b1->SetFillColorAlpha(cidx4, 0.6);
  b1->Draw();
  TBox *b2 = new TBox(34,-0.90,47,-1.05);
  b2->SetFillColorAlpha(cidx2, 1.0);
  b2->SetFillStyle(3244);
  b2->Draw();

  TLatex ll;
  ll.SetTextFont(42);
  ll.SetNDC();
  ll.SetTextSize(0.06);
  ll.SetTextSize(0.05);
  ll.DrawLatex(0.420,0.310,"Method 2");
  ll.DrawLatex(0.420,0.240,"|y| < 0.5, Net-proton");
  ll.DrawLatex(0.420,0.170,"#minus0.5 < y < 0, Proton");
  ll.SetTextSize(0.06);
  ll.DrawLatex(0.70,0.390,"Data");
  ll.DrawLatex(0.81,0.390,"UrQMD");

  //draw text
  cas->cd();
  lax.SetTextFont(42);
  lax.DrawLatex(0.360,0.040, "Collision Energy #sqrt{s_{NN}}  (GeV)");
  lax.SetTextAngle(90);
  lax.SetTextSize(0.055);
  lax.DrawLatex(0.066,0.470,"C_{4}/C_{2}");

  lax.SetTextAngle(0);
  lax.SetTextFont(62);
  lax.SetTextSize(0.065);
  lax.SetTextFont(72);
  lax.DrawLatex(0.42,0.850,"STAR");
  lax.SetTextSize(0.055);
  lax.SetTextFont(42);
  lax.DrawLatex(0.60,0.810,"5\% Au+Au Collisions");
  lax.DrawLatex(0.60,0.880,"0.4 < p_{T} < 2.0 GeV/c");
  lax.SetTextColor(1);
  lax.SetTextSize(0.040);
  lax.SetTextFont(42);

  cas->Print("cas1.pdf");
}
