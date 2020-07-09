#include "prerequisites.hxx"
#include "il2cpp.hxx"
#include "system.hxx"
#include "ctor.hxx"

using namespace icsaoy;
using namespace icsaoy::patches::buildable;

const il2cpp_method_info_ptr ctor::method() const {
  return system::get()->get_image()->get_class("Buildable")->get_method(".ctor");
}

void ctor::postfix(il2cpp_object_ptr& self) const {
  try {
    auto& klass = self->get_class();

    klass->get_field("cost")->set_value<short>(self, 0);
    klass->get_field("buildTime")->set_value(self, 0.f);
  }
  catch (...)
  {
    icsaoy_rethrow();
  }
}