#include <stdlib.h>
#include <stdio.h>
#include "TF1.h"
#include "TH1D.h"
#include "TRandom.h"

const int len = 10000;
double pts[len];

int main() {
  auto h1 = new TH1D("h1", "h1", 128, -5, 5);
  for (int i=0; i<len; ++i) {
	pts[i] = gRandom->Gaus(0,1);
	h1->Fill(pts[i]);
  }
  
  /* Serial fit */
  auto f1 = new TF1("f1", "gaus");

  /* Vectorized fit */
  //auto f1 = new TF1("f1", "gaus", -5, 5, "VEC");
  f1->SetNpx(sizeof(pts)+10);
  h1->Fit(f1);
  std::cout << "It worked!" << std::endl;
  return 0;
}
