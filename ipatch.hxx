#pragma once

#include "system.hxx"

namespace icsaoy::abstractions {
  class ipatch : public non_assignable {
    friend class icsaoy::system;

    void* hook_tramp;

  public:
    explicit ipatch()
      : hook_tramp(nullptr)
    { }

    virtual const il2cpp_method_info_ptr method() const = 0;

    virtual bool prepare() const { return true; }

    virtual bool prefix(il2cpp_object_ptr&) const { return true; }
    virtual bool prefix(il2cpp_object_ptr&, const std::vector<il2cpp_object_ptr>&) const { return true; }
    virtual bool prefix(il2cpp_object_ptr&, il2cpp_object_ptr&) const { return true; }
    virtual bool prefix(const std::vector<il2cpp_object_ptr>&, il2cpp_object_ptr&) const { return true; }
    virtual bool prefix(il2cpp_object_ptr&, const std::vector<il2cpp_object_ptr>&, il2cpp_object_ptr&) const { return true; }

    virtual void postfix(il2cpp_object_ptr&) const {  }
    virtual void postfix(il2cpp_object_ptr&, const std::vector<il2cpp_object_ptr>&) const {  }
    virtual void postfix(il2cpp_object_ptr&, il2cpp_object_ptr&) const {  }
    virtual void postfix(const std::vector<il2cpp_object_ptr>&, il2cpp_object_ptr&) const {  }
    virtual void postfix(il2cpp_object_ptr&, const std::vector<il2cpp_object_ptr>&, il2cpp_object_ptr&) const {  }
    virtual bool cleanup() const { return true; }

    virtual void* handler_builder() = 0;

    template<typename ...Args>
    inline il2cpp_object_ptr call_orig(Args ...args)
    {
      using callback_t = Il2CppObject * (__fastcall*)(Args...);
      return std::make_shared<il2cpp_object>(((callback_t)hook_tramp)(args...));
    }

    template<typename R = void, class T, typename ...Args>
    ICSAOY_NOINLINE static R __fastcall handler_this(Il2CppObject* self, Args ...args)
    {
      il2cpp_object_ptr result = {};
      std::vector<il2cpp_object_ptr> arg_parsed = { std::make_shared<il2cpp_object>(std::forward<Args>(args)) ... };
      abstractions::ipatch_ptr patch = system::get()->get_patch<T>();
      il2cpp_object_ptr __this = std::make_shared<il2cpp_object>(self);
      bool should_call_orig = true;

      try {
        if constexpr (std::is_same<R, void>::value)
        {
          if constexpr (sizeof...(Args) == 0)
            should_call_orig = patch->prefix(__this);
          else
            should_call_orig = patch->prefix(__this, arg_parsed);
        }
        else {
          if constexpr (sizeof...(Args) == 0)
            should_call_orig = patch->prefix(__this, result);
          else
            should_call_orig = patch->prefix(__this, arg_parsed, result);
        }
      }
      catch (...)
      {
      }

      if (should_call_orig)
      {
        try {
          if constexpr (std::is_same<R, void>::value)
          {
            patch->call_orig<Il2CppObject*, Args...>(__this->get_native(), args...);
          }
          else {
            if (result == nullptr || result->get_native() == nullptr)
              result = patch->call_orig<Il2CppObject*, Args...>(__this->get_native(), args...);
          }
        }
        catch (...)
        {
        }
      }

      try {
        if constexpr (std::is_same<R, void>::value)
        {
          if constexpr (sizeof...(Args) == 0)
            patch->postfix(__this);
          else
            patch->postfix(__this, arg_parsed);
        }
        else {
          if constexpr (sizeof...(Args) == 0)
            patch->postfix(__this, result);
          else
            patch->postfix(__this, arg_parsed, result);
        }
      }
      catch (...)
      {
      }

      try {
        patch->cleanup();
      }
      catch (...)
      {
      }

      if constexpr (!std::is_same<R, void>::value)
        return result->get_native();
    }

    template<typename R, class T, typename ...Args>
    ICSAOY_NOINLINE static R __fastcall handler(Args ...args)
    {
      il2cpp_object_ptr result = {};
      std::vector<il2cpp_object_ptr> arg_parsed = { std::make_shared<il2cpp_object>(std::forward<Args>(args)) ... };
      abstractions::ipatch_ptr patch = system::get()->get_patch<T>();
      bool should_call_orig = true;

      try {
        if constexpr (std::is_same<R, void>::value) {
          if constexpr (sizeof...(Args) == 0)
            should_call_orig = patch->prefix();
          else
            should_call_orig = patch->prefix(arg_parsed);
        }
        else {
          if constexpr (sizeof...(Args) == 0)
            should_call_orig = patch->prefix(result);
          else
            should_call_orig = patch->prefix(arg_parsed, result);
        }
        
      }
      catch (...)
      {
      }

      if (should_call_orig)
      {
        try {
          if constexpr (std::is_same<R, void>::value)
          {
            patch->call_orig( args...);
              
          }
          else {
            if (result == nullptr || result->get_native() == nullptr)
              result = patch->call_orig(args...);
          }
        }
        catch (...)
        {
        }
      }

      try {
        if constexpr (std::is_same<R, void>::value) {
          if constexpr (sizeof...(Args) == 0)
            patch->postfix();
          else
            patch->postfix(arg_parsed);
        }
        else {
          if constexpr (sizeof...(Args) == 0)
            patch->postfix(result);
          else
            patch->postfix(arg_parsed, result);
        }
      }
      catch (...)
      {
      }

      try {
        patch->cleanup();
      }
      catch (...) {
      }

      if constexpr (!std::is_same<R, void>::value)
        return result->get_native();
    }
  };
}