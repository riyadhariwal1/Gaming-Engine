#include "Dispatch.h"

// takes the the messages from processMessages()
// and creates a deque of output Messages assigned to the appropriate room members
// returns deque of messages in the form of
//                              Connection: Recipient ID  	(where recipient = a user who's in the same room as the sender)
//                              Text: USER_ID> MESSAGE_TEXT
std::deque<Message>
Dispatch::postOffice(const std::deque<Message> &processedMessages, Store &store)
{
  std::deque<Message> output;
  for (auto &message : processedMessages)
  {
    auto sendersRoom = store.getRoomById(message.sendersRoomId);

    // check if message.whisperId exists
    // if true, push_back one message object to the whisperId
    // else, send message to all rooms members as normal

    if (message.whisperID.id != 0)
    {
      output.push_back({message.c, message.text, message.sendersRoomId});
      output.push_back({message.whisperID, message.text, message.sendersRoomId});
    }
    else
    {
      for (auto user : sendersRoom->getUsers())
      {
        output.push_back({user.connection, message.text, message.sendersRoomId});
      }
    }
  }

  return output;
}
