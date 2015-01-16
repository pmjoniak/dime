call "%programfiles(x86)%\Microsoft Visual Studio 12.0\VC\vcvarsall.bat" x86
cd dime_vs
msbuild /p:Configuration=Release_profiling;Platform=Win32 dime_vs.sln
msbuild /p:Configuration=Release;Platform=Win32 dime_vs.sln