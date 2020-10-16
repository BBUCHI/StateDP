#include <iostream>
#include <typeinfo>
#include <array>
#include <vector>

class Context;

//Etat du module
class State {
 protected:
  Context *context_;

 public:
  virtual ~State() {
  }

  void set_context(Context *context) {
    this->context_ = context;
  }

  virtual void Handle() = 0;

  bool HasConverged(int x, int y, std::vector<std::array<int,2>> goal){
    return false;
  };

  virtual bool ClearanceTrans(State *state){return false;};

  virtual bool RunTrans(State *state){return false;};
};

//Context de la simulation
class Context {
 private:
  State *state_;

 public:
  Context(State *state) : state_(nullptr) {
    this->TransitionTo(state);
  }
  ~Context() {
    delete state_;
  }

  void TransitionTo(State *state) {
    if (this->state_ != nullptr)
      delete this->state_;
    this->state_ = state;
    this->state_->set_context(this);
  }

  void Request() {
    this->state_->Handle();
  }
};

//Etat "Not Set"
class StNotSet : public State {
 public:
  void Handle() override{};

    bool ClearanceTrans(State *state) override{
        return false;
    };
};

//Etat "Waiting"
class StWait : public State {
 public:
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