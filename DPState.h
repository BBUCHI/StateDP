#include <iostream>
#include <typeinfo>
#include <algorithm>
#include <array>
#include <vector>

class Context;

//Abstraction d'un état du module
class State {
 protected:
  Context *context_;

 public:
  State(){}
  virtual ~State() {
  }

  void set_context(Context *context) {
    this->context_ = context;
  }

  Context* get_context(){
    return context_;
  }

  virtual void Start(){};
};

//Etat du module dans son contexte
class Context {
 private:
  State *state_;

 public:
  Context();

  ~Context() {
    delete state_;
  }

  void set_state(State *state){
    state_ = state;
  }

  void Request() {
    this->state_->Start();
  }

};

//Etat "Waiting"
class StWait : public State {
 public:
  StWait(Context *context){
    set_context(context);
  }
  
  void Start() override{
    //get_context()->set_state(new StNotSet(get_context()));
    std::cout << "Starting (Waiting)\n";
  };
};

//Etat "Not Set"
class StNotSet : public State {
 public:
  StNotSet(Context *context){
    set_context(context);
  }
  
  void Start() override{
    get_context()->set_state(new StWait(get_context()));
    std::cout << "Starting (Not set)\n";
  };
};

/*
//Etat "Waiting"
class StWait : public State {
 public:
  StWait(Context *context){
    //set_context(context);
  }
  void Handle() override {};
};

//Etat "Goal"
class StGoal : public State {
 public:
  void Handle() override {};
};

//Etat "Blocked"
class StBlocked : public State {
 public:
  void Handle() override {};
};

//Etat "Ask to move"
class StAskToMove : public State {
 public:
  void Handle() override {};
};

*/

Context::Context(){
    state_ = new StNotSet(this);
  };