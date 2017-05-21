TFile* f = new TFile("simple.root");
TTree* t;
f -> GetObject("t",t);

TCanvas* c1 = new TCanvas("c1","my histo",500,800);
c1 -> Divide(1,2);

// Set a Canvas with the title "My histo"
// width =  500 px
// height = 800 px
// Divide into sub_Pad (1 col x 2 row)

c1 -> cd(1);  t -> Draw("money");
c1 -> cd(2);  t -> Draw("money", "money < 2000");

// Whole data and partial data from the selection
// First parameter represents the variable that you want to draw
// Second parameter sets boundaries on values shown on x axis
// x axis: money value
// y axis: counts (frequency)

c1 -> cd(1);  t -> Draw("Log10(money)");
c1 -> cd(2);  t -> Draw("sqrt(money)");

c1 -> cd(1);  t -> Draw("money", "money > 1000 && money < 2000");
c1 -> cd(2);  t -> Draw("money", "money < 1000 || money > 2000");

// Can also write the last line as:
TCut cut1 = "money < 1000";
TCut cut2 = "money > 2000";
c1 -> cd(1);  t -> Draw("money");
c1 -> cd(2);  t -> Draw("money", cut1 || cut2);

t -> Draw("money>>h1(2000,0,4000)","","goff");
t -> Draw("money>>h2(2000,0,4000)",cut1 || cut2,"goff");
c1 -> cd(1);  h1 -> Draw();
c1 -> cd(2);  h2 -> Draw();

// Redirect to a histrogram
// num of bin = 2000
// x axis is from 0 to 4000
