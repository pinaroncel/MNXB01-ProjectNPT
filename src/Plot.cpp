
#include <iostream>
#include <string>
#include <vector>

#include "Record.h"

#include <TCanvas.h>
#include <TPad.h>
#include <TFrame.h>
#include <TStyle.h>
#include <TString.h>
#include <TF1.h>
#include <TH1.h>
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

using namespace std;

void make_graph(const vector<double>& years, const vector<double>& temps) {
    auto c = new TCanvas("c", "canvas for g");
    TGraph *g = new TGraph(years.size(), years, temps);
    g -> SetLineColor(4);
    g -> GetXaxis() -> SetTitle("Year");
    g -> GetYaxis() -> SetTitle("Temperature");
    gStyle->SetCanvasColor(0);
    gStyle->SetPadTopMargin(0.15); 
    gStyle->SetPadBottomMargin(0.15);
    gStyle->SetPadLeftMargin(0.10); 
    gStyle->SetPadRightMargin(0.10);
    gStyle->SetFrameFillColor(0);
    gStyle->SetPadGridX(true);     
    gStyle->SetPadGridY(true);
    gStyle->SetPadColor(0);
    g->Draw();
    c->SaveAs("/out/graph.png");
}

void make_graph_min_max(const vector<double>& years, const vector<double>& minTemps, const vector<double>& maxTemps, const vector<double>& diffTemps) {
    auto c = new TCanvas("c", "canvas for g");
    TGraph *gr_min = new TGraph (years.size(), years, minTemps);
    TGraph *gr_max = new TGraph (years.size(), years, maxTemps);
    TGraph *gr_diff = new TGraph (years.size(), years, diffTemps);
    gr_min -> SetTitle("The minimum and maximum temperature of the year");
    gr_min -> SetLineColor(4);
    gr_min -> GetXaxis() -> SetTitle("Year");
    gr_min -> GetYaxis() -> SetTitle("Temperature");
    gStyle->SetCanvasColor(0);
    gStyle->SetPadTopMargin(0.15); 
    gStyle->SetPadBottomMargin(0.15);
    gStyle->SetPadLeftMargin(0.10); 
    gStyle->SetPadRightMargin(0.10);
    gStyle->SetFrameFillColor(0);
    gStyle->SetPadGridX(true);     
    gStyle->SetPadGridY(true);
    gStyle->SetPadColor(0);
    gr_min->Draw();
    gr_max->Draw();
    gr_diff->Draw();
    c->SaveAs("/out/graph_min_max.png");
}
