# Managed Wrapper Example ObjectARX

![ObjectARX2025](https://img.shields.io/badge/ObjectARX-2025-brightgreen.svg)
![BuildPassed](https://img.shields.io/badge/build-passed-brightgreen.svg)
![AutoCAD2025](https://img.shields.io/badge/AutoCAD-2025-blue.svg)

This sample demonstrates how to create a Managed Wrapper .NET API to AutoCAD
C++ API, in this example we extend to API `asdkCustomCircleMgd::setCenter` and `asdkCustomCircleMgd::setRadius`

For previous projects using NET 4.x framework, switch to `ACAD2024/NET4x` branch

## Migrating C++/CLI Project from .NET 4.x to NET 8.0

1. **Update the .vcxproj File**:
   
   - Replace `<CLRSupport>true</CLRSupport>` properties with `<CLRSupport>NetCore</CLRSupport>`.
   - Replace `<TargetFrameworkVersion>` properties with `<TargetFramework>net8.0</TargetFramework>`.

2. **Remove .NET Framework References**:
   
   - Remove any references to `System`, `System.Core`,`System.Data`, `System.Windows.Forms`, and `System.Xml` from your project.

3. **Update API Usage**:
   
   - Review your .cpp files and update any APIs that are unavailable in .NET.

4. **WPF and Windows Forms Usage**:
   
   - C++/CLI projects can use Windows Forms and WPF APIs.
   - Add explicit framework references to the UI libraries.
   
   To use Windows Forms APIs, add this reference to the *.vcxproj* file:   
   
   ```xml
   <!-- Reference all of Windows Forms -->
   <FrameworkReference Include="Microsoft.WindowsDesktop.App.WindowsForms" />
   ```
   
   To use WPF APIs, add this reference to the *.vcxproj* file:
   
   ```xml
   <!-- Reference all of WPF -->
   <FrameworkReference Include="Microsoft.WindowsDesktop.App.WPF" />
   ```
   
   To use both Windows Forms and WPF APIs, add this reference to the *.vcxproj* file:
   
   ```xml
   <!-- Reference the entirety of the Windows desktop framework:     Windows Forms, WPF, and the types that provide integration between them -->
   <FrameworkReference Include="Microsoft.WindowsDesktop.App" />
   ```

Remember that there are some limitations when migrating C++/CLI projects to .NET Core, such as not being able to compile to an executable directly and Windows-only support for C++/CLI. [Make sure to check the documentation for more details](https://learn.microsoft.com/en-us/dotnet/core/porting/cpp-cli)

5. **Upgrading a .NET 4.x Project to .NET 8.0**
   
   1. **Open the Project File:**
      
      - In Visual Studio, navigate to Solution Explorer.
      
      - Right-click on the `ManagedTest` project and select "Upgrade"
        
        Refer: How to use [upgrade assistant]([Overview of the .NET Upgrade Assistant - .NET Core | Microsoft Learn](https://learn.microsoft.com/en-us/dotnet/core/porting/upgrade-assistant-overview?WT.mc_id=dotnet-35129-website))
   
   2. **Update the Project Configuration:**
      
      - Locate the `<TargetFramework>` property and change its value to `net8.0-windows`. This specifies that the project targets the latest .NET 8.0 framework for Windows.
      - Find the `<Platforms>` property and set it to `x64`. This indicates that the project is built for the 64-bit architecture.
   
   3. **Configure Assembly Search Paths:**
      
      - Locate the `<AssemblySearchPaths>` property (it might not exist yet).
      - Add the path to your ObjectARX SDK directory within the property's value. This ensures that .NET references from the SDK are found during compilation. Here's an example structure:
      
      XML
      
      ```
      <AssemblySearchPaths>$(OutDir);$(ReferencePath);C:\Path\To\Your\ObjectARX\SDK</AssemblySearchPaths>
      ```

      - Replace `C:\Path\To\Your\ObjectARX\SDK` with the actual path to your ObjectARX SDK installation.

4. **Optional: Update Root Namespace (if necessary):**
   
   - If your project uses a specific root namespace to organize its files, locate the `<RootNamespace>` property and ensure it matches your project directory name.

5. **Save the Project File:**
   
   - Save the changes made to the project file (`ManagedTest.csproj`).

```xml
<?xml version="1.0" encoding="utf-8"?>
<Project Sdk="Microsoft.NET.Sdk">
    <PropertyGroup>
        <OutputType>Library</OutputType>
        <RootNamespace>ManagedTest</RootNamespace>     
        <TargetFramework>net8.0-windows</TargetFramework>
        <GenerateAssemblyInfo>false</GenerateAssemblyInfo>
        <ObjectARXPATH Condition="'$(ObjectARXPATH)' == ''">D:\ArxSdks\arx2025</ObjectARXPATH>
        <AssemblySearchPaths>$(ObjectARXPATH)\inc\;$(AssemblySearchPaths)</AssemblySearchPaths>
        <Platforms>x64</Platforms>
    </PropertyGroup>
    <ItemGroup>
        <FrameworkReference Include="Microsoft.WindowsDesktop.App"/>
    </ItemGroup>
    <ItemGroup>
      <ProjectReference Include="..\ManagedWrapper\ManagedWrapper.vcxproj" />
    </ItemGroup>
    <ItemGroup>
        <Reference Include="AcDbMgd">
            <Private>False</Private>
        </Reference>
        <Reference Include="AcMgd">
            <Private>False</Private>
        </Reference>
        <Reference Include="AcCoreMgd">
            <Private>False</Private>
        </Reference>
    </ItemGroup>   
</Project> 
```

## Demo

![DemoImage](https://github.com/MadhukarMoogala/ManagedCircle/blob/master/Demo.gif)

## Step To Build

```
git clone https://github.com/MadhukarMoogala/ManagedCircle.git
cd ManagedCircle
set ObjectARXPATH=<arxsdkpath>
set AcadDir=<AutoCAD Install Folder>
msbuild /t:build /verbosity:minimal
```

Expected Build Log

```bash
MSBuild version 17.10.4+10fbfbf2e for .NET Framework

  dbxCircle.vcxproj -> D:\Work\Projects\2024\ManagedCircle\x64\Debug\dbxCircle.dbx
  ArxProject1.vcxproj -> D:\Work\Projects\2024\ManagedCircle\x64\Debug\ArxProject1.arx
  ManagedWrapper.vcxproj -> D:\Work\Projects\2024\ManagedCircle\x64\Debug\ManagedWrapper.dll
  ManagedTest -> D:\Work\Projects\2024\ManagedCircle\ManagedTest\bin\x64\Debug\net8.0-windows\ManagedTest.dll
  Copying ManagedTest.dll to D:\Work\Projects\2024\ManagedCircle\x64\Debug
  --------------------------------------Congrats-------------------------------------
  Now load following modules in specified order in AutoCAD
                          1) appload D:\Work\Projects\2024\ManagedCircle\x64\Debug\dbxCircle.dbx
                          2) appload D:\Work\Projects\2024\ManagedCircle\x64\Debug\ArxProject1.arx
                          3) NETLOAD D:\Work\Projects\2024\ManagedCircle\x64\Debug\ManagedTest.dll
  To create a custom circle run arx based command ADDCUSTCIRCLE in AutoCAD Commandline,
          to identify a custom circle and change it's color run .NET core based command GETOBJECTMNG in AutoCAD Commandline
  ---------------------------------------Done!----------------------------------------
```

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
