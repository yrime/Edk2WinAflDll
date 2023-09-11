#include "pch.h"
#include "Inject.h"
#include "stdio.h"

EXPORT void WinAflProxyDll(int point) {
    printf("ggg %i", point);
}
