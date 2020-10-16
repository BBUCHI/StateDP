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
  virtual ~State() {
  }

  void set_context(Context *context) {
    this->context_ = context;
  }

  Context* get_context(){
    return context_;
  }

  virtual void Handle() = 0;
  virtual void Start();
};

//Etat du module dans son contexte
class Context {
 private:
  State *state_;

 public:
  Context(){
    state_ = new StNotSet(this);
  }
  ~Context() {
    delete state_;
  }

  void set_state(State *state){
    state_ = state;
  }

  void Handle() {
    this->state_->Handle();
  }
};

//Etat "Not Set"
class StNotSet : public State {
 public:
  StNotSet(Context *context)
  {
    set_context(context);
  }
  
  void Handle() override{std::cout<<"NOT SET\n";};
  void Start() override{
    get_context()->set_state(new StWait(get_context()));
  };
};

//Etat "Waiting"
class StWait : public State {
 public:
  StWait(Context *context){set_context(context);}
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

