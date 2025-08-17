# Chapter 1 – Introduction

## Shift to Multicore
- **Moore’s Law slowing down** → clock speeds no longer improving much.
- Industry moved to **multicore architectures** (multiple cores on one chip).
- Goal: exploit **parallelism** instead of faster single cores.

## Key Definitions

- **Mutual Exclusion**: At most one thread (or process) can access a shared resource at a time.  
- **Deadlock-Freedom**: If multiple threads want access, at least one will eventually succeed (no one gets stuck forever).  
- **Starvation-Freedom (Lockout-Freedom)**: Every thread that wants access will eventually succeed (fairness).  
- **Waiting / Blocking**: Progress depends on other threads lowering their flags or releasing locks. Delays propagate.  
- **Safety Property**: Nothing bad ever happens (e.g two pets aren’t in the yard at once).  
- **Liveness Property**: Something good eventually happens (e.g if a pet wants in, it eventually gets in).  
- **Persistent Communication**: Sender/receiver can act at different times (e.g., setting a bit, leaving a note).  
- **Transient Communication**: Both must participate at the same time (e.g shouting, phone call).  
- **Producer–Consumer Problem**: One party produces data (Bob puts food), another consumes it (pets eat).  
- **Readers–Writers Problem**: One or more readers can safely read while writers update, but must prevent inconsistent views.

## Amdahl’s Law
- Speedup limited by sequential portion of program.  
- Formula:  
  \[
  S = \frac{1}{(1-p) + \frac{p}{n}}
  \]

- minimize sequential code + coordination costs.

---


- Ctrl - Shift - V to view markdown in vscdoe