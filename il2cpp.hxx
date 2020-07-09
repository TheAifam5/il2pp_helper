#pragma once

#pragma warning(push, 0)
#include <il2cpp-config.h>
#include <il2cpp-api.h>
#include <il2cpp-object-internals.h>
#include <il2cpp-api-types.h>
#pragma warning(pop)

namespace icsaoy {
  namespace utils {
    namespace recursive {
      template<typename T>
      using il2cpp_class_iter_fn = std::function<T* const (Il2CppClass* const, void** const)>;

      template<typename T>
      ICSAOY_INLINE const T* il2cpp_class_iterate(Il2CppClass* const klass, void** const iter, const il2cpp_class_iter_fn<T>& iter_fn) {
        try {
          icsaoy_assert(klass);
          icsaoy_assert(iter);

          Il2CppClass* parent_class = klass;
          const T* prop = nullptr;

          do {
            do {
              prop = iter_fn(parent_class, iter);
              if (prop) {
                return prop;
              }
            } while (prop);

            parent_class = ::il2cpp_class_get_parent(parent_class);
            *iter = nullptr;
          } while (parent_class);

          return nullptr;
        }
        catch (...) {
          icsaoy_rethrow();
        }
      }

      ICSAOY_INLINE const PropertyInfo* il2cpp_class_get_properties(Il2CppClass* const klass, void** const iter);

      ICSAOY_INLINE const PropertyInfo* il2cpp_class_get_property_from_name(Il2CppClass* const klass, const char* const name);

      ICSAOY_INLINE const FieldInfo* il2cpp_class_get_fields(Il2CppClass* const klass, void** const iter);

      ICSAOY_INLINE const FieldInfo* il2cpp_class_get_field_from_name(Il2CppClass* const klass, const char* const name);

      ICSAOY_INLINE const MethodInfo* il2cpp_class_get_methods(Il2CppClass* const klass, void** const iter);

      ICSAOY_INLINE const MethodInfo* il2cpp_class_get_method_from_name(Il2CppClass* const klass, const char* name, const int argsCount);
    }
  }

  /////////////////////////////////////////////////////////////////////////////////////////////////////

  template<class TNative, bool must_const = true>
  class il2cpp_base : public non_assignable {
  public:
    using native_type = std::remove_all_extents_t<std::conditional_t<must_const, const TNative, TNative>>;
    static_assert(!std::is_pointer<native_type>::value, "The TNative can not be a pointer.");

    explicit il2cpp_base(const native_type* const native)
      : native_ptr{ native }
    { }

    ICSAOY_INLINE TNative* get_native() const {
      return const_cast<TNative*>(native_ptr);
    }

    ICSAOY_INLINE const std::string_view get_name() const {
      return "<NULL>";
    }

  protected:
    const native_type* native_ptr;
  };

  /////////////////////////////////////////////////////////////////////////////////////////////////////

  template<class TNative, bool must_const = true>
  class il2cpp_base_with_name : public il2cpp_base<TNative, must_const> {
  public:
    explicit il2cpp_base_with_name(const TNative* const native)
      : il2cpp_base<TNative, must_const>{ native }
    { }

    ICSAOY_INLINE const std::string_view get_name() const {
      try {
        icsaoy_assert(this->get_native());

        return this->get_native()->name;
      }
      catch (...) {
        icsaoy_rethrow();
      }
    }
  };

  /////////////////////////////////////////////////////////////////////////////////////////////////////

  class il2cpp_type : public il2cpp_base<Il2CppType>, public std::enable_shared_from_this<il2cpp_type> {
  public:
    explicit il2cpp_type(const Il2CppType* const object);

    ICSAOY_INLINE const Il2CppTypeEnum get_type() const;

    ICSAOY_INLINE const il2cpp_class_ptr get_class() const;

    ICSAOY_INLINE const il2cpp_object_ptr get_object() const;
  };

  /////////////////////////////////////////////////////////////////////////////////////////////////////

  class il2cpp_domain : public il2cpp_base<Il2CppDomain>, public std::enable_shared_from_this<il2cpp_domain> {
    std::vector<il2cpp_assembly_ptr> assemblies;

  public:
    explicit il2cpp_domain(const Il2CppDomain* const domain);

    explicit il2cpp_domain();

    ICSAOY_INLINE static const il2cpp_domain_ptr get();

    ICSAOY_INLINE const std::string_view get_name() const;

