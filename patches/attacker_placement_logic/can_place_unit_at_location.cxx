#include "prerequisites.hxx"
#include "il2cpp.hxx"
#include "system.hxx"
#include "can_place_unit_at_location.hxx"

using namespace icsaoy;
using namespace icsaoy::patches::attacker_placement_logic;

const il2cpp_method_info_ptr can_place_unit_at_location::method() const {
  return system::get()->get_image()->get_class("AttackerPlacementLogic")->get_method("CanPlaceUnitAtLocation");
}

bool can_place_unit_at_location::prefix(il2cpp_object_ptr& self, il2cpp_object_ptr& result) const {
  try {
    auto obj_class = self->get_class();

    // result.reset();
    UNREFERENCED_PARAMETER(self);
    UNREFERENCED_PARAMETER(obj_class);
    UNREFERENCED_PARAMETER(result);

    return false;
  }
  catch (...)
  {
    icsaoy_rethrow();
  }
}