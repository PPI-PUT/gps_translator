// Copyright 2023 Jakub Codogni
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef GPS_TRANSLATOR__VISIBILITY_CONTROL_HPP_
#define GPS_TRANSLATOR__VISIBILITY_CONTROL_HPP_

////////////////////////////////////////////////////////////////////////////////
#if defined(__WIN32)
  #if defined(GPS_TRANSLATOR_BUILDING_DLL) || defined(GPS_TRANSLATOR_EXPORTS)
    #define GPS_TRANSLATOR_PUBLIC __declspec(dllexport)
    #define GPS_TRANSLATOR_LOCAL
  #else  // defined(GPS_TRANSLATOR_BUILDING_DLL) || defined(GPS_TRANSLATOR_EXPORTS)
    #define GPS_TRANSLATOR_PUBLIC __declspec(dllimport)
    #define GPS_TRANSLATOR_LOCAL
  #endif  // defined(GPS_TRANSLATOR_BUILDING_DLL) || defined(GPS_TRANSLATOR_EXPORTS)
#elif defined(__linux__)
  #define GPS_TRANSLATOR_PUBLIC __attribute__((visibility("default")))
  #define GPS_TRANSLATOR_LOCAL __attribute__((visibility("hidden")))
#elif defined(__APPLE__)
  #define GPS_TRANSLATOR_PUBLIC __attribute__((visibility("default")))
  #define GPS_TRANSLATOR_LOCAL __attribute__((visibility("hidden")))
#else
  #error "Unsupported Build Configuration"
#endif

#endif  // GPS_TRANSLATOR__VISIBILITY_CONTROL_HPP_
