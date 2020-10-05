# Managed Wrapper Example ObjectARX

![ObjectARX2021](https://img.shields.io/badge/ObjectARX-2021-brightgreen.svg)
![BuildPassing](https://img.shields.io/badge/build-passing-brightgreen.svg)
![AutoCAD2021](https://img.shields.io/badge/AutoCAD-2021-blue.svg)

This sample is created with [ObjectARX Wizard](https://github.com/ADN-DevTech/ObjectARX-Wizards/tree/ForAutoCAD2021) to show how to create a Managed Wrapper .NET API to AutoCAD
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
1>------ Build started: Project: dbxCircle, Configuration: Debug x64 ------
1>Not using Vcpkg because VcpkgEnabled is "false"
1>StdAfx.cpp
1>acrxEntryPoint.cpp
1>asdkCustomCircle.cpp
1>dbxCircle.cpp
1>Generating Code...
1>   Creating library D:\Work\Arxprojects\2021\ManagedCircle\x64\Debug\dbxCircle.lib and object D:\Work\Arxprojects\2021\ManagedCircle\x64\Debug\dbxCircle.exp
1>rxapi.lib(libinit.obj) : warning LNK4099: PDB 'rxapi.pdb' was not found with 'rxapi.lib(libinit.obj)' or at 'D:\Work\Arxprojects\2021\ManagedCircle\x64\Debug\rxapi.pdb'; linking object as if no debug info
1>dbxCircle.vcxproj -> D:\Work\Arxprojects\2021\ManagedCircle\x64\Debug\dbxCircle.dbx
1>Done building project "dbxCircle.vcxproj".
2>------ Build started: Project: ArxProject1, Configuration: Debug x64 ------
2>Not using Vcpkg because VcpkgEnabled is "false"
2>StdAfx.cpp
2>acrxEntryPoint.cpp
2>ArxProject1.cpp
2>Generating Code...
2>   Creating library D:\Work\Arxprojects\2021\ManagedCircle\x64\Debug\ArxProject1.lib and object D:\Work\Arxprojects\2021\ManagedCircle\x64\Debug\ArxProject1.exp
2>rxapi.lib(libinit.obj) : warning LNK4099: PDB 'rxapi.pdb' was not found with 'rxapi.lib(libinit.obj)' or at 'D:\Work\Arxprojects\2021\ManagedCircle\x64\Debug\rxapi.pdb'; linking object as if no debug info
2>ArxProject1.vcxproj -> D:\Work\Arxprojects\2021\ManagedCircle\x64\Debug\ArxProject1.arx
2>Done building project "ArxProject1.vcxproj".
3>------ Build started: Project: ManagedWrapper, Configuration: Debug x64 ------
3>Not using Vcpkg because VcpkgEnabled is "false"
3>StdAfx.cpp
3>acrxEntryPoint.cpp
3>asdkCustomCircleMgd.cpp
3>AssemblyInfo.cpp
3>ManagedWrapper.cpp
3>Generating Code...
3>.NETFramework,Version=v4.7.AssemblyAttributes.cpp
3>acrxEntryPoint.obj : MSIL module encountered; incremental linking is disabled for MSIL; performing full link
3>   Creating library D:\Work\Arxprojects\2021\ManagedCircle\x64\Debug\ManagedWrapper.lib and object D:\Work\Arxprojects\2021\ManagedCircle\x64\Debug\ManagedWrapper.exp
3>rxapi.lib(libinit.obj) : warning LNK4099: PDB 'rxapi.pdb' was not found with 'rxapi.lib(libinit.obj)' or at 'D:\Work\Arxprojects\2021\ManagedCircle\x64\Debug\rxapi.pdb'; linking object as if no debug info
3>ManagedWrapper.vcxproj -> D:\Work\Arxprojects\2021\ManagedCircle\x64\Debug\ManagedWrapper.dll
3>Done building project "ManagedWrapper.vcxproj".
4>------ Build started: Project: ManagedTest, Configuration: Debug x64 ------
========== Build: 4 succeeded, 0 failed, 0 up-to-date, 0 skipped ==========
```

## To Use
appload ManagedCircle\x64\Debug\dbxCircle.dbx
appload ManagedCircle\x64\Debug\ArxProject1.arx
netload ManagedCircle\x64\Debug\ManagedTest.dll

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







