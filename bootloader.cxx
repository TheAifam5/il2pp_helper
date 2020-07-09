#include "prerequisites.hxx"
#include "il2cpp.hxx"
#include "bootloader.hxx"
#include "system.hxx"

using namespace icsaoy;

static std::atomic<bool> is_running(true);
static il2cpp_thread_ptr il2_thread = nullptr;

static void print_exception(const std::exception& e, int level = 0);

void bootloader::initialize() {
  std::string input;

  CONSOLE_SCREEN_BUFFER_INFO csbi;
  int columns;

  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;

  for (;;) {
    il2_thread = il2cpp_thread::attach(il2cpp_domain::get());
    auto sys = system::get();
    std::stringstream stream;

    try {
      sys->initialize();

      while (is_running) {
        sys->tick();
      }
    }
    catch (const std::exception & exc) {
      std::cerr << std::string(columns, '=') << '\n';
      print_exception(exc);
    }

    sys->finalize();
    finalize();

    std::cout << "Want to restart? ";

    input.clear();
    std::cin >> input;

    if (input != "y") {
      FreeLibraryAndExitThread(GetModuleHandle(NULL), 0x1);
      break;
    }
  }
}

void bootloader::finalize() {
  is_running = false;

  if (il2_thread) {
    il2_thread->detach();
    il2_thread.reset();
  }
}

void print_exception(const std::exception& e, int level)
{
  std::cerr << "[" << level << "]" << e.what() << '\n';

  try {
    icsaoy::rethrow_if_nested(e);
  }
  catch (const std::exception & e) {
    print_exception(e, level + 1);
  }
  catch (...) {}
}