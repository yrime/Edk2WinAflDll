#pragma once

#define IMPORT __declspec(dllimport)
#define EXPORT extern "C" __declspec(dllexport)

IMPORT void WinAflProxyDll(int point);