#include <iostream>
#include <typeinfo>
#include <array>
#include <vector>

class Context;

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
    std::cout << "Context: Transition to " << typeid(*state).name() << ".\n";
    if (this->state_ != nullptr)
      delete this->state_;
    this->state_ = state;
    this->state_->set_context(this);
  }

  void Request() {
    this->state_->Handle();
  }
};

class StNotSet : public State {
 public:
  void Handle() override{};

    bool ClearanceTrans(State *state) override{
        return false;
    };
};

class StWait : public State {
 public:
  void Handle() override {};
};

class StGoal : public State {
 public:
  void Handle() override {};
};

class StBlocked : public State {
 public:
  void Handle() override {};
};

class StAskToMove : public State {
 public:
  void Handle() override {};
};

int CodeTest() {
  Context *context = new Context(new StNotSet);
  std::cout << "Request : ...\n";
  context->Request();
  delete context;
  return 0;
}