    ICSAOY_INLINE const il2cpp_assembly_ptr& assembly_open(const std::string_view& name);

    template<class _Fty>
    ICSAOY_INLINE static const std::function<_Fty> resolve_internal_call(const std::string_view& name)
    {
      try {
        icsaoy_assert(!name.empty());

        return std::function<_Fty>(il2cpp_resolve_icall(name.data()));
      }
      catch (...) {
        icsaoy_rethrow();
      }
    }
  };

  /////////////////////////////////////////////////////////////////////////////////////////////////////

  class il2cpp_stack_frame_info : public il2cpp_base<Il2CppStackFrameInfo>, public std::enable_shared_from_this<il2cpp_stack_frame_info> {
  public:
    explicit il2cpp_stack_frame_info(const Il2CppStackFrameInfo* const stack_frame_info);

    ICSAOY_INLINE const il2cpp_method_info_ptr get_method() const;
  };

  /////////////////////////////////////////////////////////////////////////////////////////////////////

  class il2cpp_thread : public il2cpp_base<Il2CppThread>, public std::enable_shared_from_this<il2cpp_thread> {
  public:
    using stack_frame_t = std::vector<il2cpp_stack_frame_info_ptr>;

    explicit il2cpp_thread(const Il2CppThread* const thread);

    ICSAOY_INLINE static il2cpp_thread_ptr get_current();

    ICSAOY_INLINE static il2cpp_thread_ptr attach(const il2cpp_domain_ptr& domain);

    ICSAOY_INLINE void detach() const;

    ICSAOY_INLINE const il2cpp_thread::stack_frame_t get_stack_frame() const;
  };

  /////////////////////////////////////////////////////////////////////////////////////////////////////

  class il2cpp_assembly : public il2cpp_base<Il2CppAssembly>, public std::enable_shared_from_this<il2cpp_assembly> {
    const il2cpp_image_ptr image;

  public:
    explicit il2cpp_assembly(const Il2CppAssembly* const assembly);

    ICSAOY_INLINE const std::string_view get_name() const;

    ICSAOY_INLINE const il2cpp_image_ptr& get_image() const;
  };

  /////////////////////////////////////////////////////////////////////////////////////////////////////

  class il2cpp_image : public il2cpp_base_with_name<Il2CppImage>, public std::enable_shared_from_this<il2cpp_image> {
    std::vector<il2cpp_class_ptr> classes;

  public:
    explicit il2cpp_image(const Il2CppImage* const image);

    ICSAOY_INLINE const std::string_view name_without_extension() const;

    ICSAOY_INLINE const il2cpp_class_ptr& get_class(const std::string_view& name);

    ICSAOY_INLINE const il2cpp_class_ptr& get_class(const std::string_view& ns, const std::string_view& name);
  };

  /////////////////////////////////////////////////////////////////////////////////////////////////////

  class il2cpp_object : public il2cpp_base<Il2CppObject>, public std::enable_shared_from_this<il2cpp_object> {
  public:
    explicit il2cpp_object(const Il2CppObject* const object);

    ICSAOY_INLINE const size_t get_size() const;

    ICSAOY_INLINE const il2cpp_method_info_ptr get_virtual_method(const il2cpp_method_info_ptr& method_info) const;

    ICSAOY_INLINE const il2cpp_class_ptr get_class() const;

    template<typename T>
    ICSAOY_INLINE T unwrap() const {
      try {
        icsaoy_assert(get_native());

        return static_cast<T>(reinterpret_cast<intptr_t>(il2cpp_object_unbox(get_native())));
      }
      catch (...) {
        icsaoy_rethrow();
      }
    }
  };

  /////////////////////////////////////////////////////////////////////////////////////////////////////

  class il2cpp_class : public il2cpp_base_with_name<Il2CppClass>, public std::enable_shared_from_this<il2cpp_class> {
    std::vector<il2cpp_method_info_ptr> methods;
    std::vector<il2cpp_field_info_ptr> fields;
    std::vector<il2cpp_property_info_ptr> properties;

  public:
    explicit il2cpp_class(const Il2CppClass* const klass);

    ICSAOY_INLINE const std::string_view get_namespace() const;

    ICSAOY_INLINE const std::string get_full_name() const;

    ICSAOY_INLINE const il2cpp_method_info_ptr& get_method(const std::string_view& name, const int arg_count = 0);

    ICSAOY_INLINE const il2cpp_field_info_ptr& get_field(const std::string_view& name);

