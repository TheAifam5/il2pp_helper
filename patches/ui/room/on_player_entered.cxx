#include "prerequisites.hxx"
#include "il2cpp.hxx"
#include "system.hxx"
#include "on_player_entered.hxx"

using namespace icsaoy;
using namespace icsaoy::patches::ui::room;

const il2cpp_method_info_ptr on_player_entered::method() const {
  return system::get()->get_image()->get_class("UI_RoomUI")->get_method("OnPlayerEnteredRoom", 1);
}

bool on_player_entered::prefix(il2cpp_object_ptr& self, const std::vector<il2cpp_object_ptr>& args, il2cpp_object_ptr&) const {
  try {
    auto obj_class = self->get_class();

    auto player = args.at(0);
    auto player_class = player->get_class();

    UNREFERENCED_PARAMETER(obj_class);

    return true;
  }
  catch (...)
  {
    icsaoy_rethrow();
  }
}
