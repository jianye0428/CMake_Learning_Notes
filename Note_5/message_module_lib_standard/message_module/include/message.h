#ifndef MESSAGE_HEADER_H_
#define MESSAGE_HEADER_H_
#include <iostream>
#include <string>

#include "message_export_lib.h"
class MESSAGE_LIB_API Message {
 public:
  /**
   * @brief Default construction. This is a class that prints messages.
   **/
  Message() {}

  /**
   * @brief Override std::cout function.
   * @param[in] message Message.
   **/
  void Print(const std::string &message);
};
#endif // ! MESSAGE_HEADER_H_