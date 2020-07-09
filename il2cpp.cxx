#include "prerequisites.hxx"
#include "il2cpp.hxx"

using namespace icsaoy;

namespace icsaoy::utils {
  namespace recursive {
    ICSAOY_INLINE const PropertyInfo* il2cpp_class_get_properties(Il2CppClass* const klass, void** const iter) {
      try {
        icsaoy_assert(klass);
        icsaoy_assert(iter);

        return il2cpp_class_iterate<const PropertyInfo>(klass, iter, ::il2cpp_class_get_properties);
      }
      catch (...) {
        icsaoy_rethrow();
      }
    }

    ICSAOY_INLINE const PropertyInfo* il2cpp_class_get_property_from_name(Il2CppClass* const klass, const char* const name) {
      try {
        icsaoy_assert(klass);
        icsaoy_assert(name);
        icsaoy_assert(name[0] != NULL);

        const PropertyInfo* result = nullptr;
        void* iter = nullptr;

        do {
          result = il2cpp_class_iterate<const PropertyInfo>(
            klass,
            &iter,
            recursive::il2cpp_class_get_properties);
        } while (result && strcmp(result->name, name) != 0);

        icsaoy_assert(result);

        return result;
      }
      catch (...) {
        icsaoy_rethrow();
      }
    }

    ICSAOY_INLINE const FieldInfo* il2cpp_class_get_fields(Il2CppClass* const klass, void** const iter) {
      try {
        icsaoy_assert(klass);
        icsaoy_assert(iter);

        return il2cpp_class_iterate<FieldInfo>(klass, iter, ::il2cpp_class_get_fields);
      }
      catch (...) {
        icsaoy_rethrow();
      }
    }

    ICSAOY_INLINE const FieldInfo* il2cpp_class_get_field_from_name(Il2CppClass* const klass, const char* const name) {
      try {
        icsaoy_assert(klass);
        icsaoy_assert(name);
        icsaoy_assert(name[0] != NULL);

        const FieldInfo* result = nullptr;
        void* iter = nullptr;

        do {
          result = il2cpp_class_iterate<const FieldInfo>(
            klass,
            &iter,
            recursive::il2cpp_class_get_fields);
        } while (result && strcmp(result->name, name) != 0);

        icsaoy_assert(result);

        return result;
      }
      catch (...) {
        icsaoy_rethrow();
      }
    }

    ICSAOY_INLINE const MethodInfo* il2cpp_class_get_methods(Il2CppClass* const klass, void** const iter) {
      try {
        icsaoy_assert(klass);
        icsaoy_assert(iter);

        return il2cpp_class_iterate<const MethodInfo>(klass, iter, ::il2cpp_class_get_methods);
      }
      catch (...) {
        icsaoy_rethrow();
      }
    }

