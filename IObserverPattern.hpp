#ifndef __INTERFACE_OBSERVER_PATTERN_HEADER__
#define __INTERFACE_OBSERVER_PATTERN_HEADER__

class Observer {
public:
  virtual ~Observer(){};
  virtual void update(void* elemento) = 0;
};

class Subject {
public:
  virtual ~Subject(){};
  virtual void attach(Observer *observer) = 0;
  virtual void detach(Observer *observer) = 0;
  virtual void notify(void* elemento) = 0;
};

#endif