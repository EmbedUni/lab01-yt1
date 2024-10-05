# Program: Two Hearts
**Author(s):**
**Date:**

**Modified by:**  
**Date:**

**Purpose:** This program flashes two of the internal LEDs on the nRF52840 DK. One flashes five times and then the other flashes 5 times. The cycle repeats forever.

## Configuration
Uses default devicetree configuration

## Hardware
### Internal
* LED1 (digital output)
* LED2 (digital output)

## Flow
```mermaid
graph TB
  B("main()") --> C[Set i to 0]
  C --> D{Do it forever?}
  D -- Yes --> E{Is i < 5?}
  E -- Yes --> F[Turn LED1 on]
  E -- No --> K{Is i > 0?}
  F --> G([Sleep])
  G --> H[Turn LED1 off]
  H --> I([Sleep])
  I --> J(Increase i by 1)
  J --> E
  K -- Yes --> L[Turn LED4 on]
  L --> M([Sleep])
  M --> N[Turn LED4 off]
  N --> O([Sleep])
  O --> P(Decrease i by 1)
  P --> K
  K -- No --> D
```