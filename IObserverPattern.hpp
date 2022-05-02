#ifndef __INTERFACE_OBSERVER_PATTERN_HEADER__
#define __INTERFACE_OBSERVER_PATTERN_HEADER__

class Observer {
public:
  virtual ~Observer(){};
  virtual void update(void* pElement) = 0;
};

class Subject {
private:
  Observer *observer;
public:
  virtual ~Subject(){};
  virtual void attach(Observer *observer) = 0;
  virtual void detach(Observer *observer) = 0;
  virtual void notify(void* pElement) = 0;
};

#endif