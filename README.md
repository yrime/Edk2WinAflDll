# Edk2WinAflDll

msbuild /p:PlatformToolset=v141 /p:WindowsTargetPlatformVersion=10.0.17763.0 Edk2WinAflDll.sln

or

msbuild /p:PlatformToolset=v141 /p:WindowsTargetPlatformVersion=10.0.17763.0 /property:Platform=x64 /p:ConfigurationType=DynamicLibrary Edk2WinAflDll.sln
