#pragma once

#include "ipatch.hxx"

namespace icsaoy::patches::attacker_placement_logic {
  class can_place_unit_at_location : public abstractions::ipatch {
  public:
    const il2cpp_method_info_ptr method() const override;
    bool prefix(il2cpp_object_ptr& self, il2cpp_object_ptr& result) const override;

    inline void* handler_builder() override
    {
      return reinterpret_cast<void*>(&handler_this<Il2CppObject*, can_place_unit_at_location>);
    }
  };
}