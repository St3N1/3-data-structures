/*
 *  @author Thomas Cassimon
 *  @date   08/09/2022.
 */

#include <02_queues_stacks/packet.hpp>
#include <catch2/catch.hpp>

// TODO: Write Unit Tests for Packet class!

TEST_CASE("create packet, check size and layers") {
    const int physical_layer = 2;
    const int data_link_layer = 4;
    const int network_layer = 6;
    const int transport_layer = 8;
    const int application_layer = 10;

    Packet packet = create_packet(physical_layer, data_link_layer, network_layer, transport_layer, application_layer);

    CHECK(packet.size() == 5);

    CHECK(packet.top() == physical_layer);
    packet.pop();

    CHECK(packet.top() == data_link_layer);
    packet.pop();

    CHECK(packet.top() == network_layer);
    packet.pop();

    CHECK(packet.top() == transport_layer);
    packet.pop();

    CHECK(packet.top() == application_layer);
    packet.pop();
}