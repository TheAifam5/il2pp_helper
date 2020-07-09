#include "prerequisites.hxx"
#include "il2cpp.hxx"
#include "system.hxx"
#include "start.hxx"

using namespace icsaoy;
using namespace icsaoy::patches::ui::buildable_menu;

const il2cpp_method_info_ptr start::method() const {
  return system::get()->get_image()->get_class("UI_BuildableMenu")->get_method("Start");
}

void start::postfix(il2cpp_object_ptr& self) const {
  try {
    auto obj_class = self->get_class();
    auto field_info = obj_class->get_field("buildables");
    il2cpp_object_ptr buildables = field_info->get_value<il2cpp_object_ptr>(self);

    auto buildable_arr_class = buildables->get_class();
    
    UNREFERENCED_PARAMETER(obj_class);
    UNREFERENCED_PARAMETER(buildable_arr_class);
  }
  catch (...)
  {
    icsaoy_rethrow();
  }
}
