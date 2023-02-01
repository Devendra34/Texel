workspace "Texel"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Texel"
    location "Texel"
    kind "SharedLib"
    language "C++"
    cppdialect "C++17"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")


    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/third-party/spdlog/include"
    }

    filter "system:windows"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "TEXEL_PLATFROM_WINDOWS",
            "TEXEL_BUILD_DIR_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "TEXEL_DEBUG"
        symbols "On"
        

    filter "configurations:Release"
        defines "TEXEL_RELEASE"
        symbols "On"

    filter "configurations:Dist"
        defines "TEXEL_DIST"
        symbols "On"

    filter { "system:windows", "configurations:Release" }
        buildoptions "/MT"


project "Sandbox"
        location "Sandbox"
        kind "ConsoleApp"
        language "C++"
        cppdialect "C++17"


        targetdir ("bin/" .. outputdir .. "/%{prj.name}")
        objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
    
    
        files
        {
            "%{prj.name}/src/**.h",
            "%{prj.name}/src/**.cpp",
        }
    
        includedirs
        {
            "Texel/third-party/spdlog/include",
            "Texel/src"
        }
    
        links
        {
            "Texel"
        }

        filter "system:windows"
            staticruntime "On"
            systemversion "latest"
    
            defines
            {
                "TEXEL_PLATFROM_WINDOWS"
            }
    
        filter "configurations:Debug"
            defines "TEXEL_DEBUG"
            symbols "On"
            
    
        filter "configurations:Release"
            defines "TEXEL_RELEASE"
            symbols "On"
    
        filter "configurations:Dist"
            defines "TEXEL_DIST"
            symbols "On"
    
        filter { "system:windows", "configurations:Release" }
            buildoptions "/MT"
    


