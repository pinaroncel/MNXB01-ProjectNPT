
// Plot.cpp by Tilde

#include <iostream>
#include <string>
#include <vector>
#include <array>

#include "../include/Plot.h"
#include "../include/Record.h"

#include <TCanvas.h>
#include <TF1.h>
#include <TFrame.h>
#include <TGraph.h>
#include <TPad.h>
#include <TString.h>
#include <TStyle.h>

using namespace std;

// Saves a graph of all recorded temperatures on the given day
void make_graph_day(const vector<double>& years, const vector<double>& temps) {
    
    auto c    = new TCanvas("c", "canvas for g");
    TGraph *g = new TGraph(years.size(), &(years[0]), &(temps[0]));
    
    g -> SetTitle("Temperature on Christmas day");
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

    c->SaveAs("../out/graph_christmas.png");
}

// Saves a graph of averages temperatures for every year
void make_graph_ave(const vector<double>& years, const vector<double>& aveTemps) {
    
    auto c    = new TCanvas("c", "canvas for g");
    TGraph *g = new TGraph(years.size(), &(years[0]), &(aveTemps[0]));
    
    g -> SetLineColor(4);
    g -> SetTitle() -> ("Average temperature per year");
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

    c->SaveAs("../out/graph_aveTemps.png");
}

// Saves a graph of the hottest, the coldest, and the difference between the two for every year
void make_graph_min_max_diff(const vector<double>& years, const vector<double>& minTemps, const vector<double>& maxTemps, const vector<double>& diffTemps) {
    
    auto c         = new TCanvas("c", "canvas for g");
    TGraph *g_min  = new TGraph(years.size(), &(years[0]), &(minTemps[0]));
    TGraph *g_max  = new TGraph(years.size(), &(years[0]), &(maxTemps[0]));
    TGraph *g_diff = new TGraph(years.size(), &(years[0]), &(diffTemps[0]));
    
    g_min -> SetTitle("Minimum temperature per year");
    g_max -> SetTitle("Maximum temperature per year");
    g_diff -> SetTitle("Difference btw the hottest and coldest days per year");
    
    g_min -> SetLineColor(4);
    g_max -> SetLineColor(2);
    g_diff -> SetLineColor(7);
    
    g_min -> GetXaxis() -> SetTitle("Year");
    g_min -> GetYaxis() -> SetTitle("Temperature");

    gStyle->SetCanvasColor(0);
    gStyle->SetPadTopMargin(0.15); 
    gStyle->SetPadBottomMargin(0.15);
    gStyle->SetPadLeftMargin(0.10); 
    gStyle->SetPadRightMargin(0.10);
    gStyle->SetFrameFillColor(0);
    gStyle->SetPadGridX(true);     
    gStyle->SetPadGridY(true);
    gStyle->SetPadColor(0);

    g_min->Draw();
    g_max->Draw();
    g_diff->Draw();

    c->SaveAs("../out/graph_min_max_diff.png");
}
