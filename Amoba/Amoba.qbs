import qbs

Project {
    minimumQbsVersion: "1.7.1"

    qbsSearchPaths: "../QBS"
    CppApplication {
        consoleApplication: true

        cpp.cxxLanguageVersion: "c++14"
        cpp.enableRtti: "true"
        files: [
            "source/main.cpp",
            "source/mezo.cpp",
            "source/mezo.hpp",
            "source/myapplication.cpp",
            "source/myapplication.hpp",
        ]

        Group {     // Properties for the produced executable
            fileTagsFilter: "application"
            qbs.install: true
        }
        Depends { name:  "graphicslib" }
        Depends { name: "sdl" }
        Depends { name: "widgetek" }
        Depends { name: "OsApp" }
    }

    SubProject {
        filePath: "../ITK_graphicslib/graphics.qbs"
        Properties {
            name: "ITK graphics library"
        }
    }
    SubProject {
        filePath: "../widgetezos/widgets.qbs"
        Properties {
            name: "Widgetek"
        }
    }
    SubProject {
    filePath: "../application/application.qbs"
    Properties {
        name: "OsApp"
    }
}
}


