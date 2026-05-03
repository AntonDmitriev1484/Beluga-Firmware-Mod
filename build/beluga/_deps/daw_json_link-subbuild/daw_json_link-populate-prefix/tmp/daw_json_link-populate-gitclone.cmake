
if(NOT "/home/admi3ev/Beluga-Firmware-Mod/build/beluga/_deps/daw_json_link-subbuild/daw_json_link-populate-prefix/src/daw_json_link-populate-stamp/daw_json_link-populate-gitinfo.txt" IS_NEWER_THAN "/home/admi3ev/Beluga-Firmware-Mod/build/beluga/_deps/daw_json_link-subbuild/daw_json_link-populate-prefix/src/daw_json_link-populate-stamp/daw_json_link-populate-gitclone-lastrun.txt")
  message(STATUS "Avoiding repeated git clone, stamp file is up to date: '/home/admi3ev/Beluga-Firmware-Mod/build/beluga/_deps/daw_json_link-subbuild/daw_json_link-populate-prefix/src/daw_json_link-populate-stamp/daw_json_link-populate-gitclone-lastrun.txt'")
  return()
endif()

execute_process(
  COMMAND ${CMAKE_COMMAND} -E rm -rf "/home/admi3ev/Beluga-Firmware-Mod/build/beluga/_deps/daw_json_link-src"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to remove directory: '/home/admi3ev/Beluga-Firmware-Mod/build/beluga/_deps/daw_json_link-src'")
endif()

# try the clone 3 times in case there is an odd git clone issue
set(error_code 1)
set(number_of_tries 0)
while(error_code AND number_of_tries LESS 3)
  execute_process(
    COMMAND "/usr/bin/git"  clone --no-checkout --config "advice.detachedHead=false" "https://github.com/beached/daw_json_link" "daw_json_link-src"
    WORKING_DIRECTORY "/home/admi3ev/Beluga-Firmware-Mod/build/beluga/_deps"
    RESULT_VARIABLE error_code
    )
  math(EXPR number_of_tries "${number_of_tries} + 1")
endwhile()
if(number_of_tries GREATER 1)
  message(STATUS "Had to git clone more than once:
          ${number_of_tries} times.")
endif()
if(error_code)
  message(FATAL_ERROR "Failed to clone repository: 'https://github.com/beached/daw_json_link'")
endif()

execute_process(
  COMMAND "/usr/bin/git"  checkout release --
  WORKING_DIRECTORY "/home/admi3ev/Beluga-Firmware-Mod/build/beluga/_deps/daw_json_link-src"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to checkout tag: 'release'")
endif()

set(init_submodules TRUE)
if(init_submodules)
  execute_process(
    COMMAND "/usr/bin/git"  submodule update --recursive --init 
    WORKING_DIRECTORY "/home/admi3ev/Beluga-Firmware-Mod/build/beluga/_deps/daw_json_link-src"
    RESULT_VARIABLE error_code
    )
endif()
if(error_code)
  message(FATAL_ERROR "Failed to update submodules in: '/home/admi3ev/Beluga-Firmware-Mod/build/beluga/_deps/daw_json_link-src'")
endif()

# Complete success, update the script-last-run stamp file:
#
execute_process(
  COMMAND ${CMAKE_COMMAND} -E copy
    "/home/admi3ev/Beluga-Firmware-Mod/build/beluga/_deps/daw_json_link-subbuild/daw_json_link-populate-prefix/src/daw_json_link-populate-stamp/daw_json_link-populate-gitinfo.txt"
    "/home/admi3ev/Beluga-Firmware-Mod/build/beluga/_deps/daw_json_link-subbuild/daw_json_link-populate-prefix/src/daw_json_link-populate-stamp/daw_json_link-populate-gitclone-lastrun.txt"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to copy script-last-run stamp file: '/home/admi3ev/Beluga-Firmware-Mod/build/beluga/_deps/daw_json_link-subbuild/daw_json_link-populate-prefix/src/daw_json_link-populate-stamp/daw_json_link-populate-gitclone-lastrun.txt'")
endif()

