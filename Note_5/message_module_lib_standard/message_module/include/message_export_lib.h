#ifndef MESSAGE_EXPORT_LIB_H_
#define MESSAGE_EXPORT_LIB_H_

#ifdef MESSAGE_LIB_SHARED_BUILD
    #ifdef _WIN32
        #ifdef MESSAGE_LIB_EXPORTS
            #define MESSAGE_LIB_API __declspec(dllexport)
        #else
            #define MESSAGE_LIB_API __declspec(dllimport)
        #endif  // MESSAGE_LIB_EXPORTS
    #else
        #define MESSAGE_LIB_API
    #endif  // _WIN32
#else
    #define MESSAGE_LIB_API
#endif  // MESSAGE_LIB_SHARED_BUILD

#endif // ! MESSAGE_EXPORT_LIB_H_