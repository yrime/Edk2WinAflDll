#ifndef _INJECT_EDK_H_
#define _INJECT_EDK_H_

#define addrInject 0x10000000
inline void callAflProxyDll(int point) {
 /* __asm {
    push point
    mov eax, addr
    call[eax]
    add  esp, 4
  }
  */
  void(*f_ptr)(int);
  f_ptr = *((void(**)(int))(addrInject));
  f_ptr(point);
}
#endif