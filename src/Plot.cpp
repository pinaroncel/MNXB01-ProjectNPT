
// Plot.cpp by Tilde

#include <iostream>
#include <string>
#include <vector>
#include <array>

#include "../include/Plot.h"
#include "../include/Record.h"

#include <TAxis.h>
#include <TCanvas.h>
#include <TF1.h>
#include <TFrame.h>
#include <TGraph.h>
#include <TLegend.h>
#include <TMultiGraph.h>
#include <TPad.h>
#include <TString.h>
#include <TStyle.h>

using namespace std;

// -----------------------------------------------------------------------------
// Saves a graph of all recorded temperatures on the given day
void make_graph_day(const vector<double>& years, const vector<double>& temps) {
    
    auto c_xmas = new TCanvas("c", "canvas for g");
    TGraph *g = new TGraph(years.size(), &(years[0]), &(temps[0]));
    
    g->SetTitle("Temperature on Christmas day");
    g->SetLineColor(4);

    g->GetXaxis()->SetTitle("Year");
    g->GetYaxis()->SetTitle("Temperature");
    g->GetXaxis()->CenterTitle(true);
    g->GetYaxis()->CenterTitle(true);

    gStyle->SetCanvasColor(0);
    gStyle->SetPadTopMargin(0.15); 
    gStyle->SetPadBottomMargin(0.15);
    gStyle->SetPadLeftMargin(0.10); 
    gStyle->SetPadRightMargin(0.10);
    gStyle->SetFrameFillColor(0);
    gStyle->SetPadGridX(true);     
    gStyle->SetPadGridY(true);
    gStyle->SetPadColor(0);
    gStyle->SetCanvasDefW(1280);
    gStyle->SetCanvasDefH(720);

    g->Draw();

    c_xmas->SaveAs("out/graph_christmas.png");

    cout << "graph_christmas done" << endl;
}

// -----------------------------------------------------------------------------
// Saves a graph of averages temperatures for every year
void make_graph_ave(const vector<double>& years, const vector<double>& aveTemps) {
    
    auto c_ave = new TCanvas("c", "canvas for g");
    TGraph *g = new TGraph(years.size(), &(years[0]), &(aveTemps[0]));
    
    g->SetLineColor(4);
    g->SetTitle("Average temperature per year");
    g->GetXaxis()->SetTitle("Year");
    g->GetYaxis()->SetTitle("Temperature");
    g->GetXaxis()->CenterTitle(true);
    g->GetYaxis()->CenterTitle(true);


    gStyle->SetCanvasColor(0);
    gStyle->SetPadTopMargin(0.15); 
    gStyle->SetPadBottomMargin(0.15);
    gStyle->SetPadLeftMargin(0.10); 
    gStyle->SetPadRightMargin(0.10);
    gStyle->SetFrameFillColor(0);
    gStyle->SetPadGridX(true);     
    gStyle->SetPadGridY(true);
    gStyle->SetPadColor(0);
    gStyle->SetCanvasDefW(1280);
    gStyle->SetCanvasDefH(720);

    g->Draw();

    c_ave->SaveAs("out/graph_aveTemps.png");

    cout << "graph_aveTemps done" << endl;
}

// -----------------------------------------------------------------------------
// Saves a graph of the hottest, the coldest, and the difference between the two for every year
void make_graph_min_max_diff(const vector<double>& years, const vector<double>& minTemps, const vector<double>& maxTemps, const vector<double>& diffTemps) {
    
    auto c_min_max_diff = new TCanvas("c", "canvas for g");
    TGraph *g_min  = new TGraph(years.size(), &(years[0]), &(minTemps[0]));
    TGraph *g_max  = new TGraph(years.size(), &(years[0]), &(maxTemps[0]));
    TGraph *g_diff = new TGraph(years.size(), &(years[0]), &(diffTemps[0]));
    
    g_min->SetName("g_min");
    g_max->SetName("g_max");
    g_diff->SetName("g_diff");

    g_min->SetTitle("Minimum temperature per year");
    g_max->SetTitle("Maximum temperature per year");
    g_diff->SetTitle("Difference btw the hottest and coldest days per year");
    
    g_min->SetLineColor(4);
    g_max->SetLineColor(2);
    g_diff->SetLineColor(7);
    
    gStyle->SetCanvasColor(0);
    gStyle->SetPadTopMargin(0.15); 
    gStyle->SetPadBottomMargin(0.15);
    gStyle->SetPadLeftMargin(0.10); 
    gStyle->SetPadRightMargin(0.10);
    gStyle->SetFrameFillColor(0);
    gStyle->SetPadGridX(true);     
    gStyle->SetPadGridY(true);
    gStyle->SetPadColor(0);
    gStyle->SetCanvasDefW(1280);
    gStyle->SetCanvasDefH(720);

    TMultiGraph *mg = new TMultiGraph();

    mg->Add(g_min);
    mg->Add(g_max);
    mg->Add(g_diff);

    mg->GetXaxis()->SetTitle("Year");
    mg->GetYaxis()->SetTitle("Temperature");
    mg->GetXaxis()->CenterTitle(true);
    mg->GetYaxis()->CenterTitle(true);

    mg->Draw("APC");

    auto legend = new TLegend(0.8, 0.8, 0.99, 0.99);
    legend->SetHeader("Graph explanation","C");
    legend->AddEntry("g_min","Minimum temperature per year","L");
    legend->AddEntry("g_max","Maximum temperature per year","L");
    legend->AddEntry("g_diff","Difference btw the hottest and coldest days per year","L");
    legend->SetTextSize(0.025);
    legend->Draw();

    c_min_max_diff->SaveAs("out/graph_min_max_diff.png");

    cout << "graph_min_max_diff done" << endl;
}
