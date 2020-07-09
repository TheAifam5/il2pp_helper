#pragma once

#define WIN32_LEAN_AND_MEAN

#define ICSAOY_INLINE

#ifndef ICSAOY_INLINE
#define ICSAOY_INLINE inline
#endif

#define ICSAOY_NOINLINE __declspec(noinline)

#include <stdint.h>
#include <stddef.h>
#include <inttypes.h>
#include <tchar.h>

#include <windows.h>

#include <thread>
#include <memory>
#include <atomic>
#include <chrono>
#include <string_view>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <any>
#include <set>
#include <functional>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <typeinfo>

#include "detours.h"

#include "assert_exception.hxx"
#include "non_assignable.hxx"

#define ALLOC_STD_MAKE \
template <class _Ty, class... _Types> \
friend void std::_Construct_in_place(_Ty& _Obj, _Types&&... _Args) noexcept(std::is_nothrow_constructible_v<_Ty, _Types...>)

namespace icsaoy {
  namespace abstractions {
    class isystem;
    using isystem_ptr = std::shared_ptr<isystem>;

    class ipatch;
    using ipatch_ptr = std::shared_ptr<ipatch>;
  }

  class system;
  using system_ptr = std::shared_ptr<system>;

  struct system_private;
  using system_private_ptr = std::shared_ptr<system_private>;

  template <typename E>
  std::enable_if_t<!std::is_polymorphic<E>::value> rethrow_if_nested(const E&) {}

  template <typename E>
  std::enable_if_t<std::is_polymorphic<E>::value> rethrow_if_nested(const E& e)
  {
    const auto* p = dynamic_cast<const std::nested_exception*>(std::addressof(e));

    if (p && p->nested_ptr()) {
      p->rethrow_nested();
    }
  }


#define DECLARE_IL2CPP_IFACE(name, iface) \
class il2cpp_## name ##;\
using il2cpp_## name ##_ptr = std::shared_ptr<il2cpp_## iface ##>; \
using il2cpp_## name ##_const_ptr = std::shared_ptr<const il2cpp_## iface ##>;

#define DECLARE_IL2CPP(name) DECLARE_IL2CPP_IFACE(name, name)

  DECLARE_IL2CPP(type);
  DECLARE_IL2CPP(domain);
  DECLARE_IL2CPP(stack_frame_info);
  DECLARE_IL2CPP(thread);
  DECLARE_IL2CPP(assembly);
  DECLARE_IL2CPP(image);
  DECLARE_IL2CPP(object);
  DECLARE_IL2CPP(class);
  DECLARE_IL2CPP(method_info);
  DECLARE_IL2CPP(property_info);
  DECLARE_IL2CPP(field_info);

  DECLARE_IL2CPP(parameter_info);

  DECLARE_IL2CPP(arg_builder);

#undef DECLARE_IL2CPP_IFACE
#undef DECLARE_IL2CPP
}