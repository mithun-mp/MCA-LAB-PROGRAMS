# pipeline_core.py

def parse_instruction(line):
    """
    Parse a single instruction and return (op, dest, sources).
    Supports: add, sub, lw, sw
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


def count_stalls(instructions):
    """
    Count total stalls caused by load-use hazards.
    Rule: If previous instruction is lw and its destination
    is used by current instruction → +1 stall.
    """
    stalls = 0
    prev_op, prev_dest = None, None

    for line in instructions:
        op, dest, sources = parse_instruction(line)
        if prev_op == 'lw' and prev_dest and prev_dest in sources:
            stalls += 1
        prev_op, prev_dest = op, dest

    return stalls