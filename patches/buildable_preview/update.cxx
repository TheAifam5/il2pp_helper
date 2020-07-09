#include "prerequisites.hxx"
#include "il2cpp.hxx"
#include "system.hxx"
#include "update.hxx"

using namespace icsaoy;
using namespace icsaoy::patches::buildable_preview;

const il2cpp_method_info_ptr update::method() const {
  return system::get()->get_image()->get_class("BuildablePreview")->get_method("Update");
}

bool update::prefix(il2cpp_object_ptr& self) const {
  try {
    auto obj_class = self->get_class();

    obj_class->get_field("costToBuild")->set_value<short>(self, 0);
    obj_class->get_field("canBuild")->set_value(self, true);
    obj_class->get_field("buildTime")->set_value(self, 0.f);
    obj_class->get_field("buildTimer")->set_value(self, 0.f);

    return true;
  }
  catch (...)
  {
    icsaoy_rethrow();
  }
}