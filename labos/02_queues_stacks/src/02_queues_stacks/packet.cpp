/*
 *  @author Thomas Cassimon
 *  @date   08/09/2022.
 */

#include "02_queues_stacks/packet.hpp"

// TODO: Fill in this return type
Packet create_packet(int physical_layer, int data_link_layer, int network_layer, int transport_layer, int application_layer) {  // TODO: Fill in these arguments
    Packet packet;

    packet.push(application_layer);
    packet.push(transport_layer);
    packet.push(network_layer);
    packet.push(data_link_layer);
    packet.push(physical_layer);

    return packet;
}