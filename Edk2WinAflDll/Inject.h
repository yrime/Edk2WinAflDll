#pragma once
#include "pch.h"
#define EXPORT extern "C" __declspec(dllexport)
#define IMPORT __declspec(dllimport)

EXPORT void WinAflProxyDll(int point);
