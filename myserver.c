#define SOCKET_ADDRESS "ipc://test.ipc"

#include <assert.h>
#include <stdio.h>

#include "nn.h"
#include "reqrep.h"
#include "ipc.h"

int main () {
  char buf[32];
  int rc;
  int rep = nn_socket(AF_SP, NN_REP);
  assert(rep != -1);
  printf("bind\n");
  int eid = nn_bind(rep, SOCKET_ADDRESS);
  assert(eid >= 0);
  printf("recv\n");
  rc = nn_recv(rep, buf, sizeof(buf), 0);
  assert(rc == 3);
  printf("send\n");
  rc = nn_send(rep, "abc", 3, 0);
  assert(rc == 3);
  printf("shutdown\n");
  rc = nn_shutdown(rep, eid);
  assert(rc == 0);
  printf("close\n");
  rc = nn_close(rep);
  assert(rc == 0);
}
