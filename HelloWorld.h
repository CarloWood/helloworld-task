/**
 * helloworld-task -- A statefultask-based task for demonstration purposes.
 *
 * @file
 * @brief Declaration of task HelloWorld.
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

#include "statefultask/AIStatefulTask.h"

namespace task {

class HelloWorld : public AIStatefulTask
{
 private:
  int m_value;

 protected:
  typedef AIStatefulTask direct_base_type;              // The base class of this task.

  // The different states of the task.
  enum hello_world_state_type {
    HelloWorld_start = direct_base_type::state_end,     // Mandatory first value.
    HelloWorld_print,
    HelloWorld_done,
  };

 public:
  static state_type constexpr state_end = HelloWorld_done + 1;        // Must be one passed the last state.
  HelloWorld();

  void initialize(int value);

 protected: // The destructor must be protected.
  // Override virtual functions of the base class.
  ~HelloWorld() override;
  char const* task_name_impl() const override { return "HelloWorld"; }
  char const* state_str_impl(state_type run_state) const override;
  void multiplex_impl(state_type run_state) override;
};

} // namespace task
