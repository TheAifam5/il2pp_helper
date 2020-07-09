#include "prerequisites.hxx"
#include "il2cpp.hxx"
#include "system.hxx"
#include "on_click_select_region.hxx"

using namespace icsaoy;
using namespace icsaoy::patches::ui::menu_region_select;

const il2cpp_method_info_ptr on_click_select_region::method() const {
  return system::get()->get_image()->get_class("UI_MenuRegionSelect")->get_method("OnClick_SelectRegion", 1);
}

bool on_click_select_region::prefix(il2cpp_object_ptr& self, const std::vector<il2cpp_object_ptr>& args, il2cpp_object_ptr&) const {
  try {
    auto obj_class = self->get_class();

    auto code = args.at(0);

    std::wcout << il2cpp_string((Il2CppString*)code->get_native()).begin() << std::endl;

    return true;
  }
  catch (...)
  {
    icsaoy_rethrow();
  }
}
