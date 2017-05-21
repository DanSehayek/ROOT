TCanvas* c2 = new TCanvas("c2","my 2D plot",500,500);
t -> Draw("x:y>>hxy(2000,0,1500,0,12000)","","colz");

// x axis = value of x
// y axis = value of y
// color = counts (frequency)
// x axis ranges from 0 to 1500
// y axis ranges from 0 to 12000

// To make a graphic cut:
//  1) At menu bar: "View" -> "Toolbar"
//  2) At toolbar select the scissors icon
//  3) Use mouse left click to draw a region
//  4) Use double click to finish the region
//  5) Select the outline and right click --> "SetName"
//  6) Give a name (example: mycut)

t -> Draw("x:y>>hxy(2000,0,1500,2000,0,12000)","mycut","colz");
t -> Draw("x:y>>hxy(2000,0,1500,2000,0,12000)","!mycut","colz");

// This graphs the cut
// The ! acts as a not operator and graphs the remaining region instead

c1.cd(1); t -> Draw("money","mycut","");
c1.cd(2); t -> Draw("money","","");

TFile g("cut.root","recreate");
mycut -> Write();

// Save the mycut to file so that it can be reused and modified

TCanvas* ctest = new TCanvas("ctest","Just for Test",500,500);
mycut -> Draw();
mycut -> Print();

// For refining the region: You can use Print() and then SetPoint()
// Example: mycut -> SetPoint(14,100,1000);

f -> Close();
