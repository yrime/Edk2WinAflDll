#pragma once

#define IMPORT __declspec(dllimport)
#define EXPORT extern "C" __declspec(dllexport)

EXPORT void WinAflProxyDll(int point);
