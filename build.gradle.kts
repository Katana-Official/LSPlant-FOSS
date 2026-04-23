plugins {
    alias(libs.plugins.lsplugin.publish)
}

val androidTargetSdkVersion by extra(35)
val androidMinSdkVersion by extra(21)
val androidBuildToolsVersion by extra("35.0.0")
val androidCompileSdkVersion by extra(35)
val androidNdkVersion by extra("27.2.12479018")
val androidCmakeVersion by extra("4.1.2")
//val androidNinjaPath by extra("")
val androidNinjaPath by extra("C:\\Program Files\\CMake\\ninja.exe")
