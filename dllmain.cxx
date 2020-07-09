#include "prerequisites.hxx"
#include "bootloader.hxx"

using namespace std::chrono_literals;

static std::shared_ptr<std::thread> bootloader_thr;
static bool consoleAllocated = false;

BOOL APIENTRY DllMain(
  HMODULE hModule,
  DWORD  ul_reason_for_call,
  LPVOID lpReserved
)
{
  UNREFERENCED_PARAMETER(lpReserved);

  switch (ul_reason_for_call)
  {
  case DLL_PROCESS_ATTACH:
  {
    if (AllocConsole()) {
      freopen_s((FILE**)stdout, "CONOUT$", "w", stdout);
      freopen_s((FILE**)stderr, "CONOUT$", "w", stderr);
      freopen_s((FILE**)stdin, "CONIN$", "r", stdin);

      consoleAllocated = true;
    }

    DisableThreadLibraryCalls(hModule);
    bootloader_thr = std::make_shared<std::thread>(icsaoy::bootloader::initialize);
    bootloader_thr->detach();
  }
  break;

  case DLL_THREAD_ATTACH:
  case DLL_THREAD_DETACH:
    break;

  case DLL_PROCESS_DETACH:
    // Some injectors kills his own thread which was used for injection
    // and the library is still working (for eg. Process Hacker),
    // because they don't invoke the DLL_PROCESS_DETACH.
    // Unloading second twice will throw an exception and the sleep for some
    // amount of time is required.
    std::this_thread::sleep_for(5s);

    if (consoleAllocated && FreeConsole()) {
      fclose(stdout);
      fclose(stderr);
      fclose(stdin);
    }

    icsaoy::bootloader::finalize();
    if (bootloader_thr->joinable())
      bootloader_thr->join();
    break;
  }
  return TRUE;
}