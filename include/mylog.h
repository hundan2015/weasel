#pragma once
#include <fstream>
#include <iomanip>
#include <shlobj.h>
#include <string>
#pragma comment(lib, "shell32.lib")
template <class a>
void Log(a t, bool hex = false) {
  wchar_t path[255] = {0};
  SHGetSpecialFolderPathW(0, path, CSIDL_DESKTOPDIRECTORY, 0);
  std::wstring desktop(path);
  desktop += L"\\debug.log";
  std::ofstream o(desktop.c_str(), std::ios::app);
  if (hex)
    o << std::setfill('0') << std::setw(8) << std::hex << t;
  else
    o << t;
  o.close();
}
template <class a>
void Logn(a t, bool hex = false) {
  wchar_t path[255] = {0};
  SHGetSpecialFolderPathW(0, path, CSIDL_DESKTOPDIRECTORY, 0);
  std::wstring desktop(path);
  desktop += L"\\debug.log";
  std::ofstream o(desktop.c_str(), std::ios::app);
  if (hex)
    o << std::setfill('0') << std::setw(8) << std::hex << t << std::endl;
  else
    o << t << std::endl;
  o.close();
}