import qbs
Project {

    StaticLibrary {
        name: "OsApp"
        Depends { name: "cpp" }
        Depends { name: "graphicslib" }
        cpp.includePaths: [ product.sourceDirectory + "/include" ]
        files: [
            "include/application.hpp",
            "source/application.cpp"
        ]
        Export {
            Depends { name: "cpp" }
            cpp.includePaths: [product.sourceDirectory + "/include"]
       }
    }
}
