// Example 1

TTree t("t","A Simple Tree");
// key = t
// title = A Simple Tree

// Suppose we have three brothers A B C
// Each time $100 will be distributed to them
// Let us use:
// moneyA for brother A
// moneyB for brother B
// moneyC for brother C

Int_t moneyA, moneyB, moneyC;

// We now link the 3 variables moneyA, moneyB, moneyC
// There are 3 branches and each branch has 1 leaf
// Use Branch method to set up a branch
// (Key for the branch, Address of variable, Leaf and its type)

// A branch "mA" linked to variable moneyA with one leaf
t.Branch("mA", &moneyA, "moneyA/I");
t.Branch("mB", &moneyB, "moneyB/I");
t.Branch("mC", &moneyC, "moneyC/I");

moneyA = 10;  moneyB = 30;  moneyC = 60;  t.Fill()
moneyA = 20;  moneyB = 30;  moneyC = 50;  t.Fill()
moneyA = 50;  moneyB = 35;  moneyC = 15;  t.Fill()

// Save to file
TFile f("example1.root","recreate");
t.Write();
f.Close();

// Example 2

void example2()
{

  TTree t("t","a Tree");

  // Suppose we have two brothers A and B
  // Brother A has 2 bank accounts
  // Brother B has 3 bank accounts

  Int_t A_account[2] = {0};
  Int_t B_account[3] = {0};

  // Create a branch to store the array

  t.Branch("A",A_account,"bank[2]/I");
  t.Branch("B",B_account,"bank[3]/I");

  A_account[0] = 10;
  A_account[1] = 110;

  B_account[0] = 9;
  B_account[1] = 99;
  B_account[2] = 999;
  t.Fill();

  A_account[0] = 20;
  A_account[1] = 120;

  B_account[0] = 7;
  B_account[1] = 77;
  B_account[2] = 777;
  t.Fill();

  // Save to file
  TFile f("example2.root","recreate");
  t.Write();
  f.Close();

}

// Example 3: Filling a tree with an array with variable size
void example3()
{

  TTree t("t","a Tree");

  // Declare an array and set up the size

  Int_t n_maxSize = 100;
  Int_t energy[n_maxSize] = {0};
  Int_t n;

  // Set up a branch to store "n" first
  // Then create a branch "Energy"
  // And a leaf to store the array
  // With its size linking to variable "n"

  t.Branch("Size", &n, "n/I");
  t.Branch("Energy", energy, "particle_energy[n]/I");

  n = 1;
  energy[0] = 9;
  t.Fill();

  n = 2;
  energy[0] = 11;
  energy[1] = 111;
  t.Fill();

  n = 3;
  energy[0] = 3;
  energy[1] = 33;
  energy[2] = 333;
  t.Fill();

  // Read the result by the following command:
  // t.Scan("n:particle_energy","","colsize = 20")

  // Save to file
  TFile f("example3.root","recreate");
  t.Write();
  f.Close();
  
}
