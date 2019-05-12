import qbs

Module {
    Depends { name: "cpp" }

    Properties {
        condition: qbs.targetOS.contains("linux")
        cpp.includePaths: ["/usr/include"]
        cpp.dynamicLibraries: ["/usr/lib/x86_64-linux-gnu/libSDL-1.2.so.0", "/usr/lib/x86_64-linux-gnu/libSDL_ttf-2.0.so.0"]
    }
}
