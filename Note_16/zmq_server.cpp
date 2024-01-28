#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <zmq.h>

int main() {
  void *context = zmq_ctx_new();
  void *responder = zmq_socket(context, ZMQ_REP);
  int rc = zmq_bind(responder, "tcp://*:5555");

  if (rc != 0) {
    perror("Failed to bind socket");
    return 1;
  }

  while (1) {
    char buffer[10];
    zmq_recv(responder, buffer, sizeof(buffer), 0);
    printf("Received: %s\n", buffer);

    zmq_send(responder, "World", 5, 0);
  }

  zmq_close(responder);
  zmq_ctx_destroy(context);

  return 0;
}