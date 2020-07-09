#pragma once

namespace icsaoy::abstractions {
  class isystem : public non_assignable {
  public:
    virtual void initialize() = 0;
    virtual void finalize() = 0;
    virtual void tick() = 0;
  };
}