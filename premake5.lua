workspace "WinBuds"
   configurations {"Debug", "Release", "Deployment"}
   platforms { "32", "64" }
   cppdialect "C++17"

project "WinBuds"
   kind "ConsoleApp"
   language "C++"

   targetdir "build/%{cfg.buildcfg}"
   objdir "build-int/"
   files { "src/*.h", "src/*.cpp" }

   filter "system:windows"


   configuration "windows"
      files {"src/Platforms/Windows/**.h", "src/Platforms/Windows/**.cpp"}
      links{"Bthprops.lib", "ws2_32.lib"}

   configuration "macosx"
      files {"src/Platforms/Mac/**.h", "src/Platforms/Mac/**.cpp"}

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"
 
   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"  

   filter "configurations:Deployment"
      defines { "DEPLOYMENT" }
      optimize "On"

   filter "platforms:32"
      architecture "x32"
  
    filter "platforms:64"
      architecture "x64"