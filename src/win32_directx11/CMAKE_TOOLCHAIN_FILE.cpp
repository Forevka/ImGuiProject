{
"configurations": [{
    "name": "x86-Debug",
        "generator" : "Visual Studio 15 2017",
        "configurationType" : "Debug",
        "buildRoot" : "${env.LOCALAPPDATA}\\CMakeBuild\\${workspaceHash}\\build\\${name}",
        "cmakeCommandArgs" : "",
        "buildCommandArgs" : "-m -v:minimal",
        "variables" : [{
        "name": "CMAKE_TOOLCHAIN_FILE",
            "value" : "C:/Users/bohdan.lushchyk/vcpkg/scripts/buildsystems/vcpkg.cmake"
    }]
}]
}
