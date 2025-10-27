# pipeline_core.py
"""
Core logic for MIPS pipeline simulation with stall detection.
"""

from typing import List, Tuple, Dict, Set

def parse_instruction(line: str) -> Tuple[str, str, Set[str]]:
    """
    Parses a single instruction into (operation, destination, sources).
    Supports lw, sw, add, sub.
    """
    parts = line.replace(',', ' ').split()
    if not parts:
        return (None, None, set())

    op = parts[0]
    dest = None
    sources = set()

    if op in ('add', 'sub'):
        if len(parts) >= 4:
            dest = parts[1]
            sources.add(parts[2])
            sources.add(parts[3])
    elif op == 'lw':
        if len(parts) >= 2:
            dest = parts[1]
    elif op == 'sw':
        if len(parts) >= 2:
            sources.add(parts[1])

    return (op, dest, sources)


def count_stalls(instructions: List[str]) -> Tuple[int, List[Tuple[int, int, str]]]:
    """
    Detects load-use hazards and counts stalls.
    Returns (total_stalls, stall_details)
    """
    stalls = 0
    prev_op = None
    prev_dest = None
    stall_points = []

    for i, line in enumerate(instructions):
        op, dest, sources = parse_instruction(line)
        if prev_op == 'lw' and prev_dest and prev_dest in sources:
            stalls += 1
            stall_points.append((i - 1, i, prev_dest))
        prev_op, prev_dest = op, dest

    return stalls, stall_points


def generate_timeline(instructions: List[str]) -> Dict:
    """
    Builds the full timeline (stages per instruction per cycle).
    Includes Stall cycles in dependent instructions.
    """
    parsed = [parse_instruction(line) for line in instructions]
    start_cycles = []
    prev_start = 0
    prev_op = None
    prev_dest = None
    stalls_info = []

    # determine starting cycle for each instruction
    for idx, (op, dest, sources) in enumerate(parsed):
        start = 1 if idx == 0 else prev_start + 1
        if prev_op == 'lw' and prev_dest and prev_dest in sources:
            start += 1
            stalls_info.append((idx - 1, idx, prev_dest))
        start_cycles.append(start)
        prev_start = start
        prev_op, prev_dest = op, dest

    # assign stages per instruction
    stage_cycles = []
    for start in start_cycles:
        stage_cycles.append({
            'IF': start,
            'ID': start + 1,
            'EX': start + 2,
            'MEM': start + 3,
            'WB': start + 4
        })

    total_cycles = max((s['WB'] for s in stage_cycles), default=0)
    instr_labels = [f"Instruction {i+1} :  {instructions[i]}" for i in range(len(instructions))]

    # build instruction-by-cycle table
    rows = []
    for i, label in enumerate(instr_labels):
        row = {"Instruction": label}
        for cycle in range(1, total_cycles + 1):
            stage = ""
            for name, c in stage_cycles[i].items():
                if c == cycle:
                    stage = name
                    break
            row[f"C{cycle}"] = stage
        rows.append(row)

    # insert stalls in dependent instructions
    for (lw_idx, dep_idx, reg) in stalls_info:
        # add "Stall" one cycle before dependent instruction's IF
        dep_IF_cycle = stage_cycles[dep_idx]["IF"]
        stall_cycle = dep_IF_cycle - 1
        if f"C{stall_cycle}" in rows[dep_idx]:
            rows[dep_idx][f"C{stall_cycle}"] = "Stall"

    return {
        "rows": rows,
        "stalls": stalls_info,
        "instr_labels": instr_labels,
        "total_cycles": total_cycles,
    }