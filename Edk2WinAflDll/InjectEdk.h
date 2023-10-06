#pragma once

#define addr 0x10000000
inline void callAflProxyDll(int point) {
  __asm {
    push point
    mov eax, addr
    call[eax]
    add  esp, 4
  }
}
