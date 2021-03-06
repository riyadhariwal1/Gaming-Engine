#ifndef NETWORKING_DISPATCH
#define NETWORKING_DISPATCH

#include <iostream>
#include "Server.h"
#include "Store.h"

using namespace networking;

/**
 * @class Dispatch
 *
 * @brief Handles processing and sending messages to the correct rooms/users
 *
 * The Dispatch class takes in the deque of unprocessed messages and processes
 * them to be sent out to the correct rooms/users. This can also be used to get
 * the messages from a Game instance and send them to the client.
 *
 * @todo find out if server.receive and work here as well
 */
class Dispatch
{
public:
  Server &server;
  Store& store;

  Dispatch(Server& server, Store& store)
  : server{server},
    store{store}
  {};
  std::deque<Message> postOffice(const std::deque<Message> &processedMessages);
};

#endif
