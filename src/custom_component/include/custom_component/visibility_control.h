#ifndef CUSTOM_COMPONENT__VISIBILITY_CONTROL_H_
#define CUSTOM_COMPONENT__VISIBILITY_CONTROL_H_

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define CUSTOM_COMPONENT_EXPORT __attribute__ ((dllexport))
    #define CUSTOM_COMPONENT_IMPORT __attribute__ ((dllimport))
  #else
    #define CUSTOM_COMPONENT_EXPORT __declspec(dllexport)
    #define CUSTOM_COMPONENT_IMPORT __declspec(dllimport)
  #endif
  #ifdef CUSTOM_COMPONENT_BUILDING_LIBRARY
    #define CUSTOM_COMPONENT_PUBLIC CUSTOM_COMPONENT_EXPORT
  #else
    #define CUSTOM_COMPONENT_PUBLIC CUSTOM_COMPONENT_IMPORT
  #endif
  #define CUSTOM_COMPONENT_PUBLIC_TYPE CUSTOM_COMPONENT_PUBLIC
  #define CUSTOM_COMPONENT_LOCAL
#else
  #define CUSTOM_COMPONENT_EXPORT __attribute__ ((visibility("default")))
  #define CUSTOM_COMPONENT_IMPORT
  #if __GNUC__ >= 4
    #define CUSTOM_COMPONENT_PUBLIC __attribute__ ((visibility("default")))
    #define CUSTOM_COMPONENT_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define CUSTOM_COMPONENT_PUBLIC
    #define CUSTOM_COMPONENT_LOCAL
  #endif
  #define CUSTOM_COMPONENT_PUBLIC_TYPE
#endif

#endif  // CUSTOM_COMPONENT__VISIBILITY_CONTROL_H_
