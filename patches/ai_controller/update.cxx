#include "prerequisites.hxx"
#include "il2cpp.hxx"
#include "system.hxx"
#include "update.hxx"

using namespace icsaoy;
using namespace icsaoy::patches::ai_controller;

const il2cpp_method_info_ptr update::method() const {
  return system::get()->get_image()->get_class("AIController")->get_method("Update");
}

bool update::prefix(il2cpp_object_ptr& self) const {
  try {
    auto obj_class = self->get_class();

    obj_class->get_field("damage")->set_value(self, 0xFF);
    obj_class->get_field("attackRate")->set_value(self, FLT_MAX);
    obj_class->get_field("pauseTime")->set_value(self, 0.f);
    obj_class->get_field("cooldown")->set_value(self, 0.f);
    obj_class->get_field("pauseTimer")->set_value(self, 0.f);
    obj_class->get_field("isDead")->set_value(self, false);
    obj_class->get_field("timeDead")->set_value(self, 0.f);

    return true;
  }
  catch (...)
  {
    icsaoy_rethrow();
  }
}