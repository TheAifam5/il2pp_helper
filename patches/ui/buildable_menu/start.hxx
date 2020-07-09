#pragma once

#include "ipatch.hxx"

namespace icsaoy::patches::ui::buildable_menu {
  class start : public abstractions::ipatch {
  public:
    const il2cpp_method_info_ptr method() const override;
    void postfix(il2cpp_object_ptr& self) const override;

    inline void* handler_builder() override
    {
      return reinterpret_cast<void*>(&handler_this<void, start>);
    }
  };
}