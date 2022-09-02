set(APP_NAME alarm)

set(SOURCE
    main.cpp
    alarmwindow.h
    alarmwindow.cpp
    alarmeditor.h
    alarmeditor.cpp
    alarmitemdelegate.h
    alarmitemdelegate.cpp
    alarmdata.h
    resources.qrc
)

qt_add_executable(${APP_NAME} ${SOURCE})

target_include_directories(${APP_NAME}
    PUBLIC QT${QT_VERSION_MAJOR}_INCLUDE_DIRS

)

target_link_libraries(${APP_NAME}
    PUBLIC Qt${QT_VERSION_MAJOR}::Core
    PUBLIC Qt${QT_VERSION_MAJOR}::Widgets

)