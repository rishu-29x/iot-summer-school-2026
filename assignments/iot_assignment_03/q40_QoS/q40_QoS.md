# Q40. (Theory) MQTT QoS (Quality of Service) Levels

**Question:** Explain QoS (Quality of Service) levels in MQTT: QoS 0 (At most once), QoS 1 (At least once), QoS 2 (Exactly once). In an IoT water level monitoring system, which QoS level would you choose and why?

---

## Answer

### QoS 0 (At Most Once)

The message is sent once and forgotten. No acknowledgment, no retry. It might reach the subscriber, or it might get lost if the connection drops. Fastest and lightest on the network, but no delivery guarantee.

### QoS 1 (At Least Once)

The sender keeps the message until it gets a PUBACK from the receiver. If the acknowledgment doesn't arrive, the message is sent again. This guarantees delivery, but the same message can reach the subscriber more than once, so duplicates are possible.

### QoS 2 (Exactly Once)

Uses a four step handshake between sender and receiver to guarantee the message arrives exactly once, no loss and no duplicates. This is the safest option but also the slowest, since it needs more back and forth communication and more processing at both ends.

### Choice for Water Level Monitoring System

**QoS 1 is the right fit here.**

A missed water level reading due to QoS 0 could delay a flood or overflow alert, which is risky. But QoS 2's extra handshake overhead isn't justified either, since an occasional duplicate reading for something like water level is harmless as the value doesn't change drastically between two close readings. QoS 1 gives the delivery guarantee that matters for safety critical alerts, without the added latency and processing cost of QoS 2, which matters when you have many sensor nodes reporting frequently.
