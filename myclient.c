#define SOCKET_ADDRESS "ipc://test.ipc"

#include <assert.h>
#include <stdio.h>

#include "nn.h"
#include "reqrep.h"
#include "ipc.h"

int main () {
  char buf[32];
  int rc;
  int req = nn_socket(AF_SP, NN_REQ);
  assert(req != -1);
  printf("connect\n");
  int eid = nn_connect(req, SOCKET_ADDRESS);
  assert(eid >= 0);
  printf("send\n");
  rc = nn_send(req, "abc", 3, 0);
  assert(rc == 3);
  printf("recv\n");
  rc = nn_recv(req, buf, sizeof(buf), 0);
  assert(rc == 3);
  printf("shutdown\n");
  rc = nn_shutdown(req, eid);
  assert(rc == 0);
  printf("close\n");
  rc = nn_close(req);
  assert(rc == 0);
}
