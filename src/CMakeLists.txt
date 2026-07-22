SET(lib7zip_src
  7ZipArchive.cpp
  7ZipArchiveItem.cpp
  7ZipArchiveOpenCallback.cpp
  7ZipArchiveOpenCallback.h
  7ZipCodecInfo.cpp
  7ZipCodecInfo.h
  7ZipCompressCodecsInfo.cpp
  7ZipCompressCodecsInfo.h
  7ZipDllHandler.cpp
  7ZipDllHandler.h
  7ZipFormatInfo.cpp
  7ZipFormatInfo.h
  7ZipFunctions.h
  7ZipInStreamWrapper.cpp
  7ZipInStreamWrapper.h
  7ZipObjectPtrArray.cpp
  7ZipOpenArchive.cpp
  7zipLibrary.cpp
  HelperFuncs.cpp
  HelperFuncs.h
  OSFunctions.h
  OSFunctions_OS2.cpp
  OSFunctions_OS2.h
  OSFunctions_UnixLike.cpp
  OSFunctions_UnixLike.h
  OSFunctions_Win32.cpp
  OSFunctions_Win32.h
  compat.h
  lib7zip.h
)

SET(lib7zip_NODIST_SOURCES
  ${SEVENZIP_SOURCE_DIR}/CPP/Common/MyWindows.cpp
  ${SEVENZIP_SOURCE_DIR}/CPP/Windows/PropVariant.cpp
)

IF (LIB7ZIP_BUILD_SHARED_LIB)
  ADD_LIBRARY(lib7zip SHARED ${lib7zip_src} ${lib7zip_NODIST_SOURCES})
ELSE ()
  ADD_LIBRARY(lib7zip STATIC ${lib7zip_src} ${lib7zip_NODIST_SOURCES})
ENDIF ()

SET_TARGET_PROPERTIES(lib7zip PROPERTIES
  OUTPUT_NAME "7zip"
)

TARGET_INCLUDE_DIRECTORIES(lib7zip
  PRIVATE "${SEVENZIP_SOURCE_DIR}"
  PUBLIC
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/src>"
    "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)

# Installation
INSTALL(TARGETS lib7zip
  EXPORT lib7zipTargets
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
INSTALL(FILES lib7zip.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
INSTALL(EXPORT lib7zipTargets
  FILE lib7zipTargets.cmake
  NAMESPACE lib7zip::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/lib7zip
)
