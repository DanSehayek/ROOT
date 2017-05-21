// TFile:: mkdir("char")    // To make directory
// TFile:: cd()             // To change directory
// TFile:: delete()         // To delete element or directory
// TFile:: ls("-m")         // To see objects in memory
// gDirectory -> pwd()      // To show current path

// Example: Make a directory

TFile* f1 = new TFile("test1.root","recreate");
TFile* f2 = new TFile("test2.root","recreate");
gDirectory -> pwd()
f1 -> cd()
f1 -> ls()
f1 -> mkdir("new_dir")
f1 -> ls()
f1 -> cd("new_dir")
TH1F h0("h0","histro0",100,-10,10);
h0.FillRandom("gaus",100);
h0.Write();
f1 -> ls()
