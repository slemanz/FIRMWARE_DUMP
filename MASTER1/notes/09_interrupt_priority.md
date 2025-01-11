# 9. Interrupt Priority and Configuration

**What is Priority?**  
Priority refers to the urgency of an interrupt.

**What is a Priority Value?**  
The priority value measures how urgent an interrupt is compared to others. ARM processors have 60 interrupt priority registers, and the number of bits used for priority levels is vendor-specific.

## Pre-empt Priority and Sub-Priority

**What Happens When Two Interrupts of the Same Priority Occur?**  
If two interrupts with the same priority arrive at the processor simultaneously, the sub-priority value will be checked to resolve the conflict.

**Priority Grouping:**
- **Pre-empt Priority:** When an interrupt handler is running, the pre-empt priority values are compared. An interrupt with a higher pre-empt priority (lower value) will be allowed to run.
  
- **Sub-Priority:** This value is used when two interrupts with the same pre-empt priority occur at the same time. The interrupt with the higher sub-priority (lower value) will be handled first.

**What if Two Interrupts Have the Same Pre-empt and Sub-Priority?**  
If both interrupts have the same pre-empt and sub-priority, the interrupt with the lower IRQ number will be handled first.

## Pending Interrupt

A 'Pending Interrupt' refers to a signal that indicates an event has occurred and needs attention from the firmware. It allows firmware to handle tasks efficiently by notifying it immediately when an event takes place.

---

Next: 

