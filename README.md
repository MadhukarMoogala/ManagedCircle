# Managed Wrapper Example ObjectARX

![ObjectARX2024](https://img.shields.io/badge/ObjectARX-2024-brightgreen.svg)
![BuildPassed](https://img.shields.io/badge/build-passed-brightgreen.svg)
![AutoCAD2024](https://img.shields.io/badge/AutoCAD-2024-blue.svg)

This sample is created with [ObjectARX Wizard](https://github.com/ADN-DevTech/ObjectARX-Wizards/tree/ForAutoCAD2024) to show how to create a Managed Wrapper .NET API to AutoCAD
C++ API, in this example we extend to API `asdkCustomCircleMgd::setCenter` and `asdkCustomCircleMgd::setRadius`

## Demo

![DemoImage](https://github.com/MadhukarMoogala/ManagedCircle/blob/master/Demo.gif)

## Step To Build

```
git clone https://github.com/MadhukarMoogala/ManagedCircle.git
cd ManagedCircle
set ObjectARXPATH=<arxsdkpath>
set AcadDir=<AutoCAD Install Folder>
msbuild /t:build
```

Expected Build Log

```bash
MSBuild version 17.10.4+10fbfbf2e for .NET Framework
Build started 06-06-2024 12:14:04.

Project "D:\Work\Projects\2024\ManagedCircle\ArxProject1.sln" on node 1 (build target(s)).
ValidateSolutionConfiguration:
  Building solution configuration "Debug|x64".
Project "D:\Work\Projects\2024\ManagedCircle\ArxProject1.sln" (1) is building "D:\Work\Projects\2024\ManagedCircle\ArxProject1\ArxProject1.vcxproj.metaproj" (2) on node 1 (default targets).
Project "D:\Work\Projects\2024\ManagedCircle\ArxProject1\ArxProject1.vcxproj.metaproj" (2) is building "D:\Work\Projects\2024\ManagedCircle\dbxCircle\dbxCircle.vcxproj" (3) on node 1 (default targets).
PrepareForBuild:
  Structured output is enabled. The formatting of compiler diagnostics will reflect the error hierarchy. See https://aka.ms/cpp/structured-output for more details.
InitializeBuildStatus:
  Creating "x64\Debug\dbxCircle.tlog\unsuccessfulbuild" because "AlwaysCreate" was specified.
  Touching "x64\Debug\dbxCircle.tlog\unsuccessfulbuild".
ClCompile:
  C:\VS2022\VC\Tools\MSVC\14.40.33807\bin\HostX64\x64\CL.exe /c /ID:\ArxSDKs\arx2024\inc /I"D:\ArxSDKs\arx2024\inc-x64" /AI"D:\ACAD\ursa\AutoCAD 2024" /Zi /nologo /W1 /WX- /diagnostics:column /Od /D _WIN64 /D _WINDOWS /D DBXCIRCLE_MODULE /D _DBXAPP /D _WINDLL /D _UNICODE /D UNIC
  ODE /GF- /Gm- /EHsc /RTC1 /MD /GS /fp:precise /Zc:wchar_t /Zc:forScope /Zc:inline /GR /Yc"stdafx.h" /Fp"x64\Debug\dbxCircle.pch" /Fo"x64\Debug\\" /Fd"x64\Debug\vc143.pdb" /external:W1 /Gd /TP /FC /errorReport:queue StdAfx.cpp
  StdAfx.cpp
  C:\VS2022\VC\Tools\MSVC\14.40.33807\bin\HostX64\x64\CL.exe /c /ID:\ArxSDKs\arx2024\inc /I"D:\ArxSDKs\arx2024\inc-x64" /AI"D:\ACAD\ursa\AutoCAD 2024" /Zi /nologo /W1 /WX- /diagnostics:column /Od /D _WIN64 /D _WINDOWS /D DBXCIRCLE_MODULE /D _DBXAPP /D _WINDLL /D _UNICODE /D UNIC
  ODE /GF- /Gm- /EHsc /RTC1 /MD /GS /fp:precise /Zc:wchar_t /Zc:forScope /Zc:inline /GR /Yu"stdafx.h" /Fp"x64\Debug\dbxCircle.pch" /Fo"x64\Debug\\" /Fd"x64\Debug\vc143.pdb" /external:W1 /Gd /TP /FC /errorReport:queue acrxEntryPoint.cpp asdkCustomCircle.cpp dbxCircle.cpp
  acrxEntryPoint.cpp
  asdkCustomCircle.cpp
  dbxCircle.cpp
  Generating Code...
ResourceCompile:
  C:\Program Files (x86)\Windows Kits\10\bin\10.0.22621.0\x64\rc.exe /D _UNICODE /D UNICODE /l"0x0409" /Ix64\Debug\ /nologo /fo"x64\Debug\dbxCircle.res" dbxCircle.rc
Link:
  C:\VS2022\VC\Tools\MSVC\14.40.33807\bin\HostX64\x64\link.exe /ERRORREPORT:QUEUE /OUT:"D:\Work\Projects\2024\ManagedCircle\x64\Debug\dbxCircle.dbx" /INCREMENTAL /ILK:"x64\Debug\dbxCircle.ilk" /NOLOGO /LIBPATH:"D:\ArxSDKs\arx2024\Lib-x64" ac1st24.lib acad.lib acapp.lib acapp_crx
  .lib AcCamera.lib accore.lib acdb24.lib acdbmgd.lib AcDbPointCloudObj.lib AcDrawBridge.lib AcFdEval.lib AcFdUi.lib acge24.lib AcGeolocationObj.lib acgeoment.lib acgiapi.lib acismobj24.lib AcJsCoreStub_crx.lib aclmvexport_crx.lib acModelDocObj.lib AcMPolygonObj.lib AcPal.lib Ac
  Publish_crx.lib AcSceneOE.lib AcTc.lib AcTcUi.lib acui24.lib AdApplicationFrame.lib adui24.lib aNav.lib axdb.lib rxapi.lib userdata.lib /DEF:"D:\ArxSDKs\arx2024\inc\AcRxDefault.def" /MANIFEST /MANIFESTUAC:"level='asInvoker' uiAccess='false'" /manifest:embed /manifestinput:C:\V
  S2022\VC\Tools\MSVC\14.40.33807\Include\Manifest\dpiaware.manifest /DEBUG /PDB:"D:\Work\Projects\2024\ManagedCircle\x64\Debug\dbxCircle.pdb" /SUBSYSTEM:WINDOWS /TLBID:1 /DYNAMICBASE /NXCOMPAT /IMPLIB:"D:\Work\Projects\2024\ManagedCircle\x64\Debug\dbxCircle.lib" /MACHINE:X64 /D
  LL x64\Debug\dbxCircle.res
  x64\Debug\acrxEntryPoint.obj
  x64\Debug\asdkCustomCircle.obj
  x64\Debug\dbxCircle.obj
  x64\Debug\StdAfx.obj
     Creating library D:\Work\Projects\2024\ManagedCircle\x64\Debug\dbxCircle.lib and object D:\Work\Projects\2024\ManagedCircle\x64\Debug\dbxCircle.exp
rxapi.lib(libinit.obj) : warning LNK4099: PDB '' was not found with 'rxapi.lib(libinit.obj)' or at ''; linking object as if no debug info [D:\Work\Projects\2024\ManagedCircle\dbxCircle\dbxCircle.vcxproj]
  dbxCircle.vcxproj -> D:\Work\Projects\2024\ManagedCircle\x64\Debug\dbxCircle.dbx
FinalizeBuildStatus:
  Deleting file "x64\Debug\dbxCircle.tlog\unsuccessfulbuild".
  Touching "x64\Debug\dbxCircle.tlog\dbxCircle.lastbuildstate".
Done Building Project "D:\Work\Projects\2024\ManagedCircle\dbxCircle\dbxCircle.vcxproj" (default targets).

Project "D:\Work\Projects\2024\ManagedCircle\ArxProject1\ArxProject1.vcxproj.metaproj" (2) is building "D:\Work\Projects\2024\ManagedCircle\ArxProject1\ArxProject1.vcxproj" (4) on node 1 (default targets).
PrepareForBuild:
  Structured output is enabled. The formatting of compiler diagnostics will reflect the error hierarchy. See https://aka.ms/cpp/structured-output for more details.
InitializeBuildStatus:
  Creating "x64\Debug\ArxProject1.tlog\unsuccessfulbuild" because "AlwaysCreate" was specified.
  Touching "x64\Debug\ArxProject1.tlog\unsuccessfulbuild".
ClCompile:
  C:\VS2022\VC\Tools\MSVC\14.40.33807\bin\HostX64\x64\CL.exe /c /ID:\ArxSDKs\arx2024\inc /I"D:\ArxSDKs\arx2024\inc-x64" /AI"D:\ACAD\ursa\AutoCAD 2024" /Zi /nologo /W1 /WX- /diagnostics:column /Od /D _WIN64 /D _WINDOWS /D ARXPROJECT1_MODULE /D _ACRXAPP /D _WINDLL /D _UNICODE /D U
  NICODE /D _AFXDLL /GF- /Gm- /EHsc /RTC1 /MD /GS /fp:precise /Zc:wchar_t /Zc:forScope /Zc:inline /GR /Yc"stdafx.h" /Fp"x64\Debug\ArxProject1.pch" /Fo"x64\Debug\\" /Fd"x64\Debug\vc143.pdb" /external:W1 /Gd /TP /FC /errorReport:queue StdAfx.cpp
  StdAfx.cpp
  C:\VS2022\VC\Tools\MSVC\14.40.33807\bin\HostX64\x64\CL.exe /c /ID:\ArxSDKs\arx2024\inc /I"D:\ArxSDKs\arx2024\inc-x64" /AI"D:\ACAD\ursa\AutoCAD 2024" /Zi /nologo /W1 /WX- /diagnostics:column /Od /D _WIN64 /D _WINDOWS /D ARXPROJECT1_MODULE /D _ACRXAPP /D _WINDLL /D _UNICODE /D U
  NICODE /D _AFXDLL /GF- /Gm- /EHsc /RTC1 /MD /GS /fp:precise /Zc:wchar_t /Zc:forScope /Zc:inline /GR /Yu"stdafx.h" /Fp"x64\Debug\ArxProject1.pch" /Fo"x64\Debug\\" /Fd"x64\Debug\vc143.pdb" /external:W1 /Gd /TP /FC /errorReport:queue acrxEntryPoint.cpp ArxProject1.cpp
  acrxEntryPoint.cpp
  ArxProject1.cpp
  Generating Code...
ResourceCompile:
  C:\Program Files (x86)\Windows Kits\10\bin\10.0.22621.0\x64\rc.exe /D _UNICODE /D UNICODE /D _AFXDLL /l"0x0409" /Ix64\Debug\ /nologo /fo"x64\Debug\ArxProject1.res" ArxProject1.rc
Link:
  C:\VS2022\VC\Tools\MSVC\14.40.33807\bin\HostX64\x64\link.exe /ERRORREPORT:QUEUE /OUT:"D:\Work\Projects\2024\ManagedCircle\x64\Debug\ArxProject1.arx" /INCREMENTAL /ILK:"x64\Debug\ArxProject1.ilk" /NOLOGO /LIBPATH:D:\Work\Projects\2024\ManagedCircle\x64\Debug\ /LIBPATH:"D:\ArxSD
  Ks\arx2024\Lib-x64" dbxCircle.lib accore.lib ac1st24.lib acdb24.lib acad.lib acapp.lib rxapi.lib acapp_crx.lib acge24.lib acgiapi.lib acismobj24.lib axdb.lib acpal.lib ac1st24.lib acad.lib acapp.lib acapp_crx.lib AcCamera.lib accore.lib acdb24.lib acdbmgd.lib AcDbPointCloudObj
  .lib AcDrawBridge.lib AcFdEval.lib AcFdUi.lib acge24.lib AcGeolocationObj.lib acgeoment.lib acgiapi.lib acismobj24.lib AcJsCoreStub_crx.lib aclmvexport_crx.lib acModelDocObj.lib AcMPolygonObj.lib AcPal.lib AcPublish_crx.lib AcSceneOE.lib AcTc.lib AcTcUi.lib acui24.lib AdApplic
  ationFrame.lib adui24.lib aNav.lib axdb.lib rxapi.lib userdata.lib /DEF:"D:\ArxSDKs\arx2024\inc\AcRxDefault.def" /MANIFEST /MANIFESTUAC:"level='asInvoker' uiAccess='false'" /manifest:embed /manifestinput:C:\VS2022\VC\Tools\MSVC\14.40.33807\Include\Manifest\dpiaware.manifest /D
  EBUG /PDB:"D:\Work\Projects\2024\ManagedCircle\x64\Debug\ArxProject1.pdb" /SUBSYSTEM:WINDOWS /TLBID:1 /DYNAMICBASE /NXCOMPAT /IMPLIB:"D:\Work\Projects\2024\ManagedCircle\x64\Debug\ArxProject1.lib" /MACHINE:X64 /DLL x64\Debug\ArxProject1.res
  x64\Debug\acrxEntryPoint.obj
  x64\Debug\ArxProject1.obj
  x64\Debug\StdAfx.obj
     Creating library D:\Work\Projects\2024\ManagedCircle\x64\Debug\ArxProject1.lib and object D:\Work\Projects\2024\ManagedCircle\x64\Debug\ArxProject1.exp
rxapi.lib(libinit.obj) : warning LNK4099: PDB '' was not found with 'rxapi.lib(libinit.obj)' or at ''; linking object as if no debug info [D:\Work\Projects\2024\ManagedCircle\ArxProject1\ArxProject1.vcxproj]
  ArxProject1.vcxproj -> D:\Work\Projects\2024\ManagedCircle\x64\Debug\ArxProject1.arx
FinalizeBuildStatus:
  Deleting file "x64\Debug\ArxProject1.tlog\unsuccessfulbuild".
  Touching "x64\Debug\ArxProject1.tlog\ArxProject1.lastbuildstate".
Done Building Project "D:\Work\Projects\2024\ManagedCircle\ArxProject1\ArxProject1.vcxproj" (default targets).

Done Building Project "D:\Work\Projects\2024\ManagedCircle\ArxProject1\ArxProject1.vcxproj.metaproj" (default targets).

Project "D:\Work\Projects\2024\ManagedCircle\ArxProject1.sln" (1) is building "D:\Work\Projects\2024\ManagedCircle\DotProject1\ManagedTest.csproj.metaproj" (5) on node 1 (default targets).
Project "D:\Work\Projects\2024\ManagedCircle\DotProject1\ManagedTest.csproj.metaproj" (5) is building "D:\Work\Projects\2024\ManagedCircle\ManagedWrapper\ManagedWrapper.vcxproj.metaproj" (6) on node 1 (default targets).
Project "D:\Work\Projects\2024\ManagedCircle\ManagedWrapper\ManagedWrapper.vcxproj.metaproj" (6) is building "D:\Work\Projects\2024\ManagedCircle\ManagedWrapper\ManagedWrapper.vcxproj" (7) on node 1 (default targets).
PrepareForBuild:
  Structured output is enabled. The formatting of compiler diagnostics will reflect the error hierarchy. See https://aka.ms/cpp/structured-output for more details.
InitializeBuildStatus:
  Creating "x64\Debug\ManagedWrapper.tlog\unsuccessfulbuild" because "AlwaysCreate" was specified.
  Touching "x64\Debug\ManagedWrapper.tlog\unsuccessfulbuild".
GenerateTargetFrameworkMonikerAttribute:
Skipping target "GenerateTargetFrameworkMonikerAttribute" because all output files are up-to-date with respect to the input files.
ClCompile:
  C:\VS2022\VC\Tools\MSVC\14.40.33807\bin\HostX64\x64\CL.exe /c /ID:\ArxSDKs\arx2024\inc /I"D:\ArxSDKs\arx2024\inc-x64" /AI"C:\Program Files (x86)\Reference Assemblies\Microsoft\Framework\.NETFramework\v4.8\\" /AI"C:\Program Files (x86)\Windows Kits\10\References" /AI"C:\Program
   Files (x86)\Reference Assemblies\Microsoft\Framework\.NETFramework\v4.8\Facades\\" /AI"D:\ACAD\ursa\AutoCAD 2024" /AI"D:\ACAD\ursa\AutoCAD 2024" /Zi /clr /nologo /W1 /WX- /diagnostics:column /Od /D _WIN64 /D _WINDOWS /D MANAGEDWRAPPER_MODULE /D _ACRXAPP /D _WINDLL /D _UNICODE
   /D UNICODE /D _AFXDLL /GF- /Gm- /EHa /MD /GS /fp:precise /Zc:wchar_t /Zc:forScope /Zc:inline /GR /Yc"stdafx.h" /Fp"x64\Debug\ManagedWrapper.pch" /Fo"x64\Debug\\" /Fd"x64\Debug\vc143.pdb" /external:W1 /TP /FU"C:\Program Files (x86)\Reference Assemblies\Microsoft\Framework\.NET
  Framework\v4.8\mscorlib.dll" /FU"C:\Program Files (x86)\Reference Assemblies\Microsoft\Framework\.NETFramework\v4.8\System.Core.dll" /FC /errorReport:queue /clr:nostdlib StdAfx.cpp
  StdAfx.cpp
  C:\VS2022\VC\Tools\MSVC\14.40.33807\bin\HostX64\x64\CL.exe /c /ID:\ArxSDKs\arx2024\inc /I"D:\ArxSDKs\arx2024\inc-x64" /AI"C:\Program Files (x86)\Reference Assemblies\Microsoft\Framework\.NETFramework\v4.8\\" /AI"C:\Program Files (x86)\Windows Kits\10\References" /AI"C:\Program
   Files (x86)\Reference Assemblies\Microsoft\Framework\.NETFramework\v4.8\Facades\\" /AI"D:\ACAD\ursa\AutoCAD 2024" /AI"D:\ACAD\ursa\AutoCAD 2024" /Zi /clr /nologo /W1 /WX- /diagnostics:column /Od /D _WIN64 /D _WINDOWS /D MANAGEDWRAPPER_MODULE /D _ACRXAPP /D _WINDLL /D _UNICODE
   /D UNICODE /D _AFXDLL /GF- /Gm- /EHa /MD /GS /fp:precise /Zc:wchar_t /Zc:forScope /Zc:inline /GR /Yu"stdafx.h" /Fp"x64\Debug\ManagedWrapper.pch" /Fo"x64\Debug\\" /Fd"x64\Debug\vc143.pdb" /external:W1 /TP /FU"C:\Program Files (x86)\Reference Assemblies\Microsoft\Framework\.NET
  Framework\v4.8\mscorlib.dll" /FU"C:\Program Files (x86)\Reference Assemblies\Microsoft\Framework\.NETFramework\v4.8\System.Core.dll" /FC /errorReport:queue /clr:nostdlib acrxEntryPoint.cpp asdkCustomCircleMgd.cpp AssemblyInfo.cpp ManagedWrapper.cpp
  acrxEntryPoint.cpp
  asdkCustomCircleMgd.cpp
  AssemblyInfo.cpp
  ManagedWrapper.cpp
  Generating Code...
  C:\VS2022\VC\Tools\MSVC\14.40.33807\bin\HostX64\x64\CL.exe /c /ID:\ArxSDKs\arx2024\inc /I"D:\ArxSDKs\arx2024\inc-x64" /AI"C:\Program Files (x86)\Reference Assemblies\Microsoft\Framework\.NETFramework\v4.8\\" /AI"C:\Program Files (x86)\Windows Kits\10\References" /AI"C:\Program
   Files (x86)\Reference Assemblies\Microsoft\Framework\.NETFramework\v4.8\Facades\\" /AI"D:\ACAD\ursa\AutoCAD 2024" /AI"D:\ACAD\ursa\AutoCAD 2024" /Zi /clr /nologo /W1 /WX- /diagnostics:column /Od /D _WIN64 /D _WINDOWS /D MANAGEDWRAPPER_MODULE /D _ACRXAPP /D _WINDLL /D _UNICODE
   /D UNICODE /D _AFXDLL /GF- /Gm- /EHa /MD /GS /fp:precise /Zc:wchar_t /Zc:forScope /Zc:inline /GR /Fo"x64\Debug\\" /Fd"x64\Debug\vc143.pdb" /external:W1 /TP /FU"C:\Program Files (x86)\Reference Assemblies\Microsoft\Framework\.NETFramework\v4.8\mscorlib.dll" /FU"C:\Program File
  s (x86)\Reference Assemblies\Microsoft\Framework\.NETFramework\v4.8\System.Core.dll" /FC /errorReport:queue /clr:nostdlib "x64\Debug\.NETFramework,Version=v4.8.AssemblyAttributes.cpp"
  .NETFramework,Version=v4.8.AssemblyAttributes.cpp
ResourceCompile:
  C:\Program Files (x86)\Windows Kits\10\bin\10.0.22621.0\x64\rc.exe /D _UNICODE /D UNICODE /D _AFXDLL /l"0x0409" /Ix64\Debug\ /nologo /fo"x64\Debug\ManagedWrapper.res" ManagedWrapper.rc
Link:
  C:\VS2022\VC\Tools\MSVC\14.40.33807\bin\HostX64\x64\link.exe /ERRORREPORT:QUEUE /OUT:"D:\Work\Projects\2024\ManagedCircle\x64\Debug\ManagedWrapper.dll" /INCREMENTAL /ILK:"x64\Debug\ManagedWrapper.ilk" /NOLOGO /LIBPATH:D:\Work\Projects\2024\ManagedCircle\x64\Debug\ /LIBPATH:"D:
  \ArxSDKs\arx2024\Lib-x64" dbxCircle.lib ac1st24.lib acad.lib acapp.lib acapp_crx.lib AcCamera.lib accore.lib acdb24.lib acdbmgd.lib AcDbPointCloudObj.lib AcDrawBridge.lib AcFdEval.lib AcFdUi.lib acge24.lib AcGeolocationObj.lib acgeoment.lib acgiapi.lib acismobj24.lib AcJsCoreS
  tub_crx.lib aclmvexport_crx.lib acModelDocObj.lib AcMPolygonObj.lib AcPal.lib AcPublish_crx.lib AcSceneOE.lib AcTc.lib AcTcUi.lib acui24.lib AdApplicationFrame.lib adui24.lib aNav.lib axdb.lib rxapi.lib userdata.lib /DEF:"D:\ArxSDKs\arx2024\inc\AcRxDefault.def" /MANIFEST /MANI
  FESTUAC:"level='asInvoker' uiAccess='false'" /manifest:embed /manifestinput:C:\VS2022\VC\Tools\MSVC\14.40.33807\Include\Manifest\dpiaware.manifest /DEBUG /PDB:"D:\Work\Projects\2024\ManagedCircle\x64\Debug\ManagedWrapper.pdb" /SUBSYSTEM:WINDOWS /TLBID:1 /DYNAMICBASE /FIXED:NO
  /NXCOMPAT /IMPLIB:"D:\Work\Projects\2024\ManagedCircle\x64\Debug\ManagedWrapper.lib" /MACHINE:X64 /DLL x64\Debug\ManagedWrapper.res
  x64\Debug\acrxEntryPoint.obj
  x64\Debug\asdkCustomCircleMgd.obj
  x64\Debug\AssemblyInfo.obj
  x64\Debug\ManagedWrapper.obj
  x64\Debug\StdAfx.obj
  "x64\Debug\.NETFramework,Version=v4.8.AssemblyAttributes.obj"
  acrxEntryPoint.obj : MSIL module encountered; incremental linking is disabled for MSIL; performing full link
rxapi.lib(rxReferencedModules.obj) : warning LNK4099: PDB '' was not found with 'rxapi.lib(rxReferencedModules.obj)' or at ''; linking object as if no debug info [D:\Work\Projects\2024\ManagedCircle\ManagedWrapper\ManagedWrapper.vcxproj]
     Creating library D:\Work\Projects\2024\ManagedCircle\x64\Debug\ManagedWrapper.lib and object D:\Work\Projects\2024\ManagedCircle\x64\Debug\ManagedWrapper.exp
rxapi.lib(libinit.obj) : warning LNK4099: PDB '' was not found with 'rxapi.lib(libinit.obj)' or at ''; linking object as if no debug info [D:\Work\Projects\2024\ManagedCircle\ManagedWrapper\ManagedWrapper.vcxproj]
  ManagedWrapper.vcxproj -> D:\Work\Projects\2024\ManagedCircle\x64\Debug\ManagedWrapper.dll
FinalizeBuildStatus:
  Deleting file "x64\Debug\ManagedWrapper.tlog\unsuccessfulbuild".
  Touching "x64\Debug\ManagedWrapper.tlog\ManagedWrapper.lastbuildstate".
Done Building Project "D:\Work\Projects\2024\ManagedCircle\ManagedWrapper\ManagedWrapper.vcxproj" (default targets).

Done Building Project "D:\Work\Projects\2024\ManagedCircle\ManagedWrapper\ManagedWrapper.vcxproj.metaproj" (default targets).

Project "D:\Work\Projects\2024\ManagedCircle\DotProject1\ManagedTest.csproj.metaproj" (5) is building "D:\Work\Projects\2024\ManagedCircle\DotProject1\ManagedTest.csproj" (8) on node 1 (default targets).
GenerateTargetFrameworkMonikerAttribute:
Skipping target "GenerateTargetFrameworkMonikerAttribute" because all output files are up-to-date with respect to the input files.
CoreCompile:
  C:\VS2022\MSBuild\Current\Bin\Roslyn\csc.exe /noconfig /nowarn:1701,1702 /fullpaths /nostdlib+ /platform:x64 /errorreport:prompt /define:DEBUG;TRACE /highentropyva+ /reference:"D:\ACAD\ursa\AutoCAD 2024\accoremgd.dll" /reference:"D:\ACAD\ursa\AutoCAD 2024\acdbmgd.dll" /referen
  ce:D:\Work\Projects\2024\ManagedCircle\x64\Debug\ManagedWrapper.dll /reference:"C:\Program Files (x86)\Reference Assemblies\Microsoft\Framework\.NETFramework\v4.8\mscorlib.dll" /reference:"C:\Program Files (x86)\Reference Assemblies\Microsoft\Framework\.NETFramework\v4.8\Syste
  m.Core.dll" /reference:"C:\Program Files (x86)\Reference Assemblies\Microsoft\Framework\.NETFramework\v4.8\System.dll" /debug+ /debug:full /filealign:512 /out:obj\x64\Debug\ManagedTest.dll /ruleset:"C:\VS2022\Team Tools\Static Analysis Tools\\Rule Sets\MinimumRecommendedRules.
  ruleset" /subsystemversion:6.00 /target:library /utf8output /langversion:7.3 Commands.cs Properties\AssemblyInfo.cs "obj\x64\Debug\.NETFramework,Version=v4.8.AssemblyAttributes.cs"
  CompilerServer: server - server processed compilation - ManagedTest
_CopyFilesMarkedCopyLocal:
  Copying file from "D:\Work\Projects\2024\ManagedCircle\x64\Debug\ManagedWrapper.dll" to "D:\Work\Projects\2024\ManagedCircle\DotProject1\bin\x64\Debug\ManagedWrapper.dll".
  Copying file from "D:\Work\Projects\2024\ManagedCircle\x64\Debug\ManagedWrapper.pdb" to "D:\Work\Projects\2024\ManagedCircle\DotProject1\bin\x64\Debug\ManagedWrapper.pdb".
  Creating "D:\Work\Projects\2024\ManagedCircle\DotProject1\obj\x64\Debug\ManagedT.098774B7.Up2Date" because "AlwaysCreate" was specified.
  Touching "D:\Work\Projects\2024\ManagedCircle\DotProject1\obj\x64\Debug\ManagedT.098774B7.Up2Date".
CopyFilesToOutputDirectory:
  Copying file from "D:\Work\Projects\2024\ManagedCircle\DotProject1\obj\x64\Debug\ManagedTest.dll" to "D:\Work\Projects\2024\ManagedCircle\DotProject1\bin\x64\Debug\ManagedTest.dll".
  ManagedTest -> D:\Work\Projects\2024\ManagedCircle\DotProject1\bin\x64\Debug\ManagedTest.dll
  Copying file from "D:\Work\Projects\2024\ManagedCircle\DotProject1\obj\x64\Debug\ManagedTest.pdb" to "D:\Work\Projects\2024\ManagedCircle\DotProject1\bin\x64\Debug\ManagedTest.pdb".
PostBuildEvent:
  xcopy D:\Work\Projects\2024\ManagedCircle\DotProject1\bin\x64\Debug\ManagedTest.dll D:\Work\Projects\2024\ManagedCircle\x64\Debug /y
  D:\Work\Projects\2024\ManagedCircle\DotProject1\bin\x64\Debug\ManagedTest.dll
  1 File(s) copied
Done Building Project "D:\Work\Projects\2024\ManagedCircle\DotProject1\ManagedTest.csproj" (default targets).

Done Building Project "D:\Work\Projects\2024\ManagedCircle\DotProject1\ManagedTest.csproj.metaproj" (default targets).

Done Building Project "D:\Work\Projects\2024\ManagedCircle\ArxProject1.sln" (build target(s)).


Build succeeded.

"D:\Work\Projects\2024\ManagedCircle\ArxProject1.sln" (build target) (1) ->
"D:\Work\Projects\2024\ManagedCircle\ArxProject1\ArxProject1.vcxproj.metaproj" (default target) (2) ->
"D:\Work\Projects\2024\ManagedCircle\dbxCircle\dbxCircle.vcxproj" (default target) (3) ->
(Link target) ->
  rxapi.lib(libinit.obj) : warning LNK4099: PDB '' was not found with 'rxapi.lib(libinit.obj)' or at ''; linking object as if no debug info [D:\Work\Projects\2024\ManagedCircle\dbxCircle\dbxCircle.vcxproj]


"D:\Work\Projects\2024\ManagedCircle\ArxProject1.sln" (build target) (1) ->
"D:\Work\Projects\2024\ManagedCircle\ArxProject1\ArxProject1.vcxproj.metaproj" (default target) (2) ->
"D:\Work\Projects\2024\ManagedCircle\ArxProject1\ArxProject1.vcxproj" (default target) (4) ->
  rxapi.lib(libinit.obj) : warning LNK4099: PDB '' was not found with 'rxapi.lib(libinit.obj)' or at ''; linking object as if no debug info [D:\Work\Projects\2024\ManagedCircle\ArxProject1\ArxProject1.vcxproj]


"D:\Work\Projects\2024\ManagedCircle\ArxProject1.sln" (build target) (1) ->
"D:\Work\Projects\2024\ManagedCircle\DotProject1\ManagedTest.csproj.metaproj" (default target) (5) ->
"D:\Work\Projects\2024\ManagedCircle\ManagedWrapper\ManagedWrapper.vcxproj.metaproj" (default target) (6) ->
"D:\Work\Projects\2024\ManagedCircle\ManagedWrapper\ManagedWrapper.vcxproj" (default target) (7) ->
  rxapi.lib(rxReferencedModules.obj) : warning LNK4099: PDB '' was not found with 'rxapi.lib(rxReferencedModules.obj)' or at ''; linking object as if no debug info [D:\Work\Projects\2024\ManagedCircle\ManagedWrapper\ManagedWrapper.vcxproj]
  rxapi.lib(libinit.obj) : warning LNK4099: PDB '' was not found with 'rxapi.lib(libinit.obj)' or at ''; linking object as if no debug info [D:\Work\Projects\2024\ManagedCircle\ManagedWrapper\ManagedWrapper.vcxproj]
```

## To Use

```bash
appload "ManagedCircle\x64\Debug\dbxCircle.dbx"
appload "ManagedCircle\x64\Debug\ArxProject1.arx"
netload "ManagedCircle\x64\Debug\ManagedTest.dll"
```

## Testing

```bash
ADDCUSTCIRCLE
    This creates a custom circle using ARX command
GETOBJECTMNG
    This is .NET command that identifies a custom circle and changes its color.
```

## Written by

Madhukar Moogala (Forge Partner Development)
@galakar
http://forge.autodesk.com