    ICSAOY_INLINE const il2cpp_property_info_ptr& get_property(const std::string_view& name);
  };

  /////////////////////////////////////////////////////////////////////////////////////////////////////

  class il2cpp_method_info : public il2cpp_base_with_name<MethodInfo>, public std::enable_shared_from_this<il2cpp_method_info> {
    std::vector<il2cpp_parameter_info_ptr> params;

  public:
    explicit il2cpp_method_info(const MethodInfo* const method_info);

    template<typename T = Il2CppMethodPointer> // , typename = std::enable_if_t<std::is_pointer<T>::value>
    ICSAOY_INLINE const T method_ptr() const {
      try {
        icsaoy_assert(get_native());

        return (const T)get_native()->methodPointer;
      }
      catch (...) {
        icsaoy_rethrow();
      }
    }

    ICSAOY_INLINE const std::vector<il2cpp_parameter_info_ptr>& get_params() const;

    ICSAOY_INLINE const size_t get_params_count() const;

    ICSAOY_INLINE const il2cpp_parameter_info_ptr get_param_at(const size_t idx) const;

    ICSAOY_INLINE const il2cpp_parameter_info_ptr get_param_with_name(const std::string_view& name) const;

    ICSAOY_INLINE void invoke() const;

    ICSAOY_INLINE void invoke(const il2cpp_object_ptr& obj) const;

    template<typename TArg>
    ICSAOY_INLINE void invoke(const TArg& arg) const {
      try {
        icsaoy_assert(get_native());
        icsaoy_assert(&arg);

        invoke<il2cpp_object_ptr, il2cpp_arg_builder_ptr>(il2cpp_arg_builder::create()->arg(arg));
      }
      catch (...) {
        icsaoy_rethrow();
      }
    }

    template<>
    ICSAOY_INLINE void invoke<il2cpp_object_ptr>(const il2cpp_object_ptr& arg) const;

    template<>
    ICSAOY_INLINE void invoke<il2cpp_arg_builder_ptr>(const il2cpp_arg_builder_ptr& arg) const;

    template<typename TArg>
    ICSAOY_INLINE void invoke(const il2cpp_object_ptr& obj, const TArg& arg) const {
      try {
        icsaoy_assert(get_native());
        icsaoy_assert(obj->get_native());
        icsaoy_assert(&arg);

        invoke<il2cpp_object_ptr, il2cpp_arg_builder_ptr>(obj, il2cpp_arg_builder::create()->arg(arg));
      }
      catch (...) {
        icsaoy_rethrow();
      }
    }

    template<>
    ICSAOY_INLINE void invoke<il2cpp_object_ptr>(const il2cpp_object_ptr& obj, const il2cpp_object_ptr& arg) const;

    template<>
    ICSAOY_INLINE void invoke<il2cpp_arg_builder_ptr>(const il2cpp_object_ptr& obj, const il2cpp_arg_builder_ptr& arg) const;

    template<typename TResult>
    ICSAOY_INLINE const TResult invoke() const {
      try {
        icsaoy_assert(get_native());

        return invoke<il2cpp_object_ptr>()->unwrap<TResult>();
      }
      catch (...) {
        icsaoy_rethrow();
      }
    }

    template<typename TResult>
    ICSAOY_INLINE const TResult invoke(const il2cpp_object_ptr& obj) const {
      try {
        icsaoy_assert(get_native());
        icsaoy_assert(obj->get_native());

        return invoke<il2cpp_object_ptr>(obj)->unwrap<TResult>();
      }
      catch (...) {
        icsaoy_rethrow();
      }
    }

    template<typename TResult, typename TArg>
    ICSAOY_INLINE const TResult invoke(const TArg& arg) const {
      try {
        icsaoy_assert(get_native());
        icsaoy_assert(&arg);

        return invoke<il2cpp_object_ptr, il2cpp_arg_builder_ptr>(il2cpp_arg_builder::create()->raw<TArg>(arg))->unwrap<TResult>();
      }
      catch (...) {
        icsaoy_rethrow();
      }
    }

    template<typename TResult, typename TArg>
    ICSAOY_INLINE const TResult invoke(const il2cpp_object_ptr& obj, const TArg& arg) const {
      try {
        icsaoy_assert(get_native());
        icsaoy_assert(obj->get_native());
        icsaoy_assert(&arg);

        return invoke<il2cpp_object_ptr, il2cpp_arg_builder_ptr>(obj, il2cpp_arg_builder::create()->raw<TArg>(arg))->unwrap<TResult>();
      }
      catch (...) {
        icsaoy_rethrow();
      }
    }

