#include <iostream>

#include "Strategy.h"

using namespace std; 

Strategy::Strategy() {}

Strategy::~Strategy() {}

void Strategy::AlgrithmInterface(vector<Option>, multimap<double, vector<string> >&) {}

StrategyA::StrategyA() {} 

StrategyA::~StrategyA() {}

void StrategyA::AlgrithmInterface(vector<Option> vec, multimap<double, vector<string> > &resultmap) {
  double payOff;
  vector<string> temp;

  double tempPrice = vec.at(0).getStrikePrice() + 20;

  if (tempPrice <= (vec.at(0)).getStrikePrice()) {
    payOff = -(vec.at(3)).getOptionPrice() - (vec.at(0)).getOptionPrice() + (vec.at(1)).getOptionPrice() + (vec.at(2)).getOptionPrice()
    + ((vec.at(0)).getStrikePrice() - tempPrice);
  } else if ((tempPrice > vec.at(0).getStrikePrice() && tempPrice < (vec.at(2)).getStrikePrice()) || tempPrice == (vec.at(2)).getStrikePrice()) {
    payOff = -(vec.at(3)).getOptionPrice() - (vec.at(0)).getOptionPrice() + (vec.at(1)).getOptionPrice() + (vec.at(2)).getOptionPrice()
    + ((vec.at(2)).getStrikePrice() - tempPrice) + (tempPrice - (vec.at(0)).getStrikePrice());
  } else {
    payOff = -(vec.at(3)).getOptionPrice() - (vec.at(0)).getOptionPrice() + (vec.at(1)).getOptionPrice()
    + (vec.at(2)).getOptionPrice() + ((tempPrice - (vec.at(2)).getStrikePrice()) - (tempPrice) - (vec.at(2)).getStrikePrice());
  }

  for ( unsigned int i = 0 ; i < vec.size(); i++ ) {
    temp.push_back(vec.at(i).getOptionSymbol());
  }
  LOGGER(DEBUG_FLAG, "The Payoff for this combination is: " << payOff);
  typedef pair<double, vector<string> > Pair;
  resultmap.insert(Pair(payOff,temp));
}

StrategyB::StrategyB() {}

StrategyB::~StrategyB() {}

void StrategyB::AlgrithmInterface(vector<Option> vec, multimap<double, vector<string> > &resultmap) {
  double payOff;
  vector<string> temp;
  double tempPrice = vec.at(0).getStrikePrice() + 20;

  if (tempPrice <= (vec.at(0)).getStrikePrice()) {
    payOff = (vec.at(3)).getOptionPrice() + (vec.at(0)).getOptionPrice() - (vec.at(1)).getOptionPrice()
    - (vec.at(2)).getOptionPrice() + ((vec.at(0)).getStrikePrice() - tempPrice)
    - ((vec.at(2)).getStrikePrice() - tempPrice);
  } else if (((vec.at(0)).getStrikePrice() < tempPrice) && (tempPrice <= (vec.at(2)).getStrikePrice())) {
    payOff = (vec.at(3)).getOptionPrice() + (vec.at(0)).getOptionPrice() - (vec.at(1)).getOptionPrice() - (vec.at(2)).getOptionPrice() - ((vec.at(2)).getStrikePrice() - tempPrice)
    - (tempPrice - (vec.at(0)).getStrikePrice());
  } else {
    payOff = (vec.at(3)).getOptionPrice() + (vec.at(0)).getOptionPrice() - (vec.at(0)).getOptionPrice()
    - (vec.at(2)).getOptionPrice() + (tempPrice - (vec.at(2)).getStrikePrice()) - (tempPrice - (vec.at(0)).getStrikePrice());
  }

  for (unsigned int i = 0; i < vec.size(); i++) {
    temp.push_back(vec.at(i).getOptionSymbol());
  }
  LOGGER(DEBUG_FLAG, "The Payoff for this combination is: " << payOff);
  typedef pair<double, vector<string> > Pair;
  resultmap.insert(Pair(payOff,temp));
}
 
Context::Context(Strategy* strategy) {
  this->strategy = strategy;
}

Context::~Context() {
}
 
void Context::DoAction(vector<Option> vec, multimap<double, vector<string> > &resultmap) {
  this->strategy->AlgrithmInterface(vec,resultmap);
}