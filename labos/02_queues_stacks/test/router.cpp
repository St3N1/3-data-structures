/*
 *  @author Thomas Cassimon
 *  @date   08/09/2022.
 */

#include <02_queues_stacks/packet.hpp>
#include <02_queues_stacks/router.hpp>
#include <catch2/catch.hpp>
#include <iostream>

// TODO: Write Unit Tests for Router class!
TEST_CASE("create router, check size and layers") {
    const int physical_layer = 2;
    const int data_link_layer = 4;
    const int network_layer = 0;
    const int transport_layer = 8;
    const int application_layer = 10;

    Packet packet = create_packet(physical_layer, data_link_layer, network_layer, transport_layer, application_layer);
    Router router(1, 987654321);

    router.receive(std::move(packet));
    std::optional<Packet> packet_send = router.send();
}