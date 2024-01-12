#ifndef MESSAGE_HEADER_H_
#define MESSAGE_HEADER_H_

#include <iostream>
#include <string>

class Message {
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