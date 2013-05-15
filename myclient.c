#define SOCKET_ADDRESS "ipc://test.ipc"

#include <assert.h>

#include "nn.h"
#include "reqrep.h"
#include "ipc.h"

int main () {
  char buf[32];
  int rc;
  int req = nn_socket(AF_SP, NN_REQ);
  assert(req != -1);
  int eid = nn_connect(req, SOCKET_ADDRESS);
  assert(eid >= 0);
  rc = nn_send(req, "abc", 3, 0);
  assert(rc == 3);
  rc = nn_recv(req, buf, sizeof(buf), 0);
  assert(rc == 3);
  rc = nn_shutdown(req, eid);
  assert(rc == 0);
  rc = nn_close(req);
  assert(rc == 0);
}
