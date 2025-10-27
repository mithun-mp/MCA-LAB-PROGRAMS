# app.py
import streamlit as st
import pandas as pd
import time
from pipeline_core import count_stalls, generate_timeline

st.set_page_config(page_title="Pipeline Simulator", page_icon="🧠", layout="wide")

st.title("🧠 MIPS 5-Stage Pipeline Table Simulator")
st.markdown("""
### 🚀 Simulate Load-Use Hazards (with Stall Visualization)
Each instruction flows through the 5 pipeline stages (IF, ID, EX, MEM, WB).  
If a `lw` result is needed by the next instruction, a **stall** (bubble) occurs.
""")

# Default input
default_instructions = """lw $t0 , 0
add $t2 , $t0 , $t3
lw $t4 , 1
sw $t4 , 2
sub $t5 , $t0 , $t2
END"""

# Input
user_input = st.text_area("Enter instructions:", default_instructions, height=200)

col1, col2, col3 = st.columns([1, 1, 1])
with col1:
    run = st.button("▶️ Run Simulation")
with col2:
    animate = st.button("🎬 Animate")
with col3:
    speed = st.slider("⏱️ Speed per cycle (s)", 0.1, 1.5, 0.5, 0.1)

# Session memory
if "timeline" not in st.session_state:
    st.session_state.timeline = None

def parse_lines(text):
    lines = [l.strip() for l in text.split("\n") if l.strip()]
    if "END" in lines:
        lines = lines[:lines.index("END")]
    return lines

# Run simulation
if run:
    lines = parse_lines(user_input)
    if not lines:
        st.warning("⚠️ Please enter valid instructions ending with END.")
    else:
        stalls, stall_points = count_stalls(lines)
        timeline = generate_timeline(lines)
        st.session_state.timeline = timeline

        st.success(f"✅ Total Stalls Detected: {stalls}")

        # print details of stalled instructions
        if stall_points:
            st.markdown("### ⚠️ Stall Details:")
            for (lw_idx, dep_idx, reg) in stall_points:
                st.markdown(
                    f"🔸 **I{lw_idx+1}** (`{lines[lw_idx]}`) → "
                    f"**I{dep_idx+1}** (`{lines[dep_idx]}`) — "
                    f"Stall on register `{reg}`"
                )
        else:
            st.info("✅ No load-use stalls detected.")

        # display table
        df = pd.DataFrame(timeline["rows"])
        st.markdown("### 🧾 Pipeline Table (Rows = Instructions, Columns = Cycles)")
        st.table(df)

# Animate simulation (show cycle by cycle)
if animate:
    if not st.session_state.timeline:
        st.warning("⚠️ Run the simulation first.")
    else:
        timeline = st.session_state.timeline
        df = pd.DataFrame(timeline["rows"])
        total_cycles = timeline["total_cycles"]

        placeholder = st.empty()
        st.markdown("### 🎬 Cycle-by-Cycle Animation")

        for c in range(1, total_cycles + 1):
            visible_cols = ["Instruction"] + [f"C{i}" for i in range(1, c + 1)]
            placeholder.table(df[visible_cols])
            time.sleep(speed)

        st.success("✅ Animation Complete — Full pipeline shown.")