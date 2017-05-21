// Create a pointer that can reference to TFile class

// TFile* f
// f = new TFile("test.root")
// f -> Close()

// Create instance from TFile class

// TFile f("test.root","recreate");    // To Overwrite
// TFile f("test.root",);              // To Read
// TFile f("demo.root","update");      // To Append
// f.Close()

// f.ls()                              // To list what is inside this TFile object

// Example 1: Save objects to root file

TFile* f = new TFile("test.root","recreate");
f -> ls();

// We will now create histrograms
// TH1 references the histrogram object
// T refers to the class
// H refers to histrogram
// 1 refers to 1D
// F refers to the Float data type

TH1F h0("h0","histro0",100,-10,10);
TH1F h1("h1","histro1",100,-10,10);

// h0 is the key
// histro0 is the title
// 100 refers to 100 bins
// -10 is the lower limit on x
// 10 is the upper limit on x

h0.FillRandom("gaus",100);
h1.FillRandom("gaus",100);

// FillRandom draws the histrogram
// gaus refers to Gaussian Distribution
// 100 refers to the number of entries

h0.Write();
h1.Write();
f -> ls();

// You can now see two new histrograms in the test.root file
// We now update h0

h0.FillRandom("gaus",200)
h0.Draw()
h0.Write()
f -> ls()
