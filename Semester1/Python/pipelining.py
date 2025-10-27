#!/usr/bin/env python3
"""
DFCA Simulation Problem (Python version)
----------------------------------------
✅ Works directly in VS Code terminal or HackerRank.
✅ Reads instructions until the keyword 'END'.
✅ Calculates total stalls caused by load-use hazards.
✅ Outputs in the exact required format:
    Total Stalls : X
"""

import sys

def parse_instruction(line):
    """
    Parse a single instruction and return (op, dest, sources).

    Examples of supported formats:
        add $t0 , $t1 , $t2
        sub $t2, $t3, $t4
        lw $t0 , 0
        sw $t1 , 2
    """
    # Normalize spaces and commas for easier splitting
    parts = line.replace(',', ' ').split()
    if not parts:
        return (None, None, set())

    op = parts[0]            # operation name (add/sub/lw/sw)
    dest = None              # register being written to (if any)
    sources = set()          # registers being read (if any)

    # Handle instruction formats
    if op in ('add', 'sub'):
        # Format: op dest src1 src2
        if len(parts) >= 4:
            dest = parts[1]
            sources.add(parts[2])
            sources.add(parts[3])
    elif op == 'lw':
        # Format: lw dest memory_addr
        if len(parts) >= 2:
            dest = parts[1]
        # lw reads from memory — no register sources
    elif op == 'sw':
        # Format: sw src memory_addr
        if len(parts) >= 2:
            sources.add(parts[1])
        # sw stores register value to memory — no destination register
    else:
        # Unknown instruction — ignore safely
        pass

    return (op, dest, sources)


def count_stalls(instructions):
    """
    Count total stalls caused by load-use hazards.

    Rule:
    If the previous instruction is 'lw' and its destination register
    is used as a source in the current instruction → +1 stall.
    """
    stalls = 0
    prev_op = None
    prev_dest = None

    for line in instructions:
        op, dest, sources = parse_instruction(line)

        # Check for load-use hazard
        if prev_op == 'lw' and prev_dest and prev_dest in sources:
            stalls += 1

        # Update previous instruction info
        prev_op = op
        prev_dest = dest

    return stalls


def main():
    """
    Main driver function:
    Reads lines until 'END' and prints total stalls.
    """
    instructions = []

    print("Enter your instructions (type 'END' to stop):")
    for raw in sys.stdin:
        line = raw.strip()
        if line == 'END':
            break
        if line:
            instructions.append(line)

    total_stalls = count_stalls(instructions)
    print(f"Total Stalls : {total_stalls}")


if __name__ == "__main__":
    main()