    template<>
    ICSAOY_INLINE const il2cpp_object_ptr invoke<il2cpp_object_ptr>() const;

    template<>
    ICSAOY_INLINE const il2cpp_object_ptr invoke<il2cpp_object_ptr>(const il2cpp_object_ptr& obj) const;

    template<>
    ICSAOY_INLINE const il2cpp_object_ptr invoke<il2cpp_object_ptr, il2cpp_object_ptr>(const il2cpp_object_ptr& arg) const;

    template<>
    ICSAOY_INLINE const il2cpp_object_ptr invoke<il2cpp_object_ptr, il2cpp_arg_builder_ptr>(const il2cpp_arg_builder_ptr& arg) const;

    template<>
    ICSAOY_INLINE const il2cpp_object_ptr invoke<il2cpp_object_ptr, il2cpp_object_ptr>(const il2cpp_object_ptr& obj, const il2cpp_object_ptr& arg) const;

    template<>
    ICSAOY_INLINE const il2cpp_object_ptr invoke<il2cpp_object_ptr, il2cpp_arg_builder_ptr>(const il2cpp_object_ptr& obj, const il2cpp_arg_builder_ptr& arg) const;
  };

  /////////////////////////////////////////////////////////////////////////////////////////////////////

  class il2cpp_property_info : public il2cpp_base_with_name<PropertyInfo>, public std::enable_shared_from_this<il2cpp_property_info> {
  public:
    explicit il2cpp_property_info(const PropertyInfo* const property_info);

    ICSAOY_INLINE const il2cpp_method_info_ptr get_method() const;

    ICSAOY_INLINE const il2cpp_method_info_ptr set_method() const;

    template<typename TValue>
    ICSAOY_INLINE const TValue get_value() const {
      try {
        icsaoy_assert(get_native());

        return get_method()->invoke<TValue>();
      }
      catch (...) {
        icsaoy_rethrow();
      }
    }

    template<typename TValue>
    ICSAOY_INLINE const TValue get_value(const il2cpp_object_ptr& obj) const {
      try {
        icsaoy_assert(get_native());
        icsaoy_assert(obj->get_native());

        return get_method()->invoke<TValue>(obj);
      }
      catch (...) {
        icsaoy_rethrow();
      }
    }

    template<typename TKey, typename TValue>
    ICSAOY_INLINE const TValue get_value(const TKey& key) const {
      try {
        icsaoy_assert(get_native());
        icsaoy_assert(&key);

        return get_method()->invoke<TValue, TKey>(key);
      }
      catch (...) {
        icsaoy_rethrow();
      }
    }

    template<typename TKey, typename TValue>
    ICSAOY_INLINE const TValue get_value(const il2cpp_object_ptr& obj, const TKey& key) const {
      try {
        icsaoy_assert(get_native());
        icsaoy_assert(obj->get_native());
        icsaoy_assert(&key);

        return get_method()->invoke<TValue, TKey>(obj, key);
      }
      catch (...) {
        icsaoy_rethrow();
      }
    }

    template<typename TValue>
    ICSAOY_INLINE void set_value(const TValue& value) const {
      try {
        icsaoy_assert(get_native());
        icsaoy_assert(&value);

        set_method()->invoke(value);
      }
      catch (...) {
        icsaoy_rethrow();
      }
    }

    template<typename TValue>
    ICSAOY_INLINE void set_value(const il2cpp_object_ptr& obj, const TValue& value) const {
      try {
        icsaoy_assert(get_native());
        icsaoy_assert(obj->get_native());
        icsaoy_assert(&value);

        set_method()->invoke(obj, value);
      }
      catch (...) {
        icsaoy_rethrow();
      }
    }

    template<typename TKey, typename TValue>
    ICSAOY_INLINE void set_value(const TKey& key, const TValue& value) const {
      try {
        icsaoy_assert(get_native());
        icsaoy_assert(&key);
        icsaoy_assert(&value);

        set_method()->invoke(il2cpp_arg_builder::create()->raw(key)->raw(value));
      }
      catch (...) {
        icsaoy_rethrow();
      }
    }

