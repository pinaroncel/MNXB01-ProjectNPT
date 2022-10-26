
// project.cpp
// ----------------------------------------------------------------
// ----------------------------------------------------------------
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
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


#include "Record.h"
using namespace std;
// ----------------------------------------------------------------
// ----------------------------------------------------------------
// move this function later...
vector<Record> readFromFile(string filename) {
    vector<Record> records;
    ifstream input(filename);
    string line;
    while(getline(input, line)) {
        int    year      = stoi(line.substr(0, 4));
        int    month     = stoi(line.substr(5, 3));
        int    day       = stoi(line.substr(8, 3));
        double temp      = stod(line.substr(11, 6));
        double tempUrban = stod(line.substr(17, 6));
        int    dataId    = stoi(line.substr(23, 2));
        Record record = Record(year, month, day, temp, tempUrban, dataId);
        records.push_back(record);
    }
    return records;
}
// move this function later...
vector<double> tempOnDay(const vector<Record>& records, int month, int day) {
    vector<double> temps;
    for (auto record : records) {
        if (record.month() == month && record.day() == day) {
            temps.push_back(record.temp());
        }
    }
    return temps;
}

// move this function later...
int nbrDaysPerMonth(int month) {
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {return 31;}
    if (month == 4 || month == 6 || month == 9 || month == 11) {return 30;}
    else {return 28;}
}

// move this function later...
vector<vector<double>> tempPerDay(const vector<Record>& records) {
    vector<vector<double>> tempss;
    for (int m = 1; m < 13; m++) {
        int nbrDays = nbrDaysPerMonth(m);
        for (int d = 1; d < nbrDays+1; d++) {
            vector<double> temps = tempOnDay(records, m, d);
            tempss.push_back(temps);
        }
    }
    return tempss;
}

// move this function later...
vector<int> getAllYears(const vector<Record>& records) {
    vector<int> years;
    int initialYear = records.front().year();
    int finalYear   = records.back().year();
    for (int y = initialYear; y < finalYear+1; y++) {
        years.push_back(y);
    }
    return years;
}

// move this function later...
vector<double> aveTempsPerYear(const vector<Record>& records) {
    vector<double> means;
    int initialYear = records.front().year();
    int finalYear   = records.back().year();
    for (int y = initialYear; y < finalYear+1; y++) {
        double sum = 0;
        int nbrDays = 0;
        for (auto record : records) {
            if (y == record.year()) {
                sum += record.temp();
                nbrDays++;
            }
        }
        double mean = sum / nbrDays;       
        means.push_back(mean);
    }
    return means;
}

// move this function later...
vector<double> minTempsPerYear(const vector<Record>& records) {
    vector<double> mins;
    int initialYear = records.front().year();
    int finalYear   = records.back().year();
    for (int y = initialYear; y < finalYear+1; y++) {
        double min = 0;
        for (auto record : records) {
            if (y == record.year()) {
                if (record.temp() < min) {
                    min = record.temp();
                }
            }
        }
        mins.push_back(min);
    }
    return mins;
}

// move this function later...
vector<double> maxTempsPerYear(const vector<Record>& records) {
    vector<double> maxs;
    int initialYear = records.front().year();
    int finalYear   = records.back().year();
    for (int y = initialYear; y < finalYear+1; y++) {
        double max = 0;
        for (auto record : records) {
            if (y == record.year()) {
                if (record.temp() > max) {
                    max = record.temp();
                }
            }
        }
        maxs.push_back(max);
    }
    return maxs;
}

// move this function later...
vector<double> diffTempsPerYear(const vector<Record>& records) {
    vector<double> diffs;
    int initialYear = records.front().year();
    int finalYear   = records.back().year();
    for (int y = initialYear; y < finalYear+1; y++) {
        double min = 0;
        double max = 0;
        for (auto record : records) {
            if (y == record.year()) {
                if (record.temp() < min) {
                    min = record.temp();
                }
                if (record.temp() > max) {
                    max = record.temp();
                }
            }
        }
        double diff = max - min;
        diffs.push_back(diff);
    }
    return diffs;
}

// General function
void make_graph(const vector<Double_t>& years, const vector<Double_t>& temps) {
    auto c = new TCanvas("c", "canvas for g");
    TGraph *g = new TGraph(years.size(), years, temps);
    g -> SetLineColor(4);
    g -> GetXaxis() -> SetTitle("Year");
    g -> GetYaxis() -> SetTitle("Temperature");
    // g -> SetTitle(title);
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
    // TString filename = "/out/" + title + ".png";
    c->SaveAs("/out/graph.png");
}

// Makes min and max graph
void make_graph_min_max(const vector<Double_t>& years, const vector<Double_t>& minTemps, const vector<Double_t>& maxTemps, const vector<Double_t>& diffTemps) {
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



// ----------------------------------------------------------------
// ----------------------------------------------------------------
int main() {

	string filename = "in/uppsala_tm_1722-2020.dat";

    vector<Record> records   = readFromFile(filename);
    vector<Double_t> temps     = ( vector<Double_t> )tempOnDay(records, 8, 23);
    vector<Double_t> years     = ( vector<Double_t> )getAllYears(records);
    vector<Double_t> aveTemps  = ( vector<Double_t> )aveTempsPerYear(records);
    vector<Double_t> minTemps  = ( vector<Double_t> )minTempsPerYear(records);
    vector<Double_t> maxTemps  = ( vector<Double_t> )maxTempsPerYear(records);
    vector<Double_t> diffTemps = ( vector<Double_t> )diffTempsPerYear(records);
    vector<vector<Double_t>> tempss = ( vector<vector<Double_t>> )tempPerDay(records);

    // TString title1 = "temp on a given day";
    make_graph(years, temps);

    // TString title2 = "ave temp on every day";
    make_graph(years, aveTemps);

    make_graph_min_max(years, minTemps, maxTemps, diffTemps);

    cout << endl;
    cout << "nbr of records : " << records.size() << endl;
    cout << endl;

    cout << "temps on a single day : " << endl;
    for (auto temp : temps) {cout << temp << ", "; };
    cout << endl; cout << endl;
    cout << "nbr of days in temps : " << temps.size() << endl;
    cout << endl;

    cout << "years : " << endl;
    for (auto year : years) {cout << year << ", "; };
    cout << endl; cout << endl;

    cout << "ave temps : " << endl;
    for (auto aveTemp : aveTemps) {cout << aveTemp << ", "; };
    cout << endl; cout << endl;

    cout << "min temps : " << endl;
    for (auto minTemp : minTemps) {cout << minTemp << ", "; };
    cout << endl; cout << endl;

    cout << "max temps : " << endl;
    for (auto maxTemp : maxTemps) {cout << maxTemp << ", "; };
    cout << endl; cout << endl;

    cout << "diff temps : " << endl;
    for (auto diffTemp : diffTemps) {cout << diffTemp << ", "; };
    cout << endl; cout << endl;

    cout << "nbr of days in tempss : " << tempss.size() << endl;
    cout << "nbr of temps in a day : " << tempss.back().size() << endl;

    return 0;

	// Store the path to data file here
    // const string pathToFile = "/in/uppsala_tm_1722-2020.dat";

	// Instantiate analysis object
    // tempTrender t(pathToFile);

	//t.tempOnDay(8, 23);
	//t.tempOnDay(235);
	//t.tempPerDay();
	//t.hotCold();
	//t.tempPerYear(2050);
}
// ----------------------------------------------------------------
// ----------------------------------------------------------------
