#pragma once

namespace icsaoy {
  class non_assignable {
  public:
    non_assignable(non_assignable const&) = delete;
    non_assignable& operator=(non_assignable const&) = delete;
    non_assignable() {}
  };
}