    template<typename TKey, typename TValue>
    ICSAOY_INLINE void set_value(const il2cpp_object_ptr& obj, const TKey& key, const TValue& value) const {
      try {
        icsaoy_assert(get_native());
        icsaoy_assert(obj->get_native());
        icsaoy_assert(&key);
        icsaoy_assert(&value);

        set_method()->invoke(obj, il2cpp_arg_builder::create()->raw(key)->raw(value));
      }
      catch (...) {
        icsaoy_rethrow();
      }
    }

    template<>
    ICSAOY_INLINE const il2cpp_object_ptr get_value<il2cpp_object_ptr>() const;

    template<>
    ICSAOY_INLINE const il2cpp_object_ptr get_value<il2cpp_object_ptr>(const il2cpp_object_ptr& obj) const;

    template<>
    ICSAOY_INLINE const il2cpp_object_ptr get_value<il2cpp_object_ptr, il2cpp_object_ptr>(const il2cpp_object_ptr& key) const;

    template<>
    ICSAOY_INLINE const il2cpp_object_ptr get_value<il2cpp_object_ptr, il2cpp_object_ptr>(const il2cpp_object_ptr& obj, const il2cpp_object_ptr& key) const;

    template<>
    ICSAOY_INLINE void set_value<il2cpp_object_ptr>(const il2cpp_object_ptr& value) const;

    template<>
    ICSAOY_INLINE void set_value<il2cpp_object_ptr>(const il2cpp_object_ptr& obj, const il2cpp_object_ptr& value) const;

    template<>
    ICSAOY_INLINE void set_value<il2cpp_object_ptr, il2cpp_object_ptr>(const il2cpp_object_ptr& key, const il2cpp_object_ptr& value) const;

    template<>
    ICSAOY_INLINE void set_value<il2cpp_object_ptr, il2cpp_object_ptr>(const il2cpp_object_ptr& obj, const il2cpp_object_ptr& key, const il2cpp_object_ptr& value) const;
  };

  /////////////////////////////////////////////////////////////////////////////////////////////////////

  class il2cpp_field_info : public il2cpp_base_with_name<FieldInfo>, public std::enable_shared_from_this<il2cpp_field_info> {
  public:
    explicit il2cpp_field_info(const FieldInfo* const field_info);

    template<typename TValue>
    ICSAOY_INLINE const TValue get_value() const {
      try {
        icsaoy_assert(get_native());

        void* result = 0;
        il2cpp_field_static_get_value(get_native(), &result);

        icsaoy_assert(result);

        return static_cast<TValue>(result);
      }
      catch (...) {
        icsaoy_rethrow();
      }
    }

    template<typename TValue>
    ICSAOY_INLINE const TValue get_value(const il2cpp_object_ptr& obj) const {
      try {
        icsaoy_assert(get_native());
        icsaoy_assert(obj->get_native());

        void* result = 0;
        il2cpp_field_get_value(obj->get_native(), get_native(), &result);

        icsaoy_assert(result);

        return static_cast<TValue>(result);
      }
      catch (...) {
        icsaoy_rethrow();
      }
    }

    template<typename TValue>
    ICSAOY_INLINE void set_value(const TValue& value) const {
      try {
        icsaoy_assert(get_native());
        icsaoy_assert(&value);

        il2cpp_field_static_get_value(get_native(), (void*)&value);
      }
      catch (...) {
        icsaoy_rethrow();
      }
    }

    template<typename TValue>
    ICSAOY_INLINE void set_value(const il2cpp_object_ptr& obj, const TValue& value) const {
      try {
        icsaoy_assert(get_native());
        icsaoy_assert(obj->get_native());
        icsaoy_assert(&value);

        il2cpp_field_set_value(obj->get_native(), get_native(), (void*)&value);
      }
      catch (...) {
        icsaoy_rethrow();
      }
    }

    template<>
    ICSAOY_INLINE const il2cpp_object_ptr get_value<il2cpp_object_ptr>() const;

    template<>
    ICSAOY_INLINE const il2cpp_object_ptr get_value<il2cpp_object_ptr>(const il2cpp_object_ptr& obj) const;

    template<>
    ICSAOY_INLINE void set_value<il2cpp_object_ptr>(const il2cpp_object_ptr& value) const;

    template<>
    ICSAOY_INLINE void set_value<il2cpp_object_ptr>(const il2cpp_object_ptr& obj, const il2cpp_object_ptr& value) const;
  };

  /////////////////////////////////////////////////////////////////////////////////////////////////////

