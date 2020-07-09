#pragma once

#include "ipatch.hxx"

namespace icsaoy::patches::ui::room {
  class on_player_entered : public abstractions::ipatch {
  public:
    const il2cpp_method_info_ptr method() const override;
    bool prefix(il2cpp_object_ptr& self, const std::vector<il2cpp_object_ptr>& args, il2cpp_object_ptr&) const override;

    inline void* handler_builder() override
    {
      return reinterpret_cast<void*>(&handler_this<void, on_player_entered, Il2CppObject*>);
    }
  };
}