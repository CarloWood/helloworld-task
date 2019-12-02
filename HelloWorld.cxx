/**
 * helloworld-task -- A statefultask-based task for demonstration purposes.
 *
 * @file
 * @brief Definition of task HelloWorld.
 *
 * @Copyright (C) 2019  Carlo Wood.
 *
 * RSA-1024 0x624ACAD5 1997-01-26                    Sign & Encrypt
 * Fingerprint16 = 32 EC A7 B6 AC DB 65 A6  F6 F6 55 DD 1C DC FF 61
 *
 * This file is part of helloworld-task.
 *
 * Helloworld-task is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Helloworld-task is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with helloworld-task.  If not, see <http://www.gnu.org/licenses/>.
 */

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
