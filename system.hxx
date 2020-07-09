#pragma once

#include "isystem.hxx"

namespace icsaoy {
  using system_patch_map_t = std::vector<abstractions::ipatch_ptr>;

  class system : public abstractions::isystem {
    ALLOC_STD_MAKE;

    const system_private_ptr priv;
    explicit system();
  public:
    static std::shared_ptr<system> & get();
    void initialize() override;
    void finalize() override;

    const il2cpp_domain_ptr& get_domain() const;
    const il2cpp_image_ptr& get_image() const;

    const system_patch_map_t & get_patches() const;

    template<typename T>
    inline const abstractions::ipatch_ptr get_patch()
    {
      const auto patches = get_patches();
      system_patch_map_t::const_iterator it = std::find_if(
        patches.cbegin(),
        patches.cend(),
        [](const abstractions::ipatch_ptr& p) {
          return typeid(*(p)) == typeid(T);
        });

      if (it == patches.cend())
        return std::make_shared<T>();

      return *it;
    }

    void tick() override;
  };
}