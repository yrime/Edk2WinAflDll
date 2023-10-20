#include "pch.h"
#include "Inject.h"
#include "stdio.h"

#ifdef __cplusplus
	extern "C" {
#endif // __cplusplus

int prev = 0;
#define MAP_SIZE 65536
#define env_size 100
TCHAR envbuff[env_size];
TCHAR shm[env_size];
TCHAR* fuzzid;
char* __afl_area_ptr;
int mai = -1;
	
EXPORT void WinAflProxyDll(int point) {


	unsigned int j;
	j = (prev ^ point);
	j %= MAP_SIZE;
	if (__afl_area_ptr == NULL) {
		mai = point;
		PVOID areaPtr = NULL;
		GetEnvironmentVariable(TEXT("AFL_STATIC_CONFIG"), envbuff, env_size);
		if (GetLastError() == ERROR_ENVVAR_NOT_FOUND) {
			printf("afl env static not found");
			return Status;
		}
		printf("env %ls \n", envbuff);
		wchar_t  *pt;
		fuzzid = wcstok(envbuff, L":", &pt);
		printf(" fuzzid %ls \n", fuzzid);
		wcscpy(shm, TEXT("afl_shm_"));
		printf(" shm %ls \n", shm);
		wcscat(shm, fuzzid);
		printf(" shm %ls \n", shm);
		HANDLE mem = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, shm);
		if (mem == NULL) {
			printf("OpenFileMapping %d", GetLastError());
		}
		areaPtr = MapViewOfFile(mem, FILE_MAP_ALL_ACCESS, 0, 0, 0);
		if (areaPtr == NULL) {
			printf("shm value failed %d --", GetLastError());
			return Status;
		}
		__afl_area_ptr = (char*)areaPtr;
	}

		//   out << "map modification" << std::endl;
	__afl_area_ptr[j]++;
	prev = point >> 1; // pour contruire bien l'itiniraire
	return Status;
}

#ifdef __cplusplus
	}
#endif