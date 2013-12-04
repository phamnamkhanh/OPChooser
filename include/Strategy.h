#ifndef _STRATEGY_H_
#define _STRATEGY_H_
#include <vector>
#include <map>
#include <string>

#include "Option.h"
#include "Logger.h"

using namespace std;

class Strategy {

public:
  ~Strategy();
  virtual void AlgrithmInterface(vector<Option>, multimap<double, vector<Option> >&);
  Strategy();

};

class StrategyA : public Strategy {

public:
  StrategyA();
  ~StrategyA();
  void AlgrithmInterface(vector<Option>, multimap<double, vector<Option> >&);

};

class StrategyB : public Strategy {

public:
  StrategyB();
  ~StrategyB();
  void AlgrithmInterface(vector<Option>,multimap<double, vector<Option> >&);

};



class Context {

public:
  Context(Strategy*);
  ~Context();
  void DoAction(vector<Option>, multimap<double,vector<Option> >&);
private:
  Strategy* strategy;

};

#endif