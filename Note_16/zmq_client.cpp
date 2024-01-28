#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <zmq.h>

int main() {
  void *context = zmq_ctx_new();
  void *requester = zmq_socket(context, ZMQ_REQ);
  int rc = zmq_connect(requester, "tcp://localhost:5555");

  if (rc != 0) {
    perror("Failed to connect to server");
    return 1;
  }

  while (true) {
    char buffer[] = "Hello";
    zmq_send(requester, buffer, sizeof(buffer), 0);

    char reply[10];
    zmq_recv(requester, reply, sizeof(reply), 0);
    printf("Received: %s\n", reply);

    sleep(10);
  }

  zmq_close(requester);
  zmq_ctx_destroy(context);

  return 0;
}