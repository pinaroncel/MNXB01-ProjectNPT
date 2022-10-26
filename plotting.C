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
 
gStyle->SetCanvasColor(0);
gStyle->SetPadTopMargin(0.15);    // fraction of the pad size
gStyle->SetPadBottomMargin(0.15); // fraction of the pad size
gStyle->SetPadLeftMargin(0.10);   // fraction of the pad size
gStyle->SetPadRightMargin(0.10);
gStyle->SetFrameFillColor(0);
gStyle->SetPadGridX(true);     
gStyle->SetPadGridY(true);    


   
// 1 day of the year every year
TGraph *gr1 = new TGraph (20, years1, temp_certain_day);
TCanvas *c1 = new TCanvas();
gStyle->SetPadColor(0);
gr1 -> SetTitle("Temperature on the --- different years");
gr1 -> SetLineColor(4);
gr1 -> GetXaxis() -> SetTitle("Year");
gr1 -> GetYaxis() -> SetTitle("Temperature");
gr1 ->Draw();


// Mean temperature of year
TGraph *gr2 = new TGraph (20, years2, mean_temp_of_year);
TCanvas *c2 = new TCanvas();
gr2 -> SetLineColor(4);
gr2 -> GetXaxis() -> SetTitle("Year");
gr2 -> GetYaxis() -> SetTitle("Temperature");
gr2 -> SetTitle("The mean temperature during the year");
gr2 ->Draw();


// One season per year
TGraph *gr3 = new TGraph (20, years3, mean_temp_of_season);
TCanvas *c3 = new TCanvas();
gr3 -> SetLineColor(4);
gr3 -> GetXaxis() -> SetTitle("Year");
gr3 -> GetYaxis() -> SetTitle("Temperature");
gr3 -> SetTitle("Mean temperature during --- each year");
gr3 ->Draw();

}