    ICSAOY_INLINE const MethodInfo* il2cpp_class_get_method_from_name(Il2CppClass* const klass, const char* name, const int argsCount) {
      try {
        icsaoy_assert(klass);
        icsaoy_assert(name);
        icsaoy_assert(name[0] != NULL);

        const MethodInfo* result = nullptr;
        void* iter = nullptr;

        do {
          result = il2cpp_class_iterate<const MethodInfo>(
            klass,
            &iter,
            recursive::il2cpp_class_get_methods);
        } while (result && strcmp(result->name, name) != 0);

        icsaoy_assert(result);
        icsaoy_assert(result->parameters_count == argsCount);

        return result;
      }
      catch (...) {
        icsaoy_rethrow();
      }
    }
  }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

il2cpp_type::il2cpp_type(const Il2CppType* const object)
  : il2cpp_base{ object }
{ }

ICSAOY_INLINE const Il2CppTypeEnum il2cpp_type::get_type() const {
  try {
    icsaoy_assert(get_native());

    return get_native()->type;
  }
  catch (...) {
    icsaoy_rethrow();
  }
}

ICSAOY_INLINE const il2cpp_class_ptr il2cpp_type::get_class() const {
  try {
    icsaoy_assert(get_native());
    return std::make_shared<il2cpp_class>(il2cpp_class_from_il2cpp_type(get_native()));
  }
  catch (...) {
    icsaoy_rethrow();
  }
}

ICSAOY_INLINE const il2cpp_object_ptr il2cpp_type::get_object() const {
  try {
    icsaoy_assert(get_native());
    return std::make_shared<il2cpp_object>(il2cpp_type_get_object(get_native()));
  }
  catch (...) {
    icsaoy_rethrow();
  }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

il2cpp_domain::il2cpp_domain(const Il2CppDomain* const domain)
  : il2cpp_base{ domain },
  assemblies{}
{ }

il2cpp_domain::il2cpp_domain()
  : il2cpp_domain{ il2cpp_domain_get() }
{ }

ICSAOY_INLINE const il2cpp_domain_ptr il2cpp_domain::get() {
  static il2cpp_domain_ptr instance;

  if (!instance)
    instance = std::make_shared<il2cpp_domain>(il2cpp_domain_get());

  return instance;
}

ICSAOY_INLINE const std::string_view il2cpp_domain::get_name() const {
  try {
    icsaoy_assert(get_native());

    return get_native()->friendly_name;
  }
  catch (...) {
    icsaoy_rethrow();
  }
}

ICSAOY_INLINE const il2cpp_assembly_ptr& il2cpp_domain::assembly_open(const std::string_view& name) {
  try {
    icsaoy_assert(get_native());
    icsaoy_assert(!name.empty());

    auto it = std::find_if(
      assemblies.begin(),
      assemblies.end(),
      [&name](const il2cpp_assembly_ptr& ptr) { return ptr->get_name() == name; });

    if (it != assemblies.end())
      return *it;

    auto assembly = std::make_shared<il2cpp_assembly>(il2cpp_domain_assembly_open(get_native(), name.data()));
    return assemblies.emplace_back(assembly);
  }
  catch (...) {
    icsaoy_rethrow();
  }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

il2cpp_stack_frame_info::il2cpp_stack_frame_info(const Il2CppStackFrameInfo* const stack_frame_info)
  : il2cpp_base{ stack_frame_info }
{ }

ICSAOY_INLINE const il2cpp_method_info_ptr il2cpp_stack_frame_info::get_method() const {
  return std::make_shared<il2cpp_method_info>(get_native()->method);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

il2cpp_thread::il2cpp_thread(const Il2CppThread* const thread)
  : il2cpp_base{ thread }
{ }

ICSAOY_INLINE il2cpp_thread_ptr il2cpp_thread::get_current() {
  return std::make_shared<il2cpp_thread>(il2cpp_thread_current());
}

ICSAOY_INLINE il2cpp_thread_ptr il2cpp_thread::attach(const il2cpp_domain_ptr& domain) {
  return std::make_shared<il2cpp_thread>(il2cpp_thread_attach(domain->get_native()));
}

ICSAOY_INLINE void il2cpp_thread::detach() const {
  il2cpp_thread_detach(get_native());
}

ICSAOY_INLINE const il2cpp_thread::stack_frame_t il2cpp_thread::get_stack_frame() const {
  stack_frame_t stack_frame = {};

  auto frame_walker = [](const Il2CppStackFrameInfo* info, void* user_data) {
    ((stack_frame_t*)(user_data))->push_back(std::make_shared<il2cpp_stack_frame_info>(info));
  };

  il2cpp_thread_walk_frame_stack(get_native(), frame_walker, &stack_frame);

  return stack_frame;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////


il2cpp_assembly::il2cpp_assembly(const Il2CppAssembly* const assembly)
  : il2cpp_base{ assembly },
  image{ std::make_shared<il2cpp_image>(il2cpp_assembly_get_image(assembly)) }
{ }

ICSAOY_INLINE const std::string_view il2cpp_assembly::get_name() const {
  try {
    icsaoy_assert(get_native());

    return get_native()->aname.name;
  }
  catch (...) {
    icsaoy_rethrow();
  }
}

ICSAOY_INLINE const il2cpp_image_ptr& il2cpp_assembly::get_image() const {
  try {
    icsaoy_assert(get_native());

    return image;
  }
  catch (...) {
    icsaoy_rethrow();
  }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

il2cpp_image::il2cpp_image(const Il2CppImage* const image)
  : il2cpp_base_with_name{ image },
  classes{}
{ }

ICSAOY_INLINE const std::string_view il2cpp_image::name_without_extension() const {
  try {
    icsaoy_assert(get_native());

    return get_native()->nameNoExt;
  }
  catch (...) {
    icsaoy_rethrow();
  }
}

ICSAOY_INLINE const il2cpp_class_ptr& il2cpp_image::get_class(const std::string_view& name) {
  try {
    icsaoy_assert(get_native());
    icsaoy_assert(!name.empty());

    return get_class("", name);
  }
  catch (...) {
    icsaoy_rethrow();
  }
}

ICSAOY_INLINE const il2cpp_class_ptr& il2cpp_image::get_class(const std::string_view& ns, const std::string_view& name) {
  try {
    icsaoy_assert(get_native());
    icsaoy_assert(!name.empty());

    auto it = std::find_if(
      classes.begin(),
      classes.end(),
      [&ns, &name](const il2cpp_class_ptr& ptr) { return ptr->get_namespace() == ns && ptr->get_name() == name; });

    if (it != classes.end())
      return *it;

    auto klass = std::make_shared<il2cpp_class>(il2cpp_class_from_name(get_native(), ns.data(), name.data()));
    return classes.emplace_back(klass);
  }
  catch (...) {
    icsaoy_rethrow();
  }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

il2cpp_object::il2cpp_object(const Il2CppObject* const object)
  : il2cpp_base{ object }
{ }

ICSAOY_INLINE const size_t il2cpp_object::get_size() const {
  try {
    icsaoy_assert(get_native());

    return il2cpp_object_get_size(get_native());
  }
  catch (...) {
    icsaoy_rethrow();
  }
}

ICSAOY_INLINE const il2cpp_method_info_ptr il2cpp_object::get_virtual_method(const il2cpp_method_info_ptr& method_info) const {
  try {
    icsaoy_assert(get_native());
    icsaoy_assert(method_info->get_native());

    auto method_ptr = il2cpp_object_get_virtual_method(get_native(), method_info->get_native());

    icsaoy_assert(method_ptr);

    return std::make_shared<il2cpp_method_info>(method_ptr);
  }
  catch (...) {
    icsaoy_rethrow();
  }
}

ICSAOY_INLINE const il2cpp_class_ptr il2cpp_object::get_class() const {
  try {
    icsaoy_assert(get_native());

    auto class_ptr = il2cpp_object_get_class(get_native());

    icsaoy_assert(class_ptr);

    return std::make_shared<il2cpp_class>(class_ptr);
  }
  catch (...) {
    icsaoy_rethrow();
  }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

il2cpp_class::il2cpp_class(const Il2CppClass* const klass)
  : il2cpp_base_with_name{ klass },
  methods{},
  fields{},
  properties{}
{ }

ICSAOY_INLINE const std::string_view il2cpp_class::get_namespace() const {
  try {
    return get_native()->namespaze;
  }
  catch (...) {
    icsaoy_rethrow();
  }
}

ICSAOY_INLINE const std::string il2cpp_class::get_full_name() const {
  try {
    std::stringstream stream;

    stream << get_native()->name;
    if (get_native()->namespaze != NULL)
    {
      stream << std::string("::") << get_native()->namespaze;
    }

    return stream.str();
  }
  catch (...) {
    icsaoy_rethrow();
  }
}

ICSAOY_INLINE const il2cpp_method_info_ptr& il2cpp_class::get_method(const std::string_view& name, const int arg_count) {
  try {
    icsaoy_assert(get_native());
    icsaoy_assert(!name.empty());

    auto it = std::find_if(
      methods.begin(),
      methods.end(),
      [&name, &arg_count](const il2cpp_method_info_ptr& ptr) { return ptr->get_name() == name && ptr->get_params().size() == arg_count; });

    if (it != methods.end())
      return *it;

    auto method = std::make_shared<il2cpp_method_info>(utils::recursive::il2cpp_class_get_method_from_name(get_native(), name.data(), arg_count));
    return methods.emplace_back(method);
  }
  catch (...) {
    icsaoy_rethrow();
  }
}

ICSAOY_INLINE const il2cpp_field_info_ptr& il2cpp_class::get_field(const std::string_view& name) {
  try {
    icsaoy_assert(get_native());
    icsaoy_assert(!name.empty());

    auto it = std::find_if(
      fields.begin(),
      fields.end(),
      [&name](const il2cpp_field_info_ptr& ptr) { return ptr->get_name() == name; });

    if (it != fields.end())
      return *it;

    auto field = std::make_shared<il2cpp_field_info>(utils::recursive::il2cpp_class_get_field_from_name(get_native(), name.data()));
    return fields.emplace_back(field);
  }
  catch (...) {
    icsaoy_rethrow();
  }
}

ICSAOY_INLINE const il2cpp_property_info_ptr& il2cpp_class::get_property(const std::string_view& name) {
  try {
    icsaoy_assert(get_native());
    icsaoy_assert(!name.empty());

    auto it = std::find_if(
      properties.begin(),
      properties.end(),
      [&name](const il2cpp_property_info_ptr& ptr) { return ptr->get_name() == name; });

    if (it != properties.end())
      return *it;

    auto property = std::make_shared<il2cpp_property_info>(utils::recursive::il2cpp_class_get_property_from_name(get_native(), name.data()));
    return properties.emplace_back(property);
  }
  catch (...) {
    icsaoy_rethrow();
  }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

il2cpp_method_info::il2cpp_method_info(const MethodInfo* const method_info)
  : il2cpp_base_with_name{ method_info }, params{ }
{
  try {
    icsaoy_assert(method_info);

    params.resize(method_info->parameters_count);
    for (size_t i = 0; i < method_info->parameters_count; i++)
    {
      auto& param = method_info->parameters[i];
      params[param.position] = std::make_shared<il2cpp_parameter_info>(&method_info->parameters[i]);
    }
  }
  catch (...) {
    icsaoy_rethrow();
  }
}

ICSAOY_INLINE const std::vector<il2cpp_parameter_info_ptr>& il2cpp_method_info::get_params() const {
  try {
    icsaoy_assert(get_native());

    return params;
  }
  catch (...) {
    icsaoy_rethrow();
  }
}

ICSAOY_INLINE const size_t il2cpp_method_info::get_params_count() const {
  try {
    icsaoy_assert(get_native());

    return params.size();
  }
  catch (...) {
    icsaoy_rethrow();
  }
}

ICSAOY_INLINE const il2cpp_parameter_info_ptr il2cpp_method_info::get_param_at(const size_t idx) const {
  try {
    icsaoy_assert(get_native());

    return params.at(idx);
  }
  catch (...) {
    icsaoy_rethrow();
  }
}

ICSAOY_INLINE const il2cpp_parameter_info_ptr il2cpp_method_info::get_param_with_name(const std::string_view& name) const {
  try {
    icsaoy_assert(get_native());
    icsaoy_assert(name.empty());

    for (auto& param : params) {
      if (param->get_name() == name)
        return param;
    }

    throw std::out_of_range("name not found");
  }
  catch (...) {
    icsaoy_rethrow();
  }
}

ICSAOY_INLINE void il2cpp_method_info::invoke() const {
  try {
    icsaoy_assert(get_native());

    invoke<il2cpp_object_ptr>();
  }
  catch (...) {
    icsaoy_rethrow();
  }
}

ICSAOY_INLINE void il2cpp_method_info::invoke(const il2cpp_object_ptr& obj) const {
  try {
    icsaoy_assert(get_native());
    icsaoy_assert(obj->get_native());

    invoke<il2cpp_object_ptr>(obj);
  }
  catch (...) {
    icsaoy_rethrow();
  }
}

template<>
ICSAOY_INLINE void il2cpp_method_info::invoke<il2cpp_object_ptr>(const il2cpp_object_ptr& arg) const {
  try {
    icsaoy_assert(get_native());
    icsaoy_assert(arg->get_native());

    invoke<il2cpp_object_ptr, il2cpp_object_ptr>(arg);
  }
  catch (...) {
    icsaoy_rethrow();
  }
}

template<>
ICSAOY_INLINE void il2cpp_method_info::invoke<il2cpp_arg_builder_ptr>(const il2cpp_arg_builder_ptr& arg) const {
  try {
    icsaoy_assert(get_native());

    invoke<il2cpp_object_ptr, il2cpp_arg_builder_ptr>(arg);
  }
  catch (...) {
    icsaoy_rethrow();
  }
}

template<>
ICSAOY_INLINE void il2cpp_method_info::invoke<il2cpp_object_ptr>(const il2cpp_object_ptr& obj, const il2cpp_object_ptr& arg) const {
  try {
    icsaoy_assert(get_native());
    icsaoy_assert(obj->get_native());
    icsaoy_assert(arg->get_native());

    invoke<il2cpp_object_ptr, il2cpp_object_ptr>(obj, arg);
  }
  catch (...) {
    icsaoy_rethrow();
  }
}

template<>
ICSAOY_INLINE void il2cpp_method_info::invoke<il2cpp_arg_builder_ptr>(const il2cpp_object_ptr& obj, const il2cpp_arg_builder_ptr& arg) const {
  try {
    icsaoy_assert(get_native());
    icsaoy_assert(obj->get_native());

    invoke<il2cpp_object_ptr, il2cpp_arg_builder_ptr>(obj, arg);
  }
  catch (...) {
    icsaoy_rethrow();
  }
}

template<>
ICSAOY_INLINE const il2cpp_object_ptr il2cpp_method_info::invoke<il2cpp_object_ptr>() const {
  try {
    icsaoy_assert(get_native());

    return invoke<il2cpp_object_ptr>(std::make_shared<il2cpp_object>(nullptr));
  }
  catch (...) {
    icsaoy_rethrow();
  }
}

template<>
ICSAOY_INLINE const il2cpp_object_ptr il2cpp_method_info::invoke<il2cpp_object_ptr>(const il2cpp_object_ptr& obj) const {
  try {
    icsaoy_assert(get_native());
    icsaoy_assert(obj->get_native());

    return invoke<il2cpp_object_ptr, il2cpp_arg_builder_ptr>(obj, il2cpp_arg_builder::create());
  }
  catch (...) {
    icsaoy_rethrow();
  }
}

template<>
ICSAOY_INLINE const il2cpp_object_ptr il2cpp_method_info::invoke<il2cpp_object_ptr, il2cpp_object_ptr>(const il2cpp_object_ptr& arg) const {
  try {
    icsaoy_assert(get_native());
    icsaoy_assert(arg->get_native());

    return invoke<il2cpp_object_ptr, il2cpp_arg_builder_ptr>(il2cpp_arg_builder::create()->arg(arg));
  }
  catch (...) {
    icsaoy_rethrow();
  }
}

template<>
ICSAOY_INLINE const il2cpp_object_ptr il2cpp_method_info::invoke<il2cpp_object_ptr, il2cpp_arg_builder_ptr>(const il2cpp_arg_builder_ptr& arg) const {
  try {
    icsaoy_assert(get_native());

    return invoke<il2cpp_object_ptr, il2cpp_arg_builder_ptr>(std::make_shared<il2cpp_object>(nullptr), arg);
  }
  catch (...) {
    icsaoy_rethrow();
  }
}

template<>
ICSAOY_INLINE const il2cpp_object_ptr il2cpp_method_info::invoke<il2cpp_object_ptr, il2cpp_object_ptr>(const il2cpp_object_ptr& obj, const il2cpp_object_ptr& arg) const {
  try {
    icsaoy_assert(get_native());
    icsaoy_assert(obj->get_native());
    icsaoy_assert(arg->get_native());

    return invoke<il2cpp_object_ptr, il2cpp_arg_builder_ptr>(obj, il2cpp_arg_builder::create()->arg(arg));
  }
  catch (...) {
    icsaoy_rethrow();
  }
}

template<>
ICSAOY_INLINE const il2cpp_object_ptr il2cpp_method_info::invoke<il2cpp_object_ptr, il2cpp_arg_builder_ptr>(const il2cpp_object_ptr& obj, const il2cpp_arg_builder_ptr& arg) const {
  try {
    Il2CppException* exc = nullptr;
    Il2CppObject* result = nullptr;

    icsaoy_assert(get_native());
    icsaoy_assert(obj->get_native());

    arg->from_method_info(shared_from_this());

    icsaoy_assert(get_params_count() == arg->count());

    result = il2cpp_runtime_invoke(get_native(), obj->get_native(), arg->data<void*>(), &exc);

    if (exc)
      icsaoy_assert_msg(exc, (std::string_view{ (const char*)&exc->message->chars[0] , (size_t)exc->message->length }));

    return std::make_shared<il2cpp_object>(result);
  }
  catch (...) {
    icsaoy_rethrow();
  }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

il2cpp_property_info::il2cpp_property_info(const PropertyInfo* const property_info)
  : il2cpp_base_with_name{ property_info }
{ }

ICSAOY_INLINE const il2cpp_method_info_ptr il2cpp_property_info::get_method() const {
  try {
    icsaoy_assert(get_native());

    auto method_ptr = il2cpp_property_get_get_method(get_native());

    icsaoy_assert(method_ptr);

    return std::make_shared<il2cpp_method_info>(method_ptr);
  }
  catch (...) {
    icsaoy_rethrow();
  }
}

ICSAOY_INLINE const il2cpp_method_info_ptr il2cpp_property_info::set_method() const {
  try {
    icsaoy_assert(get_native());

    auto method_ptr = il2cpp_property_get_set_method(get_native());

    icsaoy_assert(method_ptr);

    return std::make_shared<il2cpp_method_info>(method_ptr);
  }
  catch (...) {
    icsaoy_rethrow();
  }
}

template<>
ICSAOY_INLINE const il2cpp_object_ptr il2cpp_property_info::get_value<il2cpp_object_ptr>() const {
  try {
    icsaoy_assert(get_native());

    return get_method()->invoke<il2cpp_object_ptr>();
  }
  catch (...) {
    icsaoy_rethrow();
  }
}

template<>
ICSAOY_INLINE const il2cpp_object_ptr il2cpp_property_info::get_value<il2cpp_object_ptr>(const il2cpp_object_ptr& obj) const {
  try {
    icsaoy_assert(get_native());
    icsaoy_assert(obj->get_native());

    return get_method()->invoke<il2cpp_object_ptr>(obj);
  }
  catch (...) {
    icsaoy_rethrow();
  }
}

template<>
ICSAOY_INLINE const il2cpp_object_ptr il2cpp_property_info::get_value<il2cpp_object_ptr, il2cpp_object_ptr>(const il2cpp_object_ptr& key) const {
  try {
    icsaoy_assert(get_native());
    icsaoy_assert(key->get_native());

    return get_method()->invoke<il2cpp_object_ptr>(il2cpp_arg_builder::create()->arg(key));
  }
  catch (...) {
    icsaoy_rethrow();
  }
}

template<>
ICSAOY_INLINE const il2cpp_object_ptr il2cpp_property_info::get_value<il2cpp_object_ptr, il2cpp_object_ptr>(const il2cpp_object_ptr& obj, const il2cpp_object_ptr& key) const {
  try {
    icsaoy_assert(get_native());
    icsaoy_assert(obj->get_native());
    icsaoy_assert(key->get_native());

    return get_method()->invoke<il2cpp_object_ptr>(obj, il2cpp_arg_builder::create()->arg(key));
  }
  catch (...) {
    icsaoy_rethrow();
  }
}

template<>
ICSAOY_INLINE void il2cpp_property_info::set_value<il2cpp_object_ptr>(const il2cpp_object_ptr& value) const {
  try {
    icsaoy_assert(get_native());
    icsaoy_assert(value->get_native());

    set_method()->invoke(value);
  }
  catch (...) {
    icsaoy_rethrow();
  }
}

template<>
ICSAOY_INLINE void il2cpp_property_info::set_value<il2cpp_object_ptr>(const il2cpp_object_ptr& obj, const il2cpp_object_ptr& value) const {
  try {
    icsaoy_assert(get_native());
    icsaoy_assert(obj->get_native());
    icsaoy_assert(value->get_native());

    set_method()->invoke(obj, value);
  }
  catch (...) {
    icsaoy_rethrow();
  }
}

template<>
ICSAOY_INLINE void il2cpp_property_info::set_value<il2cpp_object_ptr, il2cpp_object_ptr>(const il2cpp_object_ptr& key, const il2cpp_object_ptr& value) const {
  try {
    icsaoy_assert(get_native());
    icsaoy_assert(key->get_native());
    icsaoy_assert(value->get_native());

    set_method()->invoke(il2cpp_arg_builder::create()->arg(key)->arg(value));
  }
  catch (...) {
    icsaoy_rethrow();
  }
}

template<>
ICSAOY_INLINE void il2cpp_property_info::set_value<il2cpp_object_ptr, il2cpp_object_ptr>(const il2cpp_object_ptr& obj, const il2cpp_object_ptr& key, const il2cpp_object_ptr& value) const {
  try {
    icsaoy_assert(get_native());
    icsaoy_assert(obj->get_native());
    icsaoy_assert(key->get_native());
    icsaoy_assert(value->get_native());

    set_method()->invoke(obj, il2cpp_arg_builder::create()->arg(key)->arg(value));
  }
  catch (...) {
    icsaoy_rethrow();
  }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

il2cpp_field_info::il2cpp_field_info(const FieldInfo* const field_info)
  : il2cpp_base_with_name{ field_info }
{ }

template<>
ICSAOY_INLINE const il2cpp_object_ptr il2cpp_field_info::get_value<il2cpp_object_ptr>() const {
  try {
    icsaoy_assert(get_native());

    Il2CppObject* value = nullptr;
    il2cpp_field_static_get_value(get_native(), &value);

    icsaoy_assert(&value);

    return std::make_shared<il2cpp_object>(value);
  }
  catch (...) {
    icsaoy_rethrow();
  }
}

template<>
ICSAOY_INLINE const il2cpp_object_ptr il2cpp_field_info::get_value<il2cpp_object_ptr>(const il2cpp_object_ptr& obj) const {
  try {
    icsaoy_assert(get_native());
    icsaoy_assert(obj->get_native());

    Il2CppObject* value = nullptr;
    il2cpp_field_get_value(obj->get_native(), get_native(), &value);

    icsaoy_assert(&value);

    return std::make_shared<il2cpp_object>(value);
  }
  catch (...) {
    icsaoy_rethrow();
  }
}

template<>
ICSAOY_INLINE void il2cpp_field_info::set_value<il2cpp_object_ptr>(const il2cpp_object_ptr& value) const {
  try {
    icsaoy_assert(get_native());
    icsaoy_assert(value->get_native());

    il2cpp_field_static_set_value(get_native(), value->get_native());
  }
  catch (...) {
    icsaoy_rethrow();
  }
}

template<>
ICSAOY_INLINE void il2cpp_field_info::set_value<il2cpp_object_ptr>(const il2cpp_object_ptr& obj, const il2cpp_object_ptr& value) const {
  try {
    icsaoy_assert(get_native());
    icsaoy_assert(obj->get_native());
    icsaoy_assert(value->get_native());

    il2cpp_field_set_value(obj->get_native(), get_native(), value->get_native());
  }
  catch (...) {
    icsaoy_rethrow();
  }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

il2cpp_parameter_info::il2cpp_parameter_info(const ParameterInfo* const parameter_info)
  : il2cpp_base_with_name{ parameter_info }
{ }

ICSAOY_INLINE const size_t il2cpp_parameter_info::get_position() const {
  try {
    icsaoy_assert(get_native());

    return get_native()->position;
  }
  catch (...) {
    icsaoy_rethrow();
  }
}

ICSAOY_INLINE const il2cpp_type_ptr il2cpp_parameter_info::get_type() const {
  try {
    icsaoy_assert(get_native());

    return std::make_shared<il2cpp_type>(get_native()->parameter_type);
  }
  catch (...) {
    icsaoy_rethrow();
  }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

il2cpp_arg_builder::il2cpp_arg_builder()
  : args{}
{ }

ICSAOY_INLINE void il2cpp_arg_builder::_from_method_info(const il2cpp_method_info_const_ptr& method_info) {
  try {
    icsaoy_assert(method_info->get_native());
    std::vector<il2cpp_parameter_info_ptr> copy_params{ method_info->get_params() };
    std::vector<void*> new_args{ method_info->get_params_count() };

    for (auto& param : copy_params) {
      auto index = param->get_position();
      auto param_type = param->get_type();
      void* instance = nullptr;

      if (args.size() > index) {
        instance = args.at(index);
      }
      else {
        auto klass = param_type->get_class();
        auto safe_instance = std::make_shared<il2cpp_object>(il2cpp_object_new(klass->get_native()));

        klass->get_method(".ctor")->invoke(safe_instance);
        instance = safe_instance->get_native();
      }

      new_args.at(index) = instance;
    }

    args = new_args;
  }
  catch (...) {
    icsaoy_rethrow();
  }
}

ICSAOY_INLINE void il2cpp_arg_builder::_ensure_size(const size_t idx) {
  try {
    if (idx >= args.size() - 1)
      args.resize(idx);
  }
  catch (...) {
    icsaoy_rethrow();
  }
}

ICSAOY_INLINE il2cpp_arg_builder_ptr il2cpp_arg_builder::create() {
  try {
    return std::make_shared<il2cpp_arg_builder>();
  }
  catch (...) {
    icsaoy_rethrow();
  }
}

ICSAOY_INLINE il2cpp_arg_builder_ptr il2cpp_arg_builder::create(const il2cpp_method_info_ptr& method_info) {
  try {
    icsaoy_assert(method_info->get_native());

    return std::make_shared<il2cpp_arg_builder>()->from_method_info(method_info);
  }
  catch (...) {
    icsaoy_rethrow();
  }
}

ICSAOY_INLINE const int il2cpp_arg_builder::count() const {
  return static_cast<int>(args.size());
}

ICSAOY_INLINE const std::vector<void*>& il2cpp_arg_builder::raw() const {
  return args;
}

ICSAOY_INLINE const il2cpp_arg_builder_ptr il2cpp_arg_builder::from_method_info(const il2cpp_method_info_const_ptr& method_info) {
  try {
    icsaoy_assert(method_info->get_native());

    _from_method_info(method_info);
    return shared_from_this();
  }
  catch (...) {
    icsaoy_rethrow();
  }
}

ICSAOY_INLINE const il2cpp_arg_builder_ptr il2cpp_arg_builder::from_method_info(const il2cpp_method_info_ptr& method_info) {
  try {
    icsaoy_assert(method_info->get_native());

    _from_method_info(method_info);
    return shared_from_this();
  }
  catch (...) {
    icsaoy_rethrow();
  }
}

template<>
ICSAOY_INLINE const il2cpp_arg_builder_ptr il2cpp_arg_builder::arg<il2cpp_object_ptr>(const il2cpp_object_ptr& value) {
  try {
    icsaoy_assert(value->get_native());

    args.push_back(value->get_native());
    return shared_from_this();
  }
  catch (...) {
    icsaoy_rethrow();
  }
}

template<>
ICSAOY_INLINE const il2cpp_arg_builder_ptr il2cpp_arg_builder::arg<il2cpp_object_ptr>(const size_t idx, const il2cpp_object_ptr& value) {
  try {
    icsaoy_assert(value->get_native());

    _ensure_size(idx);

    args.insert(args.begin() + idx, static_cast<void*>(value->get_native()));
    return shared_from_this();
  }
  catch (...) {
    icsaoy_rethrow();
  }
}

template<>
ICSAOY_INLINE const il2cpp_arg_builder_ptr il2cpp_arg_builder::arg<std::string_view>(const std::string_view& value) {
  try {
    icsaoy_assert(!value.empty());

    args.push_back(il2cpp_string_new(value.data()));
    return shared_from_this();
  }
  catch (...) {
    icsaoy_rethrow();
  }
}

template<>
ICSAOY_INLINE const il2cpp_arg_builder_ptr il2cpp_arg_builder::arg<std::string_view>(const size_t idx, const std::string_view& value) {
  try {
    icsaoy_assert(!value.empty());

    _ensure_size(idx);

    args.insert(args.begin() + idx, il2cpp_string_new(value.data()));

    return shared_from_this();
  }
  catch (...) {
    icsaoy_rethrow();
  }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

il2cpp_string::il2cpp_string()
  : il2cpp_base<Il2CppString, false>(il2cpp_string_new(nullptr))
{ }

il2cpp_string::il2cpp_string(const Il2CppString* const string)
  : il2cpp_base<Il2CppString, false>(string)
{ }

il2cpp_string::il2cpp_string(const char* str)
  : il2cpp_base<Il2CppString, false>(il2cpp_string_new(str))
{ }

il2cpp_string::il2cpp_string(const wchar_t* str)
  : il2cpp_base<Il2CppString, false>(il2cpp_string_new_utf16(str, static_cast<int32_t>(wcslen(str))))
{ }

il2cpp_string::il2cpp_string(const std::string_view& str)
  : il2cpp_base<Il2CppString, false>(il2cpp_string_new(str.data()))
{ }

il2cpp_string::il2cpp_string(const std::wstring_view& str)
  : il2cpp_base<Il2CppString, false>(il2cpp_string_new_utf16(str.data(), static_cast<int32_t>(str.length())))
{ }

il2cpp_string::il2cpp_string(const std::string& str)
  : il2cpp_base<Il2CppString, false>(il2cpp_string_new(str.c_str()))
{ }

il2cpp_string::il2cpp_string(const std::wstring& str)
  : il2cpp_base<Il2CppString, false>(il2cpp_string_new_utf16(str.c_str(), static_cast<int32_t>(str.length())))
{ }

ICSAOY_INLINE const size_t il2cpp_string::length() const {
  return il2cpp_string_length(get_native());
}

ICSAOY_INLINE const wchar_t* il2cpp_string::begin() const {
  return il2cpp_string_chars(get_native());
}

ICSAOY_INLINE const wchar_t* il2cpp_string::end() const {
  return &begin()[length()];
}

ICSAOY_INLINE const wchar_t il2cpp_string::at(const size_t idx) const {
  if (idx >= length())
    throw std::overflow_error("");

  return begin()[idx];
}