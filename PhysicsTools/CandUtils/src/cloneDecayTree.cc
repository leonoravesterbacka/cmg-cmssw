#include "PhysicsTools/CandUtils/interface/cloneDecayTree.h"
#include "DataFormats/Candidate/interface/CompositeCandidate.h"
using namespace std;
using namespace reco;

auto_ptr<Candidate> cloneDecayTree(const Candidate & c) {
  size_t n = c.numberOfDaughters();
  if (n == 1) return auto_ptr<Candidate>(c.clone());
  // pass a particle, not a candidate, to avoid cloning daughters 
  const Candidate &p = c;
  CompositeCandidate * cmp(new CompositeCandidate(p));
  auto_ptr<Candidate> cmpPtr(cmp);
  for(size_t i = 0; i < n; ++ i)
    cmp->addDaughter(cloneDecayTree(* c.daughter(i)));
  return cmpPtr;
}
