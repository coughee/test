#include "TestApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"

template<>
InputParameters validParams<TestApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  return params;
}

TestApp::TestApp(InputParameters parameters) :
    MooseApp(parameters)
{

  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  TestApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  TestApp::associateSyntax(_syntax, _action_factory);
}

TestApp::~TestApp()
{
}

extern "C" void TestApp__registerApps() { TestApp::registerApps(); }
void
TestApp::registerApps()
{
  registerApp(TestApp);
}

void
TestApp::registerObjects(Factory & factory)
{
}

void
TestApp::associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
}
