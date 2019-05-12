import qbs
Project {

    StaticLibrary {
        name: "widgetek"
        Depends { name: "cpp" }
        Depends { name: "graphicslib" }
        Depends { name: "OsApp" }
        cpp.includePaths: [ product.sourceDirectory + "/include" ]
        files: [
            "include/widgets.hpp",
            "source/widgets.cpp"
        ]
        Export {
            Depends { name: "cpp" }
            cpp.includePaths: [product.sourceDirectory + "/include"]
       }
    }
}
