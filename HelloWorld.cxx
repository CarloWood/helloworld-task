#include "sys.h"
#include "HelloWorld.h"

namespace task {

HelloWorld::HelloWorld() : CWDEBUG_ONLY(AIStatefulTask(true),) m_value(0)
{
  DoutEntering(dc::statefultask, "HelloWorld::HelloWorld()");
}

HelloWorld::~HelloWorld()
{
  DoutEntering(dc::statefultask, "HelloWorld::~HelloWorld()");
}

// Allow human readable states.
char const* HelloWorld::state_str_impl(state_type run_state) const
{
  switch(run_state)
  {
    // A complete listing of hello_world_state_type.
    AI_CASE_RETURN(HelloWorld_start);
    AI_CASE_RETURN(HelloWorld_print);
    AI_CASE_RETURN(HelloWorld_done);
  }
  ASSERT(false);
  return "UNKNOWN STATE";
};

void HelloWorld::initialize(int value)
{
  m_value = value;
}

void HelloWorld::multiplex_impl(state_type run_state)
{
  switch(run_state)
  {
    case HelloWorld_start:              // First state is the entry point.
      set_state(HelloWorld_print);      // Continue in state HelloWorld_print.
      yield();
      break;
    case HelloWorld_print:
      Dout(dc::notice, "Hello world!");
      set_state(HelloWorld_done);
      yield();
      break;
    case HelloWorld_done:
      finish();                         // and finish.
      break;
  }
}

} // namespace task
