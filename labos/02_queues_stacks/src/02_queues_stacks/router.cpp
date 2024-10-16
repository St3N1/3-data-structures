/*
 *  @author Thomas Cassimon
 *  @date   08/09/2022.
 */

#include "02_queues_stacks/router.hpp"

// TODO: Implement all of the Router's methods here!

Router::Router(int physical_layer, int MAC_address) { /*TODO: Fill in the constructor arguments!*/
    physical_layer = physical_layer;
    MAC_address = MAC_address;
    low_priority;
    high_priority;
};

void Router::receive(Packet&& packet) {
    packet.pop();
    packet.pop();

    if (packet.top() == 1) high_priority.push(packet);
    if (packet.top() == 0) low_priority.push(packet);
};

std::optional<Packet> Router::send() {
    if (high_priority.size() == 0 && low_priority.size() == 0) return std::nullopt;

    Packet packet;

    if (high_priority.size() > 0) {
        packet = high_priority.front();
        high_priority.pop();
    } else if (low_priority.size() > 0) {
        packet = low_priority.front();
        low_priority.pop();
    }

    packet.push(MAC_address);
    packet.push(physical_layer);

    return packet;
};