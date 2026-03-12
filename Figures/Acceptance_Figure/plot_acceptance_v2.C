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


void plot_acceptance_v2(){
  
  TFile *inf1 = new TFile("../../data_points/Acceptance.root");
  TH2D* h1 = (TH2D*) inf1->Get("hPtY_3p0");
  TH2D* h2 = (TH2D*) inf1->Get("hPtY_3p2");
  TH2D* h3 = (TH2D*) inf1->Get("hPtY_3p5");
  TH2D* h4 = (TH2D*) inf1->Get("hPtY_3p9");
  TH2D* h5 = (TH2D*) inf1->Get("hPtY_4p5");
  TH2D* h6 = (TH2D*) inf1->Get("hPtY_5p2");

  h1->SetTitle(";;");
  h2->SetTitle(";;");
  h3->SetTitle(";;");
  h4->SetTitle(";;");
  h5->SetTitle(";;");
  h6->SetTitle(";;");

  gStyle->SetOptStat(0);
  gStyle->SetNumberContours(999);

  TF1* ff1 = new TF1("ff1","0.5*log((sqrt(6.25+0.938*0.938) + sqrt(6.25-x*x)) / (sqrt(6.25+0.938*0.938) - sqrt(6.25-x*x)))", 0,4.0);
  TF1* ff2 = new TF1("ff2","0.5*log((sqrt(6.25+0.938*0.938) + sqrt(6.25-x*x)) / (sqrt(6.25+0.938*0.938) - sqrt(6.25-x*x)))", 0,4.0);
  TF1* ff3 = new TF1("ff3","0.5*log((sqrt(6.25+0.938*0.938) + sqrt(6.25-x*x)) / (sqrt(6.25+0.938*0.938) - sqrt(6.25-x*x)))", 0,4.0);
  TF1* ff4 = new TF1("ff4","0.5*log((sqrt(6.25+0.938*0.938) + sqrt(6.25-x*x)) / (sqrt(6.25+0.938*0.938) - sqrt(6.25-x*x)))", 0,4.0);
  TF1* ff5 = new TF1("ff5","0.5*log((sqrt(6.25+0.938*0.938) + sqrt(6.25-x*x)) / (sqrt(6.25+0.938*0.938) - sqrt(6.25-x*x)))", 0,4.0);
  TF1* ff6 = new TF1("ff6","0.5*log((sqrt(6.25+0.938*0.938) + sqrt(6.25-x*x)) / (sqrt(6.25+0.938*0.938) - sqrt(6.25-x*x)))", 0,4.0);

    //      3.0    3.2    3.5    3.9     4.5    5.2
    //ybeam 1.049  1.139  1.254  1.375   1.522  1.683

  TH1D* hff1 = (TH1D*) ff1->GetHistogram();
  int nbins = hff1->GetNbinsX();
  double mx[nbins],my[nbins];
  for(int i=0;i<nbins;++i){
    mx[i] = hff1->GetXaxis()->GetBinCenter(i+1);
    my[i] = hff1->GetBinContent(i+1)-1.049;
  }
  TGraphErrors* hgg1 = new TGraphErrors(nbins, my, mx);
  hgg1->SetLineColor(2);


  TH1D* hff2 = (TH1D*) ff2->GetHistogram();
  int nbins2 = hff2->GetNbinsX();
  double mx2[nbins2],my2[nbins2];
  for(int i=0;i<nbins2;++i){
    mx2[i] = hff2->GetXaxis()->GetBinCenter(i+1);
    my2[i] = hff2->GetBinContent(i+1)-1.139;
  }
  TGraphErrors* hgg2 = new TGraphErrors(nbins2, my2, mx2);
  hgg2->SetLineColor(4);

  TH1D* hff3 = (TH1D*) ff3->GetHistogram();
  int nbins3 = hff3->GetNbinsX();
  double mx3[nbins3],my3[nbins3];
  for(int i=0;i<nbins3;++i){
    mx3[i] = hff3->GetXaxis()->GetBinCenter(i+1);
    my3[i] = hff3->GetBinContent(i+1)-1.254;
  }
  TGraphErrors* hgg3 = new TGraphErrors(nbins3, my3, mx3);
  hgg3->SetLineColor(4);

  TH1D* hff4 = (TH1D*) ff4->GetHistogram();
  int nbins4 = hff4->GetNbinsX();
  double mx4[nbins4],my4[nbins4];
  for(int i=0;i<nbins4;++i){
    mx4[i] = hff4->GetXaxis()->GetBinCenter(i+1);
    my4[i] = hff4->GetBinContent(i+1)-1.375;
  }
  TGraphErrors* hgg4 = new TGraphErrors(nbins4, my4, mx4);
  hgg4->SetLineColor(4);

  TH1D* hff5 = (TH1D*) ff5->GetHistogram();
  int nbins5 = hff5->GetNbinsX();
  double mx5[nbins5],my5[nbins5];
  for(int i=0;i<nbins5;++i){
    mx5[i] = hff5->GetXaxis()->GetBinCenter(i+1);
    my5[i] = hff5->GetBinContent(i+1)-1.522;
  }
  TGraphErrors* hgg5 = new TGraphErrors(nbins5, my5, mx5);
  hgg5->SetLineColor(4);

  TH1D* hff6 = (TH1D*) ff6->GetHistogram();
  int nbins6 = hff6->GetNbinsX();
  double mx6[nbins6],my6[nbins6];
  for(int i=0;i<nbins6;++i){
    mx6[i] = hff6->GetXaxis()->GetBinCenter(i+1);
    my6[i] = hff6->GetBinContent(i+1)-1.683;
  }
  TGraphErrors* hgg6 = new TGraphErrors(nbins6, my6, mx6);
  hgg6->SetLineColor(4);


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
  _h12 = (TH1D*)f2->GetHistogram();
  _h13 = (TH1D*)f3->GetHistogram();
  int total11 = _h11->GetNbinsX();
  int total12 = _h12->GetNbinsX();
  int total13 = _h13->GetNbinsX();


  TH1D *_h21;
  TH1D *_h22;
  TH1D *_h23;
  _h21 = (TH1D*)f1->GetHistogram();
  _h22 = (TH1D*)f2->GetHistogram();
  _h23 = (TH1D*)f3->GetHistogram();
  int total21 = _h21->GetNbinsX();
  int total22 = _h22->GetNbinsX();
  int total23 = _h23->GetNbinsX();

  TH1D *_h31;
  TH1D *_h32;
  TH1D *_h33;
  _h31 = (TH1D*)f1->GetHistogram();
  _h32 = (TH1D*)f2->GetHistogram();
  _h33 = (TH1D*)f3->GetHistogram();
  int total31 = _h31->GetNbinsX();
  int total32 = _h32->GetNbinsX();
  int total33 = _h33->GetNbinsX();

  TH1D *_h41;
  TH1D *_h42;
  TH1D *_h43;
  _h41 = (TH1D*)f1->GetHistogram();
  _h42 = (TH1D*)f2->GetHistogram();
  _h43 = (TH1D*)f3->GetHistogram();
  int total41 = _h41->GetNbinsX();
  int total42 = _h42->GetNbinsX();
  int total43 = _h43->GetNbinsX();

  TH1D *_h51;
  TH1D *_h52;
  TH1D *_h53;
  _h51 = (TH1D*)f1->GetHistogram();
  _h52 = (TH1D*)f2->GetHistogram();
  _h53 = (TH1D*)f3->GetHistogram();
  int total51 = _h51->GetNbinsX();
  int total52 = _h52->GetNbinsX();
  int total53 = _h53->GetNbinsX();

  TH1D *_h61;
  TH1D *_h62;
  TH1D *_h63;
  _h61 = (TH1D*)f1->GetHistogram();
  _h62 = (TH1D*)f2->GetHistogram();
  _h63 = (TH1D*)f3->GetHistogram();
  int total61 = _h61->GetNbinsX();
  int total62 = _h62->GetNbinsX();
  int total63 = _h63->GetNbinsX();

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



  //3.0
  for(int i=0; i<total11; i++){
    val_x11[i] = -1*_h11->GetXaxis()->GetBinCenter(i+1);
    val_y11[i] = _h11->GetBinContent(i+1) - 1.049;
  }

  for(int i=0; i<total12; i++){
    val_x12[i] = -1*_h21->GetXaxis()->GetBinCenter(i+1);
    val_y12[i] = _h12->GetBinContent(i+1) - 1.049;
  }

  for(int i=0; i<total13; i++){
    val_x13[i] = -1*_h13->GetXaxis()->GetBinCenter(i+1);
    val_y13[i] = _h13->GetBinContent(i+1) - 1.049;
  }

  TGraphErrors *gr_line11 = new TGraphErrors(total11, val_y11, val_x11);
  TGraphErrors *gr_line12 = new TGraphErrors(total12, val_y12, val_x12);
  TGraphErrors *gr_line13 = new TGraphErrors(total13, val_y13, val_x13);
  gr_line11->SetLineColorAlpha(kRed, 0.5);
  gr_line12->SetLineColorAlpha(kRed, 0.5);
  gr_line13->SetLineColorAlpha(kRed, 0.5);
  gr_line11->SetLineStyle(2);
  gr_line12->SetLineStyle(2);
  gr_line13->SetLineStyle(2);
  gr_line11->SetLineWidth(1);
  gr_line12->SetLineWidth(1);
  gr_line13->SetLineWidth(1);


  //3.2
  for(int i=0; i<total21; i++){
    val_x21[i] = -1*_h21->GetXaxis()->GetBinCenter(i+1);
    val_y21[i] = _h21->GetBinContent(i+1) - 1.139;
  }

  for(int i=0; i<total22; i++){
    val_x22[i] = -1*_h22->GetXaxis()->GetBinCenter(i+1);
    val_y22[i] = _h22->GetBinContent(i+1) - 1.139;
  }

  for(int i=0; i<total23; i++){
    val_x23[i] = -1*_h23->GetXaxis()->GetBinCenter(i+1);
    val_y23[i] = _h23->GetBinContent(i+1) - 1.139;
  }

  TGraphErrors *gr_line21 = new TGraphErrors(total21, val_y21, val_x21);
  TGraphErrors *gr_line22 = new TGraphErrors(total22, val_y22, val_x22);
  TGraphErrors *gr_line23 = new TGraphErrors(total23, val_y23, val_x23);
  gr_line21->SetLineColorAlpha(kRed, 0.5);
  gr_line22->SetLineColorAlpha(kRed, 0.5);
  gr_line23->SetLineColorAlpha(kRed, 0.5);
  gr_line21->SetLineStyle(2);
  gr_line22->SetLineStyle(2);
  gr_line23->SetLineStyle(2);
  gr_line21->SetLineWidth(1);
  gr_line22->SetLineWidth(1);
  gr_line23->SetLineWidth(1);


  //3.5
  for(int i=0; i<total31; i++){
    val_x31[i] = -1*_h31->GetXaxis()->GetBinCenter(i+1);
    val_y31[i] = _h31->GetBinContent(i+1) - 1.254;
  }

  for(int i=0; i<total32; i++){
    val_x32[i] = -1*_h32->GetXaxis()->GetBinCenter(i+1);
    val_y32[i] = _h32->GetBinContent(i+1) - 1.254;
  }

  for(int i=0; i<total33; i++){
    val_x33[i] = -1*_h33->GetXaxis()->GetBinCenter(i+1);
    val_y33[i] = _h33->GetBinContent(i+1) - 1.254;
  }

  TGraphErrors *gr_line31 = new TGraphErrors(total31, val_y31, val_x31);
  TGraphErrors *gr_line32 = new TGraphErrors(total32, val_y32, val_x32);
  TGraphErrors *gr_line33 = new TGraphErrors(total33, val_y33, val_x33);
  gr_line31->SetLineColorAlpha(kRed, 0.5);
  gr_line32->SetLineColorAlpha(kRed, 0.5);
  gr_line33->SetLineColorAlpha(kRed, 0.5);
  gr_line31->SetLineStyle(2);
  gr_line32->SetLineStyle(2);
  gr_line33->SetLineStyle(2);
  gr_line31->SetLineWidth(1);
  gr_line32->SetLineWidth(1);
  gr_line33->SetLineWidth(1);


  //3.9
  for(int i=0; i<total41; i++){
    val_x41[i] = -1*_h41->GetXaxis()->GetBinCenter(i+1);
    val_y41[i] = _h41->GetBinContent(i+1) - 1.375;
  }

  for(int i=0; i<total42; i++){
    val_x42[i] = -1*_h42->GetXaxis()->GetBinCenter(i+1);
    val_y42[i] = _h42->GetBinContent(i+1) - 1.375;
  }

  for(int i=0; i<total43; i++){
    val_x43[i] = -1*_h43->GetXaxis()->GetBinCenter(i+1);
    val_y43[i] = _h43->GetBinContent(i+1) - 1.375;
  }

  TGraphErrors *gr_line41 = new TGraphErrors(total41, val_y41, val_x41);
  TGraphErrors *gr_line42 = new TGraphErrors(total42, val_y42, val_x42);
  TGraphErrors *gr_line43 = new TGraphErrors(total43, val_y43, val_x43);
  gr_line41->SetLineColorAlpha(kRed, 0.5);
  gr_line42->SetLineColorAlpha(kRed, 0.5);
  gr_line43->SetLineColorAlpha(kRed, 0.5);
  gr_line41->SetLineStyle(2);
  gr_line42->SetLineStyle(2);
  gr_line43->SetLineStyle(2);
  gr_line41->SetLineWidth(1);
  gr_line42->SetLineWidth(1);
  gr_line43->SetLineWidth(1);


  //4.5
  for(int i=0; i<total51; i++){
    val_x51[i] = -1*_h51->GetXaxis()->GetBinCenter(i+1);
    val_y51[i] = _h51->GetBinContent(i+1) - 1.522;
  }

  for(int i=0; i<total52; i++){
    val_x52[i] = -1*_h52->GetXaxis()->GetBinCenter(i+1);
    val_y52[i] = _h52->GetBinContent(i+1) - 1.522;
  }

  for(int i=0; i<total53; i++){
    val_x53[i] = -1*_h53->GetXaxis()->GetBinCenter(i+1);
    val_y53[i] = _h53->GetBinContent(i+1) - 1.522;
  }

  TGraphErrors *gr_line51 = new TGraphErrors(total51, val_y51, val_x51);
  TGraphErrors *gr_line52 = new TGraphErrors(total52, val_y52, val_x52);
  TGraphErrors *gr_line53 = new TGraphErrors(total53, val_y53, val_x53);
  gr_line51->SetLineColorAlpha(kRed, 0.5);
  gr_line52->SetLineColorAlpha(kRed, 0.5);
  gr_line53->SetLineColorAlpha(kRed, 0.5);
  gr_line51->SetLineStyle(2);
  gr_line52->SetLineStyle(2);
  gr_line53->SetLineStyle(2);
  gr_line51->SetLineWidth(1);
  gr_line52->SetLineWidth(1);
  gr_line53->SetLineWidth(1);


  //5.2
  for(int i=0; i<total61; i++){
    val_x61[i] = -1*_h61->GetXaxis()->GetBinCenter(i+1);
    val_y61[i] = _h61->GetBinContent(i+1) - 1.683;
  }

  for(int i=0; i<total62; i++){
    val_x62[i] = -1*_h62->GetXaxis()->GetBinCenter(i+1);
    val_y62[i] = _h62->GetBinContent(i+1) - 1.683;
  }

  for(int i=0; i<total63; i++){
    val_x63[i] = -1*_h63->GetXaxis()->GetBinCenter(i+1);
    val_y63[i] = _h63->GetBinContent(i+1) - 1.683;
  }

  TGraphErrors *gr_line61 = new TGraphErrors(total61, val_y61, val_x61);
  TGraphErrors *gr_line62 = new TGraphErrors(total62, val_y62, val_x62);
  TGraphErrors *gr_line63 = new TGraphErrors(total63, val_y63, val_x63);
  gr_line61->SetLineColorAlpha(kRed, 0.5);
  gr_line62->SetLineColorAlpha(kRed, 0.5);
  gr_line63->SetLineColorAlpha(kRed, 0.5);
  gr_line61->SetLineStyle(2);
  gr_line62->SetLineStyle(2);
  gr_line63->SetLineStyle(2);
  gr_line61->SetLineWidth(1);
  gr_line62->SetLineWidth(1);
  gr_line63->SetLineWidth(1);


  //----------------------------------------------------------------------------
  TBox *box1 = new TBox(-0.5,0.4,0.,2.0);
  box1->SetFillStyle(0);
  box1->SetLineColor(4);
  box1->SetLineStyle(1);

  TCanvas *cas = new TCanvas("cas","",800,600);
  cas->cd();
  gPad->SetTopMargin(0.02);
  gPad->SetRightMargin(0.04);
  gPad->SetLeftMargin(0.20);
  gPad->SetBottomMargin(0.08);

  gStyle->SetTextFont(42);
  cas->Divide(3,2,0,0);
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
  h2->GetXaxis()->SetLabelOffset(-0.015);
  h1->GetYaxis()->SetLabelSize(0.075);

  h1->GetXaxis()->SetNdivisions(005);
  h1->GetYaxis()->SetNdivisions(005);
  h1->GetYaxis()->SetRangeUser(0,xmax);
  h1->GetXaxis()->SetRangeUser(-1.05,0.45);
  h1->Draw("col");
  box1->Draw();
  gr_line11->Draw("lsame");
  //gr_line12->Draw("lsame");

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
  h2->GetXaxis()->SetRangeUser(-1.25,0.95);
  h2->GetXaxis()->SetLabelSize(0.095);
  h2->GetXaxis()->SetLabelOffset(-0.015);
  h2->Draw("col");
  box1->Draw();
  gr_line21->Draw("lsame");
  gr_line22->Draw("lsame");
  //gr_line23->Draw("lsame");

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
  h3->GetXaxis()->SetRangeUser(-1.35,0.85);
  h3->GetYaxis()->SetLabelOffset(0.030);
  h3->GetYaxis()->SetLabelSize(0.075);
  h3->GetXaxis()->SetLabelSize(0.095);
  h3->GetXaxis()->SetLabelOffset(-0.015);
  h3->Draw("col");
  box1->Draw();
  gr_line31->Draw("lsame");
  gr_line32->Draw("lsame");
  //gr_line33->Draw("lsame");


  cas->cd(4);
  //gPad->SetGrid(1,1);
  gPad->SetLogz();
  gPad->SetTopMargin(0.02);
  gPad->SetLeftMargin(0.25);
  gPad->SetRightMargin(0);
  gPad->SetBottomMargin(0.18);
  h4->GetYaxis()->SetRangeUser(0,xmax);
  h4->GetXaxis()->SetNdivisions(005);
  h4->GetYaxis()->SetNdivisions(005);
  h4->GetXaxis()->SetRangeUser(-1.45,0.85);
  h4->GetYaxis()->SetLabelOffset(0.030);
  h4->GetYaxis()->SetLabelSize(0.065);
  h4->GetXaxis()->SetLabelSize(0.075);
  //h4->GetXaxis()->SetLabelOffset(-0.015);
  h4->Draw("col");
  box1->Draw();
  gr_line41->Draw("lsame");
  gr_line42->Draw("lsame");
  //gr_line43->Draw("lsame");


  cas->cd(5);
  //gPad->SetGrid(1,1);
  gPad->SetLogz();
  gPad->SetTopMargin(0.02);
  gPad->SetLeftMargin(0);
  gPad->SetRightMargin(0);
  gPad->SetBottomMargin(0.18);
  h5->GetYaxis()->SetRangeUser(0,xmax);
  h5->GetXaxis()->SetNdivisions(005);
  h5->GetYaxis()->SetNdivisions(005);
  h5->GetXaxis()->SetRangeUser(-1.65,0.66);
  h5->GetYaxis()->SetLabelOffset(0.030);
  h5->GetYaxis()->SetLabelSize(0.075);
  h5->GetXaxis()->SetLabelSize(0.095);
  h5->GetXaxis()->SetLabelOffset(-0.015);
  h5->Draw("col");
  box1->Draw();
  gr_line51->Draw("lsame");
  gr_line52->Draw("lsame");
  //gr_line53->Draw("lsame");


  cas->cd(6);
  //gPad->SetGrid(1,1);
  gPad->SetLogz();
  gPad->SetTopMargin(0.02);
  gPad->SetLeftMargin(0);
  gPad->SetRightMargin(0);
  gPad->SetBottomMargin(0.18);
  h6->GetYaxis()->SetRangeUser(0,xmax);
  h6->GetXaxis()->SetNdivisions(005);
  h6->GetYaxis()->SetNdivisions(005);
  h6->GetXaxis()->SetRangeUser(-1.75,0.45);
  h6->GetYaxis()->SetLabelOffset(0.030);
  h6->GetYaxis()->SetLabelSize(0.075);
  h6->GetXaxis()->SetLabelSize(0.095);
  h6->GetXaxis()->SetLabelOffset(-0.015);
  h6->Draw("col");
  box1->Draw();
  gr_line61->Draw("lsame");
  gr_line62->Draw("lsame");
  //gr_line63->Draw("lsame");






  cas->cd();
  TLatex *lax = new TLatex();
  lax->SetTextFont(42);
  lax->SetNDC();
  lax->SetTextSize(0.035);
  lax->DrawLatex(0.288,0.620,"3.0 GeV");
  lax->DrawLatex(0.590,0.620,"3.2 GeV");
  lax->DrawLatex(0.890,0.620,"3.5 GeV");
  lax->DrawLatex(0.288,0.110,"3.9 GeV");
  lax->DrawLatex(0.590,0.110,"4.5 GeV");
  lax->DrawLatex(0.890,0.110,"5.2 GeV");

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
  lax->SetTextSize(0.045);
  lax->DrawLatex(0.410,0.02,"Proton Rapidity (y)");
  lax->SetTextAngle(90);
  lax->DrawLatex(0.030,0.445,"p_{T} (GeV/c)");

  lax->SetTextAngle(0);
  lax->SetTextSize(0.035);
  lax->DrawLatex(0.415,0.70, "TPC");
  lax->DrawLatex(0.415,0.85, "bTOF");
  lax->DrawLatex(0.600,0.85, "eTOF");

  cas->Print("acceptance_full.pdf");
}
