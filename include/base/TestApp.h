#ifndef TESTAPP_H
#define TESTAPP_H

#include "MooseApp.h"

class TestApp;

template<>
InputParameters validParams<TestApp>();

class TestApp : public MooseApp
{
public:
  TestApp(const std::string & name, InputParameters parameters);
  virtual ~TestApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* TESTAPP_H */
