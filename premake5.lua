workspace "WinBuds"
   configurations {"Debug", "Release", "Deployment"}
   platforms { "32", "64" }
   cppdialect "C++17"

project "WinBuds"
   kind "ConsoleApp"
   language "C++"

   targetdir "build/%{cfg.buildcfg}"
   objdir "build-int/"
   files { "src/**.h", "src/**.cpp" }
   characterset ("ASCII")

   links{
      "Bthprops.lib",
      "ws2_32.lib"
   }
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