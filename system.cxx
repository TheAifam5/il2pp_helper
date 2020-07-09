#include "prerequisites.hxx"
#include "il2cpp.hxx"
#include "system.hxx"
#include "ipatch.hxx"

#include "patches/ai_controller/update.hxx"
#include "patches/ui/room/on_player_entered.hxx"
#include "patches/ui/menu_region_select/on_click_select_region.hxx"
#include "patches/buildable/ctor.hxx"
#include "patches/buildable_preview/update.hxx"
#include "patches/attacker_placement_logic/can_place_unit_at_location.hxx"
#include "patches/ui/buildable_menu/start.hxx"

struct icsaoy::system_private {
  il2cpp_domain_ptr il2cpp;
  il2cpp_image_ptr game_image;

  system_patch_map_t patches;
};

using namespace icsaoy;
using namespace icsaoy::patches;

std::shared_ptr<icsaoy::system> & system::get() {
  static std::shared_ptr<icsaoy::system> singleton;

  if (!singleton)
    singleton = std::make_shared<icsaoy::system>();

  return singleton;
}

system::system()
  : priv{ std::make_shared<system_private>() } {
  try {
    priv->il2cpp = std::make_shared<il2cpp_domain>();
    priv->game_image = priv->il2cpp
      ->assembly_open("Assembly-CSharp")
      ->get_image();

    priv->patches = {
      // std::make_shared<ai_controller::update>(),
      // std::make_shared<ui::room::on_player_entered>(),
      // std::make_shared<ui::menu_region_select::on_click_select_region>(),
      // std::make_shared<buildable::ctor>(),
      std::make_shared<ui::buildable_menu::start>(),
      // std::make_shared<buildable_preview::update>(),
      // TODO: std::make_shared<attacker_placement_logic::can_place_unit_at_location>(),
    };
  }
  catch (...) {
    icsaoy_rethrow();
  }
}

const il2cpp_domain_ptr& system::get_domain() const {
  return priv->il2cpp;
}

const il2cpp_image_ptr& system::get_image() const {
  return priv->game_image;
}

void system::initialize() {
  try {
    LONG error;

    DetourRestoreAfterWith();

    DetourTransactionBegin();
    // DetourUpdateThread(GetCurrentThread());

    for (auto& patch : priv->patches) {
      auto& method = patch->method();
      patch->hook_tramp = method->method_ptr<void*>();
      DetourAttach(&(PVOID&)patch->hook_tramp, patch->handler_builder());
    }

    error = DetourTransactionCommit();
    if (error != NO_ERROR)
      throw std::exception("Detour failed with: " + error);

    // hooks ServerAction
    /*auto current_class = priv->game_image->get_class("ServerAction");
    hooks::server_actions::tramp_rpc_get_kicked = Detours::X64::DetourFunction(
      current_class->get_method("RPC_GetKicked", 2)->method_ptr<uint8_t*>(),
      (uint8_t*)&hooks::server_actions::rpc_get_kicked
    );

    current_class = priv->game_image->get_class("AIController");
    hooks::ai_controller::tramp_fixed_update = Detours::X64::DetourFunction(
      current_class->get_method("FixedUpdate")->method_ptr<uint8_t*>(),
      (uint8_t*)&hooks::ai_controller::fixed_update
    );
    hooks::ai_controller::tramp_update = Detours::X64::DetourFunction(
      current_class->get_method("Update")->method_ptr<uint8_t*>(),
      (uint8_t*)&hooks::ai_controller::update
    );

    current_class = priv->game_image->get_class("UI_MenuPlayerListing");
    hooks::ui::menu_player_listing::tramp_update = Detours::X64::DetourFunction(
      current_class->get_method("Update")->method_ptr<uint8_t*>(),
      (uint8_t*)&hooks::ui::menu_player_listing::update
    );
    hooks::ui::menu_player_listing::on_value_changed::tramp_class_dropdown = Detours::X64::DetourFunction(
      current_class->get_method("OnValueChanged_ClassDropdown", 1)->method_ptr<uint8_t*>(),
      (uint8_t*)&hooks::ui::menu_player_listing::on_value_changed::class_dropdown
    );
    hooks::ui::menu_player_listing::on_value_changed::tramp_team_dropdown = Detours::X64::DetourFunction(
      current_class->get_method("OnValueChanged_TeamDropdown", 1)->method_ptr<uint8_t*>(),
      (uint8_t*)&hooks::ui::menu_player_listing::on_value_changed::team_dropdown
    );

    current_class = priv->game_image->get_class("UI_RoomChat");
    priv->room_chat = current_class->get_field("Instance");
    priv->room_send = current_class->get_method("SendMessageOverNetwork", 1);*/
  }
  catch (...) {
    icsaoy_rethrow();
  }
}

void system::finalize() {
  try {
    LONG error;

    DetourTransactionBegin();
    // DetourUpdateThread(GetCurrentThread());

    for (auto& patch : priv->patches) {
      DetourDetach(&(PVOID&)patch->hook_tramp, patch->handler_builder());
    }

    error = DetourTransactionCommit();
    if (error != NO_ERROR)
      throw std::exception("Undetour failed with: " + error);
  }
  catch (...) {
    icsaoy_rethrow();
  }
}

void system::tick() {
}

const system_patch_map_t& system::get_patches() const {
  return priv->patches;
}

