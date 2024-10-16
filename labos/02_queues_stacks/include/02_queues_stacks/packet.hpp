/*
 *  @author Thomas Cassimon
 *  @date   08/09/2022.
 */

#pragma once
#include <stack>

using Packet = std::stack<int>;  // TODO: Fill in this type alias!

// TODO: Fill in this return type
Packet create_packet(int physical_layer, int data_link_layer, int network_layer, int transport_layer, int application_layer);  // TODO: Fill in these arguments