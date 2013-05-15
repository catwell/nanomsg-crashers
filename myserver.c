#define SOCKET_ADDRESS "ipc://test.ipc"

#include <assert.h>

#include "nn.h"
#include "reqrep.h"
#include "ipc.h"

int main () {
  char buf[32];
  int rc;
  int rep = nn_socket(AF_SP, NN_REP);
  assert(rep != -1);
  int eid = nn_bind(rep, SOCKET_ADDRESS);
  assert(eid >= 0);
  rc = nn_recv(rep, buf, sizeof(buf), 0);
  assert(rc == 3);
  rc = nn_send(rep, "abc", 3, 0);
  assert(rc == 3);
  rc = nn_shutdown(rep, eid);
  assert(rc == 0);
  rc = nn_close(rep);
  assert(rc == 0);
}
