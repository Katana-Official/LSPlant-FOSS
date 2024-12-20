plugins {
    alias(libs.plugins.lsplugin.publish)
}

val androidTargetSdkVersion by extra(35)
val androidMinSdkVersion by extra(21)
val androidBuildToolsVersion by extra("35.0.0")
val androidCompileSdkVersion by extra(35)
val androidNdkVersion by extra("28.0.12674087")
val androidCmakeVersion by extra("3.31.1")
val androidNinjaPath by extra("")
//val androidNinjaPath by extra("C:/Program Files/CMake/bin/ninja.exe")
