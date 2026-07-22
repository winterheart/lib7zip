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

ADD_LIBRARY(lib7zip STATIC ${lib7zip_src}
  ${lib7zip_NODIST_SOURCES}
)

SET_TARGET_PROPERTIES(lib7zip PROPERTIES
  OUTPUT_NAME "7zip"
)

TARGET_INCLUDE_DIRECTORIES(lib7zip PRIVATE
  "${SEVENZIP_INCLUDE_PATH}"
)

IF (LIB7ZIP_BUILD_SHARED_LIB)
  ADD_LIBRARY(lib7zip_shared SHARED ${lib7zip_src}
    ${lib7zip_NODIST_SOURCES}
  )
  SET_TARGET_PROPERTIES(lib7zip_shared PROPERTIES
    OUTPUT_NAME "7zip"
  )

  TARGET_INCLUDE_DIRECTORIES(lib7zip_shared PRIVATE
    "${SEVENZIP_INCLUDE_PATH}"
  )
ENDIF ()
