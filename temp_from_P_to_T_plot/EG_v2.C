
// .L EG_v2.C+           // compilation
// rootfuncgenerate()    // execution

#include <iostream>

#include <TCanvas.h>  // canvas class
#include <TPad.h>     // pad class
#include <TFrame.h>   // frame class
#include <TStyle.h>   // style class
#include <TF1.h>      // 1-dim function class
#include <TH1.h>      // 1-dim histogram class
#include <TMath.h>    // math class
#include <TString.h>  // string class

using namespace std;
using namespace TMath;

void rootfuncgenerate(Int_t n);

void rootfuncgenerate(Int_t n = 10000) {

    // ------------------------------------------------------------
    /* TCanvas
     * an area mapped to a window under the control of the display manager
     * subdivided into independent graphical areas called pads
     * has a default pad which has the name of the canvas itself
     * 
     * TPad
     * a linked list of primitives of any type of objects (TH1 TH2 TGraph...)
     * Draw() adds a new element into a pad
     * 
     * TFrame
     * a TWbox object for drawing histogram frames */
    auto    c    = new TCanvas("c", "canvas for f(x) = sin(x)");
    auto    h    = new TH1D("statistics box", "sin(x); x; y", 100, 0, Pi());
    TString sSin = "sin(x)";
    TString sFit = "[0]*sin(x)";
    auto    fSin = new TF1("fSin", sSin, 0, Pi());
    auto    fFit = new TF1("fFit", sFit, 0, Pi());
    // ------------------------------------------------------------
    // Histogram settings
    h->SetMinimum(0);
    h->SetTitle("histogram for f(x) = sin(x)");
    h->GetXaxis()->SetTitle("x");
    h->GetYaxis()->SetTitle("counts of sin(x)");
    h->GetXaxis()->CenterTitle(true);
    h->GetYaxis()->CenterTitle(true);
    // ------------------------------------------------------------
    // Fitting curve settings
    fFit->SetParameter(0, 10);
    fFit->SetLineColor(2);
    fFit->SetLineStyle(9);
    fFit->SetLineWidth(4);
    // ------------------------------------------------------------
    // Fills in the histogram with random f(x) values
    for (Int_t i = 0; i < n; i++) {
        h->Fill(fSin->GetRandom());
    }
    // ------------------------------------------------------------
    // Canvas settings
    gStyle->SetCanvasDefW(1280);      // width = 1280 px
    gStyle->SetCanvasDefH(720);       // height = 720 px
    gStyle->SetCanvasDefX(0);         // position x = 0 px
    gStyle->SetCanvasDefY(0);         // position y = 0 px
    gStyle->SetCanvasColor(42);       // 42 = light orange
    // ------------------------------------------------------------
    // Pad settings
    gStyle->SetPadTopMargin(0.15);    // fraction of the pad size
    gStyle->SetPadBottomMargin(0.15); // fraction of the pad size
    gStyle->SetPadLeftMargin(0.10);   // fraction of the pad size
    gStyle->SetPadRightMargin(0.20);  // fraction of the pad size
    gStyle->SetPadColor(0);           // 0 = white
    gStyle->SetPadGridX(true);        // show grid x
    gStyle->SetPadGridY(true);        // show grid y
    // ------------------------------------------------------------
    // Frame settings
    gStyle->SetFrameFillColor(20);    // 20 = light beige
    gStyle->SetFrameLineStyle(1);     // 1 = solid line
    gStyle->SetFrameLineWidth(2);
    // ------------------------------------------------------------
    // Grid settings
    gStyle->SetGridColor(13);        // 13 = gray
    gStyle->SetGridStyle(2);         // 2 = dotted line
    gStyle->SetGridWidth(1);
    // ------------------------------------------------------------
    // Histogram settings
    gStyle->SetHistLineColor(4);     // 4 = blue
    gStyle->SetHistLineStyle(1);     // 1 = solid line
    gStyle->SetHistLineWidth(2);
    gStyle->SetHistFillColor(38);    // 38 = light blue
    gStyle->SetHistFillStyle(3001);  // 3001 = mesh pattern
    // ------------------------------------------------------------
    // Statistics box settings
    gStyle->SetStatW(0.10);          // fraction of the pad size
    gStyle->SetStatH(0.70);          // fraction of the pad size
    gStyle->SetStatX(0.99);          // fraction of the pad size
    gStyle->SetStatY(0.85);          // fraction of the pad size
    gStyle->SetStatColor(29);        // 29 = light green
    gStyle->SetStatFontSize(0.044);
    gStyle->SetStatBorderSize(2);
    // ------------------------------------------------------------
    /* Prints info in the histogram statistics box
     * SetOptStat(ksiourmen)
     *      k = 1; kurtosis printed
     *      k = 2; kurtosis and kurtosis error printed
     *      s = 1; skewness printed
     *      s = 2; skewness and skewness error printed
     *      i = 1; integral of bins printed
     *      i = 2; integral of bins with option "width" printed
     *      o = 1; number of overflows printed
     *      u = 1; number of underflows printed
     *      r = 1; rms printed
     *      r = 2; rms and rms error printed
     *      m = 1; mean value printed
     *      m = 2; mean and mean error values printed
     *      e = 1; number of entries printed
     *      n = 1; name of histogram is printed */
    gStyle->SetOptStat(222002211);
    // ------------------------------------------------------------
    /* Prints fit info in the histogram statistics box
     * SetOptFill(pcev)
     *      p = 1; print probability
     *      c = 1; print chisquare / nbr of degrees of freedom
     *      e = 1; print errors
     *      v = 1; print name / values of parameters */
    gStyle->SetOptFit(1111);
    // ------------------------------------------------------------
    // Adds the fit function to the histogram object
    h->Fit(fFit);

    // Adds the histogram object to the pad / canvas
    h->Draw();

    // Saves the canvas
    c->SaveAs("histogram.jpg");
}
