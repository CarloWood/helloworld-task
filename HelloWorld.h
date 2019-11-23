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
  char const* state_str_impl(state_type run_state) const override;
  void multiplex_impl(state_type run_state) override;
};

} // namespace task