  class il2cpp_parameter_info : public il2cpp_base_with_name<ParameterInfo>, public std::enable_shared_from_this<il2cpp_parameter_info> {
  public:
    explicit il2cpp_parameter_info(const ParameterInfo* const parameter_info);

    ICSAOY_INLINE const size_t get_position() const;

    ICSAOY_INLINE const il2cpp_type_ptr get_type() const;
  };

  /////////////////////////////////////////////////////////////////////////////////////////////////////

  class il2cpp_arg_builder : public std::enable_shared_from_this<il2cpp_arg_builder> {
    std::vector<void*> args;

    ICSAOY_INLINE void _from_method_info(const il2cpp_method_info_const_ptr& method_info);

    ICSAOY_INLINE void _ensure_size(const size_t idx);

  public:
    explicit il2cpp_arg_builder();

    ICSAOY_INLINE static il2cpp_arg_builder_ptr create();

    ICSAOY_INLINE static il2cpp_arg_builder_ptr create(const il2cpp_method_info_ptr& method_info);

    ICSAOY_INLINE const int count() const;

    template<typename T>
    ICSAOY_INLINE T* data() const {
      return (T*)(args.data());
    }

    template<typename T>
    ICSAOY_INLINE T* const& at(const size_t idx) const {
      return (T* const&)args.at(idx);
    }

    ICSAOY_INLINE const std::vector<void*>& raw() const;

    ICSAOY_INLINE const il2cpp_arg_builder_ptr from_method_info(const il2cpp_method_info_const_ptr& method_info);

    ICSAOY_INLINE const il2cpp_arg_builder_ptr from_method_info(const il2cpp_method_info_ptr& method_info);

    template<typename T>
    ICSAOY_INLINE const il2cpp_arg_builder_ptr arg(const T& value) {
      try {
        icsaoy_assert(&value);

        args.push_back(const_cast<void*>(static_cast<const void*>(&value)));
        return shared_from_this();
      }
      catch (...) {
        icsaoy_rethrow();
      }
    }

    template<std::size_t N>
    ICSAOY_INLINE const il2cpp_arg_builder_ptr arg(const char(&value)[N]) {
      try {
        return arg<std::string_view>({ &value[0], N });
      }
      catch (...) {
        icsaoy_rethrow();
      }
    }

    template<size_t N>
    ICSAOY_INLINE const il2cpp_arg_builder_ptr arg(const size_t idx, const char(&value)[N]) {
      try {
        return arg<std::string_view>(idx, { &value[0], N });
      }
      catch (...) {
        icsaoy_rethrow();
      }
    }

    template<typename T>
    ICSAOY_INLINE const il2cpp_arg_builder_ptr arg(const size_t idx, const T& value) {
      try {
        icsaoy_assert(&value);

        _ensure_size(idx);

        args.insert(args.begin() + idx, const_cast<void*>(static_cast<const void*>(&value)));
        return shared_from_this();
      }
      catch (...) {
        icsaoy_rethrow();
      }
    }

    template<>
    ICSAOY_INLINE const il2cpp_arg_builder_ptr arg<il2cpp_object_ptr>(const il2cpp_object_ptr& value);

    template<>
    ICSAOY_INLINE const il2cpp_arg_builder_ptr arg<il2cpp_object_ptr>(const size_t idx, const il2cpp_object_ptr& value);

    template<>
    ICSAOY_INLINE const il2cpp_arg_builder_ptr arg<std::string_view>(const std::string_view& value);

    template<>
    ICSAOY_INLINE const il2cpp_arg_builder_ptr arg<std::string_view>(const size_t idx, const std::string_view& value);
  };

  /////////////////////////////////////////////////////////////////////////////////////////////////////

  class il2cpp_string : public il2cpp_base<Il2CppString, false> {
  public:
    explicit il2cpp_string();

    explicit il2cpp_string(const Il2CppString* const string);

    explicit il2cpp_string(const char* str);

    explicit il2cpp_string(const wchar_t* str);

    explicit il2cpp_string(const std::string_view& str);

    explicit il2cpp_string(const std::wstring_view& str);

    explicit il2cpp_string(const std::string& str);

    explicit il2cpp_string(const std::wstring& str);

    ICSAOY_INLINE const size_t length() const;

    ICSAOY_INLINE const wchar_t* begin() const;

    ICSAOY_INLINE const wchar_t* end() const;

    ICSAOY_INLINE const wchar_t at(const size_t idx) const;
  };
}