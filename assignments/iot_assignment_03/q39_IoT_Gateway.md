# Q39. (Theory) What is an IoT Gateway?

**Question:** What is an IoT gateway? Draw a simple diagram showing the relationship between: IoT Sensor Nodes → Gateway → Cloud → User Application. What protocols are typically used at each layer? *(2 marks)*

---

## Answer

An IoT gateway sits between sensor nodes and the cloud. It collects data from multiple sensors (often over low power, short range protocols), then converts and forwards it to the internet using standard networking protocols. It can also do local processing, filtering, and protocol translation, so sensors don't have to talk directly to the cloud.

## Diagram: Sensor Nodes → Gateway → Cloud → User Application

```mermaid
flowchart TD
    A["📡 IoT Sensor Nodes<br/><sub>Temperature, soil, motion</sub>"]
    B["🔗 Gateway<br/><sub>Aggregates and forwards data</sub>"]
    C["☁️ Cloud<br/><sub>Storage, processing, analytics</sub>"]
    D["📱 User Application<br/><sub>Dashboard, mobile app</sub>"]

    A -->|Zigbee, BLE, LoRa| B
    B -->|MQTT, HTTP, CoAP| C
    C -->|REST API, WebSocket| D

    style A fill:#0e6b4f,color:#fff,stroke:#0a4f3a
    style B fill:#5b3fa8,color:#fff,stroke:#42307a
    style C fill:#1a5fb4,color:#fff,stroke:#144a8c
    style D fill:#a1381f,color:#fff,stroke:#7a2a17
```

## Protocols Typically Used at Each Layer

| Layer | Protocols |
|---|---|
| **Sensor Nodes → Gateway** | Zigbee, BLE, LoRa, Z-Wave |
| **Gateway → Cloud** | MQTT, HTTP/HTTPS, CoAP |
| **Cloud → User Application** | REST API, WebSocket |
