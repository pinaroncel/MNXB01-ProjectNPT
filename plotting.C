#include "TFile.h"
#include "TTree.h"
#include "TH1.h"
#include "TCanvas.h"
#include "TPad.h"
#include "TClonesArray.h"
#include "TParticle.h"
#include "TStyle.h"
#include "TH2.h"
#include "TGraph.h"

void plotting() {

// Example lists (will be filled with data)
Double_t temp_certain_day[20] = {1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10};
Double_t years1[20] = {1982,1984,1986,1988,1990,1992,1994,1996,1998,2000,2002,2004,2006,2008,2010,2012,2014,2016,2018,2022};
Double_t mean_temp_of_year[20] = {1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10};
Double_t years2[20] = {1982,1984,1986,1988,1990,1992,1994,1996,1998,2000,2002,2004,2006,2008,2010,2012,2014,2016,2018,2022};
Double_t mean_temp_of_season[20] = {1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10};
Double_t years3[20] = {1982,1984,1986,1988,1990,1992,1994,1996,1998,2000,2002,2004,2006,2008,2010,2012,2014,2016,2018,2022};
 
  


   
// Min and max

TGraph make_graph_1(std::vector<int> years, std::vector<double> temps)
{
gStyle->SetCanvasColor(0);
gStyle->SetPadTopMargin(0.15); 
gStyle->SetPadBottomMargin(0.15);
gStyle->SetPadLeftMargin(0.10); 
gStyle->SetPadRightMargin(0.10);
gStyle->SetFrameFillColor(0);
gStyle->SetPadGridX(true);     
gStyle->SetPadGridY(true);
gStyle->SetPadColor(0);

TGraph *gr1 = new TGraph (years.size(), years, temps);
gr1 -> SetTitle("The minimum and maximum temperature of the year");
gr1 -> SetLineColor(4);
gr1 -> GetXaxis() -> SetTitle("Year");
gr1 -> GetYaxis() -> SetTitle("Temperature");
return gr1;
}








// General function
TGraph make_graph_3(std::vector<int> years, std::vector<double> temps, std::string title)
{
gStyle->SetCanvasColor(0);
gStyle->SetPadTopMargin(0.15); 
gStyle->SetPadBottomMargin(0.15);
gStyle->SetPadLeftMargin(0.10); 
gStyle->SetPadRightMargin(0.10);
gStyle->SetFrameFillColor(0);
gStyle->SetPadGridX(true);     
gStyle->SetPadGridY(true);
gStyle->SetPadColor(0);

TGraph *gr3 = new TGraph (years.size(), years, temps);
TCanvas *c3 = new TCanvas();
gr3 -> SetLineColor(4);
gr3 -> GetXaxis() -> SetTitle("Year");
gr3 -> GetYaxis() -> SetTitle("Temperature");
gr3 -> SetTitle(title);
return gr3;
}


}
