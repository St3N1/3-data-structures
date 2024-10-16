/*
 *  @author Thomas Cassimon
 *  @date   08/09/2022.
 */

#pragma once

#include <optional>
#include <queue>

#include "02_queues_stacks/packet.hpp"

class Router {
   private:
    // TODO: Add all of the class' fields
    int physical_layer;
    int MAC_address;
    std::queue<Packet> low_priority;
    std::queue<Packet> high_priority;

   public:
    Router(int physical_layer, int MAC_address); /*TODO: Fill in the constructor arguments!*/

    // TODO: Add the receive() method!
    void receive(Packet&& packet);

    // TODO: Add the send() method!
    std::optional<Packet> send();
};