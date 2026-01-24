double rap_pt(double *x_val, double *par){
    double mass = par[0];
    double eta = par[1];
    double pt = x_val[0];
    double rap;

     rap= 0.5 * log(
             (sqrt(pt*pt*cosh(eta)*cosh(eta)+mass*mass) + (pt*sinh(eta))) /
             (sqrt(pt*pt*cosh(eta)*cosh(eta)+mass*mass) - (pt*sinh(eta))));

    return rap;
}


void plot_acceptance(){
  
  TFile *inf1 = new TFile("FXT_Acceptance.root");
  TH2D* h1 = (TH2D*) inf1->Get("pty_3p2");
  TH2D* h2 = (TH2D*) inf1->Get("pty_3p5");
  TH2D* h3 = (TH2D*) inf1->Get("pty_3p9");
  TH2D* h4 = (TH2D*) inf1->Get("pty_4p5");

  h1->SetTitle(";;");
  h2->SetTitle(";;");
  h3->SetTitle(";;");
  h4->SetTitle(";;");

  gStyle->SetOptStat(0);
  //gStyle->SetPalette(1);
  gStyle->SetNumberContours(999);

  TF1* ff1 = new TF1("ff1","0.5*log((sqrt(6.25+0.938*0.938) + sqrt(6.25-x*x)) / (sqrt(6.25+0.938*0.938) - sqrt(6.25-x*x)))", 0,4.0);
  TF1* ff2 = new TF1("ff2","0.5*log((sqrt(6.25+0.938*0.938) + sqrt(6.25-x*x)) / (sqrt(6.25+0.938*0.938) - sqrt(6.25-x*x)))", 0,4.0);
  TF1* ff3 = new TF1("ff3","0.5*log((sqrt(6.25+0.938*0.938) + sqrt(6.25-x*x)) / (sqrt(6.25+0.938*0.938) - sqrt(6.25-x*x)))", 0,4.0);
  TF1* ff4 = new TF1("ff4","0.5*log((sqrt(6.25+0.938*0.938) + sqrt(6.25-x*x)) / (sqrt(6.25+0.938*0.938) - sqrt(6.25-x*x)))", 0,4.0);

  TH1D* hff1 = (TH1D*) ff1->GetHistogram();
  int nbins = hff1->GetNbinsX();
  double mx[nbins],my[nbins];
  for(int i=0;i<nbins;++i){
    mx[i] = hff1->GetXaxis()->GetBinCenter(i+1);
    my[i] = hff1->GetBinContent(i+1)-1.24;
  }
  TGraphErrors* hgg1 = new TGraphErrors(nbins, my, mx);
  hgg1->SetLineColor(2);


  TH1D* hff2 = (TH1D*) ff2->GetHistogram();
  int nbins2 = hff2->GetNbinsX();
  double mx2[nbins2],my2[nbins2];
  for(int i=0;i<nbins2;++i){
    mx2[i] = hff2->GetXaxis()->GetBinCenter(i+1);
    my2[i] = hff2->GetBinContent(i+1)-1.36;
  }
  TGraphErrors* hgg2 = new TGraphErrors(nbins2, my2, mx2);
  hgg2->SetLineColor(4);

  TH1D* hff3 = (TH1D*) ff3->GetHistogram();
  int nbins3 = hff3->GetNbinsX();
  double mx3[nbins3],my3[nbins3];
  for(int i=0;i<nbins3;++i){
    mx3[i] = hff3->GetXaxis()->GetBinCenter(i+1);
    my3[i] = hff3->GetBinContent(i+1)-1.52;
  }
  TGraphErrors* hgg3 = new TGraphErrors(nbins3, my3, mx3);
  hgg3->SetLineColor(4);

  TH1D* hff4 = (TH1D*) ff4->GetHistogram();
  int nbins4 = hff4->GetNbinsX();
  double mx4[nbins4],my4[nbins4];
  for(int i=0;i<nbins4;++i){
    mx4[i] = hff4->GetXaxis()->GetBinCenter(i+1);
    my4[i] = hff4->GetBinContent(i+1)-1.52;
  }
  TGraphErrors* hgg4 = new TGraphErrors(nbins4, my4, mx4);
  hgg4->SetLineColor(4);

  TF1 *f1=new TF1("f1", rap_pt, 5, 4, 2);
  f1->FixParameter(0, 0.938);
  f1->FixParameter(1, -1.45);
  f1->SetLineColor(1);
  f1->SetLineStyle(2);
  f1->SetRange(-3,3);

  TF1 *f2=new TF1("f2", rap_pt, 5, 4, 2);
  f2->FixParameter(0, 0.938);
  f2->FixParameter(1, -1.55);
  f2->SetLineColor(1);
  f2->SetLineStyle(2);
  f2->SetRange(-3,3);

  TF1 *f3=new TF1("f3", rap_pt, 5, 4, 2);
  f3->FixParameter(0, 0.938);
  f3->FixParameter(1, -2.20);
  f3->SetLineColor(1);
  f3->SetLineStyle(2);
  f3->SetRange(-3,3);

  TH1D *_h11;
  TH1D *_h12;
  TH1D *_h13;
  _h11 = (TH1D*)f1->GetHistogram();
  _h12 = (TH1D*)f1->GetHistogram();
  _h13 = (TH1D*)f1->GetHistogram();
  int total11 = _h11->GetNbinsX();
  int total12 = _h12->GetNbinsX();
  int total13 = _h13->GetNbinsX();


  TH1D *_h21;
  TH1D *_h22;
  TH1D *_h23;
  _h21 = (TH1D*)f2->GetHistogram();
  _h22 = (TH1D*)f2->GetHistogram();
  _h23 = (TH1D*)f2->GetHistogram();
  int total21 = _h21->GetNbinsX();
  int total22 = _h22->GetNbinsX();
  int total23 = _h23->GetNbinsX();

  TH1D *_h31;
  TH1D *_h32;
  TH1D *_h33;
  _h31 = (TH1D*)f3->GetHistogram();
  _h32 = (TH1D*)f3->GetHistogram();
  _h33 = (TH1D*)f3->GetHistogram();
  int total31 = _h31->GetNbinsX();
  int total32 = _h32->GetNbinsX();
  int total33 = _h33->GetNbinsX();

  double val_y11[total11],  val_x11[total11];
  double val_y12[total12],  val_x12[total12];
  double val_y13[total13],  val_x13[total13];
  double val_y21[total11],  val_x21[total11];
  double val_y22[total12],  val_x22[total12];
  double val_y23[total13],  val_x23[total13];
  double val_y31[total11],  val_x31[total11];
  double val_y32[total12],  val_x32[total12];
  double val_y33[total13],  val_x33[total13];

  double val_y41[total11], val_x41[total11];
  double val_y42[total12], val_x42[total12];
  double val_y43[total13], val_x43[total13];
  double val_y51[total11], val_x51[total11];
  double val_y52[total12], val_x52[total12];
  double val_y53[total13], val_x53[total13];
  double val_y61[total11], val_x61[total11];
  double val_y62[total12], val_x62[total12];
  double val_y63[total13], val_x63[total13];


    //       3.2    3.5    3.9    4.2   4.5
    //ybeam  1.139  1.254  1.375  1.44  1.522

  //3.5
  for(int i=0; i<total11; i++){
    val_x11[i] = -1*_h11->GetXaxis()->GetBinCenter(i+1);
    val_y11[i] = _h11->GetBinContent(i+1);
    val_x41[i] = val_x11[i];
    val_y41[i] = val_y11[i] - 1.254;
  }

  for(int i=0; i<total12; i++){
    val_x21[i] = -1*_h21->GetXaxis()->GetBinCenter(i+1);
    val_y21[i] = _h21->GetBinContent(i+1);
    val_x51[i] = val_x21[i];
    val_y51[i] = val_y21[i] - 1.254;
  }

  for(int i=0; i<total13; i++){
    val_x31[i] = -1*_h31->GetXaxis()->GetBinCenter(i+1);
    val_y31[i] = _h31->GetBinContent(i+1);
    val_x61[i] = val_x31[i];
    val_y61[i] = val_y31[i] - 1.254;
  }

  TGraphErrors *gr_line11 = new TGraphErrors(total11, val_y41, val_x41);
  TGraphErrors *gr_line12 = new TGraphErrors(total12, val_y51, val_x51);
  TGraphErrors *gr_line13 = new TGraphErrors(total13, val_y61, val_x61);
  gr_line11->SetLineColorAlpha(kRed, 0.5);
  gr_line12->SetLineColorAlpha(kRed, 0.5);
  gr_line13->SetLineColorAlpha(kRed, 0.5);
  gr_line11->SetLineStyle(2);
  gr_line12->SetLineStyle(2);
  gr_line13->SetLineStyle(2);
  gr_line11->SetLineWidth(1);
  gr_line12->SetLineWidth(1);
  gr_line13->SetLineWidth(1);

  //3.9
  for(int i=0; i<total12; i++){
    val_x12[i] = -1*_h12->GetXaxis()->GetBinCenter(i+1);
    val_y12[i] = _h12->GetBinContent(i+1);
    val_x42[i] = val_x12[i];
    val_y42[i] = val_y12[i] - 1.375;
  }

  for(int i=0; i<total22; i++){
    val_x22[i] = -1*_h22->GetXaxis()->GetBinCenter(i+1);
    val_y22[i] = _h22->GetBinContent(i+1);
    val_x52[i] = val_x22[i];
    val_y52[i] = val_y22[i] - 1.375;
  }

  for(int i=0; i<total32; i++){
    val_x32[i] = -1*_h32->GetXaxis()->GetBinCenter(i+1);
    val_y32[i] = _h32->GetBinContent(i+1);
    val_x62[i] = val_x32[i];
    val_y62[i] = val_y32[i] - 1.375;
  }

  TGraphErrors *gr_line21 = new TGraphErrors(total21, val_y42, val_x42);
  TGraphErrors *gr_line22 = new TGraphErrors(total22, val_y52, val_x52);
  TGraphErrors *gr_line23 = new TGraphErrors(total23, val_y62, val_x62);
  gr_line21->SetLineColorAlpha(kRed, 0.5);
  gr_line22->SetLineColorAlpha(kRed, 0.5);
  gr_line23->SetLineColorAlpha(kRed, 0.5);
  gr_line21->SetLineStyle(2);
  gr_line22->SetLineStyle(2);
  gr_line23->SetLineStyle(2);
  gr_line21->SetLineWidth(1);
  gr_line22->SetLineWidth(1);
  gr_line23->SetLineWidth(1);


  //4.5
  for(int i=0; i<total13; i++){
    val_x13[i] = -1*_h13->GetXaxis()->GetBinCenter(i+1);
    val_y13[i] = _h13->GetBinContent(i+1);
    val_x43[i] = val_x13[i];
    val_y43[i] = val_y13[i] - 1.522;
  }

  for(int i=0; i<total23; i++){
    val_x23[i] = -1*_h23->GetXaxis()->GetBinCenter(i+1);
    val_y23[i] = _h23->GetBinContent(i+1);
    val_x53[i] = val_x23[i];
    val_y53[i] = val_y23[i] - 1.522;
  }

  for(int i=0; i<total33; i++){
    val_x33[i] = -1*_h33->GetXaxis()->GetBinCenter(i+1);
    val_y33[i] = _h33->GetBinContent(i+1);
    val_x63[i] = val_x33[i];
    val_y63[i] = val_y33[i] - 1.522;
  }

  TGraphErrors *gr_line31 = new TGraphErrors(total31, val_y43, val_x43);
  TGraphErrors *gr_line32 = new TGraphErrors(total32, val_y53, val_x53);
  TGraphErrors *gr_line33 = new TGraphErrors(total33, val_y63, val_x63);
  gr_line31->SetLineColorAlpha(kRed, 0.5);
  gr_line32->SetLineColorAlpha(kRed, 0.5);
  gr_line33->SetLineColorAlpha(kRed, 0.5);
  gr_line31->SetLineStyle(2);
  gr_line32->SetLineStyle(2);
  gr_line33->SetLineStyle(2);
  gr_line31->SetLineWidth(1);
  gr_line32->SetLineWidth(1);
  gr_line33->SetLineWidth(1);


  //----------------------------------------------------------------------------
  TBox *box1 = new TBox(-0.5,0.4,0.,2.0);
  box1->SetFillStyle(0);
  box1->SetLineColor(4);
  box1->SetLineStyle(1);


  TCanvas *cas = new TCanvas("cas","",1200,450);
  cas->cd();
  gPad->SetTopMargin(0.02);
  gPad->SetRightMargin(0.04);
  gPad->SetLeftMargin(0.20);
  gPad->SetBottomMargin(0.04);

  gStyle->SetTextFont(42);
  cas->Divide(4,1,0,0);
  gStyle->SetGridStyle(2);
  gStyle->SetGridColor(kBlue-6);

  float xmax = 2.22;

  cas->cd(1);
  gPad->SetTopMargin(0.02);
  gPad->SetLeftMargin(0.25);
  gPad->SetRightMargin(0);
  gPad->SetBottomMargin(0.18);
  //gPad->SetGrid(1,1);
  gPad->SetLogz();

  h1->GetXaxis()->SetLabelSize(0.075);
  h1->GetYaxis()->SetLabelOffset(0.030);
  h1->GetYaxis()->SetLabelSize(0.075);

  h1->GetXaxis()->SetNdivisions(005);
  h1->GetYaxis()->SetNdivisions(005);
  h1->GetYaxis()->SetRangeUser(0,xmax);
  h1->GetXaxis()->SetRangeUser(-1.25,1.05);
  h1->Draw("col");
  box1->Draw();

  cas->cd(2);
  //gPad->SetGrid(1,1);
  gPad->SetLogz();
  gPad->SetLeftMargin(0);
  gPad->SetRightMargin(0);
  gPad->SetTopMargin(0.02);
  gPad->SetBottomMargin(0.18);
  h2->GetXaxis()->SetNdivisions(005);
  h2->GetYaxis()->SetNdivisions(005);
  h2->GetYaxis()->SetRangeUser(0,xmax);
  h2->GetXaxis()->SetRangeUser(-1.35,0.95);
  h2->GetXaxis()->SetLabelSize(0.095);
  h2->GetXaxis()->SetLabelOffset(-0.015);
  h2->Draw("col");
  box1->Draw();
  gr_line11->Draw("lsame");
  gr_line12->Draw("lsame");
  //gr_line13->Draw("lsame");

  cas->cd(3);
  //gPad->SetGrid(1,1);
  gPad->SetLogz();
  gPad->SetTopMargin(0.02);
  gPad->SetLeftMargin(0);
  gPad->SetRightMargin(0);
  gPad->SetBottomMargin(0.18);
  h3->GetYaxis()->SetRangeUser(0,xmax);
  h3->GetXaxis()->SetNdivisions(005);
  h3->GetYaxis()->SetNdivisions(005);
  h3->GetXaxis()->SetRangeUser(-1.45,0.85);
  h3->GetYaxis()->SetLabelOffset(0.030);
  h3->GetYaxis()->SetLabelSize(0.075);
  h3->GetXaxis()->SetLabelSize(0.095);
  h3->GetXaxis()->SetLabelOffset(-0.015);
  h3->Draw("col");
  box1->Draw();
  gr_line21->Draw("lsame");
  gr_line22->Draw("lsame");
  //gr_line23->Draw("lsame");

  cas->cd(4);
  //gPad->SetGrid(1,1);
  gPad->SetLogz();
  gPad->SetTopMargin(0.02);
  gPad->SetLeftMargin(0);
  gPad->SetRightMargin(0);
  gPad->SetBottomMargin(0.18);
  h4->GetYaxis()->SetRangeUser(0,xmax);
  h4->GetXaxis()->SetNdivisions(005);
  h4->GetYaxis()->SetNdivisions(005);
  h4->GetXaxis()->SetRangeUser(-1.65,0.66);
  h4->GetYaxis()->SetLabelOffset(0.030);
  h4->GetYaxis()->SetLabelSize(0.075);
  h4->GetXaxis()->SetLabelSize(0.095);
  h4->GetXaxis()->SetLabelOffset(-0.015);
  h4->Draw("col");
  box1->Draw();
  gr_line31->Draw("lsame");
  gr_line32->Draw("lsame");
  //gr_line33->Draw("lsame");



  cas->cd();
  TLatex *lax = new TLatex();
  lax->SetTextFont(42);
  lax->SetNDC();
  lax->SetTextSize(0.055);
  lax->DrawLatex(0.210,0.24,"3.2 GeV");
  lax->DrawLatex(0.445,0.24,"3.5 GeV");
  lax->DrawLatex(0.680,0.24,"3.9 GeV");
  lax->DrawLatex(0.910,0.24,"4.5 GeV");
  //lax->DrawLatex(0.43,0.92,"Fixed target");

  lax->SetTextAngle(0);
  lax->SetTextColor(0);
  lax->SetTextSize(0.045);
  ///lax->DrawLatex(0.445,0.24,"TPC");
  ///lax->DrawLatex(0.495,0.78,"TOF");
  ///lax->DrawLatex(0.550,0.78,"eTOF");

  lax->SetTextAngle(-57);
  lax->SetTextColor(0);
  //lax->DrawLatex(0.10,0.72,"p_{lab} = 2.5 GeV/c");
  //lax->DrawLatex(0.425,0.71,"p_{lab} = 2.5 GeV/c");
  //lax->DrawLatex(0.75,0.71,"p_{lab} = 2.5 GeV/c");


  lax->SetTextAngle(0);
  lax->SetTextColor(1);
  lax->SetTextSize(0.065);
  lax->DrawLatex(0.440,0.04,"Proton Rapidity (y)");
  lax->SetTextAngle(90);
  lax->DrawLatex(0.028,0.44,"p_{T} (GeV/c)");

  lax->SetTextAngle(0);
  lax->SetTextSize(0.05);
  lax->DrawLatex(0.33,0.35, "TPC");
  lax->DrawLatex(0.33,0.75, "bTOF");
  lax->DrawLatex(0.455,0.75, "eTOF");

  cas->Print("acceptance.pdf");